import sys
import serial
import time


# SERIAL_DEV = "/dev/rfcomm0"
SERIAL_DEV = "/dev/ttyUSB0"

class CobsDecodeError(Exception):
    pass


def cobs_decode(packet):
    decoded_packet = bytearray()
    code_pos = 0
    packet_end  = len(packet)
    while True:
        code = packet[code_pos]
        in_block_end = code_pos + code
        if in_block_end > packet_end:
            raise CobsDecodeError("block ends beyond packet boundary")
        decoded_packet.extend(packet[code_pos + 1:in_block_end])
        if code < 255 and in_block_end < packet_end:
            decoded_packet.append(0)
        if in_block_end == packet_end:
            return decoded_packet
        code_pos = in_block_end


class PacketDecoder:
    def __init__(self, packet_processor):
        self.state = self._state_wait_sync;
        self.packet_processor = packet_processor
        self.current_packet = None

    def _state_wait_sync(self, b):
        if not b:
            self.state = self._state_wait_begin

    def _state_wait_begin(self, b):
        if b:
            self.current_packet = bytearray()
            self.current_packet.append(b)
            self.state = self._state_in_packet

    def _state_in_packet(self, b):
        if b:
            self.current_packet.append(b)
        else:
            self.packet_processor(self.current_packet)
            self.current_packet = bytearray()
            self.state = self._state_wait_begin
        
    def process_byte(self, b):
        self.state(b)


def cobs_recv():
    def process_packet(packet):
        # print(packet)
        print(cobs_decode(packet))

    with serial.Serial(SERIAL_DEV, 115200) as ser:
        d = PacketDecoder(process_packet)
        while True:
            b = ser.read()[0]
            #print(b)
            d.process_byte(b)

def send_packet(dev, packet):
    bs = [0]
    bs.extend(packet)
    bs.append(0)
    dev.write(bytes(bs))

def send_packets():
    with serial.Serial(SERIAL_DEV, 115200) as ser:
        no = 1
        for l in range(1,35):
            bs = []
            bs.append(no)
            for b in range(1, l):
                bs.append(b)
            send_packet(ser, bs)
            print(bs)
            time.sleep(0.005)
            no += 1
                
def main():
    try:
        send_packets()
    except KeyboardInterrupt:
        pass
