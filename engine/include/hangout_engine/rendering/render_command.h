#pragma once

#include "renderer_api.h"
#include <memory>
#include "vertex_array.h"

namespace HE {
    class RenderCommand {
    public:
        RenderCommand(RendererAPI* renderer) : _rendererApi(renderer) {}

        inline void SetClearColor(const glm::vec4 &color) {
            _rendererApi->SetClearColor(color);
        }

        inline void Clear() {
            _rendererApi->Clear();
        }

        inline void DrawArray(const std::shared_ptr<VertexArray>& vertexArray) {
            _rendererApi->DrawArray(vertexArray);
        }

        inline void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) {
            _rendererApi->DrawIndexed(vertexArray);
        }
    private:
        RendererAPI* _rendererApi = nullptr;
    };
}