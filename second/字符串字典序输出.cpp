//字符串按字典序输出
//题目描述
///*输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 
//输入描述:
//输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
//字典序输出 就是对一个序列 从后向前找到两个相邻的元素  前面的地址为i  后面的地址为ii   然后在从后面开始找  找到第一个大于i
//的 命名为j  交换两者   然后 将ii和后面的所有 进行颠倒顺序 （旋转一下 ）
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        if(str.length()==0) return result;
        sort(str.begin(),str.end());
        result.push_back(str);
        while(next_permutation(str.begin(),str.end())){
              result.push_back(str);
        }
        return result;
    }
};
