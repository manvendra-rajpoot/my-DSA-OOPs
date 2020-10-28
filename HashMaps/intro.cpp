#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    unordered_map<string ,int> ourmap;

    //insert
    pair<string,int> p("abc",10);
    ourmap.insert(p);
    ourmap["def"] = 20;

    //find or access
    cout << ourmap["def"] << '\n';
    cout << ourmap.at("def") << '\n';
    /* cout<<ourmap.at("ghi")<<"\n"    => This gives ERROR!*/
    cout<<ourmap.size()<<'\n';
    cout<<ourmap["ghi"]<<'\n';//This add key if not present with value 'NULL'
    cout << ourmap.size() << '\n';

    //check Presence
    if(ourmap.count("ghi")>0){
        cout<<"key is present\n";
    }
    else cout<<"key is not present\n";

    //erase
    ourmap.erase("ghi");
    cout<<ourmap.size()<<'\n';
    if (ourmap.count("ghi") > 0){
        cout << "key is present\n";
    }
    else cout << "key is not present\n";

    return 0;
} 
