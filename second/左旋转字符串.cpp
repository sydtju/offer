/*汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，
即“XYZdefabc”。是不是很简单？OK，搞定它！*/
class Solution {
public:
void swap(char &a,char &b){
	char temp=a;
	a=b;
	b=temp;
}
void retate(string &str,int start,int end){
	int i=start;
	int j=end-1;
	while (i<j)
	{
		swap(str[i++],str[j--]);
	}
}
string LeftRotateString(string str, int n) {
	int length=(int)str.length();
	if(length<2) return str;
	retate(str,0,n);
	retate(str,n,length);
	retate(str,0,length);
	return str;
}
};
