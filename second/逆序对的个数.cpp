//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
//输入一个数组，求出这个数组中的逆序对的总数。 
class Solution {
public:
    int InversePairs(vector<int> data) {
        int len = data.size();
        if(2 > len) return 0;
         
        int count = 0;
        vector<int> tmp(len,0);
        merge(data,0,len-1,count,tmp);
        return count;
    }
     
    void merge(vector<int>& data, int left, int right, int& count, vector<int>& tmp){
        if(left == right) return;
         
        int mid = (left + right) / 2;
        merge(data,left,mid,count,tmp);
        merge(data,mid+1,right,count,tmp);
         
        int flag = right;
        int i = mid, j = right;
        for( ; i >= left && j >= mid+1 ; ){
            if(data[i] > data[j]){
                count += (j - mid);
                tmp[flag --] = data[i --];
            }
            else{
                tmp[flag --] = data[j --];
            }
        }
         
        for( ; i >= left ; -- i) tmp[flag --] = data[i];
        for( ; j >= mid+1 ; --j) tmp[flag --] = data[j];
        for(int k = left ; k <= right ; ++ k) data[k] = tmp[k];
    }
};
