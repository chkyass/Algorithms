//
//  priority_queue.hpp
//  Algorithms
//
//  Created by rand0m on 23/08/2019.
//  Copyright © 2019 rand0m. All rights reserved.
//

#ifndef priority_queue_h
#define priority_queue_h

#include <vector>
#include <exception>
#include <iostream>

template <class E>
class priority_queue {
private:
    std::vector<E> binary_heap_;
    size_t size_ = 0;
    void build_heap();
    void move_node(size_t);
    
public:
    priority_queue(){};
    priority_queue(std::vector<E>);
    E top() const;
    E pop();
    void add(E);
    bool isEmpty() const;
};

struct empty_heap : public std::exception
{
    const char * what() const throw()
    {
        return "queue is empty";
    }
};

template <class E> priority_queue<E>::priority_queue(std::vector<E> array):binary_heap_(array.begin(), array.end())
{
    size_ = array.size();
    build_heap();
}

template <class E> void priority_queue<E>::build_heap()
{   
    //std::cout << size_ << std::endl;
    //std::cout << size_/2 << std::endl;

    // start from size/2 because above all nodes are leaves
    for(size_t i = size_/2; i <= size_/2; i--)
    {
        move_node(i);
    }
}

template <class E> void priority_queue<E>::move_node(size_t i)
{
    size_t left = i*2;
    size_t right = i*2 + 1;
    size_t largest_index = i;

    //std::cout << "i : "<< i << " left : "<< left << ", right : " << right << std::endl;
    
    if(left < size_ && binary_heap_[left] > binary_heap_[i])
        largest_index = left;
    if(right < size_ && binary_heap_[right] > binary_heap_[largest_index])
        largest_index = right;
    
    if(largest_index != i)
    {
        std::swap(binary_heap_[i], binary_heap_[largest_index]);
        move_node(largest_index);
    }
}

template <class E> E priority_queue<E>::top() const
{
    if (size_ > 0)
        return binary_heap_[0];
    
    throw empty_heap();
}

template <class E> E priority_queue<E>::pop()
{
    /*if (size_ == 0)
        throw empty_heap();*/
    
    E ret = binary_heap_[0];
    
    // swap the max and the last node
    std::swap(binary_heap_[0], binary_heap_[size_-1]);
    size_--;
    binary_heap_.erase(binary_heap_.begin() + size_);
    move_node(0);
    return ret;
}

template <class E> void priority_queue<E>::add(E e)
{
    // add the element at the end
    binary_heap_.push_back(e);
    size_++;
    
    size_t new_index = size_- 1;
    // index of the parent of the last element
    size_t parent_index = new_index/2;

    while(binary_heap_[parent_index] < binary_heap_[new_index])
    {
        std::swap(binary_heap_[parent_index], binary_heap_[new_index]);
        new_index = parent_index;
        parent_index = new_index/2;
    }
}

template <class E> bool priority_queue<E>::isEmpty() const
{
    return size_ == 0;
}
#endif /* priority_queue_hpp */