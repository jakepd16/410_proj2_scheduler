/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Oct 3 2021
 *      Author: jacob pond
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 *      very simple inherited scheduler with first in first out
 */

#include "../includes/scheduler_FIFO.h"
using namespace std;

//override base class behaviour if necessary, otherwise call it
bool  Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p){
	return Scheduler::time_to_switch_processes(tick_count, p);
}

//FIFO - not preemptive - no sorting needed
void Scheduler_FIFO::sort(){
	preemptive = false;
}
