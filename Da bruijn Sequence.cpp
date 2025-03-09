#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl<<flush;
#define endl '\n'
#define INF 1e17
ll M = 1e9+7;
const ll N = 5e5+1;
const ll LOG = 11;
void debug(vector<int> v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
int n,m;
vector<int>ans;
set<int>g[N];
void dfs(int cur,int par)
{
    while(g[cur].size())
    {
        auto chi=*g[cur].begin();
        g[cur].erase(g[cur].begin());
        dfs(chi,cur);
    }
    ans.pb(cur&1);
}
void bin(int x)
{
    vector<ll>v;
    while(x)
    {
        if(x&1){v.pb(1);}
        else{v.pb(0);}
        x>>=1;
    }
    while(v.size()<n-1){v.pb(0);}
    reverse(v.begin(),v.end());
    for(auto it:v){cout<<it;}cout<<" ";
}
int32_t main()
{
    fast
    int i,j=1,k,p,q,tc=1,cs=0;
    //cin>>tc;
    while(tc--)
    {
        cin>>n;
        if(n==1){cout<<10<<endl;continue;}
        M = (1<<(n-1));
        int major,minor;
        for(i=0;i<(1<<n);i++)
        {
            major=(i>>1);
            minor=(i%M);
            //bin(major);bin(minor);cout<<endl;
            g[major].insert(minor);
        }
        dfs(0,N-1);
        for(i=0;i<n-2;i++)
        {
            ans.pb(0);
        }
        reverse(ans.begin(),ans.end());
        for(auto it:ans){cout<<it;}cout<<endl;
    }
}
/*
//https://www.youtube.com/watch?v=TNYZZKrjCSk&ab_channel=BenLangmead
Solution:
Step 1: Form 0 to (1<<n)-1 consider them as n length binary number. 
Step 2: First n-1 bits are major bits. Last n-1 bits are minor bits.
Step 3: Imagine a edge from major to minor number. (Create the graph).
Step 4: Find a eular path and take the last bit from each visit.
*/
