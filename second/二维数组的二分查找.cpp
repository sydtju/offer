//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
//运行段错误  不知道   用两个二分查找    用二分查找找到大于目标值的最小的数组  然后再用二分法把小于这个数组的 所有数组
//进行二分查找
class Solution {
public:
    bool find1(vector<int> array,int value){
	int start=0;
	int end=array.size()-1;
	int middle=0;
	while (start<=end)
	{
		middle=(start+end)/2;
		if (array[middle]<value)
		{
			start=middle+1;
		}
		else if (array[middle]>value)
		{
			end=middle-1;
		}
		else{
			return true;
		}
	}
	return false;
}
bool Find(vector<vector<int> > array,int target) {
	int start=0;
	int end=array.size()-1;
	int middle=0;
	int temp_end=end;
	while (start<=end)
	{
		middle=(start+end)/2;
		if(array[middle][0]<target){
			start=middle+1;
		}
		else if(array[middle][0]>target){
			end=middle-1;
			temp_end=middle;
		}
		else{
			return true;
		}
	}
	bool temp=false;
	for(int i=temp_end;i>=0;i--){
		temp=find1(array[i],target);
		if (temp)
		{
			return temp;
		}
	}
	return false;
}
};
