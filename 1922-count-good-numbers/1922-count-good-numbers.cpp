// Approach
// 1. Even indices te
//    5 possible digits hunde ne.
// 2. Odd indices te
//    4 possible digits hunde ne.
// 3. Even indices di count
//    (n+1)/2 hovegi.
// 4. Odd indices di count
//    n/2 hovegi.
// 5. Total answer hovega:
//    5^(evenCount) × 4^(oddCount).
// 6. Kyunki n bahut vadda ho sakda hai,
//    Fast Binary Exponentiation use karaange.
// 7. Har multiplication te modulo
//    (1e9+7) apply karaange.
// 8. Final answer return karaange.

class Solution
{
public:
    const long long MOD=1e9+7;
    long long power(long long base,long long exponent)
    {
        long long answer=1;
        while(exponent>0)
        {
            if(exponent%2==1)
            {
                answer=(answer*base)%MOD;
            }

            base=(base*base)%MOD;

            exponent/=2;
        }

        return answer;
    }

    int countGoodNumbers(long long n)
    {
        long long evenCount=(n+1)/2;
        long long oddCount=n/2;
        long long evenWays=power(5,evenCount);
        long long oddWays=power(4,oddCount);

        return (evenWays*oddWays)%MOD;
    }
};