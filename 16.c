#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512    // size of a block in bytes
#define INDEX_SIZE 128    // size of an index block in bytes
#define NUM_BLOCKS 1024   // total number of blocks on disk

typedef struct {
    int index_block;      // disk address of index block for file
    int num_blocks;       // number of blocks occupied by file
} File;

void create_file(File* file) {
    int num_blocks;
    printf("Enter number of blocks for file: ");
    scanf("%d", &num_blocks);

    int num_index_blocks = num_blocks / (INDEX_SIZE / sizeof(int)) + 1;
    int* index = (int*)malloc(INDEX_SIZE);
    int* block_addresses = (int*)malloc(num_blocks * sizeof(int));
    for (int i = 0; i < num_blocks; i++) {
        block_addresses[i] = i + num_index_blocks;
    }

    int index_block_address = find_free_block();
    if (index_block_address == -1) {
        printf("Error: Disk is full\n");
        return;
    }
    write_block(index_block_address, index);

    for (int i = 0; i < num_index_blocks; i++) {
        index[i] = find_free_block();
        if (index[i] == -1) {
            printf("Error: Disk is full\n");
            return;
        }
    }
    index[num_index_blocks] = -1;

    for (int i = 0; i < num_index_blocks; i++) {
        int offset = i * INDEX_SIZE;
        write_block(index[i], block_addresses + offset);
    }

    file->index_block = index_block_address;
    file->num_blocks = num_blocks;
}

void delete_file(File* file) {
    int num_index_blocks = file->num_blocks / (INDEX_SIZE / sizeof(int)) + 1;
    int* index = (int*)malloc(INDEX_SIZE);
    read_block(file->index_block, index);

    for (int i = 0; i < num_index_blocks; i++) {
        int block_address = index[i];
        int* block = (int*)malloc(BLOCK_SIZE);
        read_block(block_address, block);

        for (int j = 0; j < INDEX_SIZE / sizeof(int); j++) {
            if (block[j] != -1) {
                free_block(block[j]);
            }
        }

        free(block);
        free_block(block_address);
    }

    free(index);
    free_block(file->index_block);
    file->index_block = -1;
    file->num_blocks = 0;
}

void write_file(File* file, void* data) {
    int num_index_blocks = file->num_blocks / (INDEX_SIZE / sizeof(int)) + 1;
    int* index = (int*)malloc(INDEX_SIZE);
    read_block(file->index_block, index);

    int block_address_index = 0;
    int block_address = index[block_address_index];
    int offset = 0;
    char* block_data = (char*)data;

    while (block_address != -1) {
        int bytes_to_write = BLOCK_SIZE;
        if (offset + bytes_to_write > file->num_blocks * BLOCK_SIZE) {
            bytes_to_write = (file->num_blocks * BLOCK_SIZE) - offset;
        }
        write_block(block_address, block_data + offset);
        offset += bytes_to_write;

        if (offset % BLOCK_SIZE == 0 && block_address_index < num_index_blocks -     1) {
        block_address_index++;
        block_address = index[block_address_index];
    }
}

free(index);

  
}

void read_file(File* file, void* data) {
int num_index_blocks = file->num_blocks / (INDEX_SIZE / sizeof(int)) + 1;
int* index = (int*)malloc(INDEX_SIZE);
read_block(file->index_block, index);
int block_address_index = 0;
int block_address = index[block_address_index];
int offset = 0;
char* block_data = (char*)data;

while (block_address != -1) {
    int bytes_to_read = BLOCK_SIZE;
    if (offset + bytes_to_read > file->num_blocks * BLOCK_SIZE) {
        bytes_to_read = (file->num_blocks * BLOCK_SIZE) - offset;
    }
    read_block(block_address, block_data + offset);
    offset += bytes_to_read;

    if (offset % BLOCK_SIZE == 0 && block_address_index < num_index_blocks - 1) {
        block_address_index++;
        block_address = index[block_address_index];
    }
    else {
        block_address = -1;
    }
}

free(index);
