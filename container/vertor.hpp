//
//  vertor.hpp
//  LiziSTL
//
//  Created by 许立子 on 2019/6/23.
//  Copyright © 2019 xulizi. All rights reserved.
//

#ifndef vertor_hpp
#define vertor_hpp

#include <iostream>
#include "common/allocator.hpp"


namespace LiziSTL
{
    template <typename T>
    class Vector
    {
    public:
        explicit Vector(const size_type capacity = 20);
        ~Vector();
        
        // 销毁容器，释放内存
        void Destory();
        
        uchar SetCapacity(const size_type capacity);
        
        // 内联函数
        inline size_type GetCapacity() {
            return m_capacity;
        }
        
        inline size_type GetSize() {
            return m_size;
        }
        
        inline size_type GetTrunkSize() {
            return m_trunk_size;
        }
        
        
        
        
    protected:
        size_type   m_capacity;     // 当前可容纳的最大数据空间
        size_type   m_size;         // 当前已经存储的数据空间
        size_type   m_trunk_size;   // 一个数据块的大小，等于sizeof(T)
        
    private:
        T*                 m_p_data;            // 所有数据都存在这个指针中
        std::shared_ptr<T> m_p_start;           // 当前已用空间的头
        std::shared_ptr<T> m_p_finish;          // 当前已用空间的尾
        std::shared_ptr<T> m_p_end_of_storage;  // 最大存储空间的尾
    };
}

#endif /* vertor_hpp */
