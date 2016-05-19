/***********************************************************************************************************************
* Copyright (C) 2015        CSEM S.A.            CH-2002 Neuchatel
* ALL RIGHTS RESERVED
************************************************************************************************************************
* Any copy of this software must include both the above copyright notice of CSEM SA and this paragraph.
* This software is made available AS IS, and CSEM SA AND THE AUTHORS DISCLAIM ALL WARRANTIES, EXPRESS OR IMPLIED,
* INCLUDING WITHOUT LIMITATION THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, AND
* NOTWITHSTANDING ANY OTHER PROVISION CONTAINED HEREIN, ANY LIABILITY FOR DAMAGES RESULTING FROM THE SOFTWARE OR ITS
* USE IS EXPRESSLY DISCLAIMED, WHETHER ARISING IN CONTRACT, TORT (INCLUDING NEGLIGENCE) OR STRICT LIABILITY, EVEN IF
* CSEM SA OR THE AUTHORS ARE ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
***********************************************************************************************************************/

#ifndef _BATTERYVOLTAGEFILTER_H_
#define _BATTERYVOLTAGEFILTER_H_

/**********************************************************************************************************************/
/**
 *  \file   batteryvoltagefilter.h
 *  \brief  Battery voltage filter function.
 * *
 *  \author  Jean-Marc Koller
 *  \date    2.09.2015
 *  \version 1.0    First version (JMK)
 */
/**********************************************************************************************************************/

#include <stdint.h>

#define BATTERYVOLTAGEFILTER_LENGTH (16U+2U)

typedef struct
{
    uint16_t values[BATTERYVOLTAGEFILTER_LENGTH];
    uint32_t sum;
    uint8_t wrIndex;
    unsigned int isFilled:1;
} batteryvoltagefilter_ts;

extern  void batteryvoltagefilter_init( batteryvoltagefilter_ts* pbvf );
extern  void batteryvoltagefilter_append( batteryvoltagefilter_ts* pbvf, uint16_t value );
extern  uint16_t batteryvoltagefilter_get( const batteryvoltagefilter_ts* pbvf );
extern  uint16_t batteryvoltagefilter_getAverage( const batteryvoltagefilter_ts* pbvf );
extern  int batteryvoltagefilter_isFillCycleCompleted( const batteryvoltagefilter_ts* pbvf );

#endif  /*!_BATTERYVOLTAGEFILTER_H_*/
