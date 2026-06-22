class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy/sentinel node to handle head deletion cleanly
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;
        
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                // Skip the node containing the target value
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp; // Good practice in C++ to prevent memory leaks!
            } else {
                // Only move forward if we DID NOT delete a node
                curr = curr->next;
            }
        }
        
        curr = dummy->next;
        delete dummy; // Clean up the dummy node
        return curr;
    }
};
