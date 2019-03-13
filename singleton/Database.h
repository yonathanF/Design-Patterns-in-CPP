/* Singleton Pattern
 *
 * A pattern that can sometimes be useful to create
 * only one instance of a class. Usually has the same
 * problems as global variables.
 */

#include<string> 
#include<iostream>

class DatabaseConnector{
  public: 
    static DatabaseConnector* getInstance(){
      return (!currentInstance) ? currentInstance = new DatabaseConnector():
	currentInstance;
    
    };
    void connect(){ std::cout << "Connected to the db!"<<std::endl; };
    void add(std::string value);

  private:
    DatabaseConnector() { std::cout << "Created connector. "<<std::endl; };
    static DatabaseConnector *currentInstance;
};
DatabaseConnector* DatabaseConnector::currentInstance= nullptr;
