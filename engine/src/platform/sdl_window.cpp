//
// Created by Paul Mauviel on 2021-11-08.
//

#include "sdl_window.h"

#include <iostream>
#include <cstddef>

namespace HE {
    bool SDLWindow::Update() {
        SDL_Event event;
        SDL_PollEvent(&event);

        // Do stuff with events
        if (event.type == SDL_QUIT) return true;

        return false;
    }

    std::pair<int, int> SDLWindow::GetWindowExtents() {
        int width, height;

        SDL_GL_GetDrawableSize(_window, &width, &height);

        return { width, height };
    }

    float SDLWindow::GetAspectRatio() {
        auto [width, height] = GetWindowExtents();
        return static_cast<float>(width) / static_cast<float>(height);
    }

    void SDLWindow::OpenWindow(WindowData data) {
#if __EMSCRIPTEN__
      _managed = true;
#endif

        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
            throw std::runtime_error("Failed to initialize SDL!");
        }

        auto width = data.width;
        auto height = data.height;

        // TODO: The renderer part (OpenGL) should be separated from the window creation.
        // This should be good enough for gamejam however.
        _window = SDL_CreateWindow(data.title.c_str(),
                                   SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                   width, height,
                                   SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);

#if !__EMSCRIPTEN__
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
#endif
        _context = SDL_GL_CreateContext(_window);
        MakeContextCurrent();
    }

    SDLWindow::~SDLWindow() {
        SDL_Quit();
    }

    void SDLWindow::MakeContextCurrent() {
        SDL_GL_MakeCurrent(_window, _context);
    }

    void SDLWindow::SwapBuffer() {
        SDL_GL_SwapWindow(_window);
    }

    void SDLWindow::SetManagedFunction(callback function) {
#if __EMSCRIPTEN__
        emscripten_set_main_loop(function, 0, 1);
#endif
    }


}