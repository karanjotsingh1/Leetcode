class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        int priority=1;
        for(int i=0;i<order.size();i++){
            mp[order[i]]=priority;
            priority++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])){
                pq.push({mp[s[i]],s[i]});
            }
            else{
                pq.push({1e9,s[i]});
            }
        }
        string ans="";
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            ans+=top.second;
        }
        return ans;
    }
};