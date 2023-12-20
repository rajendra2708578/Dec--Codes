

// this code contain only the functional code no header files and main function is not included.

 bool solve(TreeNode *root)
    {
        if(root==NULL)
        return false;
        bool leftpart=false,rightpart=false;
        leftpart|=solve(root->left);
        if(leftpart==false)
        root->left=NULL;
        rightpart|=solve(root->right);
        if(rightpart==false)
        root->right=NULL;
        return leftpart|rightpart|(root->val==1);
    }
    TreeNode* pruneTree(TreeNode* root) {
         if(solve(root)==false)
         return NULL;
         else
         return root;
    }