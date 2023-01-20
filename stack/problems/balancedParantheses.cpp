#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool arePair(char open, char close)
{
    if (open == '(' && close == ')')
        return true;
    
    else if (open == '{' && close == '}')
        return true;

    else if (open == '[' && close == ']')
        return true;

    return false;
}


bool areBalanced(string exp)
{
    stack<char> s;
    for (size_t i = 0; i < exp.length(); i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            s.push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (s.empty() || !arePair(s.top(), exp[i]))
                return false;
            else
                s.pop();
        }
    }
     
     return s.empty();
}

int main()
{
    string expression;
    cout << "Enter an Expression: ";
    cin >> expression;
    if(areBalanced(expression))
        cout << "Expression is Balanced\n";
    else
        cout << "Expression not Balanced\n";

    // Ex:
    // (9+2)*{[12*(12+2)][24*(24+2)]} or (9+2) => are Balances
    // (9+2)*{[12*(12+2)]24*(24+2)]} or (9+2 => are not Balances
}