#ifndef _EASYCO_EASYCO_H_
#define _EASYCO_EASYCO_H_

#include <stdint.h>

struct CoroutineAttr;
struct EasycoOptions;

#ifdef __cplusplus
extern "C" {
#endif

typedef int64_t easyco_coroutine_t; 

typedef CoroutineAttr easyco_coroutine_attr_t;

typedef EasycoOptions easyco_options_t;

int easyco_init(easyco_options_t* opt);

int easyco_set_opt(easyco_options_t* opt);

int easyco_create(easyco_coroutine_t* c, const easyco_coroutine_attr_t* attr, void (*start_routine)(void *), void* arg);

int easyco_run();

int easyco_unit();

void easyco_resume(easyco_coroutine_t c);

void eaysco_yield(easyco_coroutine_t c);


#ifdef __cplusplus
}
#endif


#endif
