/*
 *  stream.h - Base class for character-based streams.
 *
 *  Copyright (c) 2014 Stefan Taferner <stefan.taferner@gmx.at>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 3 as
 *  published by the Free Software Foundation.
 */
#ifndef sblib_stream_h
#define sblib_stream_h

#include <sblib/print.h>

/**
 * Base class for character-based streams.
 */
class Stream: public Print
{
public:
    /**
     * Read a single byte.
     *
     * @return the read byte (0..255) or -1 if no byte was received.
     */
    virtual int read() = 0;

    /**
     * Query the next byte to be read, without reading it.
     *
     * @return the next byte (0..255) or -1 if no byte is available
     *         for reading.
     */
//    virtual int peek() = 0;

    /**
     * @return The number of bytes that are available for reading.
     */
    virtual int available() = 0;

    /**
     * Wait until all bytes are written.
     */
    virtual void flush() = 0;

protected:
    /**
     * Create a stream with the default timeout of 1 second.
     */
    Stream();

    /**
     * Read the next byte. Wait up to the number of milliseconds that are configured
     * as timeout.
     *
     * @return The read byte (0..255) or -1 if no byte was read.
     */
    int timedRead();

//    int timedPeek(); // private method to peek stream with timeout
//    int peekNextDigit(); // returns the next numeric digit in the stream or -1 if timeout

    unsigned int timeout; // timeout for timed reads in milliseconds
};


//
//  Inline functions
//

inline Stream::Stream()
{
    timeout = 1000;
}


#endif /*sblib_print_h*/