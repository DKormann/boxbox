#pragma once
#ifndef kk_std_core_tuple_H
#define kk_std_core_tuple_H
// Koka generated module: std/core/tuple, koka version: 3.1.2, platform: 32-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"

// type declarations

// value declarations
 
// monadic lift

static inline kk_std_core_types__tuple2 kk_std_core_tuple_tuple2_fs__mlift_map_10129(kk_box_t _y_x10100, kk_box_t _y_x10101, kk_context_t* _ctx) { /* forall<a,e> (a, a) -> e (a, a) */ 
  return kk_std_core_types__new_Tuple2(_y_x10100, _y_x10101, _ctx);
}

kk_std_core_types__tuple2 kk_std_core_tuple_tuple2_fs__mlift_map_10130(kk_function_t f, kk_std_core_types__tuple2 t, kk_box_t _y_x10100, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> e b, t : (a, a), b) -> e (b, b) */ 

kk_std_core_types__tuple2 kk_std_core_tuple_tuple2_fs_map(kk_std_core_types__tuple2 t, kk_function_t f, kk_context_t* _ctx); /* forall<a,b,e> (t : (a, a), f : (a) -> e b) -> e (b, b) */ 
 
// monadic lift

static inline kk_std_core_types__tuple3 kk_std_core_tuple_tuple3_fs__mlift_map_10131(kk_box_t _y_x10102, kk_box_t _y_x10103, kk_box_t _y_x10104, kk_context_t* _ctx) { /* forall<a,e> (a, a, a) -> e (a, a, a) */ 
  return kk_std_core_types__new_Tuple3(_y_x10102, _y_x10103, _y_x10104, _ctx);
}

kk_std_core_types__tuple3 kk_std_core_tuple_tuple3_fs__mlift_map_10132(kk_box_t _y_x10102, kk_function_t f, kk_std_core_types__tuple3 t, kk_box_t _y_x10103, kk_context_t* _ctx); /* forall<a,b,e> (b, f : (a) -> e b, t : (a, a, a), b) -> e (b, b, b) */ 

kk_std_core_types__tuple3 kk_std_core_tuple_tuple3_fs__mlift_map_10133(kk_function_t f, kk_std_core_types__tuple3 t, kk_box_t _y_x10102, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> e b, t : (a, a, a), b) -> e (b, b, b) */ 

kk_std_core_types__tuple3 kk_std_core_tuple_tuple3_fs_map(kk_std_core_types__tuple3 t, kk_function_t f, kk_context_t* _ctx); /* forall<a,b,e> (t : (a, a, a), f : (a) -> e b) -> e (b, b, b) */ 
 
// monadic lift

static inline kk_std_core_types__tuple4 kk_std_core_tuple_tuple4_fs__mlift_map_10134(kk_box_t _y_x10105, kk_box_t _y_x10106, kk_box_t _y_x10107, kk_box_t _y_x10108, kk_context_t* _ctx) { /* forall<a,e> (a, a, a, a) -> e (a, a, a, a) */ 
  return kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _y_x10105, _y_x10106, _y_x10107, _y_x10108, _ctx);
}

kk_std_core_types__tuple4 kk_std_core_tuple_tuple4_fs__mlift_map_10135(kk_box_t _y_x10105, kk_box_t _y_x10106, kk_function_t f, kk_std_core_types__tuple4 t, kk_box_t _y_x10107, kk_context_t* _ctx); /* forall<a,b,e> (b, b, f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 

kk_std_core_types__tuple4 kk_std_core_tuple_tuple4_fs__mlift_map_10136(kk_box_t _y_x10105, kk_function_t f, kk_std_core_types__tuple4 t, kk_box_t _y_x10106, kk_context_t* _ctx); /* forall<a,b,e> (b, f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 

kk_std_core_types__tuple4 kk_std_core_tuple_tuple4_fs__mlift_map_10137(kk_function_t f, kk_std_core_types__tuple4 t, kk_box_t _y_x10105, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 

kk_std_core_types__tuple4 kk_std_core_tuple_tuple4_fs_map(kk_std_core_types__tuple4 t, kk_function_t f, kk_context_t* _ctx); /* forall<a,b,e> (t : (a, a, a, a), f : (a) -> e b) -> e (b, b, b, b) */ 

bool kk_std_core_tuple_tuple2_fs__lp__eq__eq__rp_(kk_std_core_types__tuple2 _pat_x29__22, kk_std_core_types__tuple2 _pat_x29__39, kk_function_t _implicit_fs_fst_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_context_t* _ctx); /* forall<a,b> ((a, b), (a, b), ?fst/(==) : (a, a) -> bool, ?snd/(==) : (b, b) -> bool) -> bool */ 

bool kk_std_core_tuple_tuple3_fs__lp__eq__eq__rp_(kk_std_core_types__tuple3 _pat_x33__22, kk_std_core_types__tuple3 _pat_x33__44, kk_function_t _implicit_fs_fst_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_context_t* _ctx); /* forall<a,b,c> ((a, b, c), (a, b, c), ?fst/(==) : (a, a) -> bool, ?snd/(==) : (b, b) -> bool, ?thd/(==) : (c, c) -> bool) -> bool */ 

kk_std_core_types__order kk_std_core_tuple_tuple2_fs_cmp(kk_std_core_types__tuple2 _pat_x38__21, kk_std_core_types__tuple2 _pat_x38__38, kk_function_t _implicit_fs_fst_fs_cmp, kk_function_t _implicit_fs_snd_fs_cmp, kk_context_t* _ctx); /* forall<a,b> ((a, b), (a, b), ?fst/cmp : (a, a) -> order, ?snd/cmp : (b, b) -> order) -> order */ 

kk_std_core_types__order kk_std_core_tuple_tuple3_fs_cmp(kk_std_core_types__tuple3 _pat_x44__26, kk_std_core_types__tuple3 _pat_x44__48, kk_function_t _implicit_fs_fst_fs_cmp, kk_function_t _implicit_fs_snd_fs_cmp, kk_function_t _implicit_fs_thd_fs_cmp, kk_context_t* _ctx); /* forall<a,b,c> ((a, b, c), (a, b, c), ?fst/cmp : (a, a) -> order, ?snd/cmp : (b, b) -> order, ?thd/cmp : (c, c) -> order) -> order */ 
 
// Convert a unit value `()` to a string

static inline kk_string_t kk_std_core_tuple_unit_fs_show(kk_unit_t u, kk_context_t* _ctx) { /* (u : ()) -> string */ 
  kk_define_string_literal(, _s_x201, 2, "()", _ctx)
  return kk_string_dup(_s_x201, _ctx);
}
 
// monadic lift

static inline kk_string_t kk_std_core_tuple_tuple2_fs__mlift_show_10138(kk_string_t _y_x10109, kk_string_t _y_x10110, kk_context_t* _ctx) { /* forall<e> (string, string) -> e string */ 
  kk_string_t _x_x202;
  kk_define_string_literal(, _s_x203, 1, "(", _ctx)
  _x_x202 = kk_string_dup(_s_x203, _ctx); /*string*/
  kk_string_t _x_x204;
  kk_string_t _x_x205;
  kk_string_t _x_x206;
  kk_define_string_literal(, _s_x207, 1, ",", _ctx)
  _x_x206 = kk_string_dup(_s_x207, _ctx); /*string*/
  kk_string_t _x_x208;
  kk_string_t _x_x209;
  kk_define_string_literal(, _s_x210, 1, ")", _ctx)
  _x_x209 = kk_string_dup(_s_x210, _ctx); /*string*/
  _x_x208 = kk_std_core_types__lp__plus__plus__rp_(_y_x10110, _x_x209, _ctx); /*string*/
  _x_x205 = kk_std_core_types__lp__plus__plus__rp_(_x_x206, _x_x208, _ctx); /*string*/
  _x_x204 = kk_std_core_types__lp__plus__plus__rp_(_y_x10109, _x_x205, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x202, _x_x204, _ctx);
}

kk_string_t kk_std_core_tuple_tuple2_fs__mlift_show_10139(kk_std_core_types__tuple2 x, kk_function_t _implicit_fs_snd_fs_show, kk_string_t _y_x10109, kk_context_t* _ctx); /* forall<a,b,e> (x : (a, b), ?snd/show : (b) -> e string, string) -> e string */ 

kk_string_t kk_std_core_tuple_tuple2_fs_show(kk_std_core_types__tuple2 x, kk_function_t _implicit_fs_fst_fs_show, kk_function_t _implicit_fs_snd_fs_show, kk_context_t* _ctx); /* forall<a,b,e> (x : (a, b), ?fst/show : (a) -> e string, ?snd/show : (b) -> e string) -> e string */ 

kk_string_t kk_std_core_tuple_tuple3_fs__mlift_show_10140(kk_string_t _y_x10111, kk_string_t _y_x10112, kk_string_t _y_x10113, kk_context_t* _ctx); /* forall<e> (string, string, string) -> e string */ 

kk_string_t kk_std_core_tuple_tuple3_fs__mlift_show_10141(kk_string_t _y_x10111, kk_std_core_types__tuple3 x, kk_function_t _implicit_fs_thd_fs_show, kk_string_t _y_x10112, kk_context_t* _ctx); /* forall<a,b,c,e> (string, x : (a, b, c), ?thd/show : (c) -> e string, string) -> e string */ 

kk_string_t kk_std_core_tuple_tuple3_fs__mlift_show_10142(kk_std_core_types__tuple3 x, kk_function_t _implicit_fs_snd_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_string_t _y_x10111, kk_context_t* _ctx); /* forall<a,b,c,e> (x : (a, b, c), ?snd/show : (b) -> e string, ?thd/show : (c) -> e string, string) -> e string */ 

kk_string_t kk_std_core_tuple_tuple3_fs_show(kk_std_core_types__tuple3 x, kk_function_t _implicit_fs_fst_fs_show, kk_function_t _implicit_fs_snd_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_context_t* _ctx); /* forall<a,b,c,e> (x : (a, b, c), ?fst/show : (a) -> e string, ?snd/show : (b) -> e string, ?thd/show : (c) -> e string) -> e string */ 
 
// _deprecated_, use `tuple2/show` instead

static inline kk_string_t kk_std_core_tuple_show_tuple(kk_std_core_types__tuple2 x, kk_function_t showfst, kk_function_t showsnd, kk_context_t* _ctx) { /* forall<a,b,e> (x : (a, b), showfst : (a) -> e string, showsnd : (b) -> e string) -> e string */ 
  return kk_std_core_tuple_tuple2_fs_show(x, showfst, showsnd, _ctx);
}

void kk_std_core_tuple__init(kk_context_t* _ctx);


void kk_std_core_tuple__done(kk_context_t* _ctx);

#endif // header
