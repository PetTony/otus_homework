#pragma once

#include <functional>

template<typename T>
struct Node
{
    T _val;
    Node* _next;
    Node (T val) : _val(val), _next(nullptr) {}
};

template<typename T, typename Allocator = std::allocator<T>>
struct MyList
{
    Node<T> *_first = nullptr;
    Node<T> *_last = nullptr;
    MyList() {}
    ~MyList() {}
    void push_back(T val)
    {
        Node<T> *p = _allocator.allocate(1);
        p->_val = val;
        p->_next = nullptr;
        if (_first == nullptr)
        {
            _first = p;
            _last = p;
            return;
        }
        _last->_next = p;
        _last = p;
    }
private:
    using NodeAllocator = typename Allocator::template rebind<Node<T>>::other;
    NodeAllocator _allocator;
};