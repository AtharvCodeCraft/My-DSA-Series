class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int currentVowels = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                currentVowels++;
            }
        }

        int maxVowels = currentVowels;

        for (int i = k; i < s.length(); i++) {
            if (isVowel(s[i])) {
                currentVowels++;           
            }
 
 
           if (isVowel(s[i - k])) {
                currentVowels--;
           }

           maxVowels = max(maxVowels, currentVowels);

           if (maxVowels == k) return k;       
        }

        return maxVowels;
    }
};