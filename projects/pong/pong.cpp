#include "unsigned_char_traits.hpp"
#include "bat.h"
#include "ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
int main()
{

VideoMode vm(960, 540);
RenderWindow window(vm, "Pong Game");
int score = 0;
int lives = 3;

//cretating bat at the bottom center of screen
Bat bat(960 / 2, 540 - 20);
Ball ball(960 / 2, 0);

//hud
Text hud;
//  font
Font font;
font.loadFromFile("fonts/KOMIKAP_.ttf");

hud.setFont(font);

hud.setCharacterSize(75);

hud.setFillColor(Color::White);
hud.setPosition(20, 20);
Clock clock;


//game loop
while (window.isOpen())
{


Event event;
		while(window.pollEvent(event)){
			if(event.type==Event::Closed){
				window.close();
			}
		}
		if(Keyboard::isKeyPressed(Keyboard::Escape)){
			window.close();
		}
		if(Keyboard::isKeyPressed(Keyboard::Left)){
			bat.moveLeft();
		}
		else{
			bat.stopLeft();
		}
		if(Keyboard::isKeyPressed(Keyboard::Right)){
			bat.moveRight();
		}
		else{
			bat.stopRight();
		}
		Time dt=clock.restart();
		bat.update(dt);
		ball.update(dt);
		std::stringstream ss;
		ss << "Score:" << score << " Lives:" << lives;
		hud.setString(ss.str());
		
		if (ball.getPosition().top > window.getSize().y)
{

ball.reboundBottom();

lives--;

if (lives < 1) {

score = 0;

lives = 3;
}
}
if (ball.getPosition().top < 0)
{
ball.reboundBatOrTop();

score++;
}

if (ball.getPosition().left < 0 ||
ball.getPosition().left + ball.getPosition().width> window.
getSize().x)
{
ball.reboundSides();
}


if (ball.getPosition().intersects(bat.getPosition()))
{

ball.reboundBatOrTop();
}





window.clear();

window.draw(hud);
window.draw(bat.getShape());
window.draw(ball.getShape());
window.display();



}

return 0;

}