// Approach
// 1. Pehla Binary Search use karke
//    oh row find karaange
//    jisde range ch target aa sakda hai.
// 2. Je aisi koi row na mile,
//    ta false return karaange.
// 3. Je row mil jaave,
//    ta us row te Binary Search lagaange.
// 4. Je target mil jaave,
//    ta true return karaange.
// 5. Je Binary Search complete ho jaave
//    te target na mile,
//    ta false return karaange.

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix,int target)
    {
        int n=matrix.size();
        int m=matrix[0].size();

        int up=0;
        int down=n-1;

        int row=-1;

        // Find the correct row
        while(up<=down)
        {
            int mid=up+(down-up)/2;

            if(matrix[mid][0]>target)
            {
                down=mid-1;
            }
            else if(matrix[mid][m-1]<target)
            {
                up=mid+1;
            }
            else
            {
                row=mid;
                break;
            }
        }

        if(row==-1)
        {
            return false;
        }

        int left=0;
        int ryt=m-1;

        // Binary Search in the row
        while(left<=ryt)
        {
            int mid=left+(ryt-left)/2;

            if(matrix[row][mid]==target)
            {
                return true;
            }
            else if(matrix[row][mid]<target)
            {
                left=mid+1;
            }
            else
            {
                ryt=mid-1;
            }
        }

        return false;
    }
};