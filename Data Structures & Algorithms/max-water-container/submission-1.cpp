class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int start = 0, end = n - 1;
        int maxWater = 0;
        while(start < end){
            int water = min(heights[start], heights[end]) * (end - start);
            maxWater = max(maxWater, water);
            if(heights[start] < heights[end]) start++;
            else end--;
        }
        return maxWater;
    }
};
