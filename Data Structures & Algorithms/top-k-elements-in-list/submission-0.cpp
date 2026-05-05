# define pii pair<int, int>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        unordered_map<int, int> mpp;
        for(auto x : nums) mpp[x]++;
        for(auto it : mpp){
            pq.push({it.second, it.first});
            while(pq.size() > k) pq.pop();
        }
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            res.push_back(node.second);
        }
        return res;
    }
};
