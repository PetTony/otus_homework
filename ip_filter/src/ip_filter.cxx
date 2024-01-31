#include <cstdlib>
#include <algorithm>
#include "ip.h"

int main(void)
{
    std::istream& in = std::cin;

    auto ips = GetIps(in);

    std::sort(ips.rbegin(), ips.rend());

    for (const auto i : ips)
    {
        PrintIp(i);
    }

    for (const auto ip : ips)
    {
        if (Filter(1, 1, ip))
            PrintIp(ip);
    }

    for (const auto ip : ips)
    {
        if (Filter(1, 46, ip) && Filter(2, 70, ip))
            PrintIp(ip);
    }

    for (const auto ip : ips)
    {
        for (int i = 1; i <= 4; ++i)
        {
            if (Filter(i, 46, ip))
                PrintIp(ip);
        }
    }
}