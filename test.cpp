//
//  test.cpp
//  jetlib
//
//  Created by JSolsvik on 02/05/2017.
//  Copyright © 2017 JSolsvik. All rights reserved.
//

#include <stdio.h>
#include "jetlib.h"
#include "noise.h"

int main()
{
    float min=2.0F, max=0.0F;

    for(int j=0; j < 1000; j++) {
        randomize(noiseGrid);

        for(int i=0; i < 800; i++) {
            float currentNoise = noise(noiseGrid, {(float)i,(float)i});
            
            if   (currentNoise < min) { min = currentNoise; }
            else if(currentNoise > max) { max = currentNoise; }
        }
    }
    printf("min: %.2f  max: %.2f\n", min, max);
}
