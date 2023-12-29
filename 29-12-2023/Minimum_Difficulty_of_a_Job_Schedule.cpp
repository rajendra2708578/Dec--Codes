

// this code contain only the functional code no main and header files are included

int dp[305][11][1001];
class Solution {
public:
    int solve(int index,vector<int>&job,int d,int maxv)
    {
        if(d==0)
        {
            if(index==job.size())
            {
                return 0;
            }
            else
            return 1e9;
        }
        if(index==job.size())
        {
            if(d>0)
            return 1e9;
            else
            {
                return 0;
            }
        }
        if(dp[index][d][maxv]!=-1)
        return  dp[index][d][maxv];
        int include=1e9,non=1e9;
        include=solve(index+1,job,d,max(maxv,job[index]));
        if(d>=1)
        non=solve(index+1,job,d-1,0)+max(maxv,job[index]);

        return dp[index][d][maxv]=min(non,include);
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<d+1;j++)
            {
                for(int k=0;k<=1000;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        int val=solve(0,jobDifficulty,d,jobDifficulty[0]);
        if(val>=1e9)
        return -1;
        else
        return val;
    }
};