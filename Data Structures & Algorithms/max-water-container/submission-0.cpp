class Solution {
public:
    int maxArea(vector<int>& a) {
        int n = a.size();
        int maxWater = 0;
        int start = 0, end = n - 1;
        while(start <= end){
            int water = min(a[start], a[end]) * (end - start);
            maxWater = max(maxWater, water);
            if(a[start] < a[end]) start++;
            else end--;
        }
        return maxWater;
    }
};
