#include <hangout_engine/platform/entry_point.h>

#include <hangout_engine/rendering/render_command.h>
#include <hangout_engine/utils/shapes.h>
#include <vector>
#include <iostream>
#include <hangout_engine/core/components/camera_component.h>


class GameJamProject : public HE::Game {
public:
    explicit GameJamProject(std::string title) :
        HE::Game(std::move(title))
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
                    .Scale = -1.f
            });

            _inputManager->MapInputToAction(HE::InputKey::KEY_S, HE::InputAction {
                    .ActionName = "moveForward",
                    .Scale = 1.f
            });

            _inputManager->MapInputToAction(HE::InputKey::CONTROLLER_AXIS_LEFTY, HE::InputAction {
                    .ActionName = "moveForward",
                    .Scale = 1.f
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
                    .Scale = -1.f
            });

            _inputManager->RegisterActionCallback("changeCameraMode", HE::InputManager::ActionCallback {
               .Ref = "Hangouts",
               .Func = [this](HE::InputSource source, int index, float value) {
                   if (value > 0.f) {
                       if (camera) {
                           auto& cameraComponent = camera->GetComponent<HE::CameraComponent>();
                           cameraComponent.SetIsPerspective(!cameraComponent.IsPerspective());
                       }
                   }
                   return true;
               }
            });
        }
        setupScene();
    }

    void Update(double deltaTime) override {
        auto& cameraTransform = camera->GetComponent<HE::TransformComponent>();

        auto moveForwardAmount = _inputManager->GetActionValue("moveForward");

        auto scaledSpeed = movementSpeed * deltaTime;
        if (std::abs(moveForwardAmount) > 0.05f) {
            cameraTransform.Translate(HE::MoveDirection::Forward, moveForwardAmount * scaledSpeed);
        }

        auto strafeAmount = _inputManager->GetActionValue("strafe");
        if (std::abs(strafeAmount) > 0.05f) {
            cameraTransform.Translate(HE::MoveDirection::Right, strafeAmount * scaledSpeed);
        }

        auto moveUpAmount = _inputManager->GetActionValue("moveUp");
        cameraTransform.Translate(HE::MoveDirection::Up, moveUpAmount * scaledSpeed);


        auto scaledLookSpeed = lookSpeed * deltaTime;

        auto lookXAmount = _inputManager->GetActionValue("lookX");
        if (std::abs(lookXAmount) > 0.05f) {
            cameraTransform.RotateBy(lookXAmount * scaledLookSpeed, 0.f);
        }

        auto lookYAmount = _inputManager->GetActionValue("lookY");
        if (std::abs(lookYAmount) > 0.05f) {
            cameraTransform.RotateBy(0.f, lookYAmount * scaledLookSpeed);
        }

        auto &transform = entity->GetComponent<HE::TransformComponent>();

        float spd = -1.f;

        transform.RotateBy(spd,0.f, spd);

        if (deltaTime < 1.0) {
            totalTime = totalTime + deltaTime;
        }
    }

private:
    void setupScene() {

        std::vector<HE::Vertex> vertices;
        vertices.resize(HE::cubeNumVertices);
        memcpy(vertices.data(), HE::cubeVertices, sizeof(HE::Vertex) * HE::cubeNumVertices);

        std::vector<uint32_t> indices;
        indices.resize(HE::cubeNumIndices);
        memcpy(indices.data(), HE::cubeIndices, sizeof(uint32_t) * HE::cubeNumIndices);

        auto texture = HE::ServiceLocator::GetRenderer()->CreateTexture();
        auto data = std::make_shared<HE::TextureData>("textures/wallet.png", true);
        texture->Bind();
        texture->BindSamplerSettings(HE::SamplerSettings{});
        texture->UploadData(data);

        auto texture2 = HE::ServiceLocator::GetRenderer()->CreateTexture();
        data = std::make_shared<HE::TextureData>("textures/awesomeface.png", true);
        texture2->Bind();
        texture2->BindSamplerSettings(HE::SamplerSettings{});
        texture2->UploadData(data);

        entity = GetScene().CreateEntity();
        auto& mesh = entity->AddComponent<HE::MeshComponent>(std::move(vertices), std::move(indices));

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

        mesh.SetShader(std::move(shader));

        auto& transform = entity->GetComponent<HE::TransformComponent>();
        transform.SetPosition({0.f, 0.f, 0.f});

        entity2 = GetScene().CreateEntity();
        auto& mesh2 = entity2->AddComponent<HE::MeshComponent>(mesh);

        auto& transform2 = entity2->GetComponent<HE::TransformComponent>();
        transform2.SetPosition({1.5f, 0.f, 0.f});

        camera = GetScene().CreateEntity();
        camera->AddComponent<HE::CameraComponent>();
        auto& cameraTransform = camera->GetComponent<HE::TransformComponent>();
        cameraTransform.SetPosition({0.f, 0.f, 5.f});

    }

private:
    float movementSpeed = 10.f;
    float lookSpeed = 180.f;
    double totalTime = 0.f;

    HE::InputManager* _inputManager = nullptr;
    HE::Entity* entity = nullptr;
    HE::Entity* entity2 = nullptr;
    HE::Entity* camera = nullptr;

};

HE::Game* HE::CreateGame() {
    return new GameJamProject("The best project");
};
