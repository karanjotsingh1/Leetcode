// Approach
// 1. Pehla linked list di size calculate kraange.
// 2. Answer vector nu 0 naal initialize kar devaange.
// 3. Monotonic decreasing stack use kraange,
//    jithe (value,index) store hovega.
// 4. Linked list nu ik vaar traverse kraange.
// 5. Je current value stack de top ton vaddi hove,
//    ta current value usda next greater element hovega.
// 6. Answer update karke stack ton pop kar devaange.
// 7. Fir current value te usda index stack ch push kar devaange.
// 8. Jehde elements stack ch bach jaan,
//    ohna da next greater element exist nahi karda,
//    is karke answer already 0 hi rahega.

class Solution
{
public:
    vector<int> nextLargerNodes(ListNode* head)
    {
        if(head==NULL)
        {
            return {};
        }

        int n=0;
        ListNode* temp=head;

        while(temp!=NULL)
        {
            n++;

            temp=temp->next;
        }

        vector<int>ans(n,0);

        stack<pair<int,int>>st;

        temp=head;

        int idx=0;

        while(temp!=NULL)
        {
            while(st.empty()==false && st.top().first<temp->val)
            {
                ans[st.top().second]=temp->val;

                st.pop();
            }

            st.push({temp->val,idx});

            idx++;

            temp=temp->next;
        }

        return ans;
    }
};