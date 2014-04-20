#include <iostream>
#include <vector>
#include "Switch.h"

using namespace std;


Switch::Switch (){
	listen_port  = -1;
}
bool Switch::set_listen_port(int port){
	listen_port = port;
	return true;
}
//get the listen port 
int Switch::get_listen_port(){
	return  listen_port;
}
//if there is Ethernet with same return false else return true and add it to ethernets
bool Switch::add_ethernet(string eth_name){
	Ethernet* eth = new Ethernet(eth_name);
	ethernets.push_back(eth);
	return true;
}
//get the eth with that name
Ethernet* Switch::get_ethernet(string eth_name){
	for(int i =0 ; i < ethernets.size() ; i++ ){
		if(ethernets[i]->get_name().compare(eth_name) == 0){
			return ethernets[i];
		}
	}
	return NULL;
}
//returns all ethernets
vector<Ethernet*> Switch::get_all_ethernets(){
	return ethernets;
}
//get empty ethernet
/*Ethernet get_empty_ethernet(){

}*/
//remove ethernet with this name if there is no eth with this name return false
bool Switch::remove_ethernet(string eth_name){
	for(int i =0 ; i < ethernets.size() ; i++ ){
		if(ethernets[i]->get_name().compare(eth_name) == 0){
			ethernets[i]->~Ethernet();
			ethernets.erase(ethernets.begin()+i);
			return true;
		}
	}
	return false;
}
//set the eth vlan if there is no eth with this name return false
bool Switch::set_vlan(string eth_name , int vlan){

}
//connect eth to another eth in another switch 
bool Switch::connect(string eth_name1 , string eth_name2 , int port){

}