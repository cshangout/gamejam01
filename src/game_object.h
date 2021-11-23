#pragma once

#include <vector>
#include <hangout_engine/rendering/vertex_array.h>
#include <hangout_engine/rendering/shader.h>

class GameObject {
public:

    void Render();

    void SetShader(std::shared_ptr<HE::Shader>&& shaderPtr) {
        this->_shader = shaderPtr;
    }

    void AddMesh(std::shared_ptr<HE::VertexArray>&& meshPtr) {
        _meshes.emplace_back(meshPtr);
    }

    void SetPosition(const glm::vec3 position) {
        _position = position;
    }

    void SetScale(const glm::vec3 scale) {
        _scale = scale;
    }

    void SetRotation(const glm::vec3 rotation) {
        _rotation = rotation;
    }

private:
    glm::vec3 _position {};
    glm::vec3 _scale {1.f, 1.f, 1.f};
    glm::vec3 _rotation {0.f, 0.f, 0.f};

    std::shared_ptr<HE::Shader> _shader = nullptr;
    std::vector<std::shared_ptr<HE::VertexArray>> _meshes{};

};


