#ifndef GAME_H
#define GAME_H
#include<SDL.h>
#include<cstdio>
#include"TextureManager.h"
#include"InputHandler.h"
#include<cstdio>

class Game
{
    public:
        Game();
        virtual ~Game();
        bool init(const char*title,int xpos,int ypos,int width,int height,int flag);
        void render();
        void clean();
        static Game*Instance();
        bool _running();
        void texture();
        SDL_Renderer* getRenderer();
        void drawGrid();
        int handle();
        int find_pos(int,int);
        void find_coordinates(int);
        void drawCross(int,int);
        void turn_off();
        int x,y;
        int emp;
        int A[9];
    protected:
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool run_status;
        static Game*_instance;

};

#endif // GAME_H
