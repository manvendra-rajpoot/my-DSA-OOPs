#include <iostream>
using namespace std;
//#include "stackByLL.h" 
#include "queueByLL.h" // "" search this file within current directory 
/*
    "<file>.h" doesn't contain main() function
*/
int main(){
    /*Stack<char> s;
    s.push('A');
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    cout<<s.top()<<'\n';
    cout<<s.pop()<<'\n';
    cout<<s.pop()<<'\n';
    cout<<s.pop()<<'\n';
    cout<<s.pop()<<'\n';
    cout << s.pop() << '\n';
    cout<<s.getSize()<<'\n';
    cout<<s.isEmpty()<<'\n'; */

    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout << q.dequeue() << '\n';
    cout<<q.dequeue()<<'\n';
    cout<<q.dequeue()<<'\n';
    cout<<q.dequeue()<<'\n';
    cout<<q.dequeue()<<'\n';
    cout << q.dequeue() << '\n';
    cout<<q.getSize()<<'\n';

    return 0;
}