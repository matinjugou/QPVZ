#pragma once

enum objectType { Plants, Zombies, Weapons, SunShine };
enum objectNames { PeaShooter, CommonZombie, SunFlower, WallNut};
enum GameModeNames { Surface, Adventure, NetFight };

struct Node
{
	objectNames Zombie_Type;
	int timetoshow;
};


