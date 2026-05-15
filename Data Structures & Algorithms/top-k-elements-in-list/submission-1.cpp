class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> mpp;
        for(auto x : nums) mpp[x]++;
        for(auto it : mpp){
            pq.push({it.second, it.first});
            while(pq.size() > k) pq.pop();
        }
        vector<int> res;
        while(!pq.empty()){
            auto node = pq.top(); pq.pop();
            res.push_back(node.second);
        }
        return res;
    }
};
