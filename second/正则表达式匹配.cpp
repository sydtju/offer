/*假设字符串为str，模式串为pattern，考虑以下情况：

A. 模式串下一个字符为*，即*(pattern+1)=='*'：

如果当前字符匹配，即*str=*pattern或者*str='.' && *pattern!='\0'，三种可能：

 1、模式串当前字符出现0次，即*表示当前字符出现0次，则str=str,pattern=pattern+2;

 2、模式串当前字符出现1次，即*表示当前字符出现1次，则str=str+1,pattern=pattern+2;

 3、模式串当前字符出现2次或2次以上，即*表示当前字符出现2次或以上，则str=str+1,pattern=pattern;

如果当前字符不匹配，则只能让*表示当前字符出现0次，则str=str，pattern=pattern+2;

B. 模式串下一个字符不为*

如果当前字符匹配，即*str=*pattern或者*str='.' && *pattern!='\0'，则str=str+1,pattern=pattern+1.*/
class Solution {
public:
    bool match(char* str, char* pattern)
    {
  if(*str=='\0' && *pattern=='\0')
        return true;
    if(*str!='\0' && *pattern=='\0')
        return false;
  
    if(*(pattern+1)=='*'){
        if(*str==*pattern || (*str!='\0' && *pattern=='.'))
            return match(str,pattern+2) || match(str+1,pattern+2) || match(str+1,pattern);
        else
            // ignore *
            return match(str,pattern+2);
    }
  
    if(*str==*pattern || (*str!='\0' && *pattern=='.'))
        return match(str+1,pattern+1);
  
    return false;
    }
};
