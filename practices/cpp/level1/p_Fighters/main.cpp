
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<SFML/Audio.hpp>

#include <SFML/Config.hpp>
#include <SFML/Main.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include <System.h>
#include <Plane_enemy.h>

int main()
{

    Plane plane;
    System system;
    system.add(plane);
    system.showPlane();
    system.manage();
    return 0;
}
