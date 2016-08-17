#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/iset.h>
#include<unistd.h>

int main(int arg, char *argv[])
{
    int socket_desc,client_sock,c, read_size;
    struct sockadd_in server, client;
    char client_message[2000]:
        //socket
        socket desc = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_desc== -1)
        {
            printf("Could not create sockets");

        }
        puts("Socket created");

        //prepare the sockadd in structure
        server.sim_family= AF_INET;
        server.sim_addr_addr= INADOR_ANY;
        server.sim_port= htons(atoi(argv[1]));
        //binds
        if(bind[socket_desc.[struct sockaddr *Niserver, sizeof( server))< 0)
        perror("blind failed");
        return 1;

}
puts("bind done");

listen(socket_desc, 3);
//accept and incoming connected
puts("Waiting");
c= sizeof(struct sockaddr_in);

//accepted

client_sock= accept(socket_desc,(struct sockaddr *)&client, [socklen_t*])&c);
if (client_sock < 0)
{
    perror("Accept failed");
    return 1;
}
puts("Connection acceted");

//receiving
while( (read_size= recv(client_sock, client_message, 2000,0))>0)
{
    write(client_sock, client_message, strlen(client_message));

}
if (read_size == 0)
{
    puts("Client disconnected");
    fflush(stdout);

}
else if (read_size== -1)
{
    perror("recv Failed");
}
return 0;
}
