// STACK IMPLEMENTATION 
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
     vector<T> data;

public:
    void push(const T& element) {
        data.push_back(element);
    }

    void pop() {
        if (!isEmpty()) {
            data.pop_back();
        }
    }

    T top() const {
        if (!isEmpty()) {
            return data.back();
        }
        throw out_of_range("Stack is empty");
    }

    bool isEmpty() const {
        return data.empty();
    }
};

int main() {
    Stack<int> stack;

    int choice;
    int element;

    do {
        cout << "Stack Operations:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to push: ";
                cin >> element;
                stack.push(element);
                cout << "Element pushed to the stack." << endl;
                break;
            case 2:
                if (!stack.isEmpty()) {
                    stack.pop();
                    cout << "Element popped from the stack." << endl;
                } else {
                     cout << "Stack is empty. Cannot perform pop operation." << endl;
                }
                break;
            case 3:
                if (!stack.isEmpty()) {
                   cout << "Top element: " << stack.top() << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

       cout << endl;
    } while (choice != 4);

    return 0;
}
// QUEUE IMPLEMENTATION

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Queue {
private:
   vector<T> data;
    int frontIndex;
    int rearIndex;

public:
    Queue() : frontIndex(-1), rearIndex(-1) {}

    void enqueue(const T& element) {
        if (isEmpty()) {
            frontIndex = 0;
        }
        rearIndex++;
        data.push_back(element);
    }

    void dequeue() {
        if (!isEmpty()) {
            frontIndex++;
            if (frontIndex > rearIndex) {
                // Reset queue indices when all elements are dequeued
                frontIndex = -1;
                rearIndex = -1;
                data.clear();
            }
        }
    }

    T front() const {
        if (!isEmpty()) {
            return data[frontIndex];
        }
        throw out_of_range("Queue is empty");
    }

    T rear() const {
        if (!isEmpty()) {
            return data[rearIndex];
        }
        throw out_of_range("Queue is empty");
    }

    bool isEmpty() const {
        return (frontIndex == -1 && rearIndex == -1);
    }
};

int main() {
    Queue<int> queue;

    int choice;
    int element;

    do {
       cout << "Queue Operations:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Rear" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to enqueue: ";
                cin >> element;
                queue.enqueue(element);
                cout << "Element enqueued." << endl;
                break;
            case 2:
                if (!queue.isEmpty()) {
                    queue.dequeue();
                    cout << "Element dequeued." << endl;
                } else {
                    cout << "Queue is empty. Cannot perform dequeue operation." << endl;
                }
                break;
            case 3:
                if (!queue.isEmpty()) {
                    cout << "Front element: " << queue.front() << endl;
                } else {
                   cout << "Queue is empty." << endl;
                }
                break;
            case 4:
                if (!queue.isEmpty()) {
                    cout << "Rear element: " << queue.rear() << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}