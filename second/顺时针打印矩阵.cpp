//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果
//输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
//则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
//这个方式 相对较为容易  
class Solution {
public:
bool print(vector<int> &result,vector<vector<int> > &matrix,int x0,int y0,int x1,int y1){
	if(x0>x1||y0>y1) return false;//只判断大于情况  
	for(int i=x0;i<=x1;++i)
		result.push_back(matrix[y0][i]);
	if(x0<=x1) ++y0;

	for(int i=y0;i<=y1;++i)
		result.push_back(matrix[i][x1]);
	if(y0<=y1)--x1;

	if(y0<=y1){
	for (int i=x1;i>=x0;--i)
		result.push_back(matrix[y1][i]);
	if(x1>=x0)--y1;
	}

	if(x0<=x1){
	for (int i=y1;i>=y0;--i)
		result.push_back(matrix[i][x0]);
	}
	return true;
}
vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int> result;
	int length_y=(int)matrix.size();//一定得确定这里是非空的
	if(length_y<=0) return result;
	int length_x=(int)matrix[0].size();//否则这里寻址是错误的
	if(length_x<=0) return result;
	int x0=0,y0=0;
	int x1=length_x-1,y1=length_y-1;
	while (print(result,matrix,x0++,y0++,x1--,y1--));//这个函数调用的前提是矩阵非空  
	return result;
}
};











//编写一个打印矩阵边框的函数 然后 依次使用（其实第一个函数可以不用考虑太多的情况）  这个太麻烦
class Solution {
public:

void subprint(vector<vector<int> > matrix,vector<int>&a,unsigned int x0,unsigned int y0,unsigned int x1,unsigned int y1){
		unsigned int absx=(x0>=x1)?x0-x1:x1-x0;
		unsigned int absy=(y0>=y1)?y0-y1:y1-y0;
		unsigned int x_start=(x0>=x1)?x1:x0;
		unsigned int y_start=(y0>=y1)?y1:y0;
		unsigned int x_end=(x0>=x1)?x0:x1;
		unsigned int y_end=(y0>=y1)?y0:y1;

		if (0==absx&&0!=absy)
		{
			unsigned int temp=0;
			while (temp<=absy)
			{
				a.push_back(matrix[x_start][y_start+temp++]);
			}
		}
		else if (0!=absx&&0==absy)
		{
			unsigned int temp=0;
			while (temp<=absx)
			{
				a.push_back(matrix[x_start+temp++][y_start]);
			}
		}
		else if (0==absx&&0==absy)
		{
			a.push_back(matrix[x_start][y_start]);
		}
		else{
			 int temp=0;
			while (temp<=absy)
			{
				a.push_back(matrix[x_start][y_start+temp++]);
			}
			 temp=1;
			while (temp<absx)
			{
				a.push_back(matrix[x_start+temp++][y_end]);
			}
			 temp=absy;
			while (temp>=0)
			{
				a.push_back(matrix[x_end][y_start+temp--]);
			}
			 temp=absx-1;
			while (temp>0)
			{
				a.push_back(matrix[x_start+temp--][y_start]);
			}
		}

	}
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int x0=0;
		int y0=0;
		int x1=matrix.size()-1;
		int y1=matrix[0].size()-1;
		vector<int> a;
		while (x0<=x1&&y0<=y1)
		{
			subprint(matrix,a,x0++,y0++,x1--,y1--);
		}
		return a;
	}
};
