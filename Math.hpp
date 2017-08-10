// @file file.h
// @date 10.08.17
// @creator Jonas J. Solsvik
// @brief Write and read file
#pragma once

namespace jet 
{
    namespace Math 
    {

        template<typename T> 
        int8_t sign(T value);

        template<typename T> 
        T radian(T grad); 
        template<typename T> 
        T grad  (T rad);

        const double incrediblySmall = 0.00001F;
        const double PI = 3.14159;

        template<typename T>
        inline int8_t sign(T value)
        {   
            return ((value > (0.0 - jet::incrediblySmall)) ? 1 : -1);
        }

        template<typename T>
        inline T radian(T deg) 
        {    
            return (deg / 180.0) * PI;    
        }

        template<typename T>
        inline T grad(T rad)
        {     
            return (rad / PI) * 180.0F;  
        }
    }
}