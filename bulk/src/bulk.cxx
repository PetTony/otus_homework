#include "bulk.h"
#include <fstream>
#include <chrono>

void Bulk::PrintBulk(std::ostream &ostream)
{
    size_t buffer_size = _buffer.size();
    if (buffer_size == 0)
    {
        return;
    }

    ostream << "bulk: ";
    for (auto iter = _buffer.begin(); iter != _buffer.end(); iter++)
    {
        if (std::next(iter, 1) != _buffer.end())
            ostream << *iter << ", ";
        else
            ostream << *iter << "\n";
    }
}

void Bulk::Read(std::istream& in = std::cin)
{
    try
    {
        size_t cmd_counter = 0;
        auto PrintBuffer = [&]()
        {
            if (_open_scope)
            {
                return;
            }
            std::string filename = "bulk" + _timestamp + ".log";
            std::fstream fstream(filename, std::ios::out | std::ios::app);
            if (!fstream.is_open()) {
                std::cerr << "Error opening file: " << filename << std::endl;
                return;
            }
            else
            {
                PrintBulk(fstream);
            }
            PrintBulk(std::cout);
            _buffer = {};
            cmd_counter = {};
        };

        auto SetTimeStamp = [&]()
        {
            _timestamp = std::to_string(
                std::chrono::duration_cast<std::chrono::seconds>(
                    std::chrono::system_clock::now().time_since_epoch()).count());
        };

        for (std::string line; std::getline(in, line);)
        {
            if (line == "{")
            {
                if (_open_scope == 0)
                {
                    PrintBuffer();
                }
                _open_scope++;
                continue;
            }

            if (line == "}")
            {
                _open_scope--;
                if (_open_scope < 0)
                {
                    std::cerr << "Error: incorrect input data\n";
                    return;
                }

                if (_open_scope == 0)
                {
                    PrintBuffer();
                }
                continue;
            }

            if (_open_scope == 0 && cmd_counter < _n)
            {
                if (_buffer.size() == 0)
                {
                    SetTimeStamp();
                }

                _buffer.push_back(line);
                cmd_counter++;
            }

            if (_open_scope == 0 && cmd_counter == _n)
            {
                PrintBuffer();
                cmd_counter = 0;
            }

            if (_open_scope != 0)
            {
                if (_buffer.size() == 0)
                {
                    SetTimeStamp();
                }
                _buffer.push_back(line);
            }
        }

        PrintBuffer();
    }
    catch(const std::exception &e)
    {
        return;
    }
};
