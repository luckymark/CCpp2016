#include "Pickup.hpp"
#include "Aircraft.hpp"
#include "DataTables.hpp"
#include "Stringhelper.hpp"

#include <vector>

namespace
{
	const std::vector<PickupData> Table = initializePickupData();
}
Pickup::Pickup(Type type, const TextureHolder & textures) :mType(type), Entity(1), mSprite(textures.get(Table[type].textureID))
{
	setCenterOrigin(mSprite);
}

unsigned int Pickup::getCategory() const
{
	return Category::Pickup;
}

sf::FloatRect Pickup::getBoundingRect() const
{
	return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}

void Pickup::apply(Aircraft & player) const
{
	Table[mType].action(player);
}

void Pickup::drawCurrent(sf::RenderTarget & target, sf::RenderStates status) const
{
	target.draw(mSprite, status);
}
