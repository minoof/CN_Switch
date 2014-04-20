#include <iostream>
#include "Ethernet.h"

using namespace std;

Ethernet::Ethernet(string inputName){
	name = inputName;
	vlan = 1;
	allocated = false;
	fd = -1;
	ip = "None";
	subnet = 0;
	mac = "None";
}
Ethernet::~Ethernet(){
	 name = "";
	 ip = "None";
	 subnet = 0;
	 mac = "None";
	 vlan = 0;
	 allocated = false;
	 fd = -1;
}
string Ethernet::get_name(){
	return name;
}
bool Ethernet::set_ip(string inputIP){
	ip = inputIP;
	return true;
}
string Ethernet::get_ip(){
	return ip;
}
bool Ethernet::set_subnet(int inputSubnet){
	subnet = inputSubnet;
	return true;
}
int Ethernet::get_subnet(){
	return subnet;
}
bool Ethernet::set_mac(string inputMac){
	mac = inputMac;
	return true;
}
string Ethernet::get_mac(){
	return mac;
}
bool Ethernet::set(int inputVlan){
	vlan = inputVlan;
	return true;
}
int Ethernet::get_vlan(){
	return vlan;
}
bool Ethernet::is_allocated(){
	return allocated;
}
bool Ethernet::set_allocate(string status){
	if (status == "busy")
		allocated = true;
	else if (status == "free")
		allocated = false;
	else return false;
	return true;
}
bool Ethernet::set_fd(int inputFd){
	fd = inputFd;
	return true;
}
int Ethernet::get_fd(){
	return fd;
}