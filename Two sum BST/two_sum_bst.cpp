// this code contain only the functional code no header files and main function is included.

class Itera{
     stack<TreeNode*>st;
     bool reverse=true;
     public:
     Itera(TreeNode *root,bool isReverse)
     {
         reverse=isReverse;
         pushAll(root);
     }
     int next()
     {
         auto it=st.top();
         st.pop();
         if(reverse)
         pushAll(it->left);
         else
         pushAll(it->right);

         return it->val;
     }
    void pushAll(TreeNode *root)
     {
         while(root!=NULL)
         {
             st.push(root);
             if(reverse)
             root=root->right;
             else
             root=root->left;
         }
     }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        Itera l(root,false);
        Itera r(root,true);
        int i=l.next(),j=r.next();
        while(i<j)
        {
            if(i+j==k)return true;
            else if(i+j<k)i=l.next();
            else
            j=r.next();
        }
        return false;
    }
};