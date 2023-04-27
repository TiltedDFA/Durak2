#include <SFML/Graphics.hpp>
#include "headers/Debug.hpp"
#include "headers/Button.hpp"
#include "headers/MainScreen.hpp"
int __MAIN
{
   sf::RenderWindow myWindow(sf::VideoMode(Screen::WIDTH,Screen::HEIGHT), "Durak");
   myWindow.setFramerateLimit(90);
   Resource_Manager instance;
   MainScreen* myScreen = new MainScreen();
   while (myWindow.isOpen())
   {
      sf::Event event{};
      while (myWindow.pollEvent(event))
      {
         if(event.type == sf::Event::Closed) myWindow.close();
      }
      myWindow.clear();
      myScreen->UpdateScreen(myWindow);
      myScreen->RenderScreen(myWindow);
      myWindow.display();
   }
   delete myScreen;
   return 0;
};