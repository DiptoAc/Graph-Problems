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
vector<vector<ll>>capacity(501,vector<ll>(501)); //This is a 2d matrix.(Changes during runtime)
vector<ll>g[N]; //Adjacency list
ll bfs(vector<ll>&parent)
{
    fill(parent.begin(),parent.end(),-1); //Use fill 
    parent[1]=-2;
    queue<pair<ll,ll>>q;
    q.push({1,INF});
 
    while(q.size())
    {
        auto [cur,flow] = q.front();
        q.pop();
 
        for(auto chi:g[cur])
        {
            if(parent[chi] == -1 && capacity[cur][chi])
            {
 
                parent[chi]=cur;
                ll min_flow = min(flow,capacity[cur][chi]);
                if(chi==n)
                {
                    return min_flow;
                }
                q.push({chi,min_flow});
            }
        }
 
    }
    return 0;
}
ll max_flow()
{
    ll now_flow,total_flow=0;
    vector<ll>parent(n+1); //This vector is used to backtrack path from source to destination.
    while(now_flow = bfs(parent)) //Keep finding augmented path as long as possible.
    {
        total_flow+=now_flow; 
        ll idx = n;
        while(idx!=1)
        {
            capacity[parent[idx]][idx]-=now_flow; //Forward paths capacity decreases.
            capacity[idx][parent[idx]]+=now_flow; //That means reverse path now has flow capacity
            idx=parent[idx];
        }
    }
    return total_flow;
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
            ll x, y,c;
            cin>>x>>y>>c;
            g[x].pb(y);
            g[y].pb(x); //Add reverse graph with flow capacity of zero.
            capacity[x][y]+=c; //Positive path has capacity. Reverse path do not.
        }
        cout<<max_flow()<<endl; 
    }
}
/*
In this problem, 1 is always the source and n is always the destination.
*/
