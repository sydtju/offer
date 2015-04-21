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
//方法2：时间复杂度为n，空间复杂度为1   用异或的方法求出整个数组的异或值 由于异或一个数两次等于没有异或  
//所以最终的值应该是两个没有重复值的异或   找到这个值的非零位， 用非零位将数组分成两个两个数组  分别求异或  
//最终的值就是两个没有重复的数字
void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
	int temp=0;
	int temp1=0;
	int temp2=0;
	int t=1;
	if (data.size()<=1)
	{
		return ;
	}
	for(int i=0;i<data.size();i++){
		temp=temp^data[i];
	}
	for(int i=0;i<sizeof(int)*8;i++){
		if (t&temp)
		{
			break;	
		}
		t=t<<1;
	}
	for(int i=0;i<data.size();i++){
		if (data[i]&t)
		{
			temp2=data[i]^temp2;
		} 
		else
		{
			temp1=data[i]^temp1;
		}
	}
	* num1=temp1;
	* num2=temp2;
}
