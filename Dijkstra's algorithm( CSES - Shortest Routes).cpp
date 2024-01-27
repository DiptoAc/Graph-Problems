#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl;
#define endl '\n'
const ll M =1e9+7;
const ll N =1e5+2;
vector<pair<ll,ll>>g[N];
vector<ll>dist(N,LLONG_MAX);
void dijkstra()
{
    //Use priority queue to work with the smallest distance node every time. It makes Dijkstra efficient.
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q; //That's how you make an ascending priority queue.
    q.push({0,1});
    while(q.size())
    {
        pair<ll,ll>t=q.top();    //The First element is distance, the second element is the length of the path(Weight).
        q.pop();
        if(dist[t.second]<t.first){continue;} //If the distance of the current node(t.second) is less than the suggested distance(t.first). Ignore the operation. This creates the difference between TLE and non TLE 
        ll a=t.second;
        ll d=t.first;
        dist[a]=d;
        for(auto [x,y]:g[a])
        {
            if(dist[x]>dist[a]+y){q.push({dist[a]+y,x});}
        }
    }
}
int32_t main()
{
    fast
    ll i,j,n,m,k,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        while(m--)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            g[x].pb({y,z}); //Input taken.(Directional)
        }
        dijkstra();
        for(i=1;i<=n;i++){cout<<dist[i]<<" ";}cout<<endl;
    }

}
/*
Shortest Routes I(CSES)
https://cses.fi/problemset/task/1671
*/
