
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"

using namespace std;

int main(int argv, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

    RenderWindow window("GAME v1.0", 1280, 720);

    SDL_Texture* grassTexture = window.loadTexture("res/grass.png");
    SDL_Texture* slimeTexture = window.loadTexture("res/slime.png");

    std::vector<Entity> entities = {
        Entity(Vector2f(400,400),grassTexture),
        Entity(Vector2f(500,500),slimeTexture)
    };

    bool gameRunning = true;

    SDL_Event event;

    while (gameRunning)
    {
        // Get our controls and events
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }
        window.clear();
        for(Entity& e: entities)
        {
            window.render(e);
        }

        std::cout << utils::hireTimeInSeconds() << std::endl;

        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}