//统计一个数字在排序数组中出现的次数。
//二分查找  找到之后 向左右比较拓展 得到个数 
class Solution {
public:
int  sumlength(vector<int>& data,int position){
	int start=position;
	int end=position;
	int length=data.size();
		while(start-1>=0)
		{
			if (data[start-1]==data[start]) start=start-1;
			else break;
		}
		while(end+1<length)
		{
			if (data[end+1]==data[end]) end=end+1;
			else break;
		}
		return end-start+1;
}
int GetNumberOfK(vector<int> data ,int k) {
	int start=0;
	int end=data.size()-1;
	int middle=0;
	int length=0;
	while (start<=end)//注意：这里是小于等于  如果前面单独处理数组为1时的情况 这里可以去掉等于  但是不建议
	{
		middle=(start+end)/2;
		if (data[middle]==k)
		{
			length=sumlength(data,middle);break;
		}
		else if (data[middle]<k)
		{
			start=middle+1;
		}
		else 
		{
			end=middle-1;
		}
	}
	return length;
}
};
