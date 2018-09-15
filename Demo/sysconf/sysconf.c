#include <stdio.h>
#include <unistd.h>

int sysConfInt[] = {
    _SC_ARG_MAX,
    _SC_ATEXIT_MAX,
    _SC_CHILD_MAX,
    _SC_CLK_TCK,
    _SC_COLL_WEIGHTS_MAX,
    _SC_DELAYTIMER_MAX,
    _SC_HOST_NAME_MAX,
    _SC_IOV_MAX,
    _SC_LINE_MAX,
    _SC_LOGIN_NAME_MAX,
    _SC_NGROUPS_MAX,
    _SC_OPEN_MAX,
    _SC_PAGESIZE,
    _SC_PAGE_SIZE,
    _SC_RE_DUP_MAX,
    _SC_RTSIG_MAX,
    _SC_SEM_NSEMS_MAX,
    _SC_SEM_VALUE_MAX,
    _SC_SIGQUEUE_MAX,
    _SC_STREAM_MAX,
    _SC_SYMLOOP_MAX,
    _SC_TIMER_MAX,
    _SC_TTY_NAME_MAX,
    _SC_TZNAME_MAX};

char *sysConfName[] = {
    "Exec func max arg length",
    "Max number of atexit func",
    "Max process number for every Effective User ID",
    "Tick for every second",
    "COLL_WEIGHTS_MAX",
    "Timer Max trigger times",
    "The Max length for hostname",
    "The Max iovec struct The readv and writev can use",
    "The Max Input line for utils program",
    "The Max length for login name",
    "Max number of Process Groups ID",
    "Max fd for a Process",
    "Size of one page",
    "Size of one page",
    "RE_DUP_MAX",
    "Max Real time Signal",
    "Max sem for a process",
    "Max value for sem",
    "Max Sig Queue for a process",
    "STREAM_MAX",
    "SYMLOOP_MAX",
    "max timer for a process",
    "TTY_NAME_MAX",
    "TZNAME_MAX"};

int pathConfInt[] = {
    _PC_FILESIZEBITS,
    _PC_LINK_MAX,
    _PC_MAX_CANON,
    _PC_MAX_INPUT,
    _PC_NAME_MAX,
    _PC_PATH_MAX,
    _PC_PIPE_BUF,
    // _PC_TIMESTAMP_RESOLUTION,
    _PC_SYMLINK_MAX};

char *pathConfName[] = {
    "FILESIZEBITS",
    "LINK_MAX",
    "MAX_CANON",
    "MAX_INPUT",
    "File name max length",
    "PATH_MAX",
    "PIPE_BUF",
    // "POSIX_TIMESTAMP_RESOLUTION",
    "SYMLINK_MAX"};

int main(int argc, char const *argv[])
{
    printf("sizeof sysConfInt: %lu, sizeof sysConfInt[0]: %lu\n", sizeof(sysConfInt), sizeof(sysConfInt[0]));
    printf("sizeof pathConfInt: %lu, sizeof pathConfInt[0]: %lu\n", sizeof(pathConfInt), sizeof(pathConfInt[0]));
    int sysConfLength = sizeof(sysConfInt) / sizeof(sysConfInt[0]);
    int pathConfLength = sizeof(pathConfInt) / sizeof(pathConfInt[0]);
    printf("sysconf: \n");
    for (int i = 0; i < sysConfLength; i++)
    {
        printf("\t%s: %ld\n", sysConfName[i], sysconf(sysConfInt[i]));
    }
    printf("pathconf: \n");
    for (int i = 0; i < pathConfLength; i++)
    {
        printf("\t%s: %ld\n", pathConfName[i], pathconf(".", pathConfInt[i]));
    }
    return 0;
}
