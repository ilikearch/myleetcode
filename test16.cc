class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 创建一个虚拟头节点以简化处理
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy; // 从虚拟头节点开始
        
        // 当有至少两个节点可供交换时继续循环
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next; // 第一节点
            ListNode* second = first->next; // 第二节点
            ListNode*third = second->next;
            
            // 进行节点交换
            prev->next=second;
            second->next=first;
            first->next=third;
            //修改指针
            prev=first;
            first=third;
        }
        
        return dummy->next; // 返回新的头节点（虚拟头节点的下一个节点）
    }
};
