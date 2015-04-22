//统计一个数字在排序数组中出现的次数  log（n)   java实现  运行通过
public class Solution {
    public int GetNumberOfK(int [] array , int k) {
       	int start=0;
		int end=array.length;
		int middle=0;
		int num=0;
		int flag=-1;
        if(end<1) return 0;
		else if(end==1){
			if(array[0]==k) return 1;
			else return 0;
		}
		//System.out.println(end);
		while(middle!=(start+end)/2){
		//	System.out.println(middle);
			middle=(start+end)/2;
			if(array[middle]==k){
				flag=middle;
				break;
			}
			else if(array[middle]<k){
				start=middle;
			}
			else{
				end=middle;
			}
		}
		if(flag==-1) return 0;
		//System.out.println(num);
		int i=flag;
		while(array[i]==k){
			i++;
			if(i==array.length) break;
		}
		int j=flag;
		while(array[j]==k){
			j--;
			if(j==-1) break;
		}
		num=i-j-1;
		return num;
        //System.out.println(num);

    }
}
