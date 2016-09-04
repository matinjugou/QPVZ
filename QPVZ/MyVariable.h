#pragma once

enum objectType { Plants, Zombies, CommonObjects, Weapons };
enum objectNames { PeaShooter, CommonZombie, SunShine };
enum GameModeNames { Surface, Adventure, NetFight };

struct Node
{
	objectNames Zombie_Type;
	int timetoshow;
};


