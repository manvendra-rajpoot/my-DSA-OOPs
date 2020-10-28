
class trieNode{
    public:
    char data;
    trieNode** children;
    bool isTerminal;

    trieNode(char elem) : data(elem), isTerminal(false){ 
        children = new trieNode*[26];
        for(int i=0;i<26;++i){
            children[i] = NULL;
        }
    }
    ~trieNode(){
        for(int i=0;i<26;++i){
            delete children[i];
        }
        delete [] children;
    }
};