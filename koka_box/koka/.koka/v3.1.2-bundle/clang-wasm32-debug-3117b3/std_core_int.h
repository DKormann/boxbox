#pragma once
#ifndef kk_std_core_int_H
#define kk_std_core_int_H
// Koka generated module: std/core/int, koka version: 3.1.2, platform: 32-bit
#include <kklib.h>
#include "std_core_types.h"

// type declarations

// value declarations

kk_std_core_types__order kk_std_core_int_order(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> order */ 
 
// Compare two integers

static inline kk_std_core_types__order kk_std_core_int_cmp(kk_integer_t x, kk_integer_t y, kk_context_t* _ctx) { /* (x : int, y : int) -> order */ 
  bool _match_x44 = kk_integer_eq_borrow(x,y,kk_context()); /*bool*/;
  if (_match_x44) {
    return kk_std_core_types__new_Eq(_ctx);
  }
  {
    bool _match_x45 = kk_integer_gt_borrow(x,y,kk_context()); /*bool*/;
    if (_match_x45) {
      return kk_std_core_types__new_Gt(_ctx);
    }
    {
      return kk_std_core_types__new_Lt(_ctx);
    }
  }
}
 
// Order two integers in ascending order.

static inline kk_std_core_types__order2 kk_std_core_int_order2(kk_integer_t x, kk_integer_t y, kk_context_t* _ctx) { /* (x : int, y : int) -> order2<int> */ 
  bool _match_x42 = kk_integer_eq_borrow(x,y,kk_context()); /*bool*/;
  if (_match_x42) {
    kk_integer_drop(y, _ctx);
    return kk_std_core_types__new_Eq2(kk_integer_box(x, _ctx), _ctx);
  }
  {
    bool _match_x43 = kk_integer_lt_borrow(x,y,kk_context()); /*bool*/;
    if (_match_x43) {
      return kk_std_core_types__new_Lt2(kk_integer_box(x, _ctx), kk_integer_box(y, _ctx), _ctx);
    }
    {
      return kk_std_core_types__new_Gt2(kk_integer_box(y, _ctx), kk_integer_box(x, _ctx), _ctx);
    }
  }
}
 
// Add two integers.

static inline kk_integer_t kk_std_core_int__lp__plus__rp_(kk_integer_t x, kk_integer_t y, kk_context_t* _ctx) { /* (x : int, y : int) -> int */ 
  return kk_integer_add(x,y,kk_context());
}
 
// Substract two integers.

static inline kk_integer_t kk_std_core_int__lp__dash__rp_(kk_integer_t x, kk_integer_t y, kk_context_t* _ctx) { /* (x : int, y : int) -> int */ 
  return kk_integer_sub(x,y,kk_context());
}

kk_std_core_types__tuple2 kk_std_core_int_divmod(kk_integer_t x, kk_integer_t y, kk_context_t* _ctx); /* (x : int, y : int) -> (int, int) */ 

static inline kk_integer_t kk_std_core_int_negate(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> int */ 
  return kk_integer_neg(i,kk_context());
}
 
// Increment

static inline kk_integer_t kk_std_core_int_inc(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> int */ 
  return kk_integer_add_small_const(i, 1, _ctx);
}
 
// Decrement

static inline kk_integer_t kk_std_core_int_dec(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> int */ 
  return kk_integer_add_small_const(i, -1, _ctx);
}

kk_integer_t kk_std_core_int_pow(kk_integer_t i, kk_integer_t exp, kk_context_t* _ctx); /* (i : int, exp : int) -> int */ 
 
// Raise an integer `i` to the power of `exp`.

static inline kk_integer_t kk_std_core_int__lp__hat__rp_(kk_integer_t i, kk_integer_t exp, kk_context_t* _ctx) { /* (i : int, exp : int) -> int */ 
  return kk_std_core_int_pow(i, exp, _ctx);
}

kk_integer_t kk_std_core_int_count_digits(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> int */ 

kk_integer_t kk_std_core_int_mul_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx); /* (i : int, n : int) -> int */ 
 
// Calculate ``10^exp``

static inline kk_integer_t kk_std_core_int_exp10(kk_integer_t exp, kk_context_t* _ctx) { /* (exp : int) -> int */ 
  return kk_std_core_int_mul_exp10(kk_integer_from_small(1), exp, _ctx);
}
 
// Calculate ``2^exp``.

static inline kk_integer_t kk_std_core_int_exp2(kk_integer_t exp, kk_context_t* _ctx) { /* (exp : int) -> int */ 
  return kk_std_core_int_pow(kk_integer_from_small(2), exp, _ctx);
}

kk_integer_t kk_std_core_int_is_exp10(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> int */ 

kk_integer_t kk_std_core_int_cdiv_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx); /* (i : int, n : int) -> int */ 

kk_std_core_types__tuple2 kk_std_core_int_cdivmod_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx); /* (i : int, n : int) -> (int, int) */ 
 
// Is the integer negative (strictly smaller than zero)

static inline bool kk_std_core_int_is_neg(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> bool */ 
  bool _brw_x40 = kk_integer_lt_borrow(i,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(i, _ctx);
  return _brw_x40;
}

kk_std_core_types__tuple2 kk_std_core_int_divmod_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx); /* (i : int, n : int) -> (int, int) */ 
 
// Is this an even integer?

static inline bool kk_std_core_int_is_even(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> bool */ 
  bool b_10014 = kk_integer_is_odd(i,kk_context()); /*bool*/;
  if (b_10014) {
    return false;
  }
  {
    return true;
  }
}
 
// Is the integer positive (strictly greater than zero)

static inline bool kk_std_core_int_is_pos(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> bool */ 
  bool _brw_x38 = kk_integer_gt_borrow(i,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(i, _ctx);
  return _brw_x38;
}
 
// Compare an integer `i` with zero

static inline kk_std_core_types__order kk_std_core_int_sign(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> order */ 
  bool _match_x36 = kk_integer_eq_borrow(i,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x36) {
    return kk_std_core_types__new_Eq(_ctx);
  }
  {
    bool _match_x37 = kk_integer_gt_borrow(i,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x37) {
      return kk_std_core_types__new_Gt(_ctx);
    }
    {
      return kk_std_core_types__new_Lt(_ctx);
    }
  }
}
 
// Return the minimum of two integers

static inline kk_integer_t kk_std_core_int_min(kk_integer_t i, kk_integer_t j, kk_context_t* _ctx) { /* (i : int, j : int) -> int */ 
  bool _match_x35 = kk_integer_lte_borrow(i,j,kk_context()); /*bool*/;
  if (_match_x35) {
    kk_integer_drop(j, _ctx);
    return i;
  }
  {
    kk_integer_drop(i, _ctx);
    return j;
  }
}
 
// Return the maximum of two integers

static inline kk_integer_t kk_std_core_int_max(kk_integer_t i, kk_integer_t j, kk_context_t* _ctx) { /* (i : int, j : int) -> int */ 
  bool _match_x34 = kk_integer_gte_borrow(i,j,kk_context()); /*bool*/;
  if (_match_x34) {
    kk_integer_drop(j, _ctx);
    return i;
  }
  {
    kk_integer_drop(i, _ctx);
    return j;
  }
}
 
// Transform an integer to a maybe type, using `Nothing` for `0`

static inline kk_std_core_types__maybe kk_std_core_int_maybe(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> maybe<int> */ 
  bool _match_x33 = kk_integer_eq_borrow(i,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x33) {
    kk_integer_drop(i, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    return kk_std_core_types__new_Just(kk_integer_box(i, _ctx), _ctx);
  }
}

kk_string_t kk_std_core_int_show(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> string */ 
 
// Convert an int to a boolean, using `False` for 0 and `True` otherwise.

static inline bool kk_std_core_int_bool(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> bool */ 
  bool _brw_x32 = kk_integer_neq_borrow(i,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(i, _ctx);
  return _brw_x32;
}
 
// Convert a `:maybe<int>` to an `:int` using zero for `Nothing`

static inline kk_integer_t kk_std_core_int_mbint(kk_std_core_types__maybe m, kk_context_t* _ctx) { /* (m : maybe<int>) -> int */ 
  if (kk_std_core_types__is_Nothing(m, _ctx)) {
    return kk_integer_from_small(0);
  }
  {
    kk_box_t _box_x30 = m._cons.Just.value;
    kk_integer_t i = kk_integer_unbox(_box_x30, _ctx);
    kk_integer_dup(i, _ctx);
    kk_std_core_types__maybe_drop(m, _ctx);
    return i;
  }
}

kk_std_core_types__maybe kk_std_core_int_xparse(kk_string_t s, bool hex, kk_context_t* _ctx); /* (s : string, hex : bool) -> maybe<int> */ 
 
// Parse an integer.
// If an illegal digit character is encountered `Nothing` is returned.
// An empty string, or a string starting with white space will result in `Nothing`
// A string can start with a `-` sign for negative numbers,
// and with `0x` or `0X` for hexadecimal numbers (in which case the `hex` parameter is ignored).

static inline kk_std_core_types__maybe kk_std_core_int_parse_int(kk_string_t s, kk_std_core_types__optional hex, kk_context_t* _ctx) { /* (s : string, hex : ? bool) -> maybe<int> */ 
  bool _x_x53;
  if (kk_std_core_types__is_Optional(hex, _ctx)) {
    kk_box_t _box_x31 = hex._cons._Optional.value;
    bool _uniq_hex_528 = kk_bool_unbox(_box_x31);
    kk_std_core_types__optional_drop(hex, _ctx);
    _x_x53 = _uniq_hex_528; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(hex, _ctx);
    _x_x53 = false; /*bool*/
  }
  return kk_std_core_int_xparse(s, _x_x53, _ctx);
}

int8_t kk_std_core_int_int8(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> int8 */ 

int8_t kk_std_core_int_uint8(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> int8 */ 

int16_t kk_std_core_int_int16(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> int16 */ 

intptr_t kk_std_core_int_intptr__t(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> intptr_t */ 

kk_ssize_t kk_std_core_int_ssize__t(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> ssize_t */ 

void kk_std_core_int__init(kk_context_t* _ctx);


void kk_std_core_int__done(kk_context_t* _ctx);

#endif // header
