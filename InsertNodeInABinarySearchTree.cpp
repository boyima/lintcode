class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> res;
        if(root == NULL) return res;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while(!st.empty() || cur != NULL){
            if(cur != NULL){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                if(cur->val > k2) break;
                st.pop();
                if(cur->val >= k1 && cur->val <= k2){
                    res.push_back(cur->val);
                }
                cur = cur->right;
            }
        }
        return res;
    }
};
