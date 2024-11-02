class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==nullptr||head->next==nullptr||head->next->next==nullptr)return;
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        //slow后面的部分逆序（头插）
        ListNode* head2=new ListNode(0);
        ListNode*cur=slow->next;
        slow->next=nullptr;//断开
        while(cur)
        {
            ListNode*next=cur->next;
            cur->next=head2->next;
            head2->next=cur;
            cur=next; 
        }
        //合并
        ListNode *ret = new ListNode(0);
        ListNode *prev=ret;
        ListNode*cur1=head;
        ListNode*cur2=head2->next;
        while(cur1){
            //先放第一个链表
            prev->next=cur1;
            cur1=cur1->next;
            prev=prev->next;
            //放第二个链表
            if(cur2){
                prev->next=cur2;
                cur2=cur2->next;
                prev=prev->next;
            }
        }

    }
};
