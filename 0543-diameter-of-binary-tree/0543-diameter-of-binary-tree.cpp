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

int depth(TreeNode* root, int &height){
    if(root == NULL) return 0;

    int Lh = depth(root->left, height);
    int Rh = depth(root->right, height);

    height = max(height, Lh+Rh);
    return 1+max(Lh,Rh);
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {

        int ans = 0;
        depth(root, ans);
        return ans;
        
    }
};