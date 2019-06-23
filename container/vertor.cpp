//
//  vertor.cpp
//  LiziSTL
//
//  Created by 许立子 on 2019/6/23.
//  Copyright © 2019 xulizi. All rights reserved.
//

#include "vertor.hpp"


namespace LiziSTL
{
    template <typename T>
    uchar Vector<T>::SetCapacity(const size_type capacity)
    {
        if (capacity < m_size) {
            return ERR_CAPACITY_LESS_SIZE;
        }
        else if (capacity == m_capacity) {
            return ERR_CAPACITY_NO_CHANGE;
        }
        else if (capacity < m_capacity) {
            size_type deltaCapacity = m_capacity - capacity;
            T* 
            m_p_end_of_storage
        }
        
        m_capacity = capacity;
    }
}
