#ifndef SHADER_H
#define SHADER_H
#include <SFML/Graphics/Shader.hpp>

class Shader
{
    public:
        static Shader* instance();
        void load();
        sf::Shader* getInvertShader();
        sf::Shader* getLightShader();
    protected:
        Shader();
    private:
        sf::Shader invertShader;
        sf::Shader lightShader;
        static Shader* _instance;
        static std::string path;
};

#endif // SHADER_H
