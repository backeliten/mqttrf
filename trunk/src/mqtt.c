#include <stdio.h>
#include <mosquitto.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <memory.h>
#include <termios.h>

/*DEFINE DECLARE*/
#define 	PORT1_ON		"A1E"
#define 	PORT1_OFF		"A0E"

#define 	PORT2_ON		"B1E"
#define 	PORT2_OFF		"B0E"

#define 	PORT3_ON		"C1E"
#define 	PORT3_OFF		"C0E"

#define 	PORT4_ON		"D1E"
#define 	PORT4_OFF		"D0E"

#define 	PORT5_ON		"E1E"
#define 	PORT5_OFF		"E0E"

#define 	PORT6_ON		"F1E"
#define 	PORT6_OFF		"F0E"

#define 	PORT7_ON		"G1E"
#define 	PORT7_OFF		"G0E"

#define 	PORT8_ON		"H1E"
#define 	PORT8_OFF		"H0E"

#define 	PORT9_ON		"I1E"
#define 	PORT9_OFF		"I0E"

#define 	PORT10_ON		"J1E"
#define 	PORT10_OFF		"J0E"

#define 	PORT11_ON		"K1E"
#define 	PORT11_OFF		"K0E"

#define		SERIAL_PORT		"/dev/ttyUSB0"

#define 	MQQT_SERVER		"192.168.0.6"

#define 	NUM_OF_OUTPUTS	11

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

void output6_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message);
void output6_connect_callback(struct mosquitto *mosq, void *userdata, int result);
void output6_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos);

void output7_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message);
void output7_connect_callback(struct mosquitto *mosq, void *userdata, int result);
void output7_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos);

void output8_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message);
void output8_connect_callback(struct mosquitto *mosq, void *userdata, int result);
void output8_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos);

void output9_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message);
void output9_connect_callback(struct mosquitto *mosq, void *userdata, int result);
void output9_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos);

void output10_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message);
void output10_connect_callback(struct mosquitto *mosq, void *userdata, int result);
void output10_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos);

void output11_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message);
void output11_connect_callback(struct mosquitto *mosq, void *userdata, int result);
void output11_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos);

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
		fd=OpenToSerial(SERIAL_PORT);
		usleep(50000);
		if(value == '1')
		{
			WriteToSerial(fd, PORT1_ON);
			printf("Set output A\n");
		}
		if(value == '0')
		{
			WriteToSerial(fd, PORT1_OFF);
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
		fd=OpenToSerial(SERIAL_PORT);
		usleep(50000);
		if(value == '1')
		{
			WriteToSerial(fd, PORT2_ON);
			printf("Set output B\n");
		}
		if(value == '0')
		{
			WriteToSerial(fd, PORT2_OFF);
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
		fd=OpenToSerial(SERIAL_PORT);
		usleep(50000);
		if(value == '1')
		{
			WriteToSerial(fd, PORT3_ON);
			printf("Set output C\n");
		}
		if(value == '0')
		{
			WriteToSerial(fd, PORT3_OFF);
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
		fd=OpenToSerial(SERIAL_PORT);
		usleep(50000);
		if(value == '1')
		{
			WriteToSerial(fd, PORT4_ON);
			printf("Set output D\n");
		}
		if(value == '0')
		{
			WriteToSerial(fd, PORT4_OFF);
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
		fd=OpenToSerial(SERIAL_PORT);
		usleep(50000);
		if(value == '1')
		{
			WriteToSerial(fd, PORT5_ON);
			printf("Set output F\n");
		}
		if(value == '0')
		{
			WriteToSerial(fd, PORT5_OFF);
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

void output6_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
	if(message->payloadlen){
		printf("%s %s\n", (char *)message->topic, (char *)message->payload);

		char value = 0;
		value = *(char*)message->payload;

		int fd;
		fd=OpenToSerial(SERIAL_PORT);
		usleep(50000);
		if(value == '1')
		{
			WriteToSerial(fd, PORT6_ON);
			printf("Set output F\n");
		}
		if(value == '0')
		{
			WriteToSerial(fd, PORT6_OFF);
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

void output7_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
	if(message->payloadlen){
		printf("%s %s\n", (char *)message->topic, (char *)message->payload);

		char value = 0;
		value = *(char*)message->payload;

		int fd;
		fd=OpenToSerial(SERIAL_PORT);
		usleep(50000);
		if(value == '1')
		{
			WriteToSerial(fd, PORT7_ON);
			printf("Set output F\n");
		}
		if(value == '0')
		{
			WriteToSerial(fd, PORT7_OFF);
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

void output8_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
	if(message->payloadlen){
		printf("%s %s\n", (char *)message->topic, (char *)message->payload);

		char value = 0;
		value = *(char*)message->payload;

		int fd;
		fd=OpenToSerial(SERIAL_PORT);
		usleep(50000);
		if(value == '1')
		{
			WriteToSerial(fd, PORT8_ON);
			printf("Set output F\n");
		}
		if(value == '0')
		{
			WriteToSerial(fd, PORT8_OFF);
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

void output9_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
	if(message->payloadlen){
		printf("%s %s\n", (char *)message->topic, (char *)message->payload);

		char value = 0;
		value = *(char*)message->payload;

		int fd;
		fd=OpenToSerial(SERIAL_PORT);
		usleep(50000);
		if(value == '1')
		{
			WriteToSerial(fd, PORT9_ON);
			printf("Set output F\n");
		}
		if(value == '0')
		{
			WriteToSerial(fd, PORT9_OFF);
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

void output10_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
	if(message->payloadlen){
		printf("%s %s\n", (char *)message->topic, (char *)message->payload);

		char value = 0;
		value = *(char*)message->payload;

		int fd;
		fd=OpenToSerial(SERIAL_PORT);
		usleep(50000);
		if(value == '1')
		{
			WriteToSerial(fd, PORT10_ON);
			printf("Set output F\n");
		}
		if(value == '0')
		{
			WriteToSerial(fd, PORT10_OFF);
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

void output11_message_callback(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
	if(message->payloadlen){
		printf("%s %s\n", (char *)message->topic, (char *)message->payload);

		char value = 0;
		value = *(char*)message->payload;

		int fd;
		fd=OpenToSerial(SERIAL_PORT);
		usleep(50000);
		if(value == '1')
		{
			WriteToSerial(fd, PORT11_ON);
			printf("Set output F\n");
		}
		if(value == '0')
		{
			WriteToSerial(fd, PORT11_OFF);
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

void output6_connect_callback(struct mosquitto *mosq, void *userdata, int result)
{
	int i;		//Didnt work to use subscribe on two channels, we got a nasty race condition, so that messages was not arrived.
	if(!result){
		/* Subscribe to broker information topics on successful connect. */
		mosquitto_subscribe(mosq, NULL, "command/output6", 2);
	}else{
		fprintf(stderr, "Connect failed\n");
	}
}

void output7_connect_callback(struct mosquitto *mosq, void *userdata, int result)
{
	int i;		//Didnt work to use subscribe on two channels, we got a nasty race condition, so that messages was not arrived.
	if(!result){
		/* Subscribe to broker information topics on successful connect. */
		mosquitto_subscribe(mosq, NULL, "command/output7", 2);
	}else{
		fprintf(stderr, "Connect failed\n");
	}
}

void output8_connect_callback(struct mosquitto *mosq, void *userdata, int result)
{
	int i;		//Didnt work to use subscribe on two channels, we got a nasty race condition, so that messages was not arrived.
	if(!result){
		/* Subscribe to broker information topics on successful connect. */
		mosquitto_subscribe(mosq, NULL, "command/output8", 2);
	}else{
		fprintf(stderr, "Connect failed\n");
	}
}

void output9_connect_callback(struct mosquitto *mosq, void *userdata, int result)
{
	int i;		//Didnt work to use subscribe on two channels, we got a nasty race condition, so that messages was not arrived.
	if(!result){
		/* Subscribe to broker information topics on successful connect. */
		mosquitto_subscribe(mosq, NULL, "command/output9", 2);
	}else{
		fprintf(stderr, "Connect failed\n");
	}
}

void output10_connect_callback(struct mosquitto *mosq, void *userdata, int result)
{
	int i;		//Didnt work to use subscribe on two channels, we got a nasty race condition, so that messages was not arrived.
	if(!result){
		/* Subscribe to broker information topics on successful connect. */
		mosquitto_subscribe(mosq, NULL, "command/output10", 2);
	}else{
		fprintf(stderr, "Connect failed\n");
	}
}

void output11_connect_callback(struct mosquitto *mosq, void *userdata, int result)
{
	int i;		//Didnt work to use subscribe on two channels, we got a nasty race condition, so that messages was not arrived.
	if(!result){
		/* Subscribe to broker information topics on successful connect. */
		mosquitto_subscribe(mosq, NULL, "command/output11", 2);
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

void output6_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos)
{
	int i;

	printf("Subscribed (mid: %d): %d", mid, granted_qos[0]);
	for(i=1; i<qos_count; i++){
		printf(", %d", granted_qos[i]);
	}
	printf("\n");
}

void output7_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos)
{
	int i;

	printf("Subscribed (mid: %d): %d", mid, granted_qos[0]);
	for(i=1; i<qos_count; i++){
		printf(", %d", granted_qos[i]);
	}
	printf("\n");
}

void output8_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos)
{
	int i;

	printf("Subscribed (mid: %d): %d", mid, granted_qos[0]);
	for(i=1; i<qos_count; i++){
		printf(", %d", granted_qos[i]);
	}
	printf("\n");
}

void output9_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos)
{
	int i;

	printf("Subscribed (mid: %d): %d", mid, granted_qos[0]);
	for(i=1; i<qos_count; i++){
		printf(", %d", granted_qos[i]);
	}
	printf("\n");
}

void output10_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos)
{
	int i;

	printf("Subscribed (mid: %d): %d", mid, granted_qos[0]);
	for(i=1; i<qos_count; i++){
		printf(", %d", granted_qos[i]);
	}
	printf("\n");
}

void output11_subscribe_callback(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos)
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

	int i;
	int count = 0;					//Used for counting
	char *host = MQQT_SERVER;
	int port = 1883;
	int keepalive = 60;
	bool clean_session = true;

	struct mosquitto *mqtt_array[NUM_OF_OUTPUTS];

	/*Init*/
	mosquitto_lib_init();

	for(count=0;count < NUM_OF_OUTPUTS;count++)
	{
		mqtt_array[count] = mosquitto_new(NULL, clean_session, NULL);
		if(!mqtt_array[count])
		{
			fprintf(stderr, "Error: Out of memory on %u.\n", count);
			return 1;
		}
	}

	//TODO: Read XML file with information about mqtt channel subscribe and data to be written out to transmitter
	//FIXME: Set this to be smart and can be build using iterativ process

	//mosquitto_log_callback_set(output1, my_log_callback); //Does not need this one for now

	mosquitto_connect_callback_set(mqtt_array[0], output1_connect_callback);
	mosquitto_message_callback_set(mqtt_array[0], output1_message_callback);
	mosquitto_subscribe_callback_set(mqtt_array[0], output1_subscribe_callback);

	mosquitto_connect_callback_set(mqtt_array[1], output2_connect_callback);
	mosquitto_message_callback_set(mqtt_array[1], output2_message_callback);
	mosquitto_subscribe_callback_set(mqtt_array[1], output2_subscribe_callback);

	mosquitto_connect_callback_set(mqtt_array[2], output3_connect_callback);
	mosquitto_message_callback_set(mqtt_array[2], output3_message_callback);
	mosquitto_subscribe_callback_set(mqtt_array[2], output3_subscribe_callback);

	mosquitto_connect_callback_set(mqtt_array[3], output4_connect_callback);
	mosquitto_message_callback_set(mqtt_array[3], output4_message_callback);
	mosquitto_subscribe_callback_set(mqtt_array[3], output4_subscribe_callback);

	mosquitto_connect_callback_set(mqtt_array[4], output5_connect_callback);
	mosquitto_message_callback_set(mqtt_array[4], output5_message_callback);
	mosquitto_subscribe_callback_set(mqtt_array[4], output5_subscribe_callback);

	mosquitto_connect_callback_set(mqtt_array[5], output6_connect_callback);
	mosquitto_message_callback_set(mqtt_array[5], output6_message_callback);
	mosquitto_subscribe_callback_set(mqtt_array[5], output6_subscribe_callback);

	mosquitto_connect_callback_set(mqtt_array[6], output7_connect_callback);
	mosquitto_message_callback_set(mqtt_array[6], output7_message_callback);
	mosquitto_subscribe_callback_set(mqtt_array[6], output7_subscribe_callback);

	mosquitto_connect_callback_set(mqtt_array[7], output8_connect_callback);
	mosquitto_message_callback_set(mqtt_array[7], output8_message_callback);
	mosquitto_subscribe_callback_set(mqtt_array[7], output8_subscribe_callback);

	mosquitto_connect_callback_set(mqtt_array[8], output9_connect_callback);
	mosquitto_message_callback_set(mqtt_array[8], output9_message_callback);
	mosquitto_subscribe_callback_set(mqtt_array[8], output9_subscribe_callback);

	mosquitto_connect_callback_set(mqtt_array[9], output10_connect_callback);
	mosquitto_message_callback_set(mqtt_array[9], output10_message_callback);
	mosquitto_subscribe_callback_set(mqtt_array[9], output10_subscribe_callback);

	mosquitto_connect_callback_set(mqtt_array[10], output11_connect_callback);
	mosquitto_message_callback_set(mqtt_array[10], output11_message_callback);
	mosquitto_subscribe_callback_set(mqtt_array[10], output11_subscribe_callback);

//	mosquitto_connect_callback_set(mqtt_array[11], output5_connect_callback);
//	mosquitto_message_callback_set(mqtt_array[11], output5_message_callback);
//	mosquitto_subscribe_callback_set(mqtt_array[11], output5_subscribe_callback);

	for(count=0;count<NUM_OF_OUTPUTS;count++)
	{
		if(mosquitto_connect(mqtt_array[count], host, port, keepalive)){
			fprintf(stderr, "Unable to connect.\n");
			return 1;
		}
	}

	while(1)
	{
		for(count=0;count<NUM_OF_OUTPUTS;count++)
		{
			mosquitto_loop(mqtt_array[count], -1, 1);
		}
		usleep(10000);		//sleep for 10ms to catch the breath
	}

	for(count=0;count<NUM_OF_OUTPUTS;count++)
	{
		mosquitto_destroy(mqtt_array[count]);
	}

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
