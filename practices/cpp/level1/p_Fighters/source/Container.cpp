#include "Container.hpp"

GUI::Container::Container() :mSelectedChild(-1), mChildren() {

}

void GUI::Container::pack(Component::Ptr component)
{
	mChildren.push_back(component);
	if (!hasSelection() && component->isSelectable()) {
		select(mChildren.size() - 1);
	}
}

bool GUI::Container::isSelectable() const
{
	return false;
}

void GUI::Container::handleEvent(const sf::Event & event)
{
	if(hasSelection() && mChildren[mSelectedChild]->isActivate()){
		mChildren[mSelectedChild]->handleEvent(event);
	}
	else if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Up) {
			selectPrevious();
		}
		else if (event.key.code == sf::Keyboard::Down) {
			selectNext();
		}
		else if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space) {
			if (hasSelection()) {
				mChildren[mSelectedChild]->activate();
			}
		}
	}
}

void GUI::Container::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	for (auto &child : mChildren) {
		target.draw(*child);
	}
}

bool GUI::Container::hasSelection() const
{
	return mSelectedChild >= 0;
}

void GUI::Container::select(std::size_t index)
{
	if (mChildren[index]->isSelectable()) {
		if (hasSelection()) {
			mChildren[mSelectedChild]->deselect();
		}
		mChildren.at(index)->select();
		mSelectedChild = index;
	}
}

void GUI::Container::selectNext()
{
	if (!hasSelection())
		return;

	int next = mSelectedChild;
	do {
		next = (next + 1) % mChildren.size();
	} while (!mChildren[next]->isSelectable());
	select(next);
}

void GUI::Container::selectPrevious()
{
	if (!hasSelection())
		return;

	int next = mSelectedChild;
	do {
		next = (next - 1) % mChildren.size();
	} while (!mChildren[next]->isSelectable());
	select(next);
}

