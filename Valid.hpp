//
// @date 10.08.17
// @creator Jonas J. Solsvik
// @brief Regex validate string types
//

#pragma once
#include <regex>
#include <string>

// @urldoc - tool for creating/validating regex - www.rubular.com

namespace jet { namespace Valid {

    //
    // @brief - regexName validates if only characters
    //   1. Characters a-åA-Å and period '.' and '\''
    //
    const std::regex regexName(R"(^([\s]*)([a-zA-ZæøåÆØÅ \.']*)([\s]*)$)");
    
    inline bool isName(std::string value)
    { 
        return std::regex_match(value, regexName);
    }

    //
    // @brief - regexChar3 validates to true if:
    //      1. 3 letter word
    //      2. All uppercase
    //      3. A-Z
    //
    const std::regex regexChar3(R"(^([\s]*)
                                    ([A-Z]{3})
                                    ([\s]*)$)");

    inline bool isChar3(std::string value)
    {
        return std::regex_match(value, regexChar3);
    }

    //
    // @brief - regexInt validates to true if:
    //      1. A string consisting only of numeric-characters 0-9
    //
    const std::regex regexInt(R"(([-]?)([0-9])+)");
    
    inline bool isInt(std::string value)
    {
        return std::regex_match(value, regexInt);
    }


    // @brief - regexDouble validates to true if:
    //     1. 0-15 numberic characters,
    //     2. followed by a period, 
    //     3. followd by 1-15 numeric characters.
    // @robustness - could overflow floating point, @broken per 06.04.17
    //
    const std::regex regexDouble(R"(([\s]*)
                                     ([+-]?)
                                     ([0-9]{0,15})
                                     ([\.]?)([0-9]{1,15}))");

    inline bool isDouble(std::string value)
    {
        return std::regex_match(value, regexDouble);
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
    const std::regex regexEmail(R"((([\d[:alpha:]_\.])*)
                                    ([@])
                                    ([\d[:alpha:]_\.])*)");  
        
    inline bool isEmail(std::string value)
    {
        return std::regex_match(value, regexEmail);
    }


    //
    // @brief - regexPhone validates to true if:
    //     1(optional). Mandatory + at beginning
    //     2(optional). 1-4 numbers 
    //     3(optional). Mandatory space
    //     4. 6-14 numbers, - or spaces.
    //
    const std::regex regexPhone(R"(^([\s]*)(([+][0-9]{1,4}[ ])?)([0-9\- ]{6,14})([\s]*)$)");

    inline bool isPhone(std::string value)
    {
        return std::regex_match(value, regexPhone);
    }

    //
    // @brief - regexTime @todo write something here about how the time 
    //           we are trying to match looks like. - JSolsvik 15.08.17
    // @robustness, demands 00:00:00:999 for milliseconds
    //
    const std::regex regexTime(R"(([\s]*)
                                   (([0-1][0-9])|([2][0-4]))
                                   ([:])
                                   ([0-5][0-9])
                                   (([:]([0-5][0-9]))?)
                                   (([:]([0-9]{3}))?))"); 

    inline bool isTime(std::string value)
    {
        return std::regex_match(value, regexTime);
    }

    //
    // @brief - regexDate @todo write something here about how the date 
    //           we are trying to match looks like. - JSolsvik 15.08.17 
    // @robustness - Does not account for varying month-length and year-length
    //
    const std::regex regexDate(R"(([\s]*)
                                   (([0][1-9])|([1-2][0-9])|([3][0-1]))
                                   ([\.])
                                   ([0][1-9]|[1][0-2])
                                   ([\.])
                                   ((([1][9])|([2][0]))?)
                                   ([0-9]{2})$)"); 
    
    inline bool isDate(std::string value)
    {
        return std::regex_match(value, regexDate);
    }
}}