#pragma once

#include <glm/glm.hpp>

namespace Hazel::Math {
	//输入一个 4x4 TRS 变换矩阵 transform，拆解出平移向量 translation、欧拉角 rotation（弧度 Y-X-Z）、缩放 scale；
	bool DecomposeTransform(const glm::mat4& transform, glm::vec3& outTranslation, glm::vec3& outRotation, glm::vec3& outScale);

}