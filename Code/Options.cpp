#include "Options.h"

Options::Options()
{
	Load("images/options.png");
	_sound = 1;
	_music = 1;
	font.loadFromFile("comic.ttf");
	text_sound.setFont(font);
	text_music.setFont(font);
	text_sound.setCharacterSize(60);
	text_music.setCharacterSize(60);
	text_sound.setFillColor(sf::Color::White);
	text_music.setFillColor(sf::Color::Red);
	text_sound.setPosition(338, 299);
	text_music.setPosition(338, 79);
	text_sound.setString("<ON");
	text_music.setString("<ON");


	OptionsItem music;
	music.nb = 1;
	music.text = &text_music;
	music.second = "OFF>";

	OptionsItem sound;
	sound.nb = 2;
	sound.text = &text_sound;
	sound.second = "OFF>";

	_optionsItems.push_back(music);
	_optionsItems.push_back(sound);
	

}

Options::~Options()
{
}


Options::OptionsResult Options::Option(sf::RenderWindow& window)
{

	static int choice = 1;
	static int side = 2;
	sf::Event menuEvent;
	while (true) {
		while (window.pollEvent(menuEvent)) {
			if (menuEvent.type == sf::Event::KeyPressed) {
				if (menuEvent.key.code == sf::Keyboard::Up) {
					if (choice == 2)
						choice=1;
					UpdateChoice(choice);

				}
				if (menuEvent.key.code == sf::Keyboard::Down) {
					if (choice ==1)
						choice=2;
					UpdateChoice(choice);

				}
				if (menuEvent.key.code == sf::Keyboard::Left) {
					side = 1;
					UpdateOption(choice, side);
					
				}
				if (menuEvent.key.code == sf::Keyboard::Right) {
					side = 2;
					UpdateOption(choice, side);
					
				}
				if (menuEvent.key.code == sf::Keyboard::Escape) {
					return Back;
				}

			}
			if (menuEvent.type == sf::Event::Closed) {
				return Exit;
			}
		}
		Show(window);
	}
	
}

void Options::Show(sf::RenderWindow& window)
{
	Screen::Show(window);
	window.draw(*_optionsItems.front().text);
	window.draw(*_optionsItems.back().text);
	window.display();
}

void Options::UpdateChoice(int x)
{
	if (x == 1) {
		_optionsItems.front() = sf::Color::Red;
		_optionsItems.back() = sf::Color::White;
		
	}
	if (x == 2) {
		_optionsItems.front() = sf::Color::White;
		_optionsItems.back() = sf::Color::Red;
	
	}

}

void Options::UpdateOption(int x, int y)
{
	if (x == 1) {
		_optionsItems.front() = _optionsItems.front().second;
		if (y == 2)
			_music = 1;
		else
			_music = 0;
	}
	if (x == 2) {
		_optionsItems.back() = _optionsItems.back().second;
		if (y == 2)
			_sound = 1;
		else
			_sound = 0;
	}
}

