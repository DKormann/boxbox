#pragma once
#ifndef kk_std_core_sslice_H
#define kk_std_core_sslice_H
// Koka generated module: std/core/sslice, koka version: 3.1.2, platform: 32-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_undiv.h"
#include "std_core_unsafe.h"
#include "std_core_hnd.h"
#include "std_core_int.h"
#include "std_core_string.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2024, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

struct kk_std_core_sslice_Sslice;

kk_integer_t kk_slice_count( struct kk_std_core_sslice_Sslice sslice, kk_context_t* ctx );
kk_string_t  kk_slice_to_string( struct kk_std_core_sslice_Sslice sslice, kk_context_t* ctx );
struct kk_std_core_sslice_Sslice kk_slice_first( kk_string_t str, kk_context_t* ctx );
struct kk_std_core_sslice_Sslice kk_slice_last( kk_string_t str, kk_context_t* ctx );

struct kk_std_core_sslice_Sslice kk_slice_common_prefix_borrow( kk_string_t str1, kk_string_t str2, kk_integer_t upto, kk_context_t* ctx );
struct kk_std_core_sslice_Sslice kk_slice_advance_borrow( struct kk_std_core_sslice_Sslice slice, kk_integer_t count, kk_context_t* ctx );
struct kk_std_core_sslice_Sslice kk_slice_extend_borrow( struct kk_std_core_sslice_Sslice slice, kk_integer_t count, kk_context_t* ctx );
kk_std_core_types__maybe kk_slice_next( struct kk_std_core_sslice_Sslice slice, kk_context_t* ctx );


// type declarations

// value type std/core/sslice/sslice
struct kk_std_core_sslice_Sslice {
  kk_string_t str;
  kk_integer_t start;
  kk_integer_t len;
};
typedef struct kk_std_core_sslice_Sslice kk_std_core_sslice__sslice;
static inline kk_std_core_sslice__sslice kk_std_core_sslice__new_Sslice(kk_string_t str, kk_integer_t start, kk_integer_t len, kk_context_t* _ctx) {
  kk_std_core_sslice__sslice _con;
  _con.str = str;
  _con.start = start;
  _con.len = len;
  return _con;
}
static inline bool kk_std_core_sslice__is_Sslice(kk_std_core_sslice__sslice x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_core_sslice__sslice kk_std_core_sslice__sslice_dup(kk_std_core_sslice__sslice _x, kk_context_t* _ctx) {
  kk_string_dup(_x.str, _ctx);
  kk_integer_dup(_x.start, _ctx);
  kk_integer_dup(_x.len, _ctx);
  return _x;
}
static inline void kk_std_core_sslice__sslice_drop(kk_std_core_sslice__sslice _x, kk_context_t* _ctx) {
  kk_string_drop(_x.str, _ctx);
  kk_integer_drop(_x.start, _ctx);
  kk_integer_drop(_x.len, _ctx);
}
static inline kk_box_t kk_std_core_sslice__sslice_box(kk_std_core_sslice__sslice _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_core_sslice__sslice, _box, _x, 3 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_core_sslice__sslice kk_std_core_sslice__sslice_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  kk_std_core_sslice__sslice _unbox;
  kk_valuetype_unbox(kk_std_core_sslice__sslice, _unbox, _x, _borrow, _ctx);
  return _unbox;
}

// value declarations
 
// Automatically generated. Retrieves the `str` constructor field of the `:sslice` type.

static inline kk_string_t kk_std_core_sslice_sslice_fs_str(kk_std_core_sslice__sslice sslice, kk_context_t* _ctx) { /* (sslice : sslice) -> string */ 
  {
    kk_string_t _x = sslice.str;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `start` constructor field of the `:sslice` type.

static inline kk_integer_t kk_std_core_sslice_sslice_fs_start(kk_std_core_sslice__sslice sslice, kk_context_t* _ctx) { /* (sslice : sslice) -> int */ 
  {
    kk_integer_t _x = sslice.start;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `len` constructor field of the `:sslice` type.

static inline kk_integer_t kk_std_core_sslice_sslice_fs_len(kk_std_core_sslice__sslice sslice, kk_context_t* _ctx) { /* (sslice : sslice) -> int */ 
  {
    kk_integer_t _x = sslice.len;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_std_core_sslice__sslice kk_std_core_sslice_sslice_fs__copy(kk_std_core_sslice__sslice _this, kk_std_core_types__optional str, kk_std_core_types__optional start, kk_std_core_types__optional len, kk_context_t* _ctx); /* (sslice, str : ? string, start : ? int, len : ? int) -> sslice */ 
 
// Internal export for the regex module

static inline kk_std_core_sslice__sslice kk_std_core_sslice__new_sslice(kk_string_t str, kk_integer_t start, kk_integer_t len, kk_context_t* _ctx) { /* (str : string, start : int, len : int) -> sslice */ 
  return kk_std_core_sslice__new_Sslice(str, start, len, _ctx);
}

kk_string_t kk_std_core_sslice_string(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx); /* (slice : sslice) -> string */ 

bool kk_std_core_sslice__lp__eq__eq__rp_(kk_std_core_sslice__sslice slice1, kk_std_core_sslice__sslice slice2, kk_context_t* _ctx); /* (slice1 : sslice, slice2 : sslice) -> bool */ 
 
// Inequality based on contents of the slice
// O(`n`+`m`) where `n` and `m` are the lengths of the two strings

static inline bool kk_std_core_sslice__lp__excl__eq__rp_(kk_std_core_sslice__sslice slice1, kk_std_core_sslice__sslice slice2, kk_context_t* _ctx) { /* (slice1 : sslice, slice2 : sslice) -> bool */ 
  bool b_10003 = kk_std_core_sslice__lp__eq__eq__rp_(slice1, slice2, _ctx); /*bool*/;
  if (b_10003) {
    return false;
  }
  {
    return true;
  }
}

bool kk_std_core_sslice__lp__eq__eq__eq__rp_(kk_std_core_sslice__sslice slice1, kk_std_core_sslice__sslice slice2, kk_context_t* _ctx); /* (slice1 : sslice, slice2 : sslice) -> bool */ 
 
// Inequality of slices at the same offset and length on the same string.
// (The strings do not have to be referentially identical though)

static inline bool kk_std_core_sslice__lp__excl__eq__eq__rp_(kk_std_core_sslice__sslice slice1, kk_std_core_sslice__sslice slice2, kk_context_t* _ctx) { /* (slice1 : sslice, slice2 : sslice) -> bool */ 
  bool b_10004 = kk_std_core_sslice__lp__eq__eq__eq__rp_(slice1, slice2, _ctx); /*bool*/;
  if (b_10004) {
    return false;
  }
  {
    return true;
  }
}

kk_integer_t kk_std_core_sslice_count(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx); /* (slice : sslice) -> int */ 

kk_std_core_sslice__sslice kk_std_core_sslice_first1(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> sslice */ 

kk_std_core_sslice__sslice kk_std_core_sslice_last1(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> sslice */ 
 
// O(1). The entire string as a slice

static inline kk_std_core_sslice__sslice kk_std_core_sslice_slice(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> sslice */ 
  kk_string_t _x_x220 = kk_string_dup(s, _ctx); /*string*/
  kk_integer_t _x_x221 = kk_string_len_int(s,kk_context()); /*int*/
  return kk_std_core_sslice__new_Sslice(_x_x220, kk_integer_from_small(0), _x_x221, _ctx);
}

kk_std_core_types__maybe kk_std_core_sslice_next(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx); /* (slice : sslice) -> maybe<(char, sslice)> */ 

kk_std_core_types__maybe kk_std_core_sslice__mlift_foreach_while_10275(kk_function_t action, kk_std_core_sslice__sslice rest, kk_std_core_types__maybe _y_x10243, kk_context_t* _ctx); /* forall<a,e> (action : (c : char) -> e maybe<a>, rest : sslice, maybe<a>) -> e maybe<a> */ 

kk_std_core_types__maybe kk_std_core_sslice_foreach_while(kk_std_core_sslice__sslice slice_0, kk_function_t action_0, kk_context_t* _ctx); /* forall<a,e> (slice : sslice, action : (c : char) -> e maybe<a>) -> e maybe<a> */ 
 
// Invoke a function for each character in a string.
// If `action` returns `Just`, the function returns immediately with that result.

static inline kk_std_core_types__maybe kk_std_core_sslice_string_fs_foreach_while(kk_string_t s, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (s : string, action : (c : char) -> e maybe<a>) -> e maybe<a> */ 
  kk_std_core_sslice__sslice _x_x226;
  kk_string_t _x_x227 = kk_string_dup(s, _ctx); /*string*/
  kk_integer_t _x_x228 = kk_string_len_int(s,kk_context()); /*int*/
  _x_x226 = kk_std_core_sslice__new_Sslice(_x_x227, kk_integer_from_small(0), _x_x228, _ctx); /*sslice/sslice*/
  return kk_std_core_sslice_foreach_while(_x_x226, action, _ctx);
}

kk_std_core_types__maybe kk_std_core_sslice__mlift_lift_foreach_10234_10276(kk_std_core_sslice__sslice _uniq_rest_10198, kk_function_t action, kk_unit_t wild__, kk_context_t* _ctx); /* forall<_a,e> (sslice, action : (c : char) -> e (), wild_ : ()) -> e maybe<_a> */ 

kk_std_core_types__maybe kk_std_core_sslice__lift_foreach_10234(kk_function_t action_0, kk_std_core_sslice__sslice _uniq_slice_0_10192, kk_context_t* _ctx); /* forall<_a,e> (action : (c : char) -> e (), sslice) -> e maybe<_a> */ 
 
// monadic lift

static inline kk_unit_t kk_std_core_sslice__mlift_foreach_10277(kk_std_core_types__maybe wild___0, kk_context_t* _ctx) { /* forall<_a,e> (wild_@0 : maybe<_a>) -> e () */ 
  kk_std_core_types__maybe_drop(wild___0, _ctx);
  kk_Unit; return kk_Unit;
}

kk_unit_t kk_std_core_sslice_foreach(kk_std_core_sslice__sslice slice_0, kk_function_t action, kk_context_t* _ctx); /* forall<e> (slice : sslice, action : (c : char) -> e ()) -> e () */ 

kk_std_core_types__maybe kk_std_core_sslice_string_fs__mlift_lift_foreach_10235_10278(kk_std_core_sslice__sslice _uniq_rest_10212, kk_function_t action, kk_unit_t wild__, kk_context_t* _ctx); /* forall<_a,e> (sslice, action : (c : char) -> e (), wild_ : ()) -> e maybe<_a> */ 

kk_std_core_types__maybe kk_std_core_sslice_string_fs__lift_foreach_10235(kk_function_t action_0, kk_std_core_sslice__sslice _uniq_slice_0_10206, kk_context_t* _ctx); /* forall<_a,e> (action : (c : char) -> e (), sslice) -> e maybe<_a> */ 
 
// monadic lift

static inline kk_unit_t kk_std_core_sslice_string_fs__mlift_foreach_10279(kk_std_core_types__maybe wild___0, kk_context_t* _ctx) { /* forall<_a,e> (wild_@0 : maybe<_a>) -> e () */ 
  kk_std_core_types__maybe_drop(wild___0, _ctx);
  kk_Unit; return kk_Unit;
}

kk_unit_t kk_std_core_sslice_string_fs_foreach(kk_string_t s, kk_function_t action, kk_context_t* _ctx); /* forall<e> (s : string, action : (c : char) -> e ()) -> e () */ 

kk_unit_t kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10280(kk_ref_t cnt, kk_integer_t _y_x10260, kk_context_t* _ctx); /* forall<h,e> (cnt : local-var<h,int>, int) -> <local<h>|e> () */ 

kk_std_core_types__maybe kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10281(kk_std_core_sslice__sslice _uniq_rest_10226, kk_ref_t cnt_0, kk_function_t pred, kk_unit_t _c_x10262, kk_context_t* _ctx); /* forall<_a,h,e> (sslice, cnt : local-var<h,int>, pred : (char) -> e bool, ()) -> maybe<_a> */ 

kk_std_core_types__maybe kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282(kk_std_core_sslice__sslice _uniq_rest_10226_0, kk_ref_t cnt_1, kk_function_t pred_0, bool _y_x10259, kk_context_t* _ctx); /* forall<_a,h,e> (sslice, cnt : local-var<h,int>, pred : (char) -> e bool, bool) -> <local<h>|e> maybe<_a> */ 

kk_std_core_types__maybe kk_std_core_sslice_pred_fs__lift_count_10236(kk_ref_t cnt_2, kk_function_t pred_1, kk_std_core_sslice__sslice _uniq_slice_0_10220, kk_context_t* _ctx); /* forall<_a,h,e> (cnt : local-var<h,int>, pred : (char) -> e bool, sslice) -> <local<h>|e> maybe<_a> */ 
 
// monadic lift

static inline kk_integer_t kk_std_core_sslice_pred_fs__mlift_count_10283(kk_ref_t cnt, kk_std_core_types__maybe wild___0, kk_context_t* _ctx) { /* forall<_a,h,e> (cnt : local-var<h,int>, wild_@0 : maybe<_a>) -> <local<h>|e> int */ 
  kk_std_core_types__maybe_drop(wild___0, _ctx);
  kk_box_t _x_x269 = kk_ref_get(cnt,kk_context()); /*1927*/
  return kk_integer_unbox(_x_x269, _ctx);
}

kk_integer_t kk_std_core_sslice_pred_fs_count(kk_string_t s, kk_function_t pred, kk_context_t* _ctx); /* forall<e> (s : string, pred : (char) -> e bool) -> e int */ 

kk_std_core_sslice__sslice kk_std_core_sslice_advance(kk_std_core_sslice__sslice slice_0, kk_integer_t count_0, kk_context_t* _ctx); /* (slice : sslice, count : int) -> sslice */ 

kk_std_core_sslice__sslice kk_std_core_sslice_extend(kk_std_core_sslice__sslice slice_0, kk_integer_t count_0, kk_context_t* _ctx); /* (slice : sslice, count : int) -> sslice */ 

kk_std_core_sslice__sslice kk_std_core_sslice_first(kk_string_t s, kk_std_core_types__optional n, kk_context_t* _ctx); /* (s : string, n : ? int) -> sslice */ 

kk_std_core_sslice__sslice kk_std_core_sslice_last(kk_string_t s, kk_std_core_types__optional n, kk_context_t* _ctx); /* (s : string, n : ? int) -> sslice */ 
 
// O(1). Return the string slice from the start of a string up to the
// start of `slice` argument.

static inline kk_std_core_sslice__sslice kk_std_core_sslice_before(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx) { /* (slice : sslice) -> sslice */ 
  {
    kk_string_t s = slice_0.str;
    kk_integer_t start = slice_0.start;
    kk_string_dup(s, _ctx);
    kk_integer_dup(start, _ctx);
    kk_std_core_sslice__sslice_drop(slice_0, _ctx);
    return kk_std_core_sslice__new_Sslice(s, kk_integer_from_small(0), start, _ctx);
  }
}

kk_std_core_sslice__sslice kk_std_core_sslice_after(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx); /* (slice : sslice) -> sslice */ 

kk_string_t kk_std_core_sslice_capitalize(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> string */ 

extern kk_std_core_sslice__sslice kk_std_core_sslice_empty;
 
// Is a slice empty?

static inline bool kk_std_core_sslice_is_empty(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx) { /* (slice : sslice) -> bool */ 
  bool b_10039;
  kk_integer_t _brw_x157;
  {
    kk_integer_t _x = slice_0.len;
    kk_integer_dup(_x, _ctx);
    kk_std_core_sslice__sslice_drop(slice_0, _ctx);
    _brw_x157 = _x; /*int*/
  }
  bool _brw_x158 = kk_integer_gt_borrow(_brw_x157,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x157, _ctx);
  b_10039 = _brw_x158; /*bool*/
  if (b_10039) {
    return false;
  }
  {
    return true;
  }
}

extern kk_std_core_sslice__sslice kk_std_core_sslice_invalid;
 
// Is a slice invalid?

static inline bool kk_std_core_sslice_is_valid(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx) { /* (slice : sslice) -> bool */ 
  kk_integer_t _brw_x155;
  {
    kk_integer_t _x = slice_0.start;
    kk_integer_dup(_x, _ctx);
    kk_std_core_sslice__sslice_drop(slice_0, _ctx);
    _brw_x155 = _x; /*int*/
  }
  bool _brw_x156 = kk_integer_gte_borrow(_brw_x155,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x155, _ctx);
  return _brw_x156;
}
 
// Is a slice not empty?

static inline bool kk_std_core_sslice_is_notempty(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx) { /* (slice : sslice) -> bool */ 
  kk_integer_t _brw_x153;
  {
    kk_integer_t _x = slice_0.len;
    kk_integer_dup(_x, _ctx);
    kk_std_core_sslice__sslice_drop(slice_0, _ctx);
    _brw_x153 = _x; /*int*/
  }
  bool _brw_x154 = kk_integer_gt_borrow(_brw_x153,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x153, _ctx);
  return _brw_x154;
}

kk_string_t kk_std_core_sslice_head(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> string */ 

kk_string_t kk_std_core_sslice_tail(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> string */ 

kk_std_core_sslice__sslice kk_std_core_sslice_common_prefix(kk_string_t s, kk_string_t t, kk_std_core_types__optional upto, kk_context_t* _ctx); /* (s : string, t : string, upto : ? int) -> sslice */ 
 
// Truncates a slice to length 0

static inline kk_std_core_sslice__sslice kk_std_core_sslice_truncate(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx) { /* (slice : sslice) -> sslice */ 
  kk_string_t _x_x312;
  {
    kk_string_t _x = slice_0.str;
    kk_string_dup(_x, _ctx);
    _x_x312 = _x; /*string*/
  }
  kk_integer_t _x_x313;
  {
    kk_integer_t _x_0 = slice_0.start;
    kk_integer_dup(_x_0, _ctx);
    kk_std_core_sslice__sslice_drop(slice_0, _ctx);
    _x_x313 = _x_0; /*int*/
  }
  return kk_std_core_sslice__new_Sslice(_x_x312, _x_x313, kk_integer_from_small(0), _ctx);
}

kk_string_t kk_std_core_sslice_string_fs_truncate(kk_string_t s, kk_integer_t count_0, kk_context_t* _ctx); /* (s : string, count : int) -> string */ 

kk_std_core_sslice__sslice kk_std_core_sslice_subslice(kk_std_core_sslice__sslice slice_0, kk_integer_t start, kk_integer_t end, kk_context_t* _ctx); /* (slice : sslice, start : int, end : int) -> sslice */ 

kk_std_core_sslice__sslice kk_std_core_sslice_take(kk_std_core_sslice__sslice slice_0, kk_integer_t n, kk_context_t* _ctx); /* (slice : sslice, n : int) -> sslice */ 

kk_std_core_sslice__sslice kk_std_core_sslice_drop(kk_std_core_sslice__sslice slice_0, kk_integer_t n, kk_context_t* _ctx); /* (slice : sslice, n : int) -> sslice */ 

kk_std_core_types__maybe kk_std_core_sslice_head_char(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> maybe<char> */ 

kk_std_core_types__maybe kk_std_core_sslice_find(kk_string_t s, kk_string_t sub, kk_context_t* _ctx); /* (s : string, sub : string) -> maybe<sslice> */ 

kk_std_core_types__maybe kk_std_core_sslice_find_last(kk_string_t s, kk_string_t sub, kk_context_t* _ctx); /* (s : string, sub : string) -> maybe<sslice> */ 

kk_std_core_types__maybe kk_std_core_sslice_starts_with(kk_string_t s, kk_string_t pre, kk_context_t* _ctx); /* (s : string, pre : string) -> maybe<sslice> */ 

bool kk_std_core_sslice_xends_with(kk_string_t s, kk_string_t post, kk_context_t* _ctx); /* (s : string, post : string) -> bool */ 

kk_std_core_types__maybe kk_std_core_sslice_ends_with(kk_string_t s, kk_string_t post, kk_context_t* _ctx); /* (s : string, post : string) -> maybe<sslice> */ 

kk_string_t kk_std_core_sslice_trim_left(kk_string_t s, kk_string_t sub, kk_context_t* _ctx); /* (s : string, sub : string) -> string */ 

kk_string_t kk_std_core_sslice_trim_right(kk_string_t s, kk_string_t sub, kk_context_t* _ctx); /* (s : string, sub : string) -> string */ 

void kk_std_core_sslice__init(kk_context_t* _ctx);


void kk_std_core_sslice__done(kk_context_t* _ctx);

#endif // header
