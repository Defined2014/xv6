#include "types.h"
#include "stat.h"
#include "user.h"
#include "ProcessInfo.h"
#include "param.h"

int
main(int argc, char *argv[])
{
  struct ProcessInfo* p;
  p = (struct ProcessInfo*) malloc(sizeof(struct ProcessInfo)*NPROC);
  int t = getprocs(p);
  int i=0;
  for (i=0;i<t;i++){	
    printf(1,"%d  %d  ",p->pid,p->ppid);
    switch (p->state){
        case 0:
	printf(1,"UNUSED");
	break;
	case 1:
	printf(1,"EMBRYO");
	break;
	case 2:
	printf(1,"SLEEPING");
	break;
	case 3:
	printf(1,"RUNNABLE");
	break;
	case 4:
	printf(1,"RUNNING");
	break;
	case 5:
	printf(1,"ZOMBIE");
	break;
        default:
	printf(1,"%d",p->state);
    }
    printf(1,"  %d  %s\n",p->sz,p->name);
    p++;
  }
  free(p);
  exit();
}
