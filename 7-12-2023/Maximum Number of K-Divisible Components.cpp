
//This code only have functional code the header files and main function are not included in this
// we use dfs technique to get the count of the sub tree which are divisible by k
// if a leaf node is not divisible by k,it must be in the same components as it parent node so we merge it with its parentnode
// if a leaf node is divides by k, it will be in its own components so we separate it from its parent node.
// with every dfs travel we decide wheather to include or separate based on the fact that the subtree sum is divisible by K or not
long long int dfs(int node,int par,vector<int>adj[],long long int &count,vector<int>&values,int k)
    {
        long long int val=values[node];
        for(auto it:adj[node])
        {
            if(it==par)
            continue;
            val+=dfs(it,node,adj,count,values,k);
        }
        if(val%k==0)
        {
            // cout<<node<<" node and parent "<<par<<" "<<val<<endl;
            count++;
            return 0;
        }
        else
        return val;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int>adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        long long int count=0;
        dfs(0,-1,adj,count,values,k);
        return count>=1?count:1;
	}