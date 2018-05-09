#include <xinu.h>

process process1(void){
		kprintf("Process 1 is running.\n");
		return OK;
}

process process2(void){
		kprintf("Process 2 is running.\n");
		return OK;
}

process process3(void){
		kprintf("Process 3 is running.\n");
		return OK;
}

process process4(void){
		kprintf("Process 4 is running.\n");
		process1();
		return OK;
}

process process5(void){
		kprintf("Process 5 is running.\n");
		return OK;
}

process process6(void){
		kprintf("Process 6 is running.\n");
		return OK;
}

process process7(void){
		kprintf("Process 7 is running.\n");
		process2();
		return OK;
}

process process8(void){
		kprintf("Process 8 is running.\n");
		return OK;
}

process process9(void){
		kprintf("Process 9 is running.\n");
		return OK;
}

process process10(void){
		kprintf("Process 10 is running.\n");
		process3();
		return OK;
}

