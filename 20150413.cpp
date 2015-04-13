//用冒泡的方法解决 调整数组顺序使奇数位于偶数前面的问题  这里空间复杂度已经降到最低  但是时间复杂度没有降到最低 
	void reOrderArray(vector<int> &array) {
        int i=0;
        while(i<array.size()){
            if(1==array[i]%2){
                while(i-1>=0){
                	if(array[i-1]%2==0){
                	    int temp=array[i-1];
                        array[i-1]=array[i];
                        array[i]=temp;
                        i--;
                	}
                    else{
                        break;
                    }
            	}
                i=i+1;
            }
            else{
                i++;
            }
        }
    }
