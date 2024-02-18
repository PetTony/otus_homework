#pragma once

#include <functional>

template <class T, size_t size>
struct MyAllocator
{
    typedef T value_type;

    static int _pos;
    const size_t _size;
    T* _data = nullptr;

    MyAllocator() : _size{size}
    {
        _data = reinterpret_cast<T*>(std::malloc(size * sizeof(T)));
    }
    ~MyAllocator()
    {
        delete[] _data;
    }

    template<class U> MyAllocator(const MyAllocator<U, size> &) = delete;
    template<class U> MyAllocator(MyAllocator<U, size> &&) = delete;

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

    template<class U>
    struct rebind
    {
        typedef MyAllocator<U, size> other;
    };
};

template <typename T, size_t size>
int MyAllocator<T, size>::_pos = 0;

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
