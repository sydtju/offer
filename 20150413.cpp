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
//输出链表倒数第k个节点
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	//	if(k<0) return 0;
        int k_temp=k;
        ListNode *start=pListHead;
         ListNode *end=pListHead;
        while(k_temp--){
            if(end==NULL){
                return NULL;
            }
            else
                end=end->next;
        }
        while(end!=NULL){
            start=start->next;
            end=end->next;
        }
        return start;
	}
};
