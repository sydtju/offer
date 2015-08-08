//
//按之字形顺序打印二叉树
//就是层序遍历  使用一个双向队列暂时存储  然后根据flag（真和假  每层变一次） 决定是从头输出 还是从尾输出
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
vector<vector<int> > Print(TreeNode *pRoot) {
	deque<TreeNode*> que;
	vector<vector<int>> result_f;
	if(!pRoot) return result_f;
	que.push_back(pRoot);
	TreeNode* temp;
	bool flag=true;
	while(que.size()){
		deque<TreeNode*> que_temp;
		deque<int> que_print;
		vector<int> result;
		while(que.size()){
			temp=que.front();
			que.pop_front();
			//result.push_back(temp->val);
			que_print.push_back(temp->val);
			if(temp->left) que_temp.push_back(temp->left);
			if(temp->right) que_temp.push_back(temp->right);
		}
		while (que_temp.size()){
			temp=que_temp.front();
			que_temp.pop_front();
			que.push_back(temp);
		}
		while (que_print.size()){
			if (flag) {
				result.push_back(que_print.front());
				que_print.pop_front();
			}
			else{
				result.push_back(que_print.back());
				que_print.pop_back();
			}
		}
		flag=!flag;
		que_temp.clear();
		result_f.push_back(result);
		result.clear();
	}
	return result_f;
}
    
};
