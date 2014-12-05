#pragma once

#include "packetconf.h"

#include <stdint.h>

typedef struct SerialDriver SerialDriver;

// These definitions must be provided in packetconf.h
//
// #define PACKET_MAX_SIZE 64
// #define MAX_PACKETS 1

typedef struct {
    uint8_t size;
    uint8_t* data;
} Packet;

#define PACKET_BUFFER_SIZE (PACKET_MAX_SIZE + sizeof(Packet))

#define PACKET_POOL_DEFS \
    MEMORYPOOL_DECL(packetPool, PACKET_BUFFER_SIZE, NULL);  \
    SEMAPHORE_DECL(packetPoolSem, MAX_PACKETS); \
    uint8_t packetPoolArena[PACKET_BUFFER_SIZE * MAX_PACKETS]

void packetPoolInit(void);

Packet* packetAlloc(uint8_t size, uint8_t* data);

void packetSendAndFree(SerialDriver* sd, Packet* packet);

void packetFree(Packet* packet);
