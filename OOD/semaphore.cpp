// Deadlock in semaphore

  T1          T2
  WAIT(S)           // changes S value to 0
            WAIT(Q) // changes Q value to 0
  WAIT(Q)           // waiting for Q value to be >0 to reduce it to 0 
            WAIT(S) // waiting for S value to be >0 to reduce it to 0
            
// Issues with Naive implmentation of semaphore 
// The wait and signal operations are atomic in nature, incase of naive implementation they can suffer from context switch.   
// naive implementation may ensure mutual exclusion but may not ensure the desirable order of entry inside the critical section.
    
// Mutex and Semaphore can be shared among processes
// In POSIX systems, a mutex with the process-shared attribute set to PTHREAD_PROCESS_SHARED can be used across processes
    
// What is POSIX
//  POSIX is the standardization of the original UNIX, which came back in 1988 to resolve issues not only between different UNIX variants but also Non-UNIX operating systems as well.
 
