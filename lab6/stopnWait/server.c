#include <stdio.h>
#include <stdlib.h>
 #include <stdio.h>
   #include <stdlib.h>
   #include <unistd.h>
   #include <string.h>
#include <netdb.h>
#include <netinet/in.h>

#include <string.h>

void doprocessing (int sock,int i, int* pipefd) {
   int n;
   char buffer[256];
   
        char buff[256];
           
           
   while(1){
   bzero(buffer,256);
   n = read(sock,buffer,255);
   
   if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
   }
   
   printf("Here is the message from %d: %s\n",i,buffer);
   n = write(sock,"Acknowlegement sent",18);
  
	}
}

int main( int argc, char *argv[] ) {
   int sockfd, newsockfd, portno, clilen;
   char buffer[256];
    int pipefd[2];
       
       pipe(pipefd);
   struct sockaddr_in serv_addr, cli_addr;
   int  n;
   
   /* First call to socket() function */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   
   if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }
   
   /* Initialize socket structure */
   bzero((char *) &serv_addr, sizeof(serv_addr));
   portno = 5001;
   
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(portno);
   
   /* Now bind the host address using bind() call.*/
   if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR on binding");
      exit(1);
   }
      
   /* Now start listening for the clients, here process will
      * go in sleep mode and will wait for the incoming connection
   */
   
   listen(sockfd,5);
   clilen = sizeof(cli_addr);
   int i=1;
   while(1)
   {
   /* Accept actual connection from the client */
   newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
	
   if (newsockfd < 0) {
      perror("ERROR on accept");
      exit(1);
   }
   int pid=fork();
   if(pid==0){
   //child pro
  close(sockfd);
     doprocessing(newsockfd,i,pipefd);
         exit(0);
   }
   else if(pid>0)
   {  close(newsockfd);
   //parent process
   }
   else
   {   perror("fork returned id<0");
      exit(1);
  
   }
   i++;
   }
   /* If connection is established then start communicating 
   bzero(buffer,256);
   n = read( newsockfd,buffer,255 );
   
   if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
   }
   
   printf("Here is the message: %s\n",buffer);
   
    Write a response to the client 
   n = write(newsockfd,"I got your message",18);
   
   if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
   }
     */
   return 0;
}
