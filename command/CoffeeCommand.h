/* Command Pattern
 *
 * A pattern that nicely encapsulates method calls.
 * Seems very useful for calling multiple methods
 * with no common interface.
 * 
 */

#include<iostream>

class CoffeeCommand {
  public: 
    virtual void make()=0;
    virtual int undo()=0;
};

class Barista{
  public:
    void order(CoffeeCommand *coffee){coffee->make();};
};

class Mocha{
  public:
    void addMilk(){std::cout << "Added milk to mocha."<<std::endl;}
    void addChocolate(){std::cout << "Added chocolate to mocha."<<std::endl;}
};

class Latte{
  public:
    void addBasicFlavor(){std::cout << "Added some basic flavors."<<std::endl;}
};

class LatteCommand : public CoffeeCommand {
  public:
    LatteCommand(Latte latte):latte(latte), latteCount(0){}
    void make();
    int undo();
  private:
    Latte latte;
    int latteCount;
};

class MochaCommand : public CoffeeCommand {
  public: 
    MochaCommand(Mocha mocha):mocha(mocha), mochaCount(0){}
    void make();
    int undo();

  private:
    Mocha mocha;
    int mochaCount;

};
