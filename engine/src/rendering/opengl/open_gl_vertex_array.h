#pragma once
#include <hangout_engine/rendering/vertex_array.h>
#include <vector>

namespace HE {
    class OpenGLVertexArray : public VertexArray {
    public:
        OpenGLVertexArray();
        ~OpenGLVertexArray() override;

        void Bind() const override;
        void Unbind() const override;
        void AddVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer) override;
        const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() override { return _vertexBuffers; }
    private:
        std::vector<std::shared_ptr<VertexBuffer>> _vertexBuffers{};
        std::shared_ptr<VertexBuffer> _indexBuffer = nullptr;

        uint32_t _handle;
        uint32_t _count = 0;

    };
}
