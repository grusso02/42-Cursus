#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "libft/libft.h"
#include <unistd.h>
#include "get_next_line_git/get_next_line.h"

void print_prompt1(void)
{
    write(1, "$ ",2);
}

void print_prompt2(void)
{
    printf("> ");
}

/*
char *read_cmd(void)
{
    char buf[1024];
    char *ptr = NULL;
    char ptrlen = 0;

    while(read(1, buf, 1) != 0)
    {
        int buflen = strlen(buf);
        if(!ptr)
            ptr = malloc(buflen+1);
        else
        {
            char *ptr2 = realloc(ptr, ptrlen+buflen+1);
            if(ptr2)
                ptr = ptr2;
            else
            {
                free(ptr);
                ptr = NULL;
            }
        }
        if(!ptr)
        {
            fprintf(stderr, "error: failed to alloc buffer: %s\n", strerror(errno));
            return NULL;
        }
        strcpy(ptr+ptrlen, buf);
        if(buf[buflen-1] == '\n')
        {
            if(buflen == 1 || buf[buflen-2] != '\\')
                return ptr;
            ptr[ptrlen+buflen-2] = '\0';
            buflen -= 2;
            print_prompt2();
        }
        ptrlen += buflen;
    }
    return ptr;
}
*/
int main(int argc, char *argv[])
{
	char    *cmd;
    int     fd;
    char    *buf;
    int     ret;
    int     first = 0;

    buf = NULL;
    fd = 0;
	while (1)
	{
        // reading command text
		print_prompt1();
       
		ret = get_next_line(fd, &buf);
        cmd = buf;
        int len_cmd = ft_strlen(cmd);

		if (!cmd)
			return (0);
		if (cmd == 0 || strcmp(cmd, "\n") == 0)
		{
			free (cmd);
			continue;
		}
		if (strcmp(cmd, "exit\n") == 0)
		{
			free(cmd);
			break;
		}

		printf("%s\n", cmd);
		free(cmd);

        //when loof finish mak e a function to exit e free buf
        //free(buf);
	}
	return (0);
}