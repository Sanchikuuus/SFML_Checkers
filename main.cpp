#include "iostream"
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Checker.h"
#include "PlayField.h"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "Checkers");

    PlayField board;

    board.Fill();

    board.SetScale(sf::Vector2<float>(1024/1800.0, 1024/1800.0));

    Checker ch1("Red", 50, 50, board.GetScele());

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
//		window.draw(ch1.GetSprite());


//		for(Checker* checker : board.GetList("Red")) {
//            window.draw(checker->GetSprite());
//		}
//		for(Checker* checker : board.GetList("White")) {
//            window.draw(checker->GetSprite());
//		}

		window.display();
	}

	return 0;
}