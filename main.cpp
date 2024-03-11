#define SOL_ALL_SAFETIES_ON 1
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
#include "engine/Transform.h"
#include "engine/Keyboard.h"
#include "engine/Rect.h"
#include "engine/Image.h"
#include "engine/Viewport.h"
#include "engine/Camera.h"
#include <fstream>
#include <assert.h>
#include <iostream>

inline bool exists_test (const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

int main(int argc, char* args[])
{
    float currentTime = 0;
    float deltaTime = 0;
    float lastUpdate = 0;
    int width = 640;
    int height = 480;
    std::string title = "GXE JellyFish";
    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::coroutine, sol::lib::string, sol::lib::io, sol::lib::math, sol::lib::table, sol::lib::debug, sol::lib::package, sol::lib::os); 
    std::string x = lua["package"]["path"];
    std::string xx = lua["package"]["cpath"];
    lua["package"]["path"] = x + ";./?.lua";  
    lua["package"]["cpath"] = xx + ";./?.dll;./?.dylib";  
    lua.new_usertype<Graphics>("GXE_Graphics",
        //TODO: Make sprite and geometric drawing (should be easy *foreshadowing maybe*)
        "ClearScreen", &Graphics::clearScreen,
        "DrawCircle", &Graphics::drawCircle,
        "DrawRect", &Graphics::drawRect,
        //Holy ducking sit i could of just passed a refrence to the font object this whole time!?!?
        "DrawText", &Graphics::drawText,
        "DrawFancyText", &Graphics::drawFancyText,

        "DrawImage", &Graphics::drawImage,
        "DrawRotatedImage", &Graphics::drawRotatedImage,

        "PauseDraw", &Graphics::pauseDraw,

        "SetView", &Graphics::setViewport,
        "RestoreView", &Graphics::restoreViewport,
        "DrawView", &Graphics::drawView
    );
    lua.new_usertype<Transform>("GXE_Transform",
        sol::constructors<Transform()>(),
        "Push", &Transform::pushTrans,
        "Pop", &Transform::popTrans,
        "Translate", &Transform::translate,
        "Scale", &Transform::scale
    );
    lua.new_usertype<Viewport>("GXE_View",
        sol::constructors<Viewport(Rect)>()
    );
    lua.new_usertype<Camera>("GXE_Camera",
        sol::constructors<Camera(float, float)>(),
        "pos",&Camera::space,
        "zoom",&Camera::zoom,
        "Mount",&Camera::mount,
        "Unmount",&Camera::unmount,
        "CenterTarget",&Camera::centerOnTarget
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
        sol::constructors<Font(),Font(std::string,int)>()
    );
    lua.new_usertype<Image>("GXE_Image",
        sol::constructors<Image(std::string)>(),
        "crop", &Image::crop,
        "source", &Image::source
    );
    lua.new_usertype<Rect>("GXE_Rect",
        sol::constructors<Rect(float, float, float, float),Rect(float, float)>(),
        "x", &Rect::x,
        "y", &Rect::y,
        "w", &Rect::w,
        "h", &Rect::h,
        "CheckAABB", &Rect::checkCollision,
        "MoveAndDetect", &Rect::obstacleCollision/*,
        "MoveAndSeperate", &Rect::obstacleSolidCollision*/
    );
    lua.new_usertype<Keyboard>("GXE_Input",
        "KeyDown", &Keyboard::isKeyDown,
        "KeyJustPress", &Keyboard::isKeyJustPress,
        "mouse", sol::var(Keyboard::mouse),
        //Key constants
        "KEY_UP", sol::var(Keyboard::KEY_UP),
        "KEY_DOWN", sol::var(Keyboard::KEY_DOWN),
        "KEY_LEFT", sol::var(Keyboard::KEY_LEFT),
        "KEY_RIGHT", sol::var(Keyboard::KEY_RIGHT)
    );
    if (!(args[1] == NULL))
    {
        std::string fn = args[1];
        if(fn.substr(fn.find_last_of(".") + 1) == "lua")
        {   
            if (exists_test(fn))
            {
                lua.script_file(fn);
            }else
            {
                printf("\nfile does not exist");
                return 0;
            }
            
        }else
        {
            printf("\nNot a lua file (should have .lua extention)");
            return 0;
        }
        
    }else
    {
        std::string fn = "main.lua";
        
            if (exists_test(fn))
            {
                lua.script_file(fn);

            }else
            {
                printf("\nfile does not exist");
                return 0;
            }
    }
    

    //lua.script_file("main.lua");

    sol::optional<float> widthDef = lua["config"]["width"];
    sol::optional<float> heightDef = lua["config"]["height"];
    sol::optional<std::string> titleDef = lua["config"]["title"];
    if(widthDef == sol::nullopt)
    {
        printf("\nNo width specified... using default");
    }else
    {
        width = lua["config"]["width"];
    }
    if(heightDef == sol::nullopt)
    {
        printf("\nNo height specified... using default");
        
    }else
    {
        height = lua["config"]["height"];
    }

    if(titleDef == sol::nullopt)
    {
        printf("\nNo title specified... using default");
        
    }else
    {
        title = lua["config"]["title"];
    }

    App app(title.c_str(), width, height);



    sol::optional<sol::function> initDef = lua["init"];
    if(initDef == sol::nullopt)
    {
        printf("\nNo init function... closing");
        return 0;

    }

    //Check Update functions

    sol::optional<sol::function> updateDef = lua["update"];
    if(updateDef == sol::nullopt)
    {
        printf("\nNo update function... closing");
        
        return 0;

    }
    sol::optional<sol::function> drawDef = lua["draw"];
    if(drawDef == sol::nullopt)
    {
        printf("\nNo draw function... closing");
        
        return 0;

    }

    al_store_state(&Graphics::previous_state, ALLEGRO_STATE_TARGET_BITMAP);

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
        case ALLEGRO_EVENT_KEY_DOWN:

            Keyboard::keys[event.keyboard.keycode] = true;
            break;
        case ALLEGRO_EVENT_KEY_UP:

            Keyboard::keys[event.keyboard.keycode] = false;

            break;
        case ALLEGRO_EVENT_MOUSE_AXES:
            Keyboard::mouse.x= event.mouse.x;
            Keyboard::mouse.y= event.mouse.y;
            lua["GXE_Input"]["mouse"]["x"] = event.mouse.x;
            lua["GXE_Input"]["mouse"]["y"] = event.mouse.y;
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
