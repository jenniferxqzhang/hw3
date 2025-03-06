#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    
    // Add other members only if necessary
    private:
        std::vector<T> vals;
};

template <typename T>
Stack<T>::Stack(){}

template <typename T>
Stack<T>::~Stack(){}

// checks if the stack is empty
template <typename T>
bool Stack<T>::empty() const{
    // vector supports .empty() function already
    return vals.empty();
}

template <typename T>
size_t Stack<T>::size() const {
    // vector supports .size() function already
    return vals.size();
}

template <typename T>
void Stack<T>::push(const T& item){
    // vector supports .push_back() which follows stack's LIFO 
    vals.push_back(item);
}

template <typename T>
void Stack<T>::pop(){
    // throw error if it is empty
    if(vals.empty()){
        throw std::underflow_error("Heap is empty");
    }
    vals.pop_back();
}

template <typename T>
const T& Stack<T>::top() const{
    // throw error if it is empty
    if(vals.empty()){
        throw std::underflow_error("Heap is empty");
    }
    return vals.back();
}

#endif