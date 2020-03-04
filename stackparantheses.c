#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool balanced(string expr)
{
    std::stack<char>s ;
    char x;
    for(int i=0;i<expr.length();i++)
    {
if (expr[i]=='('||expr[i]=='['||expr[i]=='{') 
        { 
            
            s.push(expr[i]); 
            continue; 
        } 
        else if(expr[i]==')'&&s.top()=='('||expr[i]==']'&&s.top()=='['||expr[i]=='}'&&s.top()=='{')
        {  if(s.empty()) return false;
          else
            s.pop();
        }
    }
    return s.empty()?true:false;
}
int main() 
{ 
    string expr = ""; 
  
    if (balanced(expr)) 
        cout << "Balanced"; 
    else
        cout << "Not Balanced"; 
    return 0; 
} 