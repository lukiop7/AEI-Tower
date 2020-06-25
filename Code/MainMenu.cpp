#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window) {

	image.loadFromFile("images/mainmenu.png");
	sprite.setTexture(image);

	play_text.loadFromFile("images/play.png");
	play.setTexture(play_text);
	play.setPosition(sf::Vector2f(213, 170));
	play.setColor(sf::Color(255, 0, 0, 255));

	exit_text.loadFromFile("images/exit.png");
	exit.setTexture(exit_text);
	exit.setColor(sf::Color(255, 255, 255, 255));
	exit.setPosition(sf::Vector2f(217, 370));

	options_text.loadFromFile("images/option.png");
	options.setTexture(options_text);
	options.setColor(sf::Color(255, 255, 255, 255));
	options.setPosition(sf::Vector2f(217, 270));


	MenuItem playButton;
	playButton.rect.top = 171;
	playButton.rect.height = 70;
	playButton.rect.left = 211;
	playButton.rect.width = 220;
	playButton.action = Play;
	playButton.button = 1;
	playButton.sprite = &play;

	MenuItem optionsButton;
	optionsButton.rect.top = 271;
	optionsButton.rect.height = 70;
	optionsButton.rect.left = 211;
	optionsButton.rect.width = 220;
	optionsButton.action = Options;
	optionsButton.button = 2;
	optionsButton.sprite = &options;


	MenuItem exitButton;
	exitButton.rect.top = 371;
	exitButton.rect.height = 70;
	exitButton.rect.left = 211;
	exitButton.rect.width = 220;
	exitButton.action = Exit;
	exitButton.button = 3;
	exitButton.sprite = &exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(optionsButton);
	_menuItems.push_back(exitButton);

	window.draw(sprite);
	window.draw(play);
	window.draw(options);
	window.draw(exit);
	window.display();
	
	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y) {
	std::list<MenuItem>::iterator it;

	for (it = _menuItems.begin(); it != _menuItems.end(); it++) {
		sf::Rect<int> menuItemRect = (*it).rect;
		if ((menuItemRect.top + menuItemRect.height) > y&& menuItemRect.top < y && menuItemRect.left<x && (menuItemRect.width + menuItemRect.left)>x) {
			return (*it).action;
		}
	}
	return Nothing;
}
MainMenu::MenuResult MainMenu::HandleKey(int x) {
	std::list<MenuItem>::iterator it;

	for (it = _menuItems.begin(); it != _menuItems.end(); it++) {
		if ((*it).button==x) {
			return (*it).action;
		}
	}
	return Nothing;
}

void MainMenu::UpdateButton(int x, sf::RenderWindow& window)
{
	sf::Color none(255, 255, 255, 255);
	sf::Color highlighted(255, 0, 0, 255);

	std::list<MenuItem>::iterator it;

	for (it = _menuItems.begin(); it != _menuItems.end(); it++) {
		if ((*it).button == x) {
			(*it) = highlighted;
		}
		else {
			(*it) = none;
		}
	}

	window.clear();
	window.draw(sprite);
	window.draw(play);
	window.draw(options);
	window.draw(exit);
	window.display();


}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window) {
	sf::Event menuEvent;
	int choice=1;
	while (true) {
		while (window.pollEvent(menuEvent)) {
			if (menuEvent.type == sf::Event::MouseButtonPressed) {
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::KeyPressed) {
				if (menuEvent.key.code == sf::Keyboard::Up) {
					if(choice!=1)
						choice--;
						UpdateButton(choice, window);
					
				}
				if (menuEvent.key.code == sf::Keyboard::Down) {
					if(choice!=3)
						choice++;
					UpdateButton(choice, window);
					
				}
				if (menuEvent.key.code == sf::Keyboard::Enter) {
					return HandleKey(choice);
				}
				if (menuEvent.key.code == sf::Keyboard::Space) {
					return HandleKey(choice);
				}
				
			}
			if (menuEvent.type == sf::Event::Closed) {
				return Exit;
			}
		}
	}

}