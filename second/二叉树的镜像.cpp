/*
题目描述

操作给定的二叉树，将其变换为源二叉树的镜像。 
输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5

*/
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
    void Mirror(TreeNode *pRoot) {
		deque<TreeNode *> temp;
        if(!pRoot) return;
        temp.push_back(pRoot);
        while(temp.size()){
           TreeNode * p=temp.front();
            temp.pop_front();
            TreeNode * mp=p->left;
            p->left=p->right;
            p->right=mp;
            if(p->left) temp.push_back(p->left);
            if(p->right) temp.push_back(p->right);
        }
    }
};
