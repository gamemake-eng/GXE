#include "Game.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

Game::Game()
{

}
void Game::Load() 
{
	printf("Loading");
} 
void Game::Update() 
{
	printf("update");
}
void Game::Draw()
{
	printf("draw");
}

Game* Game::getSelf()
{
	return this;
}

Game::~Game()
{
	
}