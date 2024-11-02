class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newhead = new ListNode(0); // Dummy head
        ListNode* current = newhead; // Pointer to build the new list
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Start with the carry
            
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10; // Update carry
            current->next = new ListNode(sum % 10); // Create new node for the digit
            current = current->next; // Move current pointer forward
        }

        return newhead->next; // Return the next of dummy head
    }
};

