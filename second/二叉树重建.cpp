
//题目描述

//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode* recover(vector<int> pre,int pre_start,int pre_end,vector<int> in,int in_start,int in_end){
		struct TreeNode*  node=new TreeNode(pre[pre_start]);
		if(pre_start==pre_end||in_start==in_end) return node;
		int i=in_start;
		while (pre[pre_start]!=in[i]&&i<in_end) i++;
		int next_length_left=i-in_start;//{两边都是闭区间}
		int next_length_right=in_end-i;
		if(next_length_left>0) node->left=recover(pre,pre_start+1,pre_start+next_length_left,in,in_start,i-1);
		if(next_length_right>0) node->right=recover(pre,pre_start+next_length_left+1,pre_end,in,i+1,in_end);
		return node;
	}
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
		struct TreeNode* result=recover(pre,0,pre.size()-1,in,0,in.size()-1);
        return result;
    }
};
