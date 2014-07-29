#include<string>
#include<iostream>
using namespace std;
class Solution {
    public:
            void reverseWords(string &s) {
                reduceSpaceInString(s);
                size_t len = s.length();
                if(len==0)
                    return;
                reverseSubString(s,0,len-1);
                size_t start,end;
                start=end=-1;
                while(end != len){
                    start = end + 1;
                    while(start < len && s[start] == ' ') 
                        ++start;
                    if(start >= len)
                        break;
                    end = start+1;
                    while(end < len && s[end] != ' ')
                        ++end;
                    reverseSubString(s,start,end-1);
                }
            }
            void reduceSpaceInString(string &s){
                size_t cur,wpos;
                size_t len = s.length();
                cur=wpos=0;
                while(cur<len){
                    while(wpos<len && s[wpos]==' '){
                        ++wpos;
                    }
                    while(wpos<len && s[wpos]!=' '){
                        if(cur!=wpos)
                            s[cur]=s[wpos];
                        ++cur;
                        ++wpos;
                    }
                    ++wpos;
                    if(wpos<len && cur<len){
                        s[cur]=' ';
                        ++cur;
                    }
                    if(wpos>=len && cur<len){
                        if(s[cur-1]==' ')
                            --cur;
                        s.erase(cur);
                        return;
                    }
                }
            }
            void reverseSubString(string &s,size_t start,size_t end){
                char ch;
                while(start < end ){
                    ch = s[start];
                    s[start] = s[end];
                    s[end] = ch;
                    ++start;
                    --end;
                }
            }
};

int main(){
    Solution so;
    
    string s1("abc df eg   ");
    cout<<"."<<s1<<"."<<endl;
    so.reverseWords(s1);
    cout<<"."<<s1<<"."<<endl;

    string s2("     ");
    cout<<"."<<s2<<"."<<endl;
    so.reverseWords(s2);
    cout<<"."<<s2<<"."<<endl;

    string s3(" cde sdkfj    32145 a99990000    dfk kfg  s123    ");
    cout<<"."<<s3<<"."<<endl;
    so.reverseWords(s3);
    cout<<"."<<s3<<"."<<endl;

    return 0;
}
