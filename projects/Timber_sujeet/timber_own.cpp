#include "unsigned_char_traits.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
using namespace sf;


int main(){ 
    //creating an videomode and opening an window for the game
    RenderWindow window(VideoMode(960, 540), "|| Timber ||");
    window.setFramerateLimit(60);
    View view(FloatRect(0, 0, 1920, 1080));
    window.setView(view);
  

    //creating texture to hold a graphic
    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background.png");
    Sprite spriteBackground(textureBackground);
    spriteBackground.setPosition(0, 0);
    

    Texture textureTree;
    textureTree.loadFromFile("graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810,0);

    Texture textureBee;
    textureBee.loadFromFile("graphics/bee.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0,800);
    bool beeActive=false;//is the bee moving
    float beeSpeed=0.0f;//speed of the bee

    Texture texturecloud;
    texturecloud.loadFromFile("graphics/cloud.png");
    Sprite spritecloud1;
    Sprite spritecloud2;
    Sprite spritecloud3;
    spritecloud1.setTexture(texturecloud);
    spritecloud2.setTexture(texturecloud);
    spritecloud3.setTexture(texturecloud);
    spritecloud1.setPosition(0,0);
    spritecloud2.setPosition(0,250);
    spritecloud3.setPosition(0,500);
    bool cloud1Active=false;
    bool cloud2Active=false;
    bool cloud3Active=false;
    float cloud1Speed=0.0f;
    float cloud2Speed=0.0f;
    float cloud3Speed=0.0f;

    Clock clock;
    bool paused=true;
    int score=0;

    Text messageText;
    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");
    messageText.setFont(font);
    messageText.setString("Please Enter to Start !");
    messageText.setCharacterSize(75);
    messageText.setFillColor(Color::White);

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score = 0");
    scoreText.setCharacterSize(75);
    scoreText.setFillColor(Color::White);

    //position of the text
    FloatRect textRect=messageText.getLocalBounds();
    messageText.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
    messageText.setPosition(1920/2.0f,1080/2.0f);
    scoreText.setPosition(20,20);

    while(window.isOpen()){
      Time dt=clock.restart();
      Event event;
      while (window.pollEvent(event))
        {
          if (event.type == event.Closed)
            {
              window.close();
            }
        }
      if(!paused){

      if(!beeActive){
        //How fast is the bee
        srand((int)time(0));
        beeSpeed=(rand()%200)+200;

        //How high is the bee
        srand((int)time(0)*10);
        float height=(rand()%500)+500;
        spriteBee.setPosition(2000,height);
        beeActive=true;

      }
      else{
        spriteBee.setPosition(spriteBee.getPosition().x-(beeSpeed*dt.asSeconds()),spriteBee.getPosition().y);
        if(spriteBee.getPosition().x<-100){
          beeActive=false;
        }
      }

      //managing the clouds
      //cloud1
      if(!cloud1Active){
        srand((int)time(0)*10);
        cloud1Speed=(rand()%200);

        srand((int)time(0)*10);
        float height=(rand()%150);
        spritecloud1.setPosition(-200,height);
        cloud1Active=true;
      }
      else{
        spritecloud1.setPosition(spritecloud1.getPosition().x+(cloud1Speed*dt.asSeconds()),spritecloud1.getPosition().y);
        if(spritecloud1.getPosition().x>1920){
          cloud1Active=false;
        }
      }
      //cloud2
      if(!cloud2Active){
        srand((int)time(0)*20);
        cloud2Speed=(rand()%150);

        srand((int)time(0)*20);
        float height=(rand()%300)-150;
        spritecloud2.setPosition(-200,height);
        cloud2Active=true;
      }
      else{
        spritecloud2.setPosition(spritecloud2.getPosition().x+(cloud2Speed*dt.asSeconds()),spritecloud2.getPosition().y);
        if(spritecloud2.getPosition().x>1920){
          cloud2Active=false;
        }
      }
      //cloud3
      if(!cloud3Active){
        srand((int)time(0)*30);
        cloud3Speed=(rand()%300);

        srand((int)time(0)*30);
        float height=(rand()%450)-150;
        spritecloud3.setPosition(-200,height);
        cloud3Active=true;
      }
      else{
        spritecloud3.setPosition(spritecloud3.getPosition().x+(cloud3Speed*dt.asSeconds()),spritecloud3.getPosition().y);
        if(spritecloud3.getPosition().x>1920){
          cloud3Active=false;
        }
      }
      std::stringstream ss;
      ss<<"Score = "<<score;
      scoreText.setString(ss.str());
    }

      if (event.type == Event::KeyReleased && !paused)
	      {
          if(Keyboard::isKeyPressed(Keyboard::Escape)){
              window.close();
          }
          if(Keyboard::isKeyPressed(Keyboard::Return)){ 
            paused=false;
          }
        }
          window.clear();
          window.draw(spriteBackground);
          window.draw(spritecloud1);
          window.draw(spritecloud2);
          window.draw(spritecloud3);
          window.draw(spriteTree);
          window.draw(spriteBee);
          window.draw(scoreText);
          if(paused){
            window.draw(messageText);
          }
          window.display();
      
  }
    return 0;
}
    