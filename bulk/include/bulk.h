#pragma once

#include <cstddef>
#include <vector>
#include <iostream>

class Bulk
{
public:
    Bulk(size_t N) : _n{N} {};
    void Read(std::istream& in);
private:
    void PrintBulk(std::ostream &ostream);
private:
    size_t _n {};
    int _open_scope {};
    std::string _timestamp{};
    std::vector<std::string> _buffer{};
};
