class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m * n - 1;
        while(start <= end){
            int mid = start + ((end - start) >> 1);
            int midVal = matrix[mid / n][mid % n];
            if(midVal == target) return true;
            else if(midVal > target) end = mid - 1;
            else start = mid + 1;
        }
        return false;
    }
};
