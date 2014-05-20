/* keyboard "twin-stick" shooter...but with punches, move around wasd
 * and punch in direction of arrow keys.  possible movement based combos
 * ex. away->away->towards->punch = knockback punch
 *
 * TODO: - [-] add more robust ability system
 *         - [ ] add combos to ability system
 *       - [-] add enemies
 *       - [X] add collision with enemies
 *       - [ ] make abilities interact with enemies
 */

#include<iostream>
#include<SFML/Graphics.hpp>

#include"AssetManager.hpp"
#include"Player.hpp"
#include"Enemy.hpp"
#include"Animation.hpp"

using namespace std;

Player* player;
Enemy* enemy;
Animation* anim;

void update(sf::RenderWindow* window) {
    player->update();
    enemy->update(player->getPosition());
    if(player->collide(*enemy)) {
        // cout << "you lose!" << endl;
        // window->close();
    }
}

void render(sf::RenderWindow* window) {
    window->clear(sf::Color(75,75,75));
    player->draw(window);
    enemy->draw(window);
    anim->draw(window, 0, 0);
    window->display();
}

int main(void) {
    anim = new Animation("resources/penguin.png", 3, 2, 32);
    string title = "Punch Everything v.0.01";
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Event e;
    AssetManager manager;

    float fps = 1.0/60.0;
    double delta = 0.0;
    float elapsedTime = 0;

    window.create(sf::VideoMode(640,480), title);

    player = new Player(&manager);
    player->move(sf::Vector2f(200,200));
    enemy = new Enemy("resources/ship.png", &manager);
    // enemy->move(sf::Vector2f(100,200));

    while(window.isOpen()) {
        while(window.pollEvent(e)) {
            switch(e.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                    window.close();
                }
                break;
            default:
                break;
            }
        }
        // update throttling with sf::Clock object
        delta += elapsedTime/fps;
        elapsedTime = clock.getElapsedTime().asSeconds();
        while(delta >= 1.0) {
            delta -= 1.0;
            update(&window);
        }
        clock.restart();
        render(&window);
    }


    return 0;
}
