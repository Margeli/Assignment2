#include "j1FlyingEnemie.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1Enemies.h"

j1FlyingEnemie::j1FlyingEnemie(int x, int y) : j1Enemy(x, y)
{
	
	sprite_path = App->tex->Load("textures/Fly.png");
	//----------NEED TO PUT ON XML animations.xml

	fly_right.PushBack({ 0, 0, 47, 65 });
	fly_right.PushBack({ 53, 0, 50, 65 });
	fly_right.PushBack({ 107, 0, 55, 65 });
	fly_right.PushBack({ 167, 0, 59, 65 });
	fly_right.PushBack({ 107, 0, 55, 65 });
	fly_right.PushBack({ 53, 0, 50, 65 });
	fly_right.loop = true;
	fly_right.speed = 0.2f;

	fly_left.PushBack({ 0, 69, 60, 60 });
	fly_left.PushBack({ 63, 69, 60, 60 });
	fly_left.PushBack({ 123, 69, 50, 60 });
	fly_left.PushBack({ 180, 69, 50, 60 });
	fly_left.PushBack({ 123, 69, 50, 60 });
	fly_left.PushBack({ 63, 69, 60, 60 });
	fly_left.loop = true;
	fly_left.speed = 0.2f;


	collider = App->collis->AddCollider({ position.x, position.y, 50, 60 }, COLLIDER_ENEMIE, (j1Module*)App->enemies);

	animation = &fly_left;
}

// Should have the initial pos of enemies in a XML

void j1FlyingEnemie::Move()
{
	//IA
	//Pathfinding applied to platformers.

	
	collider->SetPos(position.x, position.y + 5);
}

void j1FlyingEnemie::OnCollision(Collider* c1, int num_enemy)
{

}


