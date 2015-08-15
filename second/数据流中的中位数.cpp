//如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
//如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值
//解题思路：将输入数据分为两个部分  较大一部分用小根堆   较小的一部分用大根堆    奇数的时候小根堆多一个  
//插入的数字  如果总数是偶数就插入 较大的部分  但是也不能直接插入  到小的部分去换一个最大的  插到较大部分  
//奇数的话就插入到较小的部分  不是直接插入 如果比上面最小的还大的话 就插入上面 然后得到最小的  在插入较小的部分
class Solution {
     private:
        vector<int> min_buffer; //数组中的后一半元素组成一个最小化堆
        vector<int> max_buffer; //数组中的前一半元素组成一个最大化堆
public:
    void Insert(int num)
    {
        if(((min_buffer.size()+max_buffer.size()) & 1) == 0) {  //偶数数据的情况下，则在最小堆中插入元素
                if(max_buffer.size() > 0 && num < max_buffer[0]) {
                    max_buffer.push_back(num);
                    push_heap(max_buffer.begin(), max_buffer.end(), less<int>());
                    num=max_buffer[0];
                    pop_heap(max_buffer.begin(), max_buffer.end(), less<int>());
                    max_buffer.pop_back();
                }
                min_buffer.push_back(num); //把前一半找到的最大值放到后一半中
                push_heap(min_buffer.begin(), min_buffer.end(), greater<int>());
            } else {
                if(min_buffer.size() > 0 && num > min_buffer[0]) {   //奇数数据的情况下，则在最大堆中插入元素
                    min_buffer.push_back(num);
                    push_heap(min_buffer.begin(), min_buffer.end(), greater<int>());
                    num=min_buffer[0];
                    pop_heap(min_buffer.begin(), min_buffer.end(), greater<int>());
                    min_buffer.pop_back(); 
                }
                max_buffer.push_back(num); //把后一半找到的最大值放到前一半中
                push_heap(max_buffer.begin(), max_buffer.end(), less<int>());
            }
    }

    double GetMedian()
    { 
    		int size=min_buffer.size() + max_buffer.size();
            if(size==0) return -1;
            double median = 0;
            if((size&1) != 0) {
                median = (double) min_buffer[0];
            } else {
                median = (double) (max_buffer[0] + min_buffer[0]) / 2;
            }
            return median;
    }

};
