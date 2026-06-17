class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // 1st case : both trees are empty
        if(p==NULL && q==NULL){
            return true;        // same elements,same structure
        }

        // 2nd case : either of the trees is empty i.e structures don't match
        if(p==NULL || q==NULL){
            return false;       // different structures
        }

        // 3rd case : if their values don't match
        if(p->val != q->val){
            return false;
        }

        // final case : check if both left and right subtrees match for p, q i.e same elements and same structure
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);  // uses Recursion
    }
};
