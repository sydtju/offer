//1+2.....+n
class Solution {
public:
	int Sum_Solution(int n) {
		return n*(1+n)/2;
	}
};
//整数中二进制1的个数
class Solution {
public:
	 int  NumberOf1(int n) {
		 int counter=0;
         int temp=n;
         while(temp){
             temp=temp&(temp-1);
             counter++;
         }
         return counter;
	 }
};
//斐波那契数列
class Solution {
public:
	int Fibonacci(int n) {
		int counter=1;
        int temp0=0;
        int temp1=1;
        int temp2=0;
        if(n<0) return 0;
        if(0==n) return 0;
        if(1==n) return 1;
        while(counter<n){
            temp2=temp1+temp0;
            temp0=temp1;
            temp1=temp2;
            counter++;
        }
        return temp1;
	}
};
//字符串转整数  遇到非法输入停止返回0
class Solution {
public:
	int StrToInt(string str) {
        int flag=1;
        long long sum=0;
		for(int  i=0;i<str.length();i++){
            if(0==i) {
                if(str[i]=='-') flag=-1;
                else if(str[i]=='+') flag=1;
                else if(str[i]>='0'&&str[i]<='9') sum=sum*10+(str[i]-'0');
                else return 0;
            }
            else{
                if(str[i]>='0'&&str[i]<='9') {
                    sum=sum*10+(str[i]-'0');
                	if(flag==1&&sum>2147483647) return 0;
                   	if(flag==-1&&sum>2147483648) return 0;
                }
                else return 0;
            }
        }
        return flag*sum;
	}
};
