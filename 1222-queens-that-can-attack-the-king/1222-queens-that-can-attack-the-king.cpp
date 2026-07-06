class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens,
                                            vector<int>& king) {

        bool board[8][8] = {};

        for(auto &q : queens) {
            board[q[0]][q[1]] = true;
        }

        vector<vector<int>> ans;

        int dx[8]={-1,-1,-1, 0, 0, 1, 1, 1};
        int dy[8]={-1, 0, 1,-1, 1,-1, 0, 1};

        for(int d = 0; d < 8; d++) 
        {

            int x = king[0];
            int y = king[1];

            while(true) {

                x += dx[d];
                y += dy[d];

                if(x < 0 || x >= 8 || y < 0 || y >= 8)
                    break;

                if(board[x][y]) {

                    ans.push_back({x, y});
                    break;
                }
            }
        }

        return ans;
    }
};