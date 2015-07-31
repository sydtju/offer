//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
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
