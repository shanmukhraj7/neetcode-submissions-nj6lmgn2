class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int lengthOfS1 = s1.length();
        int lengthOfS2 = s2.length();
        if(lengthOfS1 > lengthOfS2) return false;
        vector<int> frequencyS1(26, 0);
        vector<int> frequencyS2(26, 0);
        for(int iterator = 0; iterator < lengthOfS1; iterator++){
            frequencyS1[s1[iterator] - 'a']++;
            frequencyS2[s2[iterator] - 'a']++;
        }
        if(frequencyS1 == frequencyS2){
            return true;
        }
        for(int iterator = lengthOfS1; iterator < lengthOfS2; iterator++){
            frequencyS2[s2[iterator] - 'a']++;
            frequencyS2[s2[iterator - lengthOfS1] - 'a']--;
            if(frequencyS1 == frequencyS2){
                return true;
            }
        }
        return false;
    }
};
