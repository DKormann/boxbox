#pragma once
#ifndef kk_std_core_list_H
#define kk_std_core_list_H
// Koka generated module: std/core/list, koka version: 3.1.2, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_undiv.h"
#include "std_core_hnd.h"
#include "std_core_exn.h"
#include "std_core_char.h"
#include "std_core_string.h"
#include "std_core_int.h"
#include "std_core_vector.h"

// type declarations

// value declarations

kk_std_core_types__maybe kk_std_core_list_head(kk_std_core_types__list xs, kk_context_t* _ctx); /* forall<a> (xs : list<a>) -> maybe<a> */ 

kk_box_t kk_std_core_list_default_fs_head(kk_std_core_types__list xs, kk_box_t kkloc_default, kk_context_t* _ctx); /* forall<a> (xs : list<a>, default : a) -> a */ 

kk_std_core_types__list kk_std_core_list_tail(kk_std_core_types__list xs, kk_context_t* _ctx); /* forall<a> (xs : list<a>) -> list<a> */ 
 
// Is the list empty?

static inline bool kk_std_core_list_is_empty(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> bool */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return true;
  }
  {
    kk_std_core_types__list_drop(xs, _ctx);
    return false;
  }
}
 
// Returns a singleton list.

static inline kk_std_core_types__list kk_std_core_list_single(kk_box_t x, kk_context_t* _ctx) { /* forall<a> (x : a) -> list<a> */ 
  return kk_std_core_types__new_Cons(kk_reuse_null, 0, x, kk_std_core_types__new_Nil(_ctx), _ctx);
}

kk_integer_t kk_std_core_list__unroll_lift_length_4947_10000(kk_std_core_types__list ys, kk_integer_t acc, kk_context_t* _ctx); /* forall<a> (ys : list<a>, acc : int) -> int */ 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-length@4947@10000

static inline kk_integer_t kk_std_core_list__lift_length_4947(kk_std_core_types__list ys, kk_integer_t acc, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, acc : int) -> int */ 
  if (kk_std_core_types__is_Nil(ys, _ctx)) {
    return acc;
  }
  {
    return kk_std_core_list__unroll_lift_length_4947_10000(ys, acc, _ctx);
  }
}
 
// Returns the length of a list.

static inline kk_integer_t kk_std_core_list_length(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> int */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return kk_integer_from_small(0);
  }
  {
    return kk_std_core_list__unroll_lift_length_4947_10000(xs, kk_integer_from_small(0), _ctx);
  }
}

bool kk_std_core_list__lp__at_unroll_x_10001_eq__eq__rp_(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t _implicit_fs__lp__eq__eq__rp_, kk_context_t* _ctx); /* forall<a> (xs : list<a>, ys : list<a>, ?(==) : (a, a) -> bool) -> bool */ 
 
// unrolling of singleton matches of std/core/list/(@unroll-x@10001==)

static inline bool kk_std_core_list__lp__eq__eq__rp_(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t _implicit_fs__lp__eq__eq__rp_, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>, ?(==) : (a, a) -> bool) -> bool */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(_implicit_fs__lp__eq__eq__rp_, _ctx);
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      return true;
    }
    {
      struct kk_std_core_types_Cons* _con_x1312 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t _pat_7 = _con_x1312->head;
      kk_std_core_types__list _pat_8 = _con_x1312->tail;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        kk_std_core_types__list_drop(_pat_8, _ctx);
        kk_box_drop(_pat_7, _ctx);
        kk_datatype_ptr_free(ys, _ctx);
      }
      else {
        kk_datatype_ptr_decref(ys, _ctx);
      }
      return false;
    }
  }
  {
    return kk_std_core_list__lp__at_unroll_x_10001_eq__eq__rp_(xs, ys, _implicit_fs__lp__eq__eq__rp_, _ctx);
  }
}

kk_std_core_types__order kk_std_core_list__unroll_cmp_10002(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t _implicit_fs_cmp, kk_context_t* _ctx); /* forall<a> (xs : list<a>, ys : list<a>, ?cmp : (a, a) -> order) -> order */ 
 
// unrolling of singleton matches of std/core/list/@unroll-cmp@10002

static inline kk_std_core_types__order kk_std_core_list_cmp(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t _implicit_fs_cmp, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>, ?cmp : (a, a) -> order) -> order */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(_implicit_fs_cmp, _ctx);
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      return kk_std_core_types__new_Eq(_ctx);
    }
    {
      struct kk_std_core_types_Cons* _con_x1317 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t _pat_6 = _con_x1317->head;
      kk_std_core_types__list _pat_7 = _con_x1317->tail;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        kk_std_core_types__list_drop(_pat_7, _ctx);
        kk_box_drop(_pat_6, _ctx);
        kk_datatype_ptr_free(ys, _ctx);
      }
      else {
        kk_datatype_ptr_decref(ys, _ctx);
      }
      return kk_std_core_types__new_Lt(_ctx);
    }
  }
  {
    return kk_std_core_list__unroll_cmp_10002(xs, ys, _implicit_fs_cmp, _ctx);
  }
}

kk_std_core_types__list kk_std_core_list__trmc_take(kk_std_core_types__list xs, kk_integer_t n, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a> (xs : list<a>, n : int, ctx<list<a>>) -> list<a> */ 

kk_std_core_types__list kk_std_core_list_take(kk_std_core_types__list xs_0, kk_integer_t n_0, kk_context_t* _ctx); /* forall<a> (xs : list<a>, n : int) -> list<a> */ 

kk_std_core_types__list kk_std_core_list_drop(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx); /* forall<a> (xs : list<a>, n : int) -> list<a> */ 

kk_std_core_types__list kk_std_core_list__unroll_lift_reverse_append_4948_10003(kk_std_core_types__list acc, kk_std_core_types__list ys, kk_context_t* _ctx); /* forall<a> (acc : list<a>, ys : list<a>) -> list<a> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-reverse-append@4948@10003

static inline kk_std_core_types__list kk_std_core_list__lift_reverse_append_4948(kk_std_core_types__list acc, kk_std_core_types__list ys, kk_context_t* _ctx) { /* forall<a> (acc : list<a>, ys : list<a>) -> list<a> */ 
  if (kk_std_core_types__is_Nil(ys, _ctx)) {
    return acc;
  }
  {
    return kk_std_core_list__unroll_lift_reverse_append_4948_10003(acc, ys, _ctx);
  }
}
 
// Efficiently reverse a list `xs` and append it to `tl`:
// `reverse-append(xs,tl) == reserve(xs) ++ tl

static inline kk_std_core_types__list kk_std_core_list_reverse_append(kk_std_core_types__list xs, kk_std_core_types__list tl, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, tl : list<a>) -> list<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return tl;
  }
  {
    return kk_std_core_list__unroll_lift_reverse_append_4948_10003(tl, xs, _ctx);
  }
}
 
// Reverse a list.

static inline kk_std_core_types__list kk_std_core_list_reverse(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> list<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_lift_reverse_append_4948_10003(kk_std_core_types__new_Nil(_ctx), xs, _ctx);
  }
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_append_10004(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a> (xs : list<a>, ys : list<a>, ctx<list<a>>) -> list<a> */ 

kk_std_core_types__list kk_std_core_list__unroll_append_10004(kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_context_t* _ctx); /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-append@10004

static inline kk_std_core_types__list kk_std_core_list_append(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return ys;
  }
  {
    return kk_std_core_list__unroll_append_10004(xs, ys, _ctx);
  }
}
 
// Append two lists.

static inline kk_std_core_types__list kk_std_core_list__lp__plus__plus__rp_(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return ys;
  }
  {
    return kk_std_core_list__unroll_append_10004(xs, ys, _ctx);
  }
}

kk_box_t kk_std_core_list__mlift_unroll_foldl_10005_10684(kk_function_t f, kk_std_core_types__list xx, kk_box_t _y_x10440, kk_context_t* _ctx); /* forall<a,b,e> (f : (b, a) -> e b, xx : list<a>, b) -> e b */ 

kk_box_t kk_std_core_list__unroll_foldl_10005(kk_std_core_types__list xs, kk_box_t z, kk_function_t f_0, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, z : b, f : (b, a) -> e b) -> e b */ 
 
// unrolling of singleton matches of std/core/list/@unroll-foldl@10005

static inline kk_box_t kk_std_core_list_foldl(kk_std_core_types__list xs, kk_box_t z, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, z : b, f : (b, a) -> e b) -> e b */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(f, _ctx);
    return z;
  }
  {
    return kk_std_core_list__unroll_foldl_10005(xs, z, f, _ctx);
  }
}

kk_box_t kk_std_core_list__mlift_lift_foldr_10363_10685(kk_std_core_types__list _uniq_xx_10288, kk_function_t f, kk_box_t _uniq_z_10284_0_10373, kk_context_t* _ctx); /* forall<a,b,e> (list<a>, f : (a, b) -> e b, b) -> e b */ 

kk_box_t kk_std_core_list__lift_foldr_10363(kk_function_t f_0, kk_std_core_types__list _uniq_xs_10283, kk_box_t _uniq_z_10284, kk_context_t* _ctx); /* forall<a,b,e> (f : (a, b) -> e b, list<a>, b) -> e b */ 
 
// Fold a list from the right, i.e. `foldr([1,2],0,(+)) == 1+(2+0)`
// Note, `foldr` is less efficient than `foldl` as it reverses the list first.

static inline kk_box_t kk_std_core_list_foldr(kk_std_core_types__list xs, kk_box_t z, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, z : b, f : (a, b) -> e b) -> e b */ 
  kk_std_core_types__list xs_0_10042;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    xs_0_10042 = kk_std_core_types__new_Nil(_ctx); /*list<1116>*/
  }
  else {
    xs_0_10042 = kk_std_core_list__unroll_lift_reverse_append_4948_10003(kk_std_core_types__new_Nil(_ctx), xs, _ctx); /*list<1116>*/
  }
  if (kk_std_core_types__is_Nil(xs_0_10042, _ctx)) {
    kk_function_drop(f, _ctx);
    return z;
  }
  {
    return kk_std_core_list__lift_foldr_10363(f, xs_0_10042, z, _ctx);
  }
}

kk_box_t kk_std_core_list_foldl1(kk_std_core_types__list xs, kk_function_t f, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */ 

kk_box_t kk_std_core_list_foldr1(kk_std_core_types__list xs, kk_function_t f, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */ 

kk_std_core_types__tuple2 kk_std_core_list_split(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx); /* forall<a> (xs : list<a>, n : int) -> (list<a>, list<a>) */ 

kk_std_core_types__list kk_std_core_list__mlift_unroll_drop_while_10006_10686(kk_function_t predicate, kk_std_core_types__list xs, kk_std_core_types__list xx, bool _y_x10460, kk_context_t* _ctx); /* forall<a,e> (predicate : (a) -> e bool, xs : list<a>, xx : list<a>, bool) -> e list<a> */ 

kk_std_core_types__list kk_std_core_list__unroll_drop_while_10006(kk_std_core_types__list xs_0, kk_function_t predicate_0, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-drop-while@10006

static inline kk_std_core_types__list kk_std_core_list_drop_while(kk_std_core_types__list xs, kk_function_t predicate, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(predicate, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_drop_while_10006(xs, predicate, _ctx);
  }
}

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_filter_10007_10687(kk_std_core_types__cctx _acc, kk_function_t pred, kk_box_t x, kk_std_core_types__list xx, bool _y_x10466, kk_context_t* _ctx); /* forall<a,e> (ctx<list<a>>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 

kk_std_core_types__list kk_std_core_list__trmc_unroll_filter_10007(kk_std_core_types__list xs, kk_function_t pred_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, ctx<list<a>>) -> e list<a> */ 

kk_std_core_types__list kk_std_core_list__unroll_filter_10007(kk_std_core_types__list xs_0, kk_function_t pred_1, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e list<a> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-filter@10007

static inline kk_std_core_types__list kk_std_core_list_filter(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e list<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(pred, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_filter_10007(xs, pred, _ctx);
  }
}

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_filter_map_10008_10688(kk_std_core_types__cctx _acc, kk_function_t pred, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10474, kk_context_t* _ctx); /* forall<a,b,e> (ctx<list<b>>, pred : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 

kk_std_core_types__list kk_std_core_list__trmc_unroll_filter_map_10008(kk_std_core_types__list xs, kk_function_t pred_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */ 

kk_std_core_types__list kk_std_core_list__unroll_filter_map_10008(kk_std_core_types__list xs_0, kk_function_t pred_1, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>) -> e list<b> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-filter-map@10008

static inline kk_std_core_types__list kk_std_core_list_filter_map(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(pred, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_filter_map_10008(xs, pred, _ctx);
  }
}

kk_std_core_types__maybe kk_std_core_list__mlift_unroll_foreach_while_10009_10689(kk_function_t action, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10482, kk_context_t* _ctx); /* forall<a,b,e> (action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e maybe<b> */ 

kk_std_core_types__maybe kk_std_core_list__unroll_foreach_while_10009(kk_std_core_types__list xs, kk_function_t action_0, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e maybe<b> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-foreach-while@10009

static inline kk_std_core_types__maybe kk_std_core_list_foreach_while(kk_std_core_types__list xs, kk_function_t action, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e maybe<b> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(action, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    return kk_std_core_list__unroll_foreach_while_10009(xs, action, _ctx);
  }
}

kk_std_core_types__maybe kk_std_core_list__mlift_lift_find_10364_10690(kk_box_t _uniq_x_10297, kk_std_core_types__list _uniq_xx_10298, kk_function_t pred, bool _y_x10488, kk_context_t* _ctx); /* forall<a,e> (a, list<a>, pred : (a) -> e bool, bool) -> e maybe<a> */ 

kk_std_core_types__maybe kk_std_core_list__lift_find_10364(kk_function_t pred_0, kk_std_core_types__list _uniq_xs_10293, kk_context_t* _ctx); /* forall<a,e> (pred : (a) -> e bool, list<a>) -> e maybe<a> */ 
 
// Find the first element satisfying some predicate

static inline kk_std_core_types__maybe kk_std_core_list_find(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e maybe<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(pred, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    return kk_std_core_list__lift_find_10364(pred, xs, _ctx);
  }
}
 
// Find the first element satisfying some predicate and return it.

static inline kk_std_core_types__maybe kk_std_core_list_find_maybe(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>) -> e maybe<b> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(pred, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    return kk_std_core_list__unroll_foreach_while_10009(xs, pred, _ctx);
  }
}
 
// Convert a `:maybe` type to a list type.

static inline kk_std_core_types__list kk_std_core_list_maybe_fs_list(kk_std_core_types__maybe m, kk_context_t* _ctx) { /* forall<a> (m : maybe<a>) -> list<a> */ 
  if (kk_std_core_types__is_Nothing(m, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_box_t x = m._cons.Just.value;
    return kk_std_core_types__new_Cons(kk_reuse_null, 0, x, kk_std_core_types__new_Nil(_ctx), _ctx);
  }
}

kk_std_core_types__list kk_std_core_list__trmc_list(kk_integer_t lo, kk_integer_t hi, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (lo : int, hi : int, ctx<list<int>>) -> list<int> */ 

kk_std_core_types__list kk_std_core_list_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_context_t* _ctx); /* (lo : int, hi : int) -> list<int> */ 

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_map_10010_10691(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list xx, kk_box_t _trmc_x10389, kk_context_t* _ctx); /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e b, xx : list<a>, b) -> e list<b> */ 

kk_std_core_types__list kk_std_core_list__trmc_unroll_map_10010(kk_std_core_types__list xs, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, f : (a) -> e b, ctx<list<b>>) -> e list<b> */ 

kk_std_core_types__list kk_std_core_list__unroll_map_10010(kk_std_core_types__list xs_0, kk_function_t f_1, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, f : (a) -> e b) -> e list<b> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-map@10010

static inline kk_std_core_types__list kk_std_core_list_map(kk_std_core_types__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e b) -> e list<b> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_map_10010(xs, f, _ctx);
  }
}

kk_std_core_types__list kk_std_core_list_char_fs__trmc_lift_list_10365(kk_std_core_types__list _uniq_xs_10303, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<int>, ctx<list<char>>) -> list<char> */ 

kk_std_core_types__list kk_std_core_list_char_fs__lift_list_10365(kk_std_core_types__list _uniq_xs_10303_0, kk_context_t* _ctx); /* (list<int>) -> list<char> */ 
 
// Create a list of characters from `lo`  to `hi`  (including `hi`).

static inline kk_std_core_types__list kk_std_core_list_char_fs_list(kk_char_t lo, kk_char_t hi, kk_context_t* _ctx) { /* (lo : char, hi : char) -> list<char> */ 
  kk_std_core_types__list xs_10062;
  kk_integer_t _x_x1411 = kk_integer_from_int(lo,kk_context()); /*int*/
  kk_integer_t _x_x1412 = kk_integer_from_int(hi,kk_context()); /*int*/
  xs_10062 = kk_std_core_list_list(_x_x1411, _x_x1412, _ctx); /*list<int>*/
  if (kk_std_core_types__is_Nil(xs_10062, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list_char_fs__lift_list_10365(xs_10062, _ctx);
  }
}

kk_std_core_types__list kk_std_core_list_function_fs__mlift_trmc_list_10692(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t hi, kk_integer_t lo, kk_box_t _trmc_x10395, kk_context_t* _ctx); /* forall<a,e> (ctx<list<a>>, f : (int) -> e a, hi : int, lo : int, a) -> e list<a> */ 

kk_std_core_types__list kk_std_core_list_function_fs__trmc_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx); /* forall<a,e> (lo : int, hi : int, f : (int) -> e a, ctx<list<a>>) -> e list<a> */ 

kk_std_core_types__list kk_std_core_list_function_fs_list(kk_integer_t lo_1, kk_integer_t hi_1, kk_function_t f_1, kk_context_t* _ctx); /* forall<a,e> (lo : int, hi : int, f : (int) -> e a) -> e list<a> */ 

kk_std_core_types__list kk_std_core_list_stride_fs__trmc_list(kk_integer_t lo, kk_integer_t hi, kk_integer_t stride, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (lo : int, hi : int, stride : int, ctx<list<int>>) -> list<int> */ 

kk_std_core_types__list kk_std_core_list_stride_fs_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_integer_t stride_0, kk_context_t* _ctx); /* (lo : int, hi : int, stride : int) -> list<int> */ 

kk_std_core_types__list kk_std_core_list_stridefunction_fs__mlift_trmc_list_10693(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t hi, kk_integer_t lo, kk_integer_t stride, kk_box_t _trmc_x10400, kk_context_t* _ctx); /* forall<a,e> (ctx<list<a>>, f : (int) -> e a, hi : int, lo : int, stride : int, a) -> e list<a> */ 

kk_std_core_types__list kk_std_core_list_stridefunction_fs__trmc_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_integer_t stride_0, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx); /* forall<a,e> (lo : int, hi : int, stride : int, f : (int) -> e a, ctx<list<a>>) -> e list<a> */ 

kk_std_core_types__list kk_std_core_list_stridefunction_fs_list(kk_integer_t lo_1, kk_integer_t hi_1, kk_integer_t stride_1, kk_function_t f_1, kk_context_t* _ctx); /* forall<a,e> (lo : int, hi : int, stride : int, f : (int) -> e a) -> e list<a> */ 

kk_string_t kk_std_core_list_string_fs_map(kk_string_t s, kk_function_t f, kk_context_t* _ctx); /* forall<e> (s : string, f : (char) -> e char) -> e string */ 

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_lift_map_indexed_4949_10011_10694(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t i_0_10069, kk_std_core_types__list yy, kk_box_t _trmc_x10403, kk_context_t* _ctx); /* forall<a,b,e> (ctx<list<b>>, f : (idx : int, value : a) -> e b, i@0@10069 : int, yy : list<a>, b) -> e list<b> */ 

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_map_indexed_4949_10011(kk_function_t f_0, kk_std_core_types__list ys, kk_integer_t i, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx); /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int, ctx<list<b>>) -> e list<b> */ 

kk_std_core_types__list kk_std_core_list__unroll_lift_map_indexed_4949_10011(kk_function_t f_1, kk_std_core_types__list ys_0, kk_integer_t i_0, kk_context_t* _ctx); /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int) -> e list<b> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-map-indexed@4949@10011

static inline kk_std_core_types__list kk_std_core_list__lift_map_indexed_4949(kk_function_t f, kk_std_core_types__list ys, kk_integer_t i, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int) -> e list<b> */ 
  if (kk_std_core_types__is_Nil(ys, _ctx)) {
    kk_integer_drop(i, _ctx);
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_lift_map_indexed_4949_10011(f, ys, i, _ctx);
  }
}
 
// Apply a function `f` to each element of the input list in sequence where takes
// both the index of the current element and the element itself as arguments.

static inline kk_std_core_types__list kk_std_core_list_map_indexed(kk_std_core_types__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (idx : int, value : a) -> e b) -> e list<b> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_lift_map_indexed_4949_10011(f, xs, kk_integer_from_small(0), _ctx);
  }
}

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_lift_map_peek_4950_10012_10695(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list yy, kk_box_t _trmc_x10406, kk_context_t* _ctx); /* forall<a,b,e> (ctx<list<b>>, f : (value : a, rest : list<a>) -> e b, yy : list<a>, b) -> e list<b> */ 

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_map_peek_4950_10012(kk_function_t f_0, kk_std_core_types__list ys, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx); /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>, ctx<list<b>>) -> e list<b> */ 

kk_std_core_types__list kk_std_core_list__unroll_lift_map_peek_4950_10012(kk_function_t f_1, kk_std_core_types__list ys_0, kk_context_t* _ctx); /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>) -> e list<b> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-map-peek@4950@10012

static inline kk_std_core_types__list kk_std_core_list__lift_map_peek_4950(kk_function_t f, kk_std_core_types__list ys, kk_context_t* _ctx) { /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>) -> e list<b> */ 
  if (kk_std_core_types__is_Nil(ys, _ctx)) {
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_lift_map_peek_4950_10012(f, ys, _ctx);
  }
}
 
// Apply a function `f` to each element of the input list in sequence where `f` takes
// both the current element and the tail list as arguments.

static inline kk_std_core_types__list kk_std_core_list_map_peek(kk_std_core_types__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (value : a, rest : list<a>) -> e b) -> e list<b> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_lift_map_peek_4950_10012(f, xs, _ctx);
  }
}

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_lift_map_indexed_peek_4951_10013_10696(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t i_0_10077, kk_std_core_types__list yy, kk_box_t _trmc_x10409, kk_context_t* _ctx); /* forall<a,b,e> (ctx<list<b>>, f : (idx : int, value : a, rest : list<a>) -> e b, i@0@10077 : int, yy : list<a>, b) -> e list<b> */ 

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_map_indexed_peek_4951_10013(kk_function_t f_0, kk_std_core_types__list ys, kk_integer_t i, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx); /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int, ctx<list<b>>) -> e list<b> */ 

kk_std_core_types__list kk_std_core_list__unroll_lift_map_indexed_peek_4951_10013(kk_function_t f_1, kk_std_core_types__list ys_0, kk_integer_t i_0, kk_context_t* _ctx); /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int) -> e list<b> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-map-indexed-peek@4951@10013

static inline kk_std_core_types__list kk_std_core_list__lift_map_indexed_peek_4951(kk_function_t f, kk_std_core_types__list ys, kk_integer_t i, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int) -> e list<b> */ 
  if (kk_std_core_types__is_Nil(ys, _ctx)) {
    kk_integer_drop(i, _ctx);
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_lift_map_indexed_peek_4951_10013(f, ys, i, _ctx);
  }
}
 
// Apply a function `f` to each element of the input list in sequence where takes
// both the index of the current element, the element itself, and the tail list as arguments.

static inline kk_std_core_types__list kk_std_core_list_map_indexed_peek(kk_std_core_types__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (idx : int, value : a, rest : list<a>) -> e b) -> e list<b> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_lift_map_indexed_peek_4951_10013(f, xs, kk_integer_from_small(0), _ctx);
  }
}

kk_std_core_types__list kk_std_core_list__trmc_replicate(kk_box_t x, kk_integer_t n, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a> (x : a, n : int, ctx<list<a>>) -> list<a> */ 

kk_std_core_types__list kk_std_core_list_replicate(kk_box_t x_0, kk_integer_t n_0, kk_context_t* _ctx); /* forall<a> (x : a, n : int) -> list<a> */ 

kk_std_core_types__list kk_std_core_list__mlift_trmc_lift_remove_10366_10697(kk_std_core_types__cctx _acc, kk_box_t _uniq_x_10313, kk_std_core_types__list _uniq_xx_10314, kk_function_t pred, bool _y_x10537, kk_context_t* _ctx); /* forall<a,e> (ctx<list<a>>, a, list<a>, pred : (a) -> e bool, bool) -> e list<a> */ 

kk_std_core_types__list kk_std_core_list__trmc_lift_remove_10366(kk_function_t pred_0, kk_std_core_types__list _uniq_xs_10310, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx); /* forall<a,e> (pred : (a) -> e bool, list<a>, ctx<list<a>>) -> e list<a> */ 

kk_std_core_types__list kk_std_core_list__lift_remove_10366(kk_function_t pred_1, kk_std_core_types__list _uniq_xs_10310_0, kk_context_t* _ctx); /* forall<a,e> (pred : (a) -> e bool, list<a>) -> e list<a> */ 
 
// Remove those elements of a list that satisfy the given predicate `pred`.
// For example: `remove([1,2,3],odd?) == [2]`

static inline kk_std_core_types__list kk_std_core_list_remove(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e list<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(pred, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__lift_remove_10366(pred, xs, _ctx);
  }
}

kk_std_core_types__tuple2 kk_std_core_list__mlift_unroll_partition_acc_10014_10698(kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_function_t pred, kk_box_t x, kk_std_core_types__list xx, bool _y_x10545, kk_context_t* _ctx); /* forall<a,e> (acc1 : ctx<list<a>>, acc2 : ctx<list<a>>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e (list<a>, list<a>) */ 

kk_std_core_types__tuple2 kk_std_core_list__unroll_partition_acc_10014(kk_std_core_types__list xs, kk_function_t pred_0, kk_std_core_types__cctx acc1_0, kk_std_core_types__cctx acc2_0, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, acc1 : ctx<list<a>>, acc2 : ctx<list<a>>) -> e (list<a>, list<a>) */ 
 
// unrolling of singleton matches of std/core/list/@unroll-partition-acc@10014

static inline kk_std_core_types__tuple2 kk_std_core_list_partition_acc(kk_std_core_types__list xs, kk_function_t pred, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, acc1 : ctx<list<a>>, acc2 : ctx<list<a>>) -> e (list<a>, list<a>) */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list _b_x499_501;
    kk_box_t _x_x1514 = kk_cctx_apply(acc1,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    _b_x499_501 = kk_std_core_types__list_unbox(_x_x1514, KK_OWNED, _ctx); /*list<2413>*/
    kk_std_core_types__list _b_x500_502;
    kk_box_t _x_x1515 = kk_cctx_apply(acc2,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    _b_x500_502 = kk_std_core_types__list_unbox(_x_x1515, KK_OWNED, _ctx); /*list<2413>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x499_501, _ctx), kk_std_core_types__list_box(_b_x500_502, _ctx), _ctx);
  }
  {
    return kk_std_core_list__unroll_partition_acc_10014(xs, pred, acc1, acc2, _ctx);
  }
}

kk_std_core_types__tuple2 kk_std_core_list_partition(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e (list<a>, list<a>) */ 

kk_std_core_types__maybe kk_std_core_list__mlift_lift_lookup_10367_10699(kk_std_core_types__tuple2 _uniq_x_10324, kk_std_core_types__list _uniq_xx_10325, kk_function_t pred, bool _y_x10554, kk_context_t* _ctx); /* forall<a,b,e> ((a, b), list<(a, b)>, pred : (a) -> e bool, bool) -> e maybe<b> */ 

kk_std_core_types__maybe kk_std_core_list__lift_lookup_10367(kk_function_t pred_0, kk_std_core_types__list _uniq_xs_10320, kk_context_t* _ctx); /* forall<a,b,e> (pred : (a) -> e bool, list<(a, b)>) -> e maybe<b> */ 
 
// Lookup the first element satisfying some predicate

static inline kk_std_core_types__maybe kk_std_core_list_lookup(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<(a, b)>, pred : (a) -> e bool) -> e maybe<b> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(pred, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    return kk_std_core_list__lift_lookup_10367(pred, xs, _ctx);
  }
}

kk_integer_t kk_std_core_list__mlift_unroll_index_of_acc_10015_10700(kk_integer_t idx, kk_function_t pred, kk_std_core_types__list xx, bool _y_x10561, kk_context_t* _ctx); /* forall<a,e> (idx : int, pred : (a) -> e bool, xx : list<a>, bool) -> e int */ 

kk_integer_t kk_std_core_list__unroll_index_of_acc_10015(kk_std_core_types__list xs, kk_function_t pred_0, kk_integer_t idx_0, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, idx : int) -> e int */ 
 
// unrolling of singleton matches of std/core/list/@unroll-index-of-acc@10015

static inline kk_integer_t kk_std_core_list_index_of_acc(kk_std_core_types__list xs, kk_function_t pred, kk_integer_t idx, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, idx : int) -> e int */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(pred, _ctx);
    kk_integer_drop(idx, _ctx);
    return kk_integer_from_small(-1);
  }
  {
    return kk_std_core_list__unroll_index_of_acc_10015(xs, pred, idx, _ctx);
  }
}
 
// Returns the index of the first element where `pred` holds, or `-1` if no such element exists.

static inline kk_integer_t kk_std_core_list_index_of(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e int */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(pred, _ctx);
    return kk_integer_from_small(-1);
  }
  {
    return kk_std_core_list__unroll_index_of_acc_10015(xs, pred, kk_integer_from_small(0), _ctx);
  }
}

kk_unit_t kk_std_core_list__mlift_unroll_foreach_10016_10701(kk_function_t action, kk_std_core_types__list xx, kk_unit_t wild__, kk_context_t* _ctx); /* forall<a,e> (action : (a) -> e (), xx : list<a>, wild_ : ()) -> e () */ 

kk_unit_t kk_std_core_list__unroll_foreach_10016(kk_std_core_types__list xs, kk_function_t action_0, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, action : (a) -> e ()) -> e () */ 
 
// unrolling of singleton matches of std/core/list/@unroll-foreach@10016

static inline kk_unit_t kk_std_core_list_foreach(kk_std_core_types__list xs, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, action : (a) -> e ()) -> e () */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(action, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    kk_std_core_list__unroll_foreach_10016(xs, action, _ctx); return kk_Unit;
  }
}

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_map_while_10017_10702(kk_std_core_types__cctx _acc, kk_function_t action, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10574, kk_context_t* _ctx); /* forall<a,b,e> (ctx<list<b>>, action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 

kk_std_core_types__list kk_std_core_list__trmc_unroll_map_while_10017(kk_std_core_types__list xs, kk_function_t action_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */ 

kk_std_core_types__list kk_std_core_list__unroll_map_while_10017(kk_std_core_types__list xs_0, kk_function_t action_1, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e list<b> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-map-while@10017

static inline kk_std_core_types__list kk_std_core_list_map_while(kk_std_core_types__list xs, kk_function_t action, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(action, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_map_while_10017(xs, action, _ctx);
  }
}

kk_unit_t kk_std_core_list__mlift_lift_foreach_indexed_10368_10703(kk_std_core_types__list _uniq_xx_10334, kk_function_t action, kk_ref_t i, kk_unit_t _uniq_x___10335, kk_context_t* _ctx); /* forall<h,a,e> (list<a>, action : (int, a) -> e (), i : local-var<h,int>, ()) -> <local<h>|e> () */ 

kk_unit_t kk_std_core_list__mlift_lift_foreach_indexed_10368_10704(kk_std_core_types__list _uniq_xx_10334_0, kk_function_t action_0, kk_ref_t i_0, kk_integer_t _y_x10584, kk_context_t* _ctx); /* forall<h,a,e> (list<a>, action : (int, a) -> e (), i : local-var<h,int>, int) -> <local<h>|e> () */ 

kk_unit_t kk_std_core_list__mlift_lift_foreach_indexed_10368_10705(kk_std_core_types__list _uniq_xx_10334_1, kk_function_t action_1, kk_ref_t i_1, kk_unit_t wild__, kk_context_t* _ctx); /* forall<h,a,e> (list<a>, action : (int, a) -> e (), i : local-var<h,int>, wild_ : ()) -> <local<h>|e> () */ 

kk_unit_t kk_std_core_list__mlift_lift_foreach_indexed_10368_10706(kk_box_t _uniq_x_10333, kk_std_core_types__list _uniq_xx_10334_2, kk_function_t action_2, kk_ref_t i_2, kk_integer_t j, kk_context_t* _ctx); /* forall<h,a,e> (a, list<a>, action : (int, a) -> e (), i : local-var<h,int>, j : int) -> <local<h>|e> () */ 

kk_unit_t kk_std_core_list__lift_foreach_indexed_10368(kk_function_t action_4, kk_ref_t i_3, kk_std_core_types__list _uniq_xs_10330, kk_context_t* _ctx); /* forall<h,a,e> (action : (int, a) -> e (), i : local-var<h,int>, list<a>) -> <local<h>|e> () */ 

kk_unit_t kk_std_core_list_foreach_indexed(kk_std_core_types__list xs, kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, action : (int, a) -> e ()) -> e () */ 

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_intersperse_4952_10018(kk_box_t sep, kk_std_core_types__list ys, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a> (sep : a, ys : list<a>, ctx<list<a>>) -> list<a> */ 

kk_std_core_types__list kk_std_core_list__unroll_lift_intersperse_4952_10018(kk_box_t sep_0, kk_std_core_types__list ys_0, kk_context_t* _ctx); /* forall<a> (sep : a, ys : list<a>) -> list<a> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-intersperse@4952@10018

static inline kk_std_core_types__list kk_std_core_list__lift_intersperse_4952(kk_box_t sep, kk_std_core_types__list ys, kk_context_t* _ctx) { /* forall<a> (sep : a, ys : list<a>) -> list<a> */ 
  if (kk_std_core_types__is_Nil(ys, _ctx)) {
    kk_box_drop(sep, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_lift_intersperse_4952_10018(sep, ys, _ctx);
  }
}

kk_std_core_types__list kk_std_core_list_intersperse(kk_std_core_types__list xs, kk_box_t sep, kk_context_t* _ctx); /* forall<a> (xs : list<a>, sep : a) -> list<a> */ 

kk_string_t kk_std_core_list_join(kk_std_core_types__list xs, kk_context_t* _ctx); /* (xs : list<string>) -> string */ 

kk_string_t kk_std_core_list_joinsep(kk_std_core_types__list xs, kk_string_t sep, kk_context_t* _ctx); /* (xs : list<string>, sep : string) -> string */ 
 
// Concatenate all strings in a list using a specific separator

static inline kk_string_t kk_std_core_list_joinsep_fs_join(kk_std_core_types__list xs, kk_string_t sep, kk_context_t* _ctx) { /* (xs : list<string>, sep : string) -> string */ 
  return kk_std_core_list_joinsep(xs, sep, _ctx);
}

kk_string_t kk_std_core_list__mlift_show_10707(kk_std_core_types__list _c_x10593, kk_context_t* _ctx); /* (list<string>) -> string */ 

kk_string_t kk_std_core_list_show(kk_std_core_types__list xs, kk_function_t _implicit_fs_show, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, ?show : (a) -> e string) -> e string */ 
 
// _deprecated_, use `list/show` instead.

static inline kk_string_t kk_std_core_list_show_list(kk_std_core_types__list xs, kk_function_t show_elem, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, show-elem : (a) -> e string) -> e string */ 
  return kk_std_core_list_show(xs, show_elem, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_zip_10019(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a,b> (xs : list<a>, ys : list<b>, ctx<list<(a, b)>>) -> list<(a, b)> */ 

kk_std_core_types__list kk_std_core_list__unroll_zip_10019(kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_context_t* _ctx); /* forall<a,b> (xs : list<a>, ys : list<b>) -> list<(a, b)> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-zip@10019

static inline kk_std_core_types__list kk_std_core_list_zip(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_context_t* _ctx) { /* forall<a,b> (xs : list<a>, ys : list<b>) -> list<(a, b)> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list_drop(ys, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_zip_10019(xs, ys, _ctx);
  }
}

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_zipwith_10020_10708(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list xx, kk_std_core_types__list yy, kk_box_t _trmc_x10422, kk_context_t* _ctx); /* forall<a,b,c,e> (ctx<list<c>>, f : (a, b) -> e c, xx : list<a>, yy : list<b>, c) -> e list<c> */ 

kk_std_core_types__list kk_std_core_list__trmc_unroll_zipwith_10020(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx); /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c, ctx<list<c>>) -> e list<c> */ 

kk_std_core_types__list kk_std_core_list__unroll_zipwith_10020(kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_function_t f_1, kk_context_t* _ctx); /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c) -> e list<c> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-zipwith@10020

static inline kk_std_core_types__list kk_std_core_list_zipwith(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c) -> e list<c> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_zipwith_10020(xs, ys, f, _ctx);
  }
}

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_lift_zipwith_indexed_4953_10021_10709(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t i_0_10105, kk_std_core_types__list xx, kk_std_core_types__list yy, kk_box_t _trmc_x10425, kk_context_t* _ctx); /* forall<a,b,c,e> (ctx<list<c>>, f : (int, a, b) -> e c, i@0@10105 : int, xx : list<a>, yy : list<b>, c) -> e list<c> */ 

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_zipwith_indexed_4953_10021(kk_function_t f_0, kk_integer_t i, kk_std_core_types__list xs, kk_std_core_types__list ys, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx); /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xs : list<a>, ys : list<b>, ctx<list<c>>) -> e list<c> */ 

kk_std_core_types__list kk_std_core_list__unroll_lift_zipwith_indexed_4953_10021(kk_function_t f_1, kk_integer_t i_0, kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_context_t* _ctx); /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xs : list<a>, ys : list<b>) -> e list<c> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-zipwith-indexed@4953@10021

static inline kk_std_core_types__list kk_std_core_list__lift_zipwith_indexed_4953(kk_function_t f, kk_integer_t i, kk_std_core_types__list xs, kk_std_core_types__list ys, kk_context_t* _ctx) { /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xs : list<a>, ys : list<b>) -> e list<c> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_integer_drop(i, _ctx);
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_lift_zipwith_indexed_4953_10021(f, i, xs, ys, _ctx);
  }
}
 
// Zip two lists together by apply a function `f` to all corresponding elements
// and their index in the list.
// The returned list is only as long as the smallest input list.

static inline kk_std_core_types__list kk_std_core_list_zipwith_indexed(kk_std_core_types__list xs0, kk_std_core_types__list ys0, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,c,e> (xs0 : list<a>, ys0 : list<b>, f : (int, a, b) -> e c) -> e list<c> */ 
  if (kk_std_core_types__is_Nil(xs0, _ctx)) {
    kk_std_core_types__list_drop(ys0, _ctx);
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_lift_zipwith_indexed_4953_10021(f, kk_integer_from_small(0), xs0, ys0, _ctx);
  }
}

kk_std_core_types__tuple2 kk_std_core_list__unroll_lift_unzip_4954_10022(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_context_t* _ctx); /* forall<a,b,c,d> (ys : list<(a, b)>, acc1 : cctx<c,list<a>>, acc2 : cctx<d,list<b>>) -> (c, d) */ 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-unzip@4954@10022

static inline kk_std_core_types__tuple2 kk_std_core_list__lift_unzip_4954(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_context_t* _ctx) { /* forall<a,b,c,d> (ys : list<(a, b)>, acc1 : cctx<c,list<a>>, acc2 : cctx<d,list<b>>) -> (c, d) */ 
  if (kk_std_core_types__is_Nil(ys, _ctx)) {
    kk_box_t _x_x1686 = kk_cctx_apply(acc1,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1687 = kk_cctx_apply(acc2,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    return kk_std_core_types__new_Tuple2(_x_x1686, _x_x1687, _ctx);
  }
  {
    return kk_std_core_list__unroll_lift_unzip_4954_10022(ys, acc1, acc2, _ctx);
  }
}

kk_std_core_types__tuple2 kk_std_core_list_unzip(kk_std_core_types__list xs, kk_context_t* _ctx); /* forall<a,b> (xs : list<(a, b)>) -> (list<a>, list<b>) */ 

kk_std_core_types__tuple3 kk_std_core_list__unroll_lift_unzip3_4955_10023(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_std_core_types__cctx acc3, kk_context_t* _ctx); /* forall<a,b,c,d,a1,b1> (ys : list<(a, b, c)>, acc1 : cctx<d,list<a>>, acc2 : cctx<a1,list<b>>, acc3 : cctx<b1,list<c>>) -> (d, a1, b1) */ 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-unzip3@4955@10023

static inline kk_std_core_types__tuple3 kk_std_core_list__lift_unzip3_4955(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_std_core_types__cctx acc3, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,b1> (ys : list<(a, b, c)>, acc1 : cctx<d,list<a>>, acc2 : cctx<a1,list<b>>, acc3 : cctx<b1,list<c>>) -> (d, a1, b1) */ 
  if (kk_std_core_types__is_Nil(ys, _ctx)) {
    kk_box_t _x_x1703 = kk_cctx_apply(acc1,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1704 = kk_cctx_apply(acc2,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1705 = kk_cctx_apply(acc3,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    return kk_std_core_types__new_Tuple3(_x_x1703, _x_x1704, _x_x1705, _ctx);
  }
  {
    return kk_std_core_list__unroll_lift_unzip3_4955_10023(ys, acc1, acc2, acc3, _ctx);
  }
}

kk_std_core_types__tuple3 kk_std_core_list_unzip3(kk_std_core_types__list xs, kk_context_t* _ctx); /* forall<a,b,c> (xs : list<(a, b, c)>) -> (list<a>, list<b>, list<c>) */ 

kk_std_core_types__tuple4 kk_std_core_list__unroll_lift_unzip4_4956_10024(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_std_core_types__cctx acc3, kk_std_core_types__cctx acc4, kk_context_t* _ctx); /* forall<a,b,c,d,a1,b1,c1,d1> (ys : list<(a, b, c, d)>, acc1 : cctx<a1,list<a>>, acc2 : cctx<b1,list<b>>, acc3 : cctx<c1,list<c>>, acc4 : cctx<d1,list<d>>) -> (a1, b1, c1, d1) */ 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-unzip4@4956@10024

static inline kk_std_core_types__tuple4 kk_std_core_list__lift_unzip4_4956(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_std_core_types__cctx acc3, kk_std_core_types__cctx acc4, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,b1,c1,d1> (ys : list<(a, b, c, d)>, acc1 : cctx<a1,list<a>>, acc2 : cctx<b1,list<b>>, acc3 : cctx<c1,list<c>>, acc4 : cctx<d1,list<d>>) -> (a1, b1, c1, d1) */ 
  if (kk_std_core_types__is_Nil(ys, _ctx)) {
    kk_box_t _x_x1727 = kk_cctx_apply(acc1,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1728 = kk_cctx_apply(acc2,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1729 = kk_cctx_apply(acc3,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1730 = kk_cctx_apply(acc4,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    return kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _x_x1727, _x_x1728, _x_x1729, _x_x1730, _ctx);
  }
  {
    return kk_std_core_list__unroll_lift_unzip4_4956_10024(ys, acc1, acc2, acc3, acc4, _ctx);
  }
}

kk_std_core_types__tuple4 kk_std_core_list_unzip4(kk_std_core_types__list xs, kk_context_t* _ctx); /* forall<a,b,c,d> (xs : list<(a, b, c, d)>) -> (list<a>, list<b>, list<c>, list<d>) */ 

kk_std_core_types__tuple2 kk_std_core_list__mlift_unroll_lift_span_4957_10025_10710(kk_std_core_types__list acc, kk_function_t predicate, kk_box_t y, kk_std_core_types__list ys, kk_std_core_types__list yy, bool _y_x10611, kk_context_t* _ctx); /* forall<a,e> (acc : list<a>, predicate : (a) -> e bool, y : a, ys : list<a>, yy : list<a>, bool) -> e (list<a>, list<a>) */ 

kk_std_core_types__tuple2 kk_std_core_list__unroll_lift_span_4957_10025(kk_function_t predicate_0, kk_std_core_types__list ys_0, kk_std_core_types__list acc_0, kk_context_t* _ctx); /* forall<a,e> (predicate : (a) -> e bool, ys : list<a>, acc : list<a>) -> e (list<a>, list<a>) */ 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-span@4957@10025

static inline kk_std_core_types__tuple2 kk_std_core_list__lift_span_4957(kk_function_t predicate, kk_std_core_types__list ys, kk_std_core_types__list acc, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, ys : list<a>, acc : list<a>) -> e (list<a>, list<a>) */ 
  if (kk_std_core_types__is_Nil(ys, _ctx)) {
    kk_function_drop(predicate, _ctx);
    kk_std_core_types__list _b_x987_989;
    if (kk_std_core_types__is_Nil(acc, _ctx)) {
      _b_x987_989 = kk_std_core_types__new_Nil(_ctx); /*list<4264>*/
    }
    else {
      _b_x987_989 = kk_std_core_list__unroll_lift_reverse_append_4948_10003(kk_std_core_types__new_Nil(_ctx), acc, _ctx); /*list<4264>*/
    }
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x987_989, _ctx), kk_std_core_types__list_box(ys, _ctx), _ctx);
  }
  {
    return kk_std_core_list__unroll_lift_span_4957_10025(predicate, ys, acc, _ctx);
  }
}

kk_std_core_types__tuple2 kk_std_core_list_span(kk_std_core_types__list xs, kk_function_t predicate, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e (list<a>, list<a>) */ 

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_take_while_10026_10711(kk_std_core_types__cctx _acc, kk_function_t predicate, kk_box_t x, kk_std_core_types__list xx, bool _y_x10619, kk_context_t* _ctx); /* forall<a,e> (ctx<list<a>>, predicate : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 

kk_std_core_types__list kk_std_core_list__trmc_unroll_take_while_10026(kk_std_core_types__list xs, kk_function_t predicate_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool, ctx<list<a>>) -> e list<a> */ 

kk_std_core_types__list kk_std_core_list__unroll_take_while_10026(kk_std_core_types__list xs_0, kk_function_t predicate_1, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-take-while@10026

static inline kk_std_core_types__list kk_std_core_list_take_while(kk_std_core_types__list xs, kk_function_t predicate, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(predicate, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_take_while_10026(xs, predicate, _ctx);
  }
}

kk_string_t kk_std_core_list_reverse_join(kk_std_core_types__list xs, kk_context_t* _ctx); /* (xs : list<string>) -> string */ 
 
// Append `end` to each string in the list `xs` and join them all together.
// `join-end([],end) === ""`
// `join-end(["a","b"],"/") === "a/b/"`

static inline kk_string_t kk_std_core_list_join_end(kk_std_core_types__list xs, kk_string_t end, kk_context_t* _ctx) { /* (xs : list<string>, end : string) -> string */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_string_drop(end, _ctx);
    return kk_string_empty();
  }
  {
    kk_string_t _x_x1761;
    kk_string_t _x_x1762 = kk_string_dup(end, _ctx); /*string*/
    _x_x1761 = kk_std_core_list_joinsep(xs, _x_x1762, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x1761, end, _ctx);
  }
}

kk_std_core_types__list kk_std_core_list__trmc_lift_concat_4958(kk_std_core_types__list ys, kk_std_core_types__list zss, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a> (ys : list<a>, zss : list<list<a>>, ctx<list<a>>) -> list<a> */ 

kk_std_core_types__list kk_std_core_list__lift_concat_4958(kk_std_core_types__list ys_0, kk_std_core_types__list zss_0, kk_context_t* _ctx); /* forall<a> (ys : list<a>, zss : list<list<a>>) -> list<a> */ 
 
// Concatenate all lists in a list (e.g. flatten the list). (tail-recursive)

static inline kk_std_core_types__list kk_std_core_list_concat(kk_std_core_types__list xss, kk_context_t* _ctx) { /* forall<a> (xss : list<list<a>>) -> list<a> */ 
  return kk_std_core_list__lift_concat_4958(kk_std_core_types__new_Nil(_ctx), xss, _ctx);
}

kk_std_core_types__list kk_std_core_list__mlift_trmc_lift_flatmap_4959_10712(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list zz, kk_std_core_types__list ys_1_10132, kk_context_t* _ctx); /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e list<b>, zz : list<a>, ys@1@10132 : list<b>) -> e list<b> */ 

kk_std_core_types__list kk_std_core_list__trmc_lift_flatmap_4959(kk_function_t f_0, kk_std_core_types__list ys, kk_std_core_types__list zs, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>, ctx<list<b>>) -> e list<b> */ 

kk_std_core_types__list kk_std_core_list__lift_flatmap_4959(kk_function_t f_1, kk_std_core_types__list ys_0, kk_std_core_types__list zs_0, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>) -> e list<b> */ 
 
// Concatenate the result lists from applying a function to all elements.

static inline kk_std_core_types__list kk_std_core_list_flatmap(kk_std_core_types__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e list<b>) -> e list<b> */ 
  return kk_std_core_list__lift_flatmap_4959(f, kk_std_core_types__new_Nil(_ctx), xs, _ctx);
}

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_flatmap_maybe_10027_10713(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10633, kk_context_t* _ctx); /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 

kk_std_core_types__list kk_std_core_list__trmc_unroll_flatmap_maybe_10027(kk_std_core_types__list xs, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */ 

kk_std_core_types__list kk_std_core_list__unroll_flatmap_maybe_10027(kk_std_core_types__list xs_0, kk_function_t f_1, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>) -> e list<b> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-flatmap-maybe@10027

static inline kk_std_core_types__list kk_std_core_list_flatmap_maybe(kk_std_core_types__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_flatmap_maybe_10027(xs, f, _ctx);
  }
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_concat_maybe_10028(kk_std_core_types__list xs, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a> (xs : list<maybe<a>>, ctx<list<a>>) -> list<a> */ 

kk_std_core_types__list kk_std_core_list__unroll_concat_maybe_10028(kk_std_core_types__list xs_0, kk_context_t* _ctx); /* forall<a> (xs : list<maybe<a>>) -> list<a> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-concat-maybe@10028

static inline kk_std_core_types__list kk_std_core_list_concat_maybe(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<maybe<a>>) -> list<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_concat_maybe_10028(xs, _ctx);
  }
}

kk_std_core_types__maybe kk_std_core_list_last(kk_std_core_types__list xs, kk_context_t* _ctx); /* forall<a> (xs : list<a>) -> maybe<a> */ 

kk_std_core_types__list kk_std_core_list__trmc_init(kk_std_core_types__list xs, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a> (xs : list<a>, ctx<list<a>>) -> list<a> */ 

kk_std_core_types__list kk_std_core_list_init(kk_std_core_types__list xs_0, kk_context_t* _ctx); /* forall<a> (xs : list<a>) -> list<a> */ 

kk_std_core_types__maybe kk_std_core_list__unroll_index_10029(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx); /* forall<a> (xs : list<a>, n : int) -> maybe<a> */ 
 
// unrolling of singleton matches of std/core/list/@unroll-index@10029

static inline kk_std_core_types__maybe kk_std_core_list__index(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> maybe<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_integer_drop(n, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    return kk_std_core_list__unroll_index_10029(xs, n, _ctx);
  }
}

bool kk_std_core_list__mlift_unroll_all_10030_10714(kk_function_t predicate, kk_std_core_types__list xx, bool _y_x10641, kk_context_t* _ctx); /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */ 

bool kk_std_core_list__unroll_all_10030(kk_std_core_types__list xs, kk_function_t predicate_0, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 
 
// unrolling of singleton matches of std/core/list/@unroll-all@10030

static inline bool kk_std_core_list_all(kk_std_core_types__list xs, kk_function_t predicate, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(predicate, _ctx);
    return true;
  }
  {
    return kk_std_core_list__unroll_all_10030(xs, predicate, _ctx);
  }
}

bool kk_std_core_list__mlift_unroll_any_10031_10715(kk_function_t predicate, kk_std_core_types__list xx, bool _y_x10647, kk_context_t* _ctx); /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */ 

bool kk_std_core_list__unroll_any_10031(kk_std_core_types__list xs, kk_function_t predicate_0, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 
 
// unrolling of singleton matches of std/core/list/@unroll-any@10031

static inline bool kk_std_core_list_any(kk_std_core_types__list xs, kk_function_t predicate, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(predicate, _ctx);
    return false;
  }
  {
    return kk_std_core_list__unroll_any_10031(xs, predicate, _ctx);
  }
}

kk_integer_t kk_std_core_list__lift_sum_10369(kk_std_core_types__list _uniq_xs_10339, kk_integer_t _uniq_z_10340, kk_context_t* _ctx); /* (list<int>, int) -> int */ 
 
// Return the sum of a list of integers

static inline kk_integer_t kk_std_core_list_sum(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<int>) -> int */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return kk_integer_from_small(0);
  }
  {
    return kk_std_core_list__lift_sum_10369(xs, kk_integer_from_small(0), _ctx);
  }
}

kk_integer_t kk_std_core_list__lift_minimum_10370(kk_std_core_types__list _uniq_xs_10347, kk_integer_t _uniq_z_10348, kk_context_t* _ctx); /* (list<int>, int) -> int */ 

kk_integer_t kk_std_core_list_minimum(kk_std_core_types__list xs, kk_std_core_types__optional kkloc_default, kk_context_t* _ctx); /* (xs : list<int>, default : ? int) -> int */ 

kk_integer_t kk_std_core_list__lift_maximum_10371(kk_std_core_types__list _uniq_xs_10355, kk_integer_t _uniq_z_10356, kk_context_t* _ctx); /* (list<int>, int) -> int */ 

kk_integer_t kk_std_core_list_maximum(kk_std_core_types__list xs, kk_std_core_types__optional kkloc_default, kk_context_t* _ctx); /* (xs : list<int>, default : ? int) -> int */ 
 
// Split a string into a list of lines

static inline kk_std_core_types__list kk_std_core_list_lines(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> list<string> */ 
  kk_vector_t v_10019;
  kk_string_t _x_x1817;
  kk_define_string_literal(, _s_x1818, 1, "\n", _ctx)
  _x_x1817 = kk_string_dup(_s_x1818, _ctx); /*string*/
  v_10019 = kk_string_splitv(s,_x_x1817,kk_context()); /*vector<string>*/
  return kk_std_core_vector_vlist(v_10019, kk_std_core_types__new_None(_ctx), _ctx);
}

kk_string_t kk_std_core_list_unlines(kk_std_core_types__list xs, kk_context_t* _ctx); /* (xs : list<string>) -> string */ 

void kk_std_core_list__init(kk_context_t* _ctx);


void kk_std_core_list__done(kk_context_t* _ctx);

#endif // header
