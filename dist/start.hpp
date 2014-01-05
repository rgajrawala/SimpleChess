/*
 *  start.hpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 12/01/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
 */

#ifndef SimpleChess_start_hpp
#define SimpleChess_start_hpp

/**
 * The StartPage class.
 * The main starting page or menu is created and handled here.
 */
class StartPage {
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
public:
    
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
} StartPage;

////////// SOURCE //////////

void StartPage::Initialize(void) {
    this->Window.create(sf::VideoMode(600, 600), "SimpleChess - Start Page", sf::Style::Close);
    this->Window.setFramerateLimit(10);
    
    if (!this->Icon.loadFromFile(GetResource("white_knight.png"))) {
        exit(EXIT_FAILURE);
    }
    this->Window.setIcon(this->Icon.getSize().x, this->Icon.getSize().y, this->Icon.getPixelsPtr());
    
    if(!this->Font.loadFromFile(GetResource("sansation.ttf"))) {
        exit(EXIT_FAILURE);
    }
    
    this->Title.setFont(this->Font);
    this->Title.setString("SimpleChess");
    this->Title.setPosition(20.0, 50.0);
    this->Title.setCharacterSize(100);
    
    this->NewGameText.setColor(sf::Color::Blue);
    
    this->NewGameButton.setFillColor(sf::Color::Yellow);
    this->NewGameButton.setSize(sf::Vector2f(300.0, 50.0));
    this->NewGameButton.setPosition(150.0, 200.0);
    
    this->ReaderButton.setFillColor(sf::Color::Yellow);
    this->ReaderButton.setSize(sf::Vector2f(300.0, 50.0));
    this->ReaderButton.setPosition(150.0, 275.0);
    
    this->NewGameText.setFont(this->Font);
    this->NewGameText.setColor(sf::Color::Blue);
    this->NewGameText.setPosition(200.0, 200.0);
    this->NewGameText.setCharacterSize(40);
    this->NewGameText.setString("New Game");
    
    this->ReaderText.setFont(this->Font);
    this->ReaderText.setColor(sf::Color::Blue);
    this->ReaderText.setPosition(230.0, 275.0);
    this->ReaderText.setCharacterSize(40);
    this->ReaderText.setString("Reader");
    
    this->WhoWonText.setFont(this->Font);
    if(this->WhoWon == 1) {
        this->WhoWonText.setString("White (Player 1) Won!");
    } else if(this->WhoWon == 2) {
        this->WhoWonText.setString("Black (Player 2) Won!");
    } else {
        this->WhoWonText.setString("");
    }
    this->WhoWonText.setPosition(80.0, 310.0);
    this->WhoWonText.setCharacterSize(25);
    
    this->WhoWon = 0;
}

void StartPage::CleanUp(void) {
    this->Window.close();
}

void StartPage::OnMouseMove(void) {
    this->Mouse.x = Event.mouseMove.x;
    this->Mouse.y = Event.mouseMove.y;
}

void StartPage::OnKeyPressed(void) {
    if(((this->Event.key.code is sf::Keyboard::W or this->Event.key.code is sf::Keyboard::C) and this->Event.key.control) or ((this->Event.key.code is sf::Keyboard::W or this->Event.key.code is sf::Keyboard::C) and this->Event.key.alt)) {
        this->CleanUp();
        exit(EXIT_SUCCESS);
    }
}

void StartPage::OnMouseButtonReleased(void) {
    if(Utils.Contains(this->Mouse.x, this->Mouse.y, this->NewGameButton.getPosition().x, this->NewGameButton.getPosition().y, this->NewGameButton.getSize().x, this->NewGameButton.getSize().y)) {
        Sounds.Music3.play();
        this->Go = true;
        this->CleanUp();
    } else if(Utils.Contains(this->Mouse.x, this->Mouse.y, this->ReaderButton.getPosition().x, this->ReaderButton.getPosition().y, this->ReaderButton.getSize().x, this->ReaderButton.getSize().y)) {
        Sounds.Music3.play();
        this->Go = false;
        this->CleanUp();
    }
}

void StartPage::OnEvent(void) {
    switch(this->Event.type) {
        case sf::Event::Closed: exit(EXIT_SUCCESS);
        case sf::Event::KeyPressed: this->OnKeyPressed(); break;
        case sf::Event::MouseMoved: this->OnMouseMove(); break;
        case sf::Event::MouseButtonReleased: this->OnMouseButtonReleased(); break;
        default: break;
    }
}

bool StartPage::Main(void) {
    this->Initialize();
    while(this->Window.isOpen()) {
        this->Window.clear(sf::Color::Black);
        
        while(this->Window.pollEvent(this->Event)) {
            this->OnEvent();
        }
        
        this->Window.draw(this->Title);
        this->Window.draw(this->NewGameButton);
        this->Window.draw(this->NewGameText);
        this->Window.draw(this->ReaderButton);
        this->Window.draw(this->ReaderText);
        this->Window.draw(this->WhoWonText);
        this->Window.display();
    }
    
    return this->Go;
}

void StartPage::SetWhoWon(short whowon) {
    if(whowon > 2 or whowon < 0) {
        return;
    }
    
    this->WhoWon = whowon;
}

#endif
