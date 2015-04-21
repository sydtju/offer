//一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
//C++实现  运行通过
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
	set<int> s0;
	set<int>::iterator it;
	*num1=0;
	*num2=0;
	if(data.size()<2)
		return ;
	for(int i=0;i<data.size();i++){
		it=s0.find(data[i]);
		if(it!=s0.end()) s0.erase(it);
		else
			s0.insert(data[i]);
	}
	it=s0.begin();
	*num1=*it;
	it++;
	*num2=*it;
    }
};
