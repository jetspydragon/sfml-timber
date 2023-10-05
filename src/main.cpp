#include "config.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    std::string resourcePath = RESOURCE_PATH;

    sf::VideoMode vm(WINDOW_WIDTH, WINDOW_HEIGHT);
    sf::RenderWindow window(vm, "Timber!!!", sf::Style::Titlebar);

    sf::Texture textureBackground;
    textureBackground.loadFromFile(resourcePath + "graphics/background.png");
    float scale = (float)WINDOW_WIDTH / textureBackground.getSize().x;
    sf::Vector2<float> vScale(scale, scale);

    sf::Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setScale(vScale);
    spriteBackground.setPosition(0, 0); 

    sf::Texture textureTree;
    textureTree.loadFromFile(resourcePath + "graphics/tree.png");
    sf::Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setScale(vScale);
    spriteTree.setPosition(810 * scale, 0);

    sf::Texture textureBee;
    textureBee.loadFromFile(resourcePath + "graphics/bee.png");
    sf::Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setScale(vScale);
    spriteBee.setPosition(0, 800 * scale);
    bool beeActive = false;
    float beeSpeed = 0.0f;

    sf::Texture textureCloud;
    textureCloud.loadFromFile(resourcePath + "graphics/cloud.png");
    sf::Sprite spriteCloud1;
    sf::Sprite spriteCloud2;
    sf::Sprite spriteCloud3;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);
    spriteCloud1.setScale(vScale);
    spriteCloud2.setScale(vScale);
    spriteCloud3.setScale(vScale);
    spriteCloud1.setPosition(0, 0);
    spriteCloud2.setPosition(0, 250 * scale);
    spriteCloud3.setPosition(0, 500 * scale);
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    while (window.isOpen()) {
        // Handle player input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }
        
        // Update


        // Draw
        window.clear();
        window.draw(spriteBackground);
        window.draw(spriteTree);
        window.draw(spriteBee);
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);

        // Muestra lo que se estuvo renderizando en el buffer de pantalla
        window.display();
    }

    return 0;
}