class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        ListNode *prev = &dummy, *cur = head;
        while(cur){
            int i = 0;
            ListNode *begin = cur, *tail = begin;
            while(cur && i < k){
                cur = cur->next;
                i++;
            }
            if(i == k){
                ListNode *rh = nullptr;
                while(begin != cur){
                    ListNode *tmp = begin->next;
                    begin->next = rh;
                    rh = begin;
                    begin = tmp;
                }
                prev->next = rh;
                prev = tail;
            }
            else
                prev->next = tail;
        }
        return dummy.next;
    }
};