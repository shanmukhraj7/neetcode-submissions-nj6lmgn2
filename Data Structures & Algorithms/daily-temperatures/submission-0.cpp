class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                int val = st.top();
                st.pop();
                res[val] = i - val;
            }
            st.push(i);
        }
        return res;
    }
};
