

//this code contain only the functional code no header file or main function is included in it.

 TreeNode *merge(TreeNode* root1,TreeNode *root2)
    {
        if(root1==NULL && root2==NULL)
        return NULL;
        int val=0;
        if(root1)
        val+=root1->val;
        if(root2)
        val+=root2->val;
        TreeNode *node=new TreeNode(val);
        node->left=merge(root1==NULL?NULL:root1->left,root2==NULL?NULL:root2->left);
        node->right=merge(root1==NULL?NULL:root1->right,root2==NULL?NULL:root2->right);
      
        return node;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1,root2);
    }