//最小的k个数
class Solution {
public:
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void heap_adjust(vector<int>& input,int k,int stop){
	int child=0;
	int length=stop;
	for (int i=k;2*i+1<length;i=child)
	{
		child=2*i+1;
		if (child+1<length&&input[child]>input[child+1]) ++child;
		if (input[i]>input[child]) swap(input[i],input[child]);
		else break;
	}
}
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	int length=input.size();
	vector<int> r;
	if (k>length||k==0) return r;
	for (int j=input.size()/2-1;j>=0;--j){
		heap_adjust(input,j,input.size());
	}

	for (int j=0;j<k;++j)
	{
		swap(input[0],input[length-1-j]);
		heap_adjust(input,0,length-1-j);
	}
	
	for (int j=0;j<k;++j)
	{
		r.push_back(input[length-1-j]);
	}
	return r;
}
};
