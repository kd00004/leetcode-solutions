class Solution {
public:
    bool checkGoodInteger(int n) {
        int sqsum = 0, sum = 0;
        while(n > 0){
            int digit = n%10;
            n /= 10;
            sum += digit;
            sqsum += digit * digit;
        }
        if(sqsum - sum >= 50) return true;
        return false;
    }
};