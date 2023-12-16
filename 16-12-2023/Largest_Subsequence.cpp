
// third C question of Largest Subsequence Codeforces round 915(Div 2) 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f first
#define s second
#define pb push_back
int const mod=1e9+7;
bool check(string &str)
{
    for(int i=0;i<str.size()-1;i++)
    {
        if(str[i]>str[i+1])
        return false;
    }
    return true;
}
void solve()
{
    ll n;
    cin>>n;
    string str;
    cin>>str;
    // char maxv=str[0];
    // for(auto it:str)
    // {
    //     if(maxv<it)
    //     // maxv=it;
    // }
    // unorderd_map<char,ll>mp;
   reverse(str.begin(),str.end());
   vector<char>maxarr(n);
   char maxv=str[0];
   for(int i=0;i<n;i++)
   {
        maxv=max(maxv,str[i]);
        maxarr[i]=maxv;
   }
   
   reverse(maxarr.begin(),maxarr.end());
   reverse(str.begin(),str.end());
//    for(auto it:maxarr)
//    {
//     cout<<it<<" ";
//    }
//    cout<<endl;
   vector<ll>index;
   string ans="";
   for(int i=0;i<n;i++)
   {
        if(maxarr[i]==str[i])
        {
            ans+=str[i];
            index.pb(i);
        }
   }
   reverse(ans.begin(),ans.end());
//    cout<<ans<<endl;
   for(int i=0;i<index.size();i++)
   {
        str[index[i]]=ans[i];
   }
   if(check(str))
   {
        ll count=0;
        for(auto it:ans)
        {
            if(it!=maxarr[0])
            {
                count++;
            }
        }
        cout<<count<<endl;
   }
   else
   {
        cout<<-1<<endl;
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

