/*  main.c  - main */

#include <xinu.h>

process	main(void)
{

	/* Run the Xinu shell */
	
	resume(create(process1, INITSTK, 50, "process 1", 0, NULL));
	resume(create(process4, INITSTK, 10, "process 4", 0, NULL));
	resume(create(process10, INITSTK, 10, "process 10", 0, NULL));
	resume(create(process3, INITSTK, 50, "process 3", 0, NULL));
	resume(create(process7, INITSTK, 50, "process 7", 0, NULL)); 

	

	recvclr();
	//resume(create(shell, 8192, 50, "shell", 1, CONSOLE));
	
	/* Wait for shell to exit and recreate it */

	/*while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	}*/
	return OK;
    
}
