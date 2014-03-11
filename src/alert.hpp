/*
 *  alert.hpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 1/7/14.
 *  Copyright (c) 2014 Usandfriends. All rights reserved.
 */

#ifndef SimpleChess_alert_hpp
#define SimpleChess_alert_hpp

/**
 * @todo Finish this.
 * @todo What are we going to do about the parent window?
 *      Maybe this:
 *          1. https://www.wxwidgets.org/downloads/
 *          2. http://docs.wxwidgets.org/trunk/group__group__funcmacro__dialog.html#ga193c64ed4802e379799cdb42de252647
 *          3. http://stackoverflow.com/questions/8094145/simple-alert-box-in-c-not-objective-c
 */

namespace SimpleChess {
	typedef class {
    public:
		sf::RenderWindow AlertBox,
                         *ConnecterWindow;

        void InitAlertBox(const std::string);
        void ShowAlertBox(void);
        void HideAlertBox(void);
        void NewWindowParent(sf::RenderWindow *);
	} Alert;
}

void SimpleChess::Alert::InitAlertBox(const std::string title) {
    this->AlertBox.create(sf::VideoMode(900, 640), title, sf::Style::Close);
    this->AlertBox.setFramerateLimit(5);
    this->HideAlertBox();
}

void SimpleChess::Alert::ShowAlertBox(void) {

}

void SimpleChess::Alert::HideAlertBox(void) {

}

#endif
