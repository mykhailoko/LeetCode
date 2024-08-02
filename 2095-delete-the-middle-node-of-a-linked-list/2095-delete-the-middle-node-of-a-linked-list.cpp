class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            return nullptr;
        }
        
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        
        int middleIndex = length / 2;
        
        temp = head;
        for (int i = 0; i < middleIndex - 1; ++i) {
            temp = temp->next;
        }

        ListNode* middleNode = temp->next;
        temp->next = middleNode->next;
        delete middleNode;
        
        return head;
    }
};
