#include "ip.h"
#include <gtest/gtest.h>

const std::string correct_ip = "192.168.122.7";
const std::string incorrect_ip = "192.168.122.7";

TEST(IpToInt, basic_test) {
    ASSERT_TRUE(IpToInt("255.255.255.255") == 0xFFFFFFFF);
}

TEST(IpToInt, totally_invalid) {
    std::vector<std::string> incorrect_ip_set
    {
        "192.168.17.12.abracadabra",
        "192.168.17.12abracadabra",
        "192.168.17.abracadabra.12",
        "abracadabra192.168.17.12",
        "abracadabra.192.168.17.12abracadabra"
    };

    for (const auto &i : incorrect_ip_set)
    {
        ASSERT_FALSE(IpToInt(i));
    }

}

TEST(IpToInt, not_enough_bytes) {
    ASSERT_FALSE(IpToInt("1.2.3"));
}

TEST(IpToInt, too_much_bytes) {
    ASSERT_FALSE(IpToInt("1.2.3.4.5"));
}

TEST(IpToInt, byte_out_of_range) {
    ASSERT_FALSE(IpToInt("1.2.3.321"));
}

TEST(IpToInt, negative_numbers) {
    ASSERT_FALSE(IpToInt("1.2.3.-4"));
}

TEST(GetIps, basic_test) {
    std::istringstream is(  "1.2.3.4\t5.6.7.8\t9.10.11.12\n"
                            "13.14.15.16\t17.18.19.20\t21.22.23.24\n");
    std::vector<uint32_t> result = GetIps(is);
    ASSERT_TRUE(result.size() == 2);
}

