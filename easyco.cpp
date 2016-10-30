#include "easyco.h"
#include "sched.h"

int easyco_init(easyco_options* opt) {
    gDefaultOptions = new gDefaultOptions();
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

int easyco_create(easyco_coroutine_t* c, const easyco_coroutine_attr_t* attr, void *(*start_routine)(void *), void *restrict arg) {

}

int easyco_run() {

}

int easyco_unit() {

}

void easyco_resume(easyco_coroutine_t* c) {

}

void eaysco_yield(easyco_coroutine_t* c) {

}
