class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int count = 0;
        int left = 0;
        string ans = "";

        for (int right = 0; right < n; ++right) {
            if (s[right] == '1') {
                count++;
            }

            // Once we have k ones, shrink left pointer to trim leading zeros
            while (count == k) {
                if (s[left] == '1') {
                    string sub = s.substr(left, right - left + 1);
                    
                    // Update answer if it's shorter or lexicographically smaller
                    if (ans.empty() || sub.length() < ans.length() || 
                       (sub.length() == ans.length() && sub < ans)) {
                        ans = sub;
                    }
                    count--;
                }
                left++;
            }
        }

        return ans;
    }
};