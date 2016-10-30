#ifndef _EASYCO_SCHED_H_
#define _EASYCO_SCHED_H_

class SchedTask;

class SchedMgr {
public:

    typedef std::function<void(void* args)> func_type;

    void init();
    void resume(Coroutine* c);
    void yield(Coroutine* c);
    int64_t create(Coroutine* c, const std::SchedMgr::func_type& func);
private:
    int post_g_to_task(Coroutine* c);
    std::vector<SchedTask*> sched_task;
};


extern SchedMgr* gSchedMgr = NULL;

#endif
