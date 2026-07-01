// Approach
// 1. Pehlaa aapaa do queues(q1 te q2) use kraange.
// 2. Push operation ch nava element q2 ch paavaange.
// 3. Fer q1 de saare elements q2 ch move kraange.
// 4. Hun q1 te q2 swap kr devaange.
//    Is naal nava element hamesha q1 de front te aa jaega.
// 5. Pop operation ch q1 de front element nu remove kr devaange.
// 6. Top operation q1 da front return kru ga.
// 7. Empty operation check kru ga ki q1 empty aa ja nahi.

class MyStack
{
public:
    queue<int>q1;
    queue<int>q2;

    MyStack()
    {

    }

    void push(int x)
    {
        q2.push(x);

        // Move all previous elements behind the new element
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1,q2);
    }

    int pop()
    {
        int val=q1.front();
        q1.pop();

        return val;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};