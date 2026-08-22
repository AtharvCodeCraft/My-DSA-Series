class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitProd = 1;
        int temp = n;
        
        while (temp > 0) {
            int digit = temp % 10;
            digitSum += digit;
            digitProd *= digit;
            temp /= 10;
        }
        
        int total = digitSum + digitProd;
        return n % total == 0;
    }
};