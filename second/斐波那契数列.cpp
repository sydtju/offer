//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
// 1 2 3 4 5。。。。。。。。。。。。
// 1 1 2 3 5。。。。。。。。。。。。
int Fibonacci(int n) {
	int fn2=1;
	int fn1=1;
	int i=2;
	int fn=1;
	if (n==0)
		return 0;
	else if(n==1)
		return 1;
	else if(n<0)
		return -1;
	else
	{
	while (i++<n)
	{
		fn=fn1+fn2;
		fn2=fn1;
		fn1=fn;
	}
	}
	return fn;
}
