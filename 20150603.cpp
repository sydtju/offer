
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
