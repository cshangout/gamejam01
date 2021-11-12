#pragma once
#include "open_gl_graphics.h"
#include <hangout_engine/rendering/shader.h>

namespace HE {
    class OpenGLShader : public Shader {
    public:
        void Bind() override;
        void Compile(const std::string& vertexSource, const std::string& fragmentSource) override;

        void UniformMat4(const std::string& name, const glm::mat4& matrix) override;

    private:
        uint32_t _program = 0;
    };
}

