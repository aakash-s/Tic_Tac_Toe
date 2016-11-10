#include "TextureManager.h"

TextureManager::TextureManager()
{
    //ctor
}

TextureManager::~TextureManager()
{
    //dtor
}

TextureManager*TextureManager:: _instance = 0;


/// Function to take the filename of the image to be loaded and load the image and store it into the map referenced by ID ///
bool TextureManager::load(std::string filename,std::string ID,SDL_Renderer*renderer)
{

    bool success = true;
    SDL_Surface* tempSurface = IMG_Load(filename.c_str());
    if(tempSurface == NULL){
        printf("Failed to load Image SDL_Error: %s\n",SDL_GetError());
        success = false;
        return success;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,tempSurface);
    SDL_FreeSurface(tempSurface);
    if(texture != 0){
        texture_Map[ID] = texture;
        success = true;
        return success;
    }
    return false;
}


/// Function to take the ID of the map , take the required coordinates and draw the image using ID to the renderer ///
void TextureManager::draw(std::string ID,int x,int y,int width,int height,SDL_Renderer*renderer,SDL_RendererFlip flip)
{
    SDL_Rect sourceRect;
    SDL_Rect destRect;
    sourceRect.x = sourceRect.y = 0;
    destRect.x = x;
    destRect.y = y;
    sourceRect.w = sourceRect.h = 640;
    destRect.w = width;
    destRect.h = height;
    if( SDL_RenderCopyEx(renderer,texture_Map[ID],&sourceRect,&destRect,0,0,flip) != 0){
        printf("Could not load %s\n",SDL_GetError());
    }
}

TextureManager*TextureManager::Instance()
{
    if(_instance == 0 ){
        _instance = new TextureManager();
    }
    return _instance;
}

void TextureManager::drawFrame(std::string ID,int x,int y,int width,int height,int currentRow,int currentFrame,
                       SDL_Renderer*,SDL_RendererFlip flip)
{
    /// This function will be used to crete animated frames
}
