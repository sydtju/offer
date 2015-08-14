//二叉搜索树与双向链表
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
//解题思路：进行中序遍历   没便利到一个节点 将该节点的左子树或者右子树 指向链表的底   链表的底部再指向该节点 然后依次进行
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void convertNode(TreeNode *pRootOfTree,TreeNode *&current){
        if(!pRootOfTree) return ;
        if(pRootOfTree->left) 
            convertNode(pRootOfTree->left,current);
        pRootOfTree->left=current;
        if(current) current->right=pRootOfTree;
        current=pRootOfTree;
        if(pRootOfTree->right)
            convertNode(pRootOfTree->right,current);
    }
    TreeNode* Convert(TreeNode *pRootOfTree)
    {
        TreeNode *current=NULL;
        if(!pRootOfTree) return NULL;
        convertNode(pRootOfTree,current);
        while(current&&current->left) current=current->left;
        return current;
    }
};
