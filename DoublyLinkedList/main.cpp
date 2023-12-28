#include <iostream>

using namespace std;

class DoublyLinkedList{

struct Node{
    int data;
    Node* pointerNextNode;
    Node* pointerPrevNode;
};
    Node* head;
    Node* tail;
    int length;

public:
    DoublyLinkedList(){
        head = tail = NULL;
        length = 0;
    }
    /////////////////////////////////////
   // Copy Constructor
DoublyLinkedList( DoublyLinkedList& oldDLL) {
    head = tail = NULL;

    if (oldDLL.head != NULL) {
        Node* oldDLLCurrent = oldDLL.head;

        head = new Node;
        head->data = oldDLLCurrent->data;
        head->pointerPrevNode = NULL;

        Node* current = head;
        oldDLLCurrent = oldDLLCurrent->pointerNextNode;

        while (oldDLLCurrent != NULL) {
            current->pointerNextNode = new Node;
            current->pointerNextNode->data = oldDLLCurrent->data;
            current->pointerNextNode->pointerPrevNode = current;
            current->pointerNextNode->pointerNextNode = NULL;

            current = current->pointerNextNode;
            oldDLLCurrent = oldDLLCurrent->pointerNextNode;
        }
        tail = current;
    }
    length = oldDLL.length;
}

    /////////////////////////////////////////
    bool isEmpty(){
        return (length ==0) ;
    }
    void insertFirst(int data){
        Node* newNode = new Node ;
        newNode->data = data;
        if(isEmpty()){
            head = tail = newNode ;
            newNode->pointerNextNode  = newNode->pointerPrevNode = NULL;
        }
        else{
            newNode->pointerNextNode = head;

            newNode->pointerPrevNode=NULL;

            head->pointerPrevNode=newNode;

            head= newNode;
        }
        length++;
    }
    void insertLast(int data){
        Node* newNode = new Node ;
        newNode->data = data;
        if(isEmpty()){
            head = tail = newNode ;
            newNode->pointerNextNode  = newNode->pointerPrevNode = NULL;
        }
        else{
            newNode->pointerNextNode = NULL;
            newNode->pointerPrevNode=tail;
            tail->pointerNextNode=newNode;
            tail= newNode;
        }
        length++;
    }

    void insertAtPosition(int data , int position){
        if(position < 0 || position > length){
            cout<< "Out of range" ;
        }
        else{

            Node* newNode = new Node ;
            newNode->data = data;
            if(position== 0){
                insertFirst(data);
            }
            else if(position == length){
                insertLast(data);
            }
            else{
                Node* nodeIterator = head ;
                for(int i = 1 ; i<position ; i++){
                        nodeIterator= nodeIterator->pointerNextNode;
                }
                newNode->pointerPrevNode = nodeIterator;
                newNode->pointerNextNode = nodeIterator->pointerNextNode;

                nodeIterator->pointerNextNode = newNode;
                newNode->pointerNextNode->pointerPrevNode = newNode;
                length++;
            }
        }
    }

    void removeFirst(){
        if(isEmpty()){
            cout << "The LinkedList is empty" <<endl;
        }
        else if(length == 1){
            delete head;
            head=tail=NULL;
        }
        else{
            Node* nodeIterator = head;
            head = head->pointerNextNode ;
            head->pointerPrevNode =NULL;
            delete nodeIterator;
        }
    length--;
    }

    void removeLast(){
        if(isEmpty()){
            cout << "The LinkedList is empty" <<endl;
        }
        else if(length == 1){
            delete head;
            head=tail=NULL;
        }
        else{
            Node* nodeIterator = tail;
            tail = tail->pointerPrevNode ;
            tail->pointerNextNode =NULL;
            delete nodeIterator;
        }
    length--;
    }

    void removeElement(int data ){
        if(length == 0){
            cout<< "this linkedList if empty" ;
        }
        else{

            Node* newNode = new Node ;
            newNode->data = data;
            if(head->data == data){
                removeFirst();
            }
            else if(tail->data == data){
                removeLast();
            }
            else{
                Node* nodeIterator = head->pointerNextNode ;
                while(nodeIterator != NULL){
                    if(nodeIterator->data == data){
                        break;
                    }
                    nodeIterator=nodeIterator->pointerNextNode;
                }
                if(nodeIterator == NULL){
                    cout << "This element doesn't exist";
                }
                else{
                    nodeIterator->pointerPrevNode->pointerNextNode = nodeIterator->pointerNextNode;
                    nodeIterator->pointerNextNode->pointerPrevNode = nodeIterator->pointerPrevNode;
                    delete nodeIterator;
                    length--;
                }

            }
        }
    }

     int searchElement(int data){
        Node* nodeIterator = head ;
        int index = 0 ;
        while( nodeIterator != NULL){
            if (nodeIterator->data == data ){
                return index ;
            }
            nodeIterator =nodeIterator->pointerNextNode;
            index++;
        }
        return -1;
     }
     void clearList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->pointerNextNode;
            delete temp;
        }
        tail = NULL;
        length = 0;
     }

     void print(){
        Node* NodesIterator = head;
        while(NodesIterator != NULL){
             cout<<NodesIterator->data << " " ;
             NodesIterator = NodesIterator->pointerNextNode;
        }
        cout<<endl;
     }
};

int main()
{
  DoublyLinkedList DLL;
  DLL.insertFirst(10);
  DLL.insertLast(20);
  DLL.insertLast(30);
  DLL.removeFirst();
  DLL.print();

  //DoublyLinkedList copiedDLL(DLL);
  //cout<< "Coppied DLL" ;
  //copiedDLL.print();

  //DLL.insertAtPosition( 1000 ,2);
  //DLL.print();

  //DLL.removeFirst();
  //DLL.print();

  //DLL.removeLast();
  //DLL.print();

 //DLL.removeElement(30);
  //DLL.print();

  int key = 0;
  int searchResult = DLL.searchElement(key);
  if(searchResult != -1){
    cout << "Element:  [ " << key << " ] " << "exist at index [ " << searchResult << " ]" <<endl;
  }else{
      cout << "This element doesnot exist";
  }

    return 0;
}
