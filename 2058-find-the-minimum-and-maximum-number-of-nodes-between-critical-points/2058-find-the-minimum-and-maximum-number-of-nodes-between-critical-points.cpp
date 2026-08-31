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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        vector<int>ans(2,-1);
        vector<int>pos;
        if(!head->next->next)
        {
            return ans;
        }

        ListNode *first=head;
        ListNode *second=head->next->next;
        ListNode *curr=head->next;

        int count=1;

        while(second)
        {
            if((first->val<curr->val && second->val<curr->val) || (first->val>curr->val && second->val>curr->val))
            {
                pos.push_back(count);
            }

            second=second->next;
            curr=curr->next;
            first=first->next;

            count++;
        }

        if(pos.size()<2)
        {
            return ans;
        }

        ans[1]=pos[pos.size()-1]-pos[0];
        ans[0]=1e9;
        for(int i=1;i<pos.size();i++)
        {
            ans[0]=min(ans[0],pos[i]-pos[i-1]);
        }

        return ans;
        
    }
};