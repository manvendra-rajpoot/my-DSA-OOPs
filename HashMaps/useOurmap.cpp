#include <iostream>
#include "ourmap.h"
using namespace std;


int main(){
    ourmap<int> m;
    for(int i=0;i<10;++i){
        string key = "abc";
        char ch = i + '0';
        key += ch;
        m.insert(key,i+1);
        cout<<m.getLoadFactor()<<'\n';
    }
    cout << m.size() << '\n';
    m.remove("abc3");
    m.remove("abc7");
    cout << m.size() << '\n';
    for (int i = 0; i < 10; ++i){
        string key = "abc";
        char ch = i + '0';
        key += ch;
        cout << key<<":"<<m.getValue(key) << '\n';
    }

    return 0;
}