

#include <string>
#include <iostream>
#include <stack>
using namespace std;


string kendy_crush(string s){
    stack<char> stack ;
    int counter =1;
    char curr;
    stack.push(s.at(0));
    for (int i = 1; i < s.size(); ++i) {
        if(stack.top()==s.at(i)){
            counter++;
            stack.push(s.at(i));
            if(i==s.size()-1&&counter>1){
                while(counter!=0) {
                    stack.pop();
                    counter--;
                }
            }
        }else{
            if(counter>1){
                while(counter!=0) {
                    stack.pop();
                    counter--;
                }
                counter =1;
                if(!stack.empty()) {
                    if (stack.top() == s.at(i)) {
                        counter++;
                    }
                }
                stack.push(s.at(i));
            }else{
                stack.push(s.at(i));
            }
        }

    }
    string ans="";
    while(stack.size()!=0){
        ans+=stack.top();
        stack.pop();
    }
    return ans;
}

int main(){
    string test = "aabcbbcdsaccc";
//                    "acadadas"
    cout<<"That is the string result : "<< kendy_crush(test)<<endl;

}