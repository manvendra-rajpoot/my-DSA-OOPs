#include<iostream>
#include<cmath>
using namespace std;
int subs(int num, string* output){
    int rem = num%10, q = num/10 ;
    if(rem==0){
        output[0]="";
        return 1;
    }
    int sz = subs(q,output);
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
    for(int i=0;i<sz;++i){
        output[i]= output[i]+s1[0];
    }
    int cnt = 1, j = sz;
    while(cnt<s1.size()){
        for(int i=0;i<sz;++i){
            string str(output[i]);
            str[str.size()-1]=s1[cnt];
            output[j++]= str;
        }
        cnt++;
    }
    return j; 
}
int main(){
    int num; //num doesn't contain 1
    cin>>num;
    string *output = new string[12000]; //max strings = 11664

    int n=subs(num,output);
    
    cout<<"=> "<<n<<" subSequences are:\n";
    for(int i=0;i<n;++i)cout<<output[i]<<'\n';
    cout<<n<<'\n';
    delete [] output;
    return 0;
}