//一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
	set<int> temp;
	vector<int>::iterator it;
	set<int> ::iterator it_temp;
	if (data.size()<2) {*num1=0;*num2=0;return;}
	for (it=data.begin();it!=data.end();++it)
	{
		it_temp=temp.find(*it);
		if (it_temp!=temp.end()) temp.erase(it_temp);
		else temp.insert(*it);
	}
	it_temp=temp.begin();
	*num1=*(it_temp++);
	*num2=*it_temp;
	}
};
