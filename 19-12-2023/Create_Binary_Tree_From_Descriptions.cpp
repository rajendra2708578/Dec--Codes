
// this include only functional code no header files or main function is included in it
void dfs(TreeNode *rootn,unordered_map<int,vector<pair<int,int>>>mp,int value)
    {

        for(auto it:mp[value])
        {
            if(it.second==1)
            {
                TreeNode *temp=new TreeNode(it.first);
                rootn->left=temp;
                dfs(rootn->left,mp,it.first);
            }
            else
            {
                TreeNode *temp=new TreeNode(it.first);
                rootn->right=temp;
                dfs(rootn->right,mp,it.first);
            }
        }
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // unordered_map<int,vector<pair<int,int>>>mp;
        set<int>st,st1;
        unordered_map<int,TreeNode*>match;
        for(auto it:descriptions)
        {
            // mp[it[0]].push_back({it[1],it[2]});
          st.insert(it[1]);
          st1.insert(it[0]);
          st1.insert(it[1]);
        }
        // TreeNode *dummy=new TreeNode(-1);
        // TreeNode *temp=dummy;;
        int root=0;
        for(auto it:descriptions)
        {
            if(st.find(it[0])==st.end())
            {
                root=it[0];
                break;
            }
        }
        for(auto it:st1)
        {
            TreeNode *node=new TreeNode(it);
            match[it]=node;
        }
        for(auto it:descriptions)
        {
            auto x=match[it[0]];
            TreeNode *temp=match[it[1]];
            if(it[2]==1)
            {
                
                x->left=temp;
            }
            else
            {
                x->right=temp;
            }
        }
        return match[root];
        // TreeNode *rootn=new TreeNode(root);
        // dfs(rootn,mp,root);
        // return rootn;
    }