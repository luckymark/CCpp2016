#include <iostream>
#include <algorithm>
#include <functional>

#include "Player.hpp"
#include "SceneNode.hpp"
#include "Aircraft.hpp"

struct AircraftMover {
	AircraftMover(float vx, float vy) :velocity(vx, vy) {}

	void operator()(Aircraft &aircraft, sf::Time dt) const {
		aircraft.accelerate(velocity);
	}

	sf::Vector2f velocity;
};
void Player::assignKey(Action action, sf::Keyboard::Key key)
{
}
sf::Keyboard::Key Player::getAssignKey(Action action) const
{
	for (auto &pair : mKeyBinging) {
		if (action == pair.second)
			return pair.first;
	}
	return sf::Keyboard::Unknown;
}
Player::MissionStatus Player::getMissionStatus() const
{
	return mMissionStatus;
}
void Player::setMissionStatus(MissionStatus status)
{
	mMissionStatus = status;
}
const int Player::getPlayerScore() const
{
	return mPlayerScore;
}
void Player::setPlayerScore(int score)
{
	mPlayerScore = score;
}
bool Player::isRealtimeAction(Action action)
{
	switch (action)	
	{
	case MoveDown:
	case MoveUp:
	case MoveLeft:
	case MoveRight:
	case Fire:
		return true;
	case Bomb:
		return false;
	default:
		break;
	}
	return false;
}
void Player::initAction()
{
	const float playerSpeed = 200.f;

	mActionBingding[MoveLeft].action = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f));
	mActionBingding[MoveRight].action = derivedAction<Aircraft>(AircraftMover(+playerSpeed, 0.f));
	mActionBingding[MoveUp].action = derivedAction<Aircraft>(AircraftMover(0.f, -playerSpeed));
	mActionBingding[MoveDown].action = derivedAction<Aircraft>(AircraftMover(0.f, +playerSpeed));
	mActionBingding[MoveLeft].category = Category::PlayerAircraft;
	mActionBingding[MoveRight].category = Category::PlayerAircraft;
	mActionBingding[MoveUp].category = Category::PlayerAircraft;
	mActionBingding[MoveDown].category = Category::PlayerAircraft;

	mActionBingding[Fire].action = derivedAction<Aircraft>(std::bind(&Aircraft::fire, std::placeholders::_1));
	mActionBingding[Fire].category = Category::PlayerAircraft;
	mActionBingding[Bomb].action = derivedAction<Aircraft>(std::bind(&Aircraft::launchMissile, std::placeholders::_1));
	mActionBingding[Bomb].category = Category::PlayerAircraft;
}
Player::Player() :mMissionStatus(MissionRunning), mPlayerScore(0)
{
	mKeyBinging[sf::Keyboard::Left] = MoveLeft;
	mKeyBinging[sf::Keyboard::Right] = MoveRight;
	mKeyBinging[sf::Keyboard::Up] = MoveUp;
	mKeyBinging[sf::Keyboard::Down] = MoveDown;
	mKeyBinging[sf::Keyboard::F] = Fire;
	mKeyBinging[sf::Keyboard::Space] = Bomb;
	initAction();
}

void Player::handleEvent(const sf::Event & event, CommandQueue & commands)
{
	if (event.type == sf::Event::KeyPressed) {
		auto it = mKeyBinging.find(event.key.code);
		if (it != mKeyBinging.end() && !isRealtimeAction(it->second)) {
			commands.push(mActionBingding[it->second]);
		}
	}
}

void Player::handleRealtimeInput(CommandQueue & commands)
{
	for (auto &pair : mKeyBinging)
	{
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
			commands.push(mActionBingding[pair.second]);
	}
}
