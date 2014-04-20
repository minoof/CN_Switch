//////////////////////////////////////////////////
//	In this class we are going to implement this tasks:
//		1-MAC macAdress		//set the MAC address of the host
//		2-IP IPaddress/subnetmask   //set the ip and subnetmask of host
//		3-Connect portnumber	//connect to switch that listen on the portnumber
//		4-Ping IPaddress	//send package to IPaddres
//		5-Disconnect		//close the connection to switch
//		6-Exit			//close the connection if the host is connected to switch and then close the program.
//	
//////////////////////////////////////////////////

#include <iostream>
#include "tools.h"

using namespace std;

int main(){
	//TODO
	//create a pointer to singleton network
	//add this host to network
	while(true){
		string input;
		string command;
		vector<string> parts ;
		cin >> input;

		if(input.size() > 1 ){

			parts = parseCommand(input);

			command = parts [0];
		}
		else{
			
			cout<<"Please enter somthing ..." << endl;
			continue;
		}
		cerr<<"---"<<command<<"-----"<<endl;
		if( command.compare("MAC") == 0 ){
			
			continue;
		}

		if( command.compare("IP") == 0 ){
			
			//TODO	:
			//      add new Eth to switchs

			continue;
		}

		if( command.compare("Connect") == 0 )
			//TODO :
			//	delete the Eth

			continue;
		}

		if( command.compare("Ping") == 0 ){
			


			continue;
		}

		if( command.compare("Disconnect") == 0 ){
			

			continue;
		}

		if( command.compare("Exit") == 0 ){
			
			continue;
		}

		
		//TODO:
		// 	cout list of commands


					
		


	}

}
