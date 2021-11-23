//
// Created by ozzadar on 2021-11-23.
//

#include <hangout_engine/service_locator.h>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include "game_object.h"

void GameObject::Render() {
    if (_shader) {
        static int count = 0;
        count += 2;

        glm::mat4 trans1 {1.f};
//        trans1 *= glm::eulerAngleXYZ(-1 * glm::radians(static_cast<float>(count % 360)), 0.f, 0.f);

        for (auto &mesh: _meshes) {
            glm::mat4 modelTransform {1.f};
            modelTransform = glm::translate(modelTransform, _position);
            modelTransform = glm::scale(modelTransform, _scale);

            auto rotation = glm::eulerAngleXYZ(glm::radians(_rotation.x), glm::radians(_rotation.y), glm::radians(_rotation.z));
            modelTransform *= rotation;

            _shader->UniformMat4("u_model", trans1 * modelTransform);
            HE::ServiceLocator::GetRenderer()->Submit(_shader, mesh);
        }
    }
}
