#pragma once

#include <assimp/scene.h>
#include <glm/glm.hpp>
#include <map>
#include <vector>


#include "MySkeletalAnimation/assimp_glm_helpers.h"
#include "MySkeletalAnimation/bone.h"
#include "MySkeletalAnimation/bone_info.h"
#include "MySkeletalAnimation/model.h"


struct AssimpNodeData
{
    glm::mat4 transformation;
    std::string name;
    int childrenCount;
    std::vector<AssimpNodeData> children;
};

class Animation
{
  public:
    Animation() = default;

    Animation(const std::string &animationPath, Model *model);

    ~Animation() = default;

    Bone *FindBone(const std::string &name)
    {
        auto iter =
            std::find_if(m_Bones.begin(), m_Bones.end(), [&](const Bone &Bone) { return Bone.GetBoneName() == name; });
        if (iter == m_Bones.end())
            return nullptr;
        else
            return &(*iter);
    }

    inline float GetTicksPerSecond()
    {
        return m_TicksPerSecond;
    }
    inline float GetDuration()
    {
        return m_Duration;
    }
    inline const AssimpNodeData &GetRootNode()
    {
        return m_RootAssimpDataNode;
    }
    inline const std::map<std::string, BoneInfo> &GetBoneIDMap()
    {
        return m_BoneInfoMap;
    }

  private:
    void ReadHeirarchyData(AssimpNodeData &dest, const aiNode *src);
    void ReadMissingBones(const aiAnimation *animation, Model &model);

    float m_Duration;
    int m_TicksPerSecond;
    std::vector<Bone> m_Bones;
    AssimpNodeData m_RootAssimpDataNode;
    std::map<std::string, BoneInfo> m_BoneInfoMap;
};
