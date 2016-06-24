//
// Created by wxdao on 16-5-13.
//

#include <regex>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include "SessionService.h"

static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string *) userp)->append((char *) contents, size * nmemb);
    return size * nmemb;
}

SessionService *SessionService::instance = nullptr;

SessionService *SessionService::getInstance() {
    return instance == nullptr ? instance = new SessionService() : instance;
}


bool SessionService::hasLoggedIn() {
    return !openId.empty();
}

std::string SessionService::getPlayerName() {
    if (!hasLoggedIn()) {
        return "Player (Offline)";
    }
    Json::Reader reader;
    Json::Value root;
    Json::Value tmp;
    reader.parse(getInfo(), root);
    tmp = root.get("name", Json::Value::null);
    return tmp.asString();
}


int SessionService::getMaxLives() {
    if (!hasLoggedIn()) {
        return 3;
    }
    Json::Reader reader;
    Json::Value root;
    Json::Value tmp;
    reader.parse(getInfo(), root);
    tmp = root.get("items", Json::Value::null);
    for (Json::Value v : tmp) {
        if (v.asString() == "chengdu") {
            return 5;
        }
    }
    return 3;
}

int SessionService::getShootingType() {
    if (!hasLoggedIn()) {
        return 1;
    }
    Json::Reader reader;
    Json::Value root;
    Json::Value tmp;
    reader.parse(getInfo(), root);
    tmp = root.get("items", Json::Value::null);
    for (Json::Value v : tmp) {
        if (v.asString() == "spdb") {
            return 2;
        }
    }
    return 1;
}

int SessionService::getInitialHealth() {
    if (!hasLoggedIn()) {
        return 200;
    }
    Json::Reader reader;
    Json::Value root;
    Json::Value tmp;
    reader.parse(getInfo(), root);
    tmp = root.get("items", Json::Value::null);
    for (Json::Value v : tmp) {
        if (v.asString() == "uestc") {
            return 400;
        }
    }
    return 200;
}


SessionService::SessionService() {
    curl_global_init(CURL_GLOBAL_ALL);
}


SessionService::~SessionService() {
    curl_global_cleanup();
}


std::string SessionService::getLoginToken() {
    if (loginToken.empty()) {
        CURL *curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, "https://labxdao.vecsight.com/ef/generateLoginToken");
        std::string readBuffer;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        if (CURLE_OK == curl_easy_perform(curl)) {
            if (readBuffer.length() == 36) {
                loginToken = readBuffer;
            }
        }
        curl_easy_cleanup(curl);
    }
    return loginToken;
}


void SessionService::startListen() {
    if (!loginToken.empty()) {
        std::string url = "https://labxdao.vecsight.com/ef/getLoginResult/";
        url += loginToken;
        std::thread listenThread([=]() {
            int counter = 600;
            while (!this->hasLoggedIn() && counter > 0) {
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                --counter;
                CURL *curl = curl_easy_init();
                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
                std::string readBuffer;
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
                if (CURLE_OK == curl_easy_perform(curl)) {
                    if (readBuffer != "Fatal") {
                        Json::Reader reader;
                        Json::Value root;
                        Json::Value tmp;
                        reader.parse(readBuffer, root);
                        tmp = root.get("loggedIn", Json::Value::null);
                        if (tmp.asBool()) {
                            tmp = root.get("openId", Json::Value::null);
                            openId = tmp.asString();
                        }
                    }
                }
                curl_easy_cleanup(curl);
            }
        });
        listenThread.detach();
    }
}


std::string SessionService::getInfo() {
    if (hasLoggedIn()) {
        std::string url = "https://labxdao.vecsight.com/ef/getInfo/raw/";
        url += openId;
        CURL *curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        std::string readBuffer;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        if (CURLE_OK == curl_easy_perform(curl)) {
            curl_easy_cleanup(curl);
            return readBuffer;
        } else {
            curl_easy_cleanup(curl);
            return "";
        }
    } else {
        return "";
    }
}


std::string SessionService::getOpenId() {
    return openId;
}


void SessionService::recordScore(int score) {
    if (hasLoggedIn()) {
        std::string url = "https://labxdao.vecsight.com/ef/recordScore/";
        url += openId + '/' + std::to_string(score);
        CURL *curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        std::string readBuffer;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
}

