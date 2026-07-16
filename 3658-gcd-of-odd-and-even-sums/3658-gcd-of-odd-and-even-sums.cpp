// Approach
// 1. First n odd numbers da sum hunda hai n².
// 2. First n even numbers da sum hunda hai n(n+1).
// 3. Required answer:
//    gcd(n², n(n+1)).
// 4. n common factor bahar kaddange:
//    n × gcd(n, n+1).
// 5. Consecutive numbers da gcd hamesha 1 hunda hai.
// 6. Is karke final answer sirf n hovega.

class Solution
{
public:
    int gcdOfOddEvenSums(int n)
    {
        return n;
    }
};