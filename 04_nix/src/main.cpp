#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <spdlog/spdlog.h>
 
int main(int argc, char ** argv)
{    
    spdlog::set_level(spdlog::level::debug);
    bool quit = false;
    SDL_Event event;
 
    spdlog::info("Initializing SDL and SDL_ttf");
    SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
    TTF_Init();
 
    SDL_Window * window = SDL_CreateWindow("Hello C++ Serbia",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,
        600, 0);

    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Color white_color = {255, 255, 255};

    TTF_Font* sans_font = TTF_OpenFont("OpenSans-Regular.ttf", 24);
    SDL_Surface* message_surface =
    TTF_RenderText_Solid(sans_font, "Hello C++ Serbia", white_color); 

    SDL_Texture* message_texture = SDL_CreateTextureFromSurface(renderer, message_surface);
    SDL_Rect message_rect {.x = 200, .y = 250, .w = 400, .h = 100}; //create a rect

    spdlog::info("Enter main loop");
    while (!quit)
    {
        SDL_WaitEvent(&event);
 
        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
        }
        spdlog::debug("Rendering ...");
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, message_texture, NULL, &message_rect);
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }
    spdlog::info("Exit main loop");

    spdlog::info("Cleanup");
    TTF_CloseFont(sans_font);
    TTF_Quit();
    SDL_FreeSurface(message_surface);
    SDL_DestroyTexture(message_texture);
    SDL_DestroyRenderer(renderer);
    spdlog::info("Destroy window and quit");
    SDL_DestroyWindow(window);
    SDL_Quit();
 
    return 0;
}
