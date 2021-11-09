#pragma once
#include <string>

namespace HE {
    class Shader {
    public:
        virtual void Bind() = 0;

        virtual void Compile(const std::string& vertexSource, const std::string& fragmentSource) = 0;

    protected:
    private:

    };
}