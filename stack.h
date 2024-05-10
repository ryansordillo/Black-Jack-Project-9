#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

template<typename T>
class Node {
public:
    Node(T data);
    T _data;
    Node<T> * _next;
};
template<typename T>
class Stack {
public:
    Stack();
    void push(T item);
    T top();
    T pop();
    int size();
    void display();
private:
    Node<T> * _top;
    int _size;
};

#endif // STACK_H