#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio.hpp>
int main() {
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Cube Singleplayer", sf::Style::Titlebar | sf::Style::Close); 
    window.setFramerateLimit(60);
    sf::RectangleShape square(sf::Vector2f(150.f, 150.f));
    square.setPosition({200.f, 200.f});
    square.setFillColor(sf::Color::Green);
    square.setOutlineThickness(1);
    square.setOutlineColor(sf::Color::Blue);
    sf::RectangleShape square1(sf::Vector2f(150.f, 150.f));
    square1.setPosition({500.f, -200.f});
    square1.setFillColor(sf::Color::Cyan);
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) {
        return -1;
    }
    sf::Text text(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition({20.f, 20.f});
    text.setString("WASD - Control");
    sf::Font font2;
    if (!font2.openFromFile("arial.ttf")) {
        return -1;
    }
    sf::Text text2(font2);
    text2.setCharacterSize(30);
    text2.setFillColor(sf::Color::White);
    text2.setPosition({20.f, 70.f});
    text2.setString("M - Stop Music, P - Play Music");
    sf::Music music;
    if (!music.openFromFile("0823.ogg")) {
        return -1;
    }
    sf::Font font3;
    if (!font.openFromFile("arial.ttf")) {
        return -1;
    }
    sf::Text text3(font3);
    text3.setCharacterSize(20);
    text3.setFillColor(sf::Color::Black);
    text3.setOutlineThickness(2);
    text3.setOutlineColor(sf::Color::White);
    text3.setString("E - Activate");
    music.setLooping(true);
    music.play();
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        float speed = 4.0f;
        sf::Vector2f pos = square.getPosition();
        sf::Vector2f pos1 = square1.getPosition();
        sf::Vector2f pos2 = text3.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) { pos.y -= speed; std::cout << ", W: "; std::cout << pos.y;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) { pos.y += speed; std::cout << ", S: "; std::cout << pos.y;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) { pos.x -= speed; std::cout << ", A: "; std::cout << pos.x;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) { pos.x += speed; std::cout << ", D: "; std::cout << pos.x;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M)) {
            music.stop();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
            music.play();
        }
        
        square.setPosition(pos);
        window.clear(sf::Color::Black);

        window.draw(square);
        window.draw(text);
        window.draw(text2);
        window.draw(text3);
        window.display();
        
    }

    return 0;
}