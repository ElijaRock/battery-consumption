#include <sys/utsname.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isLinux()
{
    struct utsname uts;
    if (uname(&uts) < 0)
    {
        perror("uname() error");
        return false;
    }
    else
    {
        int result = strncmp(uts.sysname, "Linux", 6);
        return (result == 0 ? true : false);
    }
}