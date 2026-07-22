#include <SDL3/SDL.h>
#include <SDL3/SDL_audio.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_render.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <stdlib.h>
#include <iostream>
#include "miku.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Surface* surface;
SDL_Texture* texture;
SDL_FRect rect;
MIX_Mixer* mixer;

#define WIDTH 1280
#define HEIGHT 720

int initializeMiku() {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != true)
        {
                std::cerr << "SDL_Init failed: " << SDL_GetError() << "\n";
                return EXIT_FAILURE;
        }

        if (MIX_Init() != true) {
                std::cerr << "MIX_Init failed: " << SDL_GetError() << "\n";
                return EXIT_FAILURE;
        }

        mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);

        if (!mixer) {
                std::cerr << "Failed to load sound: " << SDL_GetError() << "\n";
                return EXIT_FAILURE;
        }

        MIX_Audio* music = MIX_LoadAudio(mixer, "song.ogx", false);
        MIX_Track* track = MIX_CreateTrack(mixer);
        MIX_SetTrackAudio(track, music);
        
        //surface = SDL_CreateSurface();
        window = SDL_CreateWindow(
                        "mikumiku.miku",
                        WIDTH,
                        HEIGHT,
                        SDL_WINDOW_MAXIMIZED
        );
        if (!window)
        {
                std::cerr << "Window creation failed: " << SDL_GetError() << "\n";
                return EXIT_FAILURE;
        }

        renderer = SDL_CreateRenderer(window, nullptr);
        if (!renderer)
        {
                std::cerr << "Renderer creation failed: " << SDL_GetError() << "\n";
                return EXIT_FAILURE;
        }

        surface = IMG_Load("miku.png");
        if (!surface)
        {
                std::cerr << "Failed to load image: " << SDL_GetError() << "\n";
                return EXIT_FAILURE;
        }

        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (!texture)
        {
                std::cerr << "Failed to load texture: " << SDL_GetError() << "\n";
                return EXIT_FAILURE;
        }

        rect.x = 100;
        rect.y = 100;
        rect.w = 100;
        rect.h = 100;
        float velocityX = 2.0f;
        float velocityY = 2.0f;
        MIX_PlayTrack(track, 0);
        
        bool running = true;
        while (running) {
                SDL_Event event;
                while (SDL_PollEvent(&event))
                {
                        if (event.type == SDL_EVENT_QUIT)
                        {
                                running = false;
                        }
                }

                rect.x += velocityX;
                rect.y += velocityY;

                if (rect.x + rect.w >= WIDTH || rect.x <= 0)
                {
                        velocityX = -velocityX;
                        rect.x = SDL_clamp(rect.x, 0, WIDTH - rect.w);
                }

                if (rect.y + rect.h >= HEIGHT || rect.y <= 0)
                {
                        velocityY = -velocityY;
                        rect.y = SDL_clamp(rect.y, 0, HEIGHT - rect.h);
                }
                SDL_Delay(1000 / 60); // Allow setting custom framerate
                SDL_RenderClear(renderer);
                SDL_RenderTexture(renderer, texture, nullptr, &rect);
                SDL_RenderPresent(renderer);
        }
        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);
        SDL_DestroySurface(surface);
        MIX_DestroyAudio(music);
        MIX_DestroyTrack(track);
        MIX_DestroyMixer(mixer);
        MIX_Quit();
        SDL_Quit();
        return EXIT_SUCCESS;
}
