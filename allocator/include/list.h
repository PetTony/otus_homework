#pragma once

#include <functional>

template<typename T, typename Allocator = std::allocator<T>>
struct MyList
{
    struct Node
    {
        T _val;
        Node* _next;
        Node (T val, Node* next) : _val(val), _next(next) {}
    };

    Node* _first = nullptr;
    Node* _last = nullptr;

    MyList() {}
    ~MyList()
    {
        while(_first)
        {
            Node* node = _first;
            _first = _first->_next;
            _allocator.destroy(node);
        }
    }
    void push_back(T val)
    {
        Node *node = _allocator.allocate(1);
        _allocator.construct(node, val, nullptr);
        if (!_first)
        {
            _first = node;
            _last = node;
            return;
        }
        _last->_next = node;
        _last = node;
    }
private:
    using NodeAllocator = typename Allocator::template rebind<Node>::other;
    NodeAllocator _allocator;
};
