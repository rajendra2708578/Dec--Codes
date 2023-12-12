
//this code contain only the functional part no header files and main function is included.
// logic is simple start from first column ,any element of column 
// can travel right, diagoanl right up and down till we can't move
// check all possible cases until we reach end column.

int solve(int i,int j,vector<vector<int>>&vec,int n,int m,vector<vector<int>>&dp)
    {
        if(j==m-1)
        return vec[i][j];
        if(dp[i][j]!=-1)
        return dp[i][j];
        int a=0,b=0,c=0;
        if(j<m-1)
        a+=solve(i,j+1,vec,n,m,dp)+vec[i][j];
        if(i>0 && j<m-1)
        b+=solve(i-1,j+1,vec,n,m,dp)+vec[i][j];
        if(i<n-1 && j<m-1)
        c+=solve(i+1,j+1,vec,n,m,dp)+vec[i][j];
        
        return dp[i][j]=max(a,max(b,c));
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int maxv=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        { 
            maxv=max(maxv,solve(i,0,M,n,m,dp));
        }
        return maxv;
    }