/*  Writer => Manvendra Rajpoot.  */
#include<bits/stdc++.h>
using namespace std;
typedef  long long            ll;
typedef  unsigned long long   llu;
typedef  long double          ldo;
typedef  vector<ll>           vll;
typedef  vector<string>       vss;
typedef  vector<pair<ll,ll>>  vpll; 
typedef  vector<vector <ll>>  vvll;
typedef  set<ll>              sll;
typedef  set<string>          sss;
typedef  unordered_map<ll,ll> umll;//insert,find,erase in O(1) 
typedef  map<ll,ll>           mll;//insert,find,erase in O(logN)
typedef  map<string,ll>       msll;
typedef  map<char,ll>         mcll;
typedef  map<ll,string>       mlls;
typedef  priority_queue<ll>   pqll;
const ll  mod    = 1000000007;
const ldo pi     = 2*asin(1.0); //3.14159 
const int INF    = 0x3f3f3f3f; //1061109567
const ll  LL_INF = 0x3f3f3f3f3f3f3f3f;       //4557430888798830399
const ll  MAXN   = numeric_limits<ll>::max();//9223372036854775807
const ll  MINN   = -1*(1e9+1); //-1000000001
#define  endl          '\n'
#define  sz(c)         (ll)c.size()
#define  fr            first 
#define  sc            second
#define  pb            push_back
#define  mp            make_pair
#define  all(v)        (v).begin(),(v).end()
#define  rep(i,a,n)    for(ll i=a;i<n;i++)
#define  bs_a(a,i,n,x) binary_search(a+i,a+n,x)
#define  bs_v(v,x)     binary_search(all(v),x)//return bool 1/0
#define  lb_a(a,i,n,x) lower_bound(a+i,a+n,x)-a//return pointer of that 1st ind.
#define  ub_a(a,i,n,x) upper_bound(a+i,a+n,x)-a//return pointer of next ind.
#define  lb_v(v,x)     lower_bound(all(v),x)-v.begin()
#define  ub_v(v,x)     upper_bound(all(v),x)-v.begin()
#define  gcdll(x,y)    __gcd(x,y)
#define  lcmll(x,y)    (x*y)/gcdll(x,y)
#define  swapll(x,y)   swap(x,y)/*x & y can be vector,arr,numbers*/
#define  IOS       ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
class Solution{
    public:
    void SolutionFunc(){
        string s;cin>>s;
        ll x=(ll)s.find('1');
        cout<<x<<'\n';
        if(x<0 || x>=sz(s)){
            cout<<0<<endl;
        }
        else{
            std::vector<ll> v;

            ll ind = x, i = x;

            while(i<sz(s)){
                if(s[i]=='1'){
                    s[i]='0';
                    ++i;
                }
                else if(s[i]=='0'){
                    v.pb(i-ind);
                    ind=s.find('1');
                    i = ind;
                }
            }
            for(ll i=0;i<sz(v);++i)cout<<v[i]<<" ";
            cout<<'\n';
        }
    }
};

int main(){
   // #ifndef ONLINE_JUDGE
   // freopen("input.txt","r",stdin);  
  //  freopen("output.txt","w",stdout);
//    #endif
    IOS;

    Solution obj;
    int T=1;
    cin>>T;
    rep(i,0,T){ 
        //cout<<"Case #"<<i+1<<": ";
        obj.SolutionFunc();
    }  
    return(0);
} 

