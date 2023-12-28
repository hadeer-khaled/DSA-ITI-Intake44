#include <iostream>

using namespace std;

class SinglyLinkedList{
    struct Node{
        int data ;
        Node* pointerToNextNode ;
    };
    Node* head ;
    Node* tail;
    int length;

public:
    // constructor
     SinglyLinkedList(){
        head=tail=NULL;
        length = 0 ;
     }

     bool isEmpty(){
        return length == 0 ;// OR head ==Null
     }

     void insertFirst(int nodeData){
         // Create node
        Node* newNode = new Node ;
        (*newNode).data = nodeData; // OR newNode->data

        if(isEmpty()){
            head=tail=newNode;
            newNode->pointerToNextNode = NULL ;
            // Why = NULL ? COZ the ll was empty So this node is the only node in LL
        }
        else{
            newNode->pointerToNextNode = head;
            head = newNode;
        }
        length++;
     }

     void insertLast(int nodeData){
        // Create node
        Node* newNode = new Node ;
        (*newNode).data = nodeData; // OR newNode->data
        if(isEmpty()){
            head=tail=newNode;
            newNode->pointerToNextNode = NULL ;
            // Why = NULL ? COZ the ll was empty So this node is the only node in LL
        }else{
             tail->pointerToNextNode= newNode ;
             newNode->pointerToNextNode = NULL;
             tail  = newNode ;
        }
           length++;
     }

     void insertAtPosition(int nodeData , int position){
         //create node
        Node* newNode = new Node ;
        newNode->data = nodeData ;

        //check if the position at the begining --> call insertFirst function
        if(position == 0){
             insertFirst(nodeData);
        }
        else if(position == length){
            insertLast(nodeData);
        }
        else{
            Node* NodesIterator = head;
            for(int i=1  ; i<=position-1 ; i++){
                NodesIterator = NodesIterator->pointerToNextNode;
            }
            newNode->pointerToNextNode=NodesIterator->pointerToNextNode;
            NodesIterator->pointerToNextNode=newNode;
            length++;
        }
     }

     void removeFirst(){
        if(isEmpty()){
            cout << "The LinkedList is empty" <<endl;
        }else if (length == 1){
            delete head ;
            delete tail ;
            head = tail = NULL;
        }
        else{
            Node* tempNode = head ;
            head = head->pointerToNextNode;
            delete tempNode;
            length--;
        }
     }

     void removeLast(){
        if(isEmpty()){
            cout << "The LinkedList is empty" <<endl;
        }else if (length == 1){
            delete head ;
            delete tail ;
            head = tail = NULL;
        }
        else{
            Node* currentNodeIterator = head->pointerToNextNode;
            Node* previousNodeIterator = head;
            while(currentNodeIterator != tail){
                previousNodeIterator = currentNodeIterator;
                currentNodeIterator  = currentNodeIterator->pointerToNextNode;
            }
            delete currentNodeIterator;
            previousNodeIterator->pointerToNextNode = NULL;
            tail = previousNodeIterator;
            length--;
        }
     }

     void removeElement(int element){
         if(isEmpty()){
            return;
         }
         if(element == head->data){
            removeFirst();
         }
        Node* currentNodeIterator = head->pointerToNextNode;
        Node* previousNodeIterator = head;

        while (currentNodeIterator != NULL){
            if(currentNodeIterator->data == element ){
                break;
            }

            else{
                 previousNodeIterator =currentNodeIterator ;
                 currentNodeIterator = currentNodeIterator->pointerToNextNode;
            }
        }
        if (currentNodeIterator == NULL) {
            cout << "This element doesn't exist" << endl ;
        }
        else{
            previousNodeIterator->pointerToNextNode = currentNodeIterator->pointerToNextNode ;
            if(currentNodeIterator == tail){
                tail = previousNodeIterator;
            }
            delete currentNodeIterator ;
            length --;
        }
     }

     int findElement(int element){
     Node* nodeIterator = head;
     int position ;
     while( nodeIterator != NULL){
        if(nodeIterator->data == element ){
            return position;
        }
        nodeIterator = nodeIterator->pointerToNextNode ;
        position++;
     }
     return -1;
     }

     void print(){
        Node* NodesIterator = head;
        while(NodesIterator != NULL){
             cout<<NodesIterator->data << " " ;
             NodesIterator = NodesIterator->pointerToNextNode;
        }
        cout<<endl;
     }
};

int main()
{
    SinglyLinkedList SLL;
    SLL.insertFirst(10);
    SLL.insertLast(20);
    SLL.insertLast(30);
    SLL.insertLast(40);
    SLL.insertLast(50);
    SLL.insertLast(60);
    SLL.insertAtPosition(10000 , 2);
    SLL.print() ;
   cout <<  "Position of elemnt: 40 ===> " << SLL.findElement(50) <<endl;

    return 0;
}
