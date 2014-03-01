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
    SimpleChess::StartPage::Window.create(sf::VideoMode(600, 600), "SimpleChess - Start Page", sf::Style::Close);
    SimpleChess::StartPage::Window.setFramerateLimit(10);
    
    if (!SimpleChess::StartPage::Icon.loadFromFile(GetResource("white_knight.png"))) {
        exit(EXIT_FAILURE);
    }
    SimpleChess::StartPage::Window.setIcon(SimpleChess::StartPage::Icon.getSize().x, SimpleChess::StartPage::Icon.getSize().y, SimpleChess::StartPage::Icon.getPixelsPtr());
    
    if(!SimpleChess::StartPage::Font.loadFromFile(GetResource("sansation.ttf"))) {
        exit(EXIT_FAILURE);
    }
    
    SimpleChess::StartPage::Title.setFont(SimpleChess::StartPage::Font);
    SimpleChess::StartPage::Title.setString("SimpleChess");
    SimpleChess::StartPage::Title.setPosition(20.0, 50.0);
    SimpleChess::StartPage::Title.setCharacterSize(100);
    
    SimpleChess::StartPage::NewGameButton.setFillColor(sf::Color::Yellow);
    SimpleChess::StartPage::NewGameButton.setSize(sf::Vector2f(300.0, 50.0));
    SimpleChess::StartPage::NewGameButton.setPosition(150.0, 200.0);
    
    SimpleChess::StartPage::ReaderButton.setFillColor(sf::Color::Yellow);
    SimpleChess::StartPage::ReaderButton.setSize(sf::Vector2f(300.0, 50.0));
    SimpleChess::StartPage::ReaderButton.setPosition(150.0, 275.0);
    
    SimpleChess::StartPage::NewGameText.setFont(SimpleChess::StartPage::Font);
    SimpleChess::StartPage::NewGameText.setColor(sf::Color::Blue);
    SimpleChess::StartPage::NewGameText.setPosition(200.0, 200.0);
    SimpleChess::StartPage::NewGameText.setCharacterSize(40);
    SimpleChess::StartPage::NewGameText.setString("New Game");
    
    SimpleChess::StartPage::ReaderText.setFont(SimpleChess::StartPage::Font);
    SimpleChess::StartPage::ReaderText.setColor(sf::Color::Blue);
    SimpleChess::StartPage::ReaderText.setPosition(230.0, 275.0);
    SimpleChess::StartPage::ReaderText.setCharacterSize(40);
    SimpleChess::StartPage::ReaderText.setString("Reader");
    
    SimpleChess::StartPage::WhoWonText.setFont(SimpleChess::StartPage::Font);
    SimpleChess::StartPage::WhoWonText.setPosition(80.0, 310.0);
    SimpleChess::StartPage::WhoWonText.setCharacterSize(25);
    if(SimpleChess::StartPage::WhoWon == 1) {
        SimpleChess::StartPage::WhoWonText.setString("White (Player 1) Won!");
    } else if(SimpleChess::StartPage::WhoWon == 2) {
        SimpleChess::StartPage::WhoWonText.setString("Black (Player 2) Won!");
    } else if(SimpleChess::StartPage::WhoWon == -1) {
        SimpleChess::StartPage::WhoWonText.setString(" There was an error!");
    } else {
        SimpleChess::StartPage::WhoWonText.setString("");
    }
    
    SimpleChess::StartPage::WhoWon = 0;
}

void SimpleChess::StartPage::CleanUp(void) {
    SimpleChess::StartPage::Window.close();
}

void SimpleChess::StartPage::OnMouseMove(void) {
    SimpleChess::StartPage::Mouse.x = Event.mouseMove.x;
    SimpleChess::StartPage::Mouse.y = Event.mouseMove.y;
}

void SimpleChess::StartPage::OnKeyPressed(void) {
    if(((SimpleChess::StartPage::Event.key.code is sf::Keyboard::W or SimpleChess::StartPage::Event.key.code is sf::Keyboard::C) and SimpleChess::StartPage::Event.key.control) or ((SimpleChess::StartPage::Event.key.code is sf::Keyboard::W or SimpleChess::StartPage::Event.key.code is sf::Keyboard::C) and SimpleChess::StartPage::Event.key.alt)) {
        SimpleChess::StartPage::CleanUp();
        exit(EXIT_SUCCESS);
    }
}

void SimpleChess::StartPage::OnMouseButtonReleased(void) {
    if(Utils.Contains(SimpleChess::StartPage::Mouse.x, SimpleChess::StartPage::Mouse.y, SimpleChess::StartPage::NewGameButton.getPosition().x, SimpleChess::StartPage::NewGameButton.getPosition().y, SimpleChess::StartPage::NewGameButton.getSize().x, SimpleChess::StartPage::NewGameButton.getSize().y)) {
        SimpleChess::Sounds::Music3.play();
        SimpleChess::StartPage::Go = true;
        SimpleChess::StartPage::CleanUp();
    } else if(Utils.Contains(SimpleChess::StartPage::Mouse.x, SimpleChess::StartPage::Mouse.y, SimpleChess::StartPage::ReaderButton.getPosition().x, SimpleChess::StartPage::ReaderButton.getPosition().y, SimpleChess::StartPage::ReaderButton.getSize().x, SimpleChess::StartPage::ReaderButton.getSize().y)) {
        SimpleChess::Sounds::Music3.play();
        SimpleChess::StartPage::Go = false;
        SimpleChess::StartPage::CleanUp();
    }
}

void SimpleChess::StartPage::OnEvent(void) {
    switch(SimpleChess::StartPage::Event.type) {
        case sf::Event::Closed: SimpleChess::StartPage::Window.close(); SimpleChess::StartPage::Window.setSize(sf::Vector2u(0, 0)); exit(EXIT_SUCCESS);
        case sf::Event::KeyPressed: SimpleChess::StartPage::OnKeyPressed(); break;
        case sf::Event::MouseMoved: SimpleChess::StartPage::OnMouseMove(); break;
        case sf::Event::MouseButtonReleased: SimpleChess::StartPage::OnMouseButtonReleased(); break;
        default: break;
    }
}

void SimpleChess::StartPage::Draw(void) {
    SimpleChess::StartPage::Window.clear(sf::Color::Black);
    SimpleChess::StartPage::Window.draw(SimpleChess::StartPage::Title);
    SimpleChess::StartPage::Window.draw(SimpleChess::StartPage::NewGameButton);
    SimpleChess::StartPage::Window.draw(SimpleChess::StartPage::NewGameText);
    SimpleChess::StartPage::Window.draw(SimpleChess::StartPage::ReaderButton);
    SimpleChess::StartPage::Window.draw(SimpleChess::StartPage::ReaderText);
    SimpleChess::StartPage::Window.draw(SimpleChess::StartPage::WhoWonText);
    SimpleChess::StartPage::Window.display();
}

bool SimpleChess::StartPage::Main(void) {
    SimpleChess::StartPage::Initialize();
    
    while(SimpleChess::StartPage::Window.isOpen()) {
        SimpleChess::StartPage::Draw();
        
        while(SimpleChess::StartPage::Window.pollEvent(SimpleChess::StartPage::Event)) {
            SimpleChess::StartPage::OnEvent();
        }
    }
    
    return SimpleChess::StartPage::Go;
}

void SimpleChess::StartPage::SetWhoWon(short whowon) {
    if(whowon > 2 or whowon < -1 or whowon == 0) {
        return;
    }
    
    SimpleChess::StartPage::WhoWon = whowon;
}

#endif
