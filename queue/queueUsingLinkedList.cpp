#include <iostream>

using namespace std;

template <class T>
class LinkedQueue {

    struct Node
    {
        T item;
        Node *next;
    };

    Node*frontPtr;
    Node*rearPtr;
    int length;

    public:

    LinkedQueue()
    {
        frontPtr = rearPtr = NULL;
        length = 0;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    void enqueue(T element)
    {
        if(isEmpty())
        {
            frontPtr = new Node;
            frontPtr->item = element;
            frontPtr->next = NULL;
            rearPtr = frontPtr;
            length++;
        }
        else
        {
            Node* newPtr = new Node;
            newPtr->item = element;
            newPtr->next = NULL;
            rearPtr->next = newPtr;
            rearPtr = newPtr;
            length++;
        }
    }

    void dequeue()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            Node* tempPtr = frontPtr;
            if(frontPtr == rearPtr)
            {
                frontPtr = NULL;
                rearPtr = NULL;
                length--;
            }
            else
            {
                frontPtr = frontPtr->next;
                tempPtr->next = NULL;
                free(tempPtr);
                length--;
            }
        }
    }

    void clear()
    {
        if(!isEmpty())
        {
            Node* current;
            while(frontPtr != NULL)
            {
                current = frontPtr;
                frontPtr = frontPtr->next;
                free(current);
            }
            rearPtr = NULL;
            length = 0;
        }
        else
        {
            cout << "Queue is already Empty!" << endl;
        }
    }

    int getFront()
    {
        return frontPtr->item;
    }

    int getRear()
    {
        return rearPtr->item;
    }

    void display()
    {
        if(!isEmpty())
        {
            Node* current = frontPtr;
            cout << "[ ";
            while (current != NULL)
            {
                cout << current->item << " ";
                current = current->next;
            }
            cout << " ]" << endl;
        }
        else
        {
            cout << "Queue is Empty!" << endl;
        }
    }

    int qsize()
    {
        return length;
    }

};

int main()
{
    LinkedQueue<int> qu;

    qu.enqueue(50);
    qu.enqueue(70);
    qu.enqueue(90);
    qu.enqueue(110);

    cout << "Front: " << qu.getFront() << endl;
    cout << "Rear: " << qu.getRear() << endl;
    cout << "Size: " << qu.qsize() << endl;

    qu.display();
    qu.dequeue();
    qu.display();    
    qu.clear();
}