/*
 * Copyright 2019-present Open Networking Foundation
 * Copyright (c) 2003-2018, Great Software Laboratory Pvt. Ltd.
 * Copyright (c) 2017 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __S11_STRUCTS_H_
#define __S11_STRUCTS_H_

#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#define S11_MSGBUF_SIZE 2048

#pragma pack(1)
typedef struct gtpv2c_header {
	struct gtpc{
		unsigned char spare :3;
		unsigned char teidFlg :1;
		unsigned char piggyback :1;
		unsigned char version :3;
		unsigned char message_type;
		unsigned short len;
	}gtp;
	union teid {
		struct has_teid_t {
			unsigned int teid;
			unsigned int seq :24;
			unsigned int spare :8;
		} has_teid;
		struct no_teid_t {
			unsigned int seq :24;
			unsigned int spare :8;
		} no_teid;
	} teid;
} gtpv2c_header;

typedef struct fteid {
        struct fteid_header {
                unsigned char iface_type :6;
                unsigned char v6 :1;
                unsigned char v4 :1;
                unsigned int teid_gre;
        } header;
        union ftied_ip {
                struct in_addr ipv4;
                struct in6_addr ipv6;
                struct ipv4v6_t {
                        struct in_addr ipv4;
                        struct in6_addr ipv6;
                } ipv4v6;
        } ip;
} fteid_t;

struct PAA {
	uint8_t pdn_type;
        union ip_type {
                struct in_addr ipv4;
                struct ipv6_t {
                        uint8_t prefix_length;
                        struct in6_addr ipv6;
                } ipv6;
                struct paa_ipv4v6_t {
                        uint8_t prefix_length;
                        struct in6_addr ipv6;
                        struct in_addr ipv4;
                } paa_ipv4v6;
        } ip_type;
};

struct gtp_cause {
	unsigned char cause;
	unsigned char data;
};

struct bearer_ctx {
	unsigned char eps_bearer_id;
	struct gtp_cause cause;
	struct fteid s1u_sgw_teid;
	struct fteid s5s8_pgw_u_teid;
};

struct ARP {
        uint8_t prioLevel :4;
        uint8_t preEmptionCapab :1;
        uint8_t preEmptionVulnebility :1;
        uint8_t spare :2;
};


struct s11_IE_header {
	unsigned char ie_type;
	unsigned short ie_len;
	unsigned char cr_flag:4;
	unsigned char instance:4;
};

union s11_IE_data {
	struct gtp_cause cause;
	struct fteid s11_sgw_fteid;
	struct fteid s5s8_pgw_c_fteid;
	struct PAA pdn_addr;
	struct bearer_ctx bearer;
	unsigned char eps_bearer_id;
	struct ARP arp;
};

struct s11_IE {
	struct s11_IE_header header;
	union s11_IE_data data;
};

struct s11_proto_IE {
	unsigned short message_type;
	unsigned short no_of_ies;
	struct s11_IE *s11_ies;
};

#pragma pack()

#endif /* S11_STRUCTS_H */
