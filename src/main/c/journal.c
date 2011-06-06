#include "zmq.h"

static void print_init_txt()
{
	int major, minor, patch;
	zmq_version(&major,&minor,&patch);
	fprintf(stderr,"Starting journal server. 0MQ version: %d.%d.%d\n", major, minor, patch);
}


static void reply(void* socket)
{
	zmq_msg_t reply;
	zmq_msg_init_size(&reply,2);
	memcpy(zmq_msg_data(&reply), "Ok",2);
	zmq_send(socket, &reply, 0);
	zmq_msg_close(&reply);
}




int main(void)
{
	print_init_txt();
	void *socket = init_server_socket(init_context(), ZMQ_REP, "tcp://*:5555");

	while(1) {
		fprintf(stderr,"%s",s_recv(socket));
		reply(socket);
	}
	return EXIT_SUCCESS;
}
