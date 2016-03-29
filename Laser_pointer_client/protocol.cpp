#include "protocol.h"

/// Both native and Qt implementation

#ifndef QT_CORE_LIB

// NON QT VERSION

unsigned char* ApplyProtocol(Message *msg)  ///< Write a transmitable array
{
    unsigned char frame[msg->data_size+5];

    frame[0]=Protocol::START_HEADER;                        // start of header
    frame[1]=msg->mode;                                     // write mode
    frame[2]=Protocol::START_DATA;                          // start of data

    for(int i=0 ; i<msg->data_size ; i++)
        frame[i+3]=msg->data[i]+Protocol::TRANSMISSION_OFFSET;///< Apply transmission offset on data

    frame[msg->data_size+3]=Protocol::STOP_DATA;            // end of data
    frame[msg->data_size+4]=Protocol::STOP_FRAME;           // end of transmission

    return frame;
}

Message* ReadFrame(unsigned char *frame, unsigned int size)
{
    unsigned int i=0;
    Message data;

    while(frame[i] != Protocol::START_HEADER)///< Search for a "start of header" char
    {
        i++;
        if(i == size)///< If no header
        {
            unsigned char cc[1]={ErrorCode::NO_FRAME};
            data.mode=Protocol::NACK;
            data.data=cc;
            data.data_size=1;
            return &data;
        }
    }

    i++;
    data.mode=(Protocol)frame[i];
    i++;

    if(data.mode != Protocol::NACK && data.mode != Protocol::ACK && frame[i] == Protocol::START_DATA)///< If receiving standard data
    {
        unsigned char reading[33];
        i++;

        while(frame[i] != Protocol::STOP_DATA || frame[1+i] != Protocol::STOP_FRAME)///< Read all data
        {
            reading[data.data_size]=frame[i]-Protocol::TRANSMISSION_OFFSET;
            data.data_size++;
            i++;
            if(i == size-1 || data.data_size == 33)///< If reach end without encountering STOP_DATA and STOP_TRANSMISSION
            {
                unsigned char cc[1]={ErrorCode::UNTERMINATED_FRAME};
                data.mode=Protocol::NACK;
                data.data=cc;
                data.data_size=1;
                return &data;
            }
        }

        data.data=reading; // link data
        return &data;
    }
    else
    {
        if(frame[i] != Protocol::START_DATA)///< If no data block
        {
            unsigned char cc[1]={ErrorCode::UNTERMINATED_FRAME};
            data.data=cc;
            data.mode=Protocol::NACK;
        }
        else ///< If receiving a NACK or ACK
        {
            data.data=&frame[i];
        }
        data.data_size=1;
        return &data;
    }
}

#else

// QT VERSION

QByteArray* ApplyProtocol(Message *msg)  ///< Write a transmitable array
{
    QByteArray frame;

    frame.push_back(Protocol::START_HEADER);                        // start of header
    frame.push_back(msg->mode);                                     // write mode
    frame.push_back(Protocol::START_DATA);                          // start of data

    for(unsigned int i=0 ; i<msg->data_size ; i++)
        frame.push_back(msg->data[i]+Protocol::TRANSMISSION_OFFSET);///< Apply transmission offset on data

    frame.push_back(Protocol::STOP_DATA);                           // end of data
    frame.push_back(Protocol::STOP_FRAME);                          // end of transmission

    return &frame;
}

Message* ReadFrame(QByteArray *frame)
{
    unsigned int i=0;
    Message data;

    while(frame->at(i) != Protocol::START_HEADER)///< Search for a "start of header" char
    {
        i++;
        if(i == frame->size())///< If no header
        {
            unsigned char cc[1]={(unsigned char)ErrorCode::NO_FRAME};
            data.mode=Protocol::NACK;
            data.data=cc;
            data.data_size=1;
            return &data;
        }
    }

    i++;
    data.mode=(Protocol)frame->at(i);
    i++;

    if(data.mode != Protocol::NACK && data.mode != Protocol::ACK && frame->at(i) == Protocol::START_DATA)///< If receiving standard data
    {
        unsigned char reading[33];
        i++;

        while(frame->at(i) != Protocol::STOP_DATA || frame->at(i+1) != Protocol::STOP_FRAME)///< Read all data
        {
            reading[data.data_size]=frame->at(i)-Protocol::TRANSMISSION_OFFSET;
            data.data_size++;
            i++;

            if(i == frame->size()-1 || data.data_size == 33)///< If reach end without encountering STOP_DATA and STOP_TRANSMISSION
            {
                unsigned char cc[1]={(unsigned char)ErrorCode::UNTERMINATED_FRAME};
                data.mode=Protocol::NACK;
                data.data=cc;
                data.data_size=1;
                return &data;
            }
        }

        data.data=reading; // link data
        return &data;
    }
    else
    {
        unsigned char cc[1];

        if(frame->at(i) != Protocol::START_DATA)///< If no data block
        {
            cc[0]=ErrorCode::UNTERMINATED_FRAME;
            data.data=cc;
            data.mode=Protocol::NACK;
        }
        else ///< If receiving a NACK or ACK
        {
            cc[0]=frame->at(i);
            data.data=cc;
        }
        data.data_size=1;
        return &data;
    }
}

#endif
