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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
        return head;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        ListNode* temp22 = temp2;
        temp1->next=temp1->next->next;
        temp1 = temp1->next;
        while(temp1&&temp1->next!=NULL)
        {
            temp2->next=temp1->next;
            cout<<temp2->val<<endl;
            temp2=temp2->next;
            if(temp1->next->next==NULL)
            break;
            temp1->next = temp1->next->next;
            temp1=temp1->next;
        }
        // while(temp2->next!=NULL&&temp2->next->next!=NULL)
        // {
        //     temp2->next = temp2->next->next;
        //     temp2=temp2->next;
        // }
        temp2->next=NULL;
        if(temp1)
        temp1->next=temp22;
        return head;
    }
};