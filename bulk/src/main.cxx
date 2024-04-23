#include "bulk.h"
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Use: " << argv[0] << " with bulk size\n";
        return EXIT_FAILURE;
    }

    int bulk_size = std::atoi(argv[1]);
    if (bulk_size <= 0) {
        std::cerr << "Error: bulk size must be a natural number\n";
        return EXIT_FAILURE;
    }

    std::istream& in = std::cin;
    auto reader = Bulk(bulk_size);
    reader.Read(in);
    return 0;
}