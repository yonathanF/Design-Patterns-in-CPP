#include "CoffeeCommand.h"

void MochaCommand::make(){
  mocha.addMilk();
  mocha.addChocolate();
  mochaCount++;
}

int MochaCommand::undo(){
  mochaCount--;
  return mochaCount;
}

void LatteCommand::make(){
  latte.addBasicFlavor();
  latteCount++;
}

int LatteCommand::undo(){
  latteCount--;
  return latteCount;
}

// client 
int main(){
  Barista b;
  Mocha m;
  MochaCommand a(m);
  b.order(&a);
  b.order(&a);

  std::cout << "Undo: " << a.undo() << std::endl;
  std::cout << "Undo: " << a.undo() << std::endl;

  Latte l;
  LatteCommand L(l);
  b.order(&L);

  return 0;
}
