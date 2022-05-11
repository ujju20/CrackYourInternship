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
    int lenLinkedList(ListNode* head)
    {
        
        int cnt=0;
        while(head!=NULL and head->val!=1)
        {
            head=head->next;
        }
        while(head!=NULL)
        {
            head=head->next;
            cnt++;
        }
        return cnt;
    }
    int getDecimalValue(ListNode* head) {
         while(head!=NULL and head->val!=1)
        {
            head=head->next;
        }
        if(head==NULL)
            return 0;
        int n=lenLinkedList(head);
        //cout<<n<<" ";
        int num=0;
        while(head!=NULL)
        {
            if(head->val==1)
            {
                num+=pow(2,n-1);
                //cout<<num<<" ";
            }
            //cout<<n<<" ";
            --n;
            head=head->next;
        }
        return num;
        
    }
};
