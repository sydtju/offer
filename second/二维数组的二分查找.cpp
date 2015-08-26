//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
//运行段错误  不知道   用两个二分查找    用二分查找找到大于目标值的最小的数组  然后再用二分法把小于这个数组的 所有数组
//进行二分查找
//这里是最简的方式 时间复杂度为O（m+n）    思想是两个从0行cols-1开始   data[0][cols-1] 如果大于目标值 就将列数减少1
//如果等于返回true   小于就停下   开始行匹配  同样的规则  则最后的时间复杂度最大为m+n
class Solution {
public:
bool Find(vector<vector<int> > array,int target) {
	int row_length=(int)array.size();
	if (row_length<=0) return false;
	int col_length=(int)array[0].size();
	int row=0;
	int col=col_length-1;
	const int value=target;
	while (row<row_length&&col>=0)
	{
		if (array[row][col]>value) col--;//vol--;row=0; //需不需要加？ 
		else if(array[row][col]==value) return true;
		else row++;
	}
	return false;
}
};



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
