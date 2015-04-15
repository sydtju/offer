//输入字母的全排列 并且按字典序输出  运行通过    还需要再理解下
class Solution {
public:
    bool isswap(string str,int i,int j){
	for(int k=i;k<j;k++){
		if(str[i]==str[j])
			return false;
	}
	return true;
	}
    void swap(string &a,int i,int j){
	char temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	}
    void bubbleSort(string arr,int begin,int length){
    int i,j;
    for(i=begin;i<=length;i++){
        for(j=i+1;j<=length;j++){
            if(arr[i]>arr[j]){
                swap(arr,i,j);
            }
        }
  	  }
	}
	void per_it(vector<string> &t,string str,int s,int e){
	if (s==e)
	{
		t.push_back(str);
	}
	else{
		for (int i=s;i<=e;i++)
		{
            if (isswap(str,s,i))
			{
			swap(str,s,i);
            bubbleSort(str,s+1,e);
			per_it(t,str,s+1,e);
			bubbleSort(str,s+1,e);
                }
			}

		}
	}
    vector<string> Permutation(string str) {
			vector<string> t;
        	bubbleSort(str,0,str.size()-1);
			per_it(t,str,0,str.size()-1);
			return t;
	}
};
