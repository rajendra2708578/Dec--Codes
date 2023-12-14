
// this code contain only functional code the header file and main files not included
// The idea the concept is simple diff means if we choose the different color then previous value* (k-1) options we have 
// and the previous diff is the present same and the and the total option for the i index is same +diff

	const int mod=1e9+7;
    long long countWays(int n, int k){
        // code here
        vector<long long int>dp(n+1,-1);
        dp[1]=k;
        long long same=k,diff=k;
        for(int i=2;i<=n;i++)
        {
            same=diff;
            diff=dp[i-1]*(k-1);
            diff%=mod;
            dp[i]=(same+diff);
            dp[i]%=mod;
        }
        return dp[n];
    }