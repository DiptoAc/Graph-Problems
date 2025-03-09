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
const ll M = 1e9+7;
const ll N = (1<<20)-1;
const ll LOG = 11;
void debug(vector<ll> v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
ll n,m;
vector<vector<int>>dp(N,vector<int>(20,-1));
vector<int>g[20];
ll magic(ll mask, ll cur)
{
    //cout<<mask<<" mask,cur "<<cur<<endl;
    if(cur==n-1 && mask){return 0;}
    if(dp[mask][cur]!=-1){return dp[mask][cur];}
    ll ans=0;
    for(auto chi:g[cur])
    {
        if(mask & (1<<chi) )
        {
            ans+=magic(mask-(1<<chi),chi);
            ans%=M;
        }
    }
    return dp[mask][cur]=ans;
}
int32_t main()
{
    fast
    int i,j=1,k,p,q,tc=1,cs=0;
    //cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            g[x].pb(y);
        }
        for(i=0;i<n;i++){dp[0][i]=0;}
        dp[0][n-1]=1;
        k=(1<<n)-2;
        //cout<<"K ="<<k<<endl;
        cout<<magic(k,0)<<endl;
    }
}
/*
Problem link: https://cses.fi/problemset/result/12290715/
Problem name: Hamiltonian Flights

Hamiltonian path:- Path that visits every node exactly once.

Algorithm:- 
1) Run a dp with two state. (Musk, and current node).

2) Musk tracks the visited nodes

3) Cur node helps to run dfs

4) Run dfs and keep answer stored in dp.



How to stay between time limit?
1) Use int for all variables except the variable that we do modulo on.

2) Early terminate when we reach n th node without visiting all other nodes.
*/
