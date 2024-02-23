#include "lib.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> strVectorToInt(std::vector<std::string> strItems)
{
    std::vector<int> newItems;
    for(auto it = strItems.cbegin(); it != strItems.cend(); ++it)
    {
        newItems.push_back(std::stoi(*it));
    }
    return newItems;
}
bool sortIp(std::vector<std::vector<int>>& items)
{
    std::sort(items.begin(), items.end(), [](std::vector<int>firstEl, std::vector<int>SecondEl){
        auto firstS = firstEl.size();
        auto secondS = SecondEl.size();
        auto minS = firstS < secondS ? firstS : secondS;
        for(long unsigned int i = 0; i < minS; ++i)
        {
            if(firstEl.at(i) < SecondEl.at(i))
                return false;
            if(firstEl.at(i) > SecondEl.at(i))
                return true;
        }
        if(firstS <= secondS)
            return false;
        return true;
    });
    return true;
}
bool filter(const std::vector<std::vector<int>>& items, int value)
{
    for(auto it = items.cbegin(); it != items.cend(); ++it)
    {
        if(it->size() > 0 && it->at(0) == value)
        {
            for(auto ip_part = it->cbegin(); ip_part != it->cend(); ++ip_part)
            {
                if (ip_part != it->cbegin())
                {
                    std::cout << ".";

                }
                std::cout << *ip_part;
            }
            std::cout << std::endl;
        }
    }
    return true;
}
bool filter(const std::vector<std::vector<int>>& items, int valueFirst, int valueSecond)
{
    for(auto it = items.cbegin(); it != items.cend(); ++it)
    {
        if(it->size() > 1 && it->at(0) == valueFirst && it->at(1) == valueSecond)
        {
            for(auto ip_part = it->cbegin(); ip_part != it->cend(); ++ip_part)
            {
                if (ip_part != it->cbegin())
                {
                    std::cout << ".";

                }
                std::cout << *ip_part;
            }
            std::cout << std::endl;
        }
    }
    return true;
}
bool filter_any(const std::vector<std::vector<int>>& items, int value)
{
    for(auto it = items.cbegin(); it != items.cend(); ++it)
    {
        for(auto itIp = it->cbegin(); itIp != it->cend(); ++ itIp)
        {
            if(*itIp == value)
            {
                for(auto ip_part = it->cbegin(); ip_part != it->cend(); ++ip_part)
                {
                    if (ip_part != it->cbegin())
                    {
                        std::cout << ".";

                    }
                    std::cout << *ip_part;
                }
                std::cout << std::endl;
                break;
            }
        }
    }
    return true;
}

bool filterOneFunc(const std::vector<std::vector<int>>& items, std::map<int, int> positionValueMap, bool allValues)
{
    for(auto it = items.cbegin(); it != items.cend(); ++it)
    {
        bool printStr = true;
        bool oneValFound = false;
        for(auto itVal = positionValueMap.begin(); itVal != positionValueMap.end(); itVal++)
        {
            long unsigned int i = itVal->first;
            int val = itVal->second;

            if(i>=it->size())
            {
                if(allValues)
                {
                    printStr = false;
                    break;
                }
                continue;
            }

            if(it->at(i) == val)
            {
                oneValFound = true;
                if(!allValues)
                    break;
            }
            else if(allValues)
            {
                printStr = false;
                break;
            }
        }

        if(printStr && oneValFound)
        {
            for(auto ip_part = it->cbegin(); ip_part != it->cend(); ++ip_part)
                {
                    if (ip_part != it->cbegin())
                    {
                        std::cout << ".";

                    }
                    std::cout << *ip_part;
                }
                std::cout << std::endl;
        }

    }
    return true;
}