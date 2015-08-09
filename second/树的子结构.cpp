// 输入两颗二叉树A，B，判断B是不是A的子结构。

//题目描述
//
//输入两颗二叉树A，B，判断B是不是A的子结构。子结构指的是内容的子结构  不是地址
//使用递归的方式  对两个二叉树进行对比   分为两个步骤 一个寻找与pRoot2相同的首部    然后判断这个树是不是它的子部分
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
bool  comp(TreeNode* pRoot1, TreeNode* pRoot2){

	if ((!pRoot1&&pRoot2))	return false; 
	if ((!pRoot1&&!pRoot2)||(pRoot1&&!pRoot2)) return true;
	if (pRoot1->val==pRoot2->val) return comp(pRoot1->left,pRoot2->left)&&comp(pRoot1->right,pRoot2->right);
	else
		return false;
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
	if (!pRoot1&&!pRoot2) return false;
	else if((!pRoot1&&pRoot2)||(pRoot1&&!pRoot2))  return false;
	else{
		if(pRoot1->val==pRoot2->val){
			if(comp(pRoot1,pRoot2)) return true;
			else
				return	HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);
		}
		else{
			return	HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);
		}
	}
}

};
