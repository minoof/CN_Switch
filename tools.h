#ifndef _TOOLS_H
#define _TOOLS_H

#include <iostream>
#include <vector>

#define DUPLICATE_USERNAME 1
#define DUPLICATE_EMAIL 2
#define OK 3
#define BUFFER_SIZE 4096

std::vector <std::string> parseCommand (std::string command);
static std::string help="These are commands:\n1-Register username password email\n2-Login username|email password\n3-Invite username\n4-Select username\n5-Accept username\n6-ChangeStatus status\n7-Send <MSG> or file\n8-Who part-of-username-or-password\n9-Exit\n";

#endif