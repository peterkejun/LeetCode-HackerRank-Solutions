/*
Problem Name: Add Two Numbers
Problem Algorithm: Linked List
Problem URL: https://leetcode.com/problems/add-two-numbers/
*/



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *sum_head = NULL;
        ListNode *current1 = l1, *current2 = l2, *previous_sum = sum_head;;
        while (current1 || current2) {
            int val1 = current1 == NULL ? 0 : current1->val;
            int val2 = current2 == NULL ? 0 : current2->val;
            ListNode *digit = new ListNode(0);
            digit->val = (val1 + val2 + carry) % 10;
            digit->next = NULL;
            carry = (val1 + val2 + carry) / 10;
            current1 = current1 == NULL ? NULL : current1->next;
            current2 = current2 == NULL ? NULL : current2->next;
            if (sum_head == NULL) {
                sum_head = digit;
                previous_sum = digit;
            } else {
                previous_sum->next = digit;
                previous_sum = previous_sum->next;
            }
        }
        if (carry != 0) {
            ListNode *digit = new ListNode(1);
            previous_sum->next = digit;
        }
        return sum_head;
    }