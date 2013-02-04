/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s;
        return calc(root, s);
    }
    /*
    s is the single-side maximum path sum for node root
    */
    int calc(TreeNode *root, int &s)
    {
        if (!root)
        {
            s = 0;
            return 0;
        }
        
        int leftpath, rightpath;
        int leftMax = calc(root->left, leftpath);
        int rightMax = calc(root->right, rightpath);
        int result; 
        
        if (!root->left && !root->right)
        {
            result = root->val;
        }
        else
        {
            if (!root->left)
            {
                result = max(rightMax, root->val + leftpath + rightpath);
            }
            else
            {
                if (!root->right)
                {
                    result = max(leftMax, root->val + leftpath + rightpath);
                }
                else
                {
                    result = max(max(leftMax, rightMax), root->val + leftpath + rightpath);
                }
            }
        }
        
        s = max(0, root->val + max(leftpath, rightpath));
        return result;
    }
};
