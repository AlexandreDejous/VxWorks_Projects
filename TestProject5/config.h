/* config.h
 * PSR 5cache assignment
 * DO NOT MODIFY
 */

/* we need to have array sizes from 1 KiB to 4 MiB, so from 2**10 to 2 ** 22
 * there are 13 arrays to create
 * on each of these arrays we will jump from cell to cell 10 000 000 times, since the arrays are smaller
 * than 10 000 000 cells we will need to cycle through them
 * the initialization part of the array (whether random or seq.) IS NOT part of the measurement
 * and once an array is generated randomly its layout stays the same during the measumnt
 * ie. at each cycle
 * To initialize an array means that we have a very big array (most likely with size = MAX_ARRAY_SIZE)
 * of which the links will be rearranged each time */

/* sysClkRateSet(CLOCK_RATE) */




#define CLOCK_RATE 1000

#define GAP 0

struct elem {
  struct elem *next;
  int gap[GAP];
};

#define MAX_ARRAY_SIZE (4*1024*1024/sizeof(struct elem))

struct elem arr[MAX_ARRAY_SIZE]; // 1 MiB array 


unsigned longrand(long int max)
{
	#if RAND_MAX == 32767
	return (rand() ^ (rand() << 15)) % max;
	#else
  		#error Unsupported RAND_MAX value
	#endif
}


/*
 * seqArray()
 *  : (struct elem*) array -- array to modify
 *  : (int) n -- number of elements to modify
 *
 *  This function takes first `n` elements of `array`
 *  and links them together in a sequential order,
 *  i.e.,
 *      array[0].next == array[1]
 *      array[1].next == array[2]
 *      ...
 *      array[n-1].next == array[0]
 */

//arranges sequentially the array for size n bytes
void seqArray(struct elem* array, int n){
	
	//first we need to convert the n from a number of bytes to a number of indexes
	n = n/sizeof(struct elem);
	
	unsigned i;
	for (i=0; i < n - 1; i++) {
		array[i].next = &array[i+1];
	}
	array[i].next = &array[0];   /* close the cycle */
}





/*
 * ranArray()
 *  : (struct elem*) array -- array to modify
 *  : (int) n -- number of elements to modify
 *
 *  This function takes first `n` elements of `array`
 *  and links them together in a random order,
 *  i.e. (e.g.),
 *      array[0].next == array[5]
 *      array[5].next == array[1]
 *      ...
 *      array[x].next == array[0]
 */
void ranArray(struct elem* array, int n){
	
	//first we need to convert the n from a number of bytes to a number of indexes
	n = n/sizeof(struct elem);
	
	
	int randomNum;
	int m = 0; //number of cells filled
	int current = 0; // current index of cell being filled (we start at 0)
	
	//init n first cells to null
	for (i=0; i < n; i++) {
		array[i].next = NULL;
	}
	
	
	while(m < n){//while the num of completed nexts is less than the total num of nexts
		//init a rand
		randomNum = longrand(MAX_ARRAY_SIZE);
		
		//while at that rand index theres a defined next
		while(array[randomNum].next != NULL){
			
			//rerand the rand (good stuff there)
			randomNum = longrand(MAX_ARRAY_SIZE);
		}
		//define the current next
		array[current].next = &array[randomNum];
		//increase the count of completed nexts
		m++;
		//change the current index being modified to the next index
		current = randomNum;
	}
	//in the end we just need to fill the last next with the address of the 0th element
	array[current].next = &array[0];
}

/*
 * measureCache()
 *  : (int) mode -- mode of ordering elements in an array
 *                  0 = SEQUENTIAL
 *                  1 = RANDOM
 *  : (int) n -- number of traversals in a measurement
 *
 *  This function makes a measurement for memory access time.
 *  At first it prepares an array (according to selected `mode`),
 *  then it follows the links in the array `n` times. This process
 *  is repeated until all working sets are measured (1 KiB - 4 MiB).
 *
 *  Measurement should start with 'Measurement started', and end
 *  with 'Measurement finished'. Each working set should be finished
 *  by printing its size and average access time (in CPU ticks).
 *
 *  Example:
 *      Measurement started
 *      1024    22
 *      2048    23
 *      4096    22
 *      Measurement finished
 */
void measureCache(int mode, int n){
	int samples = 13;
	int bytes = 1024;
	int traversals = n;
	
	printf("Measurement started");
	
	//SEQUENTIAL MODE
	if(mode == 0){
		
		int i;
		for (i=0;i<samples;i++){
			
			//flush and init the array
			seqArray(array,bytes);
			
			//TOCHANGE
			struct elem *p = &array[0];
			unsigned start = sysTimestamp();
			while (--i) p = p->next;
			unsigned end = sysTimestamp();
			
			//double the bytes
			bytes = bytes*2;
		}
		
		
	}
	//RANDOM MODE
	if(mode == 1){
		
	}
	
	
	printf("Measurement finished");
	
}