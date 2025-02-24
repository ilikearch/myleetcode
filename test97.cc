class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> s;
        ListNode *cur=head;
        while(cur){
            auto ret=s.insert(cur);
            if(ret.second==false)
            return cur;
            cur=cur->next;
        }
        return nullptr;
    }
};
