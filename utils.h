#ifndef _EASYCO_NETUTILS_H_
#define _EASYCO_NETUTILS_H_

#include <unistd.h>
#include <fcntl.h>

static int inline set_non_block(int iSock)
{
    int iFlags;

    iFlags = fcntl(iSock, F_GETFL, 0);
    iFlags |= O_NONBLOCK;
    iFlags |= O_NDELAY;
    int ret = fcntl(iSock, F_SETFL, iFlags);
    return ret;
}

#endif
