// Approach
// 1. Ik variable answer maintain karaange,
//    jo current expression da result store karega.
// 2. Ik variable sign maintain karaange,
//    jo current number da sign (+1 ya -1) store karega.
// 3. String nu left to right traverse karaange.
// 4. Je digit mile,
//    ta poora number banaavaange
//    (multiple digits handle karaange).
//    Number nu sign naal multiply karke
//    answer ch add karaange.
// 5. Je '+' mile,
//    ta sign = +1 kar devaange.
// 6. Je '-' mile,
//    ta sign = -1 kar devaange.
// 7. Je '(' mile,
//    ta current answer te current sign
//    stack ch push karaange.
//    Fer answer = 0
//    te sign = +1 reset karaange.
// 8. Je ')' mile,
//    ta stack ton pehla sign
//    te fer previous answer pop karaange.
//    Current answer nu
//    popped sign naal multiply karaange
//    te previous answer ch add karaange.
// 9. Traversal complete hon to baad
//    final answer return karaange.

class Solution
{
public:
    int calculate(string s)
    {
        stack<int> st;

        int answer=0;
        int sign=1;

        int n=s.size();

        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                long long number=0;

                while(i<n && isdigit(s[i]))
                {
                    number=number*10+(s[i]-'0');
                    i++;
                }

                answer+=sign*number;

                i--;
            }
            else if(s[i]=='+')
            {
                sign=1;
            }
            else if(s[i]=='-')
            {
                sign=-1;
            }
            else if(s[i]=='(')
            {
                st.push(answer);
                st.push(sign);

                answer=0;
                sign=1;
            }
            else if(s[i]==')')
            {
                int previousSign=st.top();
                st.pop();

                int previousAnswer=st.top();
                st.pop();

                answer=previousAnswer+previousSign*answer;
            }
        }

        return answer;
    }
};