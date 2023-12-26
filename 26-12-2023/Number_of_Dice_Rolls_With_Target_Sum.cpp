

// this code contain only the functional code no header and main function is included
 const int mod=1e9+7;
    int solve(int index,int k,int target,int n,vector<vector<int>>&dp)
    {
        if(index==n)
        {
            if(target==0)
            return 1;
            else
            return 0;
        }
        if(dp[index][target]!=-1)
        return dp[index][target];
        int val=0;
        for(int i=1;i<=k;i++)
        {
            if(target>=i)
            {
                val=(val+solve(index+1,k,target-i,n,dp))%mod;
            }
        }
        return dp[index][target]=val%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(0,k,target,n,dp);
    }