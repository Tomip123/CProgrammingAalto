#include "header.h"
#include <stdio.h>
#include "header.c"

int main()
{
    /* Feel free to modify this function to test different things */

    uint32_t ackHeader = createAckHeader(12, 3, 4, 1);
    uint32_t nackHeader = createAckHeader(12, 3, 5, 0);
    uint32_t frameHeader = createHeader(15, 22, 8, 2);

    printf("Ack Header: valid %d, source %d frame id %d type %d \n", validateHeader(ackHeader), getSourceAddress(ackHeader), getFrameId(ackHeader), getFrameType(ackHeader));
    printf("Nack Header: valid %d, source %d frame id %d type %d \n", validateHeader(nackHeader), getSourceAddress(nackHeader), getFrameId(nackHeader), getFrameType(nackHeader));
    printf("Frame Header: valid %d, source %d frame id %d type %d \n", validateHeader(frameHeader), getSourceAddress(frameHeader), getFrameId(frameHeader), getFrameType(frameHeader));

    // test createAckHeader
    printf("Ack Header: %x\n", ackHeader);

    // test createHeader
    printf("Frame Header: %x\n", frameHeader);

    // test frameId
    printf("Frame ID: %d\n", getFrameId(420084970));

    // test frameType
    printf("Frame Type: %d\n", getFrameType(420084970));

    // test sourceAddress
    printf("Source Address: %d\n", getSourceAddress(420084970));

    // validateHeader
    printf("Valid Header: %d\n", validateHeader(2072030250));

    return 0;
}
