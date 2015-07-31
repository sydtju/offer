//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。


//这个思路很简单  但是很奇特 首先的原则是字符串放在一起的长度是一样的，所以在前面的数越小 整个数字就越小 
//也就是将字串按照从小到大的顺序进行排序   为了比较逻辑严密  将两个字符串分别放在另一个字符串的尾部
class Solution {
public:
   static bool compare(string str1,string str2){
        return(str1+str2)<(str2+str1);
    }
    string PrintMinNumber(vector<int> numbers) {
        string result;
        vector<string>str;
        int l=numbers.size();
        if(l<=0)
            return result;
        for(int i=0;i<l;i++){
            stringstream ss;
            ss<<numbers.at(i);
            str.push_back(ss.str());
        }
        sort(str.begin(),str.end(),compare);
        for(int i=0;i<l;i++){
            result+=str.at(i);
        }
        return result;
         
    }
};
