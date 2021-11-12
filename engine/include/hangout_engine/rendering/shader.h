#pragma once
#include <string>
#include <glm/glm.hpp>

#if !__EMSCRIPTEN__
#define HE_SHADER_VERSION_STRING "#version 330 core\n"
#else
#define HE_SHADER_VERSION_STRING "#version 300 es\n"
#endif

namespace HE {
    class Shader {
    public:
        virtual void Bind() = 0;
        virtual void Compile(const std::string& vertexSource, const std::string& fragmentSource) = 0;

        virtual void UniformMat4(const std::string&, const glm::mat4&) = 0;
    protected:
    private:

    };
}