
// this function contain only the functional code no header files and main function is included
// the logic is simple first make sure that all elements come to one position (1,1) then travel to whole matrix
// visit every possible index

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f first
#define s second
#define pb push_back
int const mod=1e9+7;
string fun(pair<ll,ll>fi,pair<ll,ll>se,string str,ll n,ll m)
{
        ll a=fi.f,b=fi.s,c=se.f,d=se.s;
        // cout<<a<<" "<<b<<endl;
        // cout<<c<<" "<<d<<endl;
        for(auto it:str)
        {
            if(it=='D')
            {
                if(a<n)
                a++;
            }
            else if(it=='U')
            {
                if(a>1)
                a--;
            }
            else if(it=='L')
            {
                if(b>1)
                b--;
            }
            else if(it=='R')
            {
                if(b<m)
                b++;
            }

            if(a==c && b==d)
            return str;
        }
        string ans="";
        if(a<c)
        {
            while(a<c)
            {
                ans+='D';
                a++;
            }
        }
        else if(a>c)
        {
            while(a>c)
            {
                ans+='U';
                a--;
            }
        }

        if(b<d)
        {
            while(b<d)
            {
                ans+='R';
                b++;
            }
        }
        else if(b>d)
        {
            while(b>d)
            {
                ans+='L';
                b--;
            }
        }
        // cout<<ans<<endl;
        return str+ans;
}
void solve()
{
   ll n,m,k;
   cin>>n>>m>>k;
   vector<pair<ll,ll>>fi,se;
   for(int i=0;i<k;i++)
   {
    ll a,b,c,d;
    cin>>a>>b;
    cin>>c>>d;
    fi.pb({a,b});
    se.pb({c,d});
   }
   string ans="";
   for(int i=0;i<n-1;i++)
   ans+='U';
   for(int i=0;i<m-1;i++)
   {
    ans+='L';
   }
   bool lefttoright=true;
   for(int i=0;i<n;i++)
   {
    for(int j=1;j<m;j++)
    {
        if(lefttoright)
        ans+='R';
        else
        ans+='L';
    }
    if(i!=n-1)
    ans+='D';
    lefttoright=!lefttoright;
   }
   cout<<ans.size()<<endl;
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
 