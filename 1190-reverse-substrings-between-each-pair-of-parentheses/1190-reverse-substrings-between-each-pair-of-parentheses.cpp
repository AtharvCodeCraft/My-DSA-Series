class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        vector<int> st;

        // Step 1: Pair up matching parentheses
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push_back(i);
            } else if (s[i] == ')') {
                int j = st.back();
                st.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }

        // Step 2: Traverse string with direction switching
        string result = "";
        int direction = 1; // 1 for left-to-right, -1 for right-to-left

        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];          // Teleport to matching bracket
                direction = -direction; // Reverse traversal direction
            } else {
                result += s[i];
            }
        }

        return result;
    }
};