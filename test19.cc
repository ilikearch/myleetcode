struct cmp{
    bool operator()(const ListNode*l1,const ListNode* l2){
        return l1->val>l2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> heap;

        //所有头节点入队
        for(auto l:lists){
            if(l) heap.push(l);
        }
        ListNode *ret=new ListNode(0);
        ListNode *prev=ret;
        while(!heap.empty()){
            ListNode*t=heap.top();
            heap.pop();
            prev->next=t;
            prev=t;
            if (t->next) heap.push(t->next);
        }
        return ret->next;
    }
};
