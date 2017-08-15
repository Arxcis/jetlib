//
//  test.cpp
//  jetlib
//
//  Created by JSolsvik on 02/05/2017.
//  Copyright © 2017 JSolsvik. All rights reserved.
//

#include <stdio.h>

#include "Valid.hpp"
#include "Convert.hpp"

using namespace jet;

enum Testcodes
{
    ONE =              0b1,
    TWO =             0b10,
    THREE =          0b100,
    FOUR =          0b1000,
    FIVE =        0b100000,
    SIX =        0b1000000,
    SEVEN =     0b10000000,
    EIGHT =    0b100000000,
};

//#include "noise.hpp"

namespace Test 
{
    void Valid()
    {   
        int OK = 0b0;
        int activeCodes = 0b0;
        //
        // TEST 1 - names
        //
        {
            activeCodes = Testcodes::ONE | Testcodes::TWO | Testcodes::THREE;
            
            std::string name = "Jonas Solsvik";
            OK |= Valid::isName(name) ? Testcodes::ONE : 0b0;

            name = "Jonas ++ Solsvik";
            OK |= !Valid::isName(name) ? Testcodes::TWO : 0b0;

            name = "jonas' Sølsvik";
            OK |=  Valid::isName(name) ? Testcodes::THREE : 0b0; 


            if ((OK & activeCodes) == activeCodes) 
            {
                printf("\nTEST: Names OK..");
            }
            else 
            { 
                printf("\nTEST: Names FAILED!!!");
            }
            printf("\nOK STATUS: %s activeCodes: %s", Convert::bin(OK).c_str(), Convert::bin(activeCodes).c_str());                            
        } 

        //
        // TEST 2 - Phone numbers
        //
        {
            OK = 0b0; activeCodes = 0b0;
            activeCodes = Testcodes::ONE | Testcodes::TWO | Testcodes::THREE | Testcodes::FOUR;

            std::string phone = "+400 23 30 30 21";
            OK |= Valid::isPhone(phone) ? Testcodes::ONE : 0b0;

            phone = "+48 340 23 200";
            OK |= Valid::isPhone(phone) ? Testcodes::TWO : 0b0;

            phone = " 3000230403  ";
            OK |= Valid::isPhone(phone) ? Testcodes::THREE : 0b0;

            phone = "30x00230403";
            OK |= !Valid::isPhone(phone) ? Testcodes::FOUR : 0b0;
            
            if ((OK & activeCodes) == activeCodes) 
            {
                printf("\nTEST: Phone numbers OK..");
            }
            else 
            { 
                printf("\nTEST: Phone numbers FAILED!!!");
            }
            printf("\nOK STATUS: %s activeCodes: %s", Convert::bin(OK).c_str(), Convert::bin(activeCodes).c_str());
        }

        //
        // TEST 3 - Email numbers
        //
        {

            OK = 0b0; activeCodes = 0b0;
            activeCodes = Testcodes::ONE | Testcodes::TWO | Testcodes::THREE;

//            std::string email = "Jonas Solsvik";
//            OK |= Valid::isName(name) ? Testcodes::ONE : 0b0;
//
//            std::string email = "Jonas Solsvik";
//            OK |= Valid::isName(name) ? Testcodes::ONE : 0b0;
//
//            std::string email = "Jonas Solsvik";
//            OK |= Valid::isName(name) ? Testcodes::ONE : 0b0;
//
//            if ((OK & activeCodes) == activeCodes) 
//            {
//                printf("\nTEST: Names OK..");
//            }
//            else 
//            { 
//                printf("\nTEST: Names FAILED!!!");
//            }
//            printf("\nOK STATUS: %s activeCodes: %s", Convert::bin(OK).c_str(), Convert::bin(activeCodes).c_str());                            
//        
        }
    }
}

int main () 
{   
    Test::Valid();
    return 0;
}


//    void noise() 
//    { 
//        float min=2.0F, max=0.0F;
//
//        for(int j=0; j < 1000; j++) 
//        {
//            randomize(noiseGrid);
//
//            for(int i=0; i < 800; i++) 
//            {
//                float currentNoise = noise(noiseGrid, {(float)i,(float)i});
//                
//                if (currentNoise < min)   
//                { 
//                    min = currentNoise; 
//                }
//                else if(currentNoise > max) 
//                { 
//                    max = currentNoise; 
//                }
//            }
//        }
//        printf("min: %.2f  max: %.2f\n", min, max);
//    }
