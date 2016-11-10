#include "InputHandler.h"


InputHandler*InputHandler::_instance = 0;

InputHandler::InputHandler()
{
    //ctor
}

InputHandler::~InputHandler()
{
    //dtor
}

int InputHandler::handle_events()
{

    /// 1 indicates that user needs to quit the window
    /// 2 indicates MOUSE PRESSED
    /// 3 indicates SPACEBAR
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0){

        if(event.type == SDL_QUIT)return 1;
        if(event.type == SDL_MOUSEBUTTONDOWN){
            if(event.button.button == SDL_BUTTON_LEFT){
                    mouseX = event.motion.x;
                    mouseY = event.motion.y;
                    return 2;
                    }
        }
        const Uint8* keystates;
        keystates = SDL_GetKeyboardState(0);
        if(keystates[SDL_SCANCODE_SPACE] != 0)return 3;

    }

}


int InputHandler::GetMouseX()
{
    return mouseX;
}

int InputHandler::GetMouseY()
{
    return mouseY;
}

InputHandler*InputHandler::Instance()
{
    if(_instance == 0){
        _instance = new InputHandler();
    }
    return _instance;
}


