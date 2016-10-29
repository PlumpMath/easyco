#ifndef _EASYCO_OPTIONS_H_
#define _EASYCO_OPTIONS_H_


struct Options{
    int default_stack_size;
    int processor_thread_count;

    Options(){
        
    }
};

extern Options *gDefaultOptions;

#endif

