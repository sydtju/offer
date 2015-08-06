//地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
//但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
//但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
//典型的深度优先搜索问题  DFS  这个就是栈的应用
class Solution {
public:
bool judge(int a,int b,int threshold){
	int temp=0;
	while (a!=0)
	{
		int t_a=a%10;
		temp=temp+t_a;
		a=a/10;
	}
	while (b!=0)
	{
		int t_b=b%10;
		temp=temp+t_b;
		b=b/10;
	}
	return temp>threshold?false:true;
}
int movingCount(int threshold,int rows,int cols){
	if(threshold<=0||rows<=0||cols<=0)
		return 0;
	stack<int> r_stack;
	stack<int> c_stack;
	bool *flag=new bool[rows*cols];
	memset(flag,false,sizeof(bool)*rows*cols);
	r_stack.push(0);
	c_stack.push(0);
	int count=1;
	flag[0]=true;
	int r=0;
	int c=0;
	while (r_stack.size()!=0&&c_stack.size()!=0)
	{

		if (r-1>=0&&judge(r-1,c,threshold)&&(!flag[(r-1)*cols+c]))
		{
			r_stack.push(r-1);
			c_stack.push(c);
			flag[(r-1)*cols+c]=true;
			count++;
			r=r-1;
			continue;
		}
		if (r+1<rows&&judge(r+1,c,threshold)&&(!flag[(r+1)*cols+c]))
		{
			r_stack.push(r+1);
			c_stack.push(c);
			flag[(r+1)*cols+c]=true;
			count++;
			r=r+1;
			continue;
		}
		if (c-1>=0&&judge(c-1,r,threshold)&&(!flag[r*cols+c-1]))
		{
			r_stack.push(r);
			c_stack.push(c-1);
			flag[r*cols+c-1]=true;
			count++;
			c=c-1;
			continue;
		}
		if (c+1<cols&&judge(c+1,r,threshold)&&(!flag[r*cols+c+1]))
		{
			r_stack.push(r);
			c_stack.push(c+1);
			flag[r*cols+c+1]=true;
			count++;
			c=c+1;
			continue;
		}
		r=r_stack.top();//注意STL的栈的使用 pop   vector是没有pop_front的  单端的
		r_stack.pop();
		c=c_stack.top();
		c_stack.pop();
	}
//	show(flag,rows,cols);
	return count;
}
};
