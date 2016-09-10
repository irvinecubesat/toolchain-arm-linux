#ifndef UTIL_H
#define UTIL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#ifdef __cplusplus
extern "C" {
#endif

/// Returns the serial numner for the board, or 0 if running on the
//  dev board
extern unsigned long UTIL_board_sn(void);

#define BOARD_TYPE_UNKNOWN 0x1234
#define BOARD_TYPE_INTREPID 0x7315
#define BOARD_TYPE_DEV 0xDEAD

/// Returns an enumerated type indicating which type of board this is
extern int UTIL_board_type(void);

typedef struct timeval (*cleanup_mod_time_cb_t)(const struct dirent *dirent,
   const char *full_path, struct stat *statbuff, void *arg);

typedef void (*post_delete_cb_t)(const char *file_path, void *arg);

/** Deletes old files from a directory as part of normal housekeeping

**/
int UTIL_cleanup_dir(const char *dirname, int max_entries, int ignore_hidden,
    cleanup_mod_time_cb_t modtime_cb, void *cb_arg, post_delete_cb_t del_cb,
    void *del_cb_arg);

/** Verifies that dir exists and is a directory **/
extern int UTIL_ensure_dir(const char *dir);

/** Verifies that dir exists and is a directory.  If it doesn't exist
    it will attempt to create it.  Returns true if successful,
    false otherwise
 **/
extern int UTIL_ensure_path(const char *dir);


#ifdef __cplusplus
}
#endif

#endif
