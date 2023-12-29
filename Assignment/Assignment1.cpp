#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

typedef Node *NodePtr;

class CircularLinked
{
public:
    NodePtr head; 
    CircularLinked()
    {
        head = nullptr;
    }
    void insert(NodePtr &head, int insertData);
    void deletion(NodePtr &head, int deleteData);
    void display(NodePtr &head);
    int search(NodePtr &head, int target);

    void insertNew(int value)
    {
        NodePtr newNode = new Node;
        newNode->data = value;

        if (head == nullptr) // if the list is empty to begin with
        {
            newNode->next = newNode;
            head = newNode; // the new node is the only node
        }
        else
        {
            NodePtr temp = head; 
            while (temp->next != head) // while the node is not the last node
            {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
        }
    }
};
int main()
{
    CircularLinked linklist;
    linklist.insertNew(4);
    linklist.insertNew(5);
    linklist.insertNew(6);

    linklist.display(linklist.head);
    linklist.insert(linklist.head,5);
    int a = linklist.search(linklist.head, 5);
    cout << a;
}

void CircularLinked::insert(NodePtr &head, int insertData)
{
    NodePtr newNode = new Node;
    newNode->data = insertData;

    // if the list is empty (there is no node in the linked list)
    if (head == NULL)
    {
        newNode->next = newNode; // Make the new node point to itself
        head = newNode;          // Make the head point to the new node
    }

    else
    { // if the list is not empty, we start adding
        NodePtr temp = head;

        while (temp->next != head)
        { // while the pointer is not pointing to the last node
            temp = temp->next;
        }

        // once you are at the end of the list:
        temp->next = newNode;
        newNode->next = head;
    }
};

void CircularLinked::deletion(NodePtr &head, int deleteData){

};

void CircularLinked::display(NodePtr &head)
{
    // Implement a function to display the contents of the circular linked list in a clockwise direction.
    NodePtr temp = head;

    if (temp == nullptr)
    {
        cout << "Circular linked list is empty." << endl;
        return;
    }

    while (true)
    {
        cout << temp->data << " ";
        temp = temp->next;

        if (temp == head)
            break;
    }
};

int CircularLinked::search(NodePtr &head, int target) //search function
{
    NodePtr temp;
    temp = head;
    int counter = 0;

    if (temp == NULL)
    {
        return 0;
    }
    else
    {
        while (temp->data != target)
        {
            temp = temp->next;
            counter++;
            if (temp == head)
            {
                break;
            }
        };

        if (temp->data == target)
        {
            return counter;
        }

        else
        {
            return 0;
        }
    }
}

int Difference(TreeNode* T) const
{
    return Height(T->left) - Height(T->right);
}

int Height(TreeNode* T) const
{
    if (T == nullptr)
        return 0;
    else {
        int heightLeft = Height(T->left);
        int heightRight = Height(T->right);
        if (heightLeft > heightRight)
            return heightLeft + 1;
        else
            return heightRight + 1;
    }
}

if (current_node == NULL) {
    return false; // Node to be deleted doesn't exist
}

if (current_node->leftChild != NULL && current_node->rightChild != NULL) {
    // Successor is the smallest value in the right subtree
    // Find successor by pointing to right child
    BinarySearchTreeNode *successor = current_node->rightChild;
    bool isLeftChild = false; // At the first step, the successor is the right child of its parent - currently the right child of curr_node

    BinarySearchTreeNode *successor_parent = current_node;

    // Traverse to the leftmost node in the right subtree
    while (successor->leftChild != NULL) {
        successor_parent = successor; // move to the next
        successor = successor->leftChild; // moving down
        isLeftChild = true;
    }

    // Swap the key and value of the current node with the successor
    current_node->key = successor->key;
    current_node->value = successor->value;

    // Check if the successor is a leaf node or a branch node with only one child
    // If it is a leaf node
    if (successor->rightChild == NULL) {
        // If successor is a left child
        if (isLeftChild)
            successor_parent->leftChild = NULL; // Set the left child of the successor's parent to NULL
        else
            successor_parent->rightChild = NULL; // Set the right child of the successor's parent to NULL
    }
    else { // If it is a branch node with a right child
        // If successor is a left child
        if (isLeftChild) {
            successor_parent->leftChild = successor->rightChild; // Point the left child of the successor's parent to the successor's right child
            successor->rightChild->parent = successor_parent; // Update the parent of the successor's right child
        }
        else {
            successor_parent->rightChild = successor->rightChild; // Point the right child of the successor's parent to the successor's right child
            successor->rightChild->parent = successor_parent; // Update the parent of the successor's right child
        }
    }
    delete successor;
    return true;
}



