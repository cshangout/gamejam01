#include <hangout_engine/platform/entry_point.h>

#include <hangout_engine/rendering/render_command.h>
#include <vector>


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
                    .color = {1.f, 0.f, 0.f, 1.f},
                    .uv = { 2.f, 2.f }
                },
                {
                    .position = {0.5f, -0.5f, 0.f},
                    .color = {0.f, 1.f, 0.f, 1.f},
                    .uv = { 2.f, 0.f }
                },
                {
                    .position = {-0.5f, -0.5f, 0.f},
                    .color = {0.f, 0.f, 1.f, 1.f},
                    .uv = { 0.f, 0.f }
                },
                {
                    .position = {-0.5f, 0.5f, 0.f},
                    .color = {0.f, 0.f, 1.f, 1.f},
                    .uv = { 0.f, 2.f }
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
                {HE::ShaderDataType::Float2, "aTexCoord"}
        };

        vertexBuffer->SetLayout(layout);

        auto indexBuffer = HE::ServiceLocator::GetRenderer()->CreateIndexBuffer();
        indexBuffer->Bind();
        indexBuffer->UploadData(indices);

        vertexArray = HE::ServiceLocator::GetRenderer()->CreateVertexArray();
        vertexArray->AddVertexBuffer(vertexBuffer);
        vertexArray->AddIndexBuffer(indexBuffer);

        auto texture = HE::ServiceLocator::GetRenderer()->CreateTexture();
        auto data = HE::TextureData("textures/container.jpeg");
        texture->Bind();
        texture->BindSamplerSettings(HE::SamplerSettings{
                .repeatModeS = HE::TextureWrapMode::ClampToBorder,
                .repeatModeT = HE::TextureWrapMode::MirroredRepeat,
                .minFilter = HE::TextureFiltering::Linear,
                .magFilter = HE::TextureFiltering::Linear,
        });
        texture->UploadData(data);

        auto texture2 = HE::ServiceLocator::GetRenderer()->CreateTexture();
        auto data2 = HE::TextureData("textures/awesomeface.png", true);
        texture2->Bind();
        texture2->BindSamplerSettings(HE::SamplerSettings{
                .repeatModeS = HE::TextureWrapMode::MirroredRepeat,
                .repeatModeT = HE::TextureWrapMode::ClampToBorder,
                .minFilter = HE::TextureFiltering::Linear,
                .magFilter = HE::TextureFiltering::Linear,
        });
        texture2->UploadData(data2);

        shader = HE::ServiceLocator::GetRenderer()->CreateShader();
        shader->LoadAndCompile("shaders/basic.vs", "shaders/basic.fs" );
        shader->SetTextureSamplers({
            {
                .samplerName = "smileTexture",
                .index = HE::TextureBindingIndex::Texture0,
                .texture = texture2,
            },
            {
                .samplerName = "baseTexture",
                .index = HE::TextureBindingIndex::Texture1,
                .texture = texture,
            },
        });
    }

    void Render() override {
        HE::RenderCommand::SetClearColor({0.1f, 0.2f, 0.3f, 1.0f});
        HE::RenderCommand::Clear();

        HE::ServiceLocator::GetRenderer()->BeginScene(cameraOrtho);
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
