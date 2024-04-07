#pragma once

#include <array>
#include <map>
#include <cassert>
#include <cstddef>

template<typename T, T Default, size_t Dimention>
class Matrix
{
public:
    using Key = std::array<size_t, Dimention>;
    using Map = std::map<Key, T>;
    class RowProxy
    {
    public:
        explicit RowProxy(Matrix* matrix) : _matrix(matrix) {}

        auto& operator[] (size_t idx)
        {
            assert(Dimention > _idx && "Out of dimention");
            _key[_idx] = idx;
            ++_idx;
            return *this;
        }

        T operator= (T value)
        {
            assert(Dimention == _idx && "Out of dimention");
            _matrix->set(_key, value);
            return value;
        }

        operator T() const
        {
            assert(_idx == Dimention && "Wrong dimention");
            return _matrix->get(_key);
        }

        bool operator==(const T& value) const
        {
            return _matrix->get(_key) == value;
        }
    private:
        Key _key;
        Matrix* _matrix;
        size_t _idx = 0;
    };

    auto operator[](size_t idx)
    {
        RowProxy row_proxy(this);
        return row_proxy[idx];
    }

    const T& get(const Key &key)
    {
        auto iter = _map.find(key);

        if(iter == _map.end())
        {
            return _default_value;
        }

        return iter->second;
    }

    void set(const Key &key, T value)
    {
        auto iter = _map.find(key);
        if(iter == _map.end())
        {
            if(value != _default_value)
                _map.emplace(key, value);
            return;
        }

        if(value == _default_value)
        {
            _map.erase(iter);
            return;
        }

        iter->second = value;
    }

    size_t size()
    {
        return _map.size();
    }

    auto begin()
    {
        return _map.begin();
    }

    auto end()
    {
        return _map.end();
    }

private:
    const T _default_value = Default;
    Map _map;
};
