### Ever Fighter

## Features

1. Smooth gameplay - Not laggy at all while planes and bullets everywhere

2. WeChat integration - Review your profile online and buy items with coins on wechat

3. Happy all the time - Game complexity increases as you play without any loss of fun

## Code structure

1. Logic code for a scene implemented in Scene class

2. SceneContext class to handle the hierarchy of Scene classes so as to easily transform through different scenes without pain

3. Fighters and bullets have their own class inherited from sf::Sprite

4. ResouceLoader singleton to globally deal with loading stuff of textures, fonts etc. 

5. SessionService singleton to handle online contents and return default values for offline mode

## Online server

1. Powered by Node.js

*** secret ***
