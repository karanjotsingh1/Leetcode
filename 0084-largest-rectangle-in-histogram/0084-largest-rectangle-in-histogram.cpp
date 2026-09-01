class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();

        int max_area=0;

        stack<int>st;

        vector<int>prev_smaller(n,-1);
        vector<int>next_smaller(n,n);

        // Find next smaller element
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }

            if(!st.empty())
            {
                next_smaller[i]=st.top();
            }

            st.push(i);
        }

        while(!st.empty())
        {
            st.pop();
        }

        // Find previous smaller element
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }

            if(!st.empty())
            {
                prev_smaller[i]=st.top();
            }

            st.push(i);
        }

        // Calculate maximum area
        for(int i=0;i<n;i++)
        {
            int width=next_smaller[i]-prev_smaller[i]-1;

            int area=heights[i]*width;

            max_area=max(max_area,area);
        }

        return max_area;
    }
};