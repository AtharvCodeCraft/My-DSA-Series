class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26);

        // Store last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<bool> visited(26, false);
        string st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // Skip if already included
            if (visited[c - 'a'])
                continue;

            // Maintain lexicographical order
            while (!st.empty() &&
                   st.back() > c &&
                   lastIndex[st.back() - 'a'] > i) {
                visited[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            visited[c - 'a'] = true;
        }

        return st;
    }
};