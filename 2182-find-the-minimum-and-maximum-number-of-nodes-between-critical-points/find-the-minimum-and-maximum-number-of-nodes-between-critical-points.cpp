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
        ListNode*prev=head;
        int k=1;
        vector<int>criticalpt;
        head=head->next;
        while(head->next!=NULL){
            if((prev->val<head->val&&head->val>head->next->val)||prev->val>head->val&&head->val<head->next->val){
                criticalpt.push_back(k);
            }
            k++;
            prev=head;
            head=head->next;
        }
        if(criticalpt.size()>1){
            int max=criticalpt[criticalpt.size()-1]-criticalpt[0];
            int mini=INT_MAX;
            for(int i=1;i<criticalpt.size();i++){
                mini=min(mini,criticalpt[i]-criticalpt[i-1]);
            }
            return {mini,max};
        }
        return {-1,-1};
    }
};