#include "iostream"
#include <SFML/Graphics.hpp>
#include "PlayField.h"
using namespace std;

int main()
{
    const float windowSize = 800.0;

    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Checkers");
    window.setFramerateLimit(60);

    PlayField board;

    sf::Vector2<float> scale(windowSize/1800.0f, windowSize/1800.0f);

    board.SetScale(scale);

    board.Fill();

    while (window.isOpen())
	{
        sf::Event event;
		while (window.pollEvent(event))
		{
//		    std::cout << event.type << std::endl;
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (event.type == sf::Event::LostFocus) {
		    while(window.pollEvent(event)) {
                if (event.type == sf::Event::GainedFocus)
                    break;
		    }
		}

		window.clear();
		window.draw(board.GetSprite());

        board.DrawAt(window);

		window.display();
	}

	return 0;
}