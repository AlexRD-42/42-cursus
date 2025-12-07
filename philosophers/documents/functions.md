## Common
<string.h>
memset:			fill a block of memory with a byte value.

<stdio.h>
printf:			formatted output to stdout.

<stdlib.h>
malloc:			allocate heap memory.
free:			release heap memory.

<unistd.h>
write:			write bytes to a file descriptor.
usleep:			sleep for a given number of microseconds.

<sys/time.h>
gettimeofday:	get the current wall-clock time with microsecond resolution.

<pthread.h>
_create:		start a new thread.
_detach:		detach a thread; resources reclaimed automatically.
_join:			wait for a thread to terminate.

## Mandatory Only
<pthread.h>
_mutex_init:	initialize a mutex.
_mutex_destroy:	destroy a mutex.
_mutex_lock:	lock a mutex.
_mutex_unlock:	unlock a mutex.

## Bonus Only
<unistd.h>
fork: 			create a new process (child).

<signal.h>
kill: 			send a signal to a process or process group.

<stdlib.h>
exit: 			terminate the current process.

<sys/wait.h>
waitpid:		wait for a specific child to exit (or change state).

<semaphore.h>
sem_open:		open / create a named POSIX semaphore.
sem_close:		close the handle to a named semaphore.
sem_unlink:		remove the named semaphore from the system.
sem_post:		increment (signal) the semaphore.
sem_wait:		decrement (block until > 0) the semaphore.
