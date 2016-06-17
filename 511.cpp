/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        // Write your code here
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = head;
        ListNode* pre = &dummy;
        bool v1Found = false;
        bool v2Found = false;
        ListNode* v1Pre;
        ListNode* v1Cur;
        ListNode* v1Aft;
        ListNode* v2Pre;
        ListNode* v2Cur;
        ListNode* v2Aft;
        while((cur != NULL) && !((v1Found && v2Found) == true)){
            if(cur->val == v1){
                v1Found = true;
                v1Pre = pre;
                v1Cur = cur;
                v1Aft = cur->next;
            }
            if(cur->val == v2){
                v2Found = true;
                v2Pre = pre;
                v2Cur = cur;
                v2Aft = cur->next;
            }
            pre = cur;
            cur = cur->next;
        }
        if(v1Found && v2Found){
            if(v1Aft == v2Cur){
                v1Pre->next = v2Cur;
                v2Cur->next = v1Cur;
                v1Cur->next = v2Aft;
            }
            else if(v2Aft == v1Cur){
                v2Pre->next = v1Cur;
                v1Cur->next = v2Cur;
                v2Cur->next = v1Aft;
            }
            else{
                v1Pre->next = v2Cur;
                v2Cur->next = v1Aft;
                v2Pre->next = v1Cur;
                v1Cur->next = v2Aft;
            }
        }
        return dummy.next;
    }
};
