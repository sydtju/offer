//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
//路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
//如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
//例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bccced"的路径，但是矩阵中不包含"abcb"路径，
//因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
//深度优先遍历原则
class Solution {
public:
   bool rec(char* matrix, int i, int j, int rows, int cols, char* str,vector<vector<int> >&flag){
	if(*str=='\0')
		return true;
	if(i<0||j<0||i>=rows||j>=cols)
		return false;
	if(flag[i][j]==1)
		return false;
	if(*(matrix+(i*cols)+j)!=*str)
		return false;
	else{
		flag[i][j]= 1;
		if(rec(matrix,i+1,j,rows,cols,str+1,flag))
			return true;
		if(rec(matrix,i,j+1,rows,cols,str+1,flag))
			return true;
		if(rec(matrix,i-1,j,rows,cols,str+1,flag))
			return true;
		if(rec(matrix,i,j-1,rows,cols,str+1,flag))
			return true;
		flag[i][j]= 0;
		return false;
	}

}
bool hasPath(char* matrix, int rows, int cols, char* str)
{
	vector<vector<int> >flag;
	for(int i=0;i<rows;i++){
		vector<int> temp;
		for(int j=0;j<cols;j++){
			temp.push_back(0);
		}
		flag.push_back(temp);
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(rec(matrix,i,j,rows,cols,str,flag))
				return true;
		}
	}
	return false;

}
 
};
