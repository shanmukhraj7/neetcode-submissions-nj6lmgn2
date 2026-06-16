class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = *max_element(piles.begin(), piles.end());
        while(start < end){
            int mid = start + ((end - start) >> 1);
            int x = 0;
            for(auto val : piles){
                x += ceil((double)val / mid);
            }
            if(x <= h) end = mid;
            else start = mid + 1;
        }
        return end;
    }
};
