#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "Game.h"
#include "../include/sol.hpp"
#pragma once
class App
{
public:
	App(const char* title, int w, int h);
	~App();

	ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_TIMER* timer;
    ALLEGRO_COLOR bg;

    ALLEGRO_MIXER *mixer;
    ALLEGRO_VOICE *voice;


private:
	

    float lastUpdate;
        float deltaTime;
        float currentTime;

	
};