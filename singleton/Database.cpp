#include "Database.h"
#include<iostream>

int main(){
  DatabaseConnector *db = db->getInstance();

  // this doesn't create a new instance 
  DatabaseConnector *db2 = db2->getInstance();
  db->connect();
  db->connect();
  db->connect();

  // connects using the same instance
  db2->connect();

  return 0;
}
