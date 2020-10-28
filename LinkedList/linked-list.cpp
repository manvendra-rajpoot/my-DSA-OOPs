#include<iostream>
using namespace std;
#include "Node.h"

int getCount(struct Node *head){
    if(head == NULL) return 0;
    return 1 + getCount(head->next);
}

Node* insertAtPosRecursive(Node* head,int pos,int elem){
    if(!head || pos<0)return head;
    if(pos == 0){
        Node* t= new Node(elem);
        t->next=head;
        head=t;
        return head;
    }
    else{
        Node* part2 = insertAtPosRecursive(head->next,pos-1,elem);
        head->next = part2;
    }
}

Node* deleteAtPosRecursive(Node *head, int pos){
    if (!head || pos < 0)
        return head;
    if (pos == 0){
        Node* t = head;
        head = head -> next; 
        return head;
        delete t;
    }
    else{
        Node *part2 = deleteAtPosRecursive(head->next, pos-1);
        head->next = part2;
    }
}

void insertAtBeg(Node** head,int elem){
    Node* t = new Node(elem);
    if(*head == NULL){
        *head = t;
    }
    else{
        t->next = *head;
        *head = t;
    }
}

void printLL(Node* head){
    while(head){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<'\n';
}

Node* mergeLL(Node* h1, Node* h2){ //h1 & h2 are sorted
    if(!h1) return h2;
    if(!h2) return h1;
    Node *fhead = NULL, *ftail = NULL;
    if(h2->data > h1->data){
        fhead = ftail = h1;
        h1 = h1->next;
    }
    else{
        fhead = ftail = h2;
        h2 = h2->next;
    }
    while(h1!=NULL && h2!=NULL){
        if (h2->data > h1->data){
            ftail->next = h1;
            ftail = h1;
            h1 = h1->next;
        }
        else{
            ftail->next = h2;
            ftail = h2;
            h2 = h2->next;
        }
    }
    if(h1){
        ftail->next = h1;
    }
    if(h2){
        ftail->next = h2;
    }
    return fhead;
}

Node* mergeSort(Node* head){
    Node *slowptr = head, *fastptr = head->next;
    if(!fastptr) return head;

    while(fastptr->next!=NULL){
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if(!fastptr) break;
    }
    Node* head2 = slowptr -> next;
    slowptr->next = NULL;
    Node* list1 = mergeSort(head);
    Node* list2 = mergeSort(head2);
    Node* fhead = mergeLL(list1,list2);
    return fhead;
}
Node *reverseLL_Itr(Node* head){ //O(n)
    if(!head || !head->next)return head;
    Node *prev = NULL, *curr = head, *sec = head;
    while(curr){
        sec = curr->next;
        curr->next = prev;
        prev = curr;
        curr = sec;
    }
    head = prev;
    return head;
} 
Node *reverseLL_R3(Node *head){ //O(n) - best one
    if (!head || !head->next) return head;
    Node *tail = head->next;
    Node* smallAns = reverseLL_R3(head->next);
    tail->next = head;
    head->next = NULL;
    return smallAns;
}
Pair reverseLL_R2_helper(Node *head){
    //using 2 nodes - head and tail
    if (!head || !head->next){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Node *h2 = head->next;
    head->next = NULL;
    Pair smallAns = reverseLL_R2_helper(h2);
    smallAns.tail->next = head;
    smallAns.tail = head;
    return smallAns;
}
Node *reverseLL_R2(Node *head){ //O(n)
    Pair ans = reverseLL_R2_helper(head);
    return ans.head;
}

Node* reverseLL_R(Node* head){ //O(n^2)
    if(!head || !head->next)return head;
    Node* smallAns = head->next;
    head->next = NULL;
    smallAns = reverseLL_R(smallAns);
    Node* trav = smallAns;
    while(trav->next){
        trav = trav->next;
    }
    trav->next=head;
    return smallAns;
}

int main(){
    Node* head1 = NULL;
    insertAtBeg(&head1, 1);
    insertAtBeg(&head1, 5);
    insertAtBeg(&head1, 6);
    insertAtBeg(&head1, 13);
    insertAtBeg(&head1, 9);
    insertAtBeg(&head1, 1);
    printLL(head1);
    /*  head1 = insertAtPosRecursive(head1, 2, 99);
        head1 = insertAtPosRecursive(head1, -1, 99);
        printLL(head1);
        head1 = deleteAtPosRecursive(head1, 2);
        head1 = deleteAtPosRecursive(head1, -1);
        printLL(head1);
    */

    Node *head2 = NULL;
    insertAtBeg(&head2, 86);
    insertAtBeg(&head2, 5);
    insertAtBeg(&head2, 3);
    insertAtBeg(&head2, 0);
    //printLL(head2);

    Node* head3 = mergeSort(head1);
    printLL(head3);
    head3 = reverseLL_Itr(head3);
    printLL(head3);
}