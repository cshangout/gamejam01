#include <hangout_engine/platform/entry_point.h>
#include <vector>

#include <hangout_engine/rendering/render_command.h>
#include <hangout_engine/utils/shapes.h>
#include <hangout_engine/core/components/camera_component.h>
#include "hangout_engine/core/components/light_component.h"
#include "hangout_engine/core/components/skybox_component.h"

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

            _inputManager->MapInputToAction(HE::InputKey::CONTROLLER_BUTTON_DPAD_UP, HE::InputAction {
                    .ActionName = "reflect",
                    .Scale = 1.f
            });
            _inputManager->MapInputToAction(HE::InputKey::CONTROLLER_BUTTON_DPAD_DOWN, HE::InputAction {
                    .ActionName = "reflect",
                    .Scale = -1.f
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

            _inputManager->MapInputToAction(HE::InputKey::MOUSE_MOVE_Y, HE::InputAction {
                    .ActionName = "lookY",
                    .Scale = -0.25f
            });

            _inputManager->MapInputToAction(HE::InputKey::MOUSE_MOVE_X, HE::InputAction {
                    .ActionName = "lookX",
                    .Scale = -0.25f
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
        if (std::abs(lookXAmount) > 0.05f && std::abs(lookXAmount) < 10.f) {
            cameraTransform.RotateBy(lookXAmount * scaledLookSpeed, 0.f);
        }

        auto lookYAmount = _inputManager->GetActionValue("lookY");
        if (std::abs(lookYAmount) > 0.05f && std::abs(lookYAmount) < 10.f) {
            cameraTransform.RotateBy(0.f, lookYAmount * scaledLookSpeed);
        }

        auto reflectChangeAmount = _inputManager->GetActionValue("reflect") * deltaTime;
        auto& objectmesh = entity->GetComponent<HE::MeshComponent>();
        objectmesh.Mat.Reflectivity += reflectChangeAmount;

        auto &transform = entity->GetComponent<HE::TransformComponent>();
        auto &transform2 = light->GetComponent<HE::TransformComponent>();
        auto &lightComponent = light->GetComponent<HE::LightComponent>();

        transform2.SetPosition({0.f + std::sin(totalTime), 1.5f, std::cos(totalTime)});


        if (deltaTime < 1.0) {
            totalTime = totalTime + deltaTime;
        }
    }

private:
    void setupScene() {
        auto texture = HE::ServiceLocator::GetRenderer()->CreateTexture(HE::TextureType::TWOD);
        auto data = HE::TextureData("textures/wallet.png", true);
//        auto data = HE::TextureData(100, 100, glm::vec3{1.f, 1.f, 1.f});

        texture->Bind();
        texture->BindSamplerSettings(HE::SamplerSettings{});
        texture->UploadData(data, HE::TextureTarget::TWOD);

        auto texture2 = HE::ServiceLocator::GetRenderer()->CreateTexture(HE::TextureType::TWOD);
        data = HE::TextureData(100, 100, glm::vec3{1.f, 1.f, 1.f});

        texture2->Bind();
        texture2->BindSamplerSettings(HE::SamplerSettings{});
        texture2->UploadData(data, HE::TextureTarget::TWOD);

        entity = GetScene().CreateEntity();
        auto& transform1 = entity->GetComponent<HE::TransformComponent>();
        transform1.SetScale({1.f, 1.f, 1.f});
        transform1.SetRotation({0.f, 1.f, 0.f});

        auto [sphereVertices, sphereIndices] = HE::GenerateSphere();

        for (auto index : sphereIndices) {
            if (index >= sphereVertices.size()) {
                std::cout << "Too big!" << std::endl;
            }
        }


        auto& mesh = entity->AddComponent<HE::MeshComponent>(
                std::vector<HE::Vertex>(sphereVertices.begin(), sphereVertices.end()),
                std::vector<uint32_t>(sphereIndices.begin(), sphereIndices.end())
        );

        auto shader = HE::ServiceLocator::GetRenderer()->CreateShader();
        shader->LoadAndCompile("shaders/basic.vs", "shaders/basic.fs" );
        shader->SetTextureSamplers({
            {
                 .samplerName = "baseTexture",
                 .index = HE::TextureBindingIndex::Texture0,
                 .texture = texture,
            }
         });

        mesh.SetShader(std::move(shader));
        mesh.Mat.Shininess = 256.f;
        mesh.Mat.Reflectivity = 0.25f;
        auto shader2 = HE::ServiceLocator::GetRenderer()->CreateShader();
        shader2->LoadAndCompile("shaders/basic.vs", "shaders/light.fs" );
        shader2->SetTextureSamplers({
           {
                   .samplerName = "baseTexture",
                   .index = HE::TextureBindingIndex::Texture0,
                   .texture = texture2,
           }
        });

        auto& transform = entity->GetComponent<HE::TransformComponent>();
        transform.SetPosition({0.f, 0.f, 0.f});

        light = GetScene().CreateEntity();
        auto& lightComponent = light->AddComponent<HE::LightComponent>();
        lightComponent.AmbientColor = {0.1f, 0.1f, 0.1f};
        auto& mesh2 = light->AddComponent<HE::MeshComponent>(
            std::vector<HE::Vertex>(HE::cubeVertices.begin(), HE::cubeVertices.end()),
            std::vector<uint32_t>(HE::cubeIndices.begin(), HE::cubeIndices.end())
        );

        mesh2.SetShader(shader2);

        auto& transform2 = light->GetComponent<HE::TransformComponent>();
        transform2.SetPosition({0.25f, 1.5f, -0.0f});
        transform2.SetScale({0.25f, 0.25f, 0.25f});
        camera = GetScene().CreateEntity();
        camera->AddComponent<HE::CameraComponent>();
        auto& cameraTransform = camera->GetComponent<HE::TransformComponent>();
        cameraTransform.SetPosition({0.f, 0.f, 5.f});

//        GetScene().EnableSkybox();
//        GetScene().SetSkyboxTextureFace(HE::TextureData(100, 100, {1.f, 0.f, 0.f}), HE::TextureTarget::CUBEMAP_POS_X);
//        GetScene().SetSkyboxTextureFace(HE::TextureData(100, 100, {0.f, 1.f, 1.f}), HE::TextureTarget::CUBEMAP_NEG_X);
//        GetScene().SetSkyboxTextureFace(HE::TextureData(100, 100, {1.f, 0.f, 1.f}), HE::TextureTarget::CUBEMAP_POS_Y);
//        GetScene().SetSkyboxTextureFace(HE::TextureData(100, 100, {0.f, 0.f, 1.f}), HE::TextureTarget::CUBEMAP_NEG_Y);
//        GetScene().SetSkyboxTextureFace(HE::TextureData(100, 100, {0.f, 1.f, 0.f}), HE::TextureTarget::CUBEMAP_POS_Z);
//        GetScene().SetSkyboxTextureFace(HE::TextureData(100, 100, {0.f, 0.f, 0.f}), HE::TextureTarget::CUBEMAP_NEG_Z);

        GetScene().SetSkyboxTextureFace(HE::TextureData("textures/skybox/right.jpg", false), HE::TextureTarget::CUBEMAP_POS_X);
        GetScene().SetSkyboxTextureFace(HE::TextureData("textures/skybox/left.jpg", false), HE::TextureTarget::CUBEMAP_NEG_X);
        GetScene().SetSkyboxTextureFace(HE::TextureData("textures/skybox/top.jpg", false), HE::TextureTarget::CUBEMAP_POS_Y);
        GetScene().SetSkyboxTextureFace(HE::TextureData("textures/skybox/bottom.jpg", false), HE::TextureTarget::CUBEMAP_NEG_Y);
        GetScene().SetSkyboxTextureFace(HE::TextureData("textures/skybox/front.jpg", false), HE::TextureTarget::CUBEMAP_POS_Z);
        GetScene().SetSkyboxTextureFace(HE::TextureData("textures/skybox/back.jpg", false), HE::TextureTarget::CUBEMAP_NEG_Z);
    }

private:
    float movementSpeed = 10.f;
    float lookSpeed = 180.f;
    double totalTime = 0.f;

    HE::InputManager* _inputManager = nullptr;
    HE::Entity* entity = nullptr;
    HE::Entity* light = nullptr;
    HE::Entity* camera = nullptr;
    HE::Entity* skybox = nullptr;

};

HE::Game* HE::CreateGame() {
    return new GameJamProject("The best project");
};
