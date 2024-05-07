#pragma once

#include<glm/glm.hpp>

struct BoneInfo
{
	/*id is index in finalBoneMatrices*/
	int bone_id;

	/*offset matrix transforms vertex from model space to bone space*/
	glm::mat4 offset;

};