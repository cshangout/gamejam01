//
// Created by Paul Mauviel on 2021-11-08.
//
#include "open_gl_renderer.h"

#include <hangout_engine/service_locator.h>

#include <SDL_opengl.h>

#if defined(__EMSCRIPTEN__)
#include <emscripten.h>
#include <GLES3/gl3.h>
#else
#endif

namespace HE {
    void OpenGLRenderer::Init(RendererSettings settings) {
        if (ServiceLocator::GetWindow()) {
            ServiceLocator::GetWindow()->MakeContextCurrent();
        }
    }

    void OpenGLRenderer::Shutdown() {

    }

    void OpenGLRenderer::BeginFrame(glm::vec4 clearColor) {
        glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLRenderer::EndFrame() {
        if (ServiceLocator::GetWindow()) {
            ServiceLocator::GetWindow()->SwapBuffer();
        }
    }
}