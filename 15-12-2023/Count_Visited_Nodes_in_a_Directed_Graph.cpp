


void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&edges,vector<int>&ans)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(vis[it]==0)
            dfs(it,vis,adj,edges,ans);
            else if(vis[it]==1)
            {
                unordered_set<int>st;
                st.insert(node);
                int cur=node;
                while(edges[cur]!=node)
                {
                    
                    cur=edges[cur];
                    st.insert(cur);
                }
                for(auto it:st)
                {
                    ans[it]=st.size();
                }
            }
        }
        vis[node]=2;
    }
    int find(int node,vector<int>&ans,vector<int>adj[])
    {
        if(ans[node]!=-1)
        return ans[node];
        int sum=1;
        for(auto it:adj[node])
        {
            sum+=find(it,ans,adj);
        }
        return sum;

    }
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n=edges.size();
        vector<int>ans(n,-1);
        vector<int>vis(n,0);
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            adj[i].push_back(edges[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,vis,adj,edges,ans);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i]==-1)
            {
                ans[i]=find(i,ans,adj);
            }
        }
        return ans;
    }