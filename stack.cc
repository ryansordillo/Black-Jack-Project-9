#include "stack.h"

/**
 * Constructor for the node
* @param data data that we are storing in the node of type T
*/
template<typename T>
Node<T>::Node(T data) {
    _next = nullptr;
    _data = data;
}
/**
 * Constructor for the stack, initializes attributes
 */
template<typename T>
Stack<T>::Stack() {
    _top = nullptr;
    _size = 0;
}
/**
 *Puts items onto the stack, correctly assigns pointers and keeps track of size of stack
 * @param item thing we are trying to push onto stack of type T
 */
template<typename T>
void Stack<T>::push(T item) {
    Node<T> * node_ptr = new Node<T>(item);
    // change _top to point to node_ptr
    node_ptr->_next = _top;
    _top = node_ptr;
    _size++;
}
/**
 * returns what the is on the top of the stack
 * @return data of type T of node that is on top of stack
*/
template<typename T>
T Stack<T>::top() {
    return _top->_data;
}
/**
 * takes an item off the stack and returns the data of type T in the node
 * @return data from node that was taken off the stack
*/
template<typename T>
T Stack<T>::pop() {
    // Get data and a pointer to old top
    T to_return = _top->_data;
    Node<T> * old_top = _top;
    // Reassign top, then delete old top
    _top = _top->_next;
    delete old_top;
    _size--;
    return to_return;
}
/**
 * gets how many items are on the stack
 * @return size of stack
*/
template<typename T>
int Stack<T>::size() {
    return _size;
}
/**
 * Iterates through the stack and prints its contents in a aesthetic manner
*/
template<typename T>
void Stack<T>::display() {
    Node<T> * curr = _top;
    cout << "Stack[ ";
    while (curr != nullptr) {
        cout << "(" << curr->_data.get_suit() << ", " << curr->_data.get_rank() << ") ";
        curr = curr->_next;
    }
    cout << "]" << endl;
}
