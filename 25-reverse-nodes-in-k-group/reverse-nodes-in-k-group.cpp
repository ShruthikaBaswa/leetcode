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
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while (temp != NULL) {
            ListNode* nextTemp =temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextTemp;
        }

        return prev;
    }

    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr !=NULL && k > 1) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || head ==NULL) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;
        ListNode* curr = head;

        while (true) {
            ListNode* kth = getKthNode(curr, k);
            if (kth ==NULL) break;

            ListNode* groupNext = kth->next;
            kth->next =NULL;
            ListNode* reversedHead = reverseLinkedList(curr);

            groupPrev->next = reversedHead;
            curr->next = groupNext;

            groupPrev = curr;
            curr = groupNext;
        }

        return dummy.next;
    }
};
