#include<iostream>
using namespace std;
int main(){
	char a[]="abcdef";
	char b[]={'a','b','c','d','e','f','\0'};
	char* c1 = &a[2];
	char* c2 = &b[2];
	cout<<c1<<'\n'<<c2<<'\n';
	char ch = 'z';
	char* p1 = &ch;
	cout<<ch<<"\n"<<p1<<'\n';
	return 0;
}
