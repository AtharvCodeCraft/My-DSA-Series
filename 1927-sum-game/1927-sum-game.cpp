class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sumDiff = 0;
        int qDiff = 0;

        for (int i = 0; i < n; i++) {
            int sign = (i < n / 2) ? 1 : -1;
            if (num[i] == '?') {
                qDiff += sign;
            } else {
                sumDiff += sign * (num[i] - '0');
            }
        }

        return sumDiff * 2 != -qDiff * 9;
    }
};