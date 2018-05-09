/* getmem.c - getmem */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  getmem  -  Allocate heap storage, returning lowest word address
 *------------------------------------------------------------------------
 */
char  	*getmem(
	  uint32	nbytes		/* Size of memory requested	*/
	)
{
	intmask	mask;			/* Saved interrupt mask		*/
	struct	memblk	*prev, *curr, *leftover, *largest;

	mask = disable();
	if (nbytes == 0) {
		restore(mask);
		return (char *)SYSERR;
	}

	nbytes = (uint32) roundmb(nbytes);	/* Use memblk multiples	*/

	prev = &memlist;
	curr = memlist.mnext;
	largest = memlist.mnext;

	while (curr != NULL) {			/* Search free list	*/
		
		if(curr->mlength > largest->mlength){
			largest = curr;
		}
		prev = curr;
		curr = curr->mnext;
	}
	curr = largest;

	if (curr->mlength == nbytes) {	/* Block is exact match	*/
		prev->mnext = curr->mnext;
		memlist.mlength -= nbytes;
		restore(mask);
		return (char *)(curr);
		
	} else if (curr->mlength > nbytes) { /* Split big block	*/
		leftover = (struct memblk *)((uint32) curr +
				nbytes);
		prev->mnext = leftover;
		leftover->mnext = curr->mnext;
		leftover->mlength = curr->mlength - nbytes;
		memlist.mlength -= nbytes;
		restore(mask);
		return (char *)(curr);
		}
	
	restore(mask);
	return (char *)SYSERR;
	
}
//initialize largest to the first node
//loop through entire list until current = null
//if curr->mlength is > largest->mlength, then largest = curr;
//at the end of the loop you will have three conditions and one is true
//condition 1 = curr->mlength == nbytes (first if)
//condition curr->mlength > nbytes (else if)
//condition 3 curr->mlength < nbytes (return an error

/* Move to next block	
			prev = curr;
			curr = curr->mnext; */

//worst fit: 
