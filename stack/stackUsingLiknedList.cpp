#include <iostream>
using namespace std;

template <class t>
class stack {
    struct node
    {
        int item;
        node* next;
    };
    
    node* top;
    node* current;

    public:
    
    stack ()
    {
        top = NULL;
    }

    void push(t newItem)
    {
        node* newItemPtr = new node;
        if (newItemPtr == NULL)
        {
            cout << "Stack Can't Allocate Memory";
        }
        else
        {
            newItemPtr->item = newItem;
            newItemPtr->next = top;
            top = newItemPtr;
            cout << newItem << "\n";
        }
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty On Pop";
        }
        else{
            node* temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }

    void pop(t&stackTop)
    {
        if(isEmpty())
        {
            cout << "Stack Empty On Pop";
        }
        else{
            stackTop = top->item;
            node* temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }

    void getTop(t&stackTop)
    {
        if(isEmpty())
        {
            cout << "Stack Empty On get Top Element";
        }
        else{
            stackTop = top->item;
            cout << stackTop;
        }
    }

    void print()
    {
        current = top;
        cout << "\n[";
        while (current != NULL)
        {
            cout << current->item << " ";
            current = current->next;
        }
        cout << "]\n";
    }
};

int main()
{
    stack<int> s;
    s.push(45);
    s.push(34);
    s.push(64);
    s.push(21);
    s.push(10);
    s.print();

    int toplist;
    s.getTop(toplist);
}