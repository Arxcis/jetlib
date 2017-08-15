// @file convert.h
// @date 26.05.17
// @creator Jonas Solsvik
// @brief Converters
#pragma once

#include <iostream>
#include <string>
#include <unordered_map>



namespace jet { namespace Convert {

    std::unordered_map<uint, char> hexmap = {
        {0x0, '0'},
        {0x1, '1'},
        {0x2, '2'},
        {0x3, '3'},
        {0x4, '4'},
        {0x5, '5'},
        {0x6, '6'},
        {0x7, '7'},
        {0x8, '8'},
        {0x9, '9'},
        {0xA, 'A'},
        {0xB, 'B'},
        {0xC, 'C'},
        {0xD, 'D'},
        {0xE, 'E'},
        {0xF, 'F'}
    };
    //
    // @function bin()
    //
    inline std::string bin(uint num)
    {
        std::string outstring{};

        while(num) {
            uint leastSignificantBit = num & 1;
            outstring = std::to_string(leastSignificantBit) + outstring;
            num = num >> 1;
        }
        outstring = "0b" + outstring;
        return outstring;
    }

    //
    // function hex()
    //
    inline std::string hex(uint num)
    {
        std::string outstring{};
        while(num) {

            uint leastSignificantHex = num & 0xf;
            outstring = hexmap[leastSignificantHex] + outstring;
            num = num >> 4;
        }
        outstring = "0x" + outstring;
        return outstring;
    }
}}
