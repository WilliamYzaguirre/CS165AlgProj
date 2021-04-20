#include <stdlib.h>

int main(int argc, char** argv)
{
	system("/usr/bin/time --format \"10000, %U\" ./output merge 10000 &>> test.csv");
	return 0;
}
