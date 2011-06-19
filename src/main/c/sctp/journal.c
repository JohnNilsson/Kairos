#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/sctp.h>

static void s_bind(int socket, int port)
{
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));

	addr.sin_family = AF_INET;
	addr.sin_port   = htons(port);

	inet_pton(AF_INET, INADDR_ANY, &(addr.sin_addr.s_addr));

	bind(socket, (struct sockaddr *)&addr, sizeof(addr));
}

int main()
{
	int socket = socket(PF_INET, SOCK_SEQPACKET, IPPROTO_SCTP);
	s_bind(socket,5555);
	listen(socket,1000);

	

	close(socket);	
}
