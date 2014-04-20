all: switch
        $(info ****  All done  ****)
switch:	tools Ethernet
	g++ center.cpp tools.o Switch.cpp Ethernet.cpp -o center

tools :
	g++ -c tools.cpp 
	
Ethernet:
	g++ -c Ethernet.cpp