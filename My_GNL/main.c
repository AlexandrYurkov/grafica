#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int fd = 0;
    char *line;
   // int i = 1;

    fd = open ("test.txt", O_RDONLY);
    fd = 3;

    // while (get_next_line(fd, &line) > 0)
    // {
    //     printf("%d) %s\n", i, line);
    //     i++;
    //     free (line);
    // }
    
    
    printf("|  %-d  | %20s\n",get_next_line(fd, &line), line);
    if((get_next_line(fd, &line)) > 0)
        free(line);

    // printf("|  %-d  | %20s\n",get_next_line(fd, &line), line);
    // if((get_next_line(fd, &line)) > 0)
    //     free(line);

    // printf("|  %-d  | %20s\n",get_next_line(fd, &line), line);
    // if((get_next_line(fd, &line)) > 0)
    //     free(line);

//  printf("|%-d| %s\n", get_next_line(fd, &line), line);
//     free(line);

 return 0;
}