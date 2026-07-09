class MyLinkedList {
public:
    vector<int> ll;

    MyLinkedList() {
    }

    int get(int index) {
        if(index>=0 && index<ll.size())
        {
            return ll[index];
        }

        return -1;
    }

    void addAtHead(int val) {
        ll.insert(ll.begin(),val);
    }

    void addAtTail(int val) {
        ll.push_back(val);
    }

    void addAtIndex(int index,int val) {
        int n=ll.size();

        if(index<0 || index>n)
        {
            return;
        }

        ll.push_back(0);

        for(int i=n;i>index;i--)
        {
            ll[i]=ll[i-1];
        }

        ll[index]=val;
    }

    void deleteAtIndex(int index) {
        int n=ll.size();

        if(index<0 || index>=n)
        {
            return;
        }

        for(int i=index;i<n-1;i++)
        {
            ll[i]=ll[i+1];
        }

        ll.pop_back();
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */