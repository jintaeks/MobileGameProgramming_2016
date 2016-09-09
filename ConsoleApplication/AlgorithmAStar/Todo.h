// defines several macros making it possible to insert "super to-do" messages of the form
// #pragma TODO(message)
// which expand into strings that you can double-click on (in VC++'s build output window) to jump
// to the appropriate line

#ifndef WARNING_H
#define WARNING_H

#define LINE1(x) #x
#define LINE(x) LINE1(x)
#define TODO(y) message ( __FILE__ "(" LINE(__LINE__)  "): TODO -- " y )


#endif


