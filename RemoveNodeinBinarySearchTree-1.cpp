//反人类的做法
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        if(root == NULL) return root;
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            res.push_back(temp->val);
            if(temp->right != NULL){
                st.push(temp->right);
            }
            if(temp->left != NULL){
                st.push(temp->left);
            }
        }
        sort(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++){
            if(res[i] == value){
                res.erase(res.begin() + i);
                break;
            }
        }
        return sortedArrayToBST(res);
        // write your code here
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        int n = nums.size();
        return sortedArrayToBST_sub(nums, 0, n - 1);
    }
    
    TreeNode* sortedArrayToBST_sub(vector<int>& nums, int a, int b){
        int mid = (a + b) / 2;
        if(b - a == 0){
            TreeNode* res = new TreeNode(nums[b]);
            return res;
        }
        if(b - a == 1){
            TreeNode* res = new TreeNode(nums[b]);
            res->left = sortedArrayToBST_sub(nums, a, a);
            return res;
        }
        TreeNode* res = new TreeNode(nums[mid]);
        res->left = sortedArrayToBST_sub(nums, a, mid - 1);
        res->right = sortedArrayToBST_sub(nums, mid + 1, b);
        return res;
    }
};
