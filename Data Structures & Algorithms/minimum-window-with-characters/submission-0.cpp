class Solution {
public:
    string minWindow(string s, string t) {
        int sizeOfS = s.length();
        int sizeOfT = t.length();
        map<char, int> frequency;
        for(char character : t){
            frequency[character]++;
        }
        int minimumLength = INT_MAX;
        int count = 0;
        int index = 0;
        int left = 0;
        for(int right = 0; right < sizeOfS; right++){
            if(frequency[s[right]] > 0) count++;
            frequency[s[right]]--;
            while(count == sizeOfT){
                if((right - left + 1) < minimumLength){
                    minimumLength = (right - left + 1);
                    index = left;
                }
                frequency[s[left]]++;
                if(frequency[s[left]] > 0) count--;
                left++;
            }
        }
        return minimumLength == INT_MAX ? "" : s.substr(index, minimumLength);
    }
};
