/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 2. Add Two Numbers
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0, sum;
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    struct ListNode* result = dummy;

    while (l1 || l2 || carry) {
        sum = carry;
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }
        carry = sum/10;
        dummy->next = malloc(sizeof(struct ListNode));
        dummy = dummy->next;
        dummy->val = sum%10;
        dummy->next = 0;
    }

    return result->next;
}
