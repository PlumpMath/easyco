#include "sched.h"


class SchedTask {
public:

    SchedTask(){
        
    }
    
    void resume(Coroutine* c) {
    }
    void yield(Coroutine* c) {

        coro_transfer(c.coro_ctx, lst_running_task.begin().coro_ctx);
    }

    void run() {
        while(state){
            
        }
    }

    static void read_task() {

    }

    static void write_task() {

    }

private:
    std::list<Coroutine*> lst_running_task;
    std::list<Coroutine*> lst_suspend_task;
    bool state;

    struct ev_loop* event_driver;
    int write_fd;
    int read_fd;
};


SchedMgr::SchedMgr() {
    
}

void SchedMgr::resume(Coroutine* c) {

}

void SchedMgr::yield(Coroutine* c) {

}


template<class Function, class ... Args>
void SchedMgr::create(Function&& f, Args&&... args)
{

}


void SchedMgr::resume(Coroutine* c)
{
    auto task = this.sched_task[c.taskid];
    task.resume(c);
}

void SchedMgr::yield(Coroutine* c)
{
    auto task = this.sched_task[c.taskid];
    task.yield(c);
}

void SchedMgr::post_g_to_task(Coroutine* c) {
    c.taskid = c.id % sched_task.size();
    auto task = this.sched_task[c.taskid];

}
