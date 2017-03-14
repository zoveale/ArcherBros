#include "../include/System.h"



int main(int argc, char* argv[]) {

	System system;

	system.Initialization();
	system.GameLoop();
	system.Close();

	return 0;
}