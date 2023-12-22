


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f first
#define s second
#define pb push_back
int const mod=1e9+7;
struct node{
    int x,y,sum;
};
bool static comp(const node &a,const node &b)
{
    return a.sum>b.sum;
}
void solve()
{
  ll n;
  cin>>n;
  node a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i].x;
  }
  for(int i=0;i<n;i++)
  {
    cin>>a[i].y;
    a[i].sum=a[i].x+a[i].y;
  }
  sort(a,a+n,comp);
  ll ans=0;
  for(int i=0;i<n;i++)
  {
    if(i%2==0)
    ans+=a[i].x-1;
    else
    ans-=a[i].y-1;
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
 