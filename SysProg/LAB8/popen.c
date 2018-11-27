#include <stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
        FILE *in, *out;
        char readbuf[80];

        if (( in = popen("ls /etc", "r")) == NULL)
        {
                perror("popen");
                exit(1);
        }
         
        if (( out = popen("grep m", "w")) == NULL)
        {
                perror("popen");
                exit(1);
        }


//	while(fgets(readbuf, 80, in))
//           fputs(readbuf, out);
	fread(readbuf, sizeof(char), 80, in); 
        fwrite(readbuf, sizeof(char), strlen(readbuf), out);

        pclose(in);
        pclose(out);

        return(0);
}
