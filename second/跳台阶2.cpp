//20150608 
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//这种是斐波那契数列的延展   就是 f（n）=f（n-1）+f（n-2）  而这个题是f（n）=f（n-1）+f（n-2）+f（n-3）+f（n-4）...f(0)；
class Solution {
public:
int jumpFloorII(int number) {
	int fn2=1;
	int fn1=1;
	int result=1;
	if (0==number)
		return 0;
	else if(1==number)
		return 1;
	else{
		int i=2;
		int fn=0;
		while (i++<=number)
		{
			result=result+fn1;
			fn=result;
			fn1=fn;
		}
		return result;
	}
}
};
