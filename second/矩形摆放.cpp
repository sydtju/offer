//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
//斐波那契数列  与跳台阶一样
class Solution {
public:
	int rectCover(int number) {
	int fn2=1;
	int fn1=1;
	if (number<0)
		return 0;
	else if (0==number)
		return 0;
	else if(1==number)
		return 1;
	else{
		int i=2;
		int fn=0;
		while (i++<=number)
		{
			fn=fn1+fn2;
			fn2=fn1;
			fn1=fn;
		}
		return fn;
	}
}
};
