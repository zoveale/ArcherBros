#include "../include/System.h"



int main(int argc, char* argv[]) {

  //GIT TEST TEST

	System system;

	system.Initialization();
	system.GameLoop();
	system.Close();

	return 0;
}