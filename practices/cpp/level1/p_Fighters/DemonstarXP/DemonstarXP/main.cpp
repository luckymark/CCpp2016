#include <SFML/Graphics.hpp>
int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1000, 800), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
		// load a 32x32 rectangle that starts at (10, 10)
		sf::Texture texture;
		if (!texture.loadFromFile("image.png"))
		{
		    // error...
		}
		sf::Sprite sprite;
		sprite.setTexture(texture);
		// position
		sprite.setPosition(sf::Vector2f(400, 720)); // absolute position
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        //window.draw(...);
		window.draw(sprite);
        // end the current frame
        window.display();
    }

    return 0;
}