#include<iostream>
#include<cmath>
using namespace std;
int subs(string input,string* output){
    if(input.empty()){
        output[0]="";
        return 1;
    }
    string s2 = input.substr(1);
    int smallOut_size = subs(s2,output);
    for(int i=0;i<smallOut_size;++i){
        output[i+smallOut_size] = input[0]+output[i];
    }
    return 2*smallOut_size;
}
int main(){
    string s;
    cin>>s;
    string* output = new string[(int)pow(2,s.size())];

    int n=subs(s,output);
    cout<<"Subsequences are:\n";
    for(int i=0;i<n;++i)cout<<output[i]<<'\n';
    delete [] output;
    return 0;
}