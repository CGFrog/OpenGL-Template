#include <string>
class Shader {
public:

    unsigned int ID;
    void use();

    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;

    Shader(const std::string &vertPath, const std::string &fragPath);
    ~Shader();


private:
    
    std::string importShader(const std::string &shaderPath);
    void compileShaders(const std::string &vertShader, const std::string &fragShader);
};