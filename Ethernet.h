#ifndef ETHERNET_H
#define ETHERNET_H
#include <iostream>
#include <vector>

using namespace std;


class Ethernet
{
  string name;
  string ip;
  int subnet;
  string mac;
  int vlan;
  bool allocated;
  int fd;

public:
  //set the name and false the alocated
  Ethernet(string name);
  ~Ethernet();
  string get_name();
  bool set_ip(string ip);
  string get_ip();
  bool set_subnet(int subnet);
  int get_subnet();
  bool set_mac(string mac);
  string get_mac();
  bool set(int vlan);
  int get_vlan();
  bool is_allocated();
  bool set_allocate(string status);
  bool set_fd(int fd);
  int get_fd();


};
#endif