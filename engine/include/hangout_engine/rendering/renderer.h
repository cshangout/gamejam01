#pragma once
#include <glm/glm.hpp>
#include <memory>

#include "buffer.h"
#include "camera.h"
#include "shader.h"
#include "vertex_array.h"
#include "renderer_api.h"
#include "render_command.h"

namespace HE {
    struct RendererSettings {
        void* context;
    };

    class Renderer {
    public:
        virtual ~Renderer() = default;
        virtual void Init(RendererSettings) = 0;
        virtual void Shutdown() = 0;

        // TODO: Scene settings. Camera, lights, environment
        virtual void BeginScene(Camera& camera) = 0;
        virtual void Submit(const std::shared_ptr<Shader>&, const std::shared_ptr<VertexArray>&) = 0;
        virtual void EndScene() = 0;

        virtual std::shared_ptr<VertexBuffer> CreateVertexBuffer() = 0;
        virtual std::shared_ptr<IndexBuffer> CreateIndexBuffer() = 0;
        virtual std::shared_ptr<Shader> CreateShader() = 0;
        virtual std::shared_ptr<VertexArray> CreateVertexArray() = 0;

        virtual RenderCommand GetRenderCommand() = 0;
    };
}