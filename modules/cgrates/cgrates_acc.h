/*
 * Copyright (C) 2016 Razvan Crainea <razvan@opensips.org>
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 */

#ifndef _CGRATES_ACC_H_
#define _CGRATES_ACC_H_

/*
 * Starts a CGR accounting session
 * Input:
 *  - account
 *  - destination (optional)
 * Returns:
 *  -  1: user is allowed to call
 *  - -1: cgrates error
 *  - -2: internal error
 *  - -3: no suitable cgrates server found
 *  - -4: invalid message
 */
int w_cgr_acc(struct sip_msg* msg, char* acc_c, char *dst_c);

enum cgr_acc_state {
	CGRS_EARLY = 0,
	CGRS_ENGAGED
};

struct cgr_acc_ctx {

	enum cgr_acc_state state;

	/* all branches info */
	str acc;
	str dst;
	time_t time;
	unsigned int duration;

	/* variables */
	struct list_head *kv_store;
};


struct cgr_acc_ctx *cgr_tryget_acc_ctx(void);

#endif /* _CGRATES_ACC_H_ */
