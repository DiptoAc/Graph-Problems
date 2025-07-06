#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl<<flush;
#define endl '\n'
#define INF 1e17
const ll M = 998244353;
const ll N = 1e6+1;
const ll LOG = 11;
void debug(vector<ll> v){for(auto it:v){cout<<it<<" ";}cout<<endl;}

ll n,m,bridge=0;
vector<ll>g[N],entry_time(N,INF),min_time(N,INF),vis(N);
vector<pair<ll,ll>>ans;
void dfs(ll cur, ll par, ll time)
{
    vis[cur] = 1;
    entry_time[cur] = min_time[cur] = time;
    for(auto chi:g[cur])
    {
        if(chi == par){continue;}
        if(!vis[chi])
        {
            dfs(chi,cur,time+1);
        }
        min_time[cur] = min(min_time[cur],min_time[chi]);
    }
    if(entry_time[par] < min_time[cur])
    {
        bridge++; //The number of articulation bridges.
        if(par>cur){swap(par,cur);}
        ans.pb({par,cur}); //Ans contains the list of articulation bridges.
    }
}
int32_t main()
{
    fast
    ll i,j=1,k,p,q,tc=1,cs=0;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        bridge=0;
        for(i=1;i<=m;i++)
        {
            ll x,y;
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        dfs(1,0,1);
        for(i=0;i<=n;i++)
        {
            entry_time[i] = min_time[i] = INF;
            vis[i]=0;
            g[i].clear();
        }
        cout<<"Caso #"<<++cs<<endl;
        if(!bridge)
        {
            cout<<"Sin bloqueos"<<endl;continue;
        }
        cout<<bridge<<endl;
        sort(ans.begin(),ans.end());
        for(auto [x,y]:ans){cout<<x<<" "<<y<<endl;}
            ans.clear();
    }
}
/*
CriticaL Edges - Spoj
*/
