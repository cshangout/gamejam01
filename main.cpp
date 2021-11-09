#include <hangout_engine/platform/entry_point.h>
#include <hangout_engine/rendering/types.h>
#include <hangout_engine/rendering/buffer.h>
#include <hangout_engine/rendering/vertex_array.h>
#include <vector>



class GameJamProject : public HE::Game {
public:
    explicit GameJamProject(std::string title) : HE::Game(std::move(title)) {
    }

protected:
    void Init() override {
        HE::ServiceLocator::GetWindow()->MakeContextCurrent();

        setupScene();
    }

    void Update(float deltaTime) override {
    }

private:
    void setupScene() {
        std::vector<HE::Vertex> vertices = {
                {
                    .position = {-0.5f, -0.5f, 0.f},
                    .color = {1.f, 0.f, 0.f, 1.f}
                },
                {
                    .position = {0.5f, -0.5f, 0.f},
                    .color = {0.f, 1.f, 0.f, 1.f}
                },
                {
                    .position = {0.0f, 0.5f, 0.f},
                    .color = {0.f, 0.f, 1.f, 1.f}
                }
        };

        std::shared_ptr<HE::VertexBuffer> buffer = HE::ServiceLocator::GetRenderer()->CreateBuffer();
        buffer->Bind();
        buffer->UploadData(vertices);

        HE::BufferLayout layout = {
                {HE::ShaderDataType::Float3, "aPos"},
                {HE::ShaderDataType::Float4, "aColor"},
        };

        buffer->SetLayout(layout);

        vertexArray = HE::ServiceLocator::GetRenderer()->CreateVertexArray();
        vertexArray->AddVertexBuffer(buffer);

        shader = HE::ServiceLocator::GetRenderer()->CreateShader();
        shader->Compile(
            "#version 300 es\n"
            "layout (location = 0) in vec3 aPos;\n"
            "layout (location = 1) in vec4 aColor;\n"

            "out vec4 v_Color;"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "   v_Color = aColor;"
            "}",
            "#version 300 es\n"
            "precision highp float;"
            "out vec4 FragColor;\n"
            "in vec4 v_Color;"
            "\n"
            "void main()\n"
            "{\n"
            "    FragColor = v_Color;\n"
            "} "
        );

    }

    void Render() override {
        auto commandBuffer = HE::ServiceLocator::GetRenderer()->GetRenderCommand();

        commandBuffer.SetClearColor({0.1f, 0.2f, 0.3f, 1.0f});
        commandBuffer.Clear();

        HE::ServiceLocator::GetRenderer()->BeginScene();


        shader->Bind();
        HE::ServiceLocator::GetRenderer()->Submit(vertexArray);
        HE::ServiceLocator::GetRenderer()->EndScene();

    }
private:
    std::shared_ptr<HE::Shader> shader;
    std::shared_ptr<HE::VertexArray> vertexArray = nullptr;

};

HE::Game* HE::CreateGame() {
    return new GameJamProject("The best project");
};
