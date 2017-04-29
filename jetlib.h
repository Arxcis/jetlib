#pragma once

#include <cmath>
#include <cstdint>
#include <SFML/Graphics.hpp>

namespace jet 
{
    const double incrediblySmall = 0.00001F;
    
    template<typename T>
    int8_t 
    sign(T value)
    {   
        return ((value > (0.0 - jet::incrediblySmall)) ? 1 : -1);
    }

    template<typename T>
    inline T 
    radian(T deg) 
    {    return (deg / 180.0) * PI;    }

    template<typename T>
    inline T 
    grad(T rad)
    {     return (rad / PI) * 180.0F;  }

    //
    // Vector procedures
    //
    template<typename T>
    inline void 
    printVector(sf::Vector2<T> vec, std::string msg="")
    {   
        printf("%s   X:%.3f   Y:%.3f\n", msg.c_str(), vec.x, vec.y);
    }

    template<typename T>
    inline T 
    cross(sf::Vector2<T> a, sf::Vector2<T> b) 
    {    
        T crossproduct = (a.x * b.y - a.y * b.x);
        return crossproduct;
    }

    template<typename T>
    inline T 
    dot(sf::Vector2<T> a, sf::Vector2<T> b)
    {   
        return (a.x * b.x + a.y * b.y);    
    }

    template<typename T>
    inline T
    length(sf::Vector2<T> a)
    {
        T hypotenuse = std::sqrt((a.x * a.x) + (a.y * a.y));
        return hypotenuse;
    }

    template<typename T>
    inline sf::Vector2<T> 
    normalize(sf::Vector2<T> a) 
    {
        float alength = jet::length(a);
        return {
            a.x /= alength,
            a.y /= alength,
        };
    }  

    template<typename T>
    inline float 
    angle(sf::Vector2<T> a, sf::Vector2<T> b)
    {
        float dotProduct = dot(normalize(a), normalize(b));
        return acos(dotProduct);
    } 

    template<typename T>
    inline T 
    lerp(T a, T b, T weight) 
    {
        return (((1.0 - weight) * a) + weight * b);
    }

    template<typename T>
    inline T 
    cosineLerp(T a, T b, T t) 
    {
        T cost = (1 - cos(t * PI )) * 0.5;
        return ((1.0 - cost) * a) + cost * b;
    }

    template<typename T>
    inline T  
    min(T a, T b)
    {
        return (b < a) ? b : a;
    }
    
    template<typename T>
    sf::Vector2<T>
    computeLaunchSpeedVector(sf::Vector2<T> top){
        const T gravity = 10.0F;
        const T ycomponent = std::sqrt(2 * top.y * gravity);
        return { 
            top.x * (gravity) / ycomponent, 
            ycomponent
        };
    }
}
