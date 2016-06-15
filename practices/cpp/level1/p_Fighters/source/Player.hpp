#pragma once
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <map>

#include "Command.hpp"
#include "CommandQueue.hpp"

class Player {
public:
	enum Action {
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown,
		Fire,
		Bomb,
		ActionCount
	};
	enum MissionStatus {
		MissionRunning,
		MissionFailure,
		MissionSuccess,
	};
	void assignKey(Action action, sf::Keyboard::Key key);
	sf::Keyboard::Key getAssignKey(Action action) const;

	MissionStatus getMissionStatus() const;
	void setMissionStatus(MissionStatus status);

	const int getPlayerScore() const;
	void setPlayerScore(int score);

private:
	static bool isRealtimeAction(Action action);
	void initAction();


private:
	std::map<sf::Keyboard::Key, Action> mKeyBinging;
	std::map<Action, Command> mActionBingding;

	MissionStatus mMissionStatus;
	int mPlayerScore;

public:
	Player();
	void handleEvent(const sf::Event &event, CommandQueue &commands);
	void handleRealtimeInput(CommandQueue &commands);

};