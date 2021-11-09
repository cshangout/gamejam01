#include "open_gl_shader.h"
#include <iostream>
#include <hangout_engine/rendering/types.h>

namespace HE {
    void OpenGLShader::Bind() {
        // TODO: Vertex type is hardcoded here, we probably want to make it more generic to make a more flexible interface
        bindVertexAttributes();
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

    void OpenGLShader::bindVertexAttributes() {
//        // enable the attribute arrays
//        int location = 0;
//
//        for (auto attribute : Vertex::GetAttributes()) {
//            uint32_t type = attribute.type == VertexAttribute::DataType::FLOAT ? GL_FLOAT : GL_INT;
//            glVertexAttribPointer(location, attribute.size, type, GL_FALSE, attribute.stride, (void*)attribute.offset);
//            glEnableVertexAttribArray(location);
//            location++;
//        }
    }
}
