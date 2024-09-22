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
    ListNode* swapPairs(ListNode* head) {
        ListNode*o=new ListNode(0);
        o->next=head;
       ListNode*q=o;
        while(q->next!=NULL&&q->next->next!=NULL)
        {
            ListNode*a=q->next;
            ListNode*b=q->next->next;
            q->next=b;
           a->next=b->next;
           b->next=a;
           q=a;
        }
        ListNode*ans=o->next;
        delete o;
        return ans;
    }
};
