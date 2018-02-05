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
    ListNode *detectCycle(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        ListNode *slow = dummy;
        ListNode *fast = dummy;       
        dummy->next = head;
        while (true) {
            if (!fast || !fast->next) return nullptr;
            
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                slow = dummy;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
    }
};
