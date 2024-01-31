#pragma once

#include <iostream>
#include <string>
#include <cstdint>
#include <vector>

uint32_t IpToInt (const std::string& ip);

std::vector<uint32_t> GetIps(std::istream& in);

bool Filter (const int position, const uint32_t value, const uint32_t ip);

void PrintIp (const uint32_t ip);