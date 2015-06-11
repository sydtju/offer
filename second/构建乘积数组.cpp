//给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
//不能使用除法。
//版本1 暴力解法 nlog(n)
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
	unsigned int length=A.size();
	vector<int> B;
	int temp=1;
	for (unsigned int i=0;i<length;i++)
	{
		for (unsigned int j=0;j<length;j++)
		{
			if (i!=j){
				temp=temp*A[j];
			}
		}
		B.push_back(temp);
		temp=1;
	}
	return B;
	}
};
//版本2 优秀的解法 O(n) 
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
	vector<int> B;
	int temp=1;
	unsigned int length=A.size();
	unsigned int size=length-1;
	B.push_back(temp);
	for (unsigned int i=1;i<length;i++)
	{
		temp=temp*A[i-1];
		B.push_back(temp);
	}
	temp=1;
	for (unsigned int i=1;i<length;i++)
	{
		temp=temp*A[size-i+1];
		B[size-i]=B[size-i]*temp;
	}
	return B;
	}
};
