class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,-1);

        
        if(n==0)
            return {};

        if(n==1)
        {
            ans[0]=1;
            return ans;
        }

        map<int,int>m;

        vector<int>arr_dummy=arr;
        sort(arr_dummy.begin(),arr_dummy.end());

        int rank=1;
        for(int i=0;i<n;i++)
        {
            if(m.find(arr_dummy[i])==m.end())
            {
                m[arr_dummy[i]]=rank;
                rank+=1;
            }
        }

        for(int i=0;i<n;i++)
        {
            ans[i]=m[arr[i]];
        }

        return ans;

        
    }
};