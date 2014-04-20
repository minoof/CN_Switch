#ifndef SWITCH_H
#define SWITCH_H
#include <iostream>
#include <vector>
#include <utility>
#include "Ethernet.h"


class Switch
{
  vector<Ethernet*> ethernets;
  
  int listen_port;

public:
  //create a switch create ethernets  field set the listen port to -1
  Switch ();
  //if switch already listen to a port return false else return true and listen to that port and set it in listen_port field
  bool set_listen_port(int port);
  //get the listen port 
  int get_listen_port();
  //if there is Ethernet with same return false else return true and add it to ethernets
  bool add_ethernet(std::string eth_name);
  //get the eth with that name
  Ethernet* get_ethernet(std::string eth_name);
  //returns all ethernets
  std::vector<Ethernet*> get_all_ethernets();
  //get empty ethernet
  Ethernet* get_empty_ethernet();
  //remove ethernet with this name if there is no eth with this name return false
  bool remove_ethernet(std::string name);
  //set the eth vlan if there is no eth with this name return false
  bool set_vlan(std::string eth_name , int vlan);
  //connect eth to another eth in another switch 
  bool connect(std::string eth_name1 , std::string eth_name2 , int port);
};
#endif