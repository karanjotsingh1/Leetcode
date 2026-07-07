class MagicDictionary {
public:
vector<string>s;
int count;
    MagicDictionary() {
        count=0;
    }
    
    void buildDict(vector<string> dictionary) {
        for(int i=0;i<dictionary.size();i++)
        {
            s.push_back(dictionary[i]);
        }
    }
    
    bool search(string searchWord) {
        for(int i=0;i<s.size();i++)
        {
            string stored_str=s[i];
            if(stored_str.size()!=searchWord.size())
                continue;

            int count=0;
            for(int j=0;j< stored_str.size();j++)
            {
                if(stored_str[j] != searchWord[j])
                    count+=1;
            }
            if(count==1)    
                return true; 
        }
        return false;
        
    }

};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */