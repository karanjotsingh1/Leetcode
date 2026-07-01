// Approach
// 1. Pehlaa check kraange je string di length odd aa,
//    ta valid parentheses possible nhi, false return kr devaange.
// 2. Hun ik stack use kraange opening brackets store krn lai.
// 3. Je opening bracket mile,
//    ta stack ch push kr devaange.
// 4. Je closing bracket mile,
//    ta check kraange stack empty ta nhi.
//    Je top matching opening bracket hove,
//    ta pop kr devaange.
//    Nahi ta false return kr devaange.
// 5. Puri string traverse hon to baad,
//    je stack empty aa ta saare brackets properly match ho gaye.
// 6. Je stack ch kuch reh gya,
//    matlab kuch opening brackets close nhi hoye.

class Solution
{
public:
    bool isValid(string s)
    {
        int n=s.size();

        if(n%2==1)
        {
            return false;
        }

        stack<char>st;

        for(int i=0;i<n;i++)
        {
            char ch=s[i];

            if(ch=='('||ch=='{'||ch=='[')
            {
                st.push(ch);
            }
            else
            {
                // Check whether current closing bracket matches the top
                if(!st.empty()&&((ch==')'&&st.top()=='(')||(ch=='}'&&st.top()=='{')||(ch==']'&&st.top()=='[')))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return st.empty();
    }
};