class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int sizeOfNums = nums.size();
        vector<int> resultArray;
        deque<int> valueStorage;
        for(int index = 0; index < sizeOfNums; index++){
            if(!valueStorage.empty() && valueStorage.front() <= index - k) valueStorage.pop_front();
            while(!valueStorage.empty() && nums[valueStorage.back()] <= nums[index]) valueStorage.pop_back();
            valueStorage.push_back(index);
            if(index >= k - 1) resultArray.push_back(nums[valueStorage.front()]);
        }
        return resultArray;
    }
};
