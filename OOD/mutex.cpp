// Deadlock in mutex
// 1) forgetting to unlock mutex after gaining a lock.
// 2) having two different mutexes, and each process gains control for each one of them and is waiting indefinitely for other.

// How to avoid deadlocks
// 1) The simplest solution is to always lock the mutexes in the same order.
// 2) The std::lock function can lock 2 or more mutexes at once without risk of a deadlock. Instead of having.


// lock() can take multiple mutexes as input, and ensures that mutexes are locked in deadlock fashion and if some mutex is already locked then it would leave all mutexes unlocked and retry
// hence preventing deadlock by violatng hold and wait conditions of deadlock.


// Sleep vs Wait
// Sleep means I am done with my timeslice no need to schedule me until 'n' milliseconds. I hold all the locks that I had.
// Wait means I am done with my timeslice no need to schedule me until someone notifies me. I release all the locks that i had.
