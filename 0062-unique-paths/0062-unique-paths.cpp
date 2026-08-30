class Solution {
public:

    int uniquePaths(int m, int n) {
        // Stores the total number of unique paths
        long long paths = 1;

        // Total moves needed to reach the destination
        int totalMoves = m + n - 2;

        // Compute C(totalMoves, r), where r is smaller
        // because C(n, r) = C(n, n - r)
        int r = min(m - 1, n - 1);

        // Calculate the binomial coefficient iteratively
        for (int i = 1; i <= r; i++)
        {
            paths = paths * (totalMoves - r + i) / i;
        }

        return (int)paths;
    
    }
};