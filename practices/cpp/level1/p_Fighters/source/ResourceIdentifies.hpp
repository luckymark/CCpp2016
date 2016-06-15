#pragma once

namespace Textures {
	enum ID{
		tBackground,
		tMyAircraft,
		tDesert,
		tLandscape,
		tAirplane,
		tTitleScreen,
		tButtonNormal,
		tButtonSelected,
		tButtonPressed,
		tAlliedBullet,
		tEnemyBullet,
		tMissile,
		tHealthRefill,
		tMissileRefill,
		tFireRate,
		tFireSpread,
	};
}

namespace Fonts {
	enum ID {
		fMain,
	};
}
typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;