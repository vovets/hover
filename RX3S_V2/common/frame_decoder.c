#include "frame_decoder.h"

#include <stddef.h>

uint16_t framingErrors = 0;

void frameDecoderStateWaitSync(FrameDecoder* decoder, uint8_t byte);
void frameDecoderStateWaitData(FrameDecoder* decoder, uint8_t byte);
void frameDecoderStateReadData(FrameDecoder* decoder, uint8_t byte);

void frameDecoderStateWaitSync(FrameDecoder* decoder, uint8_t byte)
{
    if (byte == 0x00) {
        decoder->state = &frameDecoderStateWaitData;
    }
}

void frameDecoderStateWaitData(FrameDecoder* decoder, uint8_t byte)
{
    if (byte != 0x00) {
        decoder->packet = packetAlloc(0, NULL);
        decoder->packet->data[0] = byte;
        decoder->packet->size = 1;
        decoder->state = &frameDecoderStateReadData;
    }
}

void frameDecoderStateReadData(FrameDecoder* decoder, uint8_t byte)
{
    if (byte == 0x00) {
        decoder->state = &frameDecoderStateWaitData;
        decoder->processPacketCallback(decoder->packet);
        decoder->packet = NULL;
        return;
    }
    
    if (decoder->packet->size == PACKET_MAX_SIZE) {
        ++framingErrors;
        packetFree(decoder->packet);
        decoder->packet = NULL;
        decoder->state = &frameDecoderStateWaitSync;
        return;
    }

    decoder->packet->data[decoder->packet->size++] = byte;
}
    
void frameDecoderInit(FrameDecoder* decoder, ProcessPacket callback)
{
    decoder->state = &frameDecoderStateWaitSync;
    decoder->processPacketCallback = callback;
    decoder->packet = NULL;
}

void frameDecoderFini(FrameDecoder* decoder)
{
    if (decoder->packet) {
        packetFree(decoder->packet);
    }
}

void frameDecoderProcessByte(FrameDecoder* decoder, uint8_t byte)
{
    decoder->state(decoder, byte);
}
