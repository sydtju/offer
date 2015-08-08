//从上往下打印出二叉树的每个节点，同层节点从左至右打印。二叉树的层序遍历


class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
		deque<TreeNode*> que;
        vector<int> result;
        if(!root) return result;
        que.push_back(root);
        TreeNode* temp;
        while(que.size()){
            temp=que.front();
            que.pop_front();
            result.push_back(temp->val);
            if(temp->left) que.push_back(temp->left);
            if(temp->right) que.push_back(temp->right);
        }
        return result;
    }
};
