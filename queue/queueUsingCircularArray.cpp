#include <iostream>
using namespace std;

template <class T>
class queueUsingCircularArray
{
    int rear; // will help for enqueue
    int front; // will help for dequeue
    int length;
    T *arr;
    int MAX_SIZE;
    public:
    
    queueUsingCircularArray(int size)
    {
        if(size <= 0)
            MAX_SIZE = 100;
        else
            MAX_SIZE = size;

        arr = new T[MAX_SIZE];
        rear = MAX_SIZE - 1;
        front = 0;
        length = 0;
    }

    bool isEmpty()
    {
        return length == 0;
    }
    
    bool isFull()
    {
        return length == MAX_SIZE;
    }

    void enqueue(T element)
    {
        // O(1)
        if(isFull())
        {
            cout << "Queue is full on enqueu\n";
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = element;
            length++;
        }
    }

    void dequeue()
    {
        // O(1)
        if(isEmpty())
        {
            cout << "Queue is empty on dequeue\n";
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
            length--;
        }
    }

    void getFront(T &element) // peek
    {
        // O(1)
        if (isEmpty())
        {
            cout << "Queue is empty on getFront";
        }
        else
            element = arr[front];
    }

    void getRear(T &element)
    {
        // O(1)
        if (isEmpty())
        {
            cout << "Queue is empty on getRear";
        }
        else
            element = arr[rear];
    }

    int search(T element)
    {
        int pos = -1;
        if(!isEmpty())
        {
            // O(n)
            for(int i = front; i != rear; i = (i + 1) % MAX_SIZE)
            {
                if(arr[i] == element)
                {
                    pos = i;
                    break;
                }
            }
            if(pos == -1)
            {
                if(arr[rear] == element)
                {
                    pos = rear;                
                }
            }
        }
        else
            cout << "Queue is empty!";
        return pos;
    }

    void display()
    {
        if (!isEmpty())
        {
            // O(n)
            for(int i = front; i != rear; i=(i+1)%MAX_SIZE)
            {
                cout << arr[i] << " ";
            }
            cout << arr[rear] << endl;
        }
        else
            cout << "Queue is empty!\n";
    }

};

int main()
{
    queueUsingCircularArray<char> q(5);

    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');
    q.enqueue('D');
    q.enqueue('E');

    char frontValue;
    q.getFront(frontValue);

    char rearValue;
    q.getRear(rearValue);

    cout << "Head: " << frontValue << endl << "Tail: " << rearValue << endl;

    q.display();

    char el = 'C'; // 3
    cout << "Position of " << el << " is: " << q.search(el);

}