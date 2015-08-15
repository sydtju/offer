//请实现两个函数，分别用来序列化和反序列化二叉树
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
private:
     string str= "";  int pos = 0;
public:
    void path(TreeNode* root)
    {
        if (root == NULL){
            str += "#";
            str += " ";
        }
        else{
            str += to_string(root->val);
            str += " ";
            path(root->left);
            path(root->right);
        }
    }
  
    char* Serialize(TreeNode *root){
        path(root);
        return (char*)str.c_str();
    }
  
    TreeNode* Deserialize(char *str){
        if (*(str + pos) == ' ')
            ++pos;
        if (*(str + pos) == '#' || *(str + pos) == '\0'){
            ++pos;
            return NULL;
        }
        else{
            string num = "";
            while (*(str + pos) != ' '){
                num += *(str + pos);
                ++pos;
            }
            TreeNode* root = new TreeNode(atoi((char*)num.c_str()));
            root->left = Deserialize(str);
            root->right = Deserialize(str);
            return root;
        }
  
    }
};
