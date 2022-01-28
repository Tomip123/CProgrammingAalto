#include "header.h"

/*
 * You are required to implement the parser functions below.
 *
 * int validateHeader(uint32_t header); function validates the header. A header is valid if all the conditions below evaluate true.
 *  - SYNC field is equal to 0x2a
 *  - if ACK bit is set V bit is also
 *  - if ACK bit is reset TYPE is non-zero.
 *  - SOURCE ADDRESS and DESTINATION ADDRESS are non-zero and different than each other.
 *
 *  If the header is valid, the function returns 1 otherwise it returns 0.
 *
 * int getFrameId(uint32_t header); function returns FRAME ID field if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to FRAME ID field.
 *
 * int getFrameType(uint32_t header); function returns TYPE field if the header is valid, possibly checked using validateHeader function above, and ACK bit is reset.
 *  - If the header is not valid, it returns -1.
 *  - If ACK bit is set, it returns 0.
 *  - Otherwise, it returns non-negative integer corresponding to TYPE field.
 *
 * int getSourceAddress(uint32_t header); function returns SOURCE ADDRESS field if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to SOURCE ADDRESS field.
 */



int validateHeader(uint32_t header)
{
    if (header == 0x2a)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int getFrameId(uint32_t header)
{
    if (validateHeader(header) == 1)
    {
        return (header & 0x0000FFFF);
    }
    else
    {
        return -1;
    }
}
int getFrameType(uint32_t header)
{
    if (validateHeader(header) == 1 && (header & 0x10000000) == 0)
    {
        return (header & 0x000000FF);
    }
    else
    {
        return -1;
    }
}
int getSourceAddress(uint32_t header)
{
    if (validateHeader(header) == 1)
    {
        return (header & 0x00FF0000) >> 16;
    }
    else
    {
        return -1;
    }
}

uint32_t createAckHeader(int destAddress, int sourceAddress, uint8_t frameId, char valid)
{
    uint32_t header = 0x2a;
    header = header | (destAddress << 16);
    header = header | (sourceAddress << 8);
    header = header | (frameId << 24);
    if (valid == 1)
    {
        header = header | 0x80000000;
    }
    return header;
}

uint32_t createHeader(int destAddress, int sourceAddress, uint8_t frameId, uint8_t type)
{
    uint32_t header = 0x2a;
    header = header | (destAddress << 16);
    header = header | (sourceAddress << 8);
    header = header | (frameId << 24);
    header = header | (type << 16);
    return header;
}
