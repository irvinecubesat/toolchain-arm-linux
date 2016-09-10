/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/**
 * @file rohc_decomp.h
 * @brief ROHC decompression routines
 * @author Didier Barvaux <didier.barvaux@toulouse.viveris.com>
 * @author The hackers from ROHC for Linux
 * @author David Moreau from TAS
 */

#ifndef DECOMP_H
#define DECOMP_H

#include "rohc.h"
#include "rohc_comp.h"

/// The number of ROHC profiles ready to be used
#define D_NUM_PROFILES 6


/// ROHC decompressor states (see 4.3.2 in the RFC 3095)
typedef enum
{
	/// The No Context state
	NO_CONTEXT = 1,
	/// The Static Context state
	STATIC_CONTEXT = 2,
	/// The Full Context state
	FULL_CONTEXT = 3,
} rohc_d_state;


/**
 * @brief Some compressor statistics.
 */
struct d_statistics
{
	/// The number of received packets
	unsigned int received;
	/// The number of bad decompressions due to wrong CRC
	unsigned int failed_crc;
	/// The number of bad decompressions due to being in the No Context state
	unsigned int failed_no_context;
	/// The number of bad decompressions
	unsigned int failed_decomp;
	/// The number of feedback packets sent to the associated compressor
	unsigned int feedbacks;
};


/**
 * @brief The ROHC decompressor.
 */
struct rohc_decomp
{
	/// The compressor associated with the decompressor
	struct rohc_comp *compressor;

	/// The medium associated with the decompressor
	struct medium medium;

	/// The array of decompression contexts that use the decompressor
	struct d_context **contexts;
	/// The last decompression context used by the decompressor
	struct d_context *last_context;

	/**
	 * @brief The feedback interval limits
	 *
	 * maxval can be updated by the user thanks to the user_interactions
	 * function.
	 *
	 * @see user_interactions
	 */
	unsigned int maxval;
	/// Variable related to the feedback interval
	unsigned int errval;
	/// Variable related to the feedback interval
	unsigned int okval;
	/// Variable related to the feedback interval
	int curval;


	/* CRC-related variables: */

	/** The table to enable fast CRC-2 computation */
	unsigned char crc_table_2[256];
	/** The table to enable fast CRC-3 computation */
	unsigned char crc_table_3[256];
	/** The table to enable fast CRC-6 computation */
	unsigned char crc_table_6[256];
	/** The table to enable fast CRC-7 computation */
	unsigned char crc_table_7[256];
	/** The table to enable fast CRC-8 computation */
	unsigned char crc_table_8[256];


	/// Some statistics about the decompression processes
	struct d_statistics stats;
};


/**
 * @brief The ROHC decompression context.
 */
struct d_context
{
	/// The associated profile
	struct d_profile *profile;
	/// Profile-specific data, defined by the profiles
	void *specific;

	/// The operation mode in which the context operates: U_MODE, O_MODE, R_MODE
	rohc_mode mode;
	/// @brief The operation state in which the context operates: NO_CONTEXT,
	///        STATIC_CONTEXT, FULL_CONTEXT
	rohc_d_state state;

	/// Usage timestamp
	unsigned int latest_used;
	/// Usage timestamp
	unsigned int first_used;

	/// Variable related to feedback interval
	int curval;

	/* below are some statistics */

	/// The average size of the uncompressed packets
	int total_uncompressed_size;
	/// The average size of the compressed packets
	int total_compressed_size;
	/// The average size of the uncompressed headers
	int header_uncompressed_size;
	/// The average size of the compressed headers
	int header_compressed_size;

	/// The number of received packets
	int num_recv_packets;
	/// The number of received IR packets
	int num_recv_ir;
	/// The number of received IR-DYN packets
	int num_recv_ir_dyn;
	/// The number of sent feedbacks
	int num_sent_feedbacks;

	/// The number of compression failures
	int num_decomp_failures;
	/// The number of decompression failures
	int num_decomp_repairs;

	/// The size of the last 16 uncompressed packets
	struct c_wlsb *total_16_uncompressed;
	/// The size of the last 16 compressed packets
	struct c_wlsb *total_16_compressed;
	/// The size of the last 16 uncompressed headers
	struct c_wlsb *header_16_uncompressed;
	/// The size of the last 16 compressed headers
	struct c_wlsb *header_16_compressed;
};


/**
 * @brief The ROHC decompression profile.
 *
 * The object defines a ROHC profile. Each field must be filled in
 * for each new profile.
 */
struct d_profile
{
	/// The profile ID as reserved by IANA
	int id;

	/// A string that describes the profile
	char *description;

	/// The handler used to decode one IR, IR-DYN and UO* packets
	int (*decode)(struct rohc_decomp *decomp,
	              struct d_context *context,
	              const unsigned char *const rohc_packet,
	              const unsigned int rohc_length,
	              const size_t add_cid_len,
	              const size_t large_cid_len,
	              unsigned char *dest);

	/// @brief The handler used to create the profile-specific part of the
	///        decompression context
	void * (*allocate_decode_data)(void);

	/// @brief The handler used to destroy the profile-specific part of the
	///        decompression context
	void (*free_decode_data)(void *);

	/// The handler used to retrieve the Sequence Number (SN)
	int (*get_sn)(struct d_context *context);
};


/*
 * Functions related to decompressor:
 */

struct rohc_decomp * rohc_alloc_decompressor(struct rohc_comp *compressor);
void rohc_free_decompressor(struct rohc_decomp *decomp);

int rohc_decompress(struct rohc_decomp *decomp, unsigned char *ibuf, int isize,
                    unsigned char *obuf, int osize);
int rohc_decompress_both(struct rohc_decomp *decomp, unsigned char *ibuf,
                         int isize, unsigned char *obuf, int osize, int large)
	ROHC_DEPRECATED("please do not use this function anymore, use "
	                "rohc_decomp_set_cid_type() and rohc_decomp_set_max_cid() "
	                "instead");


/*
 * Functions related to context:
 */

struct d_context * find_context(struct rohc_decomp *decomp, int cid);
struct d_context * context_create(struct rohc_decomp *decomp,
                                  int with_cid,
                                  struct d_profile *profile);
void context_free(struct d_context *context);


/*
 * Functions related to feedback:
 */

void d_change_mode_feedback(struct rohc_decomp *decomp, struct d_context *context);


/*
 * Functions related to statistics:
 */

int rohc_d_statistics(struct rohc_decomp *decomp, unsigned int indent,
                      char *buffer);
int rohc_d_context(struct rohc_decomp *decomp, int index, unsigned int indent,
                   char *buffer);
void clear_statistics(struct rohc_decomp *decomp);
const char * rohc_decomp_get_state_descr(const rohc_d_state state);


/*
 * Functions related to user interaction:
 */

void user_interactions(struct rohc_decomp *decomp, int feedback_maxval);

bool rohc_decomp_set_cid_type(struct rohc_decomp *const decomp,
                              const rohc_cid_type_t cid_type)
	__attribute__((nonnull(1), warn_unused_result));


bool rohc_decomp_set_max_cid(struct rohc_decomp *const decomp,
                             const size_t max_cid)
	__attribute__((nonnull(1), warn_unused_result));

#endif

