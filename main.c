#include <errno.h>
#include <stdio.h>

void print_dump(unsigned char chunk[16], size_t bytesRead) {
	printf("%012X", (int)bytesRead);

	for (int i = 0; i < 16; i++) {
		printf(" %02X", chunk[i]);
	}

	printf(" |");
	for (int i = 0; i < 16; i++) {
		if (chunk[i] < 32 || chunk[i] > 126) {
			printf(".");
		} else {
			printf("%c", chunk[i]);
		}
	}
	printf("|\n");
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Error: invalid arguments\n./build <filename>");
		return -1;
	}

	FILE* file;
	file = fopen(argv[1], "rb");
	if (file == NULL) {
		printf("Error: filename does not exist");
		return -1;
	}

	unsigned char chunk[16] = {0};
	size_t bytesRead = 0;
	size_t currRead = 0;
	while ((currRead = fread(chunk, sizeof(chunk), 1, file)) > 0) {
		print_dump(chunk, bytesRead);
		bytesRead += currRead;
	}
	fclose(file);
}
