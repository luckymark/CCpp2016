#include "StateStack.hpp"

#include <cassert>

StateStack::StateStack(State::Context context):
	mStack(),mContext(context),mPendingList(),mFactories()
{
}


void StateStack::update(sf::Time dt)
{
	for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr) {
		if (!(*itr)->update(dt)) //����False��ʾdt�������´���
			break;
	}
	applyPendingChanges();
}

void StateStack::draw()
{
	for (auto &state : mStack) {
		state->draw();
	}
	//���µ���
}

void StateStack::handleEvent(const sf::Event & event)
{
	for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr) {
		if (!(*itr)->handleEvent(event))
			return; // ����False��ʾ��Ϣ�������²㴫��
	}
	applyPendingChanges();
}

void StateStack::pushState(States::ID stateID)
{
	mPendingList.push_back(PendingChange(Push, stateID));
}

void StateStack::popState()
{
	mPendingList.push_back(PendingChange(Pop));
}

void StateStack::clearStates()
{
	mPendingList.push_back(PendingChange(Clear));
}

bool StateStack::isEmpty() const
{
	return mStack.empty();
}



void StateStack::applyPendingChanges()
{
	for (PendingChange &change : mPendingList) {
		switch (change.action)
		{
		case Push:
			mStack.push_back(creatState(change.stateID));
			break;
		case Pop:
			mStack.pop_back();
			break;
		case Clear:
			mStack.clear();
			break;
		default:
			break;
		}
	}
	mPendingList.clear();
}


State::Ptr StateStack::creatState(States::ID stateID)
{
	auto it = mFactories.find(stateID);
	assert(it != mFactories.end());
	return it->second();
}

StateStack::PendingChange::PendingChange(Action action, States::ID stateID):
	action(action),stateID(stateID)
{
}
