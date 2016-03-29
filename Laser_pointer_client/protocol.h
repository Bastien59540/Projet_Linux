/// \author Quentin Berdal
#ifndef PROTOCOL
#define PROTOCOL



enum Protocol : unsigned char ///< Describe specific char and rules used by the protocol
{
    START_HEADER=1,
    START_DATA=2,
    STOP_DATA=3,
    STOP_FRAME=4,
    NACK=21,
    ACK=6,
    MODE_AUTO=19,
    MODE_TRACKING=20,
    DATA_SEPARATOR=29,
    CUBE=40,
    ELLIPSE=41,
    TRIANGLE=42,
    POSITION_LOWER_LIMIT=0,
    POSITION_UPPER_LIMIT=180,
    TRANSMISSION_OFFSET=32
};

enum ErrorCode : unsigned char ///< Error code used with NACK
{
    NO_FRAME=0,
    UNTERMINATED_FRAME=1
};

/** Structure used by functions to read and write according to the protocol.
 *  You can interact with functions only through this structure.
 *  No verification is done on the struct, so be carefull when you assign data.
 *  Otherwise, you'll send corrupted packet and the board will answer NACK.
 */

typedef struct message
{
    Protocol mode;              ///< Describe the type of packet.
                                ///< Accept ACK, NACK, MODE_AUTO and MODE_TRACKING
    unsigned char *data;        ///< Pointer to an array of data
    unsigned int data_size=0;   ///< Number of data in the array
} Message;

/*/////////////////////////////////////////////////*/

#ifndef QT_CORE_LIB

// NON QT VERSION

unsigned char* ApplyProtocol(Message *msg);                 ///< Write a transmitable array
Message* ReadFrame(unsigned char *frame, unsigned int size);///< Read a frame

#else

// QT VERSION

#include <QtCore>

QByteArray* ApplyProtocol(Message *msg);  ///< \fn Write a transmitable array
Message* ReadFrame(QByteArray *frame);    ///< \fn Read a frame

#endif


#endif // PROTOCOL
