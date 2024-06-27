#include <iostream>

//templated stack class
template <typename T>
class Stack {
    T* stack; //pointer to the array that will store the stack elements
    int top; // index of top element
    int size; // max size of the stack

public:
//constructor that takes the maximum size of the stack 
Stack(int size): size(size) {
    stack = new T[size]; //alocate memory for the stack
    top = -1; //initialize top to -1 (empty stack)   
}
/*
public - access specifier that makes the following members accessible  from outside
the class.
Stack(int size) : size(size) - this is the constructer for the stack class.
: size(size) is an initilizer list that initializes the member variable 'size' with
the value of the parameter 'size'.
stack = new T[size] - 'staack' is a pointer to an array of type T 
and new T[size] allocates memory for size elements of type T.
 */
//deconstructor to releaase the dtnamically allocated memory when th eobject is destroyed
~Stack(){
    delete[] stack;
}

void push(T item) {
    if (top == size - 1) { //check if stack is full
        throw std::out_of_range("Stack is full");
    }
    stack[++top] = item; // increment top and add the item to the stack
}

T pop() {
    if (isEmpty()) {
        throw std::out_of_range("stack is empty");
    }
    T item = stack[top]; // get the top item
    stack[top--] = T(); // reset the top element to a default value
    return item; // return the popped item 
}

T peek() {
    if (isEmpty()) {
        throw std::out_of_range("stack is empty");
    }
    return stack[top];
}

bool isEmpty() {
    return top == -1; //if top is -1, the stack is empty
}
};

//testing
int main() {
    Stack<int> myStack(10);
    myStack.push(5);

    std::cout << "stack implementation test\n" << myStack.peek() << std::endl;
    return 0;
}