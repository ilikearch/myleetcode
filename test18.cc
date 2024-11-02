class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode*cur=head;
        while(cur){
            cur=cur->next;
            n++;
        }
        n/=k;
        //重复k次长度为k的逆序
        ListNode*newhead=new ListNode(0);
        ListNode*prev=newhead;
        cur=head;
        for(int i=0;i<n;i++){
            ListNode*tmp=cur;
            for(int j=0;j<k;j++){
                ListNode*next=cur->next;
                cur->next=prev->next;
                prev->next=cur;
                cur=next;
            }
            prev=tmp; 
        }
        //不需要的翻转的接上
        prev->next=cur;
        return newhead->next;
    }
};
