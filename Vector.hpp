// @file vector.h
// @date 29.04.17
// @creator Jonas J. Solsvik
// @brief Regex validate string types
#pragma once

#include <cmath>
#include <cstdint>
#include <string>
#include <iostream>

#include "math.h";
// 
// Declarations
// 
namespace jet 
{

    template<template<typename> class Vector, typename T> void    printVector(Vector<T> vec, std::string msg="");
    template<template<typename> class Vector, typename T> T         cross    (Vector<T> a, Vector<T> b);
    template<template<typename> class Vector, typename T> T         dot      (Vector<T> a, Vector<T> b);
    template<template<typename> class Vector, typename T> T         length   (Vector<T> a);
    template<template<typename> class Vector, typename T> Vector<T> normalize(Vector<T> a);
    template<template<typename> class Vector, typename T> float     angle    (Vector<T> a, Vector<T> b);

    template<typename T> T lerp        (T a, T b, T t);
    template<typename T> T cosineLerp  (T a, T b, T t);
    template<typename T> T smoothStep  (T a, T b, T t);
    template<typename T> T smootherStep(T a, T b, T t);

    template<typename T> T min(T a, T b);
    template<typename T> T max(T a, T b);

    template<template<typename> class Vector, typename T> Vector<T> computeLaunchSpeedVector(Vector<T> top);
    inline constexpr uint64_t pow(const uint64_t base, const int exponent);
}

// 
// Definitions
// 
namespace jet 
{


    //
    // Vector procedures
    //
    template<template<typename> class Vector, typename T>
    inline void printVector(Vector<T> vec, std::string msg)
    {   
        std::cout << msg << "   x: " << vec.x << "   y: " << vec.y << std::endl;
    }

    template<template<typename> class Vector, typename T>
    inline T cross(Vector<T> a, Vector<T> b)
    {    
        T crossproduct = (a.x * b.y - a.y * b.x);
        return crossproduct;
    }

    template<template<typename> class Vector, typename T>
    inline T dot(Vector<T> a, Vector<T> b)
    {   
        return (a.x * b.x + a.y * b.y);    
    }

    template<template<typename> class Vector, typename T>
    inline T length(Vector<T> a)
    {
        T hypotenuse = std::sqrt((a.x * a.x) + (a.y * a.y));
        return hypotenuse;
    }

    template<template<typename> class Vector, typename T>
    inline Vector<T> normalize(Vector<T> a) 
    {
        float alength = jet::length(a);
        return {
            a.x /= alength,
            a.y /= alength,
        };
    }  

    template<template<typename> class Vector, typename T>
    inline float angle(Vector<T> a, Vector<T> b)
    {
        float dotProduct = dot(normalize(a), normalize(b));
        return acos(dotProduct);
    } 

    //
    // @Lerp procedures
    //
    template<typename T>
    inline T lerp(T a, T b, T t) 
    {
        return (((1.0f - t) * a) + t * b);
    }

    template<typename T>
    inline T cosineLerp(T a, T b, T t) 
    {
        T cost = (1.0f - cos(t * PI )) * 0.5f;
        return ((1.0f - cost) * a) + cost * b;
    }

    template<typename T>
    inline T smoothStep(T a, T b, T t) 
    {
      t = t*t * (3.0f - 2.0f*t);
      return (((1.0f - t) * a) + t * b);
    }

    template<typename T>
    inline T smootherStep(T a, T b, T t)
    {
        t = t*t*t * (t * (6.0f * t - 15.0f) + 10.0f);
        return (((1.0f - t) * a) + t * b);
    }

    template<typename T>
    inline T min(T a, T b)
    {
        return (b < a) ? b : a;
    }

    template<typename T>
    inline T max(T a, T b)
    {
        return (b > a) ? b : a;
    }
    
    template<template<typename> class Vector, typename T>
    Vector<T> computeLaunchSpeedVector(Vector<T> top)
    {
        const T gravity = 10.0F;
        const T ycomponent = std::sqrt(2 * top.y * gravity);
        return { 
            top.x * (gravity) / ycomponent, 
            ycomponent
        };
    }

  //
  // @function 
  //  Recursive pow function which can be inlined and constexpressed
  //  @speed - Could be faster if repeated squaring is implemented
  //           Does only have anything to say for compile time speed,
  //            which is not important for this task
  //
  inline constexpr uint64_t 
  pow(const uint64_t base, const int exponent)  
  {
      return (exponent == 0) ? 1 : (base * pow(base, exponent-1));
  }
}
