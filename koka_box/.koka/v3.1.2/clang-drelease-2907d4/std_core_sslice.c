// Koka generated module: std/core/sslice, koka version: 3.1.2, platform: 64-bit
#include "std_core_sslice.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2024, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

static inline void kk_sslice_start_end_borrowx( kk_std_core_sslice__sslice sslice, const uint8_t** start, const uint8_t** end, const uint8_t** sstart, const uint8_t** send, kk_context_t* ctx) {
  kk_ssize_t strlen;
  const uint8_t* s = kk_string_buf_borrow(sslice.str,&strlen,ctx);
  kk_ssize_t slstart = kk_integer_clamp_ssize_t_borrow(sslice.start,ctx);
  kk_ssize_t sllen   = kk_integer_clamp_ssize_t_borrow(sslice.len,ctx);
  *start = s + slstart;
  *end = s + slstart + sllen;
  if (sstart != NULL) *sstart = s;
  if (send != NULL) *send = s + strlen;
  kk_assert_internal(*start >= s && *start <= *end);
  kk_assert_internal(*end >= *start && *end <= s + strlen);
}

static inline void kk_sslice_start_end_borrow( kk_std_core_sslice__sslice sslice, const uint8_t** start, const uint8_t** end, kk_context_t* ctx) {
  kk_sslice_start_end_borrowx(sslice,start,end,NULL,NULL,ctx);
}

kk_integer_t kk_slice_count( kk_std_core_sslice__sslice sslice, kk_context_t* ctx ) {
  // TODO: optimize this by extending kk_string_count
  const uint8_t* start;
  const uint8_t* end;
  kk_sslice_start_end_borrow(sslice, &start, &end, ctx);
  kk_ssize_t count = 0;
  while( start < end && *start != 0 ) {
    const uint8_t* next = kk_utf8_next(start);
    count++;
    start = next;
  }
  kk_std_core_sslice__sslice_drop(sslice,ctx);
  return kk_integer_from_ssize_t(count,ctx);
}

kk_string_t kk_slice_to_string( kk_std_core_sslice__sslice  sslice, kk_context_t* ctx ) {
  const uint8_t* start;
  const uint8_t* end;
  kk_sslice_start_end_borrow(sslice, &start, &end, ctx);
  // is it the full string?
  if (kk_integer_is_zero_borrow(sslice.start) &&
      kk_integer_eq_borrow(sslice.len,kk_integer_from_ssize_t(kk_string_len_borrow(sslice.str,ctx),ctx),ctx)) {
    // TODO: drop sslice and dup sslice.str?
    return sslice.str;
  }
  else {
    // if not, we copy len bytes
    kk_string_t s = kk_string_alloc_dupn_valid_utf8(kk_integer_clamp_ssize_t_borrow(sslice.len,ctx), start, ctx);
    kk_std_core_sslice__sslice_drop(sslice,ctx);
    return s;
  }
}

kk_std_core_sslice__sslice kk_slice_first( kk_string_t str, kk_context_t* ctx ) {
  kk_ssize_t slen;
  const uint8_t* s = kk_string_buf_borrow(str,&slen,ctx);
  const uint8_t* next = (slen > 0 ? kk_utf8_next(s) : s);
  return kk_std_core_sslice__new_Sslice(str, kk_integer_zero, kk_integer_from_ptrdiff_t(next - s,ctx), ctx);
}

kk_std_core_sslice__sslice kk_slice_last( kk_string_t str, kk_context_t* ctx ) {
  kk_ssize_t slen;
  const uint8_t* s = kk_string_buf_borrow(str,&slen,ctx);
  const uint8_t* end = s + slen;
  const uint8_t* prev = (s==end ? s : kk_utf8_prev(end));
  return kk_std_core_sslice__new_Sslice(str, kk_integer_from_ptrdiff_t(prev - s,ctx), kk_integer_from_ptrdiff_t(end - prev,ctx), ctx);
}

kk_std_core_sslice__sslice kk_slice_between( struct kk_std_core_sslice_Sslice slice1, struct kk_std_core_sslice_Sslice slice2, kk_context_t* ctx ) {
  const uint8_t* s1 = kk_string_buf_borrow( slice1.str, NULL, ctx );
  const uint8_t* s2 = kk_string_buf_borrow( slice2.str, NULL, ctx );
  if (s1 != s2) {
    kk_info_message("between: not equal slices: %p vs. %p\n", s1, s2);
    return kk_std_core_sslice__new_Sslice(kk_string_empty(), kk_integer_zero, kk_integer_min_one, ctx); // invalid slice
  }

  kk_integer_t start;
  kk_integer_t len;
  if (kk_integer_lte_borrow(slice1.start,slice2.start,ctx)) {
    start = kk_integer_dup(slice1.start,ctx);
    len   = kk_integer_sub(kk_integer_dup(slice2.start,ctx),kk_integer_dup(slice1.start,ctx),ctx);
  }
  else  {
    start = kk_integer_dup(slice2.start,ctx);
    len   = kk_integer_sub(kk_integer_dup(slice1.start,ctx),kk_integer_dup(slice2.start,ctx),ctx);
  }
  return kk_std_core_sslice__new_Sslice(slice1.str, start, len, ctx);
}

kk_std_core_types__maybe kk_slice_next( struct kk_std_core_sslice_Sslice slice, kk_context_t* ctx ) {
  if (!kk_integer_is_pos_borrow(slice.len,ctx)) {
    kk_std_core_sslice__sslice_drop(slice,ctx);
    return kk_std_core_types__new_Nothing(ctx);
  }
  const uint8_t* start;
  const uint8_t* end;
  kk_sslice_start_end_borrow(slice, &start, &end, ctx);
  kk_ssize_t clen;
  const kk_char_t c = kk_utf8_read(start,&clen);
  kk_assert_internal(clen > 0 && clen <= kk_integer_clamp_ssize_t_borrow(slice.len,ctx));
  kk_integer_t iclen = kk_integer_min(kk_integer_from_ssize_t(clen,ctx),kk_integer_dup(slice.len,ctx),ctx);
  // TODO: specialize type to avoid boxing
  // note: don't drop slice as we take over all fields
  kk_integer_t istart = kk_integer_add(slice.start,kk_integer_dup(iclen,ctx),ctx);
  kk_integer_t ilen   = kk_integer_sub(slice.len,iclen,ctx);
  kk_std_core_sslice__sslice snext = kk_std_core_sslice__new_Sslice(slice.str, istart, ilen, ctx);
  kk_std_core_types__tuple2 res = kk_std_core_types__new_Tuple2( kk_char_box(c,ctx), kk_std_core_sslice__sslice_box(snext,ctx), ctx);
  return kk_std_core_types__new_Just( kk_std_core_types__tuple2_box(res,ctx), ctx );
}

/* Borrow count */
struct kk_std_core_sslice_Sslice kk_slice_extend_borrow( struct kk_std_core_sslice_Sslice slice, kk_integer_t count, kk_context_t* ctx ) {
  kk_ssize_t cnt = kk_integer_clamp_ssize_t_borrow(count,ctx);
  if (cnt==0 || (!kk_integer_is_pos_borrow(slice.len,ctx) && cnt<0)) return slice;
  const uint8_t* s0;
  const uint8_t* s1;
  kk_sslice_start_end_borrow(slice,&s0,&s1,ctx);
  const uint8_t* t  = s1;
  if (cnt >= 0) {
    do {
      t = kk_utf8_next(t);
      cnt--;
    } while (cnt > 0 && *t != 0);
  }
  else {  // cnt < 0
    const uint8_t* sstart = s0 - kk_integer_clamp_ssize_t_borrow(slice.start,ctx);
    do {
      t = kk_utf8_prev(t);
      cnt++;
    } while (cnt < 0 && t > sstart);
  }
  if (t == s1) return slice;  // length is unchanged
  kk_integer_drop(slice.len,ctx);
  return kk_std_core_sslice__new_Sslice(slice.str, slice.start, kk_integer_from_ptrdiff_t(t < s0 ? 0 : (t - s0),ctx), ctx);
}

/* Borrow count */
struct kk_std_core_sslice_Sslice kk_slice_advance_borrow( struct kk_std_core_sslice_Sslice slice, kk_integer_t count, kk_context_t* ctx ) {
  const kk_ssize_t cnt0 = kk_integer_clamp_ssize_t_borrow(count,ctx);
  kk_ssize_t cnt = cnt0;
  if (cnt==0) return slice;
  const uint8_t* sstart;
  const uint8_t* s0;
  const uint8_t* s1;
  const uint8_t* send;
  kk_sslice_start_end_borrowx(slice,&s0,&s1,&sstart,&send,ctx);
  // advance the start
  const uint8_t* t0  = s0;
  if (cnt >= 0) {
    while (cnt > 0 && t0 < send) {
      t0 = kk_utf8_next(t0);
      cnt--;
    }
  }
  else {  // cnt < 0
    while (cnt < 0 && t0 > sstart) {
      t0 = kk_utf8_prev(t0);
      cnt++;
    }
  }
  if (t0 == s0 && cnt0 > 0) return slice;  // start is unchanged
  // "t0" points to the new start, now advance the end by the same amount of codepoints
  const uint8_t* t1 = s1;
  cnt = cnt0;
  if (cnt >= 0) {
    while (cnt > 0 && t1 < send) {
      t1 = kk_utf8_next(t1);
      cnt--;
    }
  }
  else {  // cnt < 0
    while (cnt < 0 && t1 > sstart) {
      t1 = kk_utf8_prev(t1);
      cnt++;
    }
  }
  // t1 points to the new end
  kk_assert_internal(t1 >= t0);
  const kk_ssize_t in_len = kk_integer_clamp_ssize_t_borrow(slice.len, ctx);
  kk_ssize_t new_len = (t1-t0);
  // kk_info_message("Here %d %d %d t: %d %d s: %d %d, st: %d %d\n", in_len, cnt0, new_len, t1, t0, s1, s0, sstart, send);
  kk_assert_internal(t1 <= send && t0 >= sstart);
  kk_integer_drop(slice.start,ctx);
  kk_integer_drop(slice.len,ctx);
  return kk_std_core_sslice__new_Sslice(slice.str, kk_integer_from_ptrdiff_t(t0 - sstart,ctx),
                                          kk_integer_from_ptrdiff_t(new_len, ctx), ctx);
}

/* Borrow iupto */
struct kk_std_core_sslice_Sslice kk_slice_common_prefix_borrow( kk_string_t str1, kk_string_t str2, kk_integer_t iupto, kk_context_t* ctx ) {
  const uint8_t* s1 = kk_string_buf_borrow(str1,NULL,ctx);
  const uint8_t* s2 = kk_string_buf_borrow(str2,NULL,ctx);
  kk_ssize_t upto = kk_integer_clamp_ssize_t_borrow(iupto,ctx);
  kk_ssize_t count;
  for(count = 0; count < upto && *s1 != 0 && *s2 != 0; count++, s1++, s2++ ) {
    if (*s1 != *s2) break;
  }
  kk_string_drop(str2,ctx);
  return kk_std_core_sslice__new_Sslice(str1, kk_integer_zero, kk_integer_from_ssize_t(count,ctx), ctx);
}


kk_std_core_sslice__sslice kk_std_core_sslice_sslice_fs__copy(kk_std_core_sslice__sslice _this, kk_std_core_types__optional str, kk_std_core_types__optional start, kk_std_core_types__optional len, kk_context_t* _ctx) { /* (sslice, str : ? string, start : ? int, len : ? int) -> sslice */ 
  kk_string_t _x_x211;
  if (kk_std_core_types__is_Optional(str, _ctx)) {
    kk_box_t _box_x0 = str._cons._Optional.value;
    kk_string_t _uniq_str_143 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_str_143, _ctx);
    kk_std_core_types__optional_drop(str, _ctx);
    _x_x211 = _uniq_str_143; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(str, _ctx);
    {
      kk_string_t _x = _this.str;
      kk_string_dup(_x, _ctx);
      _x_x211 = _x; /*string*/
    }
  }
  kk_integer_t _x_x212;
  if (kk_std_core_types__is_Optional(start, _ctx)) {
    kk_box_t _box_x1 = start._cons._Optional.value;
    kk_integer_t _uniq_start_150 = kk_integer_unbox(_box_x1, _ctx);
    kk_integer_dup(_uniq_start_150, _ctx);
    kk_std_core_types__optional_drop(start, _ctx);
    _x_x212 = _uniq_start_150; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(start, _ctx);
    {
      kk_integer_t _x_0 = _this.start;
      kk_integer_dup(_x_0, _ctx);
      _x_x212 = _x_0; /*int*/
    }
  }
  kk_integer_t _x_x213;
  if (kk_std_core_types__is_Optional(len, _ctx)) {
    kk_box_t _box_x2 = len._cons._Optional.value;
    kk_integer_t _uniq_len_157 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_len_157, _ctx);
    kk_std_core_types__optional_drop(len, _ctx);
    kk_std_core_sslice__sslice_drop(_this, _ctx);
    _x_x213 = _uniq_len_157; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(len, _ctx);
    {
      kk_integer_t _x_1 = _this.len;
      kk_integer_dup(_x_1, _ctx);
      kk_std_core_sslice__sslice_drop(_this, _ctx);
      _x_x213 = _x_1; /*int*/
    }
  }
  return kk_std_core_sslice__new_Sslice(_x_x211, _x_x212, _x_x213, _ctx);
}
 
// O(n). Copy the `slice` argument into a fresh string.
// Takes O(1) time if the slice covers the entire string.

kk_string_t kk_std_core_sslice_string(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx) { /* (slice : sslice) -> string */ 
  return kk_slice_to_string(slice_0,kk_context());
}
 
// Equality based on contents of the slice
// O(`n`+`m`) where `n` and `m` are the lengths of the two strings

bool kk_std_core_sslice__lp__eq__eq__rp_(kk_std_core_sslice__sslice slice1, kk_std_core_sslice__sslice slice2, kk_context_t* _ctx) { /* (slice1 : sslice, slice2 : sslice) -> bool */ 
  {
    kk_string_t s1 = slice1.str;
    kk_integer_t start1 = slice1.start;
    kk_integer_t len1 = slice1.len;
    kk_string_t s2 = slice2.str;
    kk_integer_t start2 = slice2.start;
    kk_integer_t len2 = slice2.len;
    kk_integer_dup(len1, _ctx);
    kk_integer_dup(len2, _ctx);
    kk_string_dup(s1, _ctx);
    kk_string_dup(s2, _ctx);
    kk_integer_dup(start1, _ctx);
    kk_integer_dup(start2, _ctx);
    bool _match_x206 = kk_box_eq((kk_string_box(s1)),(kk_string_box(s2))); /*bool*/;
    if (_match_x206) {
      bool _match_x207;
      bool _brw_x210 = kk_integer_eq_borrow(start1,start2,kk_context()); /*bool*/;
      kk_integer_drop(start1, _ctx);
      kk_integer_drop(start2, _ctx);
      _match_x207 = _brw_x210; /*bool*/
      if (_match_x207) {
        bool _match_x208;
        bool _brw_x209 = kk_integer_eq_borrow(len1,len2,kk_context()); /*bool*/;
        kk_integer_drop(len1, _ctx);
        kk_integer_drop(len2, _ctx);
        _match_x208 = _brw_x209; /*bool*/
        if (_match_x208) {
          kk_std_core_sslice__sslice_drop(slice2, _ctx);
          kk_std_core_sslice__sslice_drop(slice1, _ctx);
          return true;
        }
        {
          kk_string_t _x_x214 = kk_std_core_sslice_string(slice1, _ctx); /*string*/
          kk_string_t _x_x215 = kk_std_core_sslice_string(slice2, _ctx); /*string*/
          return kk_string_is_eq(_x_x214,_x_x215,kk_context());
        }
      }
      {
        kk_integer_drop(len2, _ctx);
        kk_integer_drop(len1, _ctx);
        kk_string_t _x_x216 = kk_std_core_sslice_string(slice1, _ctx); /*string*/
        kk_string_t _x_x217 = kk_std_core_sslice_string(slice2, _ctx); /*string*/
        return kk_string_is_eq(_x_x216,_x_x217,kk_context());
      }
    }
    {
      kk_integer_drop(start2, _ctx);
      kk_integer_drop(start1, _ctx);
      kk_integer_drop(len2, _ctx);
      kk_integer_drop(len1, _ctx);
      kk_string_t _x_x218 = kk_std_core_sslice_string(slice1, _ctx); /*string*/
      kk_string_t _x_x219 = kk_std_core_sslice_string(slice2, _ctx); /*string*/
      return kk_string_is_eq(_x_x218,_x_x219,kk_context());
    }
  }
}
 
// Equality of slices at the same offset and length on an equal string
// (The strings do not have to be referentially identical though)

bool kk_std_core_sslice__lp__eq__eq__eq__rp_(kk_std_core_sslice__sslice slice1, kk_std_core_sslice__sslice slice2, kk_context_t* _ctx) { /* (slice1 : sslice, slice2 : sslice) -> bool */ 
  {
    kk_string_t s1 = slice1.str;
    kk_integer_t start1 = slice1.start;
    kk_integer_t len1 = slice1.len;
    kk_string_t s2 = slice2.str;
    kk_integer_t start2 = slice2.start;
    kk_integer_t len2 = slice2.len;
    bool _match_x202;
    bool _brw_x205 = kk_integer_eq_borrow(start1,start2,kk_context()); /*bool*/;
    kk_integer_drop(start1, _ctx);
    kk_integer_drop(start2, _ctx);
    _match_x202 = _brw_x205; /*bool*/
    if (_match_x202) {
      bool _match_x203;
      bool _brw_x204 = kk_integer_eq_borrow(len1,len2,kk_context()); /*bool*/;
      kk_integer_drop(len1, _ctx);
      kk_integer_drop(len2, _ctx);
      _match_x203 = _brw_x204; /*bool*/
      if (_match_x203) {
        return kk_string_is_eq(s1,s2,kk_context());
      }
      {
        kk_string_drop(s2, _ctx);
        kk_string_drop(s1, _ctx);
        return false;
      }
    }
    {
      kk_string_drop(s2, _ctx);
      kk_string_drop(s1, _ctx);
      kk_integer_drop(len2, _ctx);
      kk_integer_drop(len1, _ctx);
      return false;
    }
  }
}
 
// O(n). Return the number of characters in a string slice

kk_integer_t kk_std_core_sslice_count(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx) { /* (slice : sslice) -> int */ 
  return kk_slice_count(slice_0,kk_context());
}

kk_std_core_sslice__sslice kk_std_core_sslice_first1(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> sslice */ 
  return kk_slice_first(s,kk_context());
}

kk_std_core_sslice__sslice kk_std_core_sslice_last1(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> sslice */ 
  return kk_slice_last(s,kk_context());
}
 
// If the slice is not empty,
// return the first character, and a new slice that is advanced by 1.

kk_std_core_types__maybe kk_std_core_sslice_next(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx) { /* (slice : sslice) -> maybe<(char, sslice)> */ 
  return kk_slice_next(slice_0,kk_context());
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_sslice__mlift_foreach_while_10275(kk_function_t action, kk_std_core_sslice__sslice rest, kk_std_core_types__maybe _y_x10243, kk_context_t* _ctx) { /* forall<a,e> (action : (c : char) -> e maybe<a>, rest : sslice, maybe<a>) -> e maybe<a> */ 
  if (kk_std_core_types__is_Nothing(_y_x10243, _ctx)) {
    return kk_std_core_sslice_foreach_while(rest, action, _ctx);
  }
  {
    kk_std_core_sslice__sslice_drop(rest, _ctx);
    kk_function_drop(action, _ctx);
    return _y_x10243;
  }
}
 
// Apply a function for each character in a string slice.
// If `action` returns `Just`, the function returns immediately with that result.


// lift anonymous function
struct kk_std_core_sslice_foreach_while_fun224__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_std_core_sslice__sslice rest_0;
};
static kk_box_t kk_std_core_sslice_foreach_while_fun224(kk_function_t _fself, kk_box_t _b_x11, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_new_foreach_while_fun224(kk_function_t action_0, kk_std_core_sslice__sslice rest_0, kk_context_t* _ctx) {
  struct kk_std_core_sslice_foreach_while_fun224__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_foreach_while_fun224__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_foreach_while_fun224, kk_context());
  _self->action_0 = action_0;
  _self->rest_0 = rest_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_foreach_while_fun224(kk_function_t _fself, kk_box_t _b_x11, kk_context_t* _ctx) {
  struct kk_std_core_sslice_foreach_while_fun224__t* _self = kk_function_as(struct kk_std_core_sslice_foreach_while_fun224__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (c : char) -> 442 maybe<441> */
  kk_std_core_sslice__sslice rest_0 = _self->rest_0; /* sslice/sslice */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_std_core_sslice__sslice_dup(rest_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10243_0_13 = kk_std_core_types__maybe_unbox(_b_x11, KK_OWNED, _ctx); /*maybe<441>*/;
  kk_std_core_types__maybe _x_x225 = kk_std_core_sslice__mlift_foreach_while_10275(action_0, rest_0, _y_x10243_0_13, _ctx); /*maybe<441>*/
  return kk_std_core_types__maybe_box(_x_x225, _ctx);
}

kk_std_core_types__maybe kk_std_core_sslice_foreach_while(kk_std_core_sslice__sslice slice_0, kk_function_t action_0, kk_context_t* _ctx) { /* forall<a,e> (slice : sslice, action : (c : char) -> e maybe<a>) -> e maybe<a> */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x200 = kk_std_core_sslice_next(slice_0, _ctx); /*maybe<(char, sslice/sslice)>*/;
  if (kk_std_core_types__is_Nothing(_match_x200, _ctx)) {
    kk_function_drop(action_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_box_t _box_x7 = _match_x200._cons.Just.value;
    kk_std_core_types__tuple2 _pat_1 = kk_std_core_types__tuple2_unbox(_box_x7, KK_BORROWED, _ctx);
    kk_box_t _box_x8 = _pat_1.fst;
    kk_box_t _box_x9 = _pat_1.snd;
    kk_std_core_sslice__sslice rest_0 = kk_std_core_sslice__sslice_unbox(_box_x9, KK_BORROWED, _ctx);
    kk_char_t c = kk_char_unbox(_box_x8, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(rest_0, _ctx);
    kk_std_core_types__maybe_drop(_match_x200, _ctx);
    kk_std_core_types__maybe x_10284;
    kk_function_t _x_x222 = kk_function_dup(action_0, _ctx); /*(c : char) -> 442 maybe<441>*/
    x_10284 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_char_t, kk_context_t*), _x_x222, (_x_x222, c, _ctx), _ctx); /*maybe<441>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_10284, _ctx);
      kk_box_t _x_x223 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_new_foreach_while_fun224(action_0, rest_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__maybe_unbox(_x_x223, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_10284, _ctx)) { // tailcall
                                                        slice_0 = rest_0;
                                                        goto kk__tailcall;
    }
    {
      kk_std_core_sslice__sslice_drop(rest_0, _ctx);
      kk_function_drop(action_0, _ctx);
      return x_10284;
    }
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_sslice__mlift_lift_foreach_10234_10276(kk_std_core_sslice__sslice _uniq_rest_10198, kk_function_t action, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<_a,e> (sslice, action : (c : char) -> e (), wild_ : ()) -> e maybe<_a> */ 
  return kk_std_core_sslice__lift_foreach_10234(action, _uniq_rest_10198, _ctx);
}
 
// lifted local: foreach, @spec-x10204
// specialized: std/core/sslice/foreach-while, on parameters @uniq-action@10193, using:
// @uniq-action@10193 = fn<(e :: E)>(c: char){
//   val _ : ()
//         = action(c);
//   std/core/types/Nothing<_a>;
// }


// lift anonymous function
struct kk_std_core_sslice__lift_foreach_10234_fun231__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice _uniq_rest_10198_0;
  kk_function_t action_0;
};
static kk_box_t kk_std_core_sslice__lift_foreach_10234_fun231(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice__new_lift_foreach_10234_fun231(kk_std_core_sslice__sslice _uniq_rest_10198_0, kk_function_t action_0, kk_context_t* _ctx) {
  struct kk_std_core_sslice__lift_foreach_10234_fun231__t* _self = kk_function_alloc_as(struct kk_std_core_sslice__lift_foreach_10234_fun231__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice__lift_foreach_10234_fun231, kk_context());
  _self->_uniq_rest_10198_0 = _uniq_rest_10198_0;
  _self->action_0 = action_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice__lift_foreach_10234_fun231(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx) {
  struct kk_std_core_sslice__lift_foreach_10234_fun231__t* _self = kk_function_as(struct kk_std_core_sslice__lift_foreach_10234_fun231__t*, _fself, _ctx);
  kk_std_core_sslice__sslice _uniq_rest_10198_0 = _self->_uniq_rest_10198_0; /* sslice/sslice */
  kk_function_t action_0 = _self->action_0; /* (c : char) -> 517 () */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(_uniq_rest_10198_0, _ctx);kk_function_dup(action_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_20 = kk_Unit;
  kk_unit_unbox(_b_x18);
  kk_std_core_types__maybe _x_x232 = kk_std_core_sslice__mlift_lift_foreach_10234_10276(_uniq_rest_10198_0, action_0, wild___0_20, _ctx); /*maybe<_505>*/
  return kk_std_core_types__maybe_box(_x_x232, _ctx);
}

kk_std_core_types__maybe kk_std_core_sslice__lift_foreach_10234(kk_function_t action_0, kk_std_core_sslice__sslice _uniq_slice_0_10192, kk_context_t* _ctx) { /* forall<_a,e> (action : (c : char) -> e (), sslice) -> e maybe<_a> */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x198 = kk_std_core_sslice_next(_uniq_slice_0_10192, _ctx); /*maybe<(char, sslice/sslice)>*/;
  if (kk_std_core_types__is_Nothing(_match_x198, _ctx)) {
    kk_function_drop(action_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_box_t _box_x14 = _match_x198._cons.Just.value;
    kk_std_core_types__tuple2 _uniq_pat_1_10196 = kk_std_core_types__tuple2_unbox(_box_x14, KK_BORROWED, _ctx);
    kk_box_t _box_x15 = _uniq_pat_1_10196.fst;
    kk_box_t _box_x16 = _uniq_pat_1_10196.snd;
    kk_std_core_sslice__sslice _uniq_rest_10198_0 = kk_std_core_sslice__sslice_unbox(_box_x16, KK_BORROWED, _ctx);
    kk_char_t _uniq_c_10197 = kk_char_unbox(_box_x15, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(_uniq_rest_10198_0, _ctx);
    kk_std_core_types__maybe_drop(_match_x198, _ctx);
    kk_unit_t x_10287 = kk_Unit;
    kk_function_t _x_x229 = kk_function_dup(action_0, _ctx); /*(c : char) -> 517 ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_char_t, kk_context_t*), _x_x229, (_x_x229, _uniq_c_10197, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x230 = kk_std_core_hnd_yield_extend(kk_std_core_sslice__new_lift_foreach_10234_fun231(_uniq_rest_10198_0, action_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__maybe_unbox(_x_x230, KK_OWNED, _ctx);
    }
    { // tailcall
      _uniq_slice_0_10192 = _uniq_rest_10198_0;
      goto kk__tailcall;
    }
  }
}
 
// Apply a function for each character in a string slice.


// lift anonymous function
struct kk_std_core_sslice_foreach_fun234__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_sslice_foreach_fun234(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_new_foreach_fun234(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_sslice_foreach_fun234, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_sslice_foreach_fun234(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_std_core_types__maybe wild___0_24 = kk_std_core_types__maybe_unbox(_b_x22, KK_OWNED, _ctx); /*maybe<_505>*/;
  kk_std_core_types__maybe_drop(wild___0_24, _ctx);
  return kk_unit_box(kk_Unit);
}

kk_unit_t kk_std_core_sslice_foreach(kk_std_core_sslice__sslice slice_0, kk_function_t action, kk_context_t* _ctx) { /* forall<e> (slice : sslice, action : (c : char) -> e ()) -> e () */ 
  kk_std_core_types__maybe x_10290 = kk_std_core_sslice__lift_foreach_10234(action, slice_0, _ctx); /*maybe<_505>*/;
  kk_std_core_types__maybe_drop(x_10290, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x233 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_new_foreach_fun234(_ctx), _ctx); /*2978*/
    kk_unit_unbox(_x_x233); return kk_Unit;
  }
  {
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_sslice_string_fs__mlift_lift_foreach_10235_10278(kk_std_core_sslice__sslice _uniq_rest_10212, kk_function_t action, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<_a,e> (sslice, action : (c : char) -> e (), wild_ : ()) -> e maybe<_a> */ 
  return kk_std_core_sslice_string_fs__lift_foreach_10235(action, _uniq_rest_10212, _ctx);
}
 
// lifted local: string/foreach, @spec-x10218
// specialized: std/core/sslice/foreach-while, on parameters @uniq-action@10207, using:
// @uniq-action@10207 = fn<(e :: E)>(c: char){
//   val _ : ()
//         = action(c);
//   std/core/types/Nothing<_a>;
// }


// lift anonymous function
struct kk_std_core_sslice_string_fs__lift_foreach_10235_fun237__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice _uniq_rest_10212_0;
  kk_function_t action_0;
};
static kk_box_t kk_std_core_sslice_string_fs__lift_foreach_10235_fun237(kk_function_t _fself, kk_box_t _b_x29, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_string_fs__new_lift_foreach_10235_fun237(kk_std_core_sslice__sslice _uniq_rest_10212_0, kk_function_t action_0, kk_context_t* _ctx) {
  struct kk_std_core_sslice_string_fs__lift_foreach_10235_fun237__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_string_fs__lift_foreach_10235_fun237__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_string_fs__lift_foreach_10235_fun237, kk_context());
  _self->_uniq_rest_10212_0 = _uniq_rest_10212_0;
  _self->action_0 = action_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_string_fs__lift_foreach_10235_fun237(kk_function_t _fself, kk_box_t _b_x29, kk_context_t* _ctx) {
  struct kk_std_core_sslice_string_fs__lift_foreach_10235_fun237__t* _self = kk_function_as(struct kk_std_core_sslice_string_fs__lift_foreach_10235_fun237__t*, _fself, _ctx);
  kk_std_core_sslice__sslice _uniq_rest_10212_0 = _self->_uniq_rest_10212_0; /* sslice/sslice */
  kk_function_t action_0 = _self->action_0; /* (c : char) -> 539 () */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(_uniq_rest_10212_0, _ctx);kk_function_dup(action_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_31 = kk_Unit;
  kk_unit_unbox(_b_x29);
  kk_std_core_types__maybe _x_x238 = kk_std_core_sslice_string_fs__mlift_lift_foreach_10235_10278(_uniq_rest_10212_0, action_0, wild___0_31, _ctx); /*maybe<_505>*/
  return kk_std_core_types__maybe_box(_x_x238, _ctx);
}

kk_std_core_types__maybe kk_std_core_sslice_string_fs__lift_foreach_10235(kk_function_t action_0, kk_std_core_sslice__sslice _uniq_slice_0_10206, kk_context_t* _ctx) { /* forall<_a,e> (action : (c : char) -> e (), sslice) -> e maybe<_a> */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x195 = kk_std_core_sslice_next(_uniq_slice_0_10206, _ctx); /*maybe<(char, sslice/sslice)>*/;
  if (kk_std_core_types__is_Nothing(_match_x195, _ctx)) {
    kk_function_drop(action_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_box_t _box_x25 = _match_x195._cons.Just.value;
    kk_std_core_types__tuple2 _uniq_pat_1_10210 = kk_std_core_types__tuple2_unbox(_box_x25, KK_BORROWED, _ctx);
    kk_box_t _box_x26 = _uniq_pat_1_10210.fst;
    kk_box_t _box_x27 = _uniq_pat_1_10210.snd;
    kk_std_core_sslice__sslice _uniq_rest_10212_0 = kk_std_core_sslice__sslice_unbox(_box_x27, KK_BORROWED, _ctx);
    kk_char_t _uniq_c_10211 = kk_char_unbox(_box_x26, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(_uniq_rest_10212_0, _ctx);
    kk_std_core_types__maybe_drop(_match_x195, _ctx);
    kk_unit_t x_10294 = kk_Unit;
    kk_function_t _x_x235 = kk_function_dup(action_0, _ctx); /*(c : char) -> 539 ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_char_t, kk_context_t*), _x_x235, (_x_x235, _uniq_c_10211, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x236 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_string_fs__new_lift_foreach_10235_fun237(_uniq_rest_10212_0, action_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__maybe_unbox(_x_x236, KK_OWNED, _ctx);
    }
    { // tailcall
      _uniq_slice_0_10206 = _uniq_rest_10212_0;
      goto kk__tailcall;
    }
  }
}
 
// Invoke a function for each character in a string


// lift anonymous function
struct kk_std_core_sslice_string_fs_foreach_fun242__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_sslice_string_fs_foreach_fun242(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_string_fs_new_foreach_fun242(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_sslice_string_fs_foreach_fun242, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_sslice_string_fs_foreach_fun242(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_std_core_types__maybe wild___0_35 = kk_std_core_types__maybe_unbox(_b_x33, KK_OWNED, _ctx); /*maybe<_505>*/;
  kk_std_core_types__maybe_drop(wild___0_35, _ctx);
  return kk_unit_box(kk_Unit);
}

kk_unit_t kk_std_core_sslice_string_fs_foreach(kk_string_t s, kk_function_t action, kk_context_t* _ctx) { /* forall<e> (s : string, action : (c : char) -> e ()) -> e () */ 
  kk_std_core_sslice__sslice slice_0_10005;
  kk_string_t _x_x239 = kk_string_dup(s, _ctx); /*string*/
  kk_integer_t _x_x240 = kk_string_len_int(s,kk_context()); /*int*/
  slice_0_10005 = kk_std_core_sslice__new_Sslice(_x_x239, kk_integer_from_small(0), _x_x240, _ctx); /*sslice/sslice*/
  kk_std_core_types__maybe x_10297 = kk_std_core_sslice_string_fs__lift_foreach_10235(action, slice_0_10005, _ctx); /*maybe<_505>*/;
  kk_std_core_types__maybe_drop(x_10297, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x241 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_string_fs_new_foreach_fun242(_ctx), _ctx); /*2978*/
    kk_unit_unbox(_x_x241); return kk_Unit;
  }
  {
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_unit_t kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10280(kk_ref_t cnt, kk_integer_t _y_x10260, kk_context_t* _ctx) { /* forall<h,e> (cnt : local-var<h,int>, int) -> <local<h>|e> () */ 
  kk_integer_t _b_x37_39 = kk_integer_add_small_const(_y_x10260, 1, _ctx); /*int*/;
  kk_unit_t _brw_x193 = kk_Unit;
  kk_ref_set_borrow(cnt,(kk_integer_box(_b_x37_39, _ctx)),kk_context());
  kk_ref_drop(cnt, _ctx);
  _brw_x193; return kk_Unit;
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10281(kk_std_core_sslice__sslice _uniq_rest_10226, kk_ref_t cnt_0, kk_function_t pred, kk_unit_t _c_x10262, kk_context_t* _ctx) { /* forall<_a,h,e> (sslice, cnt : local-var<h,int>, pred : (char) -> e bool, ()) -> maybe<_a> */ 
  return kk_std_core_sslice_pred_fs__lift_count_10236(cnt_0, pred, _uniq_rest_10226, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282_fun247__t {
  struct kk_function_s _base;
  kk_ref_t cnt_1;
};
static kk_box_t kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282_fun247(kk_function_t _fself, kk_box_t _b_x43, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs__new_mlift_lift_count_10236_10282_fun247(kk_ref_t cnt_1, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282_fun247__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282_fun247__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282_fun247, kk_context());
  _self->cnt_1 = cnt_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282_fun247(kk_function_t _fself, kk_box_t _b_x43, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282_fun247__t* _self = kk_function_as(struct kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282_fun247__t*, _fself, _ctx);
  kk_ref_t cnt_1 = _self->cnt_1; /* local-var<638,int> */
  kk_drop_match(_self, {kk_ref_dup(cnt_1, _ctx);}, {}, _ctx)
  kk_unit_t _x_x248 = kk_Unit;
  kk_integer_t _x_x249 = kk_integer_unbox(_b_x43, _ctx); /*int*/
  kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10280(cnt_1, _x_x249, _ctx);
  return kk_unit_box(_x_x248);
}


// lift anonymous function
struct kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282_fun252__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice _uniq_rest_10226_0;
  kk_ref_t cnt_1;
  kk_function_t pred_0;
};
static kk_box_t kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282_fun252(kk_function_t _fself, kk_box_t _b_x47, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs__new_mlift_lift_count_10236_10282_fun252(kk_std_core_sslice__sslice _uniq_rest_10226_0, kk_ref_t cnt_1, kk_function_t pred_0, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282_fun252__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282_fun252__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282_fun252, kk_context());
  _self->_uniq_rest_10226_0 = _uniq_rest_10226_0;
  _self->cnt_1 = cnt_1;
  _self->pred_0 = pred_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282_fun252(kk_function_t _fself, kk_box_t _b_x47, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282_fun252__t* _self = kk_function_as(struct kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282_fun252__t*, _fself, _ctx);
  kk_std_core_sslice__sslice _uniq_rest_10226_0 = _self->_uniq_rest_10226_0; /* sslice/sslice */
  kk_ref_t cnt_1 = _self->cnt_1; /* local-var<638,int> */
  kk_function_t pred_0 = _self->pred_0; /* (char) -> 642 bool */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(_uniq_rest_10226_0, _ctx);kk_ref_dup(cnt_1, _ctx);kk_function_dup(pred_0, _ctx);}, {}, _ctx)
  kk_unit_t _c_x10262_0_49 = kk_Unit;
  kk_unit_unbox(_b_x47);
  kk_std_core_types__maybe _x_x253 = kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10281(_uniq_rest_10226_0, cnt_1, pred_0, _c_x10262_0_49, _ctx); /*maybe<_505>*/
  return kk_std_core_types__maybe_box(_x_x253, _ctx);
}

kk_std_core_types__maybe kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282(kk_std_core_sslice__sslice _uniq_rest_10226_0, kk_ref_t cnt_1, kk_function_t pred_0, bool _y_x10259, kk_context_t* _ctx) { /* forall<_a,h,e> (sslice, cnt : local-var<h,int>, pred : (char) -> e bool, bool) -> <local<h>|e> maybe<_a> */ 
  kk_unit_t x_10301 = kk_Unit;
  if (_y_x10259) {
    kk_integer_t x_0_10303;
    kk_box_t _x_x243;
    kk_ref_t _x_x244 = kk_ref_dup(cnt_1, _ctx); /*local-var<638,int>*/
    _x_x243 = kk_ref_get(_x_x244,kk_context()); /*1909*/
    x_0_10303 = kk_integer_unbox(_x_x243, _ctx); /*int*/
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_10303, _ctx);
      kk_box_t _x_x245;
      kk_function_t _x_x246;
      kk_ref_dup(cnt_1, _ctx);
      _x_x246 = kk_std_core_sslice_pred_fs__new_mlift_lift_count_10236_10282_fun247(cnt_1, _ctx); /*(2977) -> 2979 2978*/
      _x_x245 = kk_std_core_hnd_yield_extend(_x_x246, _ctx); /*2978*/
      kk_unit_unbox(_x_x245);
    }
    else {
      kk_ref_t _x_x250 = kk_ref_dup(cnt_1, _ctx); /*local-var<638,int>*/
      kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10280(_x_x250, x_0_10303, _ctx);
    }
  }
  else {
    
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x251 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_pred_fs__new_mlift_lift_count_10236_10282_fun252(_uniq_rest_10226_0, cnt_1, pred_0, _ctx), _ctx); /*2978*/
    return kk_std_core_types__maybe_unbox(_x_x251, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10281(_uniq_rest_10226_0, cnt_1, pred_0, x_10301, _ctx);
  }
}
 
// lifted local: pred/count, @spec-x10232
// specialized: std/core/sslice/foreach-while, on parameters @uniq-action@10221, using:
// @uniq-action@10221 = fn<<(local :: H -> X)<(h :: H)>|(e :: E)>>(c: char){
//   val _ : ()
//         = match ((std/core/hnd/@mask-builtin<bool,(e :: E),<(local :: H -> X)<(h :: H)>|(e :: E)>>((fn<(e :: E)>(){
//           (pred(c));
//         })))) {
//           ((std/core/types/True() : bool ) as @pat: bool)
//              -> std/core/types/local-set<int,(e :: E),(h :: H)>(cnt, (std/core/types/@open<(total :: E),<(local :: H -> X)<(h :: H)>|(e :: E)>,(x : int, y : int) -> int,(x : int, y : int) -> <(local :: H -> X)<(h :: H)>|(e :: E)> int>((fn(x: int, y: int){
//                 (std/core/int/int-add(x, y));
//               }))((std/core/types/local-get<int,(h :: H),(e :: E)>(cnt)), 1)));
//           ((@skip std/core/types/False() : bool ) as @pat@0: bool)
//              -> std/core/types/Unit;
//         };
//   std/core/types/Nothing<_a>;
// }


// lift anonymous function
struct kk_std_core_sslice_pred_fs__lift_count_10236_fun256__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice _uniq_rest_10226_1;
  kk_ref_t cnt_2;
  kk_function_t pred_1;
};
static kk_box_t kk_std_core_sslice_pred_fs__lift_count_10236_fun256(kk_function_t _fself, kk_box_t _b_x54, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs__new_lift_count_10236_fun256(kk_std_core_sslice__sslice _uniq_rest_10226_1, kk_ref_t cnt_2, kk_function_t pred_1, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__lift_count_10236_fun256__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_pred_fs__lift_count_10236_fun256__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_pred_fs__lift_count_10236_fun256, kk_context());
  _self->_uniq_rest_10226_1 = _uniq_rest_10226_1;
  _self->cnt_2 = cnt_2;
  _self->pred_1 = pred_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_pred_fs__lift_count_10236_fun256(kk_function_t _fself, kk_box_t _b_x54, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__lift_count_10236_fun256__t* _self = kk_function_as(struct kk_std_core_sslice_pred_fs__lift_count_10236_fun256__t*, _fself, _ctx);
  kk_std_core_sslice__sslice _uniq_rest_10226_1 = _self->_uniq_rest_10226_1; /* sslice/sslice */
  kk_ref_t cnt_2 = _self->cnt_2; /* local-var<638,int> */
  kk_function_t pred_1 = _self->pred_1; /* (char) -> 642 bool */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(_uniq_rest_10226_1, _ctx);kk_ref_dup(cnt_2, _ctx);kk_function_dup(pred_1, _ctx);}, {}, _ctx)
  bool _y_x10259_0_65 = kk_bool_unbox(_b_x54); /*bool*/;
  kk_std_core_types__maybe _x_x257 = kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10282(_uniq_rest_10226_1, cnt_2, pred_1, _y_x10259_0_65, _ctx); /*maybe<_505>*/
  return kk_std_core_types__maybe_box(_x_x257, _ctx);
}


// lift anonymous function
struct kk_std_core_sslice_pred_fs__lift_count_10236_fun262__t {
  struct kk_function_s _base;
  kk_ref_t cnt_2;
};
static kk_box_t kk_std_core_sslice_pred_fs__lift_count_10236_fun262(kk_function_t _fself, kk_box_t _b_x58, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs__new_lift_count_10236_fun262(kk_ref_t cnt_2, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__lift_count_10236_fun262__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_pred_fs__lift_count_10236_fun262__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_pred_fs__lift_count_10236_fun262, kk_context());
  _self->cnt_2 = cnt_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_pred_fs__lift_count_10236_fun262(kk_function_t _fself, kk_box_t _b_x58, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__lift_count_10236_fun262__t* _self = kk_function_as(struct kk_std_core_sslice_pred_fs__lift_count_10236_fun262__t*, _fself, _ctx);
  kk_ref_t cnt_2 = _self->cnt_2; /* local-var<638,int> */
  kk_drop_match(_self, {kk_ref_dup(cnt_2, _ctx);}, {}, _ctx)
  kk_unit_t _x_x263 = kk_Unit;
  kk_integer_t _x_x264 = kk_integer_unbox(_b_x58, _ctx); /*int*/
  kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10280(cnt_2, _x_x264, _ctx);
  return kk_unit_box(_x_x263);
}


// lift anonymous function
struct kk_std_core_sslice_pred_fs__lift_count_10236_fun267__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice _uniq_rest_10226_1;
  kk_ref_t cnt_2;
  kk_function_t pred_1;
};
static kk_box_t kk_std_core_sslice_pred_fs__lift_count_10236_fun267(kk_function_t _fself, kk_box_t _b_x62, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs__new_lift_count_10236_fun267(kk_std_core_sslice__sslice _uniq_rest_10226_1, kk_ref_t cnt_2, kk_function_t pred_1, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__lift_count_10236_fun267__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_pred_fs__lift_count_10236_fun267__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_pred_fs__lift_count_10236_fun267, kk_context());
  _self->_uniq_rest_10226_1 = _uniq_rest_10226_1;
  _self->cnt_2 = cnt_2;
  _self->pred_1 = pred_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_pred_fs__lift_count_10236_fun267(kk_function_t _fself, kk_box_t _b_x62, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__lift_count_10236_fun267__t* _self = kk_function_as(struct kk_std_core_sslice_pred_fs__lift_count_10236_fun267__t*, _fself, _ctx);
  kk_std_core_sslice__sslice _uniq_rest_10226_1 = _self->_uniq_rest_10226_1; /* sslice/sslice */
  kk_ref_t cnt_2 = _self->cnt_2; /* local-var<638,int> */
  kk_function_t pred_1 = _self->pred_1; /* (char) -> 642 bool */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(_uniq_rest_10226_1, _ctx);kk_ref_dup(cnt_2, _ctx);kk_function_dup(pred_1, _ctx);}, {}, _ctx)
  kk_unit_t _c_x10262_1_66 = kk_Unit;
  kk_unit_unbox(_b_x62);
  kk_std_core_types__maybe _x_x268 = kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10281(_uniq_rest_10226_1, cnt_2, pred_1, _c_x10262_1_66, _ctx); /*maybe<_505>*/
  return kk_std_core_types__maybe_box(_x_x268, _ctx);
}

kk_std_core_types__maybe kk_std_core_sslice_pred_fs__lift_count_10236(kk_ref_t cnt_2, kk_function_t pred_1, kk_std_core_sslice__sslice _uniq_slice_0_10220, kk_context_t* _ctx) { /* forall<_a,h,e> (cnt : local-var<h,int>, pred : (char) -> e bool, sslice) -> <local<h>|e> maybe<_a> */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x187 = kk_std_core_sslice_next(_uniq_slice_0_10220, _ctx); /*maybe<(char, sslice/sslice)>*/;
  if (kk_std_core_types__is_Nothing(_match_x187, _ctx)) {
    kk_function_drop(pred_1, _ctx);
    kk_ref_drop(cnt_2, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_box_t _box_x50 = _match_x187._cons.Just.value;
    kk_std_core_types__tuple2 _uniq_pat_1_10224 = kk_std_core_types__tuple2_unbox(_box_x50, KK_BORROWED, _ctx);
    kk_box_t _box_x51 = _uniq_pat_1_10224.fst;
    kk_box_t _box_x52 = _uniq_pat_1_10224.snd;
    kk_std_core_sslice__sslice _uniq_rest_10226_1 = kk_std_core_sslice__sslice_unbox(_box_x52, KK_BORROWED, _ctx);
    kk_char_t _uniq_c_10225 = kk_char_unbox(_box_x51, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(_uniq_rest_10226_1, _ctx);
    kk_std_core_types__maybe_drop(_match_x187, _ctx);
    bool x_1_10305;
    kk_function_t _x_x254 = kk_function_dup(pred_1, _ctx); /*(char) -> 642 bool*/
    x_1_10305 = kk_function_call(bool, (kk_function_t, kk_char_t, kk_context_t*), _x_x254, (_x_x254, _uniq_c_10225, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x255 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_pred_fs__new_lift_count_10236_fun256(_uniq_rest_10226_1, cnt_2, pred_1, _ctx), _ctx); /*2978*/
      return kk_std_core_types__maybe_unbox(_x_x255, KK_OWNED, _ctx);
    }
    {
      kk_unit_t x_2_10309 = kk_Unit;
      if (x_1_10305) {
        kk_integer_t x_3_10312;
        kk_box_t _x_x258;
        kk_ref_t _x_x259 = kk_ref_dup(cnt_2, _ctx); /*local-var<638,int>*/
        _x_x258 = kk_ref_get(_x_x259,kk_context()); /*1909*/
        x_3_10312 = kk_integer_unbox(_x_x258, _ctx); /*int*/
        if (kk_yielding(kk_context())) {
          kk_integer_drop(x_3_10312, _ctx);
          kk_box_t _x_x260;
          kk_function_t _x_x261;
          kk_ref_dup(cnt_2, _ctx);
          _x_x261 = kk_std_core_sslice_pred_fs__new_lift_count_10236_fun262(cnt_2, _ctx); /*(2977) -> 2979 2978*/
          _x_x260 = kk_std_core_hnd_yield_extend(_x_x261, _ctx); /*2978*/
          kk_unit_unbox(_x_x260);
        }
        else {
          kk_ref_t _x_x265 = kk_ref_dup(cnt_2, _ctx); /*local-var<638,int>*/
          kk_std_core_sslice_pred_fs__mlift_lift_count_10236_10280(_x_x265, x_3_10312, _ctx);
        }
      }
      else {
        
      }
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x266 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_pred_fs__new_lift_count_10236_fun267(_uniq_rest_10226_1, cnt_2, pred_1, _ctx), _ctx); /*2978*/
        return kk_std_core_types__maybe_unbox(_x_x266, KK_OWNED, _ctx);
      }
      { // tailcall
        _uniq_slice_0_10220 = _uniq_rest_10226_1;
        goto kk__tailcall;
      }
    }
  }
}
 
// Count the number of times a predicate is true for each character in a string


// lift anonymous function
struct kk_std_core_sslice_pred_fs_count_fun275__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_core_sslice_pred_fs_count_fun275(kk_function_t _fself, kk_box_t _b_x73, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs_new_count_fun275(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs_count_fun275__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_pred_fs_count_fun275__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_pred_fs_count_fun275, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_pred_fs_count_fun275(kk_function_t _fself, kk_box_t _b_x73, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs_count_fun275__t* _self = kk_function_as(struct kk_std_core_sslice_pred_fs_count_fun275__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<638,int> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_box_drop(_b_x73, _ctx);
  return kk_ref_get(loc,kk_context());
}

kk_integer_t kk_std_core_sslice_pred_fs_count(kk_string_t s, kk_function_t pred, kk_context_t* _ctx) { /* forall<e> (s : string, pred : (char) -> e bool) -> e int */ 
  kk_ref_t loc = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0), _ctx)),kk_context()); /*local-var<638,int>*/;
  kk_std_core_sslice__sslice slice_0_10010;
  kk_string_t _x_x270 = kk_string_dup(s, _ctx); /*string*/
  kk_integer_t _x_x271 = kk_string_len_int(s,kk_context()); /*int*/
  slice_0_10010 = kk_std_core_sslice__new_Sslice(_x_x270, kk_integer_from_small(0), _x_x271, _ctx); /*sslice/sslice*/
  kk_std_core_types__maybe x_10316;
  kk_ref_t _x_x272 = kk_ref_dup(loc, _ctx); /*local-var<638,int>*/
  x_10316 = kk_std_core_sslice_pred_fs__lift_count_10236(_x_x272, pred, slice_0_10010, _ctx); /*maybe<_505>*/
  kk_std_core_types__maybe_drop(x_10316, _ctx);
  kk_integer_t res;
  kk_box_t _x_x273;
  if (kk_yielding(kk_context())) {
    kk_function_t _x_x274;
    kk_ref_dup(loc, _ctx);
    _x_x274 = kk_std_core_sslice_pred_fs_new_count_fun275(loc, _ctx); /*(2977) -> 2979 1927*/
    _x_x273 = kk_std_core_hnd_yield_extend(_x_x274, _ctx); /*2978*/
  }
  else {
    kk_ref_t _x_x276 = kk_ref_dup(loc, _ctx); /*local-var<638,int>*/
    _x_x273 = kk_ref_get(_x_x276,kk_context()); /*2978*/
  }
  res = kk_integer_unbox(_x_x273, _ctx); /*int*/
  kk_box_t _x_x277 = kk_std_core_hnd_prompt_local_var(loc, kk_integer_box(res, _ctx), _ctx); /*9564*/
  return kk_integer_unbox(_x_x277, _ctx);
}
 
// O(`count`). Advance the start position of a string slice by `count` characters
// up to the end of the string.
// A negative `count` advances the start position backwards upto the first position
// in a string.
// Maintains the character count of the original slice upto the end of the string.
// For example:
//
// * `"abc".first.advance(1).string == "b"`,
// * `"abc".first.advance(3).string == ""`,
// * `"abc".last.advance(-1).string == "b"`.
//

kk_std_core_sslice__sslice kk_std_core_sslice_advance(kk_std_core_sslice__sslice slice_0, kk_integer_t count_0, kk_context_t* _ctx) { /* (slice : sslice, count : int) -> sslice */ 
  return kk_slice_advance_borrow(slice_0,count_0,kk_context());
}
 
// O(`count`). Extend a string slice by `count` characters up to the end of the string.
// A negative `count` shrinks the slice up to the empty slice.
// For example:
//
// * `"abc".first.extend(1).string == "ab"`
// * `"abc".last.extend(-1).string == ""`
//

kk_std_core_sslice__sslice kk_std_core_sslice_extend(kk_std_core_sslice__sslice slice_0, kk_integer_t count_0, kk_context_t* _ctx) { /* (slice : sslice, count : int) -> sslice */ 
  return kk_slice_extend_borrow(slice_0,count_0,kk_context());
}
 
// O(`n`). The first `n` (default = `1`) characters in a string.

kk_std_core_sslice__sslice kk_std_core_sslice_first(kk_string_t s, kk_std_core_types__optional n, kk_context_t* _ctx) { /* (s : string, n : ? int) -> sslice */ 
  kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(s, _ctx); /*sslice/sslice*/;
  bool _match_x181;
  kk_integer_t _brw_x184;
  if (kk_std_core_types__is_Optional(n, _ctx)) {
    kk_box_t _box_x83 = n._cons._Optional.value;
    kk_integer_t _uniq_n_665 = kk_integer_unbox(_box_x83, _ctx);
    kk_integer_dup(_uniq_n_665, _ctx);
    _brw_x184 = _uniq_n_665; /*int*/
  }
  else {
    _brw_x184 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x185 = kk_integer_eq_borrow(_brw_x184,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x184, _ctx);
  _match_x181 = _brw_x185; /*bool*/
  if (_match_x181) {
    kk_std_core_types__optional_drop(n, _ctx);
    return slice_0;
  }
  {
    kk_integer_t _brw_x182;
    kk_integer_t _x_x278;
    if (kk_std_core_types__is_Optional(n, _ctx)) {
      kk_box_t _box_x84 = n._cons._Optional.value;
      kk_integer_t _uniq_n_665_0 = kk_integer_unbox(_box_x84, _ctx);
      kk_integer_dup(_uniq_n_665_0, _ctx);
      kk_std_core_types__optional_drop(n, _ctx);
      _x_x278 = _uniq_n_665_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(n, _ctx);
      _x_x278 = kk_integer_from_small(1); /*int*/
    }
    _brw_x182 = kk_integer_add_small_const(_x_x278, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x183 = kk_std_core_sslice_extend(slice_0, _brw_x182, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x182, _ctx);
    return _brw_x183;
  }
}
 
// O(`n`). The last `n` (default = `1`) characters in a string

kk_std_core_sslice__sslice kk_std_core_sslice_last(kk_string_t s, kk_std_core_types__optional n, kk_context_t* _ctx) { /* (s : string, n : ? int) -> sslice */ 
  kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_last1(s, _ctx); /*sslice/sslice*/;
  bool _match_x173;
  kk_integer_t _brw_x179;
  if (kk_std_core_types__is_Optional(n, _ctx)) {
    kk_box_t _box_x85 = n._cons._Optional.value;
    kk_integer_t _uniq_n_697 = kk_integer_unbox(_box_x85, _ctx);
    kk_integer_dup(_uniq_n_697, _ctx);
    _brw_x179 = _uniq_n_697; /*int*/
  }
  else {
    _brw_x179 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x180 = kk_integer_eq_borrow(_brw_x179,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x179, _ctx);
  _match_x173 = _brw_x180; /*bool*/
  if (_match_x173) {
    kk_std_core_types__optional_drop(n, _ctx);
    return slice_0;
  }
  {
    kk_std_core_sslice__sslice _own_x175;
    kk_integer_t _brw_x176;
    kk_integer_t _x_x279;
    if (kk_std_core_types__is_Optional(n, _ctx)) {
      kk_box_t _box_x86 = n._cons._Optional.value;
      kk_integer_t _uniq_n_697_0 = kk_integer_unbox(_box_x86, _ctx);
      kk_integer_dup(_uniq_n_697_0, _ctx);
      _x_x279 = _uniq_n_697_0; /*int*/
    }
    else {
      _x_x279 = kk_integer_from_small(1); /*int*/
    }
    _brw_x176 = kk_integer_sub((kk_integer_from_small(1)),_x_x279,kk_context()); /*int*/
    kk_std_core_sslice__sslice _brw_x177 = kk_std_core_sslice_advance(slice_0, _brw_x176, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x176, _ctx);
    _own_x175 = _brw_x177; /*sslice/sslice*/
    kk_integer_t _brw_x174;
    kk_integer_t _x_x280;
    if (kk_std_core_types__is_Optional(n, _ctx)) {
      kk_box_t _box_x87 = n._cons._Optional.value;
      kk_integer_t _uniq_n_697_1 = kk_integer_unbox(_box_x87, _ctx);
      kk_integer_dup(_uniq_n_697_1, _ctx);
      kk_std_core_types__optional_drop(n, _ctx);
      _x_x280 = _uniq_n_697_1; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(n, _ctx);
      _x_x280 = kk_integer_from_small(1); /*int*/
    }
    _brw_x174 = kk_integer_add_small_const(_x_x280, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x178 = kk_std_core_sslice_extend(_own_x175, _brw_x174, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x174, _ctx);
    return _brw_x178;
  }
}
 
// O(1). Return the string slice from the end of `slice` argument
// to the end of the string.

kk_std_core_sslice__sslice kk_std_core_sslice_after(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx) { /* (slice : sslice) -> sslice */ 
  {
    kk_string_t s = slice_0.str;
    kk_integer_t start = slice_0.start;
    kk_integer_t len = slice_0.len;
    kk_integer_t x_0_10020;
    kk_string_t _x_x281 = kk_string_dup(s, _ctx); /*string*/
    x_0_10020 = kk_string_len_int(_x_x281,kk_context()); /*int*/
    kk_integer_t y_0_10021;
    kk_integer_t _x_x282 = kk_integer_dup(start, _ctx); /*int*/
    kk_integer_t _x_x283 = kk_integer_dup(len, _ctx); /*int*/
    y_0_10021 = kk_integer_add(_x_x282,_x_x283,kk_context()); /*int*/
    kk_integer_t _x_x284 = kk_integer_add(start,len,kk_context()); /*int*/
    kk_integer_t _x_x285 = kk_integer_sub(x_0_10020,y_0_10021,kk_context()); /*int*/
    return kk_std_core_sslice__new_Sslice(s, _x_x284, _x_x285, _ctx);
  }
}
 
// Convert the first character of a string to uppercase.

kk_string_t kk_std_core_sslice_capitalize(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_std_core_sslice__sslice slice_0_1;
  kk_string_t _x_x286 = kk_string_dup(s, _ctx); /*string*/
  slice_0_1 = kk_std_core_sslice_first1(_x_x286, _ctx); /*sslice/sslice*/
  kk_std_core_sslice__sslice slice_0_0_10028;
  bool _match_x166;
  kk_integer_t _brw_x171;
  kk_std_core_types__optional _match_x170 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x170, _ctx)) {
    kk_box_t _box_x88 = _match_x170._cons._Optional.value;
    kk_integer_t _uniq_n_665_0 = kk_integer_unbox(_box_x88, _ctx);
    kk_integer_dup(_uniq_n_665_0, _ctx);
    kk_std_core_types__optional_drop(_match_x170, _ctx);
    _brw_x171 = _uniq_n_665_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x170, _ctx);
    _brw_x171 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x172 = kk_integer_eq_borrow(_brw_x171,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x171, _ctx);
  _match_x166 = _brw_x172; /*bool*/
  if (_match_x166) {
    slice_0_0_10028 = slice_0_1; /*sslice/sslice*/
  }
  else {
    kk_integer_t _brw_x168;
    kk_integer_t _x_x287;
    kk_std_core_types__optional _match_x167 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x167, _ctx)) {
      kk_box_t _box_x89 = _match_x167._cons._Optional.value;
      kk_integer_t _uniq_n_665_0_0 = kk_integer_unbox(_box_x89, _ctx);
      kk_integer_dup(_uniq_n_665_0_0, _ctx);
      kk_std_core_types__optional_drop(_match_x167, _ctx);
      _x_x287 = _uniq_n_665_0_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x167, _ctx);
      _x_x287 = kk_integer_from_small(1); /*int*/
    }
    _brw_x168 = kk_integer_add_small_const(_x_x287, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x169 = kk_std_core_sslice_extend(slice_0_1, _brw_x168, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x168, _ctx);
    slice_0_0_10028 = _brw_x169; /*sslice/sslice*/
  }
  kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(s, _ctx); /*sslice/sslice*/;
  kk_string_t _x_x288;
  kk_string_t _x_x289;
  kk_std_core_sslice__sslice _x_x290;
  bool _match_x159;
  kk_integer_t _brw_x164;
  kk_std_core_types__optional _match_x163 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x163, _ctx)) {
    kk_box_t _box_x90 = _match_x163._cons._Optional.value;
    kk_integer_t _uniq_n_665 = kk_integer_unbox(_box_x90, _ctx);
    kk_integer_dup(_uniq_n_665, _ctx);
    kk_std_core_types__optional_drop(_match_x163, _ctx);
    _brw_x164 = _uniq_n_665; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x163, _ctx);
    _brw_x164 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x165 = kk_integer_eq_borrow(_brw_x164,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x164, _ctx);
  _match_x159 = _brw_x165; /*bool*/
  if (_match_x159) {
    _x_x290 = slice_0; /*sslice/sslice*/
  }
  else {
    kk_integer_t _brw_x161;
    kk_integer_t _x_x291;
    kk_std_core_types__optional _match_x160 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x160, _ctx)) {
      kk_box_t _box_x91 = _match_x160._cons._Optional.value;
      kk_integer_t _uniq_n_665_1 = kk_integer_unbox(_box_x91, _ctx);
      kk_integer_dup(_uniq_n_665_1, _ctx);
      kk_std_core_types__optional_drop(_match_x160, _ctx);
      _x_x291 = _uniq_n_665_1; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x160, _ctx);
      _x_x291 = kk_integer_from_small(1); /*int*/
    }
    _brw_x161 = kk_integer_add_small_const(_x_x291, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x162 = kk_std_core_sslice_extend(slice_0, _brw_x161, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x161, _ctx);
    _x_x290 = _brw_x162; /*sslice/sslice*/
  }
  _x_x289 = kk_std_core_sslice_string(_x_x290, _ctx); /*string*/
  _x_x288 = kk_std_core_string_to_upper(_x_x289, _ctx); /*string*/
  kk_string_t _x_x292;
  kk_std_core_sslice__sslice _x_x293;
  {
    kk_string_t s_1 = slice_0_0_10028.str;
    kk_integer_t start = slice_0_0_10028.start;
    kk_integer_t len = slice_0_0_10028.len;
    kk_integer_t x_1_10035;
    kk_string_t _x_x294 = kk_string_dup(s_1, _ctx); /*string*/
    x_1_10035 = kk_string_len_int(_x_x294,kk_context()); /*int*/
    kk_integer_t y_1_10036;
    kk_integer_t _x_x295 = kk_integer_dup(start, _ctx); /*int*/
    kk_integer_t _x_x296 = kk_integer_dup(len, _ctx); /*int*/
    y_1_10036 = kk_integer_add(_x_x295,_x_x296,kk_context()); /*int*/
    kk_integer_t _x_x297 = kk_integer_add(start,len,kk_context()); /*int*/
    kk_integer_t _x_x298 = kk_integer_sub(x_1_10035,y_1_10036,kk_context()); /*int*/
    _x_x293 = kk_std_core_sslice__new_Sslice(s_1, _x_x297, _x_x298, _ctx); /*sslice/sslice*/
  }
  _x_x292 = kk_std_core_sslice_string(_x_x293, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x288, _x_x292, _ctx);
}
 
// An empty slice

kk_std_core_sslice__sslice kk_std_core_sslice_empty;
 
// An invalid slice

kk_std_core_sslice__sslice kk_std_core_sslice_invalid;
 
// Return the first character of a string as a string (or the empty string)

kk_string_t kk_std_core_sslice_head(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(s, _ctx); /*sslice/sslice*/;
  kk_std_core_sslice__sslice _x_x303;
  bool _match_x146;
  kk_integer_t _brw_x151;
  kk_std_core_types__optional _match_x150 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x150, _ctx)) {
    kk_box_t _box_x92 = _match_x150._cons._Optional.value;
    kk_integer_t _uniq_n_665 = kk_integer_unbox(_box_x92, _ctx);
    kk_integer_dup(_uniq_n_665, _ctx);
    kk_std_core_types__optional_drop(_match_x150, _ctx);
    _brw_x151 = _uniq_n_665; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x150, _ctx);
    _brw_x151 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x152 = kk_integer_eq_borrow(_brw_x151,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x151, _ctx);
  _match_x146 = _brw_x152; /*bool*/
  if (_match_x146) {
    _x_x303 = slice_0; /*sslice/sslice*/
  }
  else {
    kk_integer_t _brw_x148;
    kk_integer_t _x_x304;
    kk_std_core_types__optional _match_x147 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x147, _ctx)) {
      kk_box_t _box_x93 = _match_x147._cons._Optional.value;
      kk_integer_t _uniq_n_665_0 = kk_integer_unbox(_box_x93, _ctx);
      kk_integer_dup(_uniq_n_665_0, _ctx);
      kk_std_core_types__optional_drop(_match_x147, _ctx);
      _x_x304 = _uniq_n_665_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x147, _ctx);
      _x_x304 = kk_integer_from_small(1); /*int*/
    }
    _brw_x148 = kk_integer_add_small_const(_x_x304, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x149 = kk_std_core_sslice_extend(slice_0, _brw_x148, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x148, _ctx);
    _x_x303 = _brw_x149; /*sslice/sslice*/
  }
  return kk_std_core_sslice_string(_x_x303, _ctx);
}
 
// Return the tail of a string (or the empty string)

kk_string_t kk_std_core_sslice_tail(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_std_core_sslice__sslice slice_0_0 = kk_std_core_sslice_first1(s, _ctx); /*sslice/sslice*/;
  kk_std_core_sslice__sslice slice_0_10049;
  bool _match_x139;
  kk_integer_t _brw_x144;
  kk_std_core_types__optional _match_x143 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x143, _ctx)) {
    kk_box_t _box_x94 = _match_x143._cons._Optional.value;
    kk_integer_t _uniq_n_665 = kk_integer_unbox(_box_x94, _ctx);
    kk_integer_dup(_uniq_n_665, _ctx);
    kk_std_core_types__optional_drop(_match_x143, _ctx);
    _brw_x144 = _uniq_n_665; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x143, _ctx);
    _brw_x144 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x145 = kk_integer_eq_borrow(_brw_x144,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x144, _ctx);
  _match_x139 = _brw_x145; /*bool*/
  if (_match_x139) {
    slice_0_10049 = slice_0_0; /*sslice/sslice*/
  }
  else {
    kk_integer_t _brw_x141;
    kk_integer_t _x_x305;
    kk_std_core_types__optional _match_x140 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x140, _ctx)) {
      kk_box_t _box_x95 = _match_x140._cons._Optional.value;
      kk_integer_t _uniq_n_665_0 = kk_integer_unbox(_box_x95, _ctx);
      kk_integer_dup(_uniq_n_665_0, _ctx);
      kk_std_core_types__optional_drop(_match_x140, _ctx);
      _x_x305 = _uniq_n_665_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x140, _ctx);
      _x_x305 = kk_integer_from_small(1); /*int*/
    }
    _brw_x141 = kk_integer_add_small_const(_x_x305, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x142 = kk_std_core_sslice_extend(slice_0_0, _brw_x141, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x141, _ctx);
    slice_0_10049 = _brw_x142; /*sslice/sslice*/
  }
  kk_std_core_sslice__sslice _x_x306;
  {
    kk_string_t s_0 = slice_0_10049.str;
    kk_integer_t start = slice_0_10049.start;
    kk_integer_t len = slice_0_10049.len;
    kk_integer_t x_0_10056;
    kk_string_t _x_x307 = kk_string_dup(s_0, _ctx); /*string*/
    x_0_10056 = kk_string_len_int(_x_x307,kk_context()); /*int*/
    kk_integer_t y_0_10057;
    kk_integer_t _x_x308 = kk_integer_dup(start, _ctx); /*int*/
    kk_integer_t _x_x309 = kk_integer_dup(len, _ctx); /*int*/
    y_0_10057 = kk_integer_add(_x_x308,_x_x309,kk_context()); /*int*/
    kk_integer_t _x_x310 = kk_integer_add(start,len,kk_context()); /*int*/
    kk_integer_t _x_x311 = kk_integer_sub(x_0_10056,y_0_10057,kk_context()); /*int*/
    _x_x306 = kk_std_core_sslice__new_Sslice(s_0, _x_x310, _x_x311, _ctx); /*sslice/sslice*/
  }
  return kk_std_core_sslice_string(_x_x306, _ctx);
}
 
// Return the common prefix of two strings (upto `upto` characters (default is minimum length of the two strings))

kk_std_core_sslice__sslice kk_std_core_sslice_common_prefix(kk_string_t s, kk_string_t t, kk_std_core_types__optional upto, kk_context_t* _ctx) { /* (s : string, t : string, upto : ? int) -> sslice */ 
  kk_integer_t _brw_x137;
  if (kk_std_core_types__is_Optional(upto, _ctx)) {
    kk_box_t _box_x96 = upto._cons._Optional.value;
    kk_integer_t _uniq_upto_901 = kk_integer_unbox(_box_x96, _ctx);
    _brw_x137 = kk_integer_dup(_uniq_upto_901, _ctx); /*int*/
  }
  else {
    _brw_x137 = kk_integer_from_small(-1); /*int*/
  }
  kk_std_core_sslice__sslice _brw_x138 = kk_slice_common_prefix_borrow(s,t,_brw_x137,kk_context()); /*sslice/sslice*/;
  kk_integer_drop(_brw_x137, _ctx);
  return _brw_x138;
}
 
// Truncate a string to `count` characters.

kk_string_t kk_std_core_sslice_string_fs_truncate(kk_string_t s, kk_integer_t count_0, kk_context_t* _ctx) { /* (s : string, count : int) -> string */ 
  kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(s, _ctx); /*sslice/sslice*/;
  kk_std_core_sslice__sslice _x_x314;
  kk_std_core_sslice__sslice _own_x128;
  bool _match_x129;
  kk_integer_t _brw_x134;
  kk_std_core_types__optional _match_x133 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x133, _ctx)) {
    kk_box_t _box_x97 = _match_x133._cons._Optional.value;
    kk_integer_t _uniq_n_665 = kk_integer_unbox(_box_x97, _ctx);
    kk_integer_dup(_uniq_n_665, _ctx);
    kk_std_core_types__optional_drop(_match_x133, _ctx);
    _brw_x134 = _uniq_n_665; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x133, _ctx);
    _brw_x134 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x135 = kk_integer_eq_borrow(_brw_x134,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x134, _ctx);
  _match_x129 = _brw_x135; /*bool*/
  if (_match_x129) {
    _own_x128 = slice_0; /*sslice/sslice*/
  }
  else {
    kk_integer_t _brw_x131;
    kk_integer_t _x_x315;
    kk_std_core_types__optional _match_x130 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x130, _ctx)) {
      kk_box_t _box_x98 = _match_x130._cons._Optional.value;
      kk_integer_t _uniq_n_665_0 = kk_integer_unbox(_box_x98, _ctx);
      kk_integer_dup(_uniq_n_665_0, _ctx);
      kk_std_core_types__optional_drop(_match_x130, _ctx);
      _x_x315 = _uniq_n_665_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x130, _ctx);
      _x_x315 = kk_integer_from_small(1); /*int*/
    }
    _brw_x131 = kk_integer_add_small_const(_x_x315, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x132 = kk_std_core_sslice_extend(slice_0, _brw_x131, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x131, _ctx);
    _own_x128 = _brw_x132; /*sslice/sslice*/
  }
  kk_integer_t _brw_x127 = kk_integer_add_small_const(count_0, -1, _ctx); /*int*/;
  kk_std_core_sslice__sslice _brw_x136 = kk_std_core_sslice_extend(_own_x128, _brw_x127, _ctx); /*sslice/sslice*/;
  kk_integer_drop(_brw_x127, _ctx);
  _x_x314 = _brw_x136; /*sslice/sslice*/
  return kk_std_core_sslice_string(_x_x314, _ctx);
}
 
// Gets up to (`end`-`start`) characters from the slice beginning from `start`.
// If either start or end is negative, returns the original slice

kk_std_core_sslice__sslice kk_std_core_sslice_subslice(kk_std_core_sslice__sslice slice_0, kk_integer_t start, kk_integer_t end, kk_context_t* _ctx) { /* (slice : sslice, start : int, end : int) -> sslice */ 
  bool _match_x123 = kk_integer_lt_borrow(start,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x123) {
    kk_integer_drop(start, _ctx);
    kk_integer_drop(end, _ctx);
    return slice_0;
  }
  {
    bool _match_x124 = kk_integer_lt_borrow(end,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x124) {
      kk_integer_drop(start, _ctx);
      kk_integer_drop(end, _ctx);
      return slice_0;
    }
    {
      kk_std_core_sslice__sslice slice_0_0_10068 = kk_std_core_sslice_advance(slice_0, start, _ctx); /*sslice/sslice*/;
      kk_integer_t _brw_x125 = kk_integer_sub(end,start,kk_context()); /*int*/;
      kk_std_core_sslice__sslice _brw_x126;
      kk_std_core_sslice__sslice _x_x316;
      kk_string_t _x_x317;
      {
        kk_string_t _x = slice_0_0_10068.str;
        kk_string_dup(_x, _ctx);
        _x_x317 = _x; /*string*/
      }
      kk_integer_t _x_x318;
      {
        kk_integer_t _x_0 = slice_0_0_10068.start;
        kk_integer_dup(_x_0, _ctx);
        kk_std_core_sslice__sslice_drop(slice_0_0_10068, _ctx);
        _x_x318 = _x_0; /*int*/
      }
      _x_x316 = kk_std_core_sslice__new_Sslice(_x_x317, _x_x318, kk_integer_from_small(0), _ctx); /*sslice/sslice*/
      _brw_x126 = kk_std_core_sslice_extend(_x_x316, _brw_x125, _ctx); /*sslice/sslice*/
      kk_integer_drop(_brw_x125, _ctx);
      return _brw_x126;
    }
  }
}
 
// Gets a slice that only includes up to n characters from the start of the slice.

kk_std_core_sslice__sslice kk_std_core_sslice_take(kk_std_core_sslice__sslice slice_0, kk_integer_t n, kk_context_t* _ctx) { /* (slice : sslice, n : int) -> sslice */ 
  bool _match_x121 = kk_integer_lte_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x121) {
    kk_integer_drop(n, _ctx);
    return slice_0;
  }
  {
    kk_std_core_sslice__sslice _brw_x122;
    kk_std_core_sslice__sslice _x_x319;
    kk_string_t _x_x320;
    {
      kk_string_t _x = slice_0.str;
      kk_string_dup(_x, _ctx);
      _x_x320 = _x; /*string*/
    }
    kk_integer_t _x_x321;
    {
      kk_integer_t _x_0 = slice_0.start;
      kk_integer_dup(_x_0, _ctx);
      kk_std_core_sslice__sslice_drop(slice_0, _ctx);
      _x_x321 = _x_0; /*int*/
    }
    _x_x319 = kk_std_core_sslice__new_Sslice(_x_x320, _x_x321, kk_integer_from_small(0), _ctx); /*sslice/sslice*/
    _brw_x122 = kk_std_core_sslice_extend(_x_x319, n, _ctx); /*sslice/sslice*/
    kk_integer_drop(n, _ctx);
    return _brw_x122;
  }
}
 
// Gets a slice that drops the first n characters, shrinking the length of the slice by n accordingly.
// If the slice does not have n characters, then the slice is shrunk to an empty slice.
//
// If maintaining the length of the slice is important, use `advance` instead.

kk_std_core_sslice__sslice kk_std_core_sslice_drop(kk_std_core_sslice__sslice slice_0, kk_integer_t n, kk_context_t* _ctx) { /* (slice : sslice, n : int) -> sslice */ 
  bool _match_x118 = kk_integer_lte_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x118) {
    kk_integer_drop(n, _ctx);
    return slice_0;
  }
  {
    kk_std_core_sslice__sslice slice_0_0_10076;
    kk_std_core_sslice__sslice _x_x322 = kk_std_core_sslice__sslice_dup(slice_0, _ctx); /*sslice/sslice*/
    slice_0_0_10076 = kk_std_core_sslice_advance(_x_x322, n, _ctx); /*sslice/sslice*/
    kk_integer_t x_10079 = kk_std_core_sslice_count(slice_0, _ctx); /*int*/;
    kk_integer_t _brw_x119 = kk_integer_sub(x_10079,n,kk_context()); /*int*/;
    kk_std_core_sslice__sslice _brw_x120;
    kk_std_core_sslice__sslice _x_x323;
    kk_string_t _x_x324;
    {
      kk_string_t _x = slice_0_0_10076.str;
      kk_string_dup(_x, _ctx);
      _x_x324 = _x; /*string*/
    }
    kk_integer_t _x_x325;
    {
      kk_integer_t _x_0 = slice_0_0_10076.start;
      kk_integer_dup(_x_0, _ctx);
      kk_std_core_sslice__sslice_drop(slice_0_0_10076, _ctx);
      _x_x325 = _x_0; /*int*/
    }
    _x_x323 = kk_std_core_sslice__new_Sslice(_x_x324, _x_x325, kk_integer_from_small(0), _ctx); /*sslice/sslice*/
    _brw_x120 = kk_std_core_sslice_extend(_x_x323, _brw_x119, _ctx); /*sslice/sslice*/
    kk_integer_drop(_brw_x119, _ctx);
    return _brw_x120;
  }
}
 
// Return the first character of a string (or `Nothing` for the empty string).


// lift anonymous function
struct kk_std_core_sslice_head_char_fun329__t {
  struct kk_function_s _base;
};
static kk_std_core_types__maybe kk_std_core_sslice_head_char_fun329(kk_function_t _fself, kk_char_t _b_x99, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_new_head_char_fun329(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_sslice_head_char_fun329, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_std_core_types__maybe kk_std_core_sslice_head_char_fun329(kk_function_t _fself, kk_char_t _b_x99, kk_context_t* _ctx) {
  kk_unused(_fself);
  return kk_std_core_types__new_Just(kk_char_box(_b_x99, _ctx), _ctx);
}

kk_std_core_types__maybe kk_std_core_sslice_head_char(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> maybe<char> */ 
  kk_std_core_sslice__sslice _x_x326;
  kk_string_t _x_x327 = kk_string_dup(s, _ctx); /*string*/
  kk_integer_t _x_x328 = kk_string_len_int(s,kk_context()); /*int*/
  _x_x326 = kk_std_core_sslice__new_Sslice(_x_x327, kk_integer_from_small(0), _x_x328, _ctx); /*sslice/sslice*/
  return kk_std_core_sslice_foreach_while(_x_x326, kk_std_core_sslice_new_head_char_fun329(_ctx), _ctx);
}
 
// O(n). If it occurs, return the position of substring `sub` in `s`, tupled with
// the position just following the substring `sub`.

kk_std_core_types__maybe kk_std_core_sslice_find(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> maybe<sslice> */ 
  kk_integer_t i;
  kk_ssize_t _x_x330;
  kk_string_t _x_x331 = kk_string_dup(s, _ctx); /*string*/
  kk_string_t _x_x332 = kk_string_dup(sub, _ctx); /*string*/
  _x_x330 = kk_string_index_of1(_x_x331,_x_x332,kk_context()); /*ssize_t*/
  i = kk_integer_from_ssize_t(_x_x330,kk_context()); /*int*/
  bool _match_x117 = kk_integer_is_zero_borrow(i); /*bool*/;
  if (_match_x117) {
    kk_string_drop(sub, _ctx);
    kk_string_drop(s, _ctx);
    kk_integer_drop(i, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_std_core_sslice__sslice _b_x100_101;
    kk_integer_t _x_x333 = kk_integer_add_small_const(i, -1, _ctx); /*int*/
    kk_integer_t _x_x334 = kk_string_len_int(sub,kk_context()); /*int*/
    _b_x100_101 = kk_std_core_sslice__new_Sslice(s, _x_x333, _x_x334, _ctx); /*sslice/sslice*/
    return kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x100_101, _ctx), _ctx);
  }
}
 
// Return the last index of substring `sub` in `s` if it occurs.

kk_std_core_types__maybe kk_std_core_sslice_find_last(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> maybe<sslice> */ 
  kk_integer_t i;
  kk_ssize_t _x_x335;
  kk_string_t _x_x336 = kk_string_dup(s, _ctx); /*string*/
  kk_string_t _x_x337 = kk_string_dup(sub, _ctx); /*string*/
  _x_x335 = kk_string_last_index_of1(_x_x336,_x_x337,kk_context()); /*ssize_t*/
  i = kk_integer_from_ssize_t(_x_x335,kk_context()); /*int*/
  bool _match_x116 = kk_integer_is_zero_borrow(i); /*bool*/;
  if (_match_x116) {
    kk_string_drop(sub, _ctx);
    kk_string_drop(s, _ctx);
    kk_integer_drop(i, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_std_core_sslice__sslice _b_x102_103;
    kk_integer_t _x_x338 = kk_integer_add_small_const(i, -1, _ctx); /*int*/
    kk_integer_t _x_x339 = kk_string_len_int(sub,kk_context()); /*int*/
    _b_x102_103 = kk_std_core_sslice__new_Sslice(s, _x_x338, _x_x339, _ctx); /*sslice/sslice*/
    return kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x102_103, _ctx), _ctx);
  }
}
 
// Is `pre`  a prefix of `s`? If so, returns a slice
// of `s` following `pre` up to the end of `s`.

kk_std_core_types__maybe kk_std_core_sslice_starts_with(kk_string_t s, kk_string_t pre, kk_context_t* _ctx) { /* (s : string, pre : string) -> maybe<sslice> */ 
  bool _match_x115;
  kk_string_t _x_x340 = kk_string_dup(s, _ctx); /*string*/
  kk_string_t _x_x341 = kk_string_dup(pre, _ctx); /*string*/
  _match_x115 = kk_string_starts_with(_x_x340,_x_x341,kk_context()); /*bool*/
  if (_match_x115) {
    kk_integer_t x_10085;
    kk_string_t _x_x342 = kk_string_dup(s, _ctx); /*string*/
    x_10085 = kk_string_len_int(_x_x342,kk_context()); /*int*/
    kk_integer_t y_10086;
    kk_string_t _x_x343 = kk_string_dup(pre, _ctx); /*string*/
    y_10086 = kk_string_len_int(_x_x343,kk_context()); /*int*/
    kk_std_core_sslice__sslice _b_x104_105;
    kk_integer_t _x_x344 = kk_string_len_int(pre,kk_context()); /*int*/
    kk_integer_t _x_x345 = kk_integer_sub(x_10085,y_10086,kk_context()); /*int*/
    _b_x104_105 = kk_std_core_sslice__new_Sslice(s, _x_x344, _x_x345, _ctx); /*sslice/sslice*/
    return kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x104_105, _ctx), _ctx);
  }
  {
    kk_string_drop(s, _ctx);
    kk_string_drop(pre, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}

bool kk_std_core_sslice_xends_with(kk_string_t s, kk_string_t post, kk_context_t* _ctx) { /* (s : string, post : string) -> bool */ 
  return kk_string_ends_with(s,post,kk_context());
}
 
// Does string `s`  end with `post`?
// If so, returns a slice of `s` from the start up to the `post` string at the end.

kk_std_core_types__maybe kk_std_core_sslice_ends_with(kk_string_t s, kk_string_t post, kk_context_t* _ctx) { /* (s : string, post : string) -> maybe<sslice> */ 
  bool _match_x114;
  kk_string_t _x_x346 = kk_string_dup(s, _ctx); /*string*/
  kk_string_t _x_x347 = kk_string_dup(post, _ctx); /*string*/
  _match_x114 = kk_std_core_sslice_xends_with(_x_x346, _x_x347, _ctx); /*bool*/
  if (_match_x114) {
    kk_integer_t x_10087;
    kk_string_t _x_x348 = kk_string_dup(s, _ctx); /*string*/
    x_10087 = kk_string_len_int(_x_x348,kk_context()); /*int*/
    kk_integer_t y_10088 = kk_string_len_int(post,kk_context()); /*int*/;
    kk_std_core_sslice__sslice _b_x106_107;
    kk_integer_t _x_x349 = kk_integer_sub(x_10087,y_10088,kk_context()); /*int*/
    _b_x106_107 = kk_std_core_sslice__new_Sslice(s, kk_integer_from_small(0), _x_x349, _ctx); /*sslice/sslice*/
    return kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x106_107, _ctx), _ctx);
  }
  {
    kk_string_drop(s, _ctx);
    kk_string_drop(post, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Trim off a substring `sub` while `s` starts with that string.

kk_string_t kk_std_core_sslice_trim_left(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> string */ 
  kk__tailcall: ;
  bool _match_x112;
  kk_string_t _x_x350 = kk_string_dup(sub, _ctx); /*string*/
  kk_string_t _x_x351 = kk_string_empty(); /*string*/
  _match_x112 = kk_string_is_eq(_x_x350,_x_x351,kk_context()); /*bool*/
  if (_match_x112) {
    kk_string_drop(sub, _ctx);
    return s;
  }
  {
    kk_std_core_types__maybe _match_x113;
    kk_string_t _x_x353 = kk_string_dup(s, _ctx); /*string*/
    kk_string_t _x_x354 = kk_string_dup(sub, _ctx); /*string*/
    _match_x113 = kk_std_core_sslice_starts_with(_x_x353, _x_x354, _ctx); /*maybe<sslice/sslice>*/
    if (kk_std_core_types__is_Just(_match_x113, _ctx)) {
      kk_box_t _box_x108 = _match_x113._cons.Just.value;
      kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice__sslice_unbox(_box_x108, KK_BORROWED, _ctx);
      kk_string_drop(s, _ctx);
      kk_std_core_sslice__sslice_dup(slice_0, _ctx);
      kk_std_core_types__maybe_drop(_match_x113, _ctx);
      { // tailcall
        kk_string_t _x_x355 = kk_std_core_sslice_string(slice_0, _ctx); /*string*/
        s = _x_x355;
        goto kk__tailcall;
      }
    }
    {
      kk_string_drop(sub, _ctx);
      return s;
    }
  }
}
 
// Trim off a substring `sub` while `s` ends with that string.

kk_string_t kk_std_core_sslice_trim_right(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> string */ 
  kk__tailcall: ;
  bool _match_x110;
  kk_string_t _x_x356 = kk_string_dup(sub, _ctx); /*string*/
  kk_string_t _x_x357 = kk_string_empty(); /*string*/
  _match_x110 = kk_string_is_eq(_x_x356,_x_x357,kk_context()); /*bool*/
  if (_match_x110) {
    kk_string_drop(sub, _ctx);
    return s;
  }
  {
    kk_std_core_types__maybe _match_x111;
    kk_string_t _x_x359 = kk_string_dup(s, _ctx); /*string*/
    kk_string_t _x_x360 = kk_string_dup(sub, _ctx); /*string*/
    _match_x111 = kk_std_core_sslice_ends_with(_x_x359, _x_x360, _ctx); /*maybe<sslice/sslice>*/
    if (kk_std_core_types__is_Just(_match_x111, _ctx)) {
      kk_box_t _box_x109 = _match_x111._cons.Just.value;
      kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice__sslice_unbox(_box_x109, KK_BORROWED, _ctx);
      kk_string_drop(s, _ctx);
      kk_std_core_sslice__sslice_dup(slice_0, _ctx);
      kk_std_core_types__maybe_drop(_match_x111, _ctx);
      { // tailcall
        kk_string_t _x_x361 = kk_std_core_sslice_string(slice_0, _ctx); /*string*/
        s = _x_x361;
        goto kk__tailcall;
      }
    }
    {
      kk_string_drop(sub, _ctx);
      return s;
    }
  }
}

// initialization
void kk_std_core_sslice__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_undiv__init(_ctx);
  kk_std_core_unsafe__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_string__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_string_t _x_x299 = kk_string_empty(); /*string*/
    kk_std_core_sslice_empty = kk_std_core_sslice__new_Sslice(_x_x299, kk_integer_from_small(0), kk_integer_from_small(0), _ctx); /*sslice/sslice*/
  }
  {
    kk_string_t _x_x301 = kk_string_empty(); /*string*/
    kk_std_core_sslice_invalid = kk_std_core_sslice__new_Sslice(_x_x301, kk_integer_from_small(-1), kk_integer_from_small(0), _ctx); /*sslice/sslice*/
  }
}

// termination
void kk_std_core_sslice__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_sslice__sslice_drop(kk_std_core_sslice_invalid, _ctx);
  kk_std_core_sslice__sslice_drop(kk_std_core_sslice_empty, _ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_unsafe__done(_ctx);
  kk_std_core_undiv__done(_ctx);
  kk_std_core_types__done(_ctx);
}
