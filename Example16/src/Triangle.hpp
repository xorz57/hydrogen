#pragma once

#include "EBO.hpp"
#include "Texture.hpp"
#include "VAO.hpp"
#include "VBO.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

class Triangle {
public:
    Triangle();

    void Draw() const;
    void Delete() const;

private:
    struct Vertex {
        glm::vec3 position;
        glm::vec2 textureCoordinates;
    };

    const std::vector<Vertex> mVertices{
            {{-0.5f, -0.5f, +0.0f}, {+0.0f, +0.0f}},// 0
            {{+0.5f, -0.5f, +0.0f}, {+1.0f, +0.0f}},// 1
            {{+0.0f, +0.5f, +0.0f}, {+0.5f, +1.0f}},// 2
    };

    const std::vector<GLuint> mElements{
            0,// 0
            1,// 1
            2,// 2
    };

    VAO mVAO;
    VBO<Vertex> mVBO{mVertices};
    EBO<GLuint> mEBO{mElements};
    Texture mTexture{"assets/textures/texture.png"};
};