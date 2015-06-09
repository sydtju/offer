//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果
//输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
//则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
//编写一个打印矩阵边框的函数 然后 依次使用（其实第一个函数可以不用考虑太多的情况）
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
