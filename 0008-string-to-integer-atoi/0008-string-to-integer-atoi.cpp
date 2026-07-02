// Approach
// 1. Pehlaa string de starting spaces ignore kraange.
// 2. Hun check kraange sign '+' aa ya '-'.
//    Je '-' hove ta sign=-1 kr devaange.
// 3. Hun jadon takk digits mil dian ne,
//    answer build kraange.
// 4. Har digit add krn to pehlaa overflow check kraange.
//    Je overflow hove,
//    ta INT_MAX ya INT_MIN return kr devaange.
// 5. Je digit ton ilava koi hor character mile,
//    ta current answer return kr devaange.
// 6. Last ch answer nu sign naal multiply krke return kr devaange.

class Solution
{
public:
    int myAtoi(string s)
    {
        int i=0;
        int sign=1;
        long ans=0;

        // Skip leading spaces
        while(i<s.length()&&s[i]==' ')
        {
            i++;
        }

        // Check sign
        if(i<s.length()&&s[i]=='-')
        {
            sign=-1;
            i++;
        }
        else if(i<s.length()&&s[i]=='+')
        {
            i++;
        }

        // Build the number
        while(i<s.length())
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                ans=ans*10+(s[i]-'0');

                // Handle overflow
                if(ans>INT_MAX)
                {
                    if(sign==-1)
                    {
                        return INT_MIN;
                    }

                    return INT_MAX;
                }

                i++;
            }
            else
            {
                break;
            }
        }

        return ans*sign;
    }
};