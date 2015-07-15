//一个链表中包含环，请找出该链表的环的入口结点
//如果存在环，找到环的起始结点
//当fast指针等于slow指针时，slow指针肯定还没有遍历完整个链表，而此时fast指针已经在环内循环了n圈(n>=1)，
//假定从链表头指针开始slow走了s步，则fast走了2s步，fast所走的步数还等于s加上fast指针比slow指针在环内多走的n圈。
//设环长为r，则：
//2s = s + nr;
//=>s = nr;
//设整个链表长度为L，环的入口结点到相遇结点的距离为x, 起点到环的入口结点的距离为a.
//a + x = nr;
//=> a + x = (n-1)r + L - a;
//=> a = (n-1)r + (L - a - x);
//=> 由链表的头结点到环入口结点的距离等于n-1圈环的长度+相遇点到环入口结点的距离，于是，
//当我们在链表头部和相遇处分别设一指针，每次各走一步，则两指针必定相遇，且相遇的第一个结点即为环的入口结点，
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
 	 ListNode*  fast = pHead;
     ListNode*   slow = pHead;  
    while( fast != NULL && fast->next != NULL ){  
        slow = slow->next;  
        fast = fast->next->next;  
        if( fast == slow )  
            break;  
    }     
    if( fast == NULL || fast->next == NULL )  
        return NULL;  
    slow = pHead;  
    while( fast != slow ){  
        slow = slow->next;  
        fast = fast->next;  
    }     
    return fast;  
    }
};
