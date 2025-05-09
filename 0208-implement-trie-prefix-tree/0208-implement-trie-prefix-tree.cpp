class Trie {
public:
 Trie *c[26];
 bool isEnd;
 int cnt;

    Trie() {
        for(int i=0;i<26;i++){
            c[i]=nullptr;
        }
        cnt=0;
        isEnd=false;
    }
    
    void insert(string word) {
        Trie *r=this;
        for(int i=0;i<word.length();i++){
            int idx=word[i]-'a';
            if(r->c[idx]==nullptr){
                r->c[idx]=new Trie();
            }
            r=r->c[idx];
            r->cnt++;
        }
        r->isEnd=true;
    }
    
    bool search(string word) {
         Trie *r=this;
        for(int i=0;i<word.length();i++){
            int idx=word[i]-'a';
             if(r->c[idx]==nullptr){
               return false;
            }
            else{
                r=r->c[idx];
            }
        }
        return r->isEnd;
    }
    
    bool startsWith(string prefix) {
         Trie *r=this;
        for(int i=0;i<prefix.length();i++){
            int idx=prefix[i]-'a';
             if(r->c[idx]==nullptr){
               return false;
            }
            else{
                r=r->c[idx];
            }
        }
        return r->cnt;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */