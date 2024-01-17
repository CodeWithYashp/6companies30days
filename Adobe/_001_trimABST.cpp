/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* solve(TreeNode* root, int low, int high){
        if(root == NULL){
            return NULL;
        }

        TreeNode* lNode = solve(root->left, low, high);
        if(lNode != root -> left){
            root->left = lNode;
        }
        
        TreeNode* rNode = solve(root->right, low, high);
        if(rNode != root -> right){
            root->right = rNode;
        }

        if(root -> val > high || root -> val < low){
            return (root -> left) ? root -> left : root -> right;
        }

        return root;
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return solve(root, low, high);
    }
};