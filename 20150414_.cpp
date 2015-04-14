
//二叉树镜像 段错误！
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		deque<TreeNode*> que;
		TreeNode *temp;
		que.push_back(pRoot);
		while (!que.empty())
		{
			TreeNode *temp_m=NULL;
			temp=que.front();
			temp_m=temp->left;
			temp->left=temp->right;
			temp->right=temp_m;
			que.pop_front();
			if(temp->left!=NULL) que.push_back(temp->left);
			if (temp->right!=NULL) que.push_back(temp->right);
		}
        
	}
};
