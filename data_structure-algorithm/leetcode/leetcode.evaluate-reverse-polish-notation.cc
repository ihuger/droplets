#include<string>
#include<vector>
#include<iostream>
#include<stack>
using namespace std;
class Solution {
    public:
        int evalRPN(vector<string> &tokens) {
            stack<int> stk;
            
            for(vector<string>::iterator iter = tokens.begin();
                    iter != tokens.end(); ++iter){
                //cout<<*iter<<endl;
                if( ((*iter)[0]<='9' && (*iter)[0]>='0') || 
                        ((*iter)[0]=='-' && (*iter).length()>1)){
                    int value = atoi((*iter).c_str());
                    stk.push(value);
                }else{
                    int v1 = stk.top();
                    stk.pop();
                    int v2 = stk.top();
                    stk.pop();
                    cout<<v2<<"\t"<<*iter<<"\t"<<v1<<endl;
                    switch((*iter)[0]){
                        case '+':
                            stk.push(v2+v1);
                            break;
                        case '-':
                            stk.push(v2-v1);
                            break;
                        case '/':
                            stk.push(v2/v1);
                            break;
                        case '*':
                            stk.push(v2*v1);
                            break;
                        default:
                            break;
                    }
                }
           }
          return stk.top();
        }
};

int main(){
    vector<string> tokens;
    //tokens.push_back("2");
    //tokens.push_back("1");
    //tokens.push_back("+");
    //tokens.push_back("3");
    //tokens.push_back("*");

    tokens.push_back("-1");
    tokens.push_back("1");
    tokens.push_back("*");
    tokens.push_back("-1");
    tokens.push_back("+");

    Solution so;
    cout<<so.evalRPN(tokens)<<endl;
    
    return 0;
}
