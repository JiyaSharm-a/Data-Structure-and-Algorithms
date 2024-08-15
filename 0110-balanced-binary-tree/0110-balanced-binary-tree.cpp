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
public:
    int height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int ans = max(leftHeight,rightHeight) + 1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        // base case
        if(root == NULL)
        return true;

        // rule 3
        int leftSubtreeH = height(root->left);
        int rightSubtreeH = height(root->right);

        int difference = abs(leftSubtreeH - rightSubtreeH);

        bool rule3 = (difference <= 1);

        // rule 1
        bool leftans = isBalanced(root->left);

        // rule 2
        bool rightans = isBalanced(root->right);

        if(rule3 && leftans && rightans)
        return true;


        return false; 

    }
};