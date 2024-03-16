#include "App.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
App::App(const char* title, int w, int h)
{
	printf("\nGXE VERSION JELLYFISH");
	al_init();
	al_install_keyboard();
	al_install_mouse();
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	al_install_audio();
	al_init_acodec_addon();


	display = al_create_display(w,h);
	al_set_window_title(display, title);
	queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);
	voice = al_create_voice(44100, ALLEGRO_AUDIO_DEPTH_INT16, ALLEGRO_CHANNEL_CONF_2);
	mixer = al_create_mixer(44100, ALLEGRO_AUDIO_DEPTH_FLOAT32, ALLEGRO_CHANNEL_CONF_2);
	al_attach_mixer_to_voice(mixer, voice);
	al_set_default_mixer(mixer);
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
}


App::~App()
{
	printf("\nExiting...");
	al_destroy_display(display);
	display = NULL;
	al_destroy_timer(timer);
	timer = NULL;
	al_destroy_event_queue(queue);
	queue = NULL;
	al_detach_mixer(mixer);
	al_destroy_mixer(mixer);
	mixer = NULL;
	al_destroy_voice(voice);
	voice = NULL;
	al_uninstall_audio();
	al_uninstall_keyboard();
	al_uninstall_mouse();
	
}