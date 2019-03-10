/* State Pattern 
 *
 * A nice pattern to avoid using too many conditionals when
 * working a system that moves between different states 
 * on different actions. This example implements a state machine for
 * a simple regular expression to show the idea: 
 * 	ab+a 
 */

#include <stdio.h>
#include <string>
#include "statePattern.h"
#include <iostream>

using namespace std; 

void State0::addNewCharacter(char newChar){
  if(newChar == 'a'){
    State::FA->goToState(State::FA->getState1());
  }
  else{
    State::FA->goToState(State::FA->getRejectState());
  }
}

bool State0::isValid(){
  return false;
}


void State1::addNewCharacter(char newChar){
  if(newChar == 'b'){
    State::FA->goToState(State::FA->getState2());
  }
  else{
    State::FA->goToState(State::FA->getRejectState());
  }
}

bool State1::isValid(){
  return false;
}


void State2::addNewCharacter(char newChar){
  if(newChar == 'b'){
    State::FA->goToState(State::FA->getState2());
  }
  else if(newChar == 'a'){
    State::FA->goToState(State::FA->getState3());
  }
  else{
    State::FA->goToState(State::FA->getRejectState());
  }
}

bool State2::isValid(){
  return false;
}

void State3::addNewCharacter(char newChar){
  State::FA->goToState(State::FA->getRejectState());
}

bool State3::isValid(){
  return true;
}

void RejectState::addNewCharacter(char newChar){
  State::FA->goToState(State::FA->getRejectState());
}

bool RejectState::isValid(){
  return false;
}


FiniteState::~FiniteState(){
   delete state0;
   delete state1;
   delete state2;
   delete state3;
   delete rejectState;
}

FiniteState::FiniteState(){
  state0 = new State0(this); 
  state1 = new State1(this);
  state2 = new State2(this);
  state3 = new State3(this);
  rejectState = new RejectState(this);
  currentState = state0;
}

int main(){

  FiniteState fa;
  fa.addNewCharacter('a');
  fa.addNewCharacter('b');
  fa.addNewCharacter('b');
  fa.addNewCharacter('b');
  fa.addNewCharacter('a');

  cout << "Valid: "<<fa.isValid()<<endl;

  return 0;
}
