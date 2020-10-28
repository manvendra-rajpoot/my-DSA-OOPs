#include<iostream>
#include<cmath>
using namespace std;
void prnt_subs(string input,string output){
    if(input.empty()){
        cout<<output<<'\n';
        return ;
    }
    prnt_subs(input.substr(1),output);//not including 1st char in output string
    prnt_subs(input.substr(1), output+input[0]);//including 1st char
}
int main(){
    string s,str="";
    cin>>s;
    cout << "Subsequences are:\n";
    prnt_subs(s,str);
    return 0;
}