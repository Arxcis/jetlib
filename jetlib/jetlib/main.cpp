//
//  jetlib
//  Created by JSolsvik on 02/05/2017.
//  Copyright © 2017 JSolsvik. All rights reserved.
//  
//  Here we test the various components of jetlib to validate it's correctness
//

#include "valid.hpp";
#include <stdio.h>

bool __test__jetValid()
{   
    bool OK = false;
    
    // TEST 1 - name
    {
        const char[] name = "Jonas Solsvik";
        if (jet::Valid::isName(name)) 
            OK = true;
        else                          
            OK = false;

        if (OK)
            printf("Name test OK..")
        else 
            printf("Name test FAILED!!!");
        
        OK = false;
    }
}



int main () 
{
    __test__jetValid();
    return 0;
}