#include <unistd.h>

int main()

{


int ret;
ret = execl ("/bin/ls", "ls", "-l", (char *)0);


/*

char *env[] = { "HOME=/usr/home", "LOGNAME=home", (char *)0 };
ret = execle ("/bin/ls", "ls", "-l", (char *)0, env);


ret = execlp ("ls", "ls", "-l", (char *)0);


char *cmd[] = { "ls", "-l", (char *)0 };
ret = execv ("/bin/ls", cmd);


char *cmd[] = { "ls", "-l", (char *)0 };
char *env[] = { "HOME=/usr/home", "LOGNAME=home", (char *)0 };
ret = execve ("/bin/ls", cmd, env);


char *cmd[] = { "ls", "-l", (char *)0 };
ret = execvp ("ls", cmd);
*/


return 0;

}
