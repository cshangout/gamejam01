
#include "open_gl_buffer.h"
#include "open_gl_types.h"

namespace HE {
    OpenGLBuffer::OpenGLBuffer() {
        glGenBuffers(1, &_handle);
    }

    OpenGLBuffer::~OpenGLBuffer() {
        glDeleteBuffers(1, &_handle);
    }

    void OpenGLBuffer::Bind() {
        glBindBuffer(GL_ARRAY_BUFFER, _handle);
    }

    void OpenGLBuffer::UploadData(const std::vector<Vertex>& vertices) {
        _count = vertices.size();
        glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizei>(vertices.size() * sizeof(Vertex)),
                     vertices.data(), GL_STATIC_DRAW);
    }

    void OpenGLBuffer::SetLayout(const BufferLayout& layout) {
        _layout = layout;
    }

    const BufferLayout &OpenGLBuffer::GetLayout() const {
        return _layout;
    }

    void OpenGLBuffer::BindBufferLayout() {

        uint32_t index = 0;
        for (const auto& element : _layout) {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index, element.GetComponentCount(), ShaderDataTypeToOpenGLBaseType(element.type),
                                  element.normalized ? GL_TRUE : GL_FALSE, _layout.GetStride(), (const void*)element.offset);
            index++;
        }
    }
}
