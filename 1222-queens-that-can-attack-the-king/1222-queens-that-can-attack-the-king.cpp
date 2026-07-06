class Solution {
public:
    void attack(int k_row,int k_col,set<pair<int,int>>s ,vector<vector<int>>&ans)
    {
        for(int j=k_col;j>=0;j--)
        {
            if(s.find({k_row,j})!=s.end())
            {
                ans.push_back({k_row,j});
                break;
            }
        }
        for(int j=k_col;j<8;j++)
        {
            if(s.find({k_row,j})!=s.end())
            {
                ans.push_back({k_row,j});
                break;
            }
        }

        for(int i=k_row;i>=0;i--)
        {
            if(s.find({i,k_col})!=s.end())
            {
                ans.push_back({i,k_col});
                break;
            }
        }
        for(int i=k_row;i<8;i++)
        {
            if(s.find({i,k_col})!=s.end())
            {
                ans.push_back({i,k_col});
                break;
            }
        }

        for(int i=k_row,j=k_col;i>=0 && j>=0;i--,j--)
        {
            if(s.find({i,j})!=s.end())
            {
                ans.push_back({i,j});
                break;
            }
        }
        for(int i=k_row,j=k_col;i>=0 && j<8;i--,j++)
        {
            if(s.find({i,j})!=s.end())
            {
                ans.push_back({i,j});
                break;
            }
        }
        for(int i=k_row,j=k_col;i<8 && j>=0;i++,j--)
        {
            if(s.find({i,j})!=s.end())
            {
                ans.push_back({i,j});
                break;
            }
        }
        for(int i=k_row,j=k_col;i<8 && j<8;i++,j++)
        {
            if(s.find({i,j})!=s.end())
            {
                ans.push_back({i,j});
                break;
            }
        }
        return;

    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int k_row=king[0];
        int k_col=king[1];
        vector<vector<int>>ans;

        set<pair<int,int>>s;
        for(int i=0;i<queens.size();i++)
        {
            int q_row=queens[i][0];
            int q_col=queens[i][1];
            
            s.insert({q_row,q_col});
        }
        attack(k_row,k_col,s,ans);

        return ans;
    }
};