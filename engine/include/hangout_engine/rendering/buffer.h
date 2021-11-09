#pragma once

#include <cstdint>
#include <vector>
#include "types.h"
#include <string>

namespace HE {
    enum class ShaderDataType {
        None = 0,
        Float,
        Float2,
        Float3,
        Float4,
        Mat3,
        Mat4,
        Int,
        Int2,
        Int3,
        Int4,
        Bool
    };

    static uint32_t ShaderDataTypeSize(ShaderDataType type) {
        switch (type) {
            case ShaderDataType::None:
                return 0;
            case ShaderDataType::Float:
                return 4;
            case ShaderDataType::Float2:
                return 8;
            case ShaderDataType::Float3:
                return 12;
            case ShaderDataType::Float4:
                return 16;
            case ShaderDataType::Mat3:
                return 36;
            case ShaderDataType::Mat4:
                return 48;
            case ShaderDataType::Int:
                return 4;
            case ShaderDataType::Int2:
                return 8;
            case ShaderDataType::Int3:
                return 12;
            case ShaderDataType::Int4:
                return 16;
            case ShaderDataType::Bool:
                return 1;
        }
    }
    struct BufferElement {
        ShaderDataType type;
        std::string name;
        uint32_t offset;
        uint32_t size;
        bool normalized;

        BufferElement(ShaderDataType type, std::string name, bool normalized = false)
            : name(std::move(name)), type(type), size(ShaderDataTypeSize(type)), offset(0), normalized(normalized) {

        }

        uint32_t GetComponentCount() const {
            switch(type) {
                case ShaderDataType::Float:
                    return 1;
                case ShaderDataType::Float2:
                    return 2;
                case ShaderDataType::Float3:
                    return 3;
                case ShaderDataType::Float4:
                    return 4;
                case ShaderDataType::Mat3:
                    return 9;
                case ShaderDataType::Mat4:
                    return 16;
                case ShaderDataType::Int:
                    return 1;
                case ShaderDataType::Int2:
                    return 2;
                case ShaderDataType::Int3:
                    return 3;
                case ShaderDataType::Int4:
                    return 4;
                case ShaderDataType::Bool:
                    return 1;
            }
        }
    };

    class BufferLayout {
    public:
        BufferLayout(const std::initializer_list<BufferElement>& elements) : _elements{ elements } {
            calculateOffsetsAndStride();
        }

        BufferLayout() : _elements{} {}

        inline const std::vector<BufferElement>& GetElements() const { return _elements; }
        inline uint32_t GetStride() const { return _stride; }

        std::vector<BufferElement>::iterator begin() { return _elements.begin(); }
        std::vector<BufferElement>::iterator end() { return _elements.end(); }
    private:
        void calculateOffsetsAndStride() {
            uint32_t offset = 0;
            _stride = 0;
            for (auto& element : _elements) {
                element.offset = offset;
                offset += element.size;
                _stride += element.size;
            }
        }

    private:
        std::vector<BufferElement> _elements;
        uint32_t _stride = 0;
    };

    class VertexBuffer {
    public:
        virtual void Bind() = 0;
        virtual void UploadData(const std::vector<Vertex>&) = 0;
        virtual void SetLayout(const BufferLayout& layout) = 0;
        virtual const BufferLayout& GetLayout() const = 0;
        virtual uint32_t GetCount() = 0;
        virtual void BindBufferLayout() = 0;
    protected:
        uint32_t _handle = 0;
    };
}