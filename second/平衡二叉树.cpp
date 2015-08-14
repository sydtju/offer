//输入一棵二叉树，判断该二叉树是否是平衡二叉树。
//逐个节点判断  给出每个节点的深度  深度也是递归求得
class Solution {
public:
    int getdepth(TreeNode* pRoot){
        if(!pRoot) return 0;
        int left=getdepth(pRoot->left)+1;
        int right=getdepth(pRoot->right)+1;
		return left>right?left:right;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if(!pRoot) return true;
        int left=getdepth(pRoot->left);
        int right=getdepth(pRoot->right);
        if((left-right>1)||(left-right<-1)) return false;
        else
            return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);

    }
};
