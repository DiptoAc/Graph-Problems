https://codeforces.com/contest/1388/problem/D
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
const ll M =998244353;
const ll N =2e5+1;
vector<ll>in(N),vis(N),to(N),v(N),ans;
ll sum=0;
int32_t main()
{
    fast
    ll i,j,k,n,m,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n;
        deque<ll>dq;
        for(i=1;i<=n;i++){cin>>v[i];}
        for(i=1;i<=n;i++)
        {
            cin>>k;
            if(k==-1){continue;}
            in[k]++;
            to[i]=k;
        }
        //There's no cycle.
        for(i=1;i<=n;i++)
        {
            //So every component has at least 1 node whose in degree is zero.
            //Let's store those nodes in a deque
            if(in[i]==0)
            {
                if(v[i]>=0){dq.push_front(i);}  //We should work with non-negative elements first.
                else{dq.push_back(i);}          //And negative element last.
            }
        }
        vector<ll>neg;
        while(dq.size())
        {
            ll frnt=dq.front();
            dq.pop_front();
            vis[frnt]=1;
            if(v[frnt]<0){neg.push_back(frnt);} //We'll work with the negative elements later. For now store them somewhere else.
            else
            {
                ans.pb(frnt);
                v[to[frnt]]+=v[frnt];
                sum+=v[frnt];
            }
            in[to[frnt]]--;
            if(vis[to[frnt]]){continue;}
            if(in[to[frnt]]==0)
            {
                if(v[to[frnt]]>=0){dq.push_front(to[frnt]);}
                else{dq.push_back(to[frnt]);}
            }
        }                                       //After finishing this loop, all the positive elements are gone. Now, lets see what we can do about those naughty negatives.
        for(i=neg.size()-1;i>=0;i--)            //We will take the negative element with the lowest out degree first.
        {
            sum+=v[neg[i]];                     
            ans.pb(neg[i]);
        }
        cout<<sum<<endl;
        for(auto it:ans){cout<<it<<" ";}cout<<endl;

    }
}
