//20150608
//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
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
