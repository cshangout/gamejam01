#include "open_gl_shader.h"
#include <iostream>
#include <hangout_engine/rendering/types.h>
#include <glm/gtc/type_ptr.hpp>

namespace HE {
    void OpenGLShader::Bind() {
        // TODO: Vertex type is hardcoded here, we probably want to make it more generic to make a more flexible interface
        glUseProgram(_program);
    }

    void OpenGLShader::Compile(const std::string& vertexCode, const std::string& fragmentCode) {
        uint32_t vertex, fragment;

        int success;
        char infoLog[512];

        // Vertex Shader
        const char* vShaderCode = vertexCode.c_str();
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, nullptr);
        glCompileShader(vertex);
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        const char* fShaderCode = fragmentCode.c_str();
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, nullptr);
        glCompileShader(fragment);
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
        if (!fragment) {
            glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        _program = glCreateProgram();
        glAttachShader(_program, vertex);
        glAttachShader(_program, fragment);
        glLinkProgram(_program);

        glGetProgramiv(_program, GL_LINK_STATUS, &success);

        if (!success) {
            glGetProgramInfoLog(_program, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::LINKING FAILED\n" << infoLog << std::endl;
        }

        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    void OpenGLShader::Boolean(const std::string &name, bool value) const {
        GLint location = getShaderLocation(name);

        glUniform1i(location, static_cast<int>(value));
    }

    void OpenGLShader::Int(const std::string &name, int value) const {
        GLint location = getShaderLocation(name);

        glUniform1i(location, value);
    }

    void OpenGLShader::Float(const std::string &name, float value) const {
        GLint location = getShaderLocation(name);

        glUniform1f(location, value);
    }

    void OpenGLShader::UniformMat4(const std::string& name, const glm::mat4 &matrix) const {
        GLint location = getShaderLocation(name);

        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    GLint OpenGLShader::getShaderLocation(const std::string &name) const {
        return glGetUniformLocation(_program, name.c_str());
    }

}
