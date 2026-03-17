template <typename T>
LinkedListStack<T>::LinkedListStack()
{ }

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {

    Node<T>* curr = top;

    while (curr != nullptr) {
        Node<T>* temp = curr;
        curr = curr->next;
        delete temp;
    }

    top = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {

    if (copyObj.top == nullptr) {
        top = nullptr;
        this->length = 0;
        return;
    }

    Node<T>* src = copyObj.top;

    top = new Node<T>(src->data);
    Node<T>* dest = top;

    src = src->next;

    while (src != nullptr) {
        dest->next = new Node<T>(src->data);
        dest = dest->next;
        src = src->next;
    }

    this->length = copyObj.length;
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {

    if (isEmpty()) {
        throw runtime_error("Stack is empty");
    }

    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {

    if (isEmpty()) {
        throw runtime_error("Cannot pop from empty stack");
    }

    Node<T>* temp = top;
    top = top->next;

    delete temp;

    this->length--;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {

    Node<T>* newNode = new Node<T>(elem);
    newNode->next = top;

    top = newNode;

    this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {

    if (this->length <= 1)
        return;

    if (dir == Stack<T>::LEFT) {

        Node<T>* first = top;
        top = top->next;

        Node<T>* curr = top;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = first;
        first->next = nullptr;
    }
    else { // RIGHT rotation

        Node<T>* prev = nullptr;
        Node<T>* curr = top;

        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = nullptr;
        curr->next = top;
        top = curr;
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
