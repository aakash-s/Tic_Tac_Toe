#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<map>
#include<cstdio>
#include<iostream>

using namespace std;

class TextureManager
{
    public:
        TextureManager();
        virtual ~TextureManager();
        bool load(std::string filename,std::string ID,SDL_Renderer*);
        void draw(std::string ID,int x,int y,int width,int height,SDL_Renderer*,SDL_RendererFlip flip = SDL_FLIP_NONE);
        void drawFrame(std::string ID,int x,int y,int width,int height,int currentRow,int currentFrame,
                       SDL_Renderer*,SDL_RendererFlip = SDL_FLIP_NONE);
        static TextureManager*Instance();
        std::map<std::string,SDL_Texture*>texture_Map;
    protected:
    private:
        static TextureManager* _instance;

};

#endif // TEXTUREMANAGER_H
