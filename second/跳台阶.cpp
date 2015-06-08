//20150608
//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//f（n）=f（n-1）+f（n-2）    这里有一个优化的办法  就是用多个相同的矩阵相乘  从O（n）降到O（log（n））  
//降的方式是用矩阵  0 1       f（n）= 0 1   * 0 1 ....(n-2).......{f(1),f(0)}; 
//		    1 1               1 1     1 1
class Solution {
public:
int jumpFloor(int number) {
	int fn=1;
	int fn1=1;
	if (0==number)
		return 0;
	else if(1==number)
		return 1;
	else{
		int result=0;
		int i=2;
		while (i++<=number)
		{
			result=fn+fn1;
			fn=fn1;
			fn1=result;
		}
		return result;
	}
}
};
