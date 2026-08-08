using namespace std;
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> last_pos(m + 1, -1);
        last_pos[m] = n;

        int j = n - 1;

        for(int i = m - 1; i >= 0; --i) {
            while (j >= 0 && word1[j] != word2[i]) {
                j--;
            }
            last_pos[i] = j;
            if (j >= 0) {
                j--;
            }
        }

        vector<int> res;
        bool used_change = false;
        int word1_idx = 0;

        for (int idx = 0; idx < m; ++idx) {
            while (word1_idx < n) {
                if (word1[word1_idx] == word2[idx]) {
                    res.push_back(word1_idx);
                    word1_idx++;

                    break;
                }

                if (!used_change && last_pos[idx + 1] > word1_idx) {
                    used_change = true;
                    res.push_back(word1_idx);
                    word1_idx++;
                    break;
                }

                word1_idx++;

            }
            if (res.size() != idx + 1) {
                return {};
            }
        }

        return res;
    }
};