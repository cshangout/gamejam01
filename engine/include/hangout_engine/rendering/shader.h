#pragma once
#include <hangout_engine/platform/filesystem.h>

#include <fstream>
#include <glm/glm.hpp>
#include <iostream>
#include <sstream>
#include <string>

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
        virtual void LoadAndCompile(std::filesystem::path&& vertexPath, std::filesystem::path&& fragmentPath)  {

            std::string vertexCode;
            std::string fragmentCode;

            Path vertexAssetPath = Filesystem::GetAssetPath() /= vertexPath;
            Path fragmentAssetPath = Filesystem::GetAssetPath() /= fragmentPath;

            std::ifstream vShaderFile;
            std::ifstream fShaderFile;

            vShaderFile.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
            fShaderFile.exceptions ( std::ifstream::failbit | std::ifstream::badbit );

            try {
                vShaderFile.open(vertexAssetPath);
                fShaderFile.open(fragmentAssetPath);
                std::stringstream vShaderStream, fShaderStream;

                //read file's buffer contents into streams
                vShaderStream << vShaderFile.rdbuf();
                fShaderStream << fShaderFile.rdbuf();

                // close handlers
                vShaderFile.close();
                fShaderFile.close();

                vertexCode = vShaderStream.str();
                vertexCode.insert(0, std::string(HE_SHADER_VERSION_STRING) + "\n");
                fragmentCode = fShaderStream.str();
                fragmentCode.insert(0, std::string(HE_SHADER_VERSION_STRING) + "\n");

            } catch (const std::ifstream::failure& e) {
                std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: " << e.what() << std::endl;
            }

            Compile(vertexCode, fragmentCode);
        }

        // Uniforms
        virtual void Boolean(const std::string& name, bool value) const = 0;
        virtual void Int(const std::string& name, int value) const = 0;
        virtual void Float(const std::string& name, float value) const = 0;
        virtual void UniformMat4(const std::string&, const glm::mat4&) const = 0;
    protected:
    private:

    };
}