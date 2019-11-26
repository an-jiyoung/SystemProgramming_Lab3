#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define  BUFF_SIZE  1024

int main()
{
    char  buff[BUFF_SIZE];
    int	  fd;

    if ( 0 < ( fd = open( "./test.txt" , O_RDONLY)))
    {
	read( fd, buff, BUFF_SIZE);
	puts( buff);
	close( fd);
    }
    else
    {
	printf ( "Failed to open file. \n");
    }
    return 0;
}
