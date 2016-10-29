#ifndef _EASYCO_SCHED_H_
#define _EASYCO_SCHED_H_


class SchedTask;

class SchedMgr {
public:
    void init();
    void resume(Coroutine* c);
    void yield(Coroutine* c);

    template<class Function, class ... Args>
    std::share_ptr<Coroutine> create(Function&& f, Args&&... args);
private:
    void post_g_to_task(Coroutine* c);
    std::vector<std::share_ptr<SchedTask>> sched_task;
};


extern SchedMgr* gSchedMgr = NULL;

#endif
