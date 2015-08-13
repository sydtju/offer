//给定一颗二叉搜索树，请找出其中的第k大的结点。例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。 
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
    TreeNode* result;
    int i=0;
public:
    void  dat_init(TreeNode* pRoot,unsigned int k){
        if(pRoot){
          dat_init(pRoot->left,k);
          i++;
          if(i==k) {result=pRoot;return ;}
          dat_init(pRoot->right,k);
        }
    }
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        result=NULL;
        dat_init(pRoot,k);
        return result;
    }

    
};
