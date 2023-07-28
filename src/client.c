#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, t, done;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    int choice = 0;
    float r;
    int n; //sizeof X and Y
    int *X;
    int *Y;

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname portno\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("ERROR opening socket");
    
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    printf("Connected.\n"); 

    //Menu
    printf("1. Calculate inner product X*Y\n");
    printf("2. Calculate average Ex and Ey\n");
    printf("3. Calculate product r * (X+Y)\n");
    printf("4. Exit\n");
    do {
        printf("\nChoice: ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 4);
    if (choice == 4) {
        close(sockfd);
        exit(0);
    }
    
    //get n
    printf("Give me n (sizeof X, Y): ");
    scanf("%d", &n);
    X = (int*)malloc(n * sizeof(int));
    Y = (int*)malloc(n * sizeof(int));

    //get r
    printf("Give me r: ");
    scanf("%f", &r);

    //fill X
    printf("Give me X:\n");
    for (int i = 0; i < n; i++) {
        printf("X[%d]: ", i);
        scanf("%d", &X[i]);
    }

    //fill Y
    printf("Give me Y:\n");
    for (int i = 0; i < n; i++) {
        printf("Y[%d]: ", i);
        scanf("%d", &Y[i]);
    }

    //could send as a single struct
    write(sockfd, &choice, sizeof(int)); //send choice
    write(sockfd, &r, sizeof(float));  //send r
    write(sockfd, &n, sizeof(int));    //send n
    write(sockfd, X, n * sizeof(int)); //send X
    write(sockfd, Y, n * sizeof(int)); //send Y

    //read results
    int res1;
    float res2[2];
    float res3[n];

    if (choice == 1) {
        read(sockfd, &res1, sizeof(int));
        printf("Result: %d\n", res1);
    }

    if (choice == 2) {
        read(sockfd, res2, 2 * sizeof(float));
        printf("Result:\n");
        printf("Ex = %f\n", res2[0]);
        printf("Ey = %f\n", res2[1]);
    }

    if (choice == 3) {
        read(sockfd, res3, n * sizeof(float));
        printf("Result:\n");
        for (int i = 0; i < n; i++) {
            printf("r[%d] = %f\n", i, res3[i]);
        }
    }

    close(sockfd);
    free(X);
    free(Y);
    return 0;
}