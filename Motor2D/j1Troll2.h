#ifndef __j1TROLL2_H__
#define __j1TROLL2_H__

#include "p2Point.h"
#include "j1Entity.h"
#include "j1Pathfinding.h"

class j1Entity;

class j1Troll2 : public j1Entity
{
public:

	j1Troll2(iPoint pos);

	void OnCollision(Collider* c1, Collider* c2);

	void LoadTrollAnimations();

	bool LoadTrollAudio();

public:

	bool IsPointInCircle(float playposX, float playposY, float enemposX, float enemposY, float radi) const;

	bool Start();

	bool Update(float dt);

	bool CleanUp();

	bool Load(pugi::xml_node&);
	bool Save(pugi::xml_node&) const;

	void Move(Pathfinding& _path, float dt);

	void troll_dead();
	bool dead = false;
	fPoint death_pos;

	Pathfinding* troll_path = nullptr;

	Animation idle_right;
	Animation walk_right;
	Animation jump_right;
	Animation attack_right;
	Animation death_right;
	Animation pause_right;

	Animation idle_left;
	Animation walk_left;
	Animation jump_left;
	Animation attack_left;
	Animation death_left;
	Animation pause_left;

	uint troll_death;
	uint troll_attack;

	Pathfinding* path = nullptr;
	MoveTo direction;

private:

};
#endif // __j1TROLL2_H__