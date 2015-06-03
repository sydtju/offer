/*数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，
因此输出2。没有找到输出为0。*/
//思路：将两不同的数组成一组 去掉   实现方式很好  时间复杂度O（n）
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int temp=0;
		unsigned long times=0;
		for (unsigned long i=0;i<numbers.size();i++)
		{
			if (times==0)
			{
				temp=numbers[i];
				times++;
			}
			else if (temp==numbers[i])
			{
				times++;
			}
			else{
				times--;
			}
		}
		times=0;
		for (unsigned long i=0;i<numbers.size();i++)
		{
			if (numbers[i]==temp)
			{
				times++;
			}
		}
		if(times>(numbers.size()/2))
			return temp;
		else
			return 0;
	
	}
};
