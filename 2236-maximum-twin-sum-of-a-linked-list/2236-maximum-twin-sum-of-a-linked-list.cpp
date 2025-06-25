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
    ListNode* temp=head;
    while(temp)
    {
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
public:
    int pairSum(ListNode* head) {
        stack<int>st;
        int n = length(head);
        ListNode* temp=head;
        int ans=0;
        int cnt=0;
        while(temp)
        {
            if(cnt<=n/2-1)
            {
                st.push(temp->val);
            }
            else{
                int x = st.top();
                st.pop();
                int d = x+temp->val;
                ans = max(ans,d);
            }
            cnt++;
            temp=temp->next;
        }
        return ans;
    }
};