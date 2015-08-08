/*
题目描述

请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
bool check(TreeNode* pleft,TreeNode* pright){//这里是判断一个两个节点是不是对称
	if (!pleft&&!pright) return true;
	else if ((!pright&&pleft)||(pright&&!pleft)||(pleft->val!=pright->val)) return false;
	else
		return check(pleft->left,pright->right)&&check(pleft->left,pright->right);//注意这个里对比的是 两个外面的节点和内部的节点
}
bool isSymmetrical(TreeNode* pRoot){
    if(!pRoot) return true;
	return check(pRoot->left,pRoot->right);
}
};
