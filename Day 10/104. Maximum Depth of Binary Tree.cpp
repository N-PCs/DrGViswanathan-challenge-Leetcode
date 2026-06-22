class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Solve base case
        if(root==nullptr){
            return 0;
        }

        // use recursion to determine left and right height
        int leftDepth=maxDepth(root->left);
        int rightDepth=maxDepth(root->right);
        
        return max(leftDepth,rightDepth)+1;
    }
};
