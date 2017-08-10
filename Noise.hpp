//
// @file noise.h
// @brief extension of the library added 03.05.17 by Jonas
//
#pragma once

#include <random>
#include <vector>
#include <cassert>
#include <SFML/Graphics.hpp>

#include "jetlib.h"
#include "const.h"


struct NoiseGrid
{
    static const unsigned maxValue = SCREEN_SIZE;
    static const unsigned columns    = 10;
    static const unsigned cellCount  = columns * columns;
    float    cellSize   = maxValue / float(columns); // This has to be valid integer division, to prevent precision losses.
    
    unsigned seed = 0;
    sf::Vector2f data[cellCount];
    std::random_device rd; 
    std::uniform_real_distribution<float> uniformDistribution { 0, 1 };

} noiseGrid;

//
// @function randomize3
//  @brief fills the grid with random values.
//
inline void randomize(NoiseGrid& grid) 
{   
    grid.seed = grid.rd();
    std::mt19937 generator{ grid.seed };

    for (unsigned i = 0; i < grid.cellCount; i++)
    {
        grid.data[i] = {  
            grid.uniformDistribution(generator),  
            grid.uniformDistribution(generator) 
        };
        printf("randx: %.2f  randy: %.2f\n", grid.data[i].x , grid.data[i].y);
    }  
}

inline void init(NoiseGrid& grid){  randomize(grid); }

//
// @function noise
//  @brief An implementation of 2-dimensional perlin noise.
//
inline float noise(const NoiseGrid& grid, const sf::Vector2f unscaledPosition)
{    
    assert(unscaledPosition.x < grid.maxValue && unscaledPosition.y < grid.maxValue);
    // 0. Scale down input to fit the grid
    const sf::Vector2f position = { unscaledPosition.x / grid.cellSize, unscaledPosition.y / grid.cellSize };
    
    // 1. Find index in the grid array rectangle
    const sf::Vector2i topLeft  = { (int)std::floor(position.x), (int)std::floor(position.y) };
    const sf::Vector2i botRight = { topLeft.x + 1, topLeft.y + 1 };

    // 2. Find distance vectors
    const sf::Vector2f distances[4] = {
        { position.x - topLeft.x,  position.y - topLeft.y  },
        { position.x - botRight.x, position.y - topLeft.y  },
        { position.x - topLeft.x,  position.y - botRight.y },
        { position.x - botRight.x, position.y - botRight.y },
    };

    // 3. Dot product 4 pair of vectors - distance vectors + random vectors
    const float dots[4] = { 
        jet::dot( distances[0], grid.data[topLeft.y  * grid.columns + topLeft.x ] ),
        jet::dot( distances[1], grid.data[topLeft.y  * grid.columns + botRight.x] ),
        jet::dot( distances[2], grid.data[botRight.y * grid.columns + topLeft.x ] ),
        jet::dot( distances[3], grid.data[botRight.y * grid.columns + botRight.x] ),
    };

    // 4. LERP two and two vectors.
    const float lx1 = jet::lerp(dots[0], dots[1], position.x - topLeft.x);
    const float lx2 = jet::lerp(dots[2], dots[3], position.x - topLeft.x);

    return jet::lerp(lx1, lx2, position.y - topLeft.y) + 0.5F;
}

//
// @function noise 1d
//  @brief simplified implementation for 1 dimensions
//
inline float noise(const NoiseGrid& grid, const float offset)
{
    assert(offset < (grid.columns * grid.maxValue));

    const float soffset = offset / grid.cellSize;
    const int   gridx   = (int)soffset;

    return jet::cosineLerp(grid.data[gridx].x, grid.data[gridx+1].x, soffset - gridx);
}
