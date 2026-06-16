class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int m = a.size(), n = a[0].size();
        int s = 0, e = m * n - 1;
        while(s <= e){
            int mid = s + ((e - s) >> 1);
            int rc = mid / n, cc = mid % n;
            if(a[rc][cc] == target) return true;
            else if(a[rc][cc] > target) e = mid - 1;
            else s = mid + 1;
        }
        return false;
    }
};
