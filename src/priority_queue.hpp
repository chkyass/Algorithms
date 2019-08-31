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


/*
    Invariant = parent is always greater (or smaller) than its children
    Heap = array seen as a binary tree
    parent = i/2, left = 2i, right = 2i+1
    Need <, >  and multiplication with 1 and -1 to be set
*/
template <class E>
class priority_queue {
private:
    std::vector<E> binary_heap_;
    size_t size_;
    char max_;
    void build_heap();
    void move_node(size_t);
    
public:
    priority_queue(char=1);
    priority_queue(std::vector<E>, char=1);
    E top() const;
    E pop();
    void add(E);
    void replace(E, E);
    bool isEmpty() const;
};

struct empty_heap : public std::exception
{
    const char * what() const throw()
    {
        return "queue is empty";
    }
};

/* 
    By default max heap = 1. Set max to -1 to make it min heap.
    max argument is used to compute the opposite of all the values in the heap
*/
template <class E> priority_queue<E>::priority_queue(std::vector<E> array, char max)
                                        :binary_heap_(array.begin(), array.end()), max_(max)
{
    if(max == -1)
    {
        for(size_t i = 0; i < binary_heap_.size(); i++)
        {
            binary_heap_[i] *= -1; 
        }
    }
    size_ = array.size();
    build_heap();
}

template <class E> priority_queue<E>::priority_queue(char max): max_(max)
{
    if(max == -1)
    {
        for(size_t i = 0; i < binary_heap_.size(); i++)
        {
            binary_heap_[i] *= -1; 
        }
    }
    size_ = 0;
}


/*  
    Start from size/2 because above all nodes are leaves
    Start from end bring down node until its children are smaller
    Doing this at each new call to move a node its two subtree respect
    the invariant
*/
template <class E> void priority_queue<E>::build_heap()
{  
    for(size_t i = size_/2; i <= size_/2; i--)
    {
        move_node(i);
    }
}

/*
    move down a node until its children are smaller
*/
template <class E> void priority_queue<E>::move_node(size_t i)
{
    size_t left = i*2;
    size_t right = i*2 + 1;
    size_t largest_index = i;
    
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
        return max_ * binary_heap_[0];
    
    throw empty_heap();
}

/*
    exchange the root and the last element of the tree
    heapify from the root (with move_node)
    remove the last element
*/
template <class E> E priority_queue<E>::pop()
{
    if (size_ == 0)
        throw empty_heap();
    
    E ret = binary_heap_[0];
    
    // swap the max and the last node
    std::swap(binary_heap_[0], binary_heap_[size_-1]);
    size_--;
    binary_heap_.erase(binary_heap_.begin() + size_);
    move_node(0);
    return max_ * ret;
}

/*
    add the node at the end of the tree
    exchange parent with new element until 
    it becomes a heap
*/
template <class E> void priority_queue<E>::add(E e)
{
    // add the element at the end
    binary_heap_.push_back(max_ * e);
    
    size_t new_index = size_;
    // index of the parent of the last element
    size_t parent_index = new_index/2;

    while(binary_heap_[parent_index] < binary_heap_[new_index])
    {
        std::swap(binary_heap_[parent_index], binary_heap_[new_index]);
        new_index = parent_index;
        parent_index = new_index/2;
    }

    size_++;
}

/*
    replace an element in the heap if it exists
    otherwise does nothing
*/
template <class E> void priority_queue<E>::replace(E old_n, E new_n)
{
    for(size_t i = 0; i < size_; i++)
    {
        if(binary_heap_[i] == old_n)
        {
            binary_heap_[i] = new_n;
            move_node(i);
        }
    }
}

template <class E> bool priority_queue<E>::isEmpty() const
{
    return size_ == 0;
}
#endif /* priority_queue_hpp */