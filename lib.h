#pragma once
#include <vector>
#include <iostream>
#include<string>
std::vector<int>strVectorToInt(std::vector<std::string> strItems);
bool sortIp(std::vector<std::vector<int>>& items);
bool filter(const std::vector<std::vector<int>>& items, int value);
bool filter(const std::vector<std::vector<int>>& items, int valueFirst, int valueSecond);
bool filter_any(const std::vector<std::vector<int>>& items, int value);