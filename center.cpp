#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <sstream>
#include "tools.h"
#include "Switch.h"

using namespace std;

int main(){
	//TODO
	//create a pointer to singleton network
	//add this switch to network
	Switch* thisSwitch = new Switch();
	while(true){
		string input = "";
		string command = "";

		char buffer[BUFFER_SIZE];
		memset(buffer,'\0',BUFFER_SIZE);

		int length = read(0,buffer,BUFFER_SIZE);
		buffer[length-1]='\0';
		input = buffer;
		vector<string> parts ;
		

		if(input.size() > 1 ){

			parts = parseCommand(input);

			command = parts [0];
		}
		else{
			
			cout<<"Please enter something ..." << endl;
			continue;
		}
		cerr<<"---"<<parts[0]<<"-----"<<endl;
		if( command.compare("ListenPort") == 0 ){
			
			//TODO :
			//	check if this switch has already listen to a port.
			//	create a thread to listen to that port.
			if (parts.size() != 2){
				memset(buffer,'\0',BUFFER_SIZE);
				strcat(buffer,"Invalid Command.Correct Form is:ListenPort portnumber\n");
			}
			else{
				int port = atoi(parts[1].c_str());
				thisSwitch->set_listen_port(port);
				memset(buffer,'\0',BUFFER_SIZE);
				strcat(buffer,"port ");
				strcat(buffer, parts[1].c_str());
				strcat(buffer," assigned to this switch successfully.\n");
			}
			write(1,buffer,BUFFER_SIZE);	
			continue;
		}

		if( command.compare("Eth") == 0 ){
			
			//TODO	:
			//      add new Eth to switch
			if(parts.size()!=2){
				memset(buffer,'\0',BUFFER_SIZE);
				strcat(buffer,"Invalid Command.Correct Form is:Eth Ethname\n");
			}
			else if (thisSwitch->get_listen_port() == -1){
				memset(buffer,'\0',BUFFER_SIZE);
				strcat(buffer,"First of all, Set port number via command ListenPort\n");
			}
			else{
				string ethname = parts[1];
				thisSwitch->add_ethernet(ethname);
				memset(buffer,'\0',BUFFER_SIZE);
				strcat(buffer, "ethernet ");
				strcat(buffer, thisSwitch->get_ethernet(ethname)->get_name().c_str());
				strcat(buffer," added successfully.\n");
			}
			write(1,buffer,BUFFER_SIZE);
			continue;
		}

		if( command.compare("NoEth") == 0 ){
			
			//TODO :
			//	delete the Eth
			if(parts.size()!=2){
				memset(buffer,'\0',BUFFER_SIZE);
				strcat(buffer,"Invalid Command.Correct Form is:NoEth Ethname\n");
			}
			else if (thisSwitch->get_listen_port() == -1){
				memset(buffer,'\0',BUFFER_SIZE);
				strcat(buffer,"First of all, Set port number via command ListenPort\n");
			}
			else{				
				string ethname = parts[1];
				bool flag = thisSwitch->remove_ethernet(ethname);
				memset(buffer,'\0',BUFFER_SIZE);
				if(flag){
					strcat(buffer, "ethernet ");
					strcat(buffer, ethname.c_str());
					strcat(buffer, " removed successfully\n");
				}
				else{
					strcat(buffer, "No such ethernet exists:");
					strcat(buffer, ethname.c_str());
					strcat(buffer,"\n");
				}
			}
			write(1,buffer,BUFFER_SIZE);
			continue;
		}

		if( command.compare("Vlan") == 0 ){
			if(parts.size()!=3){
				memset(buffer,'\0',BUFFER_SIZE);
				strcat(buffer, "Invalid Command.Correct Form is:Vlan Ethname VlanNumber\n");	
			}
			else if (thisSwitch->get_listen_port() == -1){
				memset(buffer,'\0',BUFFER_SIZE);
				strcat(buffer, "First of all, Set port number via command ListenPort\n");
			}		
			else{
				int vlannum = atoi(parts[2].c_str());
				bool flag = thisSwitch->get_ethernet(parts[1])->set(vlannum);
				memset(buffer,'\0',BUFFER_SIZE);
				if (flag){
					strcat(buffer, "Virtual Lan Number of ethernet ");
					strcat(buffer, parts[1].c_str());
					strcat(buffer, " changed to ");
					strcat(buffer, parts[2].c_str());
					strcat(buffer, "\n");
				}
				else
					strcat(buffer, "Unable to change VLan Number.\n");
			}
			write(1, buffer, BUFFER_SIZE);
			continue;
		}

		if( command.compare("Show") == 0 ){
			memset(buffer,'\0',BUFFER_SIZE);
			strcat(buffer,"ETH\t\t\t\t\tMAC\t\t\t\t\tIP\t\t\t\t\tVLAN\n");
			vector<Ethernet*> interfaces = thisSwitch->get_all_ethernets();
			for (int i = 0; i <interfaces.size(); i++)
			{
				strcat(buffer, interfaces[i]->get_name().c_str());
				strcat(buffer, "\t\t");
				strcat(buffer, interfaces[i]->get_mac().c_str());
				strcat(buffer, "\t\t");
				strcat(buffer, interfaces[i]->get_ip().c_str());
				strcat(buffer, "\t\t");
				stringstream ss;
				ss<<interfaces[i]->get_vlan();
				strcat(buffer, ss.str().c_str());
			}
			continue;
		}

		if( command.compare("Connect") == 0 ){
			
			continue;
		}

		if( command.compare("Disconnect") == 0 ){
			
			continue;
		}

		
		//TODO:
		// 	cout list of commands


					
		


	}

}
