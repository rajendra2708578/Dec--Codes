

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
   ll arr[n];
   for(int i=0;i<n;i++)
   {
    cin>>arr[i];
   }
   ll l=0,r=1e9;
   for(int i=0;i<n;i++)
   {
        if(arr[i]==arr[i+1])
        continue;
        if(i+1<n && arr[i]<arr[i+1])
        {
            r=min(r,(arr[i]+arr[i+1])/2);
        }
        else if(i+1<n && arr[i]>arr[i+1])
        {
            l=max(l,(arr[i]+arr[i+1]+1)/2);
        }
   }
//    cout<<l<<" "<<r<<endl;
   if(l>r)
   cout<<-1<<endl;
   else
   cout<<l<<endl;
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

