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
     ListNode*solve(ListNode* list1, ListNode* list2){
        if(list2==NULL && list1==NULL) return NULL;
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        if(list1->val<=list2->val){
            list1->next=solve(list1->next,list2);
            return list1;
        }
            list2->next=solve(list1,list2->next);
            return list2;

     }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
       return solve(list1,list2);
    }
};