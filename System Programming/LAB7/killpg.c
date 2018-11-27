#include<stdlib.h>
#include<signal.h>


int main(int argc, char ** argv)
{
killpg(atoi(argv[1]),SIGKILL); // kills the whole group
return 0;
}
