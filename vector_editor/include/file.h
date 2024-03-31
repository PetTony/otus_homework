#pragma once

#include <iostream>
#include <filesystem>

using buffer = std::vector<char>;

class File
{
public:
    File() = default;
    ~File()
    {
        Close();
    }

    void Open(const std::filesystem::path &path)
    {
        if(_is_open)
        {
            Close();
        }
        std::cout << "Open file: " << path << std::endl;
        _is_open = true;
        _file = path;
    }

    void Close()
    {
        if(_is_open)
        {
            std::cout << "Close file: " << _file << std::endl;
            _is_open = false;
        }
    }

    void Write(const buffer &data[[maybe_unused]])
    {
        if(_is_open)
        {
            std::cout << "Write to file: " << _file << std::endl;
        }
    }

    buffer Read()
    {
        buffer data{};
        if(_is_open)
        {
            std::cout << "Read file: " << _file << std::endl;
        }
        return data;
    }

private:
    std::filesystem::path _file{};
    bool _is_open{};
};
