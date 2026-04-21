#ifndef __SDL_MANAGER_HPP__
#define __SDL_MANAGER_HPP__
#include <SDL3/SDL.h>
// #include <SDL3/SDL_opengl.h>
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#include <string>
#include <iostream>
#include "ImGui/imgui.h"
#include "ImGui/backends/imgui_impl_sdl3.h"
#include "ImGui/backends/imgui_impl_opengl3.h"
#include <SDL3_ttf/SDL_ttf.h>

const int MAX_WINDOWS = 20;
class SDL_Manager {
    private:
        SDL_Surface *buffers[MAX_WINDOWS];
        SDL_Window *windows[MAX_WINDOWS];
        bool update[MAX_WINDOWS];
        SDL_GLContext context;
        TTF_Font* font;
        size_t count;
        SDL_Manager();
        ~SDL_Manager();
        
        SDL_Manager(const SDL_Manager&) = delete;
        SDL_Manager& operator=(const SDL_Manager&) = delete;
    
    public:
        static SDL_Manager& sdl();
        void spawnWindow(const std::string, int, int, bool);
        void updateWindows(int);
        void closeWindow(std::uint32_t);
        void drawPiano(int);
        void renderUI(const std::string&, const std::string&, int);
};

#endif