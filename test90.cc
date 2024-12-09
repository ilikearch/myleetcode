class Solution {
public:
    void InOrderConvert(Node*cur,Node*&prev){
        if(cur==nullptr){
            return ;
        }
        InOrderConvert(cur->left,prev);
        //cur中序
        //left指向中序前一个，左变为前驱
        cur->left=prev;
        //中序前一个的右指向cur，右变为后继
        if(prev)prev->right=cur;
        prev=cur;
        InOrderConvert(cur->right,prev);
    }
    Node* treeToDoublyList(Node* root) {
        if(root==nullptr)return nullptr;
        Node* prev=nullptr;
        InOrderConvert(root,prev);
        Node*head=root;
        while(head->left){
            head=head->left;
        }
        //循环
        head->left=prev;
        prev->right=head;
        return head;
    }
};
