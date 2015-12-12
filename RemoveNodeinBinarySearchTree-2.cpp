class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        if(root == NULL) return root;
        TreeNode dummyNode(0);
        dummyNode.left = root;
        TreeNode* cur = root;
        TreeNode* pre = &dummyNode;
        bool found = false;
        int direction = 0;
        while(cur != NULL){
            if(cur->val == value){
                found = true;
                break;
            }
            pre = cur;
            if(value < cur->val){
                cur = cur->left;
                direction = 0;
                continue;
            }
            if(value > cur->val){
                cur = cur->right;
                direction = 1;
                continue;
            }
        }
        if(found == false) return root;
        
        if(cur->left == NULL && cur->right == NULL){
            if(direction == 0){
                pre->left = NULL;
            }
            else{
                pre->right = NULL;
            }
            delete(cur);
            return dummyNode.left;
        }
        if(cur->left != NULL && cur->right == NULL){
            if(direction == 0){
                pre->left = cur->left;
            }
            else{
                pre->right = cur->left;
            }
            delete(cur);
            return dummyNode.left;
        }
        if(cur->left == NULL && cur->right != NULL){
            if(direction == 0){
                pre->left = cur->right;
            }
            else{
                pre->right = cur->right;
            }
            delete(cur);
            return dummyNode.left;
        }
        TreeNode* subTreeCur = cur->left;
        TreeNode* subTreePre = NULL;
        while(subTreeCur->right != NULL){
            pre = cur;
            cur = cur->right;
        }
        if(subTreePre == NULL){
            subTreeCur->right = cur->right;
            delete(cur);
            if(direction == 0){
                pre->left = subTreeCur;
                return dummyNode.left;
            }
            else{
                pre->right = subTreeCur;
                return dummyNode.right;
            }
        }
        subTreePre->right = subTreeCur->left;
        subTreeCur->left = cur->left;
        subTreeCur->right = cur->right;
        delete(cur);
        if(direction == 0){
            pre->left = subTreeCur;
            return dummyNode.left;
        }
        else{
            pre->right = subTreeCur;
            return dummyNode.right;
        }
        // write your code here
    }
};
