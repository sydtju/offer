//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
//所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
//这个不是最简单的算法  简单算法应该是partition
class Solution {
public:
	void reOrderArray(vector<int> &array) {
	unsigned int length=array.size();
	int temp=0;
	unsigned int j=0;
	for (unsigned int i=0;i<length;i++)
	{
		if (1==array[i]%2){
			temp=array[i];//很常用的移位方式
			for (j=i;j>=1;j--)
			{
				if (0==array[j-1]%2) array[j]=array[j-1];
				else break;
			}
			array[j]=temp;
		}	
	}
	}
};
