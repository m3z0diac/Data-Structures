#include <iostream>
using namespace std;

// Define the maximum length of the stack
const int MAX_SIZE = 100;

template <class t>
class stack {
    int top;
    t items[MAX_SIZE];

    public:
    stack() {
        top = -1;
    }
    void push(t element)
    {
        if (top >= MAX_SIZE)
        {
            cout << "Stack Full On Push";
        }
        else
        {
            top++;
            items[top] = element;
        }
    }

    bool isEmpty()
    {
        return top < 0;
    }

    void pop()
    {
        if(isEmpty())
            cout << "Stack Empty On Pop";
        else
            top--;
    }

    void pop(t Element)
    {
        if(isEmpty())
            cout << "Stack Empty On Pop";
        else {
            Element = items[top];
            top--;
        }
    }

    void getTop()
    {
        if(isEmpty())
            cout << "Stack Empty On get Top Element";
        else {
            cout << items[top];
        }
    }

    void print()
    {
        
        for (int i = top; i >=0 ; i--)
        {
            cout << "|  " << items[i] << "  |" << endl;
        }
        cout << "-------" << endl;
    }

};

int main()
{
    stack<char> s;

    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');
    s.print();
    
    s.getTop();
}