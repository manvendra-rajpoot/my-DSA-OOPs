
class Node{
    public:
    int data;
    Node* next; 
    Node(int x):data(x){
        next = NULL;
    }
};

class Pair{
    public:
    Node *head, *tail;
};