/* Clock rate for 'sysClkRateSet()' function. */
#define CLOCK_RATE              1000

/* Priority of three tasks -- lower number = higher priority. */
#define HIGH_PRIORITY           210
#define MID_PRIORITY            211
#define LOW_PRIORITY            222

/* Work factors of the tasks for 'do_work_for_some_time()'. */
#define MID_PRIORITY_WORK       10 //10
#define LOW_PRIORITY_WORK       3 // 3

/* Delays of the tasks. Fill them with your own values */
#define HIGH_PRIORITY_DELAY     10 //1	2
#define MID_PRIORITY_DELAY      32 //3	1
#define LOW_PRIORITY_DELAY      2 //2	0
