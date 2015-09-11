class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = &dummy, *cur = head;
        while(cur != nullptr && cur->next != nullptr){
            ListNode *tmp = cur->next->next;
            prev->next = cur->next;
            prev->next->next = cur;
            cur->next = tmp;
            prev = cur;
            cur = tmp;
        }
        return dummy.next;
    }
};