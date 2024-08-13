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
    void postorder(TreeNode* root,vector<int> &vec)
    {
        // base case
        if(root == NULL)
        return;

        // right
        postorder(root->right,vec);
        // left
        postorder(root->left,vec);
        // root
        vec.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        // postorder -> right left root
        vector<int> vec;
        postorder(root,vec);
        return vec;
    }
};