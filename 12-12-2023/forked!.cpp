#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f first
#define s second
#define pb push_back
int const mod=1e9+7;
void solve()
{
   ll a,b,k1,k2,q1,q2;
   cin>>a>>b>>k1>>k2>>q1>>q2;
   set<pair<ll,ll>>st;
   vector<pair<ll,ll>>pos={
        {-1*a,-1*b},
        {a,-1*b},
        {b,-1*a},
        {b,a},
        {a,b},
        {-1*a,b},
        {-1*b,a},
        {-1*b,-1*a}
   };
   map<pair<ll,ll>,ll>mp;
   for(int i=0;i<8;i++){
        mp[{pos[i].f,pos[i].s}]++;
   }
   for(auto it:mp)
   {
         ll fi=k1+it.f.f;
        ll si=k2+it.f.s;
        st.insert({fi,si});
   }
   ll count=0;
   for(auto it:mp)
   {
        ll fi=q1+it.f.f;
        ll si=q2+it.f.s;
        if(st.find({fi,si})!=st.end())
        count++;
   }
   cout<<count<<endl;
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

