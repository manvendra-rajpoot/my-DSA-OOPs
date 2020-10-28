#include<iostream>
using namespace std;
void removeDuplicates(char s[]){
    if(s[0]=='\0')return;
    if(s[0]!=s[1]){
        removeDuplicates(s+1);
    }
    else{
        int i=1;
        for(;s[i]!='\0';++i){
            s[i-1]=s[i];
        }
        s[i - 1] = s[i];
        removeDuplicates(s);
    }
}
int length(char s[]){
    if(s[0]=='\0')return 0;
    return 1+length(s+1);
}
int main(){
    char s[101];
    cin>>s;
    removeDuplicates(s);
    cout<<s<<'\n';
    cout << length(s) << '\n';
}