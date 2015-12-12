class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if(T1 == NULL || T2 == NULL){
            if(T1 == NULL && T2 != NULL) return false;
            return true;
        }
        vector<TreeNode*> possibleHead;
        stack<TreeNode*> st;
        TreeNode* cur;
        st.push(T1);
        while(!st.empty()){
            cur = st.top();
            st.pop();
            if(cur->val == T2->val){
                possibleHead.push_back(cur);
            }
            if(cur->right != NULL){
                st.push(cur->right);
            }
            if(cur->left != NULL){
                st.push(cur->left);
            }
        }
        int n = possibleHead.size();
        for(int i = 0; i < n; i++){
            if(isSameTree(possibleHead[i], T2)) return true;
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL){
            if(p == NULL && q == NULL) return true;
            return false;
        }
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(p);
        st2.push(q);
        while(!st1.empty() && !st2.empty()){
            TreeNode* node1 = st1.top();
            TreeNode* node2 = st2.top();
            if(node1->val != node2->val) return false;
            st1.pop();
            st2.pop();
            if(node1->left != NULL || node2->left != NULL){
                if(node1->left != NULL && node2->left != NULL){
                    st1.push(node1->left);
                    st2.push(node2->left);
                }
                else{
                    return false;
                }
            }
            if(node1->right != NULL || node2->right != NULL){
                if(node1->right != NULL && node2->right != NULL){
                    st1.push(node1->right);
                    st2.push(node2->right);
                }
                else{
                    return false;
                }
            }
        }
        if(!st1.empty()|| !st2.empty()) return false;
        return true;
    }
};
