#include <cassert>
#include <cstdlib>
#include "ip.h"

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

uint32_t IpToInt (const std::string& ip)
{
    uint32_t int_ip = 0;
    std::vector<int> ip_record;
    std::vector<std::string> ip_struct;

    for (const auto& i : split(ip, '.'))
    {
        int ip_part = 0;
        try {
            ip_part = std::stoi(i);
            auto control = std::to_string(ip_part);
            if (i != control)
                break;
        }
        catch (const std::invalid_argument& ia) {
            return 0;
        }
        if (ip_part >= 0 && ip_part < 256)
        {
            ip_record.push_back(ip_part);
        }
        else
            return 0;
    }
    if (ip_record.size() == 4)
    {
        for (int i = 0; i < 4; ++i)
        {
            int_ip |= (ip_record.at(i) << (32 - ((i+1) * 8)));
        }
    }
    return int_ip;
};

bool Filter (const int position, const uint32_t value, const uint32_t ip)
{
    bool is_position_correct = position > 0 && position <= 4;
    bool is_value_correct = value > 0 && value <= 255;
    bool is_condition_true = ((ip >> (32 - position * 8)) & 0xFF) == value;

    return is_position_correct && is_value_correct && is_condition_true;
};

void PrintIp (const uint32_t ip)
{
    for (int i = 1; i <= 4; ++i)
    {
        std::cout << ((ip >> (32 - i * 8)) & 0xFF);
        if (i < 4)
            std::cout << ".";
        else
            std::cout << "\n";
    }
};

std::vector<uint32_t> GetIps (std::istream& in = std::cin)
{
    std::vector<uint32_t> ips{};
    try
    {
        for (std::string line; std::getline(in, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            uint32_t int_ip = IpToInt(v.at(0));
            if (int_ip)
                ips.push_back(int_ip);
        }
    }
    catch(const std::exception &e)
    {
        return ips;
    }
    return ips;
}
