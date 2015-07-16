//运行通过
/*
这里假设，给出n个数字（0到n-1），每次删除第m个数字，其中用f（n，m）表示剩余的最后哪一个数字。

删除之前的序列：0,1,2,3,...,k-1,k,k+1,...,n。

假设本次删除的数字为k,其中k = （m-1）%n，则删除后的序列为：0,1,2,3,...,k-1,k+1,...,n。

注意，为什么k = （m-1）%n？这是因为n可能比m小。比如，n=3（0到2），m=5。第一次删除的数为1。

此时，我们对删除k后的数字进行处理：
转换前： k+1  k+2  k+3........  k-1 x
转换后：  0    1    2 ........  n-2 y

假设转换前的数字为x，转换后的数字为y，则可得y = (x - k - 1 + n) % n。之后继续对转换后的数字进行删除。

如果知道y，我们也可以找到其对应的 x 值，其x = （y + k + 1）% n。

注：可以不用求反函数得到两个公式：

（1）转换前的数x 比 转换后的数y 多了k+1，之后直接相减，但相减后可能为负数，所以要加上n，之后在取余。

（2）转换后的数y 比 转换前的数x 少了k+1，之后直接相加取余即可。

给出两个假设。

（1）对转换前的n-1个数继续删除，最后剩下的数字为x = f'(n-1,m)。由于该序列数不是从0开始的，不能写成f(n-1,m)的形式。

（2）继续对转换后的n-1个数进行删除，最后剩余的数字为y = f(n-1,m)。

根据假设（1）可知，一定有f（n，m） = f'（n-1，m）成立。

我们继续对转换之前和转换之后的序列进行删除，最终得到的数一个为x，一个为y。

注意，此x和y一定是对应的。虽然转换前后两个序列中的数不同，但是对于最终留下的哪一个数，它们所在的下标应该是一样的。

即，一定有f'（n-1，m） =（ f（n-1，m） + k + 1）%n。

此时，相当于已知y（等于 f（n-1，m）），而要求解x，且x对应着f'（n-1，m）。

根据上述思想，可得：  n=1；f（n,m）=0；

f（n，m） = f'（n-1,m）= ( f（n-1，m） + k + 1）%n。

而k = （m - 1）%n成立，带入上式子可得，

则有f（n，m） =（ f（n-1，m） +m）%n。

即， 我们 对n-1个数（0到n-2）进行删减最终得到的数 稍做处理 ，即可得到对n个数（0到n-1）进行删减最终得到数。*/
class Solution {
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
        unsigned int fn=0;
        unsigned int nlen=2;
        if(n<1||m<1) return -1;
        while(nlen<=n){
            fn=(fn+m)%nlen;
            ++nlen;
        }
        return fn;
    }
};


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
