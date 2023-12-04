#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f first
#define s second
#define pb push_back
int const mod=1e9+7;
void solve()
{
    ll n,p,l,t;
    cin>>n>>p>>l>>t;
    ll start=0,end=n;
    ll total=(n/7);
    if(n%7)
        total+=1;
    ll ans=0;
    while(start<=end)
    {
        ll mid=(start+end)/2;
        ll mark=mid*l;
        mark+=min(mid*2,total)*t;
        if(mark>=p)
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }

    }
    cout<<n-ans<<endl;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

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