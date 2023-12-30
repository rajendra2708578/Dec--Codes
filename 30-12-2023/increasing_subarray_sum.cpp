



#include<bits/stdc++.h>
using namespace std;
int t,n,x,a[5010],s[5010],dp[5010];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
		for(int i=1;i<=n;i++)dp[i]=-1e9;
		dp[0]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				dp[i-j+1]=max(dp[i-j+1],s[i]-s[j-1]);
		for(int i=n-1;i>=0;i--)dp[i]=max(dp[i],dp[i+1]);
        cout<<endl;
		int ans=-1e9;
		for(int i=0;i<=n;i++)printf("%d ",ans=max(ans,dp[i]+x*i));
		puts("");
	}
	return 0;
}

