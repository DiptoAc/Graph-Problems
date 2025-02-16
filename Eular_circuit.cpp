//Cses- Mail delivery.
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
#define ld double
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl<<flush;
#define endl '\n'
#define INF 1e17
const ll M = 1e9+7;
const ll N = 1e5+1;
const ll LOG = 11;
const ld eps = 1e-15;
void debug(vector<ll> v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
ll n,m;
vector<ll>ans;
vector<set<ll>>g(N);
void eular_circuit(ll cur)
{
    while(g[cur].size())
    {
        ll chi = *g[cur].begin();
        g[cur].erase(chi);
        g[chi].erase(cur);
        eular_circuit(chi);
    }ans.pb(cur);
}
int32_t main()
{
    fast
    ll i,j=1,k,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        for(i=1;i<=m;i++)
        {
            ll x,y;
            cin>>x>>y;
            g[x].insert(y); //Using set since they said its a simple graph.
            g[y].insert(x); //You may need to use multiset according to the problme statement.
        }
        ll imp=0;
        for(i=1;i<=n;i++)
        {
            if((g[i].size()&1)){imp=1;}
        }
        eular_circuit(1);
        if(ans.size()!=m+1){imp=1;}
        if(imp){cout<<"IMPOSSIBLE"<<endl;continue;}
        debug(ans);
    }
}
/* 
THis is the classic problem of eular circuit.
1) If the sizze of ans is = m+1 it says - all path were visited.
2) We can't delete element of set during traversal. Therefore used while loop in dfs
3) The degree of all vertices must be a even number. Othewise they can create a eular curcuit.
*/
