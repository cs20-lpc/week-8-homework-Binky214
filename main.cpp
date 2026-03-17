#include <iostream>
#include "StackFactory.hpp"

using namespace std;

template<typename T>
void testStack(Stack<T>* stack)
{
    cout << "Push to stack" << endl;

    stack->push(10);
    stack->push(20);
    stack->push(30);

    stack->print();

    cout << "Peek: " << stack->peek() << endl;

    cout << "Pop one element" << endl;
    stack->pop();

    stack->print();

    cout << "Rotate LEFT" << endl;
    stack->rotate(Stack<T>::LEFT);
    stack->print();

    cout << "Rotate RIGHT" << endl;
    stack->rotate(Stack<T>::RIGHT);
    stack->print();

    cout << "Clearing stack" << endl;

    while (!stack->isEmpty())
        stack->pop();

    stack->print();
}

int main()
{
    cout << "Testing ArrayStack" << endl;
    Stack<int>* arrayStack = StackFactory<int>::GetStack(10);
    testStack(arrayStack);

    cout << endl;

    cout << "Testing LinkedListStack" << endl;
    Stack<int>* listStack = StackFactory<int>::GetStack();
    testStack(listStack);

    delete arrayStack;
    delete listStack;

    cout << endl;

    cout << "Testing with strings" << endl;

    Stack<string>* stringStack = StackFactory<string>::GetStack();

    stringStack->push("Alice");
    stringStack->push("Bob");
    stringStack->push("Charlie");

    stringStack->print();

    cout << "Peek: " << stringStack->peek() << endl;

    stringStack->rotate(Stack<string>::LEFT);
    stringStack->print();

    delete stringStack;

    return 0;
}