class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // 定义两个虚拟头结点
        ListNode* lessHead = new ListNode(0); // 存放小于 x 的节点
        ListNode* greaterHead = new ListNode(0); // 存放大于等于 x 的节点

        ListNode* less = lessHead;   // 指向小于 x 的链表的尾部
        ListNode* greater = greaterHead; // 指向大于等于 x 的链表的尾部

        ListNode* current = head; // 当前遍历的节点

        // 遍历链表，将节点分配到两个链表中
        while (current != nullptr) {
            if (current->val < x) {
                less->next = current;
                less = less->next;
            } else {
                greater->next = current;
                greater = greater->next;
            }
            current = current->next;
        }

        // 将两条链表连接起来
        greater->next = nullptr; // 断开最后一个大于等于 x 的节点的 next
        less->next = greaterHead->next; // 将小于 x 的链表与大于等于 x 的链表连接

        // 返回新的链表头
        return lessHead->next;
    }
};

