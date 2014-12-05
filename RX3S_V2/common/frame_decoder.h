#pragma once

#include "packet.h"

struct FrameDecoderT;

typedef void (*ProcessByte)(struct FrameDecoderT* decoder, uint8_t byte);
typedef void (*ProcessPacket)(Packet*);

typedef struct FrameDecoderT {
    ProcessByte state;
    ProcessPacket processPacketCallback;
    Packet* packet;
} FrameDecoder;

uint16_t framingErrors;

// ownership ot the packet transferred to callback
void frameDecoderInit(FrameDecoder* decoder, ProcessPacket callback);
void frameDecoderFini(FrameDecoder* decoder);
void frameDecoderProcessByte(FrameDecoder* decoder, uint8_t byte);

