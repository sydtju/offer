//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。没有找到输出为0。
//找到两个不相同的数字 就去掉这对  如果大于1/2的话 那最后剩的肯定是这个数！！
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		unsigned int length=numbers.size();
		int mermber=0;
		int times=0;
		for (unsigned int i=0;i<length;i++)
		{
			if (0==times)
			{
				mermber=numbers[i];
        times++;
			}
			else{
				if (mermber==numbers[i])
				{
					times++;
				}
				else{
					times--;
				}
			}
		}
		times=0;
		for (unsigned int i=0;i<length;i++)
		{
			if (numbers[i]==mermber)
			{
				times++;
			}
		}
		return times>length/2?mermber:0;
	}
};
