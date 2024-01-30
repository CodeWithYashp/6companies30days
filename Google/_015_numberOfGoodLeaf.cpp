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
    vector<int> dfs(TreeNode* root, int dis, int &res){
        if(root == NULL)    return {0}; //null
        
        if(root->left == NULL && root->right == NULL)   return {1}; //leaf

        vector<int> left = dfs(root->left, dis, res);  //left
        vector<int> right = dfs(root->right, dis, res);  //right

        for(auto i: left){
            for(auto j: right){
                if((i && j) && i + j <= dis)    res++;
            }
        }

        vector<int> v;

        for(auto it: left){
            if(it && it + 1 < dis)  v.push_back(it + 1);
        }

        for(auto it: right){
            if(it && it + 1 < dis)    v.push_back(it + 1);
        }

        return v;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int res = 0;
        dfs(root, distance, res);
        return res;
    }
};