
#include <stdio.h>
#include <string>
#include <vector>
#include <allegro5/allegro_font.h>
#include "include/sol.hpp"
#include "engine/App.h"
#include "engine/Game.h"
#include "engine/Graphics.h"
#include "engine/Color.h"
#include "engine/Font.h"
int main(int argc, char* args[])
{
    float currentTime = 0;
    float deltaTime = 0;
    float lastUpdate = 0;
    int width = 640;
    int height = 480;
    std::string title = "GXE JellyFish";
    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::coroutine, sol::lib::string, sol::lib::io, sol::lib::math, sol::lib::table);   
    lua.new_usertype<Graphics>("GXE_Graphics",
        //TODO: Make sprite and geometric drawing (should be easy *foreshadowing maybe*)
        "ClearScreen", &Graphics::clearScreen
    );
    lua.new_usertype<Color>("GXE_Color",
        sol::constructors<Color(float,float,float,float)>(),
        "r", &Color::r,
        "g", &Color::g,
        "b", &Color::b,
        "a", &Color::a,
        "EyeStrainBlue", sol::var(Color::EyeStrainBlue),
        "MonogameBlue",  sol::var(Color::MonogameBlue),
        "BloodShotRed",  sol::var(Color::BloodShotRed),
        "ReallyGreen",   sol::var(Color::ReallyGreen)
    );
    lua.new_usertype<Font>("GXE_Font",
        //kinda inconsistent as every other drawing function is in the GXE_Graphics class but it works 
        sol::constructors<Font(),Font(std::string,int)>(),
        "DrawText", &Font::Draw
    );

    lua.script_file("main.lua");

    sol::optional<float> widthDef = lua["config"]["width"];
    sol::optional<float> heightDef = lua["config"]["height"];
    sol::optional<std::string> titleDef = lua["config"]["title"];
    if(widthDef == sol::nullopt)
    {
        printf("No width specified... using default");
    }else
    {
        width = lua["config"]["width"];
    }
    if(heightDef == sol::nullopt)
    {
        printf("No height specified... using default");
        
    }else
    {
        height = lua["config"]["height"];
    }

    if(titleDef == sol::nullopt)
    {
        printf("No title specified... using default");
        
    }else
    {
        title = lua["config"]["title"];
    }

    App app(title.c_str(), width, height);



    sol::optional<sol::function> initDef = lua["init"];
    if(initDef == sol::nullopt)
    {
        printf("No init function... closing");
        return 0;

    }

    //Check Update functions

    sol::optional<sol::function> updateDef = lua["update"];
    if(updateDef == sol::nullopt)
    {
        printf("No update function... closing");
        
        return 0;

    }
    sol::optional<sol::function> drawDef = lua["draw"];
    if(drawDef == sol::nullopt)
    {
        printf("No draw function... closing");
        
        return 0;

    }

    ALLEGRO_EVENT event;
    al_start_timer(app.timer);

    bool done = false;
    bool redraw = true;
    lua["init"]();
    while(1) {
        al_wait_for_event(app.queue, &event);

        switch(event.type) {
        case ALLEGRO_EVENT_TIMER:
            lua["update"](deltaTime);
            redraw = true;
            currentTime = al_get_time();
            deltaTime = currentTime - lastUpdate;
            lastUpdate = currentTime;
            
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;


        }

        if(done){
            break;
        }



        if(redraw && al_is_event_queue_empty(app.queue))
        {


            
            lua["draw"]();

            al_flip_display();

            redraw = false;
        }
    }

    

    
    return 0;
}
