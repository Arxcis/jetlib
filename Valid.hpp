//
// @date 10.08.17
// @creator Jonas J. Solsvik
// @brief Regex validate string types
//

#pragma once
#include <regex>

// @urldoc - tool for creating/validating regex - www.rubular.com

namespace jet { namespace Valid {

    //
    // @brief - regexName validates if only characters
    //
    constexpr std::regex regexName(R"([#[:alpha:] \.]+)");
    
    inline bool isName(const char* value)
    { 
        return std::regex_match(value, regName);
    }

    //
    // @brief - regexChar3 validates to true if:
    //      1. 3 letter word
    //      2. All uppercase
    //      3. A-Z
    //
    constexpr std::regex regexChar3(R"([A-Z]{3})");

    inline bool isChar3(const char* value)
    {
        return std::regex_match(value, regChar3);
    }

    //
    // @brief - regexInt validates to true if:
    //      1. A string consisting only of numeric-characters 0-9
    //
    constexpr std::regex regexInt(R"(([-]?)([0-9])+)");
    
    inline bool isInt(const char* value)
    {
        return std::regex_match(value, regInt);
    }


    // @brief - regexDouble validates to true if:
    //     1. 0-15 numberic characters,
    //     2. followed by a period, 
    //     3. followd by 1-15 numeric characters.
    // @robustness - could overflow floating point, @broken per 06.04.17
    //
    constexpr std::regex regexDouble(R"(([\s]*)
                                     ([+-]?)
                                     ([0-9]{0,15})
                                     ([\.]?)([0-9]{1,15}))");

    inline bool isDouble(const char* value)
    {
        return std::regex_match(value, regDouble);
    }
    
    //
    // @brief - regexEmail validates to true if:
    //     1. Minimum of 3 aplha-numeric character or _, -, . jonas.solsvik
    //     2. Mandatory @
    //     3. Minimum of 3 aplha-numeric character or .   ex. stud.ntnu
    //     4. Mandatory . 
    //     5. Betwenn 2-6 lowercase alpha-letters.    ex. com or no
    // @robustness - pseudo email address.
    //
    constexpr std::regex regexEmail(R"((([\d[:alpha:]_\.])*)
                                    ([@])
                                    ([\d[:alpha:]_\.])*)");  
        
    inline bool isEmail(const char* value)
    {
        return std::regex_match(value, regEmail);
    }


    //
    // @brief - regexPhone validates to true if:
    //     1. Mandatory + at beginning
    //     2. 1,2 or 3 numbers
    //     3. Mandatory space
    //     4. 8 numerics in one of these patterns xxx xx xxx, or xx xx xx xx or xxxxxxxx
    //
    constexpr std::regex regexPhone(R"(([+][0-9]{1,3}[ ])?
                                    ([0-9]{7,12}))");

    inline bool isPhone(const char* value)
    {
        return std::regex_match(value, regPhone);
    }

    //
    // @brief - regexTime @todo write something here about how the time 
    //           we are trying to match looks like. - JSolsvik 15.08.17
    // @robustness, demands 00:00:00:999 for milliseconds
    //
    constexpr std::regex regexTime(R"(([\s]*)
                                   (([0-1][0-9])|([2][0-4]))
                                   ([:])
                                   ([0-5][0-9])
                                   (([:]([0-5][0-9]))?)
                                   (([:]([0-9]{3}))?))"); 

    inline bool isTime(const char* value)
    {
        return std::regex_match(value, regTime);
    }

    //
    // @brief - regexDate @todo write something here about how the date 
    //           we are trying to match looks like. - JSolsvik 15.08.17 
    // @robustness - Does not account for varying month-length and year-length
    //
    constexpr std::regex regexDate(R"(([\s]*)
                                   (([0][1-9])|([1-2][0-9])|([3][0-1]))
                                   ([\.])
                                   ([0][1-9]|[1][0-2])
                                   ([\.])
                                   ((([1][9])|([2][0]))?)
                                   ([0-9]{2})$)"); 
    
    inline bool isDate(const char* value)
    {
        return std::regex_match(value, regDate);
    }
}}