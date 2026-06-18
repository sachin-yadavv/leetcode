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
TreeNode *first, *middle, *last, *prev;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);

        if (prev != NULL && root->val < prev->val) {

            // First violation
            if (first == NULL) {
                first = prev;
                middle = root;
            }
            // Second violation
            else {
                last = root;
            }
        }

        // Update previous node
        prev = root;

        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;

        prev = new TreeNode(INT_MIN);

        inorder(root);

        // Non-adjacent swapped nodes
        if (first && last)
            swap(first->val, last->val);

        // Adjacent swapped nodes
        else if (first && middle)
            swap(first->val, middle->val);
    }
};