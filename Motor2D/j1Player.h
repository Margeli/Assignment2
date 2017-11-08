#ifndef __j1PLAYER_H__
#define __j1PLAYER_H__

#include "j1Module.h"
#include "p2Point.h"
#include "j1Animation.h"
#include "j1Collisions.h"

struct SDL_Texture;

class j1Player : public j1Module
{
public:

	j1Player();

	virtual ~j1Player();

	bool Awake(pugi::xml_node& conf);

	bool Start();

	bool Update(float dt);

	bool CleanUp();

	void OnCollision(Collider* c1, Collider* c2);

	void Dead();

	void LoseOneLife(iPoint respawn_pos);

private:

	float jump_limit;
	float jump_pos;
	float jump_speed;	
	bool walking = false;
	bool landing = false;
	bool can_jump = false;
	bool jumping = false;
	bool double_jump = true;
	void JumpReset();

	uint jump_sound;
	uint sword_sound;
	uint playersteps;

	uint lose_fx;
	uint hurt_fx;
	
	void LoadPlayerAnimations();

public:

	uint die_fx;
	bool camera_movement = false;
	float speed;
	int lifes;
	int points;

	bool dead = false;
	bool hit = false;
	bool player_hurted = false;
	Uint32 hit_time;
	
	int max_score = 0;

	iPoint position;


	bool Load(pugi::xml_node&);
	bool Save(pugi::xml_node&) const;

	SDL_Texture* graphics = nullptr;

	Animation* current_animation = nullptr;
	Animation idle;
	Animation walk;
	Animation jump;
	Animation run;
	Animation attack_right;
	Animation death_right;

	Animation idleleft;
	Animation walkleft;
	Animation jumpleft;
	Animation runleft;
	Animation attack_left;
	Animation death_left;

	Collider * playercoll;
};


#endif // __j1PLAYER_H__