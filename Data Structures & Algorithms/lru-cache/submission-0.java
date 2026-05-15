class Node{
    int val, key;
    Node next, prev;
    Node(int key, int val){
        this.val = val;
        this.key = key;
        next = prev = null;
    }
}

class LRUCache {
    private int capacity;
    private Map<Integer, Node> map;
    private Node head, tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        map = new HashMap<>();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head.next = tail;
        tail.prev = head;         
    }

    public void remove(Node node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    public void insert(Node node){
        node.next = head.next;
        head.next.prev = node;
        node.prev = head;
        head.next = node;
    }
    
    public int get(int key) {
        if(!map.containsKey(key)) return -1;
        Node node = map.get(key);
        remove(node);
        insert(node);
        return node.val;
    }
    
    public void put(int key, int value) {
        Node node = new Node(key, value);
        if(map.containsKey(key)){
            Node temp = map.get(key);
            remove(temp);
            map.remove(key);
        }
        if(map.size() == capacity){
            Node temp = tail.prev;
            remove(temp);
            map.remove(temp.key);
        }
        insert(node);
        map.put(key, node);
    }
}
