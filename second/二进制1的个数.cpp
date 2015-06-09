//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
//使用位运算  但是应该注意从低位向上移动 防止高位补符号
class Solution {
public:
int  NumberOf1(int n) {
	int test=0x01;
	int counter=0;
	int i=0;
	while (i++<32)
	{
		if (n&test)
		{
			counter++;
		}
		test=test<<1;
	}
	return counter;

	 }
};
