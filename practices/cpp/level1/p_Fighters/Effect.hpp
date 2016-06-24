//
//  Effect.hpp
//  plane
//
//  Created by mac on 16/6/1.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef Effect_hpp
#define Effect_hpp
#include "SecondaryObject.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class Effect:public SecondaryObject{
protected:
    double last;
public:
    double getLast();
};
#endif /* Effect_hpp */
