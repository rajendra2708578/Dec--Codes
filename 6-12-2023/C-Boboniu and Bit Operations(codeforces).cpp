// we try to set the ans form 0 to 2^9 check from minimum possible value to maximum run a loop.
// for each i value we check if it is possible to get (a[i]&b[j])|i==i means the set bits are same/same place or altest less compared to I 
// but set bits on the Ith set bits not in any zero places.
// we will check for every value present in the vector of a

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f first
#define s second
#define pb push_back
int const mod=1e9+7;
// ll solve(ll index,ll sum,vector<ll>&arr,vector<ll>&vec,vector<ll>&dp)
// {
//     if(index==arr.size())
//     return sum;
//     ll value=INT_MAX;
//     if(dp[index]!=-1)
//     return dp[index];
//     for(auto it:vec)
//     {
//         value=min(value,solve(index+1,sum|(arr[index]&it),arr,vec,dp));
//     }
//     return dp[index]=value;
// }
void solve()
{
  ll n,m;
    cin>>n>>m;
    vector<ll>vec(n),arr(m);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    ll ans=0;
    for(int i=0;i<(1<<9);i++)
    {
        bool poss=true;
        for(int j=0;j<n;j++)
        {
            ll f=0;
            for(int k=0;k<m;k++)
            {
                if(((vec[j]&arr[k])|i)==i)
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                poss=false;
                break;
            }
        }
        if(poss==true)
        {
            // cout<<i<<" possible index is "<<endl;
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
   

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

