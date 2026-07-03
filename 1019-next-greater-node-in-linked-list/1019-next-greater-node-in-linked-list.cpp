/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if(head==NULL)  
            return {};


        ListNode* temp1=head;
        int n=0;
        while(temp1)
        {
            n+=1;
            temp1=temp1->next;
        }

        vector<int> ans(n,0);
        stack<pair<ListNode*,int>>st;
        int idx=0;
        st.push({head,0});
        ListNode* temp=head->next;

       while(temp!=NULL)
       {
        idx+=1;
            while(st.empty()==false && (st.top()).first->val < temp->val)
            {
                ans[st.top().second]=temp->val;
                st.pop();
            }

            st.push({temp,idx});
            temp=temp->next;
       }
       
        return ans;
    }
};