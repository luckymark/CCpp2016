//
//  player.hpp
//  SFML-PLANE
//
//  Created by iam24 on 16/5/8.
//  Copyright © 2016年 iam24. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include "Plane.hpp"
#include "bullet.hpp"
#include <vector>
class Player : public Plane
{
public:
    Player(double speed);
    friend class Game;
private:
    int health_time =  150; //控制一闪一闪的时间
    bool hit = false;
};
#endif /* player_hpp */
