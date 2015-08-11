//把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。
//习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数
//这种方法是暴力枚举  OJ通过不了 
class Solution {
public:
    bool ugly(int num){
        while(num%2==0) num=num/2;
        while(num%3==0) num=num/2;
        while(num%5==0) num=num/2;
		return num==1?true:false;
    }
    int GetUglyNumber_Solution(int index) {
    	int number=0;
        int count=0;
        while(count<index){
            if(ugly(++number)) count++;
        }
        return number;
    }
};
