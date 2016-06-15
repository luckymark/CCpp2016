#pragma once
#include <SFML\Graphics.hpp>

#include <map>
#include <functional>
#include <vector>
#include <utility>

#include "State.hpp"
#include "StateIdentifiers.hpp"

class StateStack :private sf::NonCopyable {
public:
	enum Action {
		Push,
		Pop,
		Clear,
	};
public:
	explicit StateStack(State::Context context);

	template<typename T>
	void registerState(States::ID stateID);
	void update(sf::Time dt);
	void draw();
	void handleEvent(const sf::Event &event);
	void pushState(States::ID stateID);
	void popState();
	void clearStates();

	bool isEmpty() const;

private:
	State::Ptr creatState(States::ID stateID);
	void applyPendingChanges();

private:
	struct PendingChange {
		PendingChange(Action action, States::ID stateID = States::None);
		Action action;
		States::ID stateID;
	};

private:
	std::vector<State::Ptr> mStack;
	std::vector<PendingChange> mPendingList;
	State::Context mContext;
	std::map<States::ID, std::function<State::Ptr()>> mFactories;
};

template <typename T>
void StateStack::registerState(States::ID stateID) {
	mFactories[stateID] = [this]() { //Whole class?
		return State::Ptr(new T(*this, mContext));
	};
}