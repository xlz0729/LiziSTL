//
//  base.h
//  LiziSTL
//
//  Created by 许立子 on 2019/6/23.
//  Copyright © 2019 xulizi. All rights reserved.
//

#ifndef base_h
#define base_h


#define SUCCESS_OP              0x00

#define ERR_CAPACITY_LESS_SIZE  0x10
#define ERR_CAPACITY_NO_CHANGE  0x11


namespace LiziSTL
{
    typedef std::size_t      size_type;
    typedef std::ptrdiff_t   diff_type;
    
    typedef unsigned char uchar;
    typedef unsigned int  uint;
}


#endif /* base_h */
