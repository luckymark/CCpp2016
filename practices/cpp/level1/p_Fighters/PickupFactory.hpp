//
//  PickupFactory.hpp
//  plane
//
//  Created by mac on 16/5/10.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef PickupFactory_hpp
#define PickupFactory_hpp
#include "Pickup.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class PickupFactory {
  public:
    static Pickup *createPickup(int type, double PositionX, double PositionY);
};
#endif /* PickupFactory_hpp */
