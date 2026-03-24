class Solution {
public:
    int reverse(int x) {
        int reversedNum = 0;
        int digit;
        
        while(x != 0){
            digit = x % 10;
            if(reversedNum > INT_MAX/10 || reversedNum < INT_MIN/10){
                return 0;
            }
            reversedNum = reversedNum*10 + digit;
            x = x/10;;
        }
        return reversedNum;
    }
};