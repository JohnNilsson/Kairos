#include <zmq.h>
#include <stdio.h>  /* printf */
#include <string.h> /* memcpy */
#include <errno.h>  /* errno  */
#include <stdlib.h> /* atexit */

static void* init_context()
{
	static void *context = NULL;
	context = zmq_init(1);
	if(context == NULL) {
		fprintf(stderr, "0mq init failed: %s\n", zmq_strerror(errno));
		abort();
	}

	void term_context()
	{
		if(context != NULL)
			zmq_term(context);
	}
	atexit(term_context);
	return context;
}

static void* init_socket(void* context, int type)
{
	static void *socket = NULL;
	socket = zmq_socket(context, type);
	if(socket == NULL) {
		fprintf(stderr, "Could not create socket: %s\n", zmq_strerror(errno));
		abort();
	}

	void close_socket()
	{
		if(socket != NULL)
			zmq_close(socket);
			
	}
	atexit(close_socket);
	return socket;
}

static void* init_server_socket(void* context, int type, char* endpoint)
{
	void *socket = init_socket(context,type);

	if(-1 == zmq_bind(socket, endpoint)) {
		fprintf(stderr, "Could not bind socket: %s\n", zmq_strerror(errno));
		abort();
	}
	return socket;
}

static void* init_client_socket(void* context, int type, char* endpoint)
{
	void *socket = init_socket(context,type);
	if(-1 == zmq_connect(socket, endpoint)) {
		fprintf(stderr, "Could not connect to endpoint: %s\n", zmq_strerror(errno));
		abort();
	}
	return socket;
}

static char* s_recv (void *socket)
{
    zmq_msg_t msg;
    zmq_msg_init (&msg);
    if (zmq_recv (socket, &msg, 0))
        return (NULL);
    int size = zmq_msg_size (&msg);
    char *string = malloc (size + 1);
    memcpy (string, zmq_msg_data (&msg), size);
    zmq_msg_close (&msg);
    string [size] = 0;
    return (string);
}
