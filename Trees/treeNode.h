#include <vector>
using namespace std;

template <typename T>
class treeNode{
    public:
    T data;
    vector<treeNode<T>*> children;

    treeNode(T elem): data(elem){ }
    ~treeNode(){
        for(int i = 0; i < children.size() ; ++i){
            delete children[i];
        }
    }
};