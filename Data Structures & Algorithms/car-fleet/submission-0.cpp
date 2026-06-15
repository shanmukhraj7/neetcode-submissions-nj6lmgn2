class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end(), [&](auto& a, auto& b){
            return a.first > b.first;
        });
        vector<double> res;
        for(auto& it : v){
            res.push_back((double)(target - it.first) / it.second);
            if(res.size() >= 2 && res.back() <= res[res.size() - 2]) res.pop_back();
        }
        return res.size();
    }
};
