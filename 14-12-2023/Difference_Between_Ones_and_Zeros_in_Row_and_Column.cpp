
// this code contain only functional code the header file and main files are not included


vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int n=grid.size(),m=grid[0].size();
        unordered_map<int,int>row,col;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        vector<vector<int>>ans(n,vector<int>(m));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int val=n-row[i];
                int val2=m-col[j];
                ans[i][j]=(row[i]+row[j])-(val+val2);
            }
        }
        return ans;
    }