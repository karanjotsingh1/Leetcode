#include <cmath>  
class Solution {
public:
    bool isPerfectSquare(long long n) {
    if (n < 0) return false; // Negative numbers cannot be perfect squares
    
    long long root = sqrt(n);
    return (root * root == n);
    }
    int bulbSwitch(int n) {
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(isPerfectSquare(i))
                count+=1;
        }
        return count;
    }
};