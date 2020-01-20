class Solution {
public:
    int reverse(int x) {
        if(x/10 == 0) return x;

        int y = 0;
        while(x) {
            if(y > INT_MAX/10 || y < INT_MIN/10) { //溢出
                return 0;
            }

            y *= 10;
            y += x%10;  //去除x的个位，存入y中对称的位置。
            x /= 10;    //去掉x的个位。
        } 

        return y;
    }
};