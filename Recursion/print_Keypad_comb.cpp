#include<iostream>
#include<cmath>
using namespace std;
void prnt_combs(int num, string output){
    int rem = num%10, q = num/10 ;
    if(rem==0){
        cout<<output<<'\n';
        return;
    }
    string s1="";
    switch(rem){
        case 2:
            s1 += "abc";
            break;
        case 3:
            s1 += "def";
            break;
        case 4:
            s1 += "ghi";
            break;
        case 5:
            s1 += "jkl";
            break;
        case 6:
            s1 += "mno";
            break;
        case 7:
            s1 += "pqrs";
            break;
        case 8:
            s1 += "tuv";
            break;
        case 9:
            s1 += "wxyz";
            break;
    }
    for(int i=0;i<s1.size();++i){
        prnt_combs(q,s1[i]+output);
    } 
}
int main(){
    int num; //num doesn't contain 1
    cin>>num;
    string output = "";

    cout<<"Cominations are :\n";
    prnt_combs(num, output);

    return 0;
}