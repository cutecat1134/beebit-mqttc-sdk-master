#include<stdio.h>
#include<stdlib.h>
#include <beebitcpabe.h>
#include "beebit.h"


#include "SocketBuffer.h"
//"/home/pi/Desktop/beebit-cpabe-sdk/beebitcpabe.h"
#include "Heap.h"
//"/home/pi/Desktop/beebit-mqttc-sdk-master/paho.mqtt.c/src/beebit.h"
#define payload     "Hello World!\0"

int main(void){
	int payloadlen=strlen(payload);
	unsigned char* bee_buffer = "Hello World!";
	unsigned char* bee_buf = NULL;
//	bee_buffer=payload;
	int length=0;
	int bee_encodelen=0;
	length= cpabe_enc("/home/pi/Desktop/beebit-mqttc-sdk-master/cpabe_publickey", bee_buffer, "jackie", &bee_buf);
	
	printf("%u\n",bee_buf);
	
	int multiplier = 1 ;
	int number = 1;
	int value = 0;
	length=0;
	unsigned char* sub_pt_buffer = NULL;
//	unsigned char* sub_ct_buffer = NULL;
//	sub_ct_buffer=bee_buf;
	
	
	length=cpabe_dec("/home/pi/Desktop/beebit-mqttc-sdk-master/cpabe_publickey","/home/pi/Desktop/beebit-mqttc-sdk-master/cpabe_secretkey", bee_buf, &sub_pt_buffer);
	*((char*)(sub_pt_buffer+length))='\0';

	printf("%s\n",sub_pt_buffer);

	return 0;
}
/* 
-L. -lbeebit-cpabe \
        -lglib-2.0   \
        -Wl,-rpath /usr/local/lib -lgmp \
        -Wl,-rpath /usr/local/lib -lbswabe \
        -lpbc \
        -lcrypto \
        -lgmp

gcc ccc.c -g -L/usr/local/lib -lbeebit-cpabe -lglib-2.0 -Wl,-rpath /usr/local/lib -lgmp -Wl,-rpath /usr/local/lib -lbswabe -lpbc -lcrypto -lgmp -Wall -o ddd

*/