#pragma once
#include <hangout_engine/rendering/renderer.h>
#include <glm/vec4.hpp>

namespace HE {
    class OpenGLRenderer : public Renderer {
    public:
        void Init(RendererSettings settings) override;

        void Shutdown() override;

        void BeginFrame(glm::vec4 clearColor) override;
        void EndFrame() override;
    };
}
