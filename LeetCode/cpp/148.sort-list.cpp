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
    ListNode* merge_sort(ListNode *root) {
        if (!root) return nullptr;
        if (!root->next) return root;

        ListNode *dummy = new ListNode(0);
        dummy->next = root;
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *left_start = root;
        ListNode *right_start = slow->next;
        
        slow->next = nullptr;
        
        ListNode *left = merge_sort(left_start);
        ListNode *right = merge_sort(right_start);
        return merge(left, right);
    }
        
    ListNode* merge(ListNode *l, ListNode *r) {
        ListNode *dummy = new ListNode(0);
        ListNode *it = dummy;
        while (l && r) {
            if (l->val < r->val) {
                it->next = l;
                l = l->next;
            } else {
                it->next = r;
                r = r->next;
            }
            it = it->next;
        }
        it->next = l ? l : r;
        return dummy->next;
    }
    
    ListNode* sortList(ListNode* head) {
        return merge_sort(head);
    }
};
