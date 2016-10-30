#ifndef _EASYCO_COROUTINE_H_
#define _EASYCO_COROUTINE_H_


struct CoroutineAttr{
    int stack_size;//
};


struct Coroutine {
    Coroutine(){
        id = 0;
        state = 0;
        stack_size = 16*1024;
    }
    uint64_t id;
    int state;
    int taskid;
    int stack_size;
    char buf_stack[1024*16];

    coro_context* coro_ctx;
    std::Function f;
    std::Args args;

    TypeIterPos pos;

    typedef std::list<Coroutine*>::iterator TypeIterPos;
};



#endif

