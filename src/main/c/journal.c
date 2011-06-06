#include "zmq.h"

static void print_init_txt()
{
	int major, minor, patch;
	zmq_version(&major,&minor,&patch);
	fprintf(stderr,"Starting journal server. 0MQ version: %d.%d.%d\n", major, minor, patch);
}


int main(void)
{
	print_init_txt();
	void *socket = init_server_socket(init_context(), ZMQ_PULL, "tcp://*:5555");

	while(1) {
		fprintf(stderr,"%s",s_recv(socket));
	}
	return EXIT_SUCCESS;
}
