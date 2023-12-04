#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+6;
long long f[maxn][2];
long long l[maxn],r[maxn];
vector<int> e[maxn];
int n,T;
void dfs(int u,int fa){
	f[u][0]=f[u][1]=0;
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs(v,u);
		f[u][0]+=max(abs(l[u]-l[v])+f[v][0],abs(l[u]-r[v])+f[v][1]);
		f[u][1]+=max(abs(r[u]-l[v])+f[v][0],abs(r[u]-r[v])+f[v][1]);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1,0);
		cout<<max(f[1][0],f[1][1])<<'\n';
		for(int i=1;i<=n;i++)e[i].clear();
	}
	return 0;
}