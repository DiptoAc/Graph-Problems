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
#define LLONG_MAX 1e16
const ll M =1e9+7;
const ll N =2e5;
vector<array<ll, 3>>g[N];
vector<ll>dist(N,LLONG_MAX);
ll n,m;
int32_t main()
{

    fast
    ll i,j,k,p,q,tc=1,cs=0;cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        cout<<"Case "<<++cs<<": "<<endl;
        vector<ll>v(n);
        for(auto &it:v){cin>>it;}
        while(m--)
        {
            ll x,y,z=0;
            cin>>x>>y;
            for(i=x-1;i<y;i++)
            {
                z^=v[i];
            }
            cout<<z<<endl;

        }

    }
}
//https://atcoder.jp/contests/abc192/tasks/abc192_e
/**
Instead of making three element pair, create a array of three element -Nynayem.
**/
