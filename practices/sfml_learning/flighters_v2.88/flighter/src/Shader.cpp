#include "Shader.h"
Shader* Shader::_instance = 0;
std::string Shader::path= "resources/shader/";
Shader::Shader()
{

}
Shader* Shader::instance()
{
    if(_instance == 0)
        _instance = new Shader;
    return _instance;
}
void Shader::load()
{
    if(sf::Shader::isAvailable())
    {
        invertShader.loadFromFile(path+"invert.frag",sf::Shader::Fragment);
        invertShader.setParameter("texture",invertShader.CurrentTexture);
        lightShader.loadFromFile(path+"light.frag",sf::Shader::Fragment);
        printf("load OK!\n");
    }
    else printf("Can't load shader!\n");

}
sf::Shader* Shader::getInvertShader()
{
    return &invertShader;
}
sf::Shader* Shader::getLightShader()
{
    return &lightShader;
}
