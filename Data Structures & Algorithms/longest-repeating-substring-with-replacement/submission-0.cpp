class Solution {
public:
    int characterReplacement(string s, int k) {
        int sizeOfString = s.length();
        int left = 0;
        int maximumFrequency = 0;
        int maximumLength = 0;
        vector<int> frequencyArray(26, 0);
        for(int right = 0; right < sizeOfString; right++){
            frequencyArray[s[right] - 'A']++;
            maximumFrequency = max(maximumFrequency, frequencyArray[s[right] - 'A']);
            while((right - left + 1) - maximumFrequency > k){
                frequencyArray[s[left] - 'A']--;
                left++;
            }
            maximumLength = max(maximumLength, (right - left + 1));
        }
        return maximumLength;
    }
};
