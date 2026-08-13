#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
private:
    set<pair<int, int>> intervals; 
    multiset<int> lengths;          

    void addInterval(int l, int r) {
        intervals.insert({l, r});
        lengths.insert(r - l + 1);
    }

    void removeInterval(int l, int r) {
        intervals.erase({l, r});
        lengths.erase(lengths.find(r - l + 1));
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();

        
        int start = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == n || s[i] != s[start]) {
                addInterval(start, i - 1);
                start = i;
            }
        }

        int k = queryIndices.size();
        vector<int> ans(k);

        for (int i = 0; i < k; ++i) {
            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            if (s[idx] != ch) {
                
                auto it = prev(intervals.upper_bound({idx, n}));
                auto [l, r] = *it;

                
                removeInterval(l, r);

                
                if (l < idx) addInterval(l, idx - 1);
                if (idx < r) addInterval(idx + 1, r);

                s[idx] = ch;
                int cur_l = idx, cur_r = idx;

                
                if (idx > 0 && s[idx - 1] == ch) {
                    auto left_it = prev(intervals.upper_bound({idx - 1, n}));
                    auto [left_l, left_r] = *left_it;
                    removeInterval(left_l, left_r);
                    cur_l = left_l;
                }

                
                if (idx + 1 < n && s[idx + 1] == ch) {
                    auto right_it = intervals.lower_bound({idx + 1, 0});
                    auto [right_l, right_r] = *right_it;
                    removeInterval(right_l, right_r);
                    cur_r = right_r;
                }

                addInterval(cur_l, cur_r);
            }

            
            ans[i] = *lengths.rbegin();
        }

        return ans;
    }
};