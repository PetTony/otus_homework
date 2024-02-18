#include "list.h"
#include "allocator.h"
#include <map>
#include <iostream>

template<typename T>
T Factorial(T n)
{
    if(n > 1)
        return n * Factorial(n-1);
    return 1;
}

int main(void)
{
    auto PrintMap = [](auto &map)
    {
        for (const auto &[key, value] : map)
            std::cout << key << " " << value << std::endl;
    };

    std::map<int, int> map_std_alloc;
    std::map<int, int, std::less<int>, MyAllocator<std::pair<const int, int>, 10>> map_own_alloc;

    for (int i = 0; i < 10; ++i)
    {
        map_std_alloc.emplace(i, Factorial(i));
        map_own_alloc.emplace(i, Factorial(i));
    }

    PrintMap(map_own_alloc);

    MyList<int> list_std_alloc;
    MyList<int, MyAllocator<int, 10>> list_own_alloc;

    for (int i = 0; i < 10; ++i)
    {
        list_own_alloc.push_back(i);
        list_std_alloc.push_back(i);
    }

    for (auto &i = list_own_alloc._first; i != nullptr; i = i->_next)
    {
        std::cout << i->_val << std::endl;
    }

    return 0;
}