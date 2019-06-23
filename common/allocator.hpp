//
//  allocator.hpp
//  LiziSTL
//
//  Created by 许立子 on 2019/6/23.
//  Copyright © 2019 xulizi. All rights reserved.
//

#ifndef allocator_hpp
#define allocator_hpp


#include "base.h"

#include <iostream>


namespace LiziSTL
{
    struct Allocator_CppStyle
    {
        static char* malloc(const size_type bytes) {
            return new (std::nothrow) char[bytes];
        }
        
        static void free(char* const block) {
            delete [] block;
        }
    };
    
    struct Allocator_CStyle
    {
        static char* malloc(const size_type bytes) {
            return static_cast<char*>((std::malloc)(bytes));
        }
        
        static void free(char* const block) {
            (std::free)(block);
        }
    };
    
    template <typename T, typename UserAllocator = Allocator_CppStyle>
    class Allocator
    {
    public:
        template <typename T_Value>
        static inline void InitPointer(T* p, const T_Value& value) {
            new (p) T(value);
        }
        
        static inline T* Malloc(const size_type bytes) {
            char* head = UserAllocator::malloc(bytes);
            return Element(head);
        }
        
        static inline void Free(T* pointer) {
            char* free_pointer = reinterpret_cast<char*>(pointer);
            UserAllocator::free(free_pointer);
        }
        
        static inline T* Element(char* const chunk) {
            return reinterpret_cast<T*>(chunk);
        }
        
    private:
        Allocator() {}
    };
    
    
}   // Namespace end


#endif /* allocator_hpp */
