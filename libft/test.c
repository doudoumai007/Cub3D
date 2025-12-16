#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    // 测试 libft 基本函数
    char *s = ft_strdup("hello");
    free(s);

    // 测试 ft_printf
    ft_printf("Hello %s\n", "World");

    // 测试 get_next_line
    int fd = open("Makefile", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        free(line);
    }
    close(fd);

    return 0;
}
/*cc -g test.c -L. -lft -o test_libft*/
/*valgrind --leak-check=full ./test_libft*/
