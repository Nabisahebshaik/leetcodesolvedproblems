/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (k == 0 || head == NULL || head->next == NULL) {
            return head;
        }
        
        
        int length = 1;
        ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
            length++;
        }

        
        temp->next = head;

      
        k = k % length;
        int forwardsteps = length - k - 1;

        
        temp = head; 
        while (forwardsteps != 0) {
            temp = temp->next;
            forwardsteps--;
        }


        head = temp->next;
        temp->next = NULL;

        return head;
    }
};