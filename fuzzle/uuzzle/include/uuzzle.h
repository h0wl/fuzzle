/* Includes */
#include <puzzle.h>
#include <stdbool.h>
#include <unicorn.h>


#ifndef __UUZZLE_H__
#define __UUZZLE_H__

/* Definitions */
#define PERMS(__perms) \
        ((__perms & 0x1) << 2) \
        | (__perms & 0x2) \
        | ((__perms &0x4) >> 2)

/* Structures */
typedef struct uzl_options {
  bool verbose;
  bool follow_child;
  char *uzl_file_name;
} uzl_options_t;

/* Prototypes */
/* Core */
uint8_t uzl_uc_arch(pzl_ctx_t *context);
uint8_t uzl_uc_mode(pzl_ctx_t *context);
uint8_t uzl_cs_arch(pzl_ctx_t *context);
uint8_t uzl_cs_mode(pzl_ctx_t *context);
bool uzl_map_memory(pzl_ctx_t *context, uc_engine *uc);
bool uzl_set_registers(pzl_ctx_t *context, uc_engine *uc);
uint64_t uzl_get_pc(pzl_ctx_t *context);
bool uzl_reg_sys(pzl_ctx_t *context, uc_engine *uc, uc_hook *sys_hook,
                 uzl_options_t *opts);
bool uzl_parse_opts(uzl_options_t *opts, int argc, char **argv);

/* x86_64 */
bool uzl_set_x86_64_registers(pzl_ctx_t *context, uc_engine *uc);
bool uzl_set_x86_64_msr(pzl_ctx_t *context, uc_engine *uc,
                        user_regs_x86_64_t usr_reg);
uint64_t uzl_get_x86_64_pc(pzl_ctx_t *context);
bool uzl_reg_linux_x86_64_sys(pzl_ctx_t *context, uc_engine *uc,
                              uc_hook *sys_hook, uzl_options_t *opts);

#endif
