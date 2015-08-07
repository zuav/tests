#include <sys/sysctl.h>
#include <sys/syscall.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int max_open_files();


int main()
{
    int n = max_open_files();
    printf("max number of open files is: %d\n", n);

    return 0;
}


int max_open_files()
{
    struct __sysctl_args args;
    int nf = 0;
    size_t nfsz = sizeof(nf);
    int name[] = { CTL_FS, FS_MAXFILE };

    memset(&args, 0, sizeof(struct __sysctl_args));
    args.name = name;
    args.nlen = sizeof(name)/sizeof(name[0]);
    args.oldval = &nf;
    args.oldlenp = &nfsz;

    if (syscall(SYS__sysctl, &args) == -1) {
        printf("sysctl syscall failed: %s\n", strerror(errno));
        exit(1);
    }

    return nf;
}
