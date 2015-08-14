//二叉树中和为某一值的路径
//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
//二叉树中和为某一值的路径
//就是递归查找  把每条路径存起来
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
private:
	vector<vector<int>> result;    
    int std;
public:
    void path(TreeNode* root,vector<int> num){
		num.push_back(root->val);
        if(root->left&&root->right){ 
			 path(root->left,num);
             path(root->right,num);
        }
		else if(root->left&&!root->right){
			path(root->left,num);
		}
		else if(!root->left&&root->right){
			path(root->right,num);
		}
		else
		{
            int length=(int)num.size();
            int sum=0;
            for(int i=0;i<length;++i)
                sum=sum+num[i];
            if(sum==std) result.push_back(num);
        }
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<int> num;
        std=expectNumber;
		if (root) path(root,num);
        return result;
    }
};
