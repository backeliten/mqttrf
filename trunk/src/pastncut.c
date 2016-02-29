
	//mosquitto mosquitto_array[10] = NULL;

//	struct mosquitto[20] *mosquitto_array = NULL;

	//struct mosquitto mosquitto_array[10] = NULL;

	//struct mosquitto *mosq = NULL;
//	struct mosquitto *output1 = NULL;
//	struct mosquitto *output2 = NULL;
//	struct mosquitto *output3 = NULL;
//	struct mosquitto *output4 = NULL;
//	struct mosquitto *output5 = NULL;

//	output1 = mosquitto_new(NULL, clean_session, NULL);
//		if(!output1){
//			fprintf(stderr, "Error: Out of memory1.\n");
//			return 1;
//		}
//
//	output2 = mosquitto_new(NULL, clean_session, NULL);
//		if(!output2){
//			fprintf(stderr, "Error: Out of memory2.\n");
//			return 1;
//		}
//
//	output3 = mosquitto_new(NULL, clean_session, NULL);
//		if(!output2){
//			fprintf(stderr, "Error: Out of memory3.\n");
//			return 1;
//		}
//
//    output4 = mosquitto_new(NULL, clean_session, NULL);
//		if(!output3){
//			fprintf(stderr, "Error: Out of memory4.\n");
//			return 1;
//		}
//
//	 output5 = mosquitto_new(NULL, clean_session, NULL);
//		if(!output3){
//			fprintf(stderr, "Error: Out of memory5.\n");
//			return 1;
//		}


//    int fd;
//    fd=OpenToSerial(argv[1]);
//    usleep(50000);
//    WriteToSerial(fd, argv[2]);
//    usleep(600000);
//    ReadFromSerial(fd);
//    close(fd);


//	if(mosquitto_connect(output1, host, port, keepalive)){
//		fprintf(stderr, "Unable to connect.\n");
//		return 1;
//	}
//
//	if(mosquitto_connect(output2, host, port, keepalive)){
//		fprintf(stderr, "Unable to connect.\n");
//		return 1;
//	}
//
//	if(mosquitto_connect(output3, host, port, keepalive)){
//		fprintf(stderr, "Unable to connect.\n");
//		return 1;
//	}
//
//	if(mosquitto_connect(output4, host, port, keepalive)){
//		fprintf(stderr, "Unable to connect.\n");
//		return 1;
//	}
//
//	if(mosquitto_connect(output5, host, port, keepalive)){
//		fprintf(stderr, "Unable to connect.\n");
//		return 1;
//	}


		mosquitto_loop(output2, -1, 1);
		mosquitto_loop(output3, -1, 1);
		mosquitto_loop(output4, -1, 1);
		mosquitto_loop(output5, -1, 1);


		mosquitto_destroy(output1);
		mosquitto_destroy(output2);
		mosquitto_destroy(output3);
		mosquitto_destroy(output4);
		mosquitto_destroy(output5);
