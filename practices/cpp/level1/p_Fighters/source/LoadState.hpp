#pragma once
#include <SFML\Graphics.hpp>

#include "State.hpp"
#include "StateStack.hpp"
#include "ParallelTask.hpp"

class LoadState :public State {
public:
	LoadState(StateStack &stack, Context context);
	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event &event);

	void setCompletion(float percent);
private:
	sf::Text mLoadingText;
	sf::RectangleShape mProgressBarBackground;
	sf::RectangleShape mProgressBar;

	ParallelTask mLoadingTask;
};