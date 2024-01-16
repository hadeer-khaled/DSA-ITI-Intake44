#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;
    Node()
    {
        left = NULL;
        right = NULL;
    }
    Node(T value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
}; // end of Node struct
template <typename T>
class BinarySearchTree {

private:

    void deleteFromTree(Node<T>*& p) {
        Node<T>* current;
        Node<T>* parentCurrent;
        Node<T>* temp;

        if (p->left == NULL && p->right == NULL) {
            delete p;
            p = NULL;
        } else if (p->left == NULL) {
            temp = p;
            p = p->right;
            delete temp;
        } else if (p->right == NULL) {
            temp = p;
            p = p->left;
            delete temp;
        } else {
            current = p->left;
            parentCurrent = NULL;

            while (current->right != NULL) {
                parentCurrent = current;
                current = current->right;
            }

            p->data = current->data;

            if (parentCurrent == NULL)
                p->left = current->left;
            else
                parentCurrent->right = current->left;

            delete current;
        }
    }

    void inorderPrivate(Node<T>* node){
         if (node != NULL)
        {
            inorderPrivate(node->left);
            cout << node->data << " ";
            inorderPrivate(node->right);
        }
    }
    void preorderPrivate(Node<T>* node){
         if (node != NULL) {
            cout << node->data << " ";
            preorderPrivate(node->left);
            preorderPrivate(node->right);
        }
    }
    void postorderPrivate(Node<T>* node){
        if (node != NULL) {
            postorderPrivate(node->left);
            postorderPrivate(node->right);
            cout << node->data << " ";
        }

    }

    Node<T>* getParentPrivate(Node<T>* root, T data) {
        Node<T>* parent = NULL;
        Node<T>* current = root;

        while (current != NULL && current->data != data) {
            parent = current;

            if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return (current != NULL) ? parent : NULL;
    }
public:
    Node<T>* root;

    BinarySearchTree(){ root = NULL;  }

    bool isEmpty() { return (root == NULL);}

    void Insert(T data) {
        Node<T>* current;
        Node<T>* ParentCurrent;
        Node<T>* newNode;

        newNode = new Node<T>(data);
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (root == NULL)
            root = newNode;
        else {
            current = root;

            while (current != NULL) {
                ParentCurrent = current;

                if (current->data == data) {
                    cout << "The inserted data is already in the Tree -- " << endl;
                    return;
                } else if (current->data > data)
                    current = current->left;
                else
                    current = current->right;
            }

            if (ParentCurrent->data > data)
                ParentCurrent->left = newNode;
            else
                ParentCurrent->right = newNode;
        }
    }

    void Delete(T item) {
        Node<T>* current;
        Node<T>* parentCurrent;

        if (root == NULL) {
            cout << "The tree is already empty." << endl;
            return;
        }
        if (root->data == item) {
            deleteFromTree(root);
            return;
        }

        parentCurrent = root;

        if (root->data > item)
            current = root->left;
        else
            current = root->right;

        while (current != NULL) {
            if (current->data == item)
                break;
            else {
                parentCurrent = current;
                if (current->data > item)
                    current = current->left;
                else
                    current = current->right;
            }
        }

        if (current == NULL)
            cout << "The data is not in the tree." << endl;
        else if (parentCurrent->data > item)
            deleteFromTree(parentCurrent->left);
        else
            deleteFromTree(parentCurrent->right);
    }

    bool Search(T data) {
        Node<T>* current = root;

        while (current != NULL) {
            if (current->data == data)
                return true;
            else if (current->data > data)
                current = current->left;
            else
                current = current->right;
        }
        return false;
    }

    void InOrder() { inorderPrivate(root); }
    void PreOrder() { preorderPrivate(root); }
    void PostOrder() { postorderPrivate(root); }

    int Count(Node<T>* node) {
        if (node == NULL)
            return 0;
        else
            return 1 + Count(node->left) + Count(node->right);
    }

    Node<T>* getParent(T data){getParentPrivate( root, data); }
}; // end of tree class
int main()
{
BinarySearchTree<int> t;
    t.Insert(50);
    t.Insert(60);
    t.Insert(30);
    t.Insert(25);
    t.Insert(40);
    t.Insert(35);
    t.Insert(70);
    t.Insert(65);
    ////////////////////////////////////////////////////////////////
    t.Insert(11);
    t.Insert(27);
    t.Insert(26);
    t.Insert(29);
    t.Insert(45);

    t.InOrder();

    cout << endl;
    cout << "****************" << endl;
    Node<int> *Node = t.getParent(65);
    cout << "Parent of 65 = " << Node->data << endl;

    cout << "****************" << endl;
    t.Delete(30);
    t.InOrder();
    cout << endl;

    cout << "****************" << endl;
    cout << t.Count(t.root) << endl;
    system("pause");
    return 0;

}
