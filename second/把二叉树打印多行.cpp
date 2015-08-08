//题目描述

//从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

class Solution {
public:
vector<vector<int> > Print(TreeNode *pRoot) {
	deque<TreeNode*> que;
	vector<vector<int>> result_f;
	if(!pRoot) return result_f;
	que.push_back(pRoot);
	TreeNode* temp;
	
	while(que.size()){
		deque<TreeNode*> que_temp;
		vector<int> result;
		while(que.size()){
			temp=que.front();
			que.pop_front();
			result.push_back(temp->val);
			if(temp->left) que_temp.push_back(temp->left);
			if(temp->right) que_temp.push_back(temp->right);
		}
		while (que_temp.size()){
			temp=que_temp.front();
			que_temp.pop_front();
			que.push_back(temp);
		}
		que_temp.clear();
		result_f.push_back(result);
		result.clear();
	}
	return result_f;
}
    
    
};
