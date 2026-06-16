class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int index = st.top(); st.pop();
                int element = heights[index];
                int nse = i, pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, (nse - pse - 1) * element);
            }
            st.push(i);
        }
        while(!st.empty()){
            int index = st.top(); st.pop();
            int element = heights[index];
            int nse = n, pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (nse - pse - 1) * element);
        }
        return maxArea;
    }
};
