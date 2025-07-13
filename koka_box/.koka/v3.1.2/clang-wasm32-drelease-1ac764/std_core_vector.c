// Koka generated module: std/core/vector, koka version: 3.1.2, platform: 32-bit
#include "std_core_vector.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2024, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

kk_std_core_types__list kk_vector_to_list(kk_vector_t v, kk_std_core_types__list tail, kk_context_t* ctx) {
  // todo: avoid boxed_dup if v is unique
  kk_ssize_t n;
  kk_box_t* p = kk_vector_buf_borrow(v, &n, ctx);
  if (n <= 0) {
    kk_vector_drop(v,ctx);
    return tail;
  }
  kk_std_core_types__list nil  = kk_std_core_types__new_Nil(ctx);
  struct kk_std_core_types_Cons* cons = NULL;
  kk_std_core_types__list list = kk_std_core_types__new_Nil(ctx);
  for( kk_ssize_t i = 0; i < n; i++ ) {
    kk_std_core_types__list hd = kk_std_core_types__new_Cons(kk_reuse_null,0,kk_box_dup(p[i],ctx), nil, ctx);
    if (cons==NULL) {
      list = hd;
    }
    else {
      cons->tail = hd;
    }
    cons = kk_std_core_types__as_Cons(hd,ctx);
  }
  if (cons == NULL) { list = tail; }
               else { cons->tail = tail; }
  kk_vector_drop(v,ctx);
  return list;
}

kk_vector_t kk_list_to_vector(kk_std_core_types__list xs, kk_context_t* ctx) {
  // todo: avoid boxed_dup if xs is unique
  // find the length
  kk_ssize_t len = 0;
  kk_std_core_types__list ys = xs;
  while (kk_std_core_types__is_Cons(ys,ctx)) {
    struct kk_std_core_types_Cons* cons = kk_std_core_types__as_Cons(ys,ctx);
    len++;
    ys = cons->tail;
  }
  // alloc the vector and copy
  kk_box_t* p;
  kk_vector_t v = kk_vector_alloc_uninit(len, &p, ctx);
  ys = xs;
  for( kk_ssize_t i = 0; i < len; i++) {
    struct kk_std_core_types_Cons* cons = kk_std_core_types__as_Cons(ys,ctx);
    ys = cons->tail;
    p[i] = kk_box_dup(cons->head,ctx);
  }
  kk_std_core_types__list_drop(xs,ctx);  // todo: drop while visiting?
  return v;
}


kk_vector_t kk_vector_init_total( kk_ssize_t n, kk_function_t init, kk_context_t* ctx) {
  kk_vector_t v = kk_vector_alloc(n, kk_box_null(), ctx);
  kk_box_t* p = kk_vector_buf_borrow(v, NULL, ctx);
  for(kk_ssize_t i = 0; i < n; i++) {
    kk_function_dup(init,ctx);
    p[i] = kk_function_call(kk_box_t,(kk_function_t,kk_ssize_t,kk_context_t*),init,(init,i,ctx),ctx);
  }
  kk_function_drop(init,ctx);
  return v;
}

 
// Create a new vector of length `n`  with initial elements `init`` .

kk_vector_t kk_std_core_vector_vector_alloc(kk_ssize_t n, kk_box_t init, kk_context_t* _ctx) { /* forall<a,e> (n : ssize_t, init : a) -> e vector<a> */ 
  return kk_vector_alloc(n,init,kk_context());
}
 
// Create a new vector of length `n`  with initial elements given by a total function `f` .

kk_vector_t kk_std_core_vector_vector_alloc_total(kk_ssize_t n, kk_function_t f, kk_context_t* _ctx) { /* forall<a> (n : ssize_t, f : (ssize_t) -> a) -> vector<a> */ 
  return kk_vector_init_total(n,f,kk_context());
}
 
// Return the element at position `index`  in vector `v`.
// Raise an out of bounds exception if `index < 0`  or `index >= v.length`.

kk_box_t kk_std_core_vector__index(kk_vector_t v, kk_integer_t index, kk_context_t* _ctx) { /* forall<a> (v : vector<a>, index : int) -> exn a */ 
  kk_ssize_t idx;
  kk_integer_t _x_x63 = kk_integer_dup(index, _ctx); /*int*/
  idx = kk_std_core_int_ssize__t(_x_x63, _ctx); /*ssize_t*/
  bool _match_x62;
  kk_ssize_t _x_x64 = kk_vector_len_borrow(v,kk_context()); /*ssize_t*/
  _match_x62 = (idx < _x_x64); /*bool*/
  if (_match_x62) {
    return kk_vector_at_borrow(v,idx,kk_context());
  }
  {
    kk_string_t _x_x65;
    kk_define_string_literal(, _s_x66, 19, "index out of bounds", _ctx)
    _x_x65 = kk_string_dup(_s_x66, _ctx); /*string*/
    kk_std_core_types__optional _x_x67 = kk_std_core_types__new_Optional(kk_std_core_exn__exception_info_box(kk_std_core_exn__new_ExnRange(_ctx), _ctx), _ctx); /*? 7*/
    return kk_std_core_exn_throw(_x_x65, _x_x67, _ctx);
  }
}
 
// Return the element at position `index` in vector `v`, or `Nothing` if out of bounds

kk_std_core_types__maybe kk_std_core_vector_at(kk_vector_t v, kk_integer_t index, kk_context_t* _ctx) { /* forall<a> (v : vector<a>, index : int) -> maybe<a> */ 
  kk_ssize_t idx;
  kk_integer_t _x_x68 = kk_integer_dup(index, _ctx); /*int*/
  idx = kk_std_core_int_ssize__t(_x_x68, _ctx); /*ssize_t*/
  bool _match_x61;
  kk_ssize_t _x_x69 = kk_vector_len_borrow(v,kk_context()); /*ssize_t*/
  _match_x61 = (idx < _x_x69); /*bool*/
  if (_match_x61) {
    kk_box_t _x_x70 = kk_vector_at_borrow(v,idx,kk_context()); /*3*/
    return kk_std_core_types__new_Just(_x_x70, _ctx);
  }
  {
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
extern kk_box_t kk_std_core_vector_vector_init_total_fun76(kk_function_t _fself, kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_vector_vector_init_total_fun76__t* _self = kk_function_as(struct kk_std_core_vector_vector_init_total_fun76__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (int) -> 422 */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);}, {}, _ctx)
  kk_integer_t _x_x77 = kk_integer_from_ssize_t(i,kk_context()); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), f, (f, _x_x77, _ctx), _ctx);
}

kk_ssize_t kk_std_core_vector_ssize__t_fs_incr(kk_ssize_t i, kk_context_t* _ctx) { /* (i : ssize_t) -> ssize_t */ 
  return (i + 1);
}
 
// monadic lift

kk_unit_t kk_std_core_vector__mlift_lift_forz_868_10244(kk_function_t action, kk_ssize_t i, kk_ssize_t n, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<e> (action : (ssize_t) -> e (), i : ssize_t, n : ssize_t, wild_ : ()) -> e () */ 
  kk_ssize_t i_0_10000 = kk_std_core_vector_ssize__t_fs_incr(i, _ctx); /*ssize_t*/;
  kk_std_core_vector__lift_forz_868(action, n, i_0_10000, _ctx); return kk_Unit;
}
 
// lifted local: forz, rep


// lift anonymous function
struct kk_std_core_vector__lift_forz_868_fun80__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_ssize_t i_0;
  kk_ssize_t n_0;
};
static kk_box_t kk_std_core_vector__lift_forz_868_fun80(kk_function_t _fself, kk_box_t _b_x3, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector__new_lift_forz_868_fun80(kk_function_t action_0, kk_ssize_t i_0, kk_ssize_t n_0, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_forz_868_fun80__t* _self = kk_function_alloc_as(struct kk_std_core_vector__lift_forz_868_fun80__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector__lift_forz_868_fun80, kk_context());
  _self->action_0 = action_0;
  _self->i_0 = i_0;
  _self->n_0 = n_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector__lift_forz_868_fun80(kk_function_t _fself, kk_box_t _b_x3, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_forz_868_fun80__t* _self = kk_function_as(struct kk_std_core_vector__lift_forz_868_fun80__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (ssize_t) -> 470 () */
  kk_ssize_t i_0 = _self->i_0; /* ssize_t */
  kk_ssize_t n_0 = _self->n_0; /* ssize_t */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_skip_dup(i_0, _ctx);kk_skip_dup(n_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_5 = kk_Unit;
  kk_unit_unbox(_b_x3);
  kk_unit_t _x_x81 = kk_Unit;
  kk_std_core_vector__mlift_lift_forz_868_10244(action_0, i_0, n_0, wild___0_5, _ctx);
  return kk_unit_box(_x_x81);
}

kk_unit_t kk_std_core_vector__lift_forz_868(kk_function_t action_0, kk_ssize_t n_0, kk_ssize_t i_0, kk_context_t* _ctx) { /* forall<e> (action : (ssize_t) -> e (), n : ssize_t, i : ssize_t) -> e () */ 
  kk__tailcall: ;
  bool _match_x59 = (i_0 < n_0); /*bool*/;
  if (_match_x59) {
    kk_unit_t x_10254 = kk_Unit;
    kk_function_t _x_x78 = kk_function_dup(action_0, _ctx); /*(ssize_t) -> 470 ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_ssize_t, kk_context_t*), _x_x78, (_x_x78, i_0, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x79 = kk_std_core_hnd_yield_extend(kk_std_core_vector__new_lift_forz_868_fun80(action_0, i_0, n_0, _ctx), _ctx); /*2978*/
      kk_unit_unbox(_x_x79); return kk_Unit;
    }
    {
      kk_ssize_t i_0_10000_0 = kk_std_core_vector_ssize__t_fs_incr(i_0, _ctx); /*ssize_t*/;
      { // tailcall
        i_0 = i_0_10000_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(action_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_unit_t kk_std_core_vector__mlift_lift_vector_init_10176_10245(kk_ssize_t _uniq_i_10122, kk_ssize_t _uniq_n_10121, kk_function_t f, kk_vector_t v, kk_box_t _y_x10213, kk_context_t* _ctx) { /* forall<a,e> (ssize_t, ssize_t, f : (int) -> e a, v : vector<a>, a) -> e () */ 
  kk_unit_t _uniq_x___10124 = kk_Unit;
  kk_vector_t _x_x82 = kk_vector_dup(v, _ctx); /*vector<512>*/
  kk_vector_unsafe_assign(_x_x82,_uniq_i_10122,_y_x10213,kk_context());
  kk_ssize_t _uniq_i_0_10000_10125 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10122, _ctx); /*ssize_t*/;
  kk_std_core_vector__lift_vector_init_10176(f, v, _uniq_n_10121, _uniq_i_0_10000_10125, _ctx); return kk_Unit;
}
 
// lifted local: vector-init, @spec-x10127
// specialized: std/core/vector/@lift-forz@868, on parameters @uniq-action@10120, using:
// @uniq-action@10120 = fn<(e :: E)>(i@0: ssize_t){
//   std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, i : ssize_t, x : a) -> (),(v : (vector :: V -> V)<a>, i : ssize_t, x : a) -> (e :: E) ()>((std/core/vector/unsafe-assign<a>))(v, i@0, (f((std/core/types/@open<(total :: E),(e :: E),(i : ssize_t) -> int,(i : ssize_t) -> (e :: E) int>(std/core/int/ssize_t/int)(i@0)))));
// }


// lift anonymous function
struct kk_std_core_vector__lift_vector_init_10176_fun86__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_vector_t v_0;
  kk_ssize_t _uniq_i_10122_0;
  kk_ssize_t _uniq_n_10121_0;
};
static kk_box_t kk_std_core_vector__lift_vector_init_10176_fun86(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector__new_lift_vector_init_10176_fun86(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_i_10122_0, kk_ssize_t _uniq_n_10121_0, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_vector_init_10176_fun86__t* _self = kk_function_alloc_as(struct kk_std_core_vector__lift_vector_init_10176_fun86__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector__lift_vector_init_10176_fun86, kk_context());
  _self->f_0 = f_0;
  _self->v_0 = v_0;
  _self->_uniq_i_10122_0 = _uniq_i_10122_0;
  _self->_uniq_n_10121_0 = _uniq_n_10121_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector__lift_vector_init_10176_fun86(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_vector_init_10176_fun86__t* _self = kk_function_as(struct kk_std_core_vector__lift_vector_init_10176_fun86__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (int) -> 513 512 */
  kk_vector_t v_0 = _self->v_0; /* vector<512> */
  kk_ssize_t _uniq_i_10122_0 = _self->_uniq_i_10122_0; /* ssize_t */
  kk_ssize_t _uniq_n_10121_0 = _self->_uniq_n_10121_0; /* ssize_t */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_vector_dup(v_0, _ctx);kk_skip_dup(_uniq_i_10122_0, _ctx);kk_skip_dup(_uniq_n_10121_0, _ctx);}, {}, _ctx)
  kk_box_t _y_x10213_0_9 = _b_x7; /*512*/;
  kk_unit_t _x_x87 = kk_Unit;
  kk_std_core_vector__mlift_lift_vector_init_10176_10245(_uniq_i_10122_0, _uniq_n_10121_0, f_0, v_0, _y_x10213_0_9, _ctx);
  return kk_unit_box(_x_x87);
}

kk_unit_t kk_std_core_vector__lift_vector_init_10176(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_n_10121_0, kk_ssize_t _uniq_i_10122_0, kk_context_t* _ctx) { /* forall<a,e> (f : (int) -> e a, v : vector<a>, ssize_t, ssize_t) -> e () */ 
  kk__tailcall: ;
  bool _match_x57 = (_uniq_i_10122_0 < _uniq_n_10121_0); /*bool*/;
  if (_match_x57) {
    kk_box_t x_10257;
    kk_function_t _x_x84 = kk_function_dup(f_0, _ctx); /*(int) -> 513 512*/
    kk_integer_t _x_x83 = kk_integer_from_ssize_t(_uniq_i_10122_0,kk_context()); /*int*/
    x_10257 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x84, (_x_x84, _x_x83, _ctx), _ctx); /*512*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_10257, _ctx);
      kk_box_t _x_x85 = kk_std_core_hnd_yield_extend(kk_std_core_vector__new_lift_vector_init_10176_fun86(f_0, v_0, _uniq_i_10122_0, _uniq_n_10121_0, _ctx), _ctx); /*2978*/
      kk_unit_unbox(_x_x85); return kk_Unit;
    }
    {
      kk_unit_t _uniq_x___10124_0 = kk_Unit;
      kk_vector_t _x_x88 = kk_vector_dup(v_0, _ctx); /*vector<512>*/
      kk_vector_unsafe_assign(_x_x88,_uniq_i_10122_0,x_10257,kk_context());
      kk_ssize_t _uniq_i_0_10000_10125_0 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10122_0, _ctx); /*ssize_t*/;
      { // tailcall
        _uniq_i_10122_0 = _uniq_i_0_10000_10125_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_vector_drop(v_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// Create a new vector of length `n`  with initial elements given by function `f` which can have a control effect.


// lift anonymous function
struct kk_std_core_vector_vector_init_fun92__t {
  struct kk_function_s _base;
  kk_vector_t v;
};
static kk_box_t kk_std_core_vector_vector_init_fun92(kk_function_t _fself, kk_box_t _b_x11, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector_new_vector_init_fun92(kk_vector_t v, kk_context_t* _ctx) {
  struct kk_std_core_vector_vector_init_fun92__t* _self = kk_function_alloc_as(struct kk_std_core_vector_vector_init_fun92__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector_vector_init_fun92, kk_context());
  _self->v = v;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector_vector_init_fun92(kk_function_t _fself, kk_box_t _b_x11, kk_context_t* _ctx) {
  struct kk_std_core_vector_vector_init_fun92__t* _self = kk_function_as(struct kk_std_core_vector_vector_init_fun92__t*, _fself, _ctx);
  kk_vector_t v = _self->v; /* vector<512> */
  kk_drop_match(_self, {kk_vector_dup(v, _ctx);}, {}, _ctx)
  kk_unit_t wild___13 = kk_Unit;
  kk_unit_unbox(_b_x11);
  return kk_vector_box(v, _ctx);
}

kk_vector_t kk_std_core_vector_vector_init(kk_integer_t n, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (n : int, f : (int) -> e a) -> e vector<a> */ 
  kk_ssize_t len;
  kk_integer_t _x_x89 = kk_integer_dup(n, _ctx); /*int*/
  len = kk_std_core_int_ssize__t(_x_x89, _ctx); /*ssize_t*/
  kk_vector_t v = kk_vector_alloc(len,kk_box_null(),kk_context()); /*vector<512>*/;
  kk_ssize_t i = (KK_IZ(0)); /*ssize_t*/;
  kk_unit_t x_10260 = kk_Unit;
  kk_vector_t _x_x90 = kk_vector_dup(v, _ctx); /*vector<512>*/
  kk_std_core_vector__lift_vector_init_10176(f, _x_x90, len, i, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x91 = kk_std_core_hnd_yield_extend(kk_std_core_vector_new_vector_init_fun92(v, _ctx), _ctx); /*2978*/
    return kk_vector_unbox(_x_x91, _ctx);
  }
  {
    return v;
  }
}
 
// monadic lift

kk_unit_t kk_std_core_vector__mlift_lift_foreach_indexedz_10177_10247(kk_ssize_t _uniq_i_10131, kk_ssize_t _uniq_n_10130, kk_function_t f, kk_vector_t v, kk_unit_t _uniq_x___10133, kk_context_t* _ctx) { /* forall<a,e> (ssize_t, ssize_t, f : (ssize_t, a) -> e (), v : vector<a>, ()) -> e () */ 
  kk_ssize_t _uniq_i_0_10000_10134 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10131, _ctx); /*ssize_t*/;
  kk_std_core_vector__lift_foreach_indexedz_10177(f, v, _uniq_n_10130, _uniq_i_0_10000_10134, _ctx); return kk_Unit;
}
 
// lifted local: foreach-indexedz, @spec-x10136
// specialized: std/core/vector/@lift-forz@868, on parameters @uniq-action@10129, using:
// @uniq-action@10129 = fn<(e :: E)>(i@0: ssize_t){
//   f(i@0, (std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, index : ssize_t) -> a,(v : (vector :: V -> V)<a>, index : ssize_t) -> (e :: E) a>((std/core/vector/unsafe-idx<a>))(v, i@0)));
// }


// lift anonymous function
struct kk_std_core_vector__lift_foreach_indexedz_10177_fun96__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_vector_t v_0;
  kk_ssize_t _uniq_i_10131_0;
  kk_ssize_t _uniq_n_10130_0;
};
static kk_box_t kk_std_core_vector__lift_foreach_indexedz_10177_fun96(kk_function_t _fself, kk_box_t _b_x15, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector__new_lift_foreach_indexedz_10177_fun96(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_i_10131_0, kk_ssize_t _uniq_n_10130_0, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_foreach_indexedz_10177_fun96__t* _self = kk_function_alloc_as(struct kk_std_core_vector__lift_foreach_indexedz_10177_fun96__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector__lift_foreach_indexedz_10177_fun96, kk_context());
  _self->f_0 = f_0;
  _self->v_0 = v_0;
  _self->_uniq_i_10131_0 = _uniq_i_10131_0;
  _self->_uniq_n_10130_0 = _uniq_n_10130_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector__lift_foreach_indexedz_10177_fun96(kk_function_t _fself, kk_box_t _b_x15, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_foreach_indexedz_10177_fun96__t* _self = kk_function_as(struct kk_std_core_vector__lift_foreach_indexedz_10177_fun96__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (ssize_t, 549) -> 550 () */
  kk_vector_t v_0 = _self->v_0; /* vector<549> */
  kk_ssize_t _uniq_i_10131_0 = _self->_uniq_i_10131_0; /* ssize_t */
  kk_ssize_t _uniq_n_10130_0 = _self->_uniq_n_10130_0; /* ssize_t */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_vector_dup(v_0, _ctx);kk_skip_dup(_uniq_i_10131_0, _ctx);kk_skip_dup(_uniq_n_10130_0, _ctx);}, {}, _ctx)
  kk_unit_t _uniq_x___10133_0_17 = kk_Unit;
  kk_unit_unbox(_b_x15);
  kk_unit_t _x_x97 = kk_Unit;
  kk_std_core_vector__mlift_lift_foreach_indexedz_10177_10247(_uniq_i_10131_0, _uniq_n_10130_0, f_0, v_0, _uniq_x___10133_0_17, _ctx);
  return kk_unit_box(_x_x97);
}

kk_unit_t kk_std_core_vector__lift_foreach_indexedz_10177(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_n_10130_0, kk_ssize_t _uniq_i_10131_0, kk_context_t* _ctx) { /* forall<a,e> (f : (ssize_t, a) -> e (), v : vector<a>, ssize_t, ssize_t) -> e () */ 
  kk__tailcall: ;
  bool _match_x54 = (_uniq_i_10131_0 < _uniq_n_10130_0); /*bool*/;
  if (_match_x54) {
    kk_unit_t x_10265 = kk_Unit;
    kk_function_t _x_x94 = kk_function_dup(f_0, _ctx); /*(ssize_t, 549) -> 550 ()*/
    kk_box_t _x_x93 = kk_vector_at_borrow(v_0,_uniq_i_10131_0,kk_context()); /*3*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_ssize_t, kk_box_t, kk_context_t*), _x_x94, (_x_x94, _uniq_i_10131_0, _x_x93, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x95 = kk_std_core_hnd_yield_extend(kk_std_core_vector__new_lift_foreach_indexedz_10177_fun96(f_0, v_0, _uniq_i_10131_0, _uniq_n_10130_0, _ctx), _ctx); /*2978*/
      kk_unit_unbox(_x_x95); return kk_Unit;
    }
    {
      kk_ssize_t _uniq_i_0_10000_10134_0 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10131_0, _ctx); /*ssize_t*/;
      { // tailcall
        _uniq_i_10131_0 = _uniq_i_0_10000_10134_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_vector_drop(v_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_unit_t kk_std_core_vector__mlift_lift_foreach_10178_10248(kk_ssize_t _uniq_i_10140, kk_ssize_t _uniq_n_10139, kk_function_t f, kk_vector_t v, kk_unit_t _uniq_x___10142, kk_context_t* _ctx) { /* forall<a,e> (ssize_t, ssize_t, f : (a) -> e (), v : vector<a>, ()) -> e () */ 
  kk_ssize_t _uniq_i_0_10000_10143 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10140, _ctx); /*ssize_t*/;
  kk_std_core_vector__lift_foreach_10178(f, v, _uniq_n_10139, _uniq_i_0_10000_10143, _ctx); return kk_Unit;
}
 
// lifted local: foreach, @spec-x10145
// specialized: std/core/vector/@lift-forz@868, on parameters @uniq-action@10138, using:
// @uniq-action@10138 = fn<(e :: E)>(i@0: ssize_t){
//   val x@10015 : a
//         = std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, index : ssize_t) -> a,(v : (vector :: V -> V)<a>, index : ssize_t) -> (e :: E) a>((std/core/vector/unsafe-idx<a>))(v, i@0);
//   f(x@10015);
// }


// lift anonymous function
struct kk_std_core_vector__lift_foreach_10178_fun100__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_vector_t v_0;
  kk_ssize_t _uniq_i_10140_0;
  kk_ssize_t _uniq_n_10139_0;
};
static kk_box_t kk_std_core_vector__lift_foreach_10178_fun100(kk_function_t _fself, kk_box_t _b_x19, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector__new_lift_foreach_10178_fun100(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_i_10140_0, kk_ssize_t _uniq_n_10139_0, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_foreach_10178_fun100__t* _self = kk_function_alloc_as(struct kk_std_core_vector__lift_foreach_10178_fun100__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector__lift_foreach_10178_fun100, kk_context());
  _self->f_0 = f_0;
  _self->v_0 = v_0;
  _self->_uniq_i_10140_0 = _uniq_i_10140_0;
  _self->_uniq_n_10139_0 = _uniq_n_10139_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector__lift_foreach_10178_fun100(kk_function_t _fself, kk_box_t _b_x19, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_foreach_10178_fun100__t* _self = kk_function_as(struct kk_std_core_vector__lift_foreach_10178_fun100__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (575) -> 576 () */
  kk_vector_t v_0 = _self->v_0; /* vector<575> */
  kk_ssize_t _uniq_i_10140_0 = _self->_uniq_i_10140_0; /* ssize_t */
  kk_ssize_t _uniq_n_10139_0 = _self->_uniq_n_10139_0; /* ssize_t */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_vector_dup(v_0, _ctx);kk_skip_dup(_uniq_i_10140_0, _ctx);kk_skip_dup(_uniq_n_10139_0, _ctx);}, {}, _ctx)
  kk_unit_t _uniq_x___10142_0_21 = kk_Unit;
  kk_unit_unbox(_b_x19);
  kk_unit_t _x_x101 = kk_Unit;
  kk_std_core_vector__mlift_lift_foreach_10178_10248(_uniq_i_10140_0, _uniq_n_10139_0, f_0, v_0, _uniq_x___10142_0_21, _ctx);
  return kk_unit_box(_x_x101);
}

kk_unit_t kk_std_core_vector__lift_foreach_10178(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_n_10139_0, kk_ssize_t _uniq_i_10140_0, kk_context_t* _ctx) { /* forall<a,e> (f : (a) -> e (), v : vector<a>, ssize_t, ssize_t) -> e () */ 
  kk__tailcall: ;
  bool _match_x52 = (_uniq_i_10140_0 < _uniq_n_10139_0); /*bool*/;
  if (_match_x52) {
    kk_box_t x_10015 = kk_vector_at_borrow(v_0,_uniq_i_10140_0,kk_context()); /*575*/;
    kk_unit_t x_10268 = kk_Unit;
    kk_function_t _x_x98 = kk_function_dup(f_0, _ctx); /*(575) -> 576 ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x98, (_x_x98, x_10015, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x99 = kk_std_core_hnd_yield_extend(kk_std_core_vector__new_lift_foreach_10178_fun100(f_0, v_0, _uniq_i_10140_0, _uniq_n_10139_0, _ctx), _ctx); /*2978*/
      kk_unit_unbox(_x_x99); return kk_Unit;
    }
    {
      kk_ssize_t _uniq_i_0_10000_10143_0 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10140_0, _ctx); /*ssize_t*/;
      { // tailcall
        _uniq_i_10140_0 = _uniq_i_0_10000_10143_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_vector_drop(v_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_unit_t kk_std_core_vector__mlift_lift_foreach_indexed_10179_10249(kk_ssize_t _uniq_i_10149, kk_ssize_t _uniq_n_10148, kk_function_t f, kk_vector_t v, kk_unit_t _uniq_x___10151, kk_context_t* _ctx) { /* forall<a,e> (ssize_t, ssize_t, f : (int, a) -> e (), v : vector<a>, ()) -> e () */ 
  kk_ssize_t _uniq_i_0_10000_10152 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10149, _ctx); /*ssize_t*/;
  kk_std_core_vector__lift_foreach_indexed_10179(f, v, _uniq_n_10148, _uniq_i_0_10000_10152, _ctx); return kk_Unit;
}
 
// lifted local: foreach-indexed, @spec-x10154
// specialized: std/core/vector/@lift-forz@868, on parameters @uniq-action@10147, using:
// @uniq-action@10147 = fn<(e :: E)>(i@0: ssize_t){
//   val x@10017 : a
//         = std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, index : ssize_t) -> a,(v : (vector :: V -> V)<a>, index : ssize_t) -> (e :: E) a>((std/core/vector/unsafe-idx<a>))(v, i@0);
//   f((std/core/types/@open<(total :: E),(e :: E),(i : ssize_t) -> int,(i : ssize_t) -> (e :: E) int>(std/core/int/ssize_t/int)(i@0)), x@10017);
// }


// lift anonymous function
struct kk_std_core_vector__lift_foreach_indexed_10179_fun105__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_vector_t v_0;
  kk_ssize_t _uniq_i_10149_0;
  kk_ssize_t _uniq_n_10148_0;
};
static kk_box_t kk_std_core_vector__lift_foreach_indexed_10179_fun105(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector__new_lift_foreach_indexed_10179_fun105(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_i_10149_0, kk_ssize_t _uniq_n_10148_0, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_foreach_indexed_10179_fun105__t* _self = kk_function_alloc_as(struct kk_std_core_vector__lift_foreach_indexed_10179_fun105__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector__lift_foreach_indexed_10179_fun105, kk_context());
  _self->f_0 = f_0;
  _self->v_0 = v_0;
  _self->_uniq_i_10149_0 = _uniq_i_10149_0;
  _self->_uniq_n_10148_0 = _uniq_n_10148_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector__lift_foreach_indexed_10179_fun105(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_foreach_indexed_10179_fun105__t* _self = kk_function_as(struct kk_std_core_vector__lift_foreach_indexed_10179_fun105__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (int, 605) -> 606 () */
  kk_vector_t v_0 = _self->v_0; /* vector<605> */
  kk_ssize_t _uniq_i_10149_0 = _self->_uniq_i_10149_0; /* ssize_t */
  kk_ssize_t _uniq_n_10148_0 = _self->_uniq_n_10148_0; /* ssize_t */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_vector_dup(v_0, _ctx);kk_skip_dup(_uniq_i_10149_0, _ctx);kk_skip_dup(_uniq_n_10148_0, _ctx);}, {}, _ctx)
  kk_unit_t _uniq_x___10151_0_25 = kk_Unit;
  kk_unit_unbox(_b_x23);
  kk_unit_t _x_x106 = kk_Unit;
  kk_std_core_vector__mlift_lift_foreach_indexed_10179_10249(_uniq_i_10149_0, _uniq_n_10148_0, f_0, v_0, _uniq_x___10151_0_25, _ctx);
  return kk_unit_box(_x_x106);
}

kk_unit_t kk_std_core_vector__lift_foreach_indexed_10179(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_n_10148_0, kk_ssize_t _uniq_i_10149_0, kk_context_t* _ctx) { /* forall<a,e> (f : (int, a) -> e (), v : vector<a>, ssize_t, ssize_t) -> e () */ 
  kk__tailcall: ;
  bool _match_x50 = (_uniq_i_10149_0 < _uniq_n_10148_0); /*bool*/;
  if (_match_x50) {
    kk_box_t x_10017 = kk_vector_at_borrow(v_0,_uniq_i_10149_0,kk_context()); /*605*/;
    kk_unit_t x_10271 = kk_Unit;
    kk_function_t _x_x103 = kk_function_dup(f_0, _ctx); /*(int, 605) -> 606 ()*/
    kk_integer_t _x_x102 = kk_integer_from_ssize_t(_uniq_i_10149_0,kk_context()); /*int*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x_x103, (_x_x103, _x_x102, x_10017, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x104 = kk_std_core_hnd_yield_extend(kk_std_core_vector__new_lift_foreach_indexed_10179_fun105(f_0, v_0, _uniq_i_10149_0, _uniq_n_10148_0, _ctx), _ctx); /*2978*/
      kk_unit_unbox(_x_x104); return kk_Unit;
    }
    {
      kk_ssize_t _uniq_i_0_10000_10152_0 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10149_0, _ctx); /*ssize_t*/;
      { // tailcall
        _uniq_i_10149_0 = _uniq_i_0_10000_10152_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_vector_drop(v_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_vector__mlift_lift_for_whilez_869_10250(kk_function_t action, kk_ssize_t i, kk_ssize_t n, kk_std_core_types__maybe _y_x10229, kk_context_t* _ctx) { /* forall<a,e> (action : (ssize_t) -> e maybe<a>, i : ssize_t, n : ssize_t, maybe<a>) -> e maybe<a> */ 
  if (kk_std_core_types__is_Nothing(_y_x10229, _ctx)) {
    kk_ssize_t i_0_10005 = kk_std_core_vector_ssize__t_fs_incr(i, _ctx); /*ssize_t*/;
    return kk_std_core_vector__lift_for_whilez_869(action, n, i_0_10005, _ctx);
  }
  {
    kk_box_t x = _y_x10229._cons.Just.value;
    kk_function_drop(action, _ctx);
    return kk_std_core_types__new_Just(x, _ctx);
  }
}
 
// lifted local: for-whilez, rep


// lift anonymous function
struct kk_std_core_vector__lift_for_whilez_869_fun109__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_ssize_t i_0;
  kk_ssize_t n_0;
};
static kk_box_t kk_std_core_vector__lift_for_whilez_869_fun109(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector__new_lift_for_whilez_869_fun109(kk_function_t action_0, kk_ssize_t i_0, kk_ssize_t n_0, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_for_whilez_869_fun109__t* _self = kk_function_alloc_as(struct kk_std_core_vector__lift_for_whilez_869_fun109__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector__lift_for_whilez_869_fun109, kk_context());
  _self->action_0 = action_0;
  _self->i_0 = i_0;
  _self->n_0 = n_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector__lift_for_whilez_869_fun109(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_for_whilez_869_fun109__t* _self = kk_function_as(struct kk_std_core_vector__lift_for_whilez_869_fun109__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (ssize_t) -> 665 maybe<664> */
  kk_ssize_t i_0 = _self->i_0; /* ssize_t */
  kk_ssize_t n_0 = _self->n_0; /* ssize_t */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_skip_dup(i_0, _ctx);kk_skip_dup(n_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10229_0_29 = kk_std_core_types__maybe_unbox(_b_x27, KK_OWNED, _ctx); /*maybe<664>*/;
  kk_std_core_types__maybe _x_x110 = kk_std_core_vector__mlift_lift_for_whilez_869_10250(action_0, i_0, n_0, _y_x10229_0_29, _ctx); /*maybe<664>*/
  return kk_std_core_types__maybe_box(_x_x110, _ctx);
}

kk_std_core_types__maybe kk_std_core_vector__lift_for_whilez_869(kk_function_t action_0, kk_ssize_t n_0, kk_ssize_t i_0, kk_context_t* _ctx) { /* forall<a,e> (action : (ssize_t) -> e maybe<a>, n : ssize_t, i : ssize_t) -> e maybe<a> */ 
  kk__tailcall: ;
  bool _match_x48 = (i_0 < n_0); /*bool*/;
  if (_match_x48) {
    kk_std_core_types__maybe x_0_10274;
    kk_function_t _x_x107 = kk_function_dup(action_0, _ctx); /*(ssize_t) -> 665 maybe<664>*/
    x_0_10274 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_ssize_t, kk_context_t*), _x_x107, (_x_x107, i_0, _ctx), _ctx); /*maybe<664>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_10274, _ctx);
      kk_box_t _x_x108 = kk_std_core_hnd_yield_extend(kk_std_core_vector__new_lift_for_whilez_869_fun109(action_0, i_0, n_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__maybe_unbox(_x_x108, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_0_10274, _ctx)) {
      kk_ssize_t i_0_10005_0 = kk_std_core_vector_ssize__t_fs_incr(i_0, _ctx); /*ssize_t*/;
      { // tailcall
        i_0 = i_0_10005_0;
        goto kk__tailcall;
      }
    }
    {
      kk_box_t x_1 = x_0_10274._cons.Just.value;
      kk_function_drop(action_0, _ctx);
      return kk_std_core_types__new_Just(x_1, _ctx);
    }
  }
  {
    kk_function_drop(action_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_vector__mlift_lift_foreach_while_10180_10251(kk_ssize_t _uniq_i_10158, kk_ssize_t _uniq_n_10157, kk_function_t f, kk_vector_t v, kk_std_core_types__maybe _y_x10234, kk_context_t* _ctx) { /* forall<a,b,e> (ssize_t, ssize_t, f : (a) -> e maybe<b>, v : vector<a>, maybe<b>) -> e maybe<b> */ 
  if (kk_std_core_types__is_Nothing(_y_x10234, _ctx)) {
    kk_ssize_t _uniq_i_0_10005_10161 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10158, _ctx); /*ssize_t*/;
    return kk_std_core_vector__lift_foreach_while_10180(f, v, _uniq_n_10157, _uniq_i_0_10005_10161, _ctx);
  }
  {
    kk_box_t _uniq_x_10163 = _y_x10234._cons.Just.value;
    kk_vector_drop(v, _ctx);
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Just(_uniq_x_10163, _ctx);
  }
}
 
// lifted local: foreach-while, @spec-x10165
// specialized: std/core/vector/@lift-for-whilez@869, on parameters @uniq-action@10156, using:
// @uniq-action@10156 = fn<(e :: E)>(i@0: ssize_t){
//   f((std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, index : ssize_t) -> a,(v : (vector :: V -> V)<a>, index : ssize_t) -> (e :: E) a>((std/core/vector/unsafe-idx<a>))(v, i@0)));
// }


// lift anonymous function
struct kk_std_core_vector__lift_foreach_while_10180_fun114__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_vector_t v_0;
  kk_ssize_t _uniq_i_10158_0;
  kk_ssize_t _uniq_n_10157_0;
};
static kk_box_t kk_std_core_vector__lift_foreach_while_10180_fun114(kk_function_t _fself, kk_box_t _b_x31, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector__new_lift_foreach_while_10180_fun114(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_i_10158_0, kk_ssize_t _uniq_n_10157_0, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_foreach_while_10180_fun114__t* _self = kk_function_alloc_as(struct kk_std_core_vector__lift_foreach_while_10180_fun114__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector__lift_foreach_while_10180_fun114, kk_context());
  _self->f_0 = f_0;
  _self->v_0 = v_0;
  _self->_uniq_i_10158_0 = _uniq_i_10158_0;
  _self->_uniq_n_10157_0 = _uniq_n_10157_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector__lift_foreach_while_10180_fun114(kk_function_t _fself, kk_box_t _b_x31, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_foreach_while_10180_fun114__t* _self = kk_function_as(struct kk_std_core_vector__lift_foreach_while_10180_fun114__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (706) -> 708 maybe<707> */
  kk_vector_t v_0 = _self->v_0; /* vector<706> */
  kk_ssize_t _uniq_i_10158_0 = _self->_uniq_i_10158_0; /* ssize_t */
  kk_ssize_t _uniq_n_10157_0 = _self->_uniq_n_10157_0; /* ssize_t */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_vector_dup(v_0, _ctx);kk_skip_dup(_uniq_i_10158_0, _ctx);kk_skip_dup(_uniq_n_10157_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10234_0_33 = kk_std_core_types__maybe_unbox(_b_x31, KK_OWNED, _ctx); /*maybe<707>*/;
  kk_std_core_types__maybe _x_x115 = kk_std_core_vector__mlift_lift_foreach_while_10180_10251(_uniq_i_10158_0, _uniq_n_10157_0, f_0, v_0, _y_x10234_0_33, _ctx); /*maybe<707>*/
  return kk_std_core_types__maybe_box(_x_x115, _ctx);
}

kk_std_core_types__maybe kk_std_core_vector__lift_foreach_while_10180(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_n_10157_0, kk_ssize_t _uniq_i_10158_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e maybe<b>, v : vector<a>, ssize_t, ssize_t) -> e maybe<b> */ 
  kk__tailcall: ;
  bool _match_x46 = (_uniq_i_10158_0 < _uniq_n_10157_0); /*bool*/;
  if (_match_x46) {
    kk_std_core_types__maybe x_10277;
    kk_function_t _x_x112 = kk_function_dup(f_0, _ctx); /*(706) -> 708 maybe<707>*/
    kk_box_t _x_x111 = kk_vector_at_borrow(v_0,_uniq_i_10158_0,kk_context()); /*3*/
    x_10277 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x112, (_x_x112, _x_x111, _ctx), _ctx); /*maybe<707>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_10277, _ctx);
      kk_box_t _x_x113 = kk_std_core_hnd_yield_extend(kk_std_core_vector__new_lift_foreach_while_10180_fun114(f_0, v_0, _uniq_i_10158_0, _uniq_n_10157_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__maybe_unbox(_x_x113, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_10277, _ctx)) {
      kk_ssize_t _uniq_i_0_10005_10161_0 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10158_0, _ctx); /*ssize_t*/;
      { // tailcall
        _uniq_i_10158_0 = _uniq_i_0_10005_10161_0;
        goto kk__tailcall;
      }
    }
    {
      kk_box_t _uniq_x_10163_0 = x_10277._cons.Just.value;
      kk_vector_drop(v_0, _ctx);
      kk_function_drop(f_0, _ctx);
      return kk_std_core_types__new_Just(_uniq_x_10163_0, _ctx);
    }
  }
  {
    kk_vector_drop(v_0, _ctx);
    kk_function_drop(f_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// monadic lift

kk_unit_t kk_std_core_vector__mlift_lift_map_10181_10252(kk_ssize_t _uniq_i_10169, kk_ssize_t _uniq_n_10168, kk_function_t f, kk_vector_t v, kk_vector_t w, kk_box_t _y_x10239, kk_context_t* _ctx) { /* forall<a,b,e> (ssize_t, ssize_t, f : (a) -> e b, v : vector<a>, w : vector<b>, b) -> e () */ 
  kk_unit_t _uniq_x___10171 = kk_Unit;
  kk_vector_t _x_x116 = kk_vector_dup(w, _ctx); /*vector<765>*/
  kk_vector_unsafe_assign(_x_x116,_uniq_i_10169,_y_x10239,kk_context());
  kk_ssize_t _uniq_i_0_10000_10172 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10169, _ctx); /*ssize_t*/;
  kk_std_core_vector__lift_map_10181(f, v, w, _uniq_n_10168, _uniq_i_0_10000_10172, _ctx); return kk_Unit;
}
 
// lifted local: map, @spec-x10174
// specialized: std/core/vector/@lift-forz@868, on parameters @uniq-action@10167, using:
// @uniq-action@10167 = fn<(e :: E)>(i@0: ssize_t){
//   val x@10019 : a
//         = std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, index : ssize_t) -> a,(v : (vector :: V -> V)<a>, index : ssize_t) -> (e :: E) a>((std/core/vector/unsafe-idx<a>))(v, i@0);
//   std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, i : ssize_t, x : a) -> (),(v : (vector :: V -> V)<a>, i : ssize_t, x : a) -> (e :: E) ()>((std/core/vector/unsafe-assign<a>))(w, i@0, (f(x@10019)));
// }


// lift anonymous function
struct kk_std_core_vector__lift_map_10181_fun119__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_vector_t v_0;
  kk_vector_t w_0;
  kk_ssize_t _uniq_i_10169_0;
  kk_ssize_t _uniq_n_10168_0;
};
static kk_box_t kk_std_core_vector__lift_map_10181_fun119(kk_function_t _fself, kk_box_t _b_x35, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector__new_lift_map_10181_fun119(kk_function_t f_0, kk_vector_t v_0, kk_vector_t w_0, kk_ssize_t _uniq_i_10169_0, kk_ssize_t _uniq_n_10168_0, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_map_10181_fun119__t* _self = kk_function_alloc_as(struct kk_std_core_vector__lift_map_10181_fun119__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector__lift_map_10181_fun119, kk_context());
  _self->f_0 = f_0;
  _self->v_0 = v_0;
  _self->w_0 = w_0;
  _self->_uniq_i_10169_0 = _uniq_i_10169_0;
  _self->_uniq_n_10168_0 = _uniq_n_10168_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector__lift_map_10181_fun119(kk_function_t _fself, kk_box_t _b_x35, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_map_10181_fun119__t* _self = kk_function_as(struct kk_std_core_vector__lift_map_10181_fun119__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (764) -> 766 765 */
  kk_vector_t v_0 = _self->v_0; /* vector<764> */
  kk_vector_t w_0 = _self->w_0; /* vector<765> */
  kk_ssize_t _uniq_i_10169_0 = _self->_uniq_i_10169_0; /* ssize_t */
  kk_ssize_t _uniq_n_10168_0 = _self->_uniq_n_10168_0; /* ssize_t */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_vector_dup(v_0, _ctx);kk_vector_dup(w_0, _ctx);kk_skip_dup(_uniq_i_10169_0, _ctx);kk_skip_dup(_uniq_n_10168_0, _ctx);}, {}, _ctx)
  kk_box_t _y_x10239_0_37 = _b_x35; /*765*/;
  kk_unit_t _x_x120 = kk_Unit;
  kk_std_core_vector__mlift_lift_map_10181_10252(_uniq_i_10169_0, _uniq_n_10168_0, f_0, v_0, w_0, _y_x10239_0_37, _ctx);
  return kk_unit_box(_x_x120);
}

kk_unit_t kk_std_core_vector__lift_map_10181(kk_function_t f_0, kk_vector_t v_0, kk_vector_t w_0, kk_ssize_t _uniq_n_10168_0, kk_ssize_t _uniq_i_10169_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, v : vector<a>, w : vector<b>, ssize_t, ssize_t) -> e () */ 
  kk__tailcall: ;
  bool _match_x44 = (_uniq_i_10169_0 < _uniq_n_10168_0); /*bool*/;
  if (_match_x44) {
    kk_box_t x_10019 = kk_vector_at_borrow(v_0,_uniq_i_10169_0,kk_context()); /*764*/;
    kk_box_t x_10280;
    kk_function_t _x_x117 = kk_function_dup(f_0, _ctx); /*(764) -> 766 765*/
    x_10280 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x117, (_x_x117, x_10019, _ctx), _ctx); /*765*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_10280, _ctx);
      kk_box_t _x_x118 = kk_std_core_hnd_yield_extend(kk_std_core_vector__new_lift_map_10181_fun119(f_0, v_0, w_0, _uniq_i_10169_0, _uniq_n_10168_0, _ctx), _ctx); /*2978*/
      kk_unit_unbox(_x_x118); return kk_Unit;
    }
    {
      kk_unit_t _uniq_x___10171_0 = kk_Unit;
      kk_vector_t _x_x121 = kk_vector_dup(w_0, _ctx); /*vector<765>*/
      kk_vector_unsafe_assign(_x_x121,_uniq_i_10169_0,x_10280,kk_context());
      kk_ssize_t _uniq_i_0_10000_10172_0 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10169_0, _ctx); /*ssize_t*/;
      { // tailcall
        _uniq_i_10169_0 = _uniq_i_0_10000_10172_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_vector_drop(w_0, _ctx);
    kk_vector_drop(v_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// Apply a total function `f` to each element in a vector `v`


// lift anonymous function
struct kk_std_core_vector_map_fun127__t {
  struct kk_function_s _base;
  kk_vector_t w;
};
static kk_box_t kk_std_core_vector_map_fun127(kk_function_t _fself, kk_box_t _b_x39, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector_new_map_fun127(kk_vector_t w, kk_context_t* _ctx) {
  struct kk_std_core_vector_map_fun127__t* _self = kk_function_alloc_as(struct kk_std_core_vector_map_fun127__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector_map_fun127, kk_context());
  _self->w = w;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector_map_fun127(kk_function_t _fself, kk_box_t _b_x39, kk_context_t* _ctx) {
  struct kk_std_core_vector_map_fun127__t* _self = kk_function_as(struct kk_std_core_vector_map_fun127__t*, _fself, _ctx);
  kk_vector_t w = _self->w; /* vector<765> */
  kk_drop_match(_self, {kk_vector_dup(w, _ctx);}, {}, _ctx)
  kk_unit_t wild___41 = kk_Unit;
  kk_unit_unbox(_b_x39);
  return kk_vector_box(w, _ctx);
}

kk_vector_t kk_std_core_vector_map(kk_vector_t v, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (v : vector<a>, f : (a) -> e b) -> e vector<b> */ 
  kk_vector_t w;
  kk_ssize_t _x_x122;
  kk_integer_t _x_x123;
  kk_ssize_t _x_x124 = kk_vector_len_borrow(v,kk_context()); /*ssize_t*/
  _x_x123 = kk_integer_from_ssize_t(_x_x124,kk_context()); /*int*/
  _x_x122 = kk_std_core_int_ssize__t(_x_x123, _ctx); /*ssize_t*/
  w = kk_vector_alloc(_x_x122,kk_box_null(),kk_context()); /*vector<765>*/
  kk_ssize_t n_10003 = kk_vector_len_borrow(v,kk_context()); /*ssize_t*/;
  kk_ssize_t i = (KK_IZ(0)); /*ssize_t*/;
  kk_unit_t x_10283 = kk_Unit;
  kk_vector_t _x_x125 = kk_vector_dup(w, _ctx); /*vector<765>*/
  kk_std_core_vector__lift_map_10181(f, v, _x_x125, n_10003, i, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x126 = kk_std_core_hnd_yield_extend(kk_std_core_vector_new_map_fun127(w, _ctx), _ctx); /*2978*/
    return kk_vector_unbox(_x_x126, _ctx);
  }
  {
    return w;
  }
}
 
// Convert a vector to a list with an optional tail.

kk_std_core_types__list kk_std_core_vector_vlist(kk_vector_t v, kk_std_core_types__optional tail, kk_context_t* _ctx) { /* forall<a> (v : vector<a>, tail : ? (list<a>)) -> list<a> */ 
  kk_std_core_types__list _x_x128;
  if (kk_std_core_types__is_Optional(tail, _ctx)) {
    kk_box_t _box_x42 = tail._cons._Optional.value;
    kk_std_core_types__list _uniq_tail_782 = kk_std_core_types__list_unbox(_box_x42, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_tail_782, _ctx);
    kk_std_core_types__optional_drop(tail, _ctx);
    _x_x128 = _uniq_tail_782; /*list<795>*/
  }
  else {
    kk_std_core_types__optional_drop(tail, _ctx);
    _x_x128 = kk_std_core_types__new_Nil(_ctx); /*list<795>*/
  }
  return kk_vector_to_list(v,_x_x128,kk_context());
}

kk_vector_t kk_std_core_vector_unvlist(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> vector<a> */ 
  return kk_list_to_vector(xs,kk_context());
}

bool kk_std_core_vector_ssize__t_fs_is_zero(kk_ssize_t i, kk_context_t* _ctx) { /* (i : ssize_t) -> bool */ 
  return (i == 0);
}

kk_ssize_t kk_std_core_vector_ssize__t_fs_decr(kk_ssize_t i, kk_context_t* _ctx) { /* (i : ssize_t) -> ssize_t */ 
  return (i - 1);
}

// initialization
void kk_std_core_vector__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_undiv__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_exn__init(_ctx);
  kk_std_core_int__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_vector__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_int__done(_ctx);
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_undiv__done(_ctx);
  kk_std_core_types__done(_ctx);
}
