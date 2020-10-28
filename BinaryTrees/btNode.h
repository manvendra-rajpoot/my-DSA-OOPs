template <typename T>
class btNode{
    public:
    T data;
    btNode<T> *left, *right;
    btNode(T elem){
        this->data = elem;
        left = right = NULL;
    }
    ~btNode(){
        delete left;
        delete right;
    }
};