#pragma once

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <glm/glm.hpp>
#include <vector>

#include "MySkeletalAnimation/animation.h"

class Animator
{
  public:
    Animator(Animation *animation);

    void UpdateAnimation(float dt);

    void BlendTwoAnimations(Animation *pBaseAnimation, Animation *pLayeredAnimation, float blendFactor,
                            float deltaTime);

    void PlayAnimation(Animation *pAnimation);

    void CalculateBoneTransform(const AssimpNodeData *node, glm::mat4 parentTransform);

    void CalculateBlendedBoneTransform(Animation *pAnimationBase, const AssimpNodeData *node,
                                       Animation *pAnimationLayer, const AssimpNodeData *nodeLayered,
                                       const float currentTimeBase, const float currentTimeLayered,
                                       const glm::mat4 &parentTransform, const float blendFactor);

    std::vector<glm::mat4> GetFinalBoneMatrices()
    {
        return m_FinalBoneMatrices;
    }

  private:
    std::vector<glm::mat4> m_FinalBoneMatrices;
    Animation *m_CurrentAnimation;
    float m_CurrentTime;
    float m_DeltaTime;
};
