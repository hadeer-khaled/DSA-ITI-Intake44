#include <iostream>

using namespace std;

template <class T>
class Queue {
    struct Node {
        T data;
        Node* pointerNextNode;
    };
    Node* head;
    Node* tail;
    int length;

public:
    Queue() {
        head = tail = NULL;
        length = 0;
    }

    bool isEmpty() {
        return (length == 0);
    }

    void enqueue(T data) {
        if (isEmpty()) {
            head = new Node;
            head->data = data;
            head->pointerNextNode = NULL;
            tail = head;
        }
        else {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->pointerNextNode = NULL;

            tail->pointerNextNode = newNode;
            tail = newNode;
        }
        length++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "The queue is empty" << endl;
        }
        else {
            Node* tempNode = head;

            if (head == tail) {
                head = NULL;
                tail = NULL;
            }
            else {
                head = head->pointerNextNode;
            }

            delete tempNode;
            length--;
        }
    }

    void print() {
        Node* nodeIterator = head;
        while (nodeIterator != NULL) {
            cout << nodeIterator->data << endl;
            nodeIterator = nodeIterator->pointerNextNode;
        }
    }
};

int main() {
    Queue<int> q;
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);
    q.print();
    return 0;
}
