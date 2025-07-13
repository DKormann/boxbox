#pragma once
#ifndef kk_std_core_vector_H
#define kk_std_core_vector_H
// Koka generated module: std/core/vector, koka version: 3.1.2, platform: 32-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_undiv.h"
#include "std_core_hnd.h"
#include "std_core_exn.h"
#include "std_core_int.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2024, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

kk_datatype_t  kk_vector_to_list(kk_vector_t v, kk_datatype_t tail, kk_context_t* ctx);
kk_vector_t    kk_list_to_vector(kk_datatype_t xs, kk_context_t* ctx);

static inline kk_unit_t kk_vector_unsafe_assign( kk_vector_t v, kk_ssize_t i, kk_box_t x, kk_context_t* ctx  ) {
  kk_ssize_t len;
  kk_box_t* p = kk_vector_buf_borrow(v,&len,ctx);
  kk_assert(i < len);
  p[i] = x;
  kk_vector_drop(v,ctx); // TODO: use borrowing
  return kk_Unit;
}

static inline kk_box_t kk_vector_at_int_borrow( kk_vector_t v, kk_integer_t n, kk_context_t* ctx) {
  // TODO: check bounds
  kk_box_t b = kk_vector_at_borrow(v,kk_integer_clamp_ssize_t_borrow(n,ctx),ctx);
  return b;
}


// type declarations

// value declarations

kk_vector_t kk_std_core_vector_vector_alloc(kk_ssize_t n, kk_box_t init, kk_context_t* _ctx); /* forall<a,e> (n : ssize_t, init : a) -> e vector<a> */ 

kk_vector_t kk_std_core_vector_vector_alloc_total(kk_ssize_t n, kk_function_t f, kk_context_t* _ctx); /* forall<a> (n : ssize_t, f : (ssize_t) -> a) -> vector<a> */ 

kk_box_t kk_std_core_vector__index(kk_vector_t v, kk_integer_t index, kk_context_t* _ctx); /* forall<a> (v : vector<a>, index : int) -> exn a */ 

kk_std_core_types__maybe kk_std_core_vector_at(kk_vector_t v, kk_integer_t index, kk_context_t* _ctx); /* forall<a> (v : vector<a>, index : int) -> maybe<a> */ 
 
// Return the length of a vector.

static inline kk_integer_t kk_std_core_vector_length(kk_vector_t v, kk_context_t* _ctx) { /* forall<a> (v : vector<a>) -> int */ 
  kk_ssize_t _x_x71 = kk_vector_len_borrow(v,kk_context()); /*ssize_t*/
  return kk_integer_from_ssize_t(_x_x71,kk_context());
}
 
// Create a new vector of length `n`  with initial elements `default` .

static inline kk_vector_t kk_std_core_vector_vector(kk_integer_t n, kk_box_t kkloc_default, kk_context_t* _ctx) { /* forall<a> (n : int, default : a) -> vector<a> */ 
  kk_ssize_t _x_x72;
  kk_integer_t _x_x73 = kk_integer_dup(n, _ctx); /*int*/
  _x_x72 = kk_std_core_int_ssize__t(_x_x73, _ctx); /*ssize_t*/
  return kk_std_core_vector_vector_alloc(_x_x72, kkloc_default, _ctx);
}
 
// Create a new vector of length `n`  with initial elements given by _total_ function `f`.
// (can be more efficient than `vector-init`)


// lift anonymous function
struct kk_std_core_vector_vector_init_total_fun76__t {
  struct kk_function_s _base;
  kk_function_t f;
};
extern kk_box_t kk_std_core_vector_vector_init_total_fun76(kk_function_t _fself, kk_ssize_t i, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_vector_new_vector_init_total_fun76(kk_function_t f, kk_context_t* _ctx) {
  struct kk_std_core_vector_vector_init_total_fun76__t* _self = kk_function_alloc_as(struct kk_std_core_vector_vector_init_total_fun76__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector_vector_init_total_fun76, kk_context());
  _self->f = f;
  return kk_datatype_from_base(&_self->_base, kk_context());
}


static inline kk_vector_t kk_std_core_vector_vector_init_total(kk_integer_t n, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (n : int, f : (int) -> a) -> e vector<a> */ 
  kk_ssize_t _x_x74;
  kk_integer_t _x_x75 = kk_integer_dup(n, _ctx); /*int*/
  _x_x74 = kk_std_core_int_ssize__t(_x_x75, _ctx); /*ssize_t*/
  return kk_std_core_vector_vector_alloc_total(_x_x74, kk_std_core_vector_new_vector_init_total_fun76(f, _ctx), _ctx);
}

kk_ssize_t kk_std_core_vector_ssize__t_fs_incr(kk_ssize_t i, kk_context_t* _ctx); /* (i : ssize_t) -> ssize_t */ 

kk_unit_t kk_std_core_vector__mlift_lift_forz_868_10244(kk_function_t action, kk_ssize_t i, kk_ssize_t n, kk_unit_t wild__, kk_context_t* _ctx); /* forall<e> (action : (ssize_t) -> e (), i : ssize_t, n : ssize_t, wild_ : ()) -> e () */ 

kk_unit_t kk_std_core_vector__lift_forz_868(kk_function_t action_0, kk_ssize_t n_0, kk_ssize_t i_0, kk_context_t* _ctx); /* forall<e> (action : (ssize_t) -> e (), n : ssize_t, i : ssize_t) -> e () */ 
 
// Executes `action` `n` times for each integer between [`0`,`n`)  (excluding `n` ).
// If `n <= 0`  the function returns without any call to `action` .

static inline kk_unit_t kk_std_core_vector_forz(kk_ssize_t n, kk_function_t action, kk_context_t* _ctx) { /* forall<e> (n : ssize_t, action : (ssize_t) -> e ()) -> e () */ 
  kk_ssize_t i = (KK_IZ(0)); /*ssize_t*/;
  kk_std_core_vector__lift_forz_868(action, n, i, _ctx); return kk_Unit;
}

kk_unit_t kk_std_core_vector__mlift_lift_vector_init_10176_10245(kk_ssize_t _uniq_i_10122, kk_ssize_t _uniq_n_10121, kk_function_t f, kk_vector_t v, kk_box_t _y_x10213, kk_context_t* _ctx); /* forall<a,e> (ssize_t, ssize_t, f : (int) -> e a, v : vector<a>, a) -> e () */ 

kk_unit_t kk_std_core_vector__lift_vector_init_10176(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_n_10121_0, kk_ssize_t _uniq_i_10122_0, kk_context_t* _ctx); /* forall<a,e> (f : (int) -> e a, v : vector<a>, ssize_t, ssize_t) -> e () */ 
 
// monadic lift

static inline kk_vector_t kk_std_core_vector__mlift_vector_init_10246(kk_vector_t v, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (v : vector<a>, wild_ : ()) -> e vector<a> */ 
  return v;
}

kk_vector_t kk_std_core_vector_vector_init(kk_integer_t n, kk_function_t f, kk_context_t* _ctx); /* forall<a,e> (n : int, f : (int) -> e a) -> e vector<a> */ 

kk_unit_t kk_std_core_vector__mlift_lift_foreach_indexedz_10177_10247(kk_ssize_t _uniq_i_10131, kk_ssize_t _uniq_n_10130, kk_function_t f, kk_vector_t v, kk_unit_t _uniq_x___10133, kk_context_t* _ctx); /* forall<a,e> (ssize_t, ssize_t, f : (ssize_t, a) -> e (), v : vector<a>, ()) -> e () */ 

kk_unit_t kk_std_core_vector__lift_foreach_indexedz_10177(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_n_10130_0, kk_ssize_t _uniq_i_10131_0, kk_context_t* _ctx); /* forall<a,e> (f : (ssize_t, a) -> e (), v : vector<a>, ssize_t, ssize_t) -> e () */ 

static inline kk_unit_t kk_std_core_vector_foreach_indexedz(kk_vector_t v, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (v : vector<a>, f : (ssize_t, a) -> e ()) -> e () */ 
  kk_ssize_t n_10003 = kk_vector_len_borrow(v,kk_context()); /*ssize_t*/;
  kk_ssize_t i = (KK_IZ(0)); /*ssize_t*/;
  kk_std_core_vector__lift_foreach_indexedz_10177(f, v, n_10003, i, _ctx); return kk_Unit;
}

kk_unit_t kk_std_core_vector__mlift_lift_foreach_10178_10248(kk_ssize_t _uniq_i_10140, kk_ssize_t _uniq_n_10139, kk_function_t f, kk_vector_t v, kk_unit_t _uniq_x___10142, kk_context_t* _ctx); /* forall<a,e> (ssize_t, ssize_t, f : (a) -> e (), v : vector<a>, ()) -> e () */ 

kk_unit_t kk_std_core_vector__lift_foreach_10178(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_n_10139_0, kk_ssize_t _uniq_i_10140_0, kk_context_t* _ctx); /* forall<a,e> (f : (a) -> e (), v : vector<a>, ssize_t, ssize_t) -> e () */ 
 
// Invoke a function `f` for each element in a vector `v`

static inline kk_unit_t kk_std_core_vector_foreach(kk_vector_t v, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (v : vector<a>, f : (a) -> e ()) -> e () */ 
  kk_ssize_t n_10003 = kk_vector_len_borrow(v,kk_context()); /*ssize_t*/;
  kk_ssize_t i = (KK_IZ(0)); /*ssize_t*/;
  kk_std_core_vector__lift_foreach_10178(f, v, n_10003, i, _ctx); return kk_Unit;
}

kk_unit_t kk_std_core_vector__mlift_lift_foreach_indexed_10179_10249(kk_ssize_t _uniq_i_10149, kk_ssize_t _uniq_n_10148, kk_function_t f, kk_vector_t v, kk_unit_t _uniq_x___10151, kk_context_t* _ctx); /* forall<a,e> (ssize_t, ssize_t, f : (int, a) -> e (), v : vector<a>, ()) -> e () */ 

kk_unit_t kk_std_core_vector__lift_foreach_indexed_10179(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_n_10148_0, kk_ssize_t _uniq_i_10149_0, kk_context_t* _ctx); /* forall<a,e> (f : (int, a) -> e (), v : vector<a>, ssize_t, ssize_t) -> e () */ 
 
// Invoke a function `f` for each element in a vector `v`

static inline kk_unit_t kk_std_core_vector_foreach_indexed(kk_vector_t v, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (v : vector<a>, f : (int, a) -> e ()) -> e () */ 
  kk_ssize_t n_10003 = kk_vector_len_borrow(v,kk_context()); /*ssize_t*/;
  kk_ssize_t i = (KK_IZ(0)); /*ssize_t*/;
  kk_std_core_vector__lift_foreach_indexed_10179(f, v, n_10003, i, _ctx); return kk_Unit;
}

kk_std_core_types__maybe kk_std_core_vector__mlift_lift_for_whilez_869_10250(kk_function_t action, kk_ssize_t i, kk_ssize_t n, kk_std_core_types__maybe _y_x10229, kk_context_t* _ctx); /* forall<a,e> (action : (ssize_t) -> e maybe<a>, i : ssize_t, n : ssize_t, maybe<a>) -> e maybe<a> */ 

kk_std_core_types__maybe kk_std_core_vector__lift_for_whilez_869(kk_function_t action_0, kk_ssize_t n_0, kk_ssize_t i_0, kk_context_t* _ctx); /* forall<a,e> (action : (ssize_t) -> e maybe<a>, n : ssize_t, i : ssize_t) -> e maybe<a> */ 
 
// Executes `action` at most `n` times for each integer between `0`  upto `n`  (excluding `n` ).
// If `n <= 0`  the function returns without any call to `action` .
// If `action` returns `Just`, the iteration is stopped and the result returned

static inline kk_std_core_types__maybe kk_std_core_vector_for_whilez(kk_ssize_t n, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (n : ssize_t, action : (ssize_t) -> e maybe<a>) -> e maybe<a> */ 
  kk_ssize_t i = (KK_IZ(0)); /*ssize_t*/;
  return kk_std_core_vector__lift_for_whilez_869(action, n, i, _ctx);
}

kk_std_core_types__maybe kk_std_core_vector__mlift_lift_foreach_while_10180_10251(kk_ssize_t _uniq_i_10158, kk_ssize_t _uniq_n_10157, kk_function_t f, kk_vector_t v, kk_std_core_types__maybe _y_x10234, kk_context_t* _ctx); /* forall<a,b,e> (ssize_t, ssize_t, f : (a) -> e maybe<b>, v : vector<a>, maybe<b>) -> e maybe<b> */ 

kk_std_core_types__maybe kk_std_core_vector__lift_foreach_while_10180(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_n_10157_0, kk_ssize_t _uniq_i_10158_0, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> e maybe<b>, v : vector<a>, ssize_t, ssize_t) -> e maybe<b> */ 
 
// Invoke a function `f` for each element in a vector `v`.
// If `f` returns `Just`, the iteration is stopped early and the result is returned.

static inline kk_std_core_types__maybe kk_std_core_vector_foreach_while(kk_vector_t v, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (v : vector<a>, f : (a) -> e maybe<b>) -> e maybe<b> */ 
  kk_ssize_t n_10006 = kk_vector_len_borrow(v,kk_context()); /*ssize_t*/;
  kk_ssize_t i = (KK_IZ(0)); /*ssize_t*/;
  return kk_std_core_vector__lift_foreach_while_10180(f, v, n_10006, i, _ctx);
}

kk_unit_t kk_std_core_vector__mlift_lift_map_10181_10252(kk_ssize_t _uniq_i_10169, kk_ssize_t _uniq_n_10168, kk_function_t f, kk_vector_t v, kk_vector_t w, kk_box_t _y_x10239, kk_context_t* _ctx); /* forall<a,b,e> (ssize_t, ssize_t, f : (a) -> e b, v : vector<a>, w : vector<b>, b) -> e () */ 

kk_unit_t kk_std_core_vector__lift_map_10181(kk_function_t f_0, kk_vector_t v_0, kk_vector_t w_0, kk_ssize_t _uniq_n_10168_0, kk_ssize_t _uniq_i_10169_0, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> e b, v : vector<a>, w : vector<b>, ssize_t, ssize_t) -> e () */ 
 
// monadic lift

static inline kk_vector_t kk_std_core_vector__mlift_map_10253(kk_vector_t w, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (w : vector<a>, wild_ : ()) -> e vector<a> */ 
  return w;
}

kk_vector_t kk_std_core_vector_map(kk_vector_t v, kk_function_t f, kk_context_t* _ctx); /* forall<a,b,e> (v : vector<a>, f : (a) -> e b) -> e vector<b> */ 

kk_std_core_types__list kk_std_core_vector_vlist(kk_vector_t v, kk_std_core_types__optional tail, kk_context_t* _ctx); /* forall<a> (v : vector<a>, tail : ? (list<a>)) -> list<a> */ 
 
// Convert a vector to a list.

static inline kk_std_core_types__list kk_std_core_vector_list(kk_vector_t v, kk_context_t* _ctx) { /* forall<a> (v : vector<a>) -> list<a> */ 
  return kk_std_core_vector_vlist(v, kk_std_core_types__new_None(_ctx), _ctx);
}

kk_vector_t kk_std_core_vector_unvlist(kk_std_core_types__list xs, kk_context_t* _ctx); /* forall<a> (xs : list<a>) -> vector<a> */ 
 
// Convert a list to a vector.

static inline kk_vector_t kk_std_core_vector_list_fs_vector(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> vector<a> */ 
  return kk_std_core_vector_unvlist(xs, _ctx);
}

bool kk_std_core_vector_ssize__t_fs_is_zero(kk_ssize_t i, kk_context_t* _ctx); /* (i : ssize_t) -> bool */ 

kk_ssize_t kk_std_core_vector_ssize__t_fs_decr(kk_ssize_t i, kk_context_t* _ctx); /* (i : ssize_t) -> ssize_t */ 

void kk_std_core_vector__init(kk_context_t* _ctx);


void kk_std_core_vector__done(kk_context_t* _ctx);

#endif // header
