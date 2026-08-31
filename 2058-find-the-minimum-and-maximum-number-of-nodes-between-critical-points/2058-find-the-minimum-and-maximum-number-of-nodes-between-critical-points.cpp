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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) 
            return {-1, -1}; 
        int index = 1; 
        int firstCritical = -1, lastCritical = -1;
        int minDist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        while (next) {
            if ((curr->val > prev->val && curr->val > next->val) || 
                (curr->val < prev->val && curr->val < next->val)) {
                
                if (firstCritical == -1) {
                    firstCritical = index;
                } else {
                    minDist = min(minDist, index - lastCritical);
                }
                lastCritical = index;
            }
            prev = curr;
            curr = next;
            next = next->next;
            index++;
        }

        if (firstCritical == -1 || lastCritical == firstCritical) 
            return {-1, -1};
        return {minDist, lastCritical - firstCritical};
    }
};
