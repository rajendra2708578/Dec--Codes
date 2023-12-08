

//Let's consider 2
 


//	n≤m. Then we can calculate this product directly in O(n2)


//n>m Note that there are only m  possible remainders under division by m, so some 2 numbers of n have the same remainder. 
//Then their difference is divisible by m, so the entire product is 0 mod m
.//

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f first
#define s second
#define pb push_back
int const mod=1e9+7;
void solve()
{
   ll n,m;
   cin>>n>>m;
   vector<ll>arr(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   if(n>m)
   {
    cout<<0<<endl;
   }
   else
   {
         ll total=1;
     for(int i=0;i<n-1;i++)
     {
         for(int j=i+1;j<n;j++)
     {
           ll value=abs(arr[i]-arr[j])%m;
           total=(total*value)%m;
            total%=m;
     }
     }
      cout<<total%m<<endl;
   }
  
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // ll t;
    // cin>>t;
    // while(t--)
    // {
        solve();
    // }
    return 0;
}



