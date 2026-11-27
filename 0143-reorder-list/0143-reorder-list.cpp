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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        // Step 1: Find the middle 
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        slow->next = NULL;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Merge both halves
        ListNode* first = head;
        ListNode* second = prev;

        while (second != NULL) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }

        // if (head == NULL || head->next == NULL)
        //     return;
        // vector<ListNode*> arr;
        // ListNode* temp = head;
        // // Store all nodes in vector
        // while (temp != NULL) {
        //     arr.push_back(temp);
        //     temp = temp->next;
        // }

        // int i = 0,j = arr.size() - 1;
        // // Reorder the list
        // while (i < j) {
        //     arr[i]->next = arr[j];
        //     i++;
        //     if (i == j)
        //         break;
        //     arr[j]->next = arr[i];
        //     j--;
        // }
        // arr[j]->next = NULL;
    }
};