//题目描述
//给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
//中序遍历的下一个节点是  1如果该节点有右子树  则找到右子树中最左的节点  2 如果没有右子树 就向上找   
//（也有两种情况  一种该节点就是上一个节点的左子树  那就直接返回上一个节点就可以   另一种是该节点是上一个节点的右子树 那就继续向上追溯  直到为空 或者出现左节点）
using namespace std;
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        TreeLinkNode* temp;
        if(!pNode) return pNode;
        if(pNode->right){
            temp=pNode->right;
            while(temp->left) temp=temp->left;
            return temp;
        }
        while (pNode->next&&pNode->next->right==pNode) pNode=pNode->next;
        return pNode->next;
    }
};
