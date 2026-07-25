class Solution {
public:
    int maxProduct(int n) {
        int a=0 , b=0;
        while(n > 0){
            int x = n % 10;
            if(a < x){
                b = a;
                a = x;
            }
            else if(b<x)  b = x;
            n = n / 10;
        }
        return a * b;
    }
};