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
    int length(ListNode* head)
    {
        int cnt=0;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* solve(ListNode* head, int n)
    {
        ListNode* temp = head;
        int cnt=0;
        while(temp!=NULL)
        {
            if(cnt==n)
            break;
            temp=temp->next;
            cnt++;
        }
        temp->next = temp->next->next;
        return head;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return NULL;
        int n = length(head);
        n = n/2 ;
        solve(head, n-1);
        return head;
    }
};