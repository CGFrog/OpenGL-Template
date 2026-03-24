#include <vector>
#include "Vertex.hpp"
#include "../Texture/Texture.hpp"
#include <Shader.hpp>
#include <glad.h>
class Mesh{
public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    ~Mesh();

    void draw(Shader &shader);
private:
    unsigned int VAO, VBO, EBO;
    void setupMesh();
};