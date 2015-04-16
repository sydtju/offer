//数组中重复的数字问题  运行通过
class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		int *temp=new int[length];
        int counter=0;
        int k=0;
        for(int i=0;i<length;i++){
            temp[i]=-1;
        }
        for(int j=0;j<length;j++){
                temp[numbers[j]]++;
        }
        for(int i=0;i<length;i++){
            if(temp[i]>=1) {
                counter++;
             	duplication[k++]=i;
        }
        }
        delete[] temp;
     if(counter==0) 
         			return false;
     else
        			return true;
	}
};
