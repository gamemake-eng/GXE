#include <allegro5/allegro.h>
#pragma once
class Game
{
public:
	Game();
	~Game();

    virtual void Load();
    virtual void Update();
    virtual void Draw();

    Game* getSelf();

private:
	

	
};