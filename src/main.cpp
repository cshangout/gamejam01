#include <hangout_engine/platform/entry_point.h>

#include <hangout_engine/rendering/render_command.h>
#include <hangout_engine/utils/shapes.h>
#include <vector>
#include <iostream>
#include "game_object.h"


class GameJamProject : public HE::Game {
public:
    explicit GameJamProject(std::string title) :
        HE::Game(std::move(title)),
        camera(
            HE::Camera()
        )
        {
        _desiredFPS = 60.f;
    }

protected:
    void Init() override {
        HE::ServiceLocator::GetWindow()->MakeContextCurrent();

        _inputManager = HE::ServiceLocator::GetInputManager();

        if (_inputManager) {
            _inputManager->MapInputToAction(HE::InputKey::KEY_A, HE::InputAction {
                .ActionName = "strafe",
                .Scale = -1.f
            });
            _inputManager->MapInputToAction(HE::InputKey::KEY_D, HE::InputAction {
                    .ActionName = "strafe",
                    .Scale = 1.f
            });

            _inputManager->MapInputToAction(HE::InputKey::CONTROLLER_AXIS_LEFTX, HE::InputAction {
                    .ActionName = "strafe",
                    .Scale = 1.f
            });

            _inputManager->MapInputToAction(HE::InputKey::KEY_W, HE::InputAction {
                    .ActionName = "moveForward",
                    .Scale = 1.f
            });

            _inputManager->MapInputToAction(HE::InputKey::KEY_S, HE::InputAction {
                    .ActionName = "moveForward",
                    .Scale = -1.f
            });

            _inputManager->MapInputToAction(HE::InputKey::CONTROLLER_AXIS_LEFTY, HE::InputAction {
                    .ActionName = "moveForward",
                    .Scale = -1.f
            });

            _inputManager->MapInputToAction(HE::InputKey::KEY_E, HE::InputAction {
                    .ActionName = "moveUp",
                    .Scale = -1.f
            });

            _inputManager->MapInputToAction(HE::InputKey::KEY_Q, HE::InputAction {
                    .ActionName = "moveUp",
                    .Scale = 1.f
            });

            _inputManager->MapInputToAction(HE::InputKey::CONTROLLER_BUTTON_RIGHTSHOULDER, HE::InputAction {
                    .ActionName = "moveUp",
                    .Scale = -1.f
            });

            _inputManager->MapInputToAction(HE::InputKey::CONTROLLER_BUTTON_LEFTSHOULDER, HE::InputAction {
                    .ActionName = "moveUp",
                    .Scale = 1.f
            });

            _inputManager->MapInputToAction(HE::InputKey::KEY_C, HE::InputAction {
                    .ActionName = "changeCameraMode",
                    .Scale = 1.f
            });

            _inputManager->MapInputToAction(HE::InputKey::CONTROLLER_BUTTON_SELECT, HE::InputAction {
                    .ActionName = "changeCameraMode",
                    .Scale = 1.f
            });

            _inputManager->MapInputToAction(HE::InputKey::CONTROLLER_AXIS_RIGHTY, HE::InputAction {
                    .ActionName = "lookY",
                    .Scale = -1.f
            });

            _inputManager->MapInputToAction(HE::InputKey::CONTROLLER_AXIS_RIGHTX, HE::InputAction {
                    .ActionName = "lookX",
                    .Scale = 1.f
            });

            _inputManager->RegisterActionCallback("changeCameraMode", HE::InputManager::ActionCallback {
               .Ref = "Hangouts",
               .Func = [this](HE::InputSource source, int index, float value) {
                   if (value > 0.f) {
                       this->camera.SetIsPerspective(!this->camera.IsPerspective());
                   }
                   return true;
               }
            });
        }
        setupScene();
    }

    void Update(float deltaTime) override {
        auto moveForwardAmount = _inputManager->GetActionValue("moveForward");

        auto scaledSpeed = movementSpeed * deltaTime;
        if (std::abs(moveForwardAmount) > 0.05f) {
            camera.Translate(HE::Camera::MoveDirection::Forward, moveForwardAmount * scaledSpeed);
        }

        auto strafeAmount = _inputManager->GetActionValue("strafe");
        if (std::abs(strafeAmount) > 0.05f) {
            camera.Translate(HE::Camera::MoveDirection::Right, strafeAmount * scaledSpeed);
        }

        auto moveUpAmount = _inputManager->GetActionValue("moveUp");
        camera.Translate(HE::Camera::MoveDirection::Up, moveUpAmount * scaledSpeed);


        auto scaledLookSpeed = lookSpeed * deltaTime;

        auto lookXAmount = _inputManager->GetActionValue("lookX");
        if (std::abs(lookXAmount) > 0.05f) {
            camera.RotateBy(lookXAmount * scaledLookSpeed, 0.f);
        }

        auto lookYAmount = _inputManager->GetActionValue("lookY");
        if (std::abs(lookYAmount) > 0.05f) {
            camera.RotateBy(0.f, lookYAmount * scaledLookSpeed);
        }

        obj.SetRotation({0.f, static_cast<int>(totalTime/2) % 360, 0.f});
        totalTime += 1;
    }

private:
    void setupScene() {

        std::vector<HE::Vertex> vertices;
        vertices.resize(HE::cubeNumVertices);
        memcpy(vertices.data(), HE::cubeVertices, sizeof(HE::Vertex) * HE::cubeNumVertices);

        std::shared_ptr<HE::VertexBuffer> vertexBuffer = HE::ServiceLocator::GetRenderer()->CreateVertexBuffer();
        vertexBuffer->Bind();
        vertexBuffer->UploadData(vertices);

        HE::BufferLayout layout = {
                {HE::ShaderDataType::Float3, "aPos"},
                {HE::ShaderDataType::Float4, "aColor"},
                {HE::ShaderDataType::Float2, "aTexCoord"}
        };

        vertexBuffer->SetLayout(layout);

        std::vector<uint32_t> indices;
        indices.resize(HE::cubeNumIndices);
        memcpy(indices.data(), HE::cubeIndices, sizeof(uint32_t) * HE::cubeNumIndices);

        auto indexBuffer = HE::ServiceLocator::GetRenderer()->CreateIndexBuffer();
        indexBuffer->Bind();
        indexBuffer->UploadData(indices);

        auto vertexArray = HE::ServiceLocator::GetRenderer()->CreateVertexArray();
        vertexArray->AddVertexBuffer(vertexBuffer);
        vertexArray->AddIndexBuffer(indexBuffer);

        auto texture = HE::ServiceLocator::GetRenderer()->CreateTexture();
        auto data = std::make_shared<HE::TextureData>("textures/container.jpeg");
        texture->Bind();
        texture->BindSamplerSettings(HE::SamplerSettings{
                .repeatModeS = HE::TextureWrapMode::ClampToBorder,
                .repeatModeT = HE::TextureWrapMode::ClampToEdge,
                .minFilter = HE::TextureFiltering::Linear,
                .magFilter = HE::TextureFiltering::Linear,
                .borderColor = {1.0f, 1.f, 1.f, 1.f }
        });
        texture->UploadData(data);

        auto texture2 = HE::ServiceLocator::GetRenderer()->CreateTexture();
        data = std::make_shared<HE::TextureData>("textures/awesomeface.png", true);
        texture2->Bind();
        texture2->BindSamplerSettings(HE::SamplerSettings{
                .repeatModeS = HE::TextureWrapMode::ClampToBorder,
                .repeatModeT = HE::TextureWrapMode::ClampToEdge,
                .minFilter = HE::TextureFiltering::Linear,
                .magFilter = HE::TextureFiltering::Linear,
                .borderColor = {1.0f, 1.f, 1.f, 1.f }
        });

        texture2->UploadData(data);

        auto shader = HE::ServiceLocator::GetRenderer()->CreateShader();
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

        obj.SetShader(std::move(shader));
        obj.AddMesh(std::move(vertexArray));
        obj.SetPosition({0.f, 1.f, 0.f});

    }

    void Render() override {
        HE::RenderCommand::SetClearColor({0.1f, 0.2f, 0.3f, 1.0f});
        HE::RenderCommand::Clear();

        HE::ServiceLocator::GetRenderer()->BeginScene(camera);
        obj.Render();
        HE::ServiceLocator::GetRenderer()->EndScene();

    }
private:
    float movementSpeed = 10.f;
    float lookSpeed = 180.f;
    float totalTime = 0.f;

    GameObject obj;

    HE::Camera camera;

    HE::InputManager* _inputManager = nullptr;
};

HE::Game* HE::CreateGame() {
    return new GameJamProject("The best project");
};
