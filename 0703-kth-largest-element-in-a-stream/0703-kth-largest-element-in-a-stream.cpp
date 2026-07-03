// Approach
// 1. Min Heap use kraange jisda size hamesha k hovega.
// 2. Heap ch hamesha k largest elements hi store honge.
// 3. Constructor ch nums de saare elements ik ik karke add kraange.
// 4. Je heap da size k ton vadda ho jaave,
//    ta smallest element pop kar devaange.
// 5. Is tarah heap da top hamesha kth largest element hovega.
// 6. add() function ch vi nava element push kraange.
// 7. Je heap size k ton vaddi ho jaave,
//    ta top pop kar devaange.
// 8. Aakhir ch heap da top return kar devaange.

class KthLargest
{
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int k;

    KthLargest(int k,vector<int>& nums)
    {
        this->k=k;

        for(int num:nums)
        {
            pq.push(num);

            if(pq.size()>k)
            {
                pq.pop();
            }
        }
    }

    int add(int val)
    {
        pq.push(val);

        if(pq.size()>k)
        {
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj=new KthLargest(k,nums);
 * int param_1=obj->add(val);
 */