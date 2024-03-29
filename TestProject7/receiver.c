/* This program listens at a UDP port specified as command line
 * parameter and once it receives a packet it adds "OK!" and sends it
 * back. */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <inetLib.h>
#include <sockLib.h>

#define MAX_BUF 1024

/*#define CLOCK_RATE 5000*/

#define GAP 0



/*struct elem {
  struct elem *next;
  int gap[GAP];
};*/

int receive(int port)
{
  /*sysClkRateSet(5000);*/
  
	
	
  int sockd;
  struct sockaddr_in my_name, cli_name;
  char buf[MAX_BUF];
  int status;
  int addrlen;

  /*if (argc < 2)
  {
    fprintf(stderr, "Usage: %s port_number\n", argv[0]);
    exit(1);
  }*/
  /* Create a UDP socket */
  sockd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockd == -1)
  {
    perror("Socket creation error");
    exit(1);
  }

  /* Configure server address */
  my_name.sin_family = AF_INET;
  my_name.sin_addr.s_addr = INADDR_ANY;
  my_name.sin_port = htons(port);

  status = bind(sockd, (struct sockaddr*)&my_name, sizeof(my_name));

  addrlen = sizeof(cli_name);
  status = recvfrom(sockd, buf, MAX_BUF, 0,
      (struct sockaddr*)&cli_name, &addrlen);

  printf("%s", buf);
  strcat(buf, "OK!\n");

  status = sendto(sockd, buf, strlen(buf)+1, 0,
      (struct sockaddr*)&cli_name, sizeof(cli_name));

  close(sockd);
  printf("Program ended");
  return 0;
}
