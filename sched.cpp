#include "sched.h"
#include "utils.h"
#include <sys/socket.h>

class SchedTask {
private:
    Coroutine* main_coroutine_ = nullptr;
    std::list<Coroutine*> lst_running_task_;
    bool state_ = false;
    
    struct ev_loop* event_driver_ = nullptr;
    std::pair<int, struct ev_io> notification_pipe_fd_[2];
public:

    SchedTask() {
        
    }

    int init() {
        event_driver = ev_default_loop (0);
        if (!event_driver) {
            return -1;
        }
        if(create_notification_pipe() != 0){
            return -1;
        }
        return 0;

    }

    int uninit() {

    }

    void resume(Coroutine* c) {

    }

    void switch_main(){

    }

    void yield(Coroutine* c) {
        coro_transfer(c.coro_ctx, lst_running_task.begin().coro_ctx);
    }

    //main_coroutine
    void run() {
        while (state_) {
            //运行就绪的协程
            for(auto run_it = lst_running_task_.begin(); run_it != lst_running_task_.end(); 
                ++run_it){

            }

            //epoll事件，找到已经就绪的协程，扔到就绪队列

            //如果没有就绪的，
            usleep(1);
        }
    }

    static void run_coroutine(void* argv) {

    }

    static void read_task(struct ev_loop *loop, struct ev_io *watcher, int revents) {
        
    }

    int create_notification_pipe() {
        if (socketpair(AF_UNIX, SOCK_STREAM, 0, notification_pipe_fd_) != 0) {
            return -1;
        }
        for (int i = 0; i < 2; i++) {
            if (set_non_block(notification_pipe_fd_[0]) != 0) {
                return -1;
            }
        }
        ev_io_init(&notification_pipe_fd_[0].second, read_task, notification_pipe_fd_[0].first, EV_READ);
        ev_io_start(loop, &&notification_pipe_fd_[0].second);  
    }

    int notity(Coroutine * c) {
        int fd = notification_pipe_fd_[1].first;
        if(fd < 0){
            return -1;
        }

        fd_set wfds, efds;
        long ret = -1;
        long kSize = sizeof(c);
        const char* pos = reinterpret_cast<const char*>(&c);

        while (kSize > 0) {
            FD_ZERO(&wfds);
            FD_ZERO(&efds);
            FD_SET(fd, &wfds);
            FD_SET(fd, &efds);
            ret = select(static_cast<int>(fd + 1), NULL, &wfds, &efds, NULL);
            if (ret < 0) {
                return false;
            } else if (ret == 0) {
                continue;
            }

            if (FD_ISSET(fd, &efds)) {
                return false;
            }

            if (FD_ISSET(fd, &wfds)) {
                ret = send(fd, pos, kSize, 0);
                if (ret < 0) {
                    if (errno == EAGAIN) {
                        continue;
                    }
                    return false;
                }
                kSize -= ret;
                pos += ret;
            }
        }
        return true;
    }
};


SchedMgr::SchedMgr() {

}

void SchedMgr::resume(Coroutine* c) {

}

void SchedMgr::yield(Coroutine* c) {
    
}

int SchedMgr::create(Coroutine** c, const std::SchedMgr::func_type& func)
{
    Coroutine* c = new Coroutine();
    return post_g_to_task(c);
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
    c->taskid = c.id % sched_task.size();
    return sched_task[c->taskid].notity(c);
}
