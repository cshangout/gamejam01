//
// Created by Paul Mauviel on 2021-11-08.
//
#include "open_gl_renderer.h"

#include <hangout_engine/service_locator.h>
#include <SDL_video.h>
#include <hangout_engine/rendering/render_command.h>
#include "open_gl_graphics.h"
#include "open_gl_buffer.h"
#include "open_gl_shader.h"
#include "open_gl_vertex_array.h"

namespace HE {
    void OpenGLRenderer::Init(RendererSettings settings) {
        if (ServiceLocator::GetWindow()) {
            ServiceLocator::GetWindow()->MakeContextCurrent();
        }

#ifdef GLAD
        gladLoadGLES2Loader(SDL_GL_GetProcAddress);
#endif
        _rendererAPI = std::make_unique<OpenGLRendererAPI>();
    }

    void OpenGLRenderer::Shutdown() {

    }

    void OpenGLRenderer::BeginScene() {
    }

    void OpenGLRenderer::Submit(const std::shared_ptr<VertexArray>& vertexArray) {
        vertexArray->Bind();
        RenderCommand(_rendererAPI.get()).DrawIndexed(vertexArray);
    }

    void OpenGLRenderer::EndScene() {
        if (ServiceLocator::GetWindow()) {
            ServiceLocator::GetWindow()->SwapBuffer();
        }
    }

    std::shared_ptr<VertexBuffer> OpenGLRenderer::CreateVertexBuffer() {
        return std::make_shared<OpenGLVertexBuffer>();
    }

    std::shared_ptr<IndexBuffer> OpenGLRenderer::CreateIndexBuffer() {
        return std::make_shared<OpenGLIndexBuffer>();
    }

    std::shared_ptr<Shader> OpenGLRenderer::CreateShader() {
        return std::make_shared<OpenGLShader>();
    }

    std::shared_ptr<VertexArray> OpenGLRenderer::CreateVertexArray() {
        return std::make_shared<OpenGLVertexArray>();
    }

    RenderCommand OpenGLRenderer::GetRenderCommand() {
        return {_rendererAPI.get() };
    }

}