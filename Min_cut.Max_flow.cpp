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
const ll M = 998244353;
const ll N = 1e6+1;
const ll LOG = 11;
void debug(vector<ll> v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
ll n,m;
vector<vector<ll>>capacity(501,vector<ll>(501,0));
vector<ll>g[501],vis(501);
ll bfs(vector<ll>&parent)
{
    fill(parent.begin(),parent.end(),-1);
    parent[1]=1;
    ll mn_flow = INF;
    queue<pair<ll,ll>>qu;
    qu.push({1,INF});
    while(qu.size())
    {
        auto [cur,flow]=qu.front();
        qu.pop();
        mn_flow=min(mn_flow,flow);
        if(cur==n){return mn_flow;}
        for(auto chi:g[cur])
        {
            if(parent[chi]!=-1 || capacity[cur][chi]==0){continue;}
            qu.push({chi,capacity[cur][chi]});
            parent[chi]=cur;
        }
    }return 0;
}
ll max_flow()
{
    ll total_flow=0,flow;
    vector<ll>parent(n+1);
    while(flow=bfs(parent))
    {
        total_flow+=flow;
        ll now = n;
        while(now!=1)
        {
            ll prev = parent[now];
            capacity[prev][now]-=flow;
            capacity[now][prev]+=flow;
            now=prev;
        }
    }
    return total_flow;

}

void dfs(ll cur)
{
    vis[cur]=1;
    for(auto chi:g[cur])
    {
        if(vis[chi] || capacity[cur][chi]==0){continue;}
        dfs(chi);
    }
}

int32_t main()
{
    fast
    ll i,j=1,k,p,q,tc=1,cs=0;
    //cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            ll x,y;
            cin>>x>>y;
            capacity[x][y]++; //Every road has 1 capacity worth of flow.
            capacity[y][x]++; //Bi-directional road.
            g[x].pb(y); 
            g[y].pb(x);
        }
        //Step 1: Find the max flow.
        cout<<max_flow()<<endl;

        //This dfs visits all reachable nodes using unused roads.
        dfs(1);
        
        for(i=1;i<=n;i++)
        {
            if(!vis[i]){continue;}
            for(auto chi:g[i])
            {
                //If a node is visited and adjacent node is unvisited. Then this road is a must.
                if(!vis[chi]){cout<<i<<" "<<chi<<endl;}
            }
        }
    }
}
