/*
 * scheduler.cpp
 *
 *  Created on: Oct 3 2021
 *      Author: jacob pond
 *
 */

#include "../includes/scheduler.h"
#include "../includes/PCB.h"
#include "../includes/constants.h"
#include <queue>

using namespace std;


//add a process, either a new one or one that
//had been running on the CPU and has been preempted
void Scheduler::add(PCB p) {
	ready_q->push(p);
	sort();
}

//get next process
PCB Scheduler::getNext() {
	if (!ready_q->empty()) {
		PCB p = ready_q->front();
		ready_q->pop();
		return p;
	}
	return PCB();

}

//returns true if there are no  jobs in the readyQ
//false otherwise
bool Scheduler::isEmpty(){
	if (ready_q->empty()) {
		return true;
	}
	return false;
}

//if process has completed (used all its remaining_cpu_time) or
//if we are using a preemptive scheduling algorithm and the
//timeslice is over then its time to switch processes
//returns:
//true - switch processes
//false - do not switch
bool Scheduler::time_to_switch_processes(int tick_count, PCB &p){
	sort();
	return (p.remaining_cpu_time <= 0 || (preemptive && (tick_count - p.start_time) >= time_slice));
}





