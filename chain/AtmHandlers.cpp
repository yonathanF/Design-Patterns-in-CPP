#include "AtmHandlers.h"
#include<iostream>

int TwentyHandler::deposit(int value){
  if(value == 20) 
      return value+20;

  return nextHandler->deposit(value);
}


int FiftyHandler::deposit(int value){
  if(value == 50) 
      return value+50;

  return nextHandler->deposit(value);
}

int HundredHandler::deposit(int value){
  if(value == 100) 
      return value+100;

  return nextHandler->deposit(value);
}

int DefaultHandler::deposit(int value){
  return -1; 
}

int main(){
  ATMHandler *twenty = new TwentyHandler();
  ATMHandler *fifty = new  FiftyHandler();
  ATMHandler *hundred = new HundredHandler();
  ATMHandler *defaultH = new DefaultHandler();

  twenty->setNextHandler(fifty);
  fifty->setNextHandler(hundred);
  hundred->setNextHandler(defaultH);

  fifty->setPreviousHandler(twenty);
  hundred->setPreviousHandler(fifty);
  defaultH->setPreviousHandler(hundred);

  std::cout << twenty->deposit(20) << std::endl; 
  std::cout << twenty->deposit(50) << std::endl; 
  std::cout << twenty->deposit(100) << std::endl; 
  std::cout << twenty->deposit(1000) << std::endl; 

  return 0;
}
