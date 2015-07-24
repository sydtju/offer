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
//o（n）的时间复杂度   O（1）的空间复杂度  用异或的方式 取出两个不一样的数的加和  用和中为1的位  将数列分开 相加
void findnumsappearonce(vector<int> data,int* num1,int *num2) {
	int length=(int)data.size();
	*num1=0;
	*num2=0;
	if (length<2) return ;
	int sum=0;
	for(int i=0;i<length;++i){
		sum=data[i]^sum;
	}
	int temp=1;
	if(!sum) return ;
	while (!(temp&sum))
		temp=temp<<1;
	for (int j=0;j<length;++j)
	{
		if (data[j]&temp)
			*num1=(*num1)^data[j];
		else
			*num2=(*num2)^data[j];
	}
}
