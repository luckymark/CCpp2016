cmake_minimum_required(VERSION 3.5)
project(EverFighter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Scene.cpp Scene.h SceneContext.cpp SceneContext.h SplashScene.cpp SplashScene.h LoginScene.cpp LoginScene.h QRCodeHelper.cpp QRCodeHelper.h SessionService.cpp SessionService.h MainMenuScene.cpp MainMenuScene.h QRCodeScene.cpp QRCodeScene.h TextScene.cpp TextScene.h GameObject.h PlayerFighterObject.cpp PlayerFighterObject.h BattleScene.cpp BattleScene.h ShootTexturePack.h BulletObject.cpp BulletObject.h EnemyFighterObject.cpp EnemyFighterObject.h ResourceLoader.cpp ResourceLoader.h GameOverScene.cpp GameOverScene.h)
add_executable(EverFighter ${SOURCE_FILES})
target_link_libraries(EverFighter jsoncpp curl zint sfml-audio sfml-graphics sfml-window sfml-system pthread)