#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//uniform_int_distribution<int> random(1, 1000000);
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
ll n,m,id=0;
vector<ll>g[N],rg[N],vis(N),in_scc(N),answer(N,-1),compressed_g[N],in_degree(N);
vector<vector<ll>>components(N);
stack<ll>stk;
/*
>>Kosaraju's alogorithm's first part
>>Pushes nodes into stack according to dfs leaving(completion) order
*/
void dfs(ll cur)
{
    vis[cur]=1;
    for(auto chi:g[cur])
    {
        if(vis[chi]){continue;}
        dfs(chi);
    }stk.push(cur);
}
/*
>>Kosaraju's algorithm second(final) part
>>Runs dfs on reversed graph and stores all node on this single scc
*/
void scc_detector(ll cur, vector<ll>&v)
{
    in_scc[cur]=id;
    v.pb(cur);
    for(auto chi:rg[cur])
    {
        if(in_scc[chi]){continue;}
        scc_detector(chi,v);
    }
}
/*
>>Returns the value position of -1 for 1 and 1 for -1
*/
ll rev(ll x)
{
    if(x>m){x-=m;}
    else{x+=m;}
    return x;
}
int32_t main()
{
    fast
    ll i,j=1,k,p,q,tc=1,cs=0;
    //cin>>tc;
    while(tc--)
    {
       cin>>n>>m;
       j=n;
       //Building the implication graph. And reverse implication graph
       while(j--)
       {
           char a,b;ll x,y;
           cin>>a>>x>>b>>y;
           if(a=='-'){x+=m;}
           if(b=='-'){y+=m;}
           g[rev(x)].pb(y);
           rg[y].pb(rev(x));
           g[rev(y)].pb(x);
           rg[x].pb(rev(y));
       }
       //Kosaraju
       for(i=1;i<=2*m;i++)
       {
           if(!vis[i]){dfs(i);}
       }
       ll impossible=0;
       while(stk.size())
       {
           ll t=stk.top();
           //cout<<t<<" ";
           stk.pop();
           if(in_scc[t]){continue;}
           id++; //id tracks the number of scc
           vector<ll>v;
           scc_detector(t,v); 
           components[id]=v;//Component stores all the nodes inside this(id th) scc
       }//Kosaraju ends
       for(i=1;i<=2*m;i++)
       {
           if(in_scc[i]==in_scc[rev(i)]){impossible=1;break;} //If -1 and 1 belongs to same scc. Unsatifiable.
           for(auto chi:g[i])
           {
               if(in_scc[chi]==in_scc[i]){continue;}
               compressed_g[in_scc[i]].pb(in_scc[chi]);//compress every scc to a single node
               in_degree[in_scc[chi]]++;
           }
       }if(impossible){cout<<"IMPOSSIBLE"<<endl;continue;}
       //Toposort on compressed graph (To start marking from the reverse)
       queue<ll>que;
       vector<ll>topo_order;
       for(i=1;i<=id;i++)
       {
           if(in_degree[i]==0){que.push(i);}
       }
       while(que.size())
       {
           ll node = que.front();
           que.pop();
           topo_order.pb(node);
           for(auto chi:compressed_g[node])
           {
               in_degree[chi]--;
               if(in_degree[chi]){continue;}
               que.push(chi);
           }
       }
       //toposort end
       reverse(topo_order.begin(),topo_order.end()); //Reverse the topo ordering to get values based on out degree.
       for(auto it:topo_order)
       {

           for(auto tt:components[it])
           {
               if(tt>n)
               {
                   ll x=rev(tt);
                   if(answer[x]==-1)
                   {
                       answer[x]=0;
                       answer[tt]=1;
                   }
               }
               else
               {
                   if(answer[tt]==-1)
                   {
                       answer[tt]=1;
                       answer[rev(tt)]=0;
                   }
               }
           }
       }
       for(i=1;i<=m;i++)
       {
           cout<<(answer[i]==1?"+ ":"- ");
       }cout<<endl;
    }
}
//Giant pizza/Cses
