/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
int len(ListNode *head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *h1=headA;
        ListNode *h2=headB;
        int l1=len(h1);
        int l2=len(h2);
        if(l1>l2){
            while(l1!=l2){
                h1=h1->next;
                l1--;
            }
        }
        else if(l2>l1){
            while(l1!=l2){
                h2=h2->next;
                l2--;
            }
        }
        while(h1!=NULL && h2!=NULL){
            if(h1==h2){
                return h1;
            }
            h1=h1->next;
            h2=h2->next;
        }
        return NULL;
        
    }
};