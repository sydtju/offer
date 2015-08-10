//题目描述
//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
//使用的是二分查找

class Solution {
public:
int binarySearch(vector<int> arr,int front,int rear){
	if(front+1 == rear || front == rear)
		return arr[rear]<arr[front]?arr[rear]:arr[front];
	int index = (front+rear)/2;
	if(arr[front] == arr[index] && arr[rear] == arr[index]){//此时两边中间都一样，考虑到特殊情况，我们两遍均遍历一次，进行最后的比较大小。
		int find1 = binarySearch(arr,front,index);
		int find2 = binarySearch(arr,index+1,rear);
		return find1<find2?find1:find2;
	}else if(arr[index] >= arr[front] && arr[index] > arr[rear])
		return	binarySearch(arr,index,rear);
	else
		return 	binarySearch(arr,front,index);
}
int minNumberInRotateArray(vector<int> rotateArray) {
	int result=0;
    if(rotateArray.size()==0) return 0;
    result=binarySearch( rotateArray,0,rotateArray.size()-1);
	return result;
}
};
