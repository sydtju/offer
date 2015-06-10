//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。如果是非法的整数字符，比如1aa3，则返回0。
//这里需要注意的就是溢出  溢出的判断是相当重要的 
class Solution {
public:
    int StrToInt(string str) {
		int length=(int)str.length();
		int flag=1;
		unsigned int result=0;
		for(int i=0;i<length;i++){
			if (0==i&&str[i]=='+')	flag=1;
			else if(0==i&&str[i]=='-') flag=-1;
			else if (str[i]>='0'&&str[i]<='9')
			{
				result=result*10+(unsigned int)(str[i]-'0');
				if (1==flag&&result>INT_MAX) return 0; //一定要有
				if (-1==flag&&result>INT_MAX+1) return 0;//用longlong 不行 不知道为什么？？？？？
			}
			else{
				return 0;
			}
		}

		return (int)flag*result;
	}
};
