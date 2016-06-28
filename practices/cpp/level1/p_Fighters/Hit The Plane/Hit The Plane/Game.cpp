//
//  Game.cpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/12.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include "Game.hpp"

char scorePath[200]="/Users/caoxiann/Desktop/c/c &c++lesson/CCpp2016/practices/cpp/level1/p_Fighters/Hit The Plane/score.txt";
Game *Game::instance=nullptr;
std::default_random_engine Game::random_engine(time(0));

Game *Game::getInstance(){
    if (!instance) {
        instance=new Game;
    }
    return instance;
}

void Game::scored(){
    score++;
}

int Game::getScore(){
    return score;
}

void Game::isGameOver(){
    
}

void Game::setPlayer(Player *thePlayer){
    this->player=thePlayer;
}

void Game::restartGame(){
    this->resetScore();
}

void Game::resetScore(){
    score=0;
}

int Game::getBestScore(){
    int bestScore;
    FILE *fp=fopen(scorePath, "r+");
    while (fscanf(fp, "%d",&bestScore)!=EOF) {
        if (score>=bestScore) {
            fclose(fp);
            FILE *fw=fopen(scorePath, "w");
            fprintf(fw, "%d",score);
            fclose(fw);
            return score;
        }else{
            fclose(fp);
            return bestScore;
        }
    }
    
}
