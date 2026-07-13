class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        // row searching 
        int up=0;
        int down=n-1;
        
        int mid;
        while(up<=down)
        {
            mid=up+(down-up)/2;

            if(matrix[mid][0] > target)
            {
                down=mid-1;
            }
            else if(matrix[mid][m-1] < target)
            {
                up=mid+1;
            }
            else
            {
                break;
            }
        }

        int left=0;
        int ryt=m-1;

        while(left<=ryt)
        {
            int mid_col=left+(ryt-left)/2;

            if(matrix[mid][mid_col]==target)
            {
                return true;
            }
            else if(matrix[mid][mid_col]< target)
            {
                left=mid_col+1;
            }
            else
            {
                ryt=mid_col-1;
            }
        }
        return false;
        
        
    }
};