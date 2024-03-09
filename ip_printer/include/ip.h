#pragma once

#include <iostream>

/**
 * @brief Print ip
 *
 * @param ip Integer ip
 */

template <typename T,
    typename std::enable_if_t<std::is_integral_v<T>, bool> = true>
void PrintIp(T ip)
{
    uint8_t size = sizeof(ip);
    uint8_t max_pos = size * 8;
    for(int i = 1; i <= size; ++i)
    {
        std::cout << ((ip >> (max_pos - i * 8)) & 0xFF);
        if (i < size)
            std::cout << ".";
        else
            std::cout << "\n";
    }
    return;
}

/**
 * @brief Print ip
 *
 * @param ip String ip
 */
template <typename T,
    typename std::enable_if_t<std::is_same_v<T, std::string>, bool> = true>
void PrintIp(T ip)
{
    std::cout << ip << std::endl;
    return;
}

/**
 * @brief Print ip
 *
 * @param ip Vector or list ip
 */
template<typename T,
    typename std::enable_if_t<!std::is_same_v<typename T::value_type, char>, bool> = true>
void PrintIp(T ips)
{
    for (auto iter = ips.begin(); iter != ips.end(); iter++)
    {
        if (std::next(iter, 1) != ips.end())
            std::cout << *iter << ".";
        else
            std::cout << *iter;
    }
    if (!ips.empty())
        std::cout << "\n";
}
