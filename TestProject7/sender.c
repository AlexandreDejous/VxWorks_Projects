/* This program sends "Hello world" string to address and port given
 * as command line parameters, then it wait for any response and
 * prints it. */

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

#define MAX_BUF 100

int sender(/*char ip[],*/ int port)
{
  int sockd;
  struct sockaddr_in my_addr, srv_addr;
  char buf[MAX_BUF];
  int count;
  int addrlen;
  
  /*test purposes only*/
  char ip[16] = "192.168.202.214";
  
  
/*
  if (argc < 3)
  {
    fprintf(stderr, "Usage: %s ip_address port_number\n", argv[0]);
    exit(1);
  }*/
  /* Create a UDP socket */
  sockd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockd == -1)
  {
    perror("Socket creation error");
    exit(1);
  }

  /* Configure client address */
  my_addr.sin_family = AF_INET;
  my_addr.sin_addr.s_addr = INADDR_ANY;
  my_addr.sin_port = 0;

  bind(sockd, (struct sockaddr*)&my_addr, sizeof(my_addr));

  strcpy(buf, "Hello world\n");

  /* Set server address */
  srv_addr.sin_family = AF_INET;
  inet_aton(ip, &srv_addr.sin_addr);
  srv_addr.sin_port = htons(port);
  
  printf("Sending Message\n");
  
  int code = sendto(sockd, buf, strlen(buf)+1, 0,
      (struct sockaddr*)&srv_addr, sizeof(srv_addr));

  printf("Message Sent\n");
  
  addrlen = sizeof(srv_addr);
  count = recvfrom(sockd, buf, MAX_BUF, 0,
      (struct sockaddr*)&srv_addr, &addrlen);
  write(1, buf, count);
  printf("%s",buf);
  close(sockd);
  printf("Program Ended !");
  return 0;
}
