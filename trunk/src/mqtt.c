#include <stdio.h>
#include <mosquitto.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <memory.h>
#include <termios.h>

/*FUNCTIONS DECLARE*/

int OpenToSerial(const char* ttyDev);
void WriteToSerial(int fd, const char *str);
void ReadFromSerial(int fd);

void output1_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message);
void output1_connect_callback(struct mosquitto *mosq, void *userdata, int result);
void output1_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos);

void output2_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message);
void output2_connect_callback(struct mosquitto *mosq, void *userdata, int result);
void output2_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos);

void output3_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message);
void output3_connect_callback(struct mosquitto *mosq, void *userdata, int result);
void output3_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos);

void output4_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message);
void output4_connect_callback(struct mosquitto *mosq, void *userdata, int result);
void output4_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos);

void output5_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message);
void output5_connect_callback(struct mosquitto *mosq, void *userdata, int result);
void output5_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos);

//void my_log_callback(struct mosquitto *mosq, void *userdata, int level, const char *str);

/*FUNCTIONS*/

void output1_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
	if(message->payloadlen){
		//Do the funny stuff Here
		printf("%s %s\n", (char*)message->topic, (char*)message->payload);

		char value = 0;
		value = *(char*)message->payload;

		int fd;
		fd=OpenToSerial("/dev/ttyS0");
		usleep(50000);
		if(value == '1')
		{
			WriteToSerial(fd, "A1E");
			printf("Set output A\n");
		}
		if(value == '0')
		{
			WriteToSerial(fd, "A0E");
			printf("Clear output A\n");
		}
		//usleep(600000);
		//ReadFromSerial(fd);
		close(fd);

		//Set callback to send status that it has been updated even if we dont know if the output was really set.
	}else{
		printf("%s (null)\n", message->topic);
	}
	fflush(stdout);
}

void output2_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
	if(message->payloadlen){
		printf("%s %s\n", (char *)message->topic, (char *)message->payload);

		char value = 0;
		value = *(char*)message->payload;

		int fd;
		fd=OpenToSerial("/dev/ttyS0");
		usleep(50000);
		if(value == '1')
		{
			WriteToSerial(fd, "B1E");
			printf("Set output B\n");
		}
		if(value == '0')
		{
			WriteToSerial(fd, "B0E");
			printf("Clear output B\n");
		}
		//usleep(600000);
		//ReadFromSerial(fd);
		close(fd);

	}else{
		printf("%s (null)\n", message->topic);
	}
	fflush(stdout);
}

void output3_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
	if(message->payloadlen){
		printf("%s %s\n", (char *)message->topic, (char *)message->payload);
		char value = 0;
		value = *(char*)message->payload;

		int fd;
		fd=OpenToSerial("/dev/ttyS0");
		usleep(50000);
		if(value == '1')
		{
			WriteToSerial(fd, "C1E");
			printf("Set output C\n");
		}
		if(value == '0')
		{
			WriteToSerial(fd, "C0E");
			printf("Clear output C\n");
		}
		//usleep(600000);
		//ReadFromSerial(fd);
		close(fd);
	}else{
		printf("%s (null)\n", message->topic);
	}
	fflush(stdout);
}

void output4_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
	if(message->payloadlen){
		printf("%s %s\n", (char *)message->topic, (char *)message->payload);
		char value = 0;
		value = *(char*)message->payload;

		int fd;
		fd=OpenToSerial("/dev/ttyS0");
		usleep(50000);
		if(value == '1')
		{
			WriteToSerial(fd, "D1E");
			printf("Set output D\n");
		}
		if(value == '0')
		{
			WriteToSerial(fd, "D0E");
			printf("Clear output D\n");
		}
		//usleep(600000);
		//ReadFromSerial(fd);
		close(fd);
	}else{
		printf("%s (null)\n", message->topic);
	}
	fflush(stdout);
}

void output5_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
	if(message->payloadlen){
		printf("%s %s\n", (char *)message->topic, (char *)message->payload);

		char value = 0;
		value = *(char*)message->payload;

		int fd;
		fd=OpenToSerial("/dev/ttyS0");
		usleep(50000);
		if(value == '1')
		{
			WriteToSerial(fd, "F1E");
			printf("Set output F\n");
		}
		if(value == '0')
		{
			WriteToSerial(fd, "F0E");
			printf("Clear output F\n");
		}
		//usleep(600000);
		//ReadFromSerial(fd);
		close(fd);
	}else{
		printf("%s (null)\n", message->topic);
	}
	fflush(stdout);
}

void output1_connect_callback(struct mosquitto *mosq, void *userdata, int result)
{
	int i;		//Didnt work to use subscribe on two channels, we got a nasty race condition, so that messages was not arrived.
	if(!result){
		/* Subscribe to broker information topics on successful connect. */
		mosquitto_subscribe(mosq, NULL, "command/output1", 2);
	}else{
		fprintf(stderr, "Connect failed\n");
	}
}

void output2_connect_callback(struct mosquitto *mosq, void *userdata, int result)
{
	int i;		//Didnt work to use subscribe on two channels, we got a nasty race condition, so that messages was not arrived.
	if(!result){
		/* Subscribe to broker information topics on successful connect. */
		mosquitto_subscribe(mosq, NULL, "command/output2", 2);
	}else{
		fprintf(stderr, "Connect failed\n");
	}
}

void output3_connect_callback(struct mosquitto *mosq, void *userdata, int result)
{
	int i;		//Didnt work to use subscribe on two channels, we got a nasty race condition, so that messages was not arrived.
	if(!result){
		/* Subscribe to broker information topics on successful connect. */
		mosquitto_subscribe(mosq, NULL, "command/output3", 2);
	}else{
		fprintf(stderr, "Connect failed\n");
	}
}

void output4_connect_callback(struct mosquitto *mosq, void *userdata, int result)
{
	int i;		//Didnt work to use subscribe on two channels, we got a nasty race condition, so that messages was not arrived.
	if(!result){
		/* Subscribe to broker information topics on successful connect. */
		mosquitto_subscribe(mosq, NULL, "command/output4", 2);
	}else{
		fprintf(stderr, "Connect failed\n");
	}
}

void output5_connect_callback(struct mosquitto *mosq, void *userdata, int result)
{
	int i;		//Didnt work to use subscribe on two channels, we got a nasty race condition, so that messages was not arrived.
	if(!result){
		/* Subscribe to broker information topics on successful connect. */
		mosquitto_subscribe(mosq, NULL, "command/output5", 2);
	}else{
		fprintf(stderr, "Connect failed\n");
	}
}

void output1_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos)
{
	int i;

	printf("Subscribed (mid: %d): %d", mid, granted_qos[0]);
	for(i=1; i<qos_count; i++){
		printf(", %d", granted_qos[i]);
	}
	printf("\n");
}

void output2_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos)
{
	int i;

	printf("Subscribed (mid: %d): %d", mid, granted_qos[0]);
	for(i=1; i<qos_count; i++){
		printf(", %d", granted_qos[i]);
	}
	printf("\n");
}

void output3_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos)
{
	int i;

	printf("Subscribed (mid: %d): %d", mid, granted_qos[0]);
	for(i=1; i<qos_count; i++){
		printf(", %d", granted_qos[i]);
	}
	printf("\n");
}

void output4_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos)
{
	int i;

	printf("Subscribed (mid: %d): %d", mid, granted_qos[0]);
	for(i=1; i<qos_count; i++){
		printf(", %d", granted_qos[i]);
	}
	printf("\n");
}

void output5_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos)
{
	int i;

	printf("Subscribed (mid: %d): %d", mid, granted_qos[0]);
	for(i=1; i<qos_count; i++){
		printf(", %d", granted_qos[i]);
	}
	printf("\n");
}

/*
void my_log_callback(struct mosquitto *mosq, void *userdata, int level, const char *str)
{
	// Pring all log messages regardless of level.
	printf("%s\n", str);
}
*/

int main(int argc, char *argv[])
{

//    int fd;
//    fd=OpenToSerial(argv[1]);
//    usleep(50000);
//    WriteToSerial(fd, argv[2]);
//    usleep(600000);
//    ReadFromSerial(fd);
//    close(fd);

	int i;
	char *host = "localhost";
	int port = 1883;
	int keepalive = 60;
	bool clean_session = true;
	//struct mosquitto *mosq = NULL;
	struct mosquitto *output1 = NULL;
	struct mosquitto *output2 = NULL;
	struct mosquitto *output3 = NULL;
	struct mosquitto *output4 = NULL;
	struct mosquitto *output5 = NULL;

	/*Init*/
	mosquitto_lib_init();

	output1 = mosquitto_new(NULL, clean_session, NULL);
		if(!output1){
			fprintf(stderr, "Error: Out of memory1.\n");
			return 1;
		}

	output2 = mosquitto_new(NULL, clean_session, NULL);
		if(!output2){
			fprintf(stderr, "Error: Out of memory2.\n");
			return 1;
		}

	output3 = mosquitto_new(NULL, clean_session, NULL);
		if(!output2){
			fprintf(stderr, "Error: Out of memory3.\n");
			return 1;
		}

    output4 = mosquitto_new(NULL, clean_session, NULL);
		if(!output3){
			fprintf(stderr, "Error: Out of memory4.\n");
			return 1;
		}

	 output5 = mosquitto_new(NULL, clean_session, NULL);
		if(!output3){
			fprintf(stderr, "Error: Out of memory5.\n");
			return 1;
		}

	//mosquitto_log_callback_set(output1, my_log_callback); //Does not need this one for now
	mosquitto_connect_callback_set(output1, output1_connect_callback);
	mosquitto_message_callback_set(output1, output1_message_callback);
	mosquitto_subscribe_callback_set(output1, output1_subscribe_callback);

	mosquitto_connect_callback_set(output2, output2_connect_callback);
	mosquitto_message_callback_set(output2, output2_message_callback);
	mosquitto_subscribe_callback_set(output2, output2_subscribe_callback);

	mosquitto_connect_callback_set(output3, output3_connect_callback);
	mosquitto_message_callback_set(output3, output3_message_callback);
	mosquitto_subscribe_callback_set(output3, output3_subscribe_callback);

	mosquitto_connect_callback_set(output4, output4_connect_callback);
	mosquitto_message_callback_set(output4, output4_message_callback);
	mosquitto_subscribe_callback_set(output4, output4_subscribe_callback);

	mosquitto_connect_callback_set(output5, output5_connect_callback);
	mosquitto_message_callback_set(output5, output5_message_callback);
	mosquitto_subscribe_callback_set(output5, output5_subscribe_callback);


	if(mosquitto_connect(output1, host, port, keepalive)){
		fprintf(stderr, "Unable to connect.\n");
		return 1;
	}

	if(mosquitto_connect(output2, host, port, keepalive)){
		fprintf(stderr, "Unable to connect.\n");
		return 1;
	}

	if(mosquitto_connect(output3, host, port, keepalive)){
		fprintf(stderr, "Unable to connect.\n");
		return 1;
	}

	if(mosquitto_connect(output4, host, port, keepalive)){
		fprintf(stderr, "Unable to connect.\n");
		return 1;
	}

	if(mosquitto_connect(output5, host, port, keepalive)){
		fprintf(stderr, "Unable to connect.\n");
		return 1;
	}

	while(1)
	{
		mosquitto_loop(output1, -1, 1);
		mosquitto_loop(output2, -1, 1);
		mosquitto_loop(output3, -1, 1);
		mosquitto_loop(output4, -1, 1);
		mosquitto_loop(output5, -1, 1);
		usleep(50000);		//sleep for 50ms to catch the breath
	}

//	mosquitto_loop_forever(mosq, -1, 1);


	mosquitto_destroy(output1);
	mosquitto_destroy(output2);
	mosquitto_destroy(output3);
	mosquitto_destroy(output4);
	mosquitto_destroy(output5);

	mosquitto_lib_cleanup();
	return 0;
}

int OpenToSerial(const char* ttyDev)
{
    struct termios newtio;

    int fd = open(ttyDev, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd <0) perror(ttyDev);

    tcgetattr (fd,&newtio);    // get the current port settings
    newtio.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;
    newtio.c_lflag = ICANON;
    newtio.c_cc[VEOL] = 0;

    cfmakeraw(&newtio);

    tcflush(fd, TCIFLUSH);
    tcsetattr(fd,TCSANOW, &newtio);
    tcflush(fd, TCIFLUSH);
    return fd;
}

void WriteToSerial(int fd, const char *str)
{
//	printf("Send %s \n\r", str);
    int i = strlen(str);
    write(fd, str, i);
}

void ReadFromSerial(int fd)
{
    int count = 0;
	int i = 0;
//    int i = strlen(command);
	//printf("length %u", i);

	char command[20] = {0};

    count =  read(fd, command, 20);
	if(count < 1)
	{
		//printf("Read no character from port count %d \n\r", count);
	}
	else
	{
	//	printf("Count %d Value: %s \n\r",count, command);
		printf("%s",command);
	}
//	for(i=0;i<20;i++)
//	{
//		command[i] = 0;
//	}
}
