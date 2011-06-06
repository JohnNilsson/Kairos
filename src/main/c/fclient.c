#include "zmq.h"


#define MAX_LEN = 1024;

static void send(void *socket, char* text, size_t bytes)
{
	zmq_msg_t msg;
	zmq_msg_init_size(&msg,bytes);
	memcpy(zmq_msg_data(&msg), text, bytes);
	zmq_send(socket,&msg,0);
	zmq_msg_close(&msg);
}


int main (void)
{
	void *socket = init_client_socket(init_context(),ZMQ_PUSH,"tcp://localhost:5555");

	FILE *in = stdin;
	size_t bytes_read;
	size_t bytes_used;
	char *line;
	while(-1 != (bytes_read = getline(&line,&bytes_used,in))) {
		send(socket, line, bytes_read);
	}
	return EXIT_SUCCESS;
}
