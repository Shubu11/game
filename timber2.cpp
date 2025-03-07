#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;	
using namespace std;


int main() {
	VideoMode vm(1600, 900);
	View view(FloatRect(0, 0, 1600, 900));
	RenderWindow window(vm, "Timber");
	window.setView(view);
  
	Texture textureBG, textureTree, textureCloud, textureBee, textureLeaves, texturePlayer;
	textureBG.loadFromFile("graphics/background.jpeg");
	textureTree.loadFromFile("graphics/tree.png");
	textureCloud.loadFromFile("graphics/cloud.png");
	textureBee.loadFromFile("graphics/bee.png");
	textureLeaves.loadFromFile("graphics/branch.png");
	texturePlayer.loadFromFile("graphics/player.png");
  
	Sprite spriteBG, spriteTree, spriteCloud1, spriteCloud2, spriteCloud3, spriteBee, spriteLeaves, spritePlayer;
	spriteBG.setTexture(textureBG);
	spriteTree.setTexture(textureTree);
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);
	spriteBee.setTexture(textureBee);
	spriteLeaves.setTexture(textureLeaves);
	spritePlayer.setTexture(texturePlayer);
  
	spriteBG.setPosition(0, 0);
	spriteTree.setPosition(650, 0);
	spriteCloud1.setPosition(450, -50);
	spriteCloud2.setPosition(866, 50);
	spriteCloud3.setPosition(555, 0);
	spriteBee.setPosition(999, 555);
	spriteLeaves.setPosition(950, 333);
	spritePlayer.setPosition(500, 708);

	bool beeActive = false;
	float beeSpeed = 0.0;
	
	bool cloud1Active = false, cloud2Active = false, cloud3Active = false;
	float cloud1Speed = -0.6, cloud2Speed = 0.0, cloud3Speed = -0.3;
	
	Clock clock;

  while(window.isOpen()) {
	Event event1;
	while(window.pollEvent(event1)) {
		if(event1.type == event1.Closed) {
			window.close();
		}
	}
	if(Keyboard::isKeyPressed(Keyboard::Escape)) {
	    window.close();
	    cout << "Exited !" << endl;
	    return 0;
	}
	
	Time dt = clock.restart();
	if(!beeActive) {
		srand((int)time(0));
		beeSpeed = rand()%200 + 200;
		
		srand((int)time(0) * 10);
		float height = rand() % 400 + 400;
		spriteBee.setPosition(1700, height);
		
		beeActive = true;
	} else {
		spriteBee.setPosition(spriteBee.getPosition().x-(beeSpeed*dt.asSeconds()), spriteBee.getPosition().y);
		
		if(spriteBee.getPosition().x < -100) {
			beeActive = false;
		}
	}
	
	if(!cloud1Active) {
		srand((int)time(0));
		cloud1Speed = rand()%200 + 200;
		
		srand((int)time(0) * 10);
		float height = rand() % 50 + 50;
		spriteCloud1.setPosition(-400, height);
		
		cloud1Active = true;
	} else {
		spriteCloud1.setPosition(spriteCloud1.getPosition().x+(cloud1Speed*dt.asSeconds()), spriteCloud1.getPosition().y);
		
		if(spriteCloud1.getPosition().x > 1800) {
			cloud1Active = false;
		}
	}
	
	if(!cloud2Active) {
		srand((int)time(0));
		cloud2Speed = rand()%200 + 200;
		
		srand((int)time(0) * 10);
		float height = rand() % 50 + 50;
		spriteCloud2.setPosition(-999, height);
		
		cloud2Active = true;
	} else {
		spriteCloud2.setPosition(spriteCloud2.getPosition().x+(cloud2Speed*dt.asSeconds()), spriteCloud2.getPosition().y);
		
		if(spriteCloud2.getPosition().x > 1800) {
			cloud2Active = false;
		}
	}
	
	if(!cloud3Active) {
		srand((int)time(0));
		cloud3Speed = rand()%200 + 200;
		
		srand((int)time(0) * 10);
		float height = rand() % 50+ 50;
		spriteCloud3.setPosition(-1200, height);
		
		cloud3Active = true;
	} else {
		spriteCloud3.setPosition(spriteCloud3.getPosition().x+(cloud3Speed*dt.asSeconds()), spriteCloud3.getPosition().y);
		
		if(spriteCloud3.getPosition().x > 1800) {
			cloud3Active = false;
		}
	}
	
	window.clear();
	window.draw(spriteBG);
	window.draw(spriteTree);
	window.draw(spriteCloud1);
	window.draw(spriteCloud2);
	window.draw(spriteCloud3);
	window.draw(spriteBee);
	window.draw(spriteLeaves);
	window.draw(spritePlayer);
	window.display();
  }	

  return 0;
}
