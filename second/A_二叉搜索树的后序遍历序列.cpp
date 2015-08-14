//二叉搜索树的后序遍历序列
//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
//如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
//就是理解后序遍历就行了
class Solution{
public:
	bool check(vector<int> sequence,int start,int end){
		if(start>=end) return true;
		int std=sequence[end];
		int i=start,j=0;
		while(sequence[i]<std)i++;
		j=i;
		while(sequence[j]>std)j++;
		if(j==end)  return check(sequence,start,i-1)&&check(sequence,i,end-1);
		else
			return false;
	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		if(!sequence.size()) return false;
		else
			return check(sequence,0,sequence.size()-1);
	}
};

