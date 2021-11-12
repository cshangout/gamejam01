#include <hangout_engine/platform/entry_point.h>
#include <hangout_engine/rendering/types.h>
#include <hangout_engine/rendering/buffer.h>
#include <hangout_engine/rendering/vertex_array.h>
#include <vector>
#include <hangout_engine/rendering/camera.h>


class GameJamProject : public HE::Game {
public:
    explicit GameJamProject(std::string title) :
        HE::Game(std::move(title)),
        camera(HE::PerspectiveCamera(45.f, HE::ServiceLocator::GetWindow()->GetAspectRatio(), 0.1f, 100.f)),
        cameraOrtho(HE::ServiceLocator::GetWindow()->GetAspectRatio()){

    }

protected:
    void Init() override {
        HE::ServiceLocator::GetWindow()->MakeContextCurrent();
        camera.SetPosition(glm::vec3(1.f,5.f,5));
        camera.LookAt(glm::vec3(0,0,0));
        cameraOrtho.SetPosition(glm::vec3(0.5f,0.f,0));

        setupScene();
    }

    void Update(float deltaTime) override {

    }

private:
    void setupScene() {
        std::vector<HE::Vertex> vertices = {
                {
                    .position = {0.5f, 0.5f, 0.f},
                    .color = {1.f, 0.f, 0.f, 1.f}
                },
                {
                    .position = {0.5f, -0.5f, 0.f},
                    .color = {0.f, 1.f, 0.f, 1.f}
                },
                {
                    .position = {-0.5f, -0.5f, 0.f},
                    .color = {0.f, 0.f, 1.f, 1.f}
                },
                {
                    .position = {-0.5f, 0.5f, 0.f},
                    .color = {0.f, 0.f, 1.f, 1.f}
                }
        };

        std::vector<uint32_t> indices = {
                0, 1, 3,
                1, 2, 3
        };

        std::shared_ptr<HE::VertexBuffer> vertexBuffer = HE::ServiceLocator::GetRenderer()->CreateVertexBuffer();
        vertexBuffer->Bind();
        vertexBuffer->UploadData(vertices);

        HE::BufferLayout layout = {
                {HE::ShaderDataType::Float3, "aPos"},
                {HE::ShaderDataType::Float4, "aColor"},
        };

        vertexBuffer->SetLayout(layout);

        auto indexBuffer = HE::ServiceLocator::GetRenderer()->CreateIndexBuffer();
        indexBuffer->Bind();
        indexBuffer->UploadData(indices);

        vertexArray = HE::ServiceLocator::GetRenderer()->CreateVertexArray();
        vertexArray->AddVertexBuffer(vertexBuffer);
        vertexArray->AddIndexBuffer(indexBuffer);

        shader = HE::ServiceLocator::GetRenderer()->CreateShader();
        shader->Compile(
            HE_SHADER_VERSION_STRING
            "layout (location = 0) in vec3 aPos;\n"
            "layout (location = 1) in vec4 aColor;\n"

            "uniform mat4 u_ViewProjection;"

            "out vec4 v_Color;"
            "void main()\n"
            "{\n"
            "   gl_Position = u_ViewProjection * vec4(aPos, 1.0);\n"
            "   v_Color = aColor;"
            "}",
            HE_SHADER_VERSION_STRING
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

        HE::ServiceLocator::GetRenderer()->BeginScene(camera);

        HE::ServiceLocator::GetRenderer()->Submit(shader, vertexArray);

        HE::ServiceLocator::GetRenderer()->EndScene();

    }
private:
    std::shared_ptr<HE::Shader> shader;
    std::shared_ptr<HE::VertexArray> vertexArray = nullptr;

    HE::PerspectiveCamera camera;
    HE::OrthographicCamera cameraOrtho;
};

HE::Game* HE::CreateGame() {
    return new GameJamProject("The best project");
};
