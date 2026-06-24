class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Solve base case : if linked list is empty 
        if(head==nullptr){
            return nullptr;
        }

        // initial pointers
        ListNode* prev=nullptr;
        ListNode* current=head;     // to avoid head deletion

        while(current != nullptr){
            // swapping pointer's direction 
            ListNode* nextNode=current->next;
            current->next=prev;
            prev=current;
            current=nextNode;
        }

        // returning new head i.e prev
        return prev;
    }
};
