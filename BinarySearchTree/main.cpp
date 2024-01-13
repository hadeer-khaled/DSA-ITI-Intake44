#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
struct TreeNode {
    T info;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T value) : info(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree {
public:
    bool isEmpty();
    bool search(T);
    void insert(T);
    void remove(T);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    int treeHeight();
    int treeNodeCount();
    int treeLeavesCount();
    BinarySearchTree();
private:
    TreeNode<T>* root;
    void inorder(TreeNode<T>*);
    void preorder(TreeNode<T>*);
    void postorder(TreeNode<T>*);
    int height(TreeNode<T>*);
    int max(int x, int y);
    int nodeCount(TreeNode<T>*);
    int leavesCount(TreeNode<T>*);
    void deleteFromTree(TreeNode<T>*&);
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {}

template <typename T>
bool BinarySearchTree<T>::isEmpty() {
    return (root == nullptr);
}

template <typename T>
void BinarySearchTree<T>::inorderTraversal() {
    inorder(root);
}

template <typename T>
void BinarySearchTree<T>::preorderTraversal() {
    preorder(root);
}

template <typename T>
void BinarySearchTree<T>::postorderTraversal() {
    postorder(root);
}

template <typename T>
int BinarySearchTree<T>::treeHeight() {
    return height(root);
}

template <typename T>
int BinarySearchTree<T>::treeNodeCount() {
    return nodeCount(root);
}

template <typename T>
int BinarySearchTree<T>::treeLeavesCount() {
    return leavesCount(root);
}

template <typename T>
void BinarySearchTree<T>::inorder(TreeNode<T>* p) {
    if (p != nullptr) {
        inorder(p->left);
        cout << p->info << " ";
        inorder(p->right);
    }
}

template <typename T>
void BinarySearchTree<T>::preorder(TreeNode<T>* p) {
    if (p != nullptr) {
        cout << p->info << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

template <typename T>
void BinarySearchTree<T>::postorder(TreeNode<T>* p) {
    if (p != nullptr) {
        postorder(p->left);
        postorder(p->right);
        cout << p->info << " ";
    }
}

template <typename T>
int BinarySearchTree<T>::height(TreeNode<T>* p) {
    if (p == nullptr)
        return 0;
    else
        return 1 + max(height(p->left), height(p->right));
}

template <typename T>
int BinarySearchTree<T>::max(int x, int y) {
    if (x >= y)
        return x;
    else
        return y;
}

template <typename T>
int BinarySearchTree<T>::nodeCount(TreeNode<T>* p) {
    if (p == nullptr)
        return 0;
    else
        return 1 + nodeCount(p->left) + nodeCount(p->right);
}

template <typename T>
int BinarySearchTree<T>::leavesCount(TreeNode<T>* p) {
    if (p == nullptr)
        return 0;
    else if (p->left == nullptr && p->right == nullptr)
        return 1;
    else
        return leavesCount(p->left) + leavesCount(p->right);
}

template <typename T>
bool BinarySearchTree<T>::search(T item) {
    TreeNode<T>* current = root;

    while (current != nullptr) {
        if (current->info == item)
            return true;
        else if (current->info > item)
            current = current->left;
        else
            current = current->right;
    }

    return false;
}

template <typename T>
void BinarySearchTree<T>::insert(T item) {
    TreeNode<T>* current;
    TreeNode<T>* trailCurrent;
    TreeNode<T>* newNode;

    newNode = new TreeNode<T>(item);
    assert(newNode != nullptr);
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (root == nullptr)
        root = newNode;
    else {
        current = root;

        while (current != nullptr) {
            trailCurrent = current;

            if (current->info == item) {
                cout << "The insert item is already in the list -- ";
                cout << "duplicates are not allowed." << endl;
                return;
            } else if (current->info > item)
                current = current->left;
            else
                current = current->right;
        }

        if (trailCurrent->info > item)
            trailCurrent->left = newNode;
        else
            trailCurrent->right = newNode;
    }
}

template <typename T>
void BinarySearchTree<T>::remove(T item) {
    TreeNode<T>* current;
    TreeNode<T>* trailCurrent;

    if (root == nullptr) {
        cout << "Cannot delete from the empty tree." << endl;
        return;
    }
    if (root->info == item) {
        deleteFromTree(root);
        return;
    }

    trailCurrent = root;

    if (root->info > item)
        current = root->left;
    else
        current = root->right;

    while (current != nullptr) {
        if (current->info == item)
            break;
        else {
            trailCurrent = current;
            if (current->info > item)
                current = current->left;
            else
                current = current->right;
        }
    }

    if (current == nullptr)
        cout << "The delete item is not in the tree." << endl;
    else if (trailCurrent->info > item)
        deleteFromTree(trailCurrent->left);
    else
        deleteFromTree(trailCurrent->right);
}

template <typename T>
void BinarySearchTree<T>::deleteFromTree(TreeNode<T>*& p) {
    TreeNode<T>* current;
    TreeNode<T>* trailCurrent;
    TreeNode<T>* temp;

    if (p->left == nullptr && p->right == nullptr) {
        delete p;
        p = nullptr;
    } else if (p->left == nullptr) {
        temp = p;
        p = p->right;
        delete temp;
    } else if (p->right == nullptr) {
        temp = p;
        p = p->left;
        delete temp;
    } else {
        current = p->left;
        trailCurrent = nullptr;

        while (current->right != nullptr) {
            trailCurrent = current;
            current = current->right;
        }

        p->info = current->info;

        if (trailCurrent == nullptr)
            p->left = current->left;
        else
            trailCurrent->right = current->left;

        delete current;
    }
}

int main() {
    BinarySearchTree<int> b;
    b.insert(10);
    b.insert(20);
    b.insert(5);
    b.remove(10);
    b.inorderTraversal();
    b.postorderTraversal();
}
