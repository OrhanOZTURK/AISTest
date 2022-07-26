/* -----------------------------------------------------------------------
   6-bit packed ASCII functions
   Copyright 2006-2008 by Brian C. Lane <bcl@brianlane.com
   All Rights Reserved
   ----------------------------------------------------------------------- */

/*! \file
    \brief Header file for sixbit.c
    \author Brian C. Lane <bcl@brianlane.com>

*/

#ifndef SIXBIT_H
#define SIXBIT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "portable.h"

#define SIXBIT_LEN   255

/** sixbit state

    The size of bits is enough to handle a little over 5 slots of data
    ((5 * 256) / 6) = 214
*/
typedef struct {
    char bits[SIXBIT_LEN];          //!< raw 6-bit ASCII data string
    char *p;                        //!< pointer to current character in bits
    unsigned char remainder;        //!< Remainder bits
    unsigned char remainder_bits;   //!< Number of remainder bits
} sixbit;

/* Prototypes -- need to document these */
char __stdcall binfrom6bit( char ascii );
int __stdcall init_6bit( sixbit *state );
unsigned long __stdcall get_6bit( sixbit *state, short numbits );
unsigned int __stdcall sixbit_length( sixbit *state );
char __stdcall binto6bit( char value );


#ifdef __cplusplus
 }
#endif

#endif
