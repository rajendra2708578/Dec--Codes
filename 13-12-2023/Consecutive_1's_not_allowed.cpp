
// This code include only functional code no header files or main function is included
// example of dp where we store index and if previous element is 1 we cannot use 1 again it has to 0 
const int mod=1e9+7;
	ll solve(long long int val,int index,int n,vector<vector<long long int>>&dp)
	{
	    if(index==n)
	    return 1;
	    if(dp[index][val]!=-1)
	    return dp[index][val];
	   ll way1=0,way2=0;
	   if(val==0)
	   way1=solve(1,index+1,n,dp);
	   way2=solve(0,index+1,n,dp);
	   
	  
	   return dp[index][val]=(way1+way2)%mod;
	}
	ll countStrings(int n) {
	    // code here
	    vector<vector<long long int>>dp(n+1,vector<long long int>(2,-1));
	    return solve(0,0,n,dp);
	}