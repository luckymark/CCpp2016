//
// Created by wxdao on 16-5-13.
//

#ifndef EVERFIGHTER_ONLINESERVICE_H
#define EVERFIGHTER_ONLINESERVICE_H


#include <string>
#include <thread>

class SessionService {
private:
    static SessionService *instance;
    std::string loginToken;
    std::string openId;

    SessionService();

    ~SessionService();

public:
    static SessionService *getInstance();

    void startListen();

    std::string getLoginToken();

    std::string getOpenId();

    bool hasLoggedIn();

    std::string getInfo();

    std::string getPlayerName();

    int getMaxLives();

    int getShootingType();

    int getInitialHealth();

    void recordScore(int score);
};


#endif //EVERFIGHTER_ONLINESERVICE_H
