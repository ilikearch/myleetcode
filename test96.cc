class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> maplist;
        Node *copyhead = nullptr, *copytail = nullptr;
        Node* cur = head;
        while (cur) {
            //深拷贝
            if (copytail == nullptr) {
                copyhead = copytail = new Node(cur->val);
            } else {
                copytail->next = new Node(cur->val);
                copytail = copytail->next;
            }
            //拷贝节点与原节点k-v储存
            maplist[cur] = copytail;
            cur = cur->next;
        }
        cur = head;
        Node* copy = copyhead;
        //处理random节点
        while (cur) {
            if (cur->random == nullptr)
                copy->random = nullptr;
            else {
                copy->random = maplist[cur->random];//k-v存储
            }
            cur = cur->next;
            copy = copy->next;
        }
        return copyhead;
    }
};
