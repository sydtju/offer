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
//这种方法  可以减少时间复杂度  可以通过OJ  可以使用打表的方式  然后使用进行查找 
class Solution {
public:
int min(int a,int b,int c){
	int min_temp=a>b?b:a;
	return  min_temp>c?c:min_temp;
}
int GetUglyNumber_Solution(int index){
	int index_std=0,index2=0,index3=0,index5=0;
	if (index<=0) return 0;
	int value=1;
	int *array=new int[index];
	array[0]=1;
	while (index_std<index-1)
	{
		value=min(array[index2]*2,array[index3]*3,array[index5]*5);
		if (array[index2]*2==value) index2++;
		if (array[index3]*3==value) index3++;
		if (array[index5]*5==value) index5++;
		array[++index_std]=value;
	}
	int result=array[index_std];
	delete[] array;
	return result;
}
};
