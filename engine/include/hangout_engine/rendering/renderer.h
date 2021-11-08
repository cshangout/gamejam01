#pragma once
#include <glm/glm.hpp>

namespace HE {
    struct RendererSettings {
        void* context;
    };

    class Renderer {
    public:
        virtual ~Renderer() = default;
        virtual void Init(RendererSettings) = 0;
        virtual void Shutdown() = 0;
        virtual void BeginFrame(glm::vec4) = 0;
        virtual void EndFrame() = 0;

    };
}