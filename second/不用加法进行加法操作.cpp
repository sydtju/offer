
//写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
class Solution {
public:
    int Add(int num1, int num2)
    {
	int reult=0;
	int temp=0;
	int a=num1;
	int b=num2;
	do //每一次都一次新的加法
	{
		reult=a^b;	
		temp=(a&b)<<1;
		a=reult;
		b=temp;
	} while(temp);
	return reult;
    }
};
