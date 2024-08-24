#include <SFML\Graphics.hpp> 
#include <SFML\Window.hpp> 
#include <iostream> 
#include <Windows.h> 
#include <vector> 
#include <math.h> 
#include <SFML\Audio.hpp> 

using namespace std; 
const float bKiri = 300; 
const float bKanan = 1200; 
//batas kanan dan kiri object rudal

double rSpeed = 5; 
double airspeed = 1; 
//air speed dan rudal speed

string stringTank1 = ""; 
string stringTank2 = ""; 
string stringHitler = ""; 
//string score 

int scoreTank1 = 0; 
int scoreTank2 = 0; 
int scoreHitler = 100000; 
//starting score 

const int screenx = 1600; 
const int screeny = 900; 
//batas layar 

const int tank1x = 250; 
const int tank1y = 130; 
// tank 1 

const int tank2x = 250; 
const int tank2y = 130; 
// tank 2 
int getRandomNumber(int a, int b) 
{ 
    static bool first = true; 
    if (first) 
    { 
        srand(time(NULL)); 
        first = false;
    }
    int result = a + rand() % ((b + 1) - a); 
    result = (result / 10) * 10; 
    return result; 
} 
int getRandomNumber(int a, int b); 
int main() 
{ 
    sf::RenderWindow Menu(sf::VideoMode(1600, 900), "I Gusti Ngurah  Agung 072-0073", sf::Style::Close); 
    //Untuk main Menu 

    sf::RectangleShape Menuback(sf::Vector2f(1600.0f, 900.0f)); 
    sf::Texture MenuTexture; 
    MenuTexture.loadFromFile("Menu.png"); 
    Menuback.setTexture(&MenuTexture); 

    sf::SoundBuffer MenuSong; 
    sf::Sound MenuSong1; 
    MenuSong1.setVolume(60); 
    if (!MenuSong.loadFromFile("Nazi.wav")) 
        std::cout << "ERROR" << std::endl; 
    //Main Menu Song 

    MenuSong1.setBuffer(MenuSong); 
    //Menu Song set 

    while (Menu.isOpen()) 
    {
      sf::Event Menu1; 
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F)) Menu.close(); 
      while (Menu.pollEvent(Menu1)) 
      { 
        if (MenuSong1.getStatus() == 0) 
        {
          MenuSong1.play(); 
        } 
        Menu.display(); 
        Menu.clear(); 
        Menu.draw(Menuback); 
        if (Menu1.type == Menu1.Closed) 
        { 
          Menu.close(); 
        } 
      } 
    } 
    sf::RenderWindow Tutorial(sf::VideoMode(1600, 900), "I Gusti Ngurah  Agung 072-0073 Tutorial Tank", sf::Style::Close); 
     //window untuk tutor 
 
    sf::RectangleShape Tutorial2(sf::Vector2f(1600.0f, 900.0f)); 
    sf::Texture Tutorialtexture; 
    Tutorialtexture.loadFromFile("Tutorial.png"); 
    Tutorial2.setTexture(&Tutorialtexture); 
     //Tutor texture 
    while (Tutorial.isOpen()) 
    { 
      sf::Event TutorialBar; 
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F)) Tutorial.close(); 
      while (Tutorial.pollEvent(TutorialBar)) 
      { 
        Tutorial.display(); 
        Tutorial.clear(); 
        Tutorial.draw(Tutorial2); 
        if (TutorialBar.type == TutorialBar.Closed)
        { 
          Tutorial.close();
        }
      }
    }
      sf::RenderWindow Scoring(sf::VideoMode(1600, 900), "I Gusti Ngurah  Agung 072-0073 Tutor score", sf::Style::Close); 
      //window untuk score

      sf::RectangleShape Scoring2(sf::Vector2f(1600.0f, 900.0f)); 
      sf::Texture Scoringtexture; 
      Scoringtexture.loadFromFile("TutorialScore.png"); 
      Scoring2.setTexture(&Scoringtexture); 
      //score background

     while (Scoring.isOpen()) 
     { 
       sf::Event ScoringBar; 
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F)) 
         Scoring.close(); 
       while (Scoring.pollEvent(ScoringBar)) 
       {
         Scoring.display(); 
         Scoring.clear(); 
         Scoring.draw(Scoring2); 
         if (ScoringBar.type == ScoringBar.Closed) 
         { 
           Scoring.close(); 
         } 
       } 
     } 
  sf::Font font; 
  font.loadFromFile("Franchise.ttf"); 
 //font score 
  sf::SoundBuffer Tembak1; 
  sf::Sound Tembak11; 
  Tembak11.setVolume(60); 
  if (!Tembak1.loadFromFile("loaded.wav")) 
    std::cout << "ERROR" << std::endl; 
  //sound tembak tank 

  sf::SoundBuffer Tembak2; 
  sf::Sound Tembak22;

  if (!Tembak2.loadFromFile("loadedtank2.wav")) 
    std::cout << "ERROR" << std::endl; 
  //sound tembak tank 2

  Tembak11.setBuffer(Tembak1); 
  //set tembak 1 
  Tembak22.setBuffer(Tembak2); 
  //set tembak 2

  sf::SoundBuffer Sound1; 
  sf::Sound Sound2; 
  if (!Sound1.loadFromFile("sound1.ogg")) 
    std::cout << "ERROR" << std::endl; 
    //bg music

  Sound2.setBuffer(Sound1); 
  //bg music set

  sf::SoundBuffer Collision1; 
  sf::Sound Collision11;

  if (!Collision1.loadFromFile("Tank.wav")) 
    std::cout << "ERROR" << std::endl; 
    //suara ledak impact

  Collision11.setBuffer(Collision1); 
  //set ledakan 

  sf::SoundBuffer Collision2; 
  sf::Sound Collision22; 

  if (!Collision2.loadFromFile("Collision2.wav")) 
    std::cout << "ERROR" << std::endl; 
  //suara ledak impact tank 2 
  
  Collision22.setBuffer(Collision2); 
  //set ledakan

  sf::RenderWindow window(sf::VideoMode(screenx, screeny), "I Gusti Ngurah  Agung 072-0073 Games", sf::Style::Close); 
  window.setFramerateLimit(60); 
  //window untuk Games 

  double Tank1X, Tank1Y; 
  double Tank2X, Tank2Y; 
  Tank1X = 2 * screenx / 7; 
  Tank1Y = 2 * screeny / 5; 
  Tank2X = 4.5 * screenx / 7; 
  Tank2Y = 2 * screeny / 5; 
  sf::RectangleShape Backgrnd(sf::Vector2f(1600.0f, 900.0f)); 
  sf::Texture BackgrndTexture; 
  BackgrndTexture.loadFromFile("BackgroundAkhirnya2.png"); 
  Backgrnd.setTexture(&BackgrndTexture); 
  //Background kota Berlin 

  sf::Texture rudal; 
  if (!rudal.loadFromFile("rudal.png")) 
  return EXIT_FAILURE; 
  sf::Sprite Rudal(rudal); 
  double RudalX, RudalY; 
  bool rudalNabrak = false; 
  RudalX = getRandomNumber(bKiri, bKanan); 
  RudalY = 0; 
  //rudal

  sf::SoundBuffer Rudal1; 
  sf::Sound Rudal11; 
  Rudal11.setVolume(60);

  if (!Rudal1.loadFromFile("rudal.wav")) 
    std::cout << "ERROR" << std::endl; 
  //sound rudal

  Rudal11.setBuffer(Rudal1); 
  sf::Texture airdrop; 

  if (!airdrop.loadFromFile("loot.png")) 
    return EXIT_FAILURE; 
  
  sf::Sprite AIRDROP(airdrop); 
  double airX, airY; 
  bool airnabrak = false; 
  airX = getRandomNumber(bKiri, bKanan); 
  airY = -1000; 
  //airdrop 

  sf::SoundBuffer air1; 
  sf::Sound air11; 
  air11.setVolume(60); 
  if (!air1.loadFromFile("loot.wav")) 
  std::cout << "ERROR" << std::endl; 
  //sound airdrop 

  air11.setBuffer(air1);
  int duar; 
  duar = 0; 
  sf::CircleShape shape(9.f); 
  std::vector<sf::CircleShape> peluru; 
  shape.setFillColor(sf::Color::Black); 
  //bullet player 1 

  bool pencet = false; 
  int duar2; 
  duar2 = 0; 
  sf::CircleShape shape2(9.f); 
  std::vector<sf::CircleShape> peluru2; 
  shape2.setFillColor(sf::Color::Black); 
  //bullet player 2 

  sf::RectangleShape Tank(sf::Vector2f(160.0f, 80.0f)); 
  Tank.setPosition(Tank1X, Tank1Y); 
  sf::Texture TankTexture; 
  TankTexture.loadFromFile("tank1.png"); 
  Tank.setTexture(&TankTexture); 
  //Tank player 1 

  sf::RectangleShape Tank2(sf::Vector2f(160.0f, 80.0f));
  Tank2.setPosition(Tank2X, Tank2Y); 
  sf::Texture TankTexture2; 
  TankTexture2.loadFromFile("tank2.png"); 
  Tank2.setTexture(&TankTexture2); 
   //Tank player 2 

  while (window.isOpen()) 
  {
    MenuSong1.stop();  
    stringTank1 = "P1 SKOR : " + to_string(scoreTank1); 
    sf::Text TextP1(stringTank1, font, 30); 
    TextP1.setFillColor(sf::Color::Black); 
    TextP1.setPosition(82, 25);

    stringTank2 = "P2 SKOR: " + to_string(scoreTank2); 
    sf::Text TextP2(stringTank2, font, 30); 
    TextP2.setFillColor(sf::Color::Black); 
    TextP2.setPosition(1230, 19); 
    stringHitler = "HITLER RUDAL: " + to_string(scoreHitler); 
    sf::Text TextHitler(stringHitler, font, 30); 
    TextHitler.setFillColor(sf::Color::Yellow); 
    TextHitler.setPosition(615, 25); 
    
    window.clear(sf::Color::White); 
    window.draw(Backgrnd); 
    window.draw(Tank); 
    window.draw(Tank2); 
    window.draw(Rudal); 
    window.draw(AIRDROP); 
    for (int i = 0; i < peluru2.size(); i++) 
    { 
      window.draw(peluru2[i]); 
    } 
    for (int i = 0; i < peluru.size(); i++) 
    {
      window.draw(peluru[i]); 
    } 
    window.draw(TextP1); 
    window.draw(TextP2);
    window.draw(TextHitler); 
    window.display(); 
    if (scoreHitler < scoreTank1 || scoreHitler < scoreTank2)
    { 
      window.close(); 
    }
    Tank.setPosition(Tank1X, Tank1Y); 
    Tank2.setPosition(Tank2X, Tank2Y); 
    AIRDROP.setPosition(airX, airY); 
    Rudal.setPosition(RudalX, RudalY);
    
    if (RudalY > 400 || rudalNabrak) 
    { 
      rudalNabrak = false; 
      RudalY = 0; 
      RudalX = getRandomNumber(bKiri, bKanan); 
    } 
    else 
    { 
      RudalY = RudalY + rSpeed; 
    }
    if (airY > 400 || airnabrak) 
    { 
      airnabrak = false; 
      airY = -500; 
      airX = getRandomNumber(bKiri, bKanan); 
    } 
    else 
    { 
      airY = airY + airspeed; 
    }
    sf::Event tbarcntrl; 
    while (window.pollEvent(tbarcntrl))
    {
      if (tbarcntrl.type == tbarcntrl.Closed)
      {
        window.close(); 
      }
    }
    //TABRAKAN Tank1 
    if (((Tank1X >= (RudalX - 100)) && (Tank1X <= (RudalX + 100))) && ((Tank1Y >= (RudalY - 100)) && (Tank1Y) <= (RudalY + 100))) 
    {
      rudalNabrak = true; 
      scoreHitler = scoreHitler + 100; 
      scoreTank1 = scoreTank1 - 100; 
      Rudal11.play(); 
    };

    //TABRAKAN Tank2 
    if (((Tank2X >= (RudalX - 100)) && (Tank2X <= (RudalX + 100))) && ((Tank2Y >= (RudalY - 100)) && (Tank2Y) <= (RudalY + 100))) 
    {
      rudalNabrak = true; 
      scoreHitler = scoreHitler + 100; 
      scoreTank2 = scoreTank2 - 100; 
      Rudal11.play(); 
    };
    
    //TABRAKAN loot 
    if (((Tank1X >= (airX - 100)) && (Tank1X <= (airX + 100))) && ((Tank1Y >= (airY - 100)) && (Tank1Y) <= (airY + 100))) 
    {
      airnabrak = true; 
      scoreTank1 = scoreTank1 + 3000; 
      air11.play(); 
    };
    
    //TABRAKAN loot 2 
    if (((Tank2X >= (airX - 100)) && (Tank2X <= (airX + 100))) && ((Tank2Y >= (airY - 100)) && (Tank2Y) <= (airY + 100))) 
    {
      airnabrak = true; 
      scoreTank2 = scoreTank2 + 3000; 
      air11.play();
    };
    if (Sound2.getStatus() == 0) 
      Sound2.play(); 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) 
    { 
      pencet = true; 
    } 
    if (duar2 >= 30 && !sf::Keyboard::isKeyPressed(sf::Keyboard::L) && pencet) 
    { 
      Tembak22.play(); 
      pencet = false; 
      shape2.setPosition(Tank2.getPosition().x + 90, Tank2.getPosition().y + 30); 
      peluru2.push_back(sf::CircleShape(shape2)); 
      duar2 = 0; 
    } 
    if (duar2 < 30) 
    { 
      duar2++; 
    }
    for (int h = 0; h < peluru2.size(); h++) //tank2 
    { 
      peluru2[h].move(-8.0f, 0.0f); 
      if (peluru2[h].getGlobalBounds().intersects(Tank.getGlobalBounds())) 
      { 
        std::cout << "Player 2 hit"; 
        Collision22.play(); 
        peluru2.erase(peluru2.begin() + h); 
        scoreTank2 = scoreTank2 + 300; 
      }
      else if (peluru2[h].getPosition().x > 1600 || peluru2[h].getPosition().x < 300) 
      { 
        peluru2.erase(peluru2.begin() + h); 
      } 
    }
    if (duar >= 30 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) 
    { 
      Tembak11.play(); 
      shape.setPosition(Tank.getPosition().x + 90, Tank.getPosition().y + 30); 
      peluru.push_back(sf::CircleShape(shape)); 
      duar = 0; 
    } 
    if (duar < 30) 
    { 
      duar++; 
    } 
    for (int i = 0; i < peluru.size(); i++) //tank1 
    { 
      peluru[i].move(8.0f, 0.0f); 
      if 
        (peluru[i].getGlobalBounds().intersects(Tank2.getGlobalBounds())) 
      { 
        std::cout << "player hit"; 
        Collision11.play(); 
        peluru.erase(peluru.begin() + i); 
        scoreTank1 = scoreTank1 + 300; 
      } 
      else if (peluru[i].getPosition().x > 1250 ||peluru[i].getPosition().x < 0) 
      { 
        peluru.erase(peluru.begin() + i); 
      } 
    } 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
      if (Tank1Y > 200)
      {
        Tank1Y = Tank1Y - 2; 
      } 
    } 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) 
    { 
      if (Tank1X < 700) 
      { 
        Tank1X = Tank1X + 2; 
      } 
    } 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) 
    { 
      if (Tank1Y < 460) 
      { 
        Tank1Y = Tank1Y + 2; 
      } 
    } 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) 
    { 
      if (Tank1X > 400) 
      { 
        Tank1X = Tank1X - 2; 
      } 
    } 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) 
    { 
      if (Tank2Y > 200) 
      { 
        Tank2Y = Tank2Y - 2; 
      } 
    } 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) 
    { 
      if (Tank2X < 1050) 
      { 
        Tank2X = Tank2X + 2; 
      } 
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) 
    { 
      if (Tank2Y < 460) 
      { 
        Tank2Y = Tank2Y + 2; 
      } 
    } 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) 
    { 
      if (Tank2X > 700) 
      { 
        Tank2X = Tank2X - 2; 
      } 
    } 
  } 
  
  sf::RenderWindow Finish(sf::VideoMode(1600, 900), "I Gusti Ngurah  Agung 072-0073 FINISH", sf::Style::Close);
  //Untuk Ending 
  
  sf::RectangleShape Finish1(sf::Vector2f(1600.0f, 900.0f)); 
  sf::Texture Finish11; 
  Finish11.loadFromFile("finish.png"); 
  Finish1.setTexture(&Finish11); 
  //finish background 
  
  sf::SoundBuffer FinishSong; 
  sf::Sound FSong; 
  FSong.setVolume(100); 
  if (!FinishSong.loadFromFile("play1.ogg")) 
    std::cout << "ERROR" << std::endl; 
  //Finish Song 
  
  FSong.setBuffer(FinishSong); 
 //Finish song 
  
  while (Finish.isOpen()) 
  { 
    sf::Event FinishGame; 
    if (scoreTank1 > scoreHitler) 
    { 
      Tank.setPosition(450, 450);  
      Finish.draw(Tank);
    } 
    if (scoreTank2 > scoreHitler) 
    { 
      Tank2.setPosition(450, 450); 
      Finish.draw(Tank2); 
    } 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F)) 
      Finish.close(); 
    while (Finish.pollEvent(FinishGame)) 
    { 
      if (FSong.getStatus() == 0) 
      { 
        FSong.play(); 
      } 
      Finish.display(); 
      Finish.clear(); 
      Finish.draw(Finish1); 
      
      if (FinishGame.type == FinishGame.Closed) 
      { 
        Finish.close(); 
      } 
    } 
  } 
  std::vector<sf::CircleShape>(); 
  return 0;
} 


    
  }





 

  
