#pragma once
namespace Category {
	enum Type {
		None = 0,
		Scene = 1 << 0,
		PlayerAircraft = 1 << 1,
		EnemyAircraft = 1 << 2,
		EnemyProjectile = 1 << 3,
		AlliedProjectile = 1 << 4,
		Pickup = 1 << 5,
		Aircraft = PlayerAircraft | EnemyAircraft,
		Projectile = EnemyProjectile | AlliedProjectile,
	};
}