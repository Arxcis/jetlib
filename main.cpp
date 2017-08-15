//
//  test.cpp
//  jetlib
//
//  Created by JSolsvik on 02/05/2017.
//  Copyright © 2017 JSolsvik. All rights reserved.
//

#include <stdio.h>

enum Testcodes : int
{
    ONE =              0b1,
    TWO =             0b10,
    THREE =          0b100,
    FOUR =          0b1000,
    FIVE =        0b100000,
    SIX =        0b1000000,
    SEVEN =     0b10000000,
    EIGHT =    0b100000000,

    PASS = 0b111111111111111111,
}

//#include "noise.hpp"
#include "valid.hpp"

namespace Test 
{
    void Valid()
    {   
        int OK = 0b0;
        // TEST 1 - name
        {
            std::string name = "Jonas Solsvik";
            OK |= (jet::Valid::isName(name)) ? Testcodes::ONE : 0b0;

            name = "Jonas ++ Solsvik";
            OK |= (!jet::Valid::isName(name)) ? Testcodes::TWO : 0b0;

            name = "jonas' Sølsvik";
            OK |= jet::Valid::isName(name) ? Testcodes::THREE : 0b0; 

            if (OK & PASS == PASS)
                printf("TEST: Names OK..")
            else 
                printf("TEST: Names FAILED!!!");
        } 

        // TEST 2 - Phone numberss
        {}
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
}

int main () 
{   
    Test::Valid();
    return 0;
}