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
 struct Result {
  bool isBST;
  int max;
  int min;
  int sum;
  Result() : isBST(false) {}
  Result(bool isBST, int max, int min, int sum)
    : isBST(isBST), max(max), min(min), sum(sum) {}
};

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        traverse( root, ans );
        return ans;
    }

    Result traverse(TreeNode* root, int& ans) {
        if (root == nullptr)
        return Result(true, INT_MIN, INT_MAX, 0);

        const Result left = traverse(root->left, ans);
        const Result right = traverse(root->right, ans);

        if (!left.isBST || !right.isBST)
        return Result();
        if (root->val <= left.max || root->val >= right.min)
        return Result();

        const int sum = root->val + left.sum + right.sum;
        ans = max(ans, sum);
        return Result(true, max(root->val, right.max), min(root->val, left.min), sum);
    }
};