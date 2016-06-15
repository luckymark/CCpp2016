#include <SFML\Graphics.hpp>
#include "Application.hpp"
#include <iostream>

int main() {
	try {
		Application game;
		game.run();
	}catch (std::exception& exp) {
		std::cout << "\nException:  " << exp.what() << std::endl;
	}
	return 0;
}