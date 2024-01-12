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
    int ans = 0;
    void makeGraph(TreeNode* root, vector<vector<int>> &adj){
        if(root == NULL){
            return ;
        }

        if(root -> left){
            adj[root->val].push_back(root -> left -> val);
            adj[root -> left -> val].push_back(root->val);
        }

        if(root -> right){
            adj[root->val].push_back(root -> right -> val);
            adj[root -> right -> val].push_back(root->val);
        }

        makeGraph(root -> right, adj);
        makeGraph(root -> left, adj);
    }

    void bfs(int s, vector<vector<int>> &adj, vector<bool> &visited){
        queue<int> q;
        
        q.push(s);

        while(!q.empty()){
            int k = q.size();

            while(k--){
                int a = q.front();
                q.pop();
                visited[a] = 1;
                for(int i = 0; i < adj[a].size(); i++){
                    if(!visited[adj[a][i]])
                        q.push(adj[a][i]);
                }
            }
            ans++;
        }
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> adj(100001);
        vector<bool> visited(100001);
        makeGraph(root, adj);
        ans = 0;
        bfs(start, adj, visited);
        return ans - 1;
    }
};