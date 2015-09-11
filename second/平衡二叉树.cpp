//输入一棵二叉树，判断该二叉树是否是平衡二叉树。
//逐个节点判断  给出每个节点的深度  深度也是递归求得
//时间复杂度 在O（n）和O（n^2）之间

//最简单方案
class Solution {
public:
    bool check(TreeNode* pRoot,int &depth){
        if(pRoot==NULL) {depth=0;return true;}
        int depth_right,depth_left;
        bool flag_right=check(pRoot->right,depth_right);
        bool flag_left=check(pRoot->left,depth_left);
        if(flag_right&&flag_left){
            int diff=depth_right-depth_left;
            if(diff<=1&&diff>=-1){depth=1+(diff>0?depth_right:depth_left); return true;}
        }
        return false;
    } 
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int temp=0;
		return  check(pRoot,temp);
    }
};

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
//时间复杂度为O(n)
class Solution {
public:
    bool bcheck(TreeNode* pRoot,int &depth) {
		if(!pRoot) {depth=0;return true;}
        int ldepth=0;
        int rdepth=0;
		if(bcheck(pRoot->left,ldepth)&&bcheck(pRoot->right,rdepth)){
            int temp=ldepth-rdepth;
            if((temp>1)||(temp<-1)) return false;
            else{
                depth=1+((ldepth>rdepth)?ldepth:rdepth);
                return true;
            }
            }
        else
            return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int temp=0;
		return bcheck(pRoot,temp);
    }
};
