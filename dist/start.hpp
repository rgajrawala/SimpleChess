/*
 *  start.hpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 12/01/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
 */

#ifndef SimpleChess_start_hpp
#define SimpleChess_start_hpp

namespace SimpleChess {
    /**
     * The StartPage class.
     * The main starting page or menu is created and handled here.
     */
    namespace StartPage {
        sf::RenderWindow Window; /**< The window of the menu. */
        sf::Font Font; /**< The font that the text on the menu will use (sansation.ttf). */
        sf::Event Event; /**< Any window events. */
        sf::Vector2u Mouse; /**< Mouse coordinates. */
        sf::Image Icon; /**< The icon for the window */
        
        sf::Text Title; /**< The menu's title. Will say: "Simple Chess". */
        sf::Text WhoWonText; /**< Shows who won. */
        
        sf::RectangleShape NewGameButton; /**< The button for New Game. */
        sf::Text NewGameText; /**< Will say: "New Game". */
        sf::RectangleShape ReaderButton; /**< The button for the reader. */
        sf::Text ReaderText; /**< Will say: "Reader". */
        
        short WhoWon = 0; /**< Who won the game. 1 if white won. 2 if black won. 0 if game is still playing or tie. */
        bool Go; /**< True if to go to game, otherwise false if to go to reader. */
        
        /**
         * Creates the menu and other important parts of the start page.
         */
        void Initialize(void);
        
        /**
         * Closes the window.
         */
        void CleanUp(void);
        
        /**
         * Main loop for the start page.
         * Initializes, runs / loops, and cleans up.
         * @return True if to go to game, false if to go to reader.
         */
        bool Main(void);
        
        /**
         * Draws the window.
         */
        void Draw(void);
        
        /**
         * Event handler for window events.
         */
        void OnEvent(void);
        
        /**
         * Event handler for mouse moves.
         * @see OnEvent
         */
        void OnMouseMove(void);
        
        /**
         * Event handler for key presses.
         * @see OnEvent
         */
        void OnKeyPressed(void);
        
        /**
         * Handler for mouse button releases.
         * @see OnEvent
         */
        void OnMouseButtonReleased(void);
        
        /**
         * Sets WhoWon.
         * @see WhoWon
         */
        void SetWhoWon(short);
    };
};

////////// SOURCE //////////

void SimpleChess::StartPage::Initialize(void) {
    Window.create(sf::VideoMode(600, 600), "SimpleChess - Start Page", sf::Style::Close);
    Window.setFramerateLimit(10);
    
    if (!Icon.loadFromFile(GetResource("white_knight.png"))) {
        exit(EXIT_FAILURE);
    }
    Window.setIcon(Icon.getSize().x, Icon.getSize().y, Icon.getPixelsPtr());
    
    if(!Font.loadFromFile(GetResource("sansation.ttf"))) {
        exit(EXIT_FAILURE);
    }
    
    Title.setFont(Font);
    Title.setString("SimpleChess");
    Title.setPosition(20.0, 50.0);
    Title.setCharacterSize(100);
    
    NewGameButton.setFillColor(sf::Color::Yellow);
    NewGameButton.setSize(sf::Vector2f(300.0, 50.0));
    NewGameButton.setPosition(150.0, 200.0);
    
    ReaderButton.setFillColor(sf::Color::Yellow);
    ReaderButton.setSize(sf::Vector2f(300.0, 50.0));
    ReaderButton.setPosition(150.0, 275.0);
    
    NewGameText.setFont(Font);
    NewGameText.setColor(sf::Color::Blue);
    NewGameText.setPosition(200.0, 200.0);
    NewGameText.setCharacterSize(40);
    NewGameText.setString("New Game");
    
    ReaderText.setFont(Font);
    ReaderText.setColor(sf::Color::Blue);
    ReaderText.setPosition(230.0, 275.0);
    ReaderText.setCharacterSize(40);
    ReaderText.setString("Reader");
    
    WhoWonText.setFont(Font);
    WhoWonText.setPosition(80.0, 310.0);
    WhoWonText.setCharacterSize(25);
    if(WhoWon == 1) {
        WhoWonText.setString("White (Player 1) Won!");
    } else if(WhoWon == 2) {
        WhoWonText.setString("Black (Player 2) Won!");
    } else if(WhoWon == -1) {
        WhoWonText.setString(" There was an error!");
    } else {
        WhoWonText.setString("");
    }
    
    WhoWon = 0;
}

void SimpleChess::StartPage::CleanUp(void) {
    Window.close();
}

void SimpleChess::StartPage::OnMouseMove(void) {
    Mouse.x = Event.mouseMove.x;
    Mouse.y = Event.mouseMove.y;
}

void SimpleChess::StartPage::OnKeyPressed(void) {
    if(((Event.key.code is sf::Keyboard::W or Event.key.code is sf::Keyboard::C) and Event.key.control) or ((Event.key.code is sf::Keyboard::W or Event.key.code is sf::Keyboard::C) and Event.key.alt)) {
        CleanUp();
        exit(EXIT_SUCCESS);
    }
}

void SimpleChess::StartPage::OnMouseButtonReleased(void) {
    if(Utils::Contains(Mouse.x, Mouse.y, NewGameButton.getPosition().x, NewGameButton.getPosition().y, NewGameButton.getSize().x, NewGameButton.getSize().y)) {
        Sounds::Music3.play();
        Go = true;
        CleanUp();
    } else if(Utils::Contains(Mouse.x, Mouse.y, ReaderButton.getPosition().x, ReaderButton.getPosition().y, ReaderButton.getSize().x, ReaderButton.getSize().y)) {
        Sounds::Music3.play();
        Go = false;
        CleanUp();
    }
}

void SimpleChess::StartPage::OnEvent(void) {
    switch(Event.type) {
        case sf::Event::Closed: Window.close(); Window.setSize(sf::Vector2u(0, 0)); exit(EXIT_SUCCESS);
        case sf::Event::KeyPressed: OnKeyPressed(); break;
        case sf::Event::MouseMoved: OnMouseMove(); break;
        case sf::Event::MouseButtonReleased: OnMouseButtonReleased(); break;
        default: break;
    }
}

void SimpleChess::StartPage::Draw(void) {
    Window.clear(sf::Color::Black);
    Window.draw(Title);
    Window.draw(NewGameButton);
    Window.draw(NewGameText);
    Window.draw(ReaderButton);
    Window.draw(ReaderText);
    Window.draw(WhoWonText);
    Window.display();
}

bool SimpleChess::StartPage::Main(void) {
    Initialize();
    
    while(Window.isOpen()) {
        Draw();
        
        while(Window.pollEvent(Event)) {
            OnEvent();
        }
    }
    
    return Go;
}

void SimpleChess::StartPage::SetWhoWon(short whowon) {
    if(whowon > 2 or whowon < -1 or whowon == 0) {
        return;
    }
    
    WhoWon = whowon;
}

#endif
