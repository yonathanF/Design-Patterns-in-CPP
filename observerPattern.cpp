#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
#include<string>

using namespace std; 

//forward definitions
class IObserver;
class IObservable;
class ChatServer;
class Client;

//observer interface
class IObserver{
public:
  virtual void update()const; 
  IObserver(IObservable*, int);
  virtual ~IObserver(){}
  bool operator==(const IObserver &rhs)const;
  int getId()const {return id; }

private:
  int id;
protected:
  IObservable *observable;
  
};

//constructor for observer
IObserver::IObserver(IObservable *obs, int newId): id(newId), observable(obs){} 

void IObserver::update()const{
  cout<<"Update recived...\t"<<endl;
}

//overload the == operator with ID
bool IObserver::operator==(const IObserver &rhs)const{
  if(this->id==rhs.getId())
    return true;

  return false; 
}
  
//observable abstract class
class IObservable{
public:
  virtual void sub(IObserver*);
  void unsub(IObserver);
  virtual string getState()const;
  virtual ~IObservable(){}

private:
  IObserver *observers[10]; 
    
protected:
  virtual void notify() const; 
};

//subscribes the object 
void IObservable::sub(IObserver *obs){
  observers[obs->getId()]=obs; 
}

//unsubscribes the passed observable
void IObservable::unsub(IObserver obs){
 delete  observers[obs.getId()];
}

//loops through every observable and calls update function
void IObservable::notify()const{
  for(int i=0; i<3; i++){
      observers[i]->update();
   }
  
}

//Default state for everything 
string IObservable::getState()const{
  return "New State";
}


//concrete classes
class ChatServer:public IObservable{
public:
  ChatServer(string serverName): name(serverName){}

  string getName()const{return name; }
  string getState()const{return lastMessage;}
  void setLastMessage(string message){lastMessage=message; notify();}

private:
  string name; 
  string lastMessage; 
};


class Client:public IObserver{
public:
  Client(string newName, IObservable *server, int id):IObserver(server, id), name(newName){server->sub(this);}

  void update()const; 
  string getName()const{return name; }

private:
  string name; 
};

void Client::update() const{
  cout<<name<<":\t recived message: "<<observable->getState()<<endl;
}


int main(){

  //server
  ChatServer *server= new ChatServer("Main Server");

  //chatters 
  IObserver *james= new Client("James", server, 0);
  IObserver *yonathan= new Client("Yonathan",server, 1); 
  IObserver *kim = new Client("kim", server, 2); 

  server->setLastMessage("Hello guys");
  server->setLastMessage("Hey everyone");
  server->setLastMessage("This is awesome!");
  
  return 0; 
  
}
