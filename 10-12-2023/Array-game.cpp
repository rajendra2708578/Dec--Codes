#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f first
#define s second
#define pb push_back
int const mod=1e9+7;
void solve()
{
   ll n,k;
   cin>>n>>k;
   vector<ll>vec(n);
   for(int i=0;i<n;i++)
   {
    cin>>vec[i];
   }
   sort(vec.begin(),vec.end());
   if(k>=3)
   {
    cout<<0<<endl;
   }
   else if(k==1)
   {
    ll minv=vec[0];
    for(int i=0;i<n-1;i++)
    {
        minv=min(minv,abs(vec[i+1]-vec[i]));

    }
    cout<<minv<<endl;
   }
   else
   {
    ll minv=vec[0];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ll v=abs(vec[j]-vec[i]);
                minv=min(minv,v);
                ll ind=lower_bound(vec.begin(),vec.end(),v)-vec.begin();
                if(ind<n)
                minv=min(minv,vec[ind]-v);
                if(ind>0)
                minv=min(minv,v-vec[ind-1]);
            }
        }
        cout<<minv<<endl;
    
    
   }
   
    
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