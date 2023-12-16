

// the concept is the contribution of each element

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f first
#define s second
#define pb push_back
int const mod=1e9+7;
void solve()
{
    ll n;
    cin>>n;
    unordered_map<ll,vector<ll>>mp;
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        mp[x].pb(i);
    }
    ll ans=0;
    for(auto it:mp)
    {
        ll sz=it.s.size();
        vector<ll>pre(sz);
        pre[sz-1]=(n-it.s[sz-1])+1;
        for(int i=sz-2;i>=0;i--)
        {
            pre[i]=pre[i+1]+(n-it.s[i])+1;
        }
        for(int i=0;i<sz-1;i++)
        {
            ans+=it.s[i]*(pre[i+1]);
        }
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
 