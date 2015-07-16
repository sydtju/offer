//下面是使用STL list模拟约瑟夫环进行的结题思路  但是运行超时
int LastRemaining_Solution(unsigned int n, unsigned int m)
{
	list<int> ltemp;
	list<int>::iterator it,it_temp;
	int num=1;
	if (n==0) return -1;
	if (n==1) return 1;
	while (num<=n)
	{
		ltemp.push_back(num++);
	}
	cout<<"size="<<ltemp.size()<<endl;
	int count=1;
	it=ltemp.begin();
	while (ltemp.size()!=1)
	{
		if (count==m){
			if (it==ltemp.end()){
				it=ltemp.begin();
			}
			it_temp=it++;
			ltemp.erase(it_temp);
			count=1;}
		else{
			if (it==ltemp.end()) 
				{it=ltemp.begin();++it;}
			else
				++it;
			++count;
		}
	}
	return ltemp.front();
}
