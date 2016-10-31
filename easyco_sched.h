#ifndef _EASYCO_SCHED_H_
#define _EASYCO_SCHED_H_

#include "easyco.h"
#include "coroutine.h"
#include <memory>
#include <vector>

class SchedTask;

class SchedMgr {
public:
    void init();
    void resume(easyco_coroutine_t* c);
    void yield(easyco_coroutine_t* c);
    //int64_t create(easyco_coroutine_t* c, const Coroutine::func_type& func);
private:
    int post_g_to_task(const std::shared_ptr<Coroutine>& c);
    std::vector<SchedTask*> sched_task;
};


//extern SchedMgr* gSchedMgr = NULL;

#endif
