#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include <glm/glm.hpp>

struct TransformComponent {
	glm::vec2 position;
	glm::vec2 scale;
	float rotation;

	TransformComponent(glm::vec2 pos = glm::vec2(0.0, 0.0), glm::vec2 scale = glm::vec2(1.0, 1.0), double rotation = 0.0) {
		this->position = pos;
		this->scale = scale;
		this->rotation = rotation;
	}
};

#endif // TRANSFORM_COMPONENT_H
