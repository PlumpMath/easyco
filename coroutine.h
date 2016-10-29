#ifndef _EASYCO_COROUTINE_H_
#define _EASYCO_COROUTINE_H_


struct CoroutineAttr{
    int stack_size;//
};

struct Coroutine {
    uint64_t id;
    int state;
    int taskid;
    int stack_size;
    char buf_stack[1024*16];

    coro_context* coro_ctx;
};

#endif

