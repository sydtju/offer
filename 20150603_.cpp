//打印数字矩形  代码比较短

#include <stdio.h>
#include <stdlib.h>
int dat[3][4]={{0,1,2,3},{4,5,6,7},{7,8,9,10}};
void prin(int x0,int y0,int x1,int y1){
	int i=0;
	if (x0==x1)
	{
		for( i=y0;i<=y1;i++)
			printf("%d  ",dat[x0][i]);
	}
	else if (y0==y1)
	{
		for( i=x0;i<=x1;i++)
			printf("%d  ",dat[y0][i]);
	}
	else{
	for( i=y0;i<=y1;i++)
		printf("%d  ",dat[x0][i]);
	for( i=x0+1;i<x1;i++)
		printf("%d  ",dat[i][y1]);
	for( i=y1;i>=y0;i--)
		printf("%d  ",dat[x1][i]);
	for( i=x1-1;i>x0;i--)
		printf("%d  ",dat[i][y0]);
	}
	printf("\n");
}
int main(){
	
	int x0=0;
	int y0=0;
	int x1=2;
	int y1=3;
	//printf("%d\n",dat[0][0]);
	while (x0<=x1)
	{
		prin(x0++,y0++,x1--,y1--);
	}
	system("pause");
	return 0;
}
