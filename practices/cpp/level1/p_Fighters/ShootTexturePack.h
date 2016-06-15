//
// Created by wxdao on 16-5-23.
//

#ifndef EVERFIGHTER_SHOOTTEXTUREPACK_H
#define EVERFIGHTER_SHOOTTEXTUREPACK_H


#include <SFML/Graphics.hpp>

class ShootTexturePack {
public:
    static std::string getFilePath() {
        return "res/textures/shoot.png";
    }

    static sf::IntRect hero1() {
        return sf::IntRect(0, 99, 102, 126);
    }

    static sf::IntRect hero2() {
        return sf::IntRect(165, 360, 102, 126);
    }

    static sf::IntRect hero_blowup_n1() {
        return sf::IntRect(165, 234, 102, 126);
    }

    static sf::IntRect hero_blowup_n2() {
        return sf::IntRect(330, 624, 102, 126);
    }

    static sf::IntRect hero_blowup_n3() {
        return sf::IntRect(330, 498, 102, 126);
    }

    static sf::IntRect hero_blowup_n4() {
        return sf::IntRect(432, 624, 102, 126);
    }

    static sf::IntRect enemy1() {
        return sf::IntRect(534, 612, 57, 43);
    }

    static sf::IntRect enemy1_down1() {
        return sf::IntRect(267, 347, 57, 51);
    }

    static sf::IntRect enemy1_down2() {
        return sf::IntRect(873, 697, 57, 51);
    }

    static sf::IntRect enemy1_down3() {
        return sf::IntRect(267, 296, 57, 51);
    }

    static sf::IntRect enemy1_down4() {
        return sf::IntRect(930, 697, 57, 51);
    }

    static sf::IntRect enemy2() {
        return sf::IntRect(0, 0, 69, 99);
    }

    static sf::IntRect enemy2_down1() {
        return sf::IntRect(534, 655, 69, 95);
    }

    static sf::IntRect enemy2_down2() {
        return sf::IntRect(603, 655, 69, 95);
    }

    static sf::IntRect enemy2_down3() {
        return sf::IntRect(672, 653, 69, 95);
    }

    static sf::IntRect enemy2_down4() {
        return sf::IntRect(741, 653, 69, 95);
    }

    static sf::IntRect bullet1() {
        return sf::IntRect(1004, 987, 9, 21);
    }

    static sf::IntRect bullet2() {
        return sf::IntRect(69, 78, 9, 21);
    }
};


#endif //EVERFIGHTER_SHOOTTEXTUREPACK_H
