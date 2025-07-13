#pragma once
#ifndef kk_koka_main_H
#define kk_koka_main_H
// Koka generated module: koka/main, koka version: 3.1.2, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core_exn.h"
#include "std_core_bool.h"
#include "std_core_order.h"
#include "std_core_char.h"
#include "std_core_int.h"
#include "std_core_vector.h"
#include "std_core_string.h"
#include "std_core_sslice.h"
#include "std_core_list.h"
#include "std_core_maybe.h"
#include "std_core_either.h"
#include "std_core_tuple.h"
#include "std_core_show.h"
#include "std_core_debug.h"
#include "std_core_delayed.h"
#include "std_core_console.h"
#include "std_core.h"

// type declarations

// value declarations

static inline kk_unit_t kk_koka_main_main(kk_context_t* _ctx) { /* () -> console/console () */ 
  kk_string_t _x_x0;
  kk_define_string_literal(, _s_x1, 13, "Hello, World!", _ctx)
  _x_x0 = kk_string_dup(_s_x1, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x0, _ctx); return kk_Unit;
}

void kk_koka_main__init(kk_context_t* _ctx);


void kk_koka_main__done(kk_context_t* _ctx);

#endif // header
