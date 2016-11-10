#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include<cstdio>
#include<SDL.h>


class InputHandler
{
    public:
        InputHandler();
        virtual ~InputHandler();
        int handle_events();
        int GetMouseX();
        int GetMouseY();
        static InputHandler*Instance();
    protected:
    private:
        int mouseX;
        int mouseY;
        static InputHandler*_instance;
};

#endif // INPUTHANDLER_H
