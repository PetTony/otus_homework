#include <cstdint>
#include <string>
#include <vector>
#include <list>
#include "ip.h"

int main(void)
{
    PrintIp( int8_t{-1} ); // 255
    PrintIp( int16_t{0} ); // 0.0
    PrintIp( int32_t{2130706433} ); // 127.0.0.1
    PrintIp( int64_t{8875824491850138409} );// 123.45.67.89.101.112.131.41
    PrintIp( std::string{"Hello, World!"} ); // Hello, World!
    PrintIp( std::vector<int>{100, 200, 300, 400} ); // 100.200.300.400
    PrintIp( std::list<short>{} ); // 400.300.200.100
    PrintIp( std::list<short>{400, 300, 200, 100} ); // 400.300.200.100
    PrintIp( std::list<short>{} ); // 400.300.200.100
    return 0;
}