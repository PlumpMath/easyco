#include "easyco.h"
#include "options.h"
#include "easyco_sched.h"

int easyco_init(easyco_options_t* opt) {
    gDefaultOptions = new EasycoOptions();
    if (!opt) {
        opt = gDefaultOptions;
    } else {
        easyco_set_opt(opt);
    }
    gSchedMgr = new SchedMgr();

    return gSchedMgr->init();
}


int easyco_set_opt(easyco_options_t* opt) {

}

int easyco_create(easyco_coroutine_t* c, const easyco_coroutine_attr_t* attr, void (*start_routine)(void *), void *restrict arg) {
    gSchedMgr->create(
        c,
        [arg] -> (){
            start_routine(arg);
        }
    );
}

int easyco_run() {

}

int easyco_unit() {

}

void easyco_resume(easyco_coroutine_t* c) {

}

void eaysco_yield(easyco_coroutine_t* c) {

}
