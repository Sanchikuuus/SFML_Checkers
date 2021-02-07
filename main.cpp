#include "iostream"
#include <SFML/Graphics.hpp>
#include "PlayField.h"
using namespace std;

int main()
{
    const float windowSize = 800.0;

    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "15 puzzle");
    window.setFramerateLimit(60);

    PlayField board("15");

//    sf::Vector2<float> scale(windowSize/1800.0f, windowSize/1800.0f);

//    board.SetScale(scale);

    board.Fill();

    while (window.isOpen())
	{
        sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			    board.OnMouseDown(window);
            if (event.type == sf::Event::LostFocus)
            {
                board.SetColor(sf::Color(111, 111, 111, 111));
                board.Update(window);

                while(true)
                {
                    window.pollEvent(event);
                    if (event.type == sf::Event::GainedFocus)
                    {
                        board.SetColor(sf::Color(255, 255, 255, 255));
                        break;
                    }
                }
            }
		}

        board.Update(window);

	}

	return 0;
}
