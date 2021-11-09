#pragma once
#include <glm/glm.hpp>
#include <vector>

namespace HE {
    class VertexAttribute {
    public:
        enum class DataType {
            FLOAT,
            INT
        };

        int size;
        DataType type;
        int stride;
        int offset;
    };

    struct Vertex {
        glm::vec3 position;
        glm::vec4 color;
    };


}
