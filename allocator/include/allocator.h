#pragma once

#include <functional>

template <class T, size_t size>
struct MyAllocator
{
    typedef T value_type;

    int _pos{};
    const size_t _size{};
    T* _data = nullptr;

    MyAllocator() : _size{size}
    {
        _data = reinterpret_cast<T*>(std::malloc(size * sizeof(T)));
    }
    ~MyAllocator()
    {
        std::free(_data);
    }

    MyAllocator(const MyAllocator<T, size> &) = delete;
    MyAllocator(MyAllocator<T, size> &&) = delete;

    T* allocate (std::size_t n)
    {
        if (_pos + n > _size)
        {
            throw std::bad_alloc();
        }

        int cur = _pos;
        _pos += n;
        return reinterpret_cast<T*>(_data) + cur;
    }

    void deallocate ([[maybe_unused]] T* p, [[maybe_unused]] std::size_t n) {}

    template <typename U, typename... Args>
    void construct(U* p, Args&&... args)
    {
        new (p) U(std::forward<Args>(args)...);
    }

    template <typename U>
    void destroy(U *p)
    {
        p->~U();
    }

    template<class U>
    struct rebind
    {
        typedef MyAllocator<U, size> other;
    };
};

template<class T, class U, size_t size>
constexpr bool operator==(const MyAllocator<T, size>& a1, const MyAllocator<U, size>& a2) noexcept
{
    return true;
};

template<class T, class U, size_t size>
constexpr bool operator!=(const MyAllocator<T, size>& a1, const MyAllocator<U, size>& a2)
{
    return false;
};
