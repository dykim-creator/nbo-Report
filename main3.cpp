#include <stdio.h> // for printf
#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <netinet/in.h>

int main(int argc, char *argv[]) {
	FILE* in1, *in2;
	uint8_t network_buffer1[100];
	uint8_t network_buffer2[100];
	uint32_t* p1 = reinterpret_cast<uint32_t*>(network_buffer1);
	uint32_t* p2 = reinterpret_cast<uint32_t*>(network_buffer2);

	in1 = fopen(argv[1], "r");
	in2 = fopen(argv[2], "r");

	fread(network_buffer1, 100, 1, in1);
	fread(network_buffer2, 100, 1, in2);

	uint32_t final1 = ntohl(*p1);
	uint32_t final2 = ntohl(*p2);

	printf("First File = 0x%x\n", final1);
	printf("Second File = 0x%x\n\n", final2);

	fclose(in1);
	fclose(in2);

	return printf("sum = 0x%x\n", final1 + final2);

}
