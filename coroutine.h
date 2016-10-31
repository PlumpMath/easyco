#ifndef _EASYCO_COROUTINE_H_
#define _EASYCO_COROUTINE_H_

#include "coro.h"
//#include <functional>

/*
struct CoroutineAttr {
    int stack_size;//
};*/


struct Coroutine {
public:
    /*typedef std::function<void()> func_type;

    Coroutine() {
        id = 0;
        state = 0;
        stack_size = 16 * 1024;
    }
    uint64_t id;

    int state;
    int stack_size;
    char buf_stack[1024 * 16];

    coro_context* coro_ctx;
    func_type func;*/
};



#endif

