

// this include only functional code no header files and main function is include
// The concept is we mark the element where it not follow the BST rule 
// we travel in inorder and check if prev value is greater then current value 
// we take if it is first time then first and middle 
// if this is second time then only store the last value
// if we encounter the bst rule broke two time then swap first and last
// else swap the first and middle only



class Solution {
    struct Node *prev;
    struct Node *first;
    struct Node *middle;
    struct Node *last;
  public:
    void inorder(Node *root)
    {
        if(root==NULL)
        return;
        inorder(root->left);
        if(prev!=NULL && root->data<prev->data)
        {
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else
            last=root;
        }
        prev=root;
        inorder(root->right);
    }
    void correctBST( struct Node* root )
    {
        // add code here.
        prev=first=middle=last=NULL;
        inorder(root);
        if(first && last) swap(first->data,last->data);
        else if(first && middle) swap(first->data,middle->data);
    }
};
