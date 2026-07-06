class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> m;
        int priority=1;
        for(int i=0;i<order.size();i++)
        {
            m[order[i]]=priority;
            priority++;
        }

        priority_queue< pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>> pq;

        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])!=m.end())
            {
                pq.push({m[s[i]],s[i]});
            }
            else{
                pq.push({1e9,s[i]});
            }
        }
        string ans="";

        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();

            ans+=top.second;
        }
        return ans;
    }
};