/*
 *  alert.hpp
 *  SimpleChess
 *
 *  Created by Usandfriends on 1/7/14.
 *  Copyright (c) 2014 Usandfriends. All rights reserved.
 */

#ifndef SimpleChess_alert_hpp
#define SimpleChess_alert_hpp

/**
 * @todo Finish this.
 * @todo What are we going to do about the parent window?
 *	  Maybe this:
 *		  1. https://www.wxwidgets.org/downloads/
 *		  2. http://docs.wxwidgets.org/trunk/group__group__funcmacro__dialog.html#ga193c64ed4802e379799cdb42de252647
 *		  3. http://stackoverflow.com/questions/8094145/simple-alert-box-in-c-not-objective-c
 *
 * @note Badly broken! I'm giving up on it for now...
 */

namespace SimpleChess {
	namespace Alert {
		sf::RenderWindow AlertBox;

		std::string InputAlert(sf::RenderWindow *, std::string, std::string, const std::string);
	};
}

std::string SimpleChess::Alert::InputAlert(sf::RenderWindow *parent, std::string title, std::string message, const std::string prompt) {
	if (parent is NULL) {
		return NULL;
	}

	(*parent).setVisible(false);
	(*parent).setActive(false);

	sf::Font Font;
	if (not Font.loadFromFile(Resources::GetResource("sansation.ttf"))) {
		exit(EXIT_FAILURE);
	}

	/** @note Was forced to put this here. Was getting EXC_BAD_ACCESS before. */
	sf::Text Message;
	Message.setPosition(10.0, 30.0);
	Message.setCharacterSize(13);
	Message.setColor(sf::Color::White);
	Message.setFont(Font);
	Message.setString(message);

	if (title.length() > 99) {
		title = title.substr(0, 96);
		title += "...";
	}

	if (message.length() > 389) {
		message = message.substr(0, 386);
		message += "...";
	}

	for (unsigned short iter = 0; iter < message.length(); iter += 40) {
		message.insert(iter, "\n");
	}

	std::string retVal = "";

	AlertBox.create(sf::VideoMode(500, 400), title, sf::Style::Close);
	AlertBox.setFramerateLimit(5);
	AlertBox.setTitle(title);

	std::cout << prompt;

	while (AlertBox.isOpen()) {
		AlertBox.clear(sf::Color::Black);

		sf::Event Event;
		while (AlertBox.pollEvent(Event)) {
			switch (Event.type) {
				case sf::Event::Closed: {
					AlertBox.close();
				} break;
				case sf::Event::TextEntered: {
					const char tmp = static_cast<char>(Event.text.unicode);
					if (tmp == '\n') {
						AlertBox.close();
					} else if (tmp == '\b') {
						std::cout << "\b \b"; /** @note Prints some wierd stuff on XCode's Output Terminal. */
						if (retVal.length() > 1) {
							retVal = retVal.substr(0, retVal.length() - 1);
						} else if (retVal.length() == 1) {
							retVal = "";
						}
					} else {
						std::cout << tmp;
						retVal += tmp;
					}
				} break;
				default: {}
			}
		}

		AlertBox.draw(Message);
		AlertBox.display();
	}

	AlertBox.close();

	(*parent).setVisible(true);
	(*parent).setActive(true);

	return retVal;
}

#endif
