#include <iostream>

using namespace std;

template <class t >
class Stack{
    struct Node{
        t data ;
        Node* PointerToNext;
    };
    Node* top ;

    public:
    Stack(){
        top = NULL;
    }

    void push( t newItem){
         Node* newNode = new Node;
         newNode->data = newItem;

         newNode->PointerToNext =top;
         top =newNode;
    }

    bool isEmpty(){
        return (top == NULL) ;
    }
    t pop(){
        if(isEmpty()){
            cout << "Stack is empty" ;
        }
        else{
            t poppedItem = top->data ;
            Node* tempNode = new Node ;
            tempNode = top ;

            top=top->PointerToNext ;
            tempNode=tempNode->PointerToNext = NULL;
            delete tempNode ;
        }
    }
    void print(){
        Node* nodeIterator = new Node ;
        nodeIterator = top ;
        while(nodeIterator != NULL ){
            cout << nodeIterator->data << endl ;
            nodeIterator= nodeIterator->PointerToNext;
        }
    }

};
int main()
{

    Stack<int> s ;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();

    s.pop();
    s.print();

    return 0;
}
