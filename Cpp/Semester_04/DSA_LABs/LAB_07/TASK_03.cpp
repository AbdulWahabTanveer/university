#include <iostream>
#include "Stack.cpp"

using namespace std;
 
bool brackets_correctness(string expr){ 
    Stack<char> s;
    char x;
 
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{'){
            s.push(expr[i]);
            continue;
        }

        if (s.isEmpty())
            return false;
 
        switch (expr[i]){
        
            case ')':
                x = s.seeTop();
                s.pop();
                if (x == '{' || x == '[')
                    return false;
                break;
    
            case '}':
                x = s.seeTop();
                s.pop();
                if (x == '(' || x == '[')
                    return false;
                break;
    
            case ']':
                x = s.seeTop();
                s.pop();
                if (x == '(' || x == '{')
                    return false;
                break;

        }
    }

    return (s.isEmpty());
}

int main(){
    
    string val = "{asd(d((abbsaldljasd))casd)}";
    
    if (brackets_correctness(val))
        cout <<val<<"   is correct expression"<<endl;
    else
        cout <<val<<"   is incorrect expression"<<endl;
 
    val = "{(((abbsaldl(jasd)))}";
    
    if (brackets_correctness(val))
        cout <<val<<"   is correct expression"<<endl<<endl;
    else
        cout <<val<<"   is incorrect expression"<<endl<<endl;
    
    return 0;
}