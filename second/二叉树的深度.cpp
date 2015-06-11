//输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，
//最长路径的长度为树的深度。
//有两个版本 第二个版本牛客网的在线系统 显示段错误  空间占用太大了  说明STL的内存管理 还是不行
/*struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//版本1  递归实现  空间复杂度其实 相对于版本2来讲是相对比较低的 而且代码短  但是 递归会带来频繁的栈操作 浪费时间 
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
	int deep_left=0;
	int deep_right=0;
	if (pRoot) {deep_left=1;deep_right=1;}
	else return 0;
	deep_left+=TreeDepth(pRoot->left);
	deep_right+=TreeDepth(pRoot->right);
	return deep_left>deep_right?deep_left:deep_right;
	}
};
//版本2  STL队列实现   牛客网 段错误
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		deque<TreeNode*> que;
		if (pRoot==NULL) return 0;
		que.push_back(pRoot);
		int couter=1;
		int deep=0;
		int couter_temp=0;
		while (!que.empty())
		{
			deep++;
			while (couter--)
			{
				TreeNode * temp=NULL;
				temp=que.front();
				que.pop_front();
				if (temp->left) {que.push_back(temp->left);couter_temp++;}
				if (temp->right) {que.push_back(temp->right);couter_temp++;}
			}
			couter=couter_temp;
		}
		return deep;
	}
};
