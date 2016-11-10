#include "Game.h"

Game*Game::_instance = 0;

/// Constructor ///
Game::Game()
{
    run_status = false;
    window = NULL;
    renderer = NULL;
    x = -1;
    y = -1;
    emp = 9;
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::turn_off()
{
    run_status = false;
}

/// This function takes the attributes and creates a corresponding surface and a window ///
bool Game::init(const char*title,int xpos,int ypos,int width,int height,int flag = 0)
{
    for(int i = 0;i<9;i++)A[i] = -1;
    bool success = false;
    if( SDL_Init(SDL_INIT_VIDEO) < 0 ){
        printf("SDL could not be initialized. SDL_Error: %s\n",SDL_GetError());
        return success;
    }
    window = SDL_CreateWindow(title,xpos,ypos,width,height,SDL_WINDOW_SHOWN);
    if(window == NULL){
        printf("Window could not be initialized. SDL_Error: %s\n",SDL_GetError());
        return success;
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);
    if(renderer == NULL){
        printf("Renderer could not be initialized .SDL_Error: %s\n",SDL_GetError());
        success = false;
    }
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);

    success = true;
    run_status = true;
    emp = 9;
    x = -1; y = -1;
    return success;
}

/// Function to draw a grid ///
void Game::drawGrid()
{
    int x = 0;
    int y = 0;
    for(int i = 0;i < 4;i++){
    SDL_RenderDrawLine(renderer,x,y,x,600);
    x = x+200;
    }
    x = 0;
    for(int i = 0;i < 4;i++){
        SDL_RenderDrawLine(renderer,x,y,600,y);
        y = y+200;
    }
}
/// This function to make the class Game a singleton so that only a single instance will work throughout the project ///
Game*Game::Instance()
{
    if(_instance == 0){
        _instance = new Game();
    }
    return _instance;
}


/// Function to clean the winodow ///
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/// Function to and draw all the images to the renderer ///
void Game::texture()
{
   if(TextureManager::Instance()->load("assets/cross.png","cross",renderer) == false){
        printf("Could not load Cross SDL_Error: %s\n",SDL_GetError());
    }
    if(TextureManager::Instance()->load("assets/back.png","back",renderer) == false){
        printf("Could not load the texture SDL_Error: %s\n",SDL_GetError());
        return;
    }
     if(TextureManager::Instance()->load("assets/button.png","button",renderer) == false){
        printf("Could not load the texture SDL_Error: %s\n",SDL_GetError());
        return;
    }
    TextureManager::Instance()->draw("back",0,0,600,600,renderer);
    TextureManager::Instance()->draw("button",0,600,575,50,renderer);


    SDL_SetRenderDrawColor(renderer,0,0,0,255);

    drawGrid();
}

/// Function to get the renderer ///
SDL_Renderer* Game::getRenderer()
{
    return renderer;
}

/// Function to draw the renderer to the screen ///
void Game::render()
{

    SDL_RenderPresent(renderer);
}
/// Function to return the running status of the game ///
bool Game::_running()
{
    return run_status;
}

void Game::find_coordinates(int pos)
{
    if(pos == 0){
        x = 50;
        y = 50;
    }
    if(pos == 1){
        x = 250;
        y = 50;
    }
    if(pos == 2){
        x = 450;
        y = 50;
    }
    if(pos == 3){
        x = 50;
        y = 250;
    }
    if(pos == 4){
        x = 250;
        y = 250;
    }
    if(pos == 5){
        x = 450;
        y = 250;
    }
    if(pos == 6){
        x = 50;
        y = 450;
    }
    if(pos == 7){
        x = 250;
        y = 450;
    }
    if(pos == 8){
        x = 450;
        y = 450;
    }
}

void Game::drawCross(int x,int y)
{
    TextureManager::Instance()->draw("cross",x,y,100,100,renderer);
}

/// Function to handle mouse and keyboard events ///
int Game::handle()
{

    int result;
    result = InputHandler::Instance()->handle_events();

    if(result == 1)run_status = false;
    if(result == 2){
        int pos = find_pos(InputHandler::Instance()->GetMouseX(),InputHandler::Instance()->GetMouseY());

        if(A[pos] == -1 and pos > -1 and pos < 9){

        find_coordinates(pos);
        drawCross(x,y);
        }
    }
    if(result == 3){
         SDL_Quit();
         return 3;
    }
}

int Game::find_pos(int x,int y)
{
    int pos;
    /// Function to provide the position of the array corresponding to mouse coordinates
    if(x < 200 and x>0 and y<200 and y>0)pos = 0;
    if(x > 200 and x<400 and y<200 and y>0)pos = 1;
    if(x > 400 and x<600 and y<200 and y>0)pos = 2;
    if(x < 200 and x>0 and y>200 and y<400)pos = 3;
    if(x > 200 and x<400 and y>200 and y<400)pos = 4;
    if(x > 400 and x<600 and y>200 and y<400)pos = 5;
    if(x > 0 and x<200 and y>400 and y<600)pos = 6;
    if(x > 200 and x<400 and y>400 and y<600)pos = 7;
    if(x > 400 and x<600 and y>400 and y<600)pos = 8;
    return pos;
}
