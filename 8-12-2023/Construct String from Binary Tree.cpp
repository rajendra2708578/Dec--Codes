// This code only include functional code no header files and main function is included.

 string fun(int value)
    {
        string ans="";
        int sign=1;
        if(value==0)
        return "0";
        
        if(value<0)
        {
            sign=-1;
            value*=-1;
        }
        while(value)
        {
           ans+=(value%10)+'0';
            value/=10;
        }
        reverse(ans.begin(),ans.end());
        if(sign<0)
        ans="-"+ans;
        return ans;
    }
    void solve(TreeNode *root,string &str)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            str+=fun(root->val);
            return;
        }
        str+=fun(root->val);
        str+='(';
        solve(root->left,str);
        str+=')';
        if(root->right)
        {
            str+='(';
            solve(root->right,str);
            str+=')';
        }
    }
    string tree2str(TreeNode* root) {
        string str="";
        solve(root,str);
        return str;
    }