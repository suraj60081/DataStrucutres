#include<string>
#include<stack>
#include<iostream>
using namespace std;
int prec(char c)
{
    if(c=='^') return 3;
    if(c=='/'||c=='*') return 2;
    if(c=='-'||c=='+') return 1;
    return -1;
}

void postfix(string e)
{
    string ne="";
    std::stack<char> s ;
    s.push('N');
    
    for(int i=0;i<e.length();i++)
    {
        if(e[i]>='a' &&e[i]<='z' || e[i]=='A'&&e[i]<='Z')
        {
            ne=ne+e[i];
        }
        else if(e[i]=='+'||e[i]=='-'||e[i]=='*'||e[i]=='/'||e[i]=='^')
        {
            while(s.top()!='N'&&prec(e[i])<=prec(s.top()))
            {
                char x=s.top();
                ne+=x;
                s.pop();
            }
            s.push(e[i]);
        }
        else if(e[i]=='(')
        {
            s.push(e[i]);
        }
        else if(e[i]==')')
        {
            while(s.top()!='N'&&s.top()!='(')
            {
                char c = s.top();
                s.pop();
                ne+=c;
            }
            if(s.top()=='(')
            {
                s.pop();
            }
        }
    }
    while(s.top()!='N')
    {
        ne+=s.top();
        s.pop();
    }
    cout<<ne<<endl;
}
int main()
{
    string e;
    std::cout << "enter string" << std::endl;
    cin>>e;
    postfix(e);
    return 0;
}
