#include <iostream>

template <typename T>
class Stack {
    // define a private struct Node to represent elements in the stack
    struct Node {
        T data; // data of the node
        Node* next; // pointer to the next node in the stack
    };
    Node* top; // pointer to the top node of the stack

public:
    // constructor: initialize the top pointer to nullptr , indicating an empty stack
    Stack(): top(nullptr) {}

    // deconstructor: frees memory by deleting all nodes in the stck
    ~Stack() {
        while (top) {
            Node* oldTop = top;
            top = top-> next;
            delete oldTop;
        }
    }

void push(T item){
    //create a new node
    Node* newNode = new Node;
    newNode-> data = item;
    //set the next pointer of the new node to point to the previous top node
    newNode->next = top; /*sets the next pointer of the new node to the current top node
    links the new node to the previous top of the stack, maintaining the 
    linked list structure*/
    
    //update the top pointer to point to the new node
    top = newNode;
}

T pop() {
    if (!top) {
        // if the stack is empty, throw an exception
        throw std::out_of_range("stck is empty");
    }
    T item = top->data; //get the data of the top node and store in variable item
    Node* oldTop = top; // save a pointer to the current top node in the variable oldTop
    top = top-> next; //update the top pointer to point to the next node in the stack
    // effectively removing the current top node from the stack
    delete oldTop; // delete the old top node to free memory
    return item;
}

T peek() {
    if (!top) {
        throw std::out_of_range("stack is empty");
    }
    return top->data;
}

bool isEmpty() {
    return top == nullptr;
}

};


//testing
int main(){
    Stack<int> MyStack;
    MyStack.push(5);
    MyStack.push(2);
    MyStack.push(3);

    std::cout << "top element is: " << MyStack.peek() << std::endl;

    std::cout << "popped element is: " << MyStack.pop() << std::endl;
    return 0;
}