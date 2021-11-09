#pragma once
#include <hangout_engine/rendering/buffer.h>
#include "open_gl_graphics.h"

namespace HE {
    class OpenGLBuffer : public VertexBuffer {
    public:
        OpenGLBuffer();
        ~OpenGLBuffer();
        void Bind() override;

        void UploadData(const std::vector<Vertex>& vertices) override;
        void SetLayout(const BufferLayout& layout) override;
        const BufferLayout& GetLayout() const override;
        void BindBufferLayout() override;
        uint32_t GetCount() override { return _count; };

    private:
        BufferLayout _layout;
        uint32_t _count;
    };
}
