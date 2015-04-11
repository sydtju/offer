//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
class Solution {
public:
	int jumpFloor(int number) {
		int  temp0=1;
        int  temp1=2;
        int  temp2=0;
        int counter=2;
        if(1==number) return 1;
        else if (2==number) return 2;
        else {
            while(counter<number){
                temp2=temp1+temp0;
                temp0=temp1;
                temp1=temp2;
                counter++;
            }
            return temp1;
        }
            
	}
};
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
class Solution {
public:
	int jumpFloorII(int number) {
		int counter=1;
        int temp1=1;
        int temp=0;
        if(number<0) return -1;
		if(number==0) return 1;
        else if(number==1) return 1;
        else {
            while(counter<number){
                temp=2*temp1;
                temp1=temp;
                counter++;
            }
            return temp1;
        }
	}
};
