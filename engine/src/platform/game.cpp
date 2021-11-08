#include <hangout_engine/platform/game.h>
#include <hangout_engine/service_locator.h>
#include <rendering/open_gl_renderer.h>
#include "sdl_window.h"

namespace HE {
    Game::Game() : Game("New CS Hangouts Game Engine") {}

    Game::Game(std::string windowTitle) : _title(std::move(windowTitle)), _running(false) {
        initializeServices();
    }

    Game::~Game() {
        shutdownServices();
    }

    void Game::Run() {
        _running = true;

        while (_running) {
            // If the X button was clicked, exit
            if (ServiceLocator::GetWindow()->Update()) {
                _running = false;
                continue;
            }
            ServiceLocator::GetRenderer()->BeginFrame(_clearColor);

            PhysicsUpdate(0.0f);
            Update(0.0f);

            Render();

            ServiceLocator::GetRenderer()->EndFrame();
        }
    }

    void Game::initializeServices() {
        ServiceLocator::Provide(new SDLWindow());
        ServiceLocator::GetWindow()->OpenWindow({
            .title = _title,
            .width = 800,
            .height = 600
        });

        ServiceLocator::Provide(new OpenGLRenderer());
    }

    void Game::shutdownServices() {}
}