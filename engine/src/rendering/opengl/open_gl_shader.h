#pragma once
#include "open_gl_graphics.h"
#include <hangout_engine/rendering/shader.h>

namespace HE {
    class OpenGLShader : public Shader {
    public:
        void Bind() override;

        void Compile(const std::string& vertexSource, const std::string& fragmentSource) override;

    private:
        void bindVertexAttributes();
        uint32_t _program = 0;
    };
}

