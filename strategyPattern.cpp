#include<iostream>

using namespace std;

//interfaces defined 
class IMove{
public:
  virtual ~IMove(){}; 
  virtual void move()=0;
};

class IStop{
public:
  virtual ~IStop(){}; 
  virtual void stop()=0;
};


//defines the main vehicle class
class Vehicle{
public:
  void move();
  void stop();
  
  Vehicle(IMove*, IStop*);
  ~Vehicle(){delete moveBehavior; delete stopBehavior;};

  string getName()const{return name; }
  void setName (string newName){name=newName;}
private:
  string name;
  IMove *moveBehavior;
  IStop *stopBehavior;
};

//the main move and stop methods 
void Vehicle::move(){moveBehavior->move();} 
void Vehicle::stop(){stopBehavior->stop();}


//constructor just assigns the behaviors 
Vehicle::Vehicle(IMove *mb, IStop *sb):
  moveBehavior(mb), stopBehavior(sb){}

//different versions of fly/move implementing the interfaces
class FlyMovement: public IMove{
public:
  void move(){cout<<"Flying...."<<endl; }
};

class DriveMovement:public IMove{
public:
  void move(){cout<<"Driving..."<<endl;}
};

class FastStop:public IStop{
public:
  void stop(){cout<<"Stopping fast..."<<endl; }
};

class SlowStop:public IStop{
public:
  void stop(){cout<<"Stopping slow...."<<endl; }
};

int main(){
  //flying vehicle that stops slow
  FlyMovement *flyMove= new FlyMovement(); 
  SlowStop *slowStop = new SlowStop();

  Vehicle *slowFlyingVehicle= new Vehicle(flyMove, slowStop); 
  slowFlyingVehicle->setName("Slow flying Vehicle");
  cout<<"Name: "<<slowFlyingVehicle->getName()<<endl;

  slowFlyingVehicle->move(); 
  slowFlyingVehicle->stop();

  return 0;
}
