//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
//这里使用的  选择排序  进行前k项
//vector进行交换的时候 要使用的是引用  
//是否有更为好的办法？？？？？
class Solution {
public:
void swap(vector<int> &input,unsigned int i,unsigned int j){
		int temp=0;
		temp=input[i];
		input[i]=input[j];
		input[j]=temp;
	}
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int>  temp;
		unsigned int length=input.size();
		unsigned int absk=k<length?k:length;
    if (k>length)//本题规定  如果k大于数组长度则返回的是空的vector
		{
			return temp;
		}
		for (int j=0;j<absk;j++)
		{
      unsigned int min=input[j];//每次变量都要重置
			unsigned int address=j;
			for (unsigned int i=j;i<length;i++)
			{
				if (input[i]<min)
				{
					min=input[i];
					address=i;
				}
			}
			swap(input,j,address);
			temp.push_back(input[j]);
		}
		return temp;
	}
};
