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
#define LLONG_MAX 1e15
const ll M =1e9+7;
const ll N =501;
//Idea is by Abdul Bari sir.
vector<vector<ll>>g(N,vector<ll>(N,LLONG_MAX));
vector<ll>dist(N,LLONG_MAX);
int32_t main()
{
    fast
    ll i,j,n,m,k,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n>>m>>q;
        while(m--)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            g[x][y]=min(g[x][y],z); //Minimum is being taken is case there's two road between same pair of city.
            g[y][x]=min(g[y][x],z);
        }
        for(i=1;i<=n;i++){g[i][i]=0;} //Makeing the elements of main diagonal zero.
        for(k=1;k<=n;k++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]); //n*n*n loop 
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(g[i][j]==LLONG_MAX){g[i][j]=-1;} //If there's no path. -1 is assigned
            }
        }
        while(q--)
        {
            ll x,y;
            cin>>x>>y;
            cout<<g[x][y]<<endl;
        }
    }

}
/*
//Application of floyd warshall algorithm
Shortest Routes II(CSES)
https://cses.fi/problemset/task/1672
Input
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

Output
5
5
8
-1
3

*/
