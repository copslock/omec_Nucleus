/*
 * Copyright (c) 2020, Infosys Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 /******************************************************************************
 *
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/GtpV2StackCodeGen/tts/ietemplate.h.tt>
 ******************************************************************************/
#ifndef UETIMEZONEIE_H_
#define UETIMEZONEIE_H_

#include "manual/gtpV2Ie.h"



class UeTimeZoneIe: public GtpV2Ie {
public:
    UeTimeZoneIe();
    virtual ~UeTimeZoneIe();

    bool encodeUeTimeZoneIe(MsgBuffer &buffer,
                 UeTimeZoneIeData const &data);
    bool decodeUeTimeZoneIe(MsgBuffer &buffer,
                 UeTimeZoneIeData &data, Uint16 length);
    void displayUeTimeZoneIe_v(UeTimeZoneIeData const &data,
                 Debug &stream);
};

#endif /* UETIMEZONEIE_H_ */
