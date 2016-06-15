//
//  PickupFactory.cpp
//  plane
//
//  Created by mac on 16/5/10.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#include "AutoFire.hpp"
#include "DamageUp.hpp"
#include "HealthUp.hpp"
#include "LuckUp.hpp"
#include "Magnetic.hpp"
#include "PickupFactory.hpp"
#include "speedUp.hpp"
Pickup *PickupFactory::createPickup(int type, double PositionX,
                                    double PositionY) {
    Pickup *pickup = NULL;
    switch (type) {
    case 0:
        pickup = new HealthUp(PositionX, PositionY);
        break;
    case 1:
        pickup = new DamageUp(PositionX, PositionY);
        break;
    case 2:
        pickup = new SpeedUp(PositionX, PositionY);
        break;
    case 3:
        pickup = new LuckUp(PositionX, PositionY);
        break;
    case 4:
        pickup = new AutoFire(PositionX, PositionY);
        break;
    case 5:
        pickup = new Magnetic(PositionX, PositionY);
        break;
    default:
        break;
    }
    return pickup;
}