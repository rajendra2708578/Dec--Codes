
// trhs code contain only the functional code not any main or header file is included in it.


TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode *node=new TreeNode(val);
            node->left=root;
            return node;
        }
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty())
        {
            level++;
            int sz=q.size();
            if(level+1==depth)
            {
                for(int i=0;i<sz;i++)
                {
                    auto it=q.front();
                    q.pop();
                 
                      TreeNode *node=new TreeNode(val);
                      node->left=it->left;
                      it->left=node;
                  
                 
                      TreeNode *node1=new TreeNode(val);
                      node1->right=it->right;
                      it->right=node1;
                  
                    
                }
                break;
            }
            else
            {
                for(int i=0;i<sz;i++)
                {
                    auto it=q.front();
                    q.pop();
                    if(it->left)
                    q.push(it->left);
                    if(it->right)
                    q.push(it->right);
                }
            }
        }
        return root;
    }