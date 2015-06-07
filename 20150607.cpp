//最小需要排序的子序列
#include <iostream>
#include <utility>
using namespace std;
int main(){
	int dat[8]={1,2,6,7,8,9,3,10};
	int i=0;
	int max=dat[0];
	int min=dat[7];
	int temp0=0;
	int temp1=0;
	for (;i<8;i++){
		if (dat[i]<max)
		{
			temp0=i;
		}
		else{
			max=dat[i];
		}
		if (dat[7-i]>min)
		{
			temp1=7-i;
		}
		else{
			min=dat[7-i];
		}
	}
	cout<<temp0<<"  "<<temp1<<endl;
	system("pause");
	return 0;
}
