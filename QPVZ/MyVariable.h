#pragma once

enum objectType { Plants, Zombies, Weapons, SunShine };
enum objectNames { Nosuchobject, PeaShooter, CommonZombie, SunFlower, WallNut, BucketHeadZombie, PoleVaultingZombie};
enum GameModeNames { Surface, Adventure, NetFight };

struct Node
{
	objectNames Zombie_Type;
	int timetoshow;
};


