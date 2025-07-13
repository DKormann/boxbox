// Koka generated module: std/core/list, koka version: 3.1.2, platform: 32-bit
#include "std_core_list.h"
 
// Return the head of list if the list is not empty.

kk_std_core_types__maybe kk_std_core_list_head(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> maybe<a> */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1304 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1304->head;
    kk_std_core_types__list _pat_0 = _con_x1304->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_std_core_types__list_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    return kk_std_core_types__new_Just(x, _ctx);
  }
  {
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Return the head of list with a default value in case the list is empty.

kk_box_t kk_std_core_list_default_fs_head(kk_std_core_types__list xs, kk_box_t kkloc_default, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, default : a) -> a */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1305 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1305->head;
    kk_std_core_types__list _pat_0 = _con_x1305->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_std_core_types__list_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_box_drop(kkloc_default, _ctx);
    return x;
  }
  {
    return kkloc_default;
  }
}
 
// Return the tail of list. Returns the empty list if `xs` is empty.

kk_std_core_types__list kk_std_core_list_tail(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> list<a> */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1306 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _pat_0 = _con_x1306->head;
    kk_std_core_types__list xx = _con_x1306->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_box_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    return xx;
  }
  {
    return kk_std_core_types__new_Nil(_ctx);
  }
}
 
// lifted local: length, len

kk_integer_t kk_std_core_list__unroll_lift_length_4947_10000(kk_std_core_types__list ys, kk_integer_t acc, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, acc : int) -> int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1307 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t _pat_0 = _con_x1307->head;
    kk_std_core_types__list yy = _con_x1307->tail;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      kk_box_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(ys, _ctx);
    }
    else {
      kk_std_core_types__list_dup(yy, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x1308 = kk_integer_add_small_const(acc, 1, _ctx); /*int*/
      ys = yy;
      acc = _x_x1308;
      goto kk__tailcall;
    }
  }
  {
    return acc;
  }
}
 
// Element-wise list equality

bool kk_std_core_list__lp__at_unroll_x_10001_eq__eq__rp_(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t _implicit_fs__lp__eq__eq__rp_, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>, ?(==) : (a, a) -> bool) -> bool */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1309 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1309->head;
    kk_std_core_types__list xx = _con_x1309->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      kk_function_drop(_implicit_fs__lp__eq__eq__rp_, _ctx);
      kk_std_core_types__list_drop(xx, _ctx);
      kk_box_drop(x, _ctx);
      return false;
    }
    {
      struct kk_std_core_types_Cons* _con_x1310 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1310->head;
      kk_std_core_types__list yy = _con_x1310->tail;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        kk_datatype_ptr_free(ys, _ctx);
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      bool _match_x1218;
      kk_function_t _x_x1311 = kk_function_dup(_implicit_fs__lp__eq__eq__rp_, _ctx); /*(761, 761) -> bool*/
      _match_x1218 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1311, (_x_x1311, x, y, _ctx), _ctx); /*bool*/
      if (_match_x1218) { // tailcall
                          xs = xx;
                          ys = yy;
                          goto kk__tailcall;
      }
      {
        kk_function_drop(_implicit_fs__lp__eq__eq__rp_, _ctx);
        kk_std_core_types__list_drop(yy, _ctx);
        kk_std_core_types__list_drop(xx, _ctx);
        return false;
      }
    }
  }
  {
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
}
 
// Order on lists

kk_std_core_types__order kk_std_core_list__unroll_cmp_10002(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t _implicit_fs_cmp, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>, ?cmp : (a, a) -> order) -> order */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1314 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1314->head;
    kk_std_core_types__list xx = _con_x1314->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      kk_function_drop(_implicit_fs_cmp, _ctx);
      kk_std_core_types__list_drop(xx, _ctx);
      kk_box_drop(x, _ctx);
      return kk_std_core_types__new_Gt(_ctx);
    }
    {
      struct kk_std_core_types_Cons* _con_x1315 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1315->head;
      kk_std_core_types__list yy = _con_x1315->tail;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        kk_datatype_ptr_free(ys, _ctx);
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      kk_std_core_types__order _match_x1217;
      kk_function_t _x_x1316 = kk_function_dup(_implicit_fs_cmp, _ctx); /*(830, 830) -> order*/
      _match_x1217 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1316, (_x_x1316, x, y, _ctx), _ctx); /*order*/
      if (kk_std_core_types__is_Eq(_match_x1217, _ctx)) { // tailcall
                                                          xs = xx;
                                                          ys = yy;
                                                          goto kk__tailcall;
      }
      {
        kk_function_drop(_implicit_fs_cmp, _ctx);
        kk_std_core_types__list_drop(yy, _ctx);
        kk_std_core_types__list_drop(xx, _ctx);
        return _match_x1217;
      }
    }
  }
  {
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
}
 
// Take the first `n` elements of a list (or fewer if the list is shorter than `n`)

kk_std_core_types__list kk_std_core_list__trmc_take(kk_std_core_types__list xs, kk_integer_t n, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1319 = kk_std_core_types__as_Cons(xs, _ctx);
    if (kk_integer_gt_borrow(n,(kk_integer_from_small(0)),kk_context())) {
      kk_box_t x = _con_x1319->head;
      kk_std_core_types__list xx = _con_x1319->tail;
      kk_reuse_t _ru_x1231 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        _ru_x1231 = (kk_datatype_ptr_reuse(xs, _ctx));
      }
      else {
        kk_box_dup(x, _ctx);
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      kk_std_core_types__list _trmc_x10379 = kk_datatype_null(); /*list<879>*/;
      kk_std_core_types__list _trmc_x10380 = kk_std_core_types__new_Cons(_ru_x1231, 0, x, _trmc_x10379, _ctx); /*list<879>*/;
      kk_field_addr_t _b_x5_10 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10380, _ctx)->tail, _ctx); /*@field-addr<list<879>>*/;
      { // tailcall
        kk_integer_t _x_x1320 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
        kk_std_core_types__cctx _x_x1321 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10380, _ctx)),_b_x5_10,kk_context()); /*ctx<0>*/
        xs = xx;
        n = _x_x1320;
        _acc = _x_x1321;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_std_core_types__list_drop(xs, _ctx);
    kk_integer_drop(n, _ctx);
    kk_box_t _x_x1322 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1322, KK_OWNED, _ctx);
  }
}
 
// Take the first `n` elements of a list (or fewer if the list is shorter than `n`)

kk_std_core_types__list kk_std_core_list_take(kk_std_core_types__list xs_0, kk_integer_t n_0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> list<a> */ 
  kk_std_core_types__cctx _x_x1323 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_take(xs_0, n_0, _x_x1323, _ctx);
}
 
// Drop the first `n` elements of a list (or fewer if the list is shorter than `n`)

kk_std_core_types__list kk_std_core_list_drop(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1324 = kk_std_core_types__as_Cons(xs, _ctx);
    if (kk_integer_gt_borrow(n,(kk_integer_from_small(0)),kk_context())) {
      kk_box_t _pat_0 = _con_x1324->head;
      kk_std_core_types__list xx = _con_x1324->tail;
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_box_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      { // tailcall
        kk_integer_t _x_x1325 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
        xs = xx;
        n = _x_x1325;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(n, _ctx);
    return xs;
  }
}
 
// lifted local: reverse-append, reverse-acc

kk_std_core_types__list kk_std_core_list__unroll_lift_reverse_append_4948_10003(kk_std_core_types__list acc, kk_std_core_types__list ys, kk_context_t* _ctx) { /* forall<a> (acc : list<a>, ys : list<a>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1326 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t x = _con_x1326->head;
    kk_std_core_types__list xx = _con_x1326->tail;
    kk_reuse_t _ru_x1233 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1233 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    { // tailcall
      kk_std_core_types__list _x_x1327 = kk_std_core_types__new_Cons(_ru_x1233, 0, x, acc, _ctx); /*list<82>*/
      acc = _x_x1327;
      ys = xx;
      goto kk__tailcall;
    }
  }
  {
    return acc;
  }
}
 
// Append two lists.

kk_std_core_types__list kk_std_core_list__trmc_unroll_append_10004(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1328 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1328->head;
    kk_std_core_types__list xx = _con_x1328->tail;
    kk_reuse_t _ru_x1234 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1234 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__list _trmc_x10381 = kk_datatype_null(); /*list<1016>*/;
    kk_std_core_types__list _trmc_x10382 = kk_std_core_types__new_Cons(_ru_x1234, 0, x, _trmc_x10381, _ctx); /*list<1016>*/;
    kk_field_addr_t _b_x21_26 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10382, _ctx)->tail, _ctx); /*@field-addr<list<1016>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1329 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10382, _ctx)),_b_x21_26,kk_context()); /*ctx<0>*/
      xs = xx;
      _acc = _x_x1329;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1330 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(ys, _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1330, KK_OWNED, _ctx);
  }
}
 
// Append two lists.

kk_std_core_types__list kk_std_core_list__unroll_append_10004(kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */ 
  kk_std_core_types__cctx _x_x1331 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_append_10004(xs_0, ys_0, _x_x1331, _ctx);
}
 
// monadic lift

kk_box_t kk_std_core_list__mlift_unroll_foldl_10005_10682(kk_function_t f, kk_std_core_types__list xx, kk_box_t _y_x10440, kk_context_t* _ctx) { /* forall<a,b,e> (f : (b, a) -> e b, xx : list<a>, b) -> e b */ 
  return kk_std_core_list__unroll_foldl_10005(xx, _y_x10440, f, _ctx);
}
 
// Fold a list from the left, i.e. `foldl([1,2],0,(+)) == (0+1)+2`
// Since `foldl` is tail recursive, it is preferred over `foldr` when using an associative function `f`


// lift anonymous function
struct kk_std_core_list__unroll_foldl_10005_fun1334__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_foldl_10005_fun1334(kk_function_t _fself, kk_box_t _y_x10440_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_foldl_10005_fun1334(kk_function_t f_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foldl_10005_fun1334__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_foldl_10005_fun1334__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_foldl_10005_fun1334, kk_context());
  _self->f_0 = f_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_foldl_10005_fun1334(kk_function_t _fself, kk_box_t _y_x10440_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foldl_10005_fun1334__t* _self = kk_function_as(struct kk_std_core_list__unroll_foldl_10005_fun1334__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (1073, 1072) -> 1074 1073 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1072> */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  return kk_std_core_list__mlift_unroll_foldl_10005_10682(f_0, xx_0, _y_x10440_0, _ctx);
}

kk_box_t kk_std_core_list__unroll_foldl_10005(kk_std_core_types__list xs, kk_box_t z, kk_function_t f_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, z : b, f : (b, a) -> e b) -> e b */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1332 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1332->head;
    kk_std_core_types__list xx_0 = _con_x1332->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_box_t x_0_10714;
    kk_function_t _x_x1333 = kk_function_dup(f_0, _ctx); /*(1073, 1072) -> 1074 1073*/
    x_0_10714 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1333, (_x_x1333, z, x, _ctx), _ctx); /*1073*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10714, _ctx);
      return kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_foldl_10005_fun1334(f_0, xx_0, _ctx), _ctx);
    }
    { // tailcall
      xs = xx_0;
      z = x_0_10714;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    return z;
  }
}
 
// monadic lift

kk_box_t kk_std_core_list__mlift_lift_foldr_10363_10683(kk_std_core_types__list _uniq_xx_10288, kk_function_t f, kk_box_t _uniq_z_10284_0_10373, kk_context_t* _ctx) { /* forall<a,b,e> (list<a>, f : (a, b) -> e b, b) -> e b */ 
  return kk_std_core_list__lift_foldr_10363(f, _uniq_xx_10288, _uniq_z_10284_0_10373, _ctx);
}
 
// lifted local: foldr, @spec-x10290
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10285, using:
// @uniq-f@10285 = fn<(e :: E)>(x: 1117, y: 1116){
//   f(y, x);
// }


// lift anonymous function
struct kk_std_core_list__lift_foldr_10363_fun1337__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10288_0;
  kk_function_t f_0;
};
static kk_box_t kk_std_core_list__lift_foldr_10363_fun1337(kk_function_t _fself, kk_box_t _uniq_z_10284_0_10373_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_foldr_10363_fun1337(kk_std_core_types__list _uniq_xx_10288_0, kk_function_t f_0, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foldr_10363_fun1337__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_foldr_10363_fun1337__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_foldr_10363_fun1337, kk_context());
  _self->_uniq_xx_10288_0 = _uniq_xx_10288_0;
  _self->f_0 = f_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_foldr_10363_fun1337(kk_function_t _fself, kk_box_t _uniq_z_10284_0_10373_0, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foldr_10363_fun1337__t* _self = kk_function_as(struct kk_std_core_list__lift_foldr_10363_fun1337__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10288_0 = _self->_uniq_xx_10288_0; /* list<1116> */
  kk_function_t f_0 = _self->f_0; /* (1116, 1117) -> 1118 1117 */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10288_0, _ctx);kk_function_dup(f_0, _ctx);}, {}, _ctx)
  return kk_std_core_list__mlift_lift_foldr_10363_10683(_uniq_xx_10288_0, f_0, _uniq_z_10284_0_10373_0, _ctx);
}

kk_box_t kk_std_core_list__lift_foldr_10363(kk_function_t f_0, kk_std_core_types__list _uniq_xs_10283, kk_box_t _uniq_z_10284, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a, b) -> e b, list<a>, b) -> e b */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10283, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1335 = kk_std_core_types__as_Cons(_uniq_xs_10283, _ctx);
    kk_box_t _uniq_x_10287 = _con_x1335->head;
    kk_std_core_types__list _uniq_xx_10288_0 = _con_x1335->tail;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10283, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10283, _ctx);
    }
    else {
      kk_box_dup(_uniq_x_10287, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10288_0, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10283, _ctx);
    }
    kk_box_t x_10717;
    kk_function_t _x_x1336 = kk_function_dup(f_0, _ctx); /*(1116, 1117) -> 1118 1117*/
    x_10717 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1336, (_x_x1336, _uniq_x_10287, _uniq_z_10284, _ctx), _ctx); /*1117*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_10717, _ctx);
      return kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_foldr_10363_fun1337(_uniq_xx_10288_0, f_0, _ctx), _ctx);
    }
    { // tailcall
      _uniq_xs_10283 = _uniq_xx_10288_0;
      _uniq_z_10284 = x_10717;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    return _uniq_z_10284;
  }
}


// lift anonymous function
struct kk_std_core_list_foldl1_fun1340__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_foldl1_fun1340(kk_function_t _fself, kk_box_t _b_x36, kk_box_t _b_x37, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_foldl1_fun1340(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_foldl1_fun1340, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_foldl1_fun1340(kk_function_t _fself, kk_box_t _b_x36, kk_box_t _b_x37, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t _x_x1341 = kk_string_unbox(_b_x36); /*string*/
  kk_std_core_types__optional _x_x1342 = kk_std_core_types__optional_unbox(_b_x37, KK_OWNED, _ctx); /*? exception-info*/
  return kk_std_core_exn_throw(_x_x1341, _x_x1342, _ctx);
}

kk_box_t kk_std_core_list_foldl1(kk_std_core_types__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1338 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1338->head;
    kk_std_core_types__list xx = _con_x1338->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Nil(xx, _ctx)) {
      kk_function_drop(f, _ctx);
      return x;
    }
    {
      return kk_std_core_list__unroll_foldl_10005(xx, x, f, _ctx);
    }
  }
  {
    kk_function_drop(f, _ctx);
    kk_ssize_t _b_x32_38;
    kk_std_core_hnd__htag _x_x1339 = kk_std_core_hnd__htag_dup(kk_std_core_exn__tag_exn, _ctx); /*hnd/htag<exn>*/
    _b_x32_38 = kk_std_core_hnd__evv_index(_x_x1339, _ctx); /*hnd/ev-index*/
    kk_box_t _x_x1343;
    kk_string_t _x_x1344;
    kk_define_string_literal(, _s_x1345, 33, "unexpected Nil in std/core/foldl1", _ctx)
    _x_x1344 = kk_string_dup(_s_x1345, _ctx); /*string*/
    _x_x1343 = kk_string_box(_x_x1344); /*9232*/
    return kk_std_core_hnd__open_at2(_b_x32_38, kk_std_core_list_new_foldl1_fun1340(_ctx), _x_x1343, kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_core_list_foldr1_fun1347__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_foldr1_fun1347(kk_function_t _fself, kk_box_t _b_x44, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_foldr1_fun1347(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_foldr1_fun1347, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_foldr1_fun1347(kk_function_t _fself, kk_box_t _b_x44, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_std_core_types__list _x_x1348;
  kk_std_core_types__list _match_x1214;
  kk_box_t _x_x1349 = kk_box_dup(_b_x44, _ctx); /*8579*/
  _match_x1214 = kk_std_core_types__list_unbox(_x_x1349, KK_OWNED, _ctx); /*list<1195>*/
  if (kk_std_core_types__is_Nil(_match_x1214, _ctx)) {
    kk_box_drop(_b_x44, _ctx);
    _x_x1348 = kk_std_core_types__new_Nil(_ctx); /*forall<a> list<a>*/
  }
  else {
    kk_std_core_types__list_drop(_match_x1214, _ctx);
    kk_std_core_types__list _x_x1350 = kk_std_core_types__list_unbox(_b_x44, KK_OWNED, _ctx); /*list<1195>*/
    _x_x1348 = kk_std_core_list__unroll_lift_reverse_append_4948_10003(kk_std_core_types__new_Nil(_ctx), _x_x1350, _ctx); /*forall<a> list<a>*/
  }
  return kk_std_core_types__list_box(_x_x1348, _ctx);
}


// lift anonymous function
struct kk_std_core_list_foldr1_fun1353__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_foldr1_fun1353(kk_function_t _fself, kk_box_t _b_x52, kk_box_t _b_x53, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_foldr1_fun1353(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_foldr1_fun1353, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_foldr1_fun1353(kk_function_t _fself, kk_box_t _b_x52, kk_box_t _b_x53, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t _x_x1354 = kk_string_unbox(_b_x52); /*string*/
  kk_std_core_types__optional _x_x1355 = kk_std_core_types__optional_unbox(_b_x53, KK_OWNED, _ctx); /*? exception-info*/
  return kk_std_core_exn_throw(_x_x1354, _x_x1355, _ctx);
}

kk_box_t kk_std_core_list_foldr1(kk_std_core_types__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */ 
  kk_std_core_types__list xs_0_10050;
  kk_box_t _x_x1346 = kk_std_core_hnd__open_none1(kk_std_core_list_new_foldr1_fun1347(_ctx), kk_std_core_types__list_box(xs, _ctx), _ctx); /*8580*/
  xs_0_10050 = kk_std_core_types__list_unbox(_x_x1346, KK_OWNED, _ctx); /*list<1195>*/
  if (kk_std_core_types__is_Cons(xs_0_10050, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1351 = kk_std_core_types__as_Cons(xs_0_10050, _ctx);
    kk_box_t x = _con_x1351->head;
    kk_std_core_types__list xx = _con_x1351->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs_0_10050, _ctx)) {
      kk_datatype_ptr_free(xs_0_10050, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs_0_10050, _ctx);
    }
    if (kk_std_core_types__is_Nil(xx, _ctx)) {
      kk_function_drop(f, _ctx);
      return x;
    }
    {
      return kk_std_core_list__unroll_foldl_10005(xx, x, f, _ctx);
    }
  }
  {
    kk_function_drop(f, _ctx);
    kk_ssize_t _b_x48_54;
    kk_std_core_hnd__htag _x_x1352 = kk_std_core_hnd__htag_dup(kk_std_core_exn__tag_exn, _ctx); /*hnd/htag<exn>*/
    _b_x48_54 = kk_std_core_hnd__evv_index(_x_x1352, _ctx); /*hnd/ev-index*/
    kk_box_t _x_x1356;
    kk_string_t _x_x1357;
    kk_define_string_literal(, _s_x1358, 33, "unexpected Nil in std/core/foldl1", _ctx)
    _x_x1357 = kk_string_dup(_s_x1358, _ctx); /*string*/
    _x_x1356 = kk_string_box(_x_x1357); /*9232*/
    return kk_std_core_hnd__open_at2(_b_x48_54, kk_std_core_list_new_foldr1_fun1353(_ctx), _x_x1356, kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx);
  }
}
 
// split a list at position `n`

kk_std_core_types__tuple2 kk_std_core_list_split(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> (list<a>, list<a>) */ 
  kk_std_core_types__list _b_x58_60;
  kk_std_core_types__list _x_x1359 = kk_std_core_types__list_dup(xs, _ctx); /*list<1233>*/
  kk_integer_t _x_x1360 = kk_integer_dup(n, _ctx); /*int*/
  _b_x58_60 = kk_std_core_list_take(_x_x1359, _x_x1360, _ctx); /*list<1233>*/
  kk_std_core_types__list _b_x59_61 = kk_std_core_list_drop(xs, n, _ctx); /*list<1233>*/;
  return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x58_60, _ctx), kk_std_core_types__list_box(_b_x59_61, _ctx), _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_unroll_drop_while_10006_10684(kk_function_t predicate, kk_std_core_types__list xs, kk_std_core_types__list xx, bool _y_x10458, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, xs : list<a>, xx : list<a>, bool) -> e list<a> */ 
  if (_y_x10458) {
    kk_std_core_types__list_drop(xs, _ctx);
    return kk_std_core_list__unroll_drop_while_10006(xx, predicate, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(predicate, _ctx);
    return xs;
  }
}
 
// Drop all initial elements that satisfy `predicate`


// lift anonymous function
struct kk_std_core_list__unroll_drop_while_10006_fun1364__t {
  struct kk_function_s _base;
  kk_function_t predicate_0;
  kk_std_core_types__list xs_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_drop_while_10006_fun1364(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_drop_while_10006_fun1364(kk_function_t predicate_0, kk_std_core_types__list xs_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_drop_while_10006_fun1364__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_drop_while_10006_fun1364__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_drop_while_10006_fun1364, kk_context());
  _self->predicate_0 = predicate_0;
  _self->xs_0 = xs_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_drop_while_10006_fun1364(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_drop_while_10006_fun1364__t* _self = kk_function_as(struct kk_std_core_list__unroll_drop_while_10006_fun1364__t*, _fself, _ctx);
  kk_function_t predicate_0 = _self->predicate_0; /* (1270) -> 1271 bool */
  kk_std_core_types__list xs_0 = _self->xs_0; /* list<1270> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1270> */
  kk_drop_match(_self, {kk_function_dup(predicate_0, _ctx);kk_std_core_types__list_dup(xs_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10458_0_65 = kk_bool_unbox(_b_x63); /*bool*/;
  kk_std_core_types__list _x_x1365 = kk_std_core_list__mlift_unroll_drop_while_10006_10684(predicate_0, xs_0, xx_0, _y_x10458_0_65, _ctx); /*list<1270>*/
  return kk_std_core_types__list_box(_x_x1365, _ctx);
}

kk_std_core_types__list kk_std_core_list__unroll_drop_while_10006(kk_std_core_types__list xs_0, kk_function_t predicate_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs_0, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1361 = kk_std_core_types__as_Cons(xs_0, _ctx);
    kk_box_t x = _con_x1361->head;
    kk_std_core_types__list xx_0 = _con_x1361->tail;
    kk_box_dup(x, _ctx);
    kk_std_core_types__list_dup(xx_0, _ctx);
    bool x_0_10720;
    kk_function_t _x_x1362 = kk_function_dup(predicate_0, _ctx); /*(1270) -> 1271 bool*/
    x_0_10720 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1362, (_x_x1362, x, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1363 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_drop_while_10006_fun1364(predicate_0, xs_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1363, KK_OWNED, _ctx);
    }
    if (x_0_10720) {
      if kk_likely(kk_datatype_ptr_is_unique(xs_0, _ctx)) {
        kk_std_core_types__list_drop(xx_0, _ctx);
        kk_box_drop(x, _ctx);
        kk_datatype_ptr_free(xs_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(xs_0, _ctx);
      }
      { // tailcall
        xs_0 = xx_0;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      return xs_0;
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_filter_10007_10685(kk_std_core_types__cctx _acc, kk_function_t pred, kk_box_t x, kk_std_core_types__list xx, bool _y_x10464, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 
  if (_y_x10464) {
    kk_std_core_types__list _trmc_x10383 = kk_datatype_null(); /*list<1325>*/;
    kk_std_core_types__list _trmc_x10384 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _trmc_x10383, _ctx); /*list<1325>*/;
    kk_field_addr_t _b_x71_74 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10384, _ctx)->tail, _ctx); /*@field-addr<list<1325>>*/;
    kk_std_core_types__cctx _x_x1366 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10384, _ctx)),_b_x71_74,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_unroll_filter_10007(xx, pred, _x_x1366, _ctx);
  }
  {
    kk_box_drop(x, _ctx);
    return kk_std_core_list__trmc_unroll_filter_10007(xx, pred, _acc, _ctx);
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filter([1,2,3],odd?) == [1,3]`


// lift anonymous function
struct kk_std_core_list__trmc_unroll_filter_10007_fun1371__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t pred_0;
  kk_box_t x_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_filter_10007_fun1371(kk_function_t _fself, kk_box_t _b_x79, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_filter_10007_fun1371(kk_std_core_types__cctx _acc_0, kk_function_t pred_0, kk_box_t x_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_filter_10007_fun1371__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_filter_10007_fun1371__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_filter_10007_fun1371, kk_context());
  _self->_acc_0 = _acc_0;
  _self->pred_0 = pred_0;
  _self->x_0 = x_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_filter_10007_fun1371(kk_function_t _fself, kk_box_t _b_x79, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_filter_10007_fun1371__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_filter_10007_fun1371__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<1325>> */
  kk_function_t pred_0 = _self->pred_0; /* (1325) -> 1326 bool */
  kk_box_t x_0 = _self->x_0; /* 1325 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1325> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(pred_0, _ctx);kk_box_dup(x_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10464_0_97 = kk_bool_unbox(_b_x79); /*bool*/;
  kk_std_core_types__list _x_x1372 = kk_std_core_list__mlift_trmc_unroll_filter_10007_10685(_acc_0, pred_0, x_0, xx_0, _y_x10464_0_97, _ctx); /*list<1325>*/
  return kk_std_core_types__list_box(_x_x1372, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_filter_10007(kk_std_core_types__list xs, kk_function_t pred_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1367 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x_0 = _con_x1367->head;
    kk_std_core_types__list xx_0 = _con_x1367->tail;
    kk_reuse_t _ru_x1240 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1240 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x_0, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_1_10723;
    kk_function_t _x_x1369 = kk_function_dup(pred_0, _ctx); /*(1325) -> 1326 bool*/
    kk_box_t _x_x1368 = kk_box_dup(x_0, _ctx); /*1325*/
    x_1_10723 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1369, (_x_x1369, _x_x1368, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1240,kk_context());
      kk_box_t _x_x1370 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_filter_10007_fun1371(_acc_0, pred_0, x_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1370, KK_OWNED, _ctx);
    }
    if (x_1_10723) {
      kk_std_core_types__list _trmc_x10383_0 = kk_datatype_null(); /*list<1325>*/;
      kk_std_core_types__list _trmc_x10384_0 = kk_std_core_types__new_Cons(_ru_x1240, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0, _trmc_x10383_0, _ctx); /*list<1325>*/;
      kk_field_addr_t _b_x85_91 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10384_0, _ctx)->tail, _ctx); /*@field-addr<list<1325>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1373 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10384_0, _ctx)),_b_x85_91,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1373;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1240,kk_context());
      kk_box_drop(x_0, _ctx);
      { // tailcall
        xs = xx_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(pred_0, _ctx);
    kk_box_t _x_x1374 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1374, KK_OWNED, _ctx);
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filter([1,2,3],odd?) == [1,3]`

kk_std_core_types__list kk_std_core_list__unroll_filter_10007(kk_std_core_types__list xs_0, kk_function_t pred_1, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1375 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_filter_10007(xs_0, pred_1, _x_x1375, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_filter_map_10008_10686(kk_std_core_types__cctx _acc, kk_function_t pred, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10472, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, pred : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Nothing(_y_x10472, _ctx)) {
    return kk_std_core_list__trmc_unroll_filter_map_10008(xx, pred, _acc, _ctx);
  }
  {
    kk_box_t y = _y_x10472._cons.Just.value;
    kk_std_core_types__list _trmc_x10385 = kk_datatype_null(); /*list<1393>*/;
    kk_std_core_types__list _trmc_x10386 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _trmc_x10385, _ctx); /*list<1393>*/;
    kk_field_addr_t _b_x103_106 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10386, _ctx)->tail, _ctx); /*@field-addr<list<1393>>*/;
    kk_std_core_types__cctx _x_x1376 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10386, _ctx)),_b_x103_106,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_unroll_filter_map_10008(xx, pred, _x_x1376, _ctx);
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if i.odd? then Nothing else Just(i*i) }) == [4]`


// lift anonymous function
struct kk_std_core_list__trmc_unroll_filter_map_10008_fun1381__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t pred_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_filter_map_10008_fun1381(kk_function_t _fself, kk_box_t _b_x113, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_filter_map_10008_fun1381(kk_std_core_types__cctx _acc_0, kk_function_t pred_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_filter_map_10008_fun1381__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_filter_map_10008_fun1381__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_filter_map_10008_fun1381, kk_context());
  _self->_acc_0 = _acc_0;
  _self->pred_0 = pred_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_filter_map_10008_fun1381(kk_function_t _fself, kk_box_t _b_x113, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_filter_map_10008_fun1381__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_filter_map_10008_fun1381__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<1393>> */
  kk_function_t pred_0 = _self->pred_0; /* (1392) -> 1394 maybe<1393> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1392> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(pred_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10472_0_129 = kk_std_core_types__maybe_unbox(_b_x113, KK_OWNED, _ctx); /*maybe<1393>*/;
  kk_std_core_types__list _x_x1382 = kk_std_core_list__mlift_trmc_unroll_filter_map_10008_10686(_acc_0, pred_0, xx_0, _y_x10472_0_129, _ctx); /*list<1393>*/
  return kk_std_core_types__list_box(_x_x1382, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_filter_map_10008(kk_std_core_types__list xs, kk_function_t pred_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(pred_0, _ctx);
    kk_box_t _x_x1377 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1377, KK_OWNED, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1378 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1378->head;
    kk_std_core_types__list xx_0 = _con_x1378->tail;
    kk_reuse_t _ru_x1241 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1241 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__maybe x_0_10726;
    kk_function_t _x_x1379 = kk_function_dup(pred_0, _ctx); /*(1392) -> 1394 maybe<1393>*/
    x_0_10726 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x1379, (_x_x1379, x, _ctx), _ctx); /*maybe<1393>*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1241,kk_context());
      kk_std_core_types__maybe_drop(x_0_10726, _ctx);
      kk_box_t _x_x1380 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_filter_map_10008_fun1381(_acc_0, pred_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1380, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_0_10726, _ctx)) {
      kk_reuse_drop(_ru_x1241,kk_context());
      { // tailcall
        xs = xx_0;
        goto kk__tailcall;
      }
    }
    {
      kk_box_t y_0 = x_0_10726._cons.Just.value;
      kk_std_core_types__list _trmc_x10385_0 = kk_datatype_null(); /*list<1393>*/;
      kk_std_core_types__list _trmc_x10386_0 = kk_std_core_types__new_Cons(_ru_x1241, kk_field_index_of(struct kk_std_core_types_Cons, tail), y_0, _trmc_x10385_0, _ctx); /*list<1393>*/;
      kk_field_addr_t _b_x119_125 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10386_0, _ctx)->tail, _ctx); /*@field-addr<list<1393>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1383 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10386_0, _ctx)),_b_x119_125,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1383;
        goto kk__tailcall;
      }
    }
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if i.odd? then Nothing else Just(i*i) }) == [4]`

kk_std_core_types__list kk_std_core_list__unroll_filter_map_10008(kk_std_core_types__list xs_0, kk_function_t pred_1, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1384 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_filter_map_10008(xs_0, pred_1, _x_x1384, _ctx);
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_list__mlift_unroll_foreach_while_10009_10687(kk_function_t action, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10480, kk_context_t* _ctx) { /* forall<a,b,e> (action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e maybe<b> */ 
  if (kk_std_core_types__is_Nothing(_y_x10480, _ctx)) {
    return kk_std_core_list__unroll_foreach_while_10009(xx, action, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(action, _ctx);
    return _y_x10480;
  }
}
 
// Invoke `action` for each element of a list while `action` return `Nothing`


// lift anonymous function
struct kk_std_core_list__unroll_foreach_while_10009_fun1388__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_foreach_while_10009_fun1388(kk_function_t _fself, kk_box_t _b_x131, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_foreach_while_10009_fun1388(kk_function_t action_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foreach_while_10009_fun1388__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_foreach_while_10009_fun1388__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_foreach_while_10009_fun1388, kk_context());
  _self->action_0 = action_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_foreach_while_10009_fun1388(kk_function_t _fself, kk_box_t _b_x131, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foreach_while_10009_fun1388__t* _self = kk_function_as(struct kk_std_core_list__unroll_foreach_while_10009_fun1388__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (1453) -> 1455 maybe<1454> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1453> */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10480_0_133 = kk_std_core_types__maybe_unbox(_b_x131, KK_OWNED, _ctx); /*maybe<1454>*/;
  kk_std_core_types__maybe _x_x1389 = kk_std_core_list__mlift_unroll_foreach_while_10009_10687(action_0, xx_0, _y_x10480_0_133, _ctx); /*maybe<1454>*/
  return kk_std_core_types__maybe_box(_x_x1389, _ctx);
}

kk_std_core_types__maybe kk_std_core_list__unroll_foreach_while_10009(kk_std_core_types__list xs, kk_function_t action_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e maybe<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(action_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1385 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1385->head;
    kk_std_core_types__list xx_0 = _con_x1385->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__maybe x_0_10729;
    kk_function_t _x_x1386 = kk_function_dup(action_0, _ctx); /*(1453) -> 1455 maybe<1454>*/
    x_0_10729 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x1386, (_x_x1386, x, _ctx), _ctx); /*maybe<1454>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_10729, _ctx);
      kk_box_t _x_x1387 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_foreach_while_10009_fun1388(action_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__maybe_unbox(_x_x1387, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_0_10729, _ctx)) { // tailcall
                                                          xs = xx_0;
                                                          goto kk__tailcall;
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(action_0, _ctx);
      return x_0_10729;
    }
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_list__mlift_lift_find_10364_10688(kk_box_t _uniq_x_10297, kk_std_core_types__list _uniq_xx_10298, kk_function_t pred, bool _y_x10486, kk_context_t* _ctx) { /* forall<a,e> (a, list<a>, pred : (a) -> e bool, bool) -> e maybe<a> */ 
  if (_y_x10486) {
    kk_function_drop(pred, _ctx);
    kk_std_core_types__list_drop(_uniq_xx_10298, _ctx);
    return kk_std_core_types__new_Just(_uniq_x_10297, _ctx);
  }
  {
    kk_box_drop(_uniq_x_10297, _ctx);
    return kk_std_core_list__lift_find_10364(pred, _uniq_xx_10298, _ctx);
  }
}
 
// lifted local: find, @spec-x10301
// specialized: std/core/list/@unroll-foreach-while@10009, on parameters @uniq-action@10294, using:
// @uniq-action@10294 = fn<(e :: E)>(x: 1515){
//   match ((pred(x))) {
//     ((std/core/types/True() : bool ) as @pat@1: bool)
//        -> std/core/types/Just<a>(x);
//     ((@skip std/core/types/False() : bool ) as @pat@0@0: bool)
//        -> std/core/types/Nothing<a>;
//   };
// }


// lift anonymous function
struct kk_std_core_list__lift_find_10364_fun1394__t {
  struct kk_function_s _base;
  kk_box_t _uniq_x_10297_0;
  kk_std_core_types__list _uniq_xx_10298_0;
  kk_function_t pred_0;
};
static kk_box_t kk_std_core_list__lift_find_10364_fun1394(kk_function_t _fself, kk_box_t _b_x135, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_find_10364_fun1394(kk_box_t _uniq_x_10297_0, kk_std_core_types__list _uniq_xx_10298_0, kk_function_t pred_0, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_find_10364_fun1394__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_find_10364_fun1394__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_find_10364_fun1394, kk_context());
  _self->_uniq_x_10297_0 = _uniq_x_10297_0;
  _self->_uniq_xx_10298_0 = _uniq_xx_10298_0;
  _self->pred_0 = pred_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_find_10364_fun1394(kk_function_t _fself, kk_box_t _b_x135, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_find_10364_fun1394__t* _self = kk_function_as(struct kk_std_core_list__lift_find_10364_fun1394__t*, _fself, _ctx);
  kk_box_t _uniq_x_10297_0 = _self->_uniq_x_10297_0; /* 1515 */
  kk_std_core_types__list _uniq_xx_10298_0 = _self->_uniq_xx_10298_0; /* list<1515> */
  kk_function_t pred_0 = _self->pred_0; /* (1515) -> 1516 bool */
  kk_drop_match(_self, {kk_box_dup(_uniq_x_10297_0, _ctx);kk_std_core_types__list_dup(_uniq_xx_10298_0, _ctx);kk_function_dup(pred_0, _ctx);}, {}, _ctx)
  bool _y_x10486_0_137 = kk_bool_unbox(_b_x135); /*bool*/;
  kk_std_core_types__maybe _x_x1395 = kk_std_core_list__mlift_lift_find_10364_10688(_uniq_x_10297_0, _uniq_xx_10298_0, pred_0, _y_x10486_0_137, _ctx); /*maybe<1515>*/
  return kk_std_core_types__maybe_box(_x_x1395, _ctx);
}

kk_std_core_types__maybe kk_std_core_list__lift_find_10364(kk_function_t pred_0, kk_std_core_types__list _uniq_xs_10293, kk_context_t* _ctx) { /* forall<a,e> (pred : (a) -> e bool, list<a>) -> e maybe<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(_uniq_xs_10293, _ctx)) {
    kk_function_drop(pred_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1390 = kk_std_core_types__as_Cons(_uniq_xs_10293, _ctx);
    kk_box_t _uniq_x_10297_0 = _con_x1390->head;
    kk_std_core_types__list _uniq_xx_10298_0 = _con_x1390->tail;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10293, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10293, _ctx);
    }
    else {
      kk_box_dup(_uniq_x_10297_0, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10298_0, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10293, _ctx);
    }
    bool x_10732;
    kk_function_t _x_x1392 = kk_function_dup(pred_0, _ctx); /*(1515) -> 1516 bool*/
    kk_box_t _x_x1391 = kk_box_dup(_uniq_x_10297_0, _ctx); /*1515*/
    x_10732 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1392, (_x_x1392, _x_x1391, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1393 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_find_10364_fun1394(_uniq_x_10297_0, _uniq_xx_10298_0, pred_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__maybe_unbox(_x_x1393, KK_OWNED, _ctx);
    }
    if (x_10732) {
      kk_function_drop(pred_0, _ctx);
      kk_std_core_types__list_drop(_uniq_xx_10298_0, _ctx);
      return kk_std_core_types__new_Just(_uniq_x_10297_0, _ctx);
    }
    {
      kk_box_drop(_uniq_x_10297_0, _ctx);
      { // tailcall
        _uniq_xs_10293 = _uniq_xx_10298_0;
        goto kk__tailcall;
      }
    }
  }
}
 
// Returns an integer list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list__trmc_list(kk_integer_t lo, kk_integer_t hi, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (lo : int, hi : int, ctx<list<int>>) -> list<int> */ 
  kk__tailcall: ;
  bool _match_x1208 = kk_integer_lte_borrow(lo,hi,kk_context()); /*bool*/;
  if (_match_x1208) {
    kk_std_core_types__list _trmc_x10387 = kk_datatype_null(); /*list<int>*/;
    kk_std_core_types__list _trmc_x10388;
    kk_box_t _x_x1396;
    kk_integer_t _x_x1397 = kk_integer_dup(lo, _ctx); /*int*/
    _x_x1396 = kk_integer_box(_x_x1397, _ctx); /*82*/
    _trmc_x10388 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1396, _trmc_x10387, _ctx); /*list<int>*/
    kk_field_addr_t _b_x147_152 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10388, _ctx)->tail, _ctx); /*@field-addr<list<int>>*/;
    { // tailcall
      kk_integer_t _x_x1398 = kk_integer_add_small_const(lo, 1, _ctx); /*int*/
      kk_std_core_types__cctx _x_x1399 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10388, _ctx)),_b_x147_152,kk_context()); /*ctx<0>*/
      lo = _x_x1398;
      _acc = _x_x1399;
      goto kk__tailcall;
    }
  }
  {
    kk_integer_drop(lo, _ctx);
    kk_integer_drop(hi, _ctx);
    kk_box_t _x_x1400 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1400, KK_OWNED, _ctx);
  }
}
 
// Returns an integer list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_context_t* _ctx) { /* (lo : int, hi : int) -> list<int> */ 
  kk_std_core_types__cctx _x_x1401 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_list(lo_0, hi_0, _x_x1401, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_map_10010_10689(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list xx, kk_box_t _trmc_x10389, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e b, xx : list<a>, b) -> e list<b> */ 
  kk_std_core_types__list _trmc_x10390 = kk_datatype_null(); /*list<1969>*/;
  kk_std_core_types__list _trmc_x10391 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10389, _trmc_x10390, _ctx); /*list<1969>*/;
  kk_field_addr_t _b_x163_166 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10391, _ctx)->tail, _ctx); /*@field-addr<list<1969>>*/;
  kk_std_core_types__cctx _x_x1402 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10391, _ctx)),_b_x163_166,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_map_10010(xx, f, _x_x1402, _ctx);
}
 
// Apply a function `f` to each element of the input list in sequence.


// lift anonymous function
struct kk_std_core_list__trmc_unroll_map_10010_fun1406__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_map_10010_fun1406(kk_function_t _fself, kk_box_t _b_x171, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_map_10010_fun1406(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_map_10010_fun1406__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_map_10010_fun1406__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_map_10010_fun1406, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_map_10010_fun1406(kk_function_t _fself, kk_box_t _b_x171, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_map_10010_fun1406__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_map_10010_fun1406__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<1969>> */
  kk_function_t f_0 = _self->f_0; /* (1968) -> 1970 1969 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1968> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10389_0_189 = _b_x171; /*1969*/;
  kk_std_core_types__list _x_x1407 = kk_std_core_list__mlift_trmc_unroll_map_10010_10689(_acc_0, f_0, xx_0, _trmc_x10389_0_189, _ctx); /*list<1969>*/
  return kk_std_core_types__list_box(_x_x1407, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_map_10010(kk_std_core_types__list xs, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e b, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1403 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1403->head;
    kk_std_core_types__list xx_0 = _con_x1403->tail;
    kk_reuse_t _ru_x1244 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1244 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_box_t x_0_10735;
    kk_function_t _x_x1404 = kk_function_dup(f_0, _ctx); /*(1968) -> 1970 1969*/
    x_0_10735 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1404, (_x_x1404, x, _ctx), _ctx); /*1969*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1244,kk_context());
      kk_box_drop(x_0_10735, _ctx);
      kk_box_t _x_x1405 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_map_10010_fun1406(_acc_0, f_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1405, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10390_0 = kk_datatype_null(); /*list<1969>*/;
      kk_std_core_types__list _trmc_x10391_0 = kk_std_core_types__new_Cons(_ru_x1244, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0_10735, _trmc_x10390_0, _ctx); /*list<1969>*/;
      kk_field_addr_t _b_x177_183 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10391_0, _ctx)->tail, _ctx); /*@field-addr<list<1969>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1408 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10391_0, _ctx)),_b_x177_183,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1408;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1409 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1409, KK_OWNED, _ctx);
  }
}
 
// Apply a function `f` to each element of the input list in sequence.

kk_std_core_types__list kk_std_core_list__unroll_map_10010(kk_std_core_types__list xs_0, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e b) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1410 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_map_10010(xs_0, f_1, _x_x1410, _ctx);
}
 
// lifted local: char/list, @spec-x10309
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10304, using:
// @uniq-f@10304 = std/core/char/int/char

kk_std_core_types__list kk_std_core_list_char_fs__trmc_lift_list_10365(kk_std_core_types__list _uniq_xs_10303, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<int>, ctx<list<char>>) -> list<char> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10303, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1411 = kk_std_core_types__as_Cons(_uniq_xs_10303, _ctx);
    kk_box_t _box_x190 = _con_x1411->head;
    kk_std_core_types__list _uniq_xx_10307 = _con_x1411->tail;
    kk_integer_t _uniq_x_10306 = kk_integer_unbox(_box_x190, _ctx);
    kk_reuse_t _ru_x1245 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10303, _ctx)) {
      _ru_x1245 = (kk_datatype_ptr_reuse(_uniq_xs_10303, _ctx));
    }
    else {
      kk_integer_dup(_uniq_x_10306, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10307, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10303, _ctx);
    }
    kk_char_t _trmc_x10392 = kk_integer_clamp32(_uniq_x_10306,kk_context()); /*char*/;
    kk_std_core_types__list _trmc_x10393 = kk_datatype_null(); /*list<char>*/;
    kk_std_core_types__list _trmc_x10394 = kk_std_core_types__new_Cons(_ru_x1245, 0, kk_char_box(_trmc_x10392, _ctx), _trmc_x10393, _ctx); /*list<char>*/;
    kk_field_addr_t _b_x200_205 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10394, _ctx)->tail, _ctx); /*@field-addr<list<char>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1412 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10394, _ctx)),_b_x200_205,kk_context()); /*ctx<0>*/
      _uniq_xs_10303 = _uniq_xx_10307;
      _acc = _x_x1412;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1413 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1413, KK_OWNED, _ctx);
  }
}
 
// lifted local: char/list, @spec-x10309
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10304, using:
// @uniq-f@10304 = std/core/char/int/char

kk_std_core_types__list kk_std_core_list_char_fs__lift_list_10365(kk_std_core_types__list _uniq_xs_10303_0, kk_context_t* _ctx) { /* (list<int>) -> list<char> */ 
  kk_std_core_types__cctx _x_x1414 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list_char_fs__trmc_lift_list_10365(_uniq_xs_10303_0, _x_x1414, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list_function_fs__mlift_trmc_list_10690(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t hi, kk_integer_t lo, kk_box_t _trmc_x10395, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, f : (int) -> e a, hi : int, lo : int, a) -> e list<a> */ 
  kk_std_core_types__list _trmc_x10396 = kk_datatype_null(); /*list<1754>*/;
  kk_std_core_types__list _trmc_x10397 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10395, _trmc_x10396, _ctx); /*list<1754>*/;
  kk_field_addr_t _b_x216_219 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10397, _ctx)->tail, _ctx); /*@field-addr<list<1754>>*/;
  kk_integer_t _x_x1417 = kk_integer_add_small_const(lo, 1, _ctx); /*int*/
  kk_std_core_types__cctx _x_x1418 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10397, _ctx)),_b_x216_219,kk_context()); /*ctx<0>*/
  return kk_std_core_list_function_fs__trmc_list(_x_x1417, hi, f, _x_x1418, _ctx);
}
 
// Applies a function `f` to list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.


// lift anonymous function
struct kk_std_core_list_function_fs__trmc_list_fun1422__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t hi_0;
  kk_integer_t lo_0;
};
static kk_box_t kk_std_core_list_function_fs__trmc_list_fun1422(kk_function_t _fself, kk_box_t _b_x224, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_function_fs__new_trmc_list_fun1422(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t hi_0, kk_integer_t lo_0, kk_context_t* _ctx) {
  struct kk_std_core_list_function_fs__trmc_list_fun1422__t* _self = kk_function_alloc_as(struct kk_std_core_list_function_fs__trmc_list_fun1422__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_function_fs__trmc_list_fun1422, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->hi_0 = hi_0;
  _self->lo_0 = lo_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_function_fs__trmc_list_fun1422(kk_function_t _fself, kk_box_t _b_x224, kk_context_t* _ctx) {
  struct kk_std_core_list_function_fs__trmc_list_fun1422__t* _self = kk_function_as(struct kk_std_core_list_function_fs__trmc_list_fun1422__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<1754>> */
  kk_function_t f_0 = _self->f_0; /* (int) -> 1755 1754 */
  kk_integer_t hi_0 = _self->hi_0; /* int */
  kk_integer_t lo_0 = _self->lo_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(hi_0, _ctx);kk_integer_dup(lo_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10395_0_242 = _b_x224; /*1754*/;
  kk_std_core_types__list _x_x1423 = kk_std_core_list_function_fs__mlift_trmc_list_10690(_acc_0, f_0, hi_0, lo_0, _trmc_x10395_0_242, _ctx); /*list<1754>*/
  return kk_std_core_types__list_box(_x_x1423, _ctx);
}

kk_std_core_types__list kk_std_core_list_function_fs__trmc_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (lo : int, hi : int, f : (int) -> e a, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  bool _match_x1205 = kk_integer_lte_borrow(lo_0,hi_0,kk_context()); /*bool*/;
  if (_match_x1205) {
    kk_box_t x_10738;
    kk_function_t _x_x1420 = kk_function_dup(f_0, _ctx); /*(int) -> 1755 1754*/
    kk_integer_t _x_x1419 = kk_integer_dup(lo_0, _ctx); /*int*/
    x_10738 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x1420, (_x_x1420, _x_x1419, _ctx), _ctx); /*1754*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_10738, _ctx);
      kk_box_t _x_x1421 = kk_std_core_hnd_yield_extend(kk_std_core_list_function_fs__new_trmc_list_fun1422(_acc_0, f_0, hi_0, lo_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1421, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10396_0 = kk_datatype_null(); /*list<1754>*/;
      kk_std_core_types__list _trmc_x10397_0 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10738, _trmc_x10396_0, _ctx); /*list<1754>*/;
      kk_field_addr_t _b_x230_236 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10397_0, _ctx)->tail, _ctx); /*@field-addr<list<1754>>*/;
      { // tailcall
        kk_integer_t _x_x1424 = kk_integer_add_small_const(lo_0, 1, _ctx); /*int*/
        kk_std_core_types__cctx _x_x1425 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10397_0, _ctx)),_b_x230_236,kk_context()); /*ctx<0>*/
        lo_0 = _x_x1424;
        _acc_0 = _x_x1425;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(lo_0, _ctx);
    kk_integer_drop(hi_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1426 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1426, KK_OWNED, _ctx);
  }
}
 
// Applies a function `f` to list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_function_fs_list(kk_integer_t lo_1, kk_integer_t hi_1, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,e> (lo : int, hi : int, f : (int) -> e a) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1427 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list_function_fs__trmc_list(lo_1, hi_1, f_1, _x_x1427, _ctx);
}
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_stride_fs__trmc_list(kk_integer_t lo, kk_integer_t hi, kk_integer_t stride, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (lo : int, hi : int, stride : int, ctx<list<int>>) -> list<int> */ 
  kk__tailcall: ;
  bool _match_x1204 = kk_integer_lte_borrow(lo,hi,kk_context()); /*bool*/;
  if (_match_x1204) {
    kk_std_core_types__list _trmc_x10398 = kk_datatype_null(); /*list<int>*/;
    kk_std_core_types__list _trmc_x10399;
    kk_box_t _x_x1428;
    kk_integer_t _x_x1429 = kk_integer_dup(lo, _ctx); /*int*/
    _x_x1428 = kk_integer_box(_x_x1429, _ctx); /*82*/
    _trmc_x10399 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1428, _trmc_x10398, _ctx); /*list<int>*/
    kk_field_addr_t _b_x252_257 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10399, _ctx)->tail, _ctx); /*@field-addr<list<int>>*/;
    { // tailcall
      kk_integer_t _x_x1430;
      kk_integer_t _x_x1431 = kk_integer_dup(stride, _ctx); /*int*/
      _x_x1430 = kk_integer_add(lo,_x_x1431,kk_context()); /*int*/
      kk_std_core_types__cctx _x_x1432 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10399, _ctx)),_b_x252_257,kk_context()); /*ctx<0>*/
      lo = _x_x1430;
      _acc = _x_x1432;
      goto kk__tailcall;
    }
  }
  {
    kk_integer_drop(stride, _ctx);
    kk_integer_drop(lo, _ctx);
    kk_integer_drop(hi, _ctx);
    kk_box_t _x_x1433 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1433, KK_OWNED, _ctx);
  }
}
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_stride_fs_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_integer_t stride_0, kk_context_t* _ctx) { /* (lo : int, hi : int, stride : int) -> list<int> */ 
  kk_std_core_types__cctx _x_x1434 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list_stride_fs__trmc_list(lo_0, hi_0, stride_0, _x_x1434, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list_stridefunction_fs__mlift_trmc_list_10691(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t hi, kk_integer_t lo, kk_integer_t stride, kk_box_t _trmc_x10400, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, f : (int) -> e a, hi : int, lo : int, stride : int, a) -> e list<a> */ 
  kk_std_core_types__list _trmc_x10401 = kk_datatype_null(); /*list<1873>*/;
  kk_std_core_types__list _trmc_x10402 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10400, _trmc_x10401, _ctx); /*list<1873>*/;
  kk_field_addr_t _b_x268_271 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10402, _ctx)->tail, _ctx); /*@field-addr<list<1873>>*/;
  kk_integer_t _x_x1435;
  kk_integer_t _x_x1436 = kk_integer_dup(stride, _ctx); /*int*/
  _x_x1435 = kk_integer_add(lo,_x_x1436,kk_context()); /*int*/
  kk_std_core_types__cctx _x_x1437 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10402, _ctx)),_b_x268_271,kk_context()); /*ctx<0>*/
  return kk_std_core_list_stridefunction_fs__trmc_list(_x_x1435, hi, stride, f, _x_x1437, _ctx);
}
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.


// lift anonymous function
struct kk_std_core_list_stridefunction_fs__trmc_list_fun1441__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t hi_0;
  kk_integer_t lo_0;
  kk_integer_t stride_0;
};
static kk_box_t kk_std_core_list_stridefunction_fs__trmc_list_fun1441(kk_function_t _fself, kk_box_t _b_x276, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_stridefunction_fs__new_trmc_list_fun1441(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t hi_0, kk_integer_t lo_0, kk_integer_t stride_0, kk_context_t* _ctx) {
  struct kk_std_core_list_stridefunction_fs__trmc_list_fun1441__t* _self = kk_function_alloc_as(struct kk_std_core_list_stridefunction_fs__trmc_list_fun1441__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_stridefunction_fs__trmc_list_fun1441, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->hi_0 = hi_0;
  _self->lo_0 = lo_0;
  _self->stride_0 = stride_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_stridefunction_fs__trmc_list_fun1441(kk_function_t _fself, kk_box_t _b_x276, kk_context_t* _ctx) {
  struct kk_std_core_list_stridefunction_fs__trmc_list_fun1441__t* _self = kk_function_as(struct kk_std_core_list_stridefunction_fs__trmc_list_fun1441__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<1873>> */
  kk_function_t f_0 = _self->f_0; /* (int) -> 1874 1873 */
  kk_integer_t hi_0 = _self->hi_0; /* int */
  kk_integer_t lo_0 = _self->lo_0; /* int */
  kk_integer_t stride_0 = _self->stride_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(hi_0, _ctx);kk_integer_dup(lo_0, _ctx);kk_integer_dup(stride_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10400_0_294 = _b_x276; /*1873*/;
  kk_std_core_types__list _x_x1442 = kk_std_core_list_stridefunction_fs__mlift_trmc_list_10691(_acc_0, f_0, hi_0, lo_0, stride_0, _trmc_x10400_0_294, _ctx); /*list<1873>*/
  return kk_std_core_types__list_box(_x_x1442, _ctx);
}

kk_std_core_types__list kk_std_core_list_stridefunction_fs__trmc_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_integer_t stride_0, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (lo : int, hi : int, stride : int, f : (int) -> e a, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  bool _match_x1202 = kk_integer_lte_borrow(lo_0,hi_0,kk_context()); /*bool*/;
  if (_match_x1202) {
    kk_box_t x_10741;
    kk_function_t _x_x1439 = kk_function_dup(f_0, _ctx); /*(int) -> 1874 1873*/
    kk_integer_t _x_x1438 = kk_integer_dup(lo_0, _ctx); /*int*/
    x_10741 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x1439, (_x_x1439, _x_x1438, _ctx), _ctx); /*1873*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_10741, _ctx);
      kk_box_t _x_x1440 = kk_std_core_hnd_yield_extend(kk_std_core_list_stridefunction_fs__new_trmc_list_fun1441(_acc_0, f_0, hi_0, lo_0, stride_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1440, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10401_0 = kk_datatype_null(); /*list<1873>*/;
      kk_std_core_types__list _trmc_x10402_0 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10741, _trmc_x10401_0, _ctx); /*list<1873>*/;
      kk_field_addr_t _b_x282_288 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10402_0, _ctx)->tail, _ctx); /*@field-addr<list<1873>>*/;
      { // tailcall
        kk_integer_t _x_x1443;
        kk_integer_t _x_x1444 = kk_integer_dup(stride_0, _ctx); /*int*/
        _x_x1443 = kk_integer_add(lo_0,_x_x1444,kk_context()); /*int*/
        kk_std_core_types__cctx _x_x1445 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10402_0, _ctx)),_b_x282_288,kk_context()); /*ctx<0>*/
        lo_0 = _x_x1443;
        _acc_0 = _x_x1445;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(stride_0, _ctx);
    kk_integer_drop(lo_0, _ctx);
    kk_integer_drop(hi_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1446 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1446, KK_OWNED, _ctx);
  }
}
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_stridefunction_fs_list(kk_integer_t lo_1, kk_integer_t hi_1, kk_integer_t stride_1, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,e> (lo : int, hi : int, stride : int, f : (int) -> e a) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1447 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list_stridefunction_fs__trmc_list(lo_1, hi_1, stride_1, f_1, _x_x1447, _ctx);
}
 
// Apply a function `f` to each character in a string


// lift anonymous function
struct kk_std_core_list_string_fs_map_fun1448__t {
  struct kk_function_s _base;
  kk_function_t f;
};
static kk_box_t kk_std_core_list_string_fs_map_fun1448(kk_function_t _fself, kk_box_t _b_x297, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_string_fs_new_map_fun1448(kk_function_t f, kk_context_t* _ctx) {
  struct kk_std_core_list_string_fs_map_fun1448__t* _self = kk_function_alloc_as(struct kk_std_core_list_string_fs_map_fun1448__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_string_fs_map_fun1448, kk_context());
  _self->f = f;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_string_fs_map_fun1448(kk_function_t _fself, kk_box_t _b_x297, kk_context_t* _ctx) {
  struct kk_std_core_list_string_fs_map_fun1448__t* _self = kk_function_as(struct kk_std_core_list_string_fs_map_fun1448__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (char) -> 1922 char */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);}, {}, _ctx)
  kk_char_t _x_x1449;
  kk_char_t _x_x1450 = kk_char_unbox(_b_x297, KK_OWNED, _ctx); /*char*/
  _x_x1449 = kk_function_call(kk_char_t, (kk_function_t, kk_char_t, kk_context_t*), f, (f, _x_x1450, _ctx), _ctx); /*char*/
  return kk_char_box(_x_x1449, _ctx);
}


// lift anonymous function
struct kk_std_core_list_string_fs_map_fun1452__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_string_fs_map_fun1452(kk_function_t _fself, kk_box_t _b_x301, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_string_fs_new_map_fun1452(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_string_fs_map_fun1452, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_string_fs_map_fun1452(kk_function_t _fself, kk_box_t _b_x301, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t _x_x1453;
  kk_std_core_types__list _x_x1454 = kk_std_core_types__list_unbox(_b_x301, KK_OWNED, _ctx); /*list<char>*/
  _x_x1453 = kk_std_core_string_listchar_fs_string(_x_x1454, _ctx); /*string*/
  return kk_string_box(_x_x1453);
}

kk_string_t kk_std_core_list_string_fs_map(kk_string_t s, kk_function_t f, kk_context_t* _ctx) { /* forall<e> (s : string, f : (char) -> e char) -> e string */ 
  kk_std_core_types__list xs_10066 = kk_std_core_string_list(s, _ctx); /*list<char>*/;
  kk_std_core_types__list x_10744;
  if (kk_std_core_types__is_Nil(xs_10066, _ctx)) {
    kk_function_drop(f, _ctx);
    x_10744 = kk_std_core_types__new_Nil(_ctx); /*list<char>*/
  }
  else {
    x_10744 = kk_std_core_list__unroll_map_10010(xs_10066, kk_std_core_list_string_fs_new_map_fun1448(f, _ctx), _ctx); /*list<char>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10744, _ctx);
    kk_box_t _x_x1451 = kk_std_core_hnd_yield_extend(kk_std_core_list_string_fs_new_map_fun1452(_ctx), _ctx); /*2978*/
    return kk_string_unbox(_x_x1451);
  }
  {
    return kk_std_core_string_listchar_fs_string(x_10744, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_lift_map_indexed_4949_10011_10692(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t i_0_10069, kk_std_core_types__list yy, kk_box_t _trmc_x10403, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (idx : int, value : a) -> e b, i@0@10069 : int, yy : list<a>, b) -> e list<b> */ 
  kk_std_core_types__list _trmc_x10404 = kk_datatype_null(); /*list<2069>*/;
  kk_std_core_types__list _trmc_x10405 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10403, _trmc_x10404, _ctx); /*list<2069>*/;
  kk_field_addr_t _b_x308_311 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10405, _ctx)->tail, _ctx); /*@field-addr<list<2069>>*/;
  kk_std_core_types__cctx _x_x1455 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10405, _ctx)),_b_x308_311,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_indexed_4949_10011(f, yy, i_0_10069, _x_x1455, _ctx);
}
 
// lifted local: map-indexed, map-idx


// lift anonymous function
struct kk_std_core_list__trmc_unroll_lift_map_indexed_4949_10011_fun1460__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t i_0_10069_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_lift_map_indexed_4949_10011_fun1460(kk_function_t _fself, kk_box_t _b_x316, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_lift_map_indexed_4949_10011_fun1460(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t i_0_10069_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_indexed_4949_10011_fun1460__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_lift_map_indexed_4949_10011_fun1460__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_lift_map_indexed_4949_10011_fun1460, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->i_0_10069_0 = i_0_10069_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_lift_map_indexed_4949_10011_fun1460(kk_function_t _fself, kk_box_t _b_x316, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_indexed_4949_10011_fun1460__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_lift_map_indexed_4949_10011_fun1460__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2069>> */
  kk_function_t f_0 = _self->f_0; /* (idx : int, value : 2068) -> 2070 2069 */
  kk_integer_t i_0_10069_0 = _self->i_0_10069_0; /* int */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<2068> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(i_0_10069_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10403_0_334 = _b_x316; /*2069*/;
  kk_std_core_types__list _x_x1461 = kk_std_core_list__mlift_trmc_unroll_lift_map_indexed_4949_10011_10692(_acc_0, f_0, i_0_10069_0, yy_0, _trmc_x10403_0_334, _ctx); /*list<2069>*/
  return kk_std_core_types__list_box(_x_x1461, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_map_indexed_4949_10011(kk_function_t f_0, kk_std_core_types__list ys, kk_integer_t i, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1456 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1456->head;
    kk_std_core_types__list yy_0 = _con_x1456->tail;
    kk_reuse_t _ru_x1246 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1246 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy_0, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_integer_t i_0_10069_0;
    kk_integer_t _x_x1457 = kk_integer_dup(i, _ctx); /*int*/
    i_0_10069_0 = kk_integer_add_small_const(_x_x1457, 1, _ctx); /*int*/
    kk_box_t x_10746;
    kk_function_t _x_x1458 = kk_function_dup(f_0, _ctx); /*(idx : int, value : 2068) -> 2070 2069*/
    x_10746 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x_x1458, (_x_x1458, i, y, _ctx), _ctx); /*2069*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1246,kk_context());
      kk_box_drop(x_10746, _ctx);
      kk_box_t _x_x1459 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_lift_map_indexed_4949_10011_fun1460(_acc_0, f_0, i_0_10069_0, yy_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1459, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10404_0 = kk_datatype_null(); /*list<2069>*/;
      kk_std_core_types__list _trmc_x10405_0 = kk_std_core_types__new_Cons(_ru_x1246, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10746, _trmc_x10404_0, _ctx); /*list<2069>*/;
      kk_field_addr_t _b_x322_328 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10405_0, _ctx)->tail, _ctx); /*@field-addr<list<2069>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1462 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10405_0, _ctx)),_b_x322_328,kk_context()); /*ctx<0>*/
        ys = yy_0;
        i = i_0_10069_0;
        _acc_0 = _x_x1462;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(i, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1463 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1463, KK_OWNED, _ctx);
  }
}
 
// lifted local: map-indexed, map-idx

kk_std_core_types__list kk_std_core_list__unroll_lift_map_indexed_4949_10011(kk_function_t f_1, kk_std_core_types__list ys_0, kk_integer_t i_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1464 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_indexed_4949_10011(f_1, ys_0, i_0, _x_x1464, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_lift_map_peek_4950_10012_10693(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list yy, kk_box_t _trmc_x10406, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (value : a, rest : list<a>) -> e b, yy : list<a>, b) -> e list<b> */ 
  kk_std_core_types__list _trmc_x10407 = kk_datatype_null(); /*list<2121>*/;
  kk_std_core_types__list _trmc_x10408 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10406, _trmc_x10407, _ctx); /*list<2121>*/;
  kk_field_addr_t _b_x340_343 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10408, _ctx)->tail, _ctx); /*@field-addr<list<2121>>*/;
  kk_std_core_types__cctx _x_x1465 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10408, _ctx)),_b_x340_343,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_peek_4950_10012(f, yy, _x_x1465, _ctx);
}
 
// lifted local: map-peek, mappeek


// lift anonymous function
struct kk_std_core_list__trmc_unroll_lift_map_peek_4950_10012_fun1470__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_lift_map_peek_4950_10012_fun1470(kk_function_t _fself, kk_box_t _b_x348, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_lift_map_peek_4950_10012_fun1470(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_peek_4950_10012_fun1470__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_lift_map_peek_4950_10012_fun1470__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_lift_map_peek_4950_10012_fun1470, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_lift_map_peek_4950_10012_fun1470(kk_function_t _fself, kk_box_t _b_x348, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_peek_4950_10012_fun1470__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_lift_map_peek_4950_10012_fun1470__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2121>> */
  kk_function_t f_0 = _self->f_0; /* (value : 2120, rest : list<2120>) -> 2122 2121 */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<2120> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10406_0_366 = _b_x348; /*2121*/;
  kk_std_core_types__list _x_x1471 = kk_std_core_list__mlift_trmc_unroll_lift_map_peek_4950_10012_10693(_acc_0, f_0, yy_0, _trmc_x10406_0_366, _ctx); /*list<2121>*/
  return kk_std_core_types__list_box(_x_x1471, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_map_peek_4950_10012(kk_function_t f_0, kk_std_core_types__list ys, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1466 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1466->head;
    kk_std_core_types__list yy_0 = _con_x1466->tail;
    kk_reuse_t _ru_x1247 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1247 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy_0, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_box_t x_10749;
    kk_function_t _x_x1468 = kk_function_dup(f_0, _ctx); /*(value : 2120, rest : list<2120>) -> 2122 2121*/
    kk_std_core_types__list _x_x1467 = kk_std_core_types__list_dup(yy_0, _ctx); /*list<2120>*/
    x_10749 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_std_core_types__list, kk_context_t*), _x_x1468, (_x_x1468, y, _x_x1467, _ctx), _ctx); /*2121*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1247,kk_context());
      kk_box_drop(x_10749, _ctx);
      kk_box_t _x_x1469 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_lift_map_peek_4950_10012_fun1470(_acc_0, f_0, yy_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1469, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10407_0 = kk_datatype_null(); /*list<2121>*/;
      kk_std_core_types__list _trmc_x10408_0 = kk_std_core_types__new_Cons(_ru_x1247, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10749, _trmc_x10407_0, _ctx); /*list<2121>*/;
      kk_field_addr_t _b_x354_360 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10408_0, _ctx)->tail, _ctx); /*@field-addr<list<2121>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1472 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10408_0, _ctx)),_b_x354_360,kk_context()); /*ctx<0>*/
        ys = yy_0;
        _acc_0 = _x_x1472;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1473 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1473, KK_OWNED, _ctx);
  }
}
 
// lifted local: map-peek, mappeek

kk_std_core_types__list kk_std_core_list__unroll_lift_map_peek_4950_10012(kk_function_t f_1, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1474 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_peek_4950_10012(f_1, ys_0, _x_x1474, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_lift_map_indexed_peek_4951_10013_10694(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t i_0_10077, kk_std_core_types__list yy, kk_box_t _trmc_x10409, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (idx : int, value : a, rest : list<a>) -> e b, i@0@10077 : int, yy : list<a>, b) -> e list<b> */ 
  kk_std_core_types__list _trmc_x10410 = kk_datatype_null(); /*list<2183>*/;
  kk_std_core_types__list _trmc_x10411 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10409, _trmc_x10410, _ctx); /*list<2183>*/;
  kk_field_addr_t _b_x372_375 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10411, _ctx)->tail, _ctx); /*@field-addr<list<2183>>*/;
  kk_std_core_types__cctx _x_x1475 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10411, _ctx)),_b_x372_375,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_indexed_peek_4951_10013(f, yy, i_0_10077, _x_x1475, _ctx);
}
 
// lifted local: map-indexed-peek, mapidx


// lift anonymous function
struct kk_std_core_list__trmc_unroll_lift_map_indexed_peek_4951_10013_fun1481__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t i_0_10077_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_lift_map_indexed_peek_4951_10013_fun1481(kk_function_t _fself, kk_box_t _b_x380, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_lift_map_indexed_peek_4951_10013_fun1481(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t i_0_10077_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_indexed_peek_4951_10013_fun1481__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_lift_map_indexed_peek_4951_10013_fun1481__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_lift_map_indexed_peek_4951_10013_fun1481, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->i_0_10077_0 = i_0_10077_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_lift_map_indexed_peek_4951_10013_fun1481(kk_function_t _fself, kk_box_t _b_x380, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_indexed_peek_4951_10013_fun1481__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_lift_map_indexed_peek_4951_10013_fun1481__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2183>> */
  kk_function_t f_0 = _self->f_0; /* (idx : int, value : 2182, rest : list<2182>) -> 2184 2183 */
  kk_integer_t i_0_10077_0 = _self->i_0_10077_0; /* int */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<2182> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(i_0_10077_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10409_0_398 = _b_x380; /*2183*/;
  kk_std_core_types__list _x_x1482 = kk_std_core_list__mlift_trmc_unroll_lift_map_indexed_peek_4951_10013_10694(_acc_0, f_0, i_0_10077_0, yy_0, _trmc_x10409_0_398, _ctx); /*list<2183>*/
  return kk_std_core_types__list_box(_x_x1482, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_map_indexed_peek_4951_10013(kk_function_t f_0, kk_std_core_types__list ys, kk_integer_t i, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1476 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1476->head;
    kk_std_core_types__list yy_0 = _con_x1476->tail;
    kk_reuse_t _ru_x1248 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1248 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy_0, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_integer_t i_0_10077_0;
    kk_integer_t _x_x1477 = kk_integer_dup(i, _ctx); /*int*/
    i_0_10077_0 = kk_integer_add_small_const(_x_x1477, 1, _ctx); /*int*/
    kk_box_t x_10752;
    kk_function_t _x_x1479 = kk_function_dup(f_0, _ctx); /*(idx : int, value : 2182, rest : list<2182>) -> 2184 2183*/
    kk_std_core_types__list _x_x1478 = kk_std_core_types__list_dup(yy_0, _ctx); /*list<2182>*/
    x_10752 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_std_core_types__list, kk_context_t*), _x_x1479, (_x_x1479, i, y, _x_x1478, _ctx), _ctx); /*2183*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1248,kk_context());
      kk_box_drop(x_10752, _ctx);
      kk_box_t _x_x1480 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_lift_map_indexed_peek_4951_10013_fun1481(_acc_0, f_0, i_0_10077_0, yy_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1480, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10410_0 = kk_datatype_null(); /*list<2183>*/;
      kk_std_core_types__list _trmc_x10411_0 = kk_std_core_types__new_Cons(_ru_x1248, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10752, _trmc_x10410_0, _ctx); /*list<2183>*/;
      kk_field_addr_t _b_x386_392 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10411_0, _ctx)->tail, _ctx); /*@field-addr<list<2183>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1483 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10411_0, _ctx)),_b_x386_392,kk_context()); /*ctx<0>*/
        ys = yy_0;
        i = i_0_10077_0;
        _acc_0 = _x_x1483;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(i, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1484 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1484, KK_OWNED, _ctx);
  }
}
 
// lifted local: map-indexed-peek, mapidx

kk_std_core_types__list kk_std_core_list__unroll_lift_map_indexed_peek_4951_10013(kk_function_t f_1, kk_std_core_types__list ys_0, kk_integer_t i_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1485 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_indexed_peek_4951_10013(f_1, ys_0, i_0, _x_x1485, _ctx);
}
 
// Create a list of `n` repeated elements `x`

kk_std_core_types__list kk_std_core_list__trmc_replicate(kk_box_t x, kk_integer_t n, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (x : a, n : int, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  bool _match_x1197 = kk_integer_gt_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1197) {
    kk_std_core_types__list _trmc_x10412 = kk_datatype_null(); /*list<2235>*/;
    kk_std_core_types__list _trmc_x10413;
    kk_box_t _x_x1486 = kk_box_dup(x, _ctx); /*2235*/
    _trmc_x10413 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1486, _trmc_x10412, _ctx); /*list<2235>*/
    kk_field_addr_t _b_x404_409 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10413, _ctx)->tail, _ctx); /*@field-addr<list<2235>>*/;
    { // tailcall
      kk_integer_t _x_x1487 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
      kk_std_core_types__cctx _x_x1488 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10413, _ctx)),_b_x404_409,kk_context()); /*ctx<0>*/
      n = _x_x1487;
      _acc = _x_x1488;
      goto kk__tailcall;
    }
  }
  {
    kk_box_drop(x, _ctx);
    kk_integer_drop(n, _ctx);
    kk_box_t _x_x1489 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1489, KK_OWNED, _ctx);
  }
}
 
// Create a list of `n` repeated elements `x`

kk_std_core_types__list kk_std_core_list_replicate(kk_box_t x_0, kk_integer_t n_0, kk_context_t* _ctx) { /* forall<a> (x : a, n : int) -> list<a> */ 
  kk_std_core_types__cctx _x_x1490 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_replicate(x_0, n_0, _x_x1490, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_lift_remove_10366_10695(kk_std_core_types__cctx _acc, kk_box_t _uniq_x_10313, kk_std_core_types__list _uniq_xx_10314, kk_function_t pred, bool _y_x10535, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, a, list<a>, pred : (a) -> e bool, bool) -> e list<a> */ 
  if (_y_x10535) {
    kk_box_drop(_uniq_x_10313, _ctx);
    return kk_std_core_list__trmc_lift_remove_10366(pred, _uniq_xx_10314, _acc, _ctx);
  }
  {
    kk_std_core_types__list _trmc_x10414 = kk_datatype_null(); /*list<2269>*/;
    kk_std_core_types__list _trmc_x10415 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _uniq_x_10313, _trmc_x10414, _ctx); /*list<2269>*/;
    kk_field_addr_t _b_x420_423 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10415, _ctx)->tail, _ctx); /*@field-addr<list<2269>>*/;
    kk_std_core_types__cctx _x_x1491 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10415, _ctx)),_b_x420_423,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_lift_remove_10366(pred, _uniq_xx_10314, _x_x1491, _ctx);
  }
}
 
// lifted local: remove, @spec-x10318
// specialized: std/core/list/@unroll-filter@10007, on parameters @uniq-pred@10311, using:
// @uniq-pred@10311 = fn<(e :: E)>(x: 2269){
//   std/core/types/@open<(total :: E),(e :: E),(b : bool) -> bool,(b : bool) -> (e :: E) bool>((fn(b: bool){
//     (match (b) {
//       ((std/core/types/True() : bool ) as @pat@0: bool)
//          -> std/core/types/False;
//       ((@skip std/core/types/False() : bool ) as @pat@0@0: bool)
//          -> std/core/types/True;
//     });
//   }))((pred(x)));
// }


// lift anonymous function
struct kk_std_core_list__trmc_lift_remove_10366_fun1496__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_box_t _uniq_x_10313_0;
  kk_std_core_types__list _uniq_xx_10314_0;
  kk_function_t pred_0;
};
static kk_box_t kk_std_core_list__trmc_lift_remove_10366_fun1496(kk_function_t _fself, kk_box_t _b_x428, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_lift_remove_10366_fun1496(kk_std_core_types__cctx _acc_0, kk_box_t _uniq_x_10313_0, kk_std_core_types__list _uniq_xx_10314_0, kk_function_t pred_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_remove_10366_fun1496__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_lift_remove_10366_fun1496__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_lift_remove_10366_fun1496, kk_context());
  _self->_acc_0 = _acc_0;
  _self->_uniq_x_10313_0 = _uniq_x_10313_0;
  _self->_uniq_xx_10314_0 = _uniq_xx_10314_0;
  _self->pred_0 = pred_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_lift_remove_10366_fun1496(kk_function_t _fself, kk_box_t _b_x428, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_remove_10366_fun1496__t* _self = kk_function_as(struct kk_std_core_list__trmc_lift_remove_10366_fun1496__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2269>> */
  kk_box_t _uniq_x_10313_0 = _self->_uniq_x_10313_0; /* 2269 */
  kk_std_core_types__list _uniq_xx_10314_0 = _self->_uniq_xx_10314_0; /* list<2269> */
  kk_function_t pred_0 = _self->pred_0; /* (2269) -> 2270 bool */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_box_dup(_uniq_x_10313_0, _ctx);kk_std_core_types__list_dup(_uniq_xx_10314_0, _ctx);kk_function_dup(pred_0, _ctx);}, {}, _ctx)
  bool _y_x10535_0_446 = kk_bool_unbox(_b_x428); /*bool*/;
  kk_std_core_types__list _x_x1497 = kk_std_core_list__mlift_trmc_lift_remove_10366_10695(_acc_0, _uniq_x_10313_0, _uniq_xx_10314_0, pred_0, _y_x10535_0_446, _ctx); /*list<2269>*/
  return kk_std_core_types__list_box(_x_x1497, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_lift_remove_10366(kk_function_t pred_0, kk_std_core_types__list _uniq_xs_10310, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (pred : (a) -> e bool, list<a>, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10310, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1492 = kk_std_core_types__as_Cons(_uniq_xs_10310, _ctx);
    kk_box_t _uniq_x_10313_0 = _con_x1492->head;
    kk_std_core_types__list _uniq_xx_10314_0 = _con_x1492->tail;
    kk_reuse_t _ru_x1249 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10310, _ctx)) {
      _ru_x1249 = (kk_datatype_ptr_reuse(_uniq_xs_10310, _ctx));
    }
    else {
      kk_box_dup(_uniq_x_10313_0, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10314_0, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10310, _ctx);
    }
    bool x_10755;
    kk_function_t _x_x1494 = kk_function_dup(pred_0, _ctx); /*(2269) -> 2270 bool*/
    kk_box_t _x_x1493 = kk_box_dup(_uniq_x_10313_0, _ctx); /*2269*/
    x_10755 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1494, (_x_x1494, _x_x1493, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1249,kk_context());
      kk_box_t _x_x1495 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_lift_remove_10366_fun1496(_acc_0, _uniq_x_10313_0, _uniq_xx_10314_0, pred_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1495, KK_OWNED, _ctx);
    }
    if (x_10755) {
      kk_reuse_drop(_ru_x1249,kk_context());
      kk_box_drop(_uniq_x_10313_0, _ctx);
      { // tailcall
        _uniq_xs_10310 = _uniq_xx_10314_0;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list _trmc_x10414_0 = kk_datatype_null(); /*list<2269>*/;
      kk_std_core_types__list _trmc_x10415_0 = kk_std_core_types__new_Cons(_ru_x1249, kk_field_index_of(struct kk_std_core_types_Cons, tail), _uniq_x_10313_0, _trmc_x10414_0, _ctx); /*list<2269>*/;
      kk_field_addr_t _b_x434_440 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10415_0, _ctx)->tail, _ctx); /*@field-addr<list<2269>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1498 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10415_0, _ctx)),_b_x434_440,kk_context()); /*ctx<0>*/
        _uniq_xs_10310 = _uniq_xx_10314_0;
        _acc_0 = _x_x1498;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(pred_0, _ctx);
    kk_box_t _x_x1499 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1499, KK_OWNED, _ctx);
  }
}
 
// lifted local: remove, @spec-x10318
// specialized: std/core/list/@unroll-filter@10007, on parameters @uniq-pred@10311, using:
// @uniq-pred@10311 = fn<(e :: E)>(x: 2269){
//   std/core/types/@open<(total :: E),(e :: E),(b : bool) -> bool,(b : bool) -> (e :: E) bool>((fn(b: bool){
//     (match (b) {
//       ((std/core/types/True() : bool ) as @pat@0: bool)
//          -> std/core/types/False;
//       ((@skip std/core/types/False() : bool ) as @pat@0@0: bool)
//          -> std/core/types/True;
//     });
//   }))((pred(x)));
// }

kk_std_core_types__list kk_std_core_list__lift_remove_10366(kk_function_t pred_1, kk_std_core_types__list _uniq_xs_10310_0, kk_context_t* _ctx) { /* forall<a,e> (pred : (a) -> e bool, list<a>) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1500 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_remove_10366(pred_1, _uniq_xs_10310_0, _x_x1500, _ctx);
}
 
// monadic lift

kk_std_core_types__tuple2 kk_std_core_list__mlift_unroll_partition_acc_10014_10696(kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_function_t pred, kk_box_t x, kk_std_core_types__list xx, bool _y_x10543, kk_context_t* _ctx) { /* forall<a,e> (acc1 : ctx<list<a>>, acc2 : ctx<list<a>>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e (list<a>, list<a>) */ 
  if (_y_x10543) {
    kk_std_core_types__list _cctx_x2361;
    kk_std_core_types__list _x_x1501 = kk_datatype_null(); /*list<2413>*/
    _cctx_x2361 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1501, _ctx); /*list<2413>*/
    kk_field_addr_t _cctx_x2362 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x2361, _ctx)->tail, _ctx); /*@field-addr<list<2413>>*/;
    kk_std_core_types__list _b_x453_463 = _cctx_x2361; /*list<2413>*/;
    kk_field_addr_t _b_x454_464 = _cctx_x2362; /*@field-addr<list<2413>>*/;
    kk_std_core_types__cctx _own_x1194;
    kk_std_core_types__cctx _x_x1502 = kk_cctx_create((kk_std_core_types__list_box(_b_x453_463, _ctx)),_b_x454_464,kk_context()); /*cctx<0,1>*/
    _own_x1194 = kk_cctx_compose(acc1,_x_x1502,kk_context()); /*cctx<371,373>*/
    kk_std_core_types__tuple2 _brw_x1195 = kk_std_core_list__unroll_partition_acc_10014(xx, pred, _own_x1194, acc2, _ctx); /*(list<2413>, list<2413>)*/;
    kk_function_drop(pred, _ctx);
    return _brw_x1195;
  }
  {
    kk_std_core_types__list _cctx_x2404;
    kk_std_core_types__list _x_x1503 = kk_datatype_null(); /*list<2413>*/
    _cctx_x2404 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1503, _ctx); /*list<2413>*/
    kk_field_addr_t _cctx_x2405 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x2404, _ctx)->tail, _ctx); /*@field-addr<list<2413>>*/;
    kk_std_core_types__list _b_x461_465 = _cctx_x2404; /*list<2413>*/;
    kk_field_addr_t _b_x462_466 = _cctx_x2405; /*@field-addr<list<2413>>*/;
    kk_std_core_types__cctx _own_x1192;
    kk_std_core_types__cctx _x_x1504 = kk_cctx_create((kk_std_core_types__list_box(_b_x461_465, _ctx)),_b_x462_466,kk_context()); /*cctx<0,1>*/
    _own_x1192 = kk_cctx_compose(acc2,_x_x1504,kk_context()); /*cctx<371,373>*/
    kk_std_core_types__tuple2 _brw_x1193 = kk_std_core_list__unroll_partition_acc_10014(xx, pred, acc1, _own_x1192, _ctx); /*(list<2413>, list<2413>)*/;
    kk_function_drop(pred, _ctx);
    return _brw_x1193;
  }
}


// lift anonymous function
struct kk_std_core_list__unroll_partition_acc_10014_fun1512__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx acc1_0;
  kk_std_core_types__cctx acc2_0;
  kk_function_t pred_0;
  kk_box_t x_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_partition_acc_10014_fun1512(kk_function_t _fself, kk_box_t _b_x474, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_partition_acc_10014_fun1512(kk_std_core_types__cctx acc1_0, kk_std_core_types__cctx acc2_0, kk_function_t pred_0, kk_box_t x_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_partition_acc_10014_fun1512__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_partition_acc_10014_fun1512__t, 8, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_partition_acc_10014_fun1512, kk_context());
  _self->acc1_0 = acc1_0;
  _self->acc2_0 = acc2_0;
  _self->pred_0 = pred_0;
  _self->x_0 = x_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_partition_acc_10014_fun1512(kk_function_t _fself, kk_box_t _b_x474, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_partition_acc_10014_fun1512__t* _self = kk_function_as(struct kk_std_core_list__unroll_partition_acc_10014_fun1512__t*, _fself, _ctx);
  kk_std_core_types__cctx acc1_0 = _self->acc1_0; /* ctx<list<2413>> */
  kk_std_core_types__cctx acc2_0 = _self->acc2_0; /* ctx<list<2413>> */
  kk_function_t pred_0 = _self->pred_0; /* (2413) -> 2414 bool */
  kk_box_t x_0 = _self->x_0; /* 2413 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<2413> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(acc1_0, _ctx);kk_std_core_types__cctx_dup(acc2_0, _ctx);kk_function_dup(pred_0, _ctx);kk_box_dup(x_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10543_0_502 = kk_bool_unbox(_b_x474); /*bool*/;
  kk_std_core_types__tuple2 _x_x1513 = kk_std_core_list__mlift_unroll_partition_acc_10014_10696(acc1_0, acc2_0, pred_0, x_0, xx_0, _y_x10543_0_502, _ctx); /*(list<2413>, list<2413>)*/
  return kk_std_core_types__tuple2_box(_x_x1513, _ctx);
}

kk_std_core_types__tuple2 kk_std_core_list__unroll_partition_acc_10014(kk_std_core_types__list xs, kk_function_t pred_0, kk_std_core_types__cctx acc1_0, kk_std_core_types__cctx acc2_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, acc1 : ctx<list<a>>, acc2 : ctx<list<a>>) -> e (list<a>, list<a>) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list _b_x471_491;
    kk_box_t _x_x1505 = kk_cctx_apply(acc1_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    _b_x471_491 = kk_std_core_types__list_unbox(_x_x1505, KK_OWNED, _ctx); /*list<2413>*/
    kk_std_core_types__list _b_x472_492;
    kk_box_t _x_x1506 = kk_cctx_apply(acc2_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    _b_x472_492 = kk_std_core_types__list_unbox(_x_x1506, KK_OWNED, _ctx); /*list<2413>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x471_491, _ctx), kk_std_core_types__list_box(_b_x472_492, _ctx), _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1507 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x_0 = _con_x1507->head;
    kk_std_core_types__list xx_0 = _con_x1507->tail;
    kk_reuse_t _ru_x1250 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1250 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x_0, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_1_10758;
    kk_function_t _x_x1509 = kk_function_dup(pred_0, _ctx); /*(2413) -> 2414 bool*/
    kk_box_t _x_x1508 = kk_box_dup(x_0, _ctx); /*2413*/
    x_1_10758 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1509, (_x_x1509, _x_x1508, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1250,kk_context());
      kk_box_t _x_x1510;
      kk_function_t _x_x1511;
      kk_function_dup(pred_0, _ctx);
      _x_x1511 = kk_std_core_list__new_unroll_partition_acc_10014_fun1512(acc1_0, acc2_0, pred_0, x_0, xx_0, _ctx); /*(2977) -> 2979 2978*/
      _x_x1510 = kk_std_core_hnd_yield_extend(_x_x1511, _ctx); /*2978*/
      return kk_std_core_types__tuple2_unbox(_x_x1510, KK_OWNED, _ctx);
    }
    if (x_1_10758) {
      kk_std_core_types__list _cctx_x2361_0;
      kk_std_core_types__list _x_x1514 = kk_datatype_null(); /*list<2413>*/
      _cctx_x2361_0 = kk_std_core_types__new_Cons(_ru_x1250, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0, _x_x1514, _ctx); /*list<2413>*/
      kk_field_addr_t _cctx_x2362_0 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x2361_0, _ctx)->tail, _ctx); /*@field-addr<list<2413>>*/;
      kk_std_core_types__list _b_x481_498 = _cctx_x2361_0; /*list<2413>*/;
      kk_field_addr_t _b_x482_499 = _cctx_x2362_0; /*@field-addr<list<2413>>*/;
      kk_std_core_types__cctx _own_x1191;
      kk_std_core_types__cctx _x_x1515 = kk_cctx_create((kk_std_core_types__list_box(_b_x481_498, _ctx)),_b_x482_499,kk_context()); /*cctx<0,1>*/
      _own_x1191 = kk_cctx_compose(acc1_0,_x_x1515,kk_context()); /*cctx<371,373>*/
      { // tailcall
        xs = xx_0;
        acc1_0 = _own_x1191;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list _cctx_x2404_0;
      kk_std_core_types__list _x_x1516 = kk_datatype_null(); /*list<2413>*/
      _cctx_x2404_0 = kk_std_core_types__new_Cons(_ru_x1250, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0, _x_x1516, _ctx); /*list<2413>*/
      kk_field_addr_t _cctx_x2405_0 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x2404_0, _ctx)->tail, _ctx); /*@field-addr<list<2413>>*/;
      kk_std_core_types__list _b_x489_500 = _cctx_x2404_0; /*list<2413>*/;
      kk_field_addr_t _b_x490_501 = _cctx_x2405_0; /*@field-addr<list<2413>>*/;
      kk_std_core_types__cctx _own_x1190;
      kk_std_core_types__cctx _x_x1517 = kk_cctx_create((kk_std_core_types__list_box(_b_x489_500, _ctx)),_b_x490_501,kk_context()); /*cctx<0,1>*/
      _own_x1190 = kk_cctx_compose(acc2_0,_x_x1517,kk_context()); /*cctx<371,373>*/
      { // tailcall
        xs = xx_0;
        acc2_0 = _own_x1190;
        goto kk__tailcall;
      }
    }
  }
}
 
// Partition a list in two lists where the first list contains
// those elements that satisfy the given predicate `pred`.
// For example: `partition([1,2,3],odd?) == ([1,3],[2])`

kk_std_core_types__tuple2 kk_std_core_list_partition(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e (list<a>, list<a>) */ 
  kk_std_core_types__cctx acc1_10086 = kk_cctx_empty(kk_context()); /*ctx<list<2453>>*/;
  kk_std_core_types__cctx acc2_10087 = kk_cctx_empty(kk_context()); /*ctx<list<2453>>*/;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list _b_x519_521;
    kk_box_t _x_x1520 = kk_cctx_apply(acc1_10086,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    _b_x519_521 = kk_std_core_types__list_unbox(_x_x1520, KK_OWNED, _ctx); /*list<2453>*/
    kk_std_core_types__list _b_x520_522;
    kk_box_t _x_x1521 = kk_cctx_apply(acc2_10087,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    _b_x520_522 = kk_std_core_types__list_unbox(_x_x1521, KK_OWNED, _ctx); /*list<2453>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x519_521, _ctx), kk_std_core_types__list_box(_b_x520_522, _ctx), _ctx);
  }
  {
    return kk_std_core_list__unroll_partition_acc_10014(xs, pred, acc1_10086, acc2_10087, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_list__mlift_lift_lookup_10367_10697(kk_std_core_types__tuple2 _uniq_x_10324, kk_std_core_types__list _uniq_xx_10325, kk_function_t pred, bool _y_x10552, kk_context_t* _ctx) { /* forall<a,b,e> ((a, b), list<(a, b)>, pred : (a) -> e bool, bool) -> e maybe<b> */ 
  if (_y_x10552) {
    kk_function_drop(pred, _ctx);
    kk_std_core_types__list_drop(_uniq_xx_10325, _ctx);
    kk_box_t _x_x1522;
    {
      kk_box_t _x_0 = _uniq_x_10324.snd;
      kk_box_dup(_x_0, _ctx);
      kk_std_core_types__tuple2_drop(_uniq_x_10324, _ctx);
      _x_x1522 = _x_0; /*2579*/
    }
    return kk_std_core_types__new_Just(_x_x1522, _ctx);
  }
  {
    kk_std_core_types__tuple2_drop(_uniq_x_10324, _ctx);
    return kk_std_core_list__lift_lookup_10367(pred, _uniq_xx_10325, _ctx);
  }
}
 
// lifted local: lookup, @spec-x10328
// specialized: std/core/list/@unroll-foreach-while@10009, on parameters @uniq-action@10321, using:
// @uniq-action@10321 = fn<(e :: E)>(kv: (2578, 2579)){
//   match ((pred((std/core/types/@open<(total :: E),(e :: E),(tuple2 : (a, b)) -> a,(tuple2 : (a, b)) -> (e :: E) a>((fn(tuple2: (2578, 2579)){
//     (match (tuple2) {
//       ((@skip std/core/types/Tuple2((@x: 2578) : a, (@pat@0@0: 2579) : a) : (a, b) ) as @pat@1: (2578, 2579))
//          -> @x;
//     });
//   }))(kv))))) {
//     ((std/core/types/True() : bool ) as @pat@2: bool)
//        -> std/core/types/Just<a>((std/core/types/@open<(total :: E),(e :: E),(tuple2 : (a, b)) -> b,(tuple2 : (a, b)) -> (e :: E) b>((fn(tuple2@0: (2578, 2579)){
//         (match (tuple2@0) {
//           ((@skip std/core/types/Tuple2((@pat@0@1: 2578) : a, (@x@0: 2579) : a) : (a, b) ) as @pat@3: (2578, 2579))
//              -> @x@0;
//         });
//       }))(kv)));
//     ((@skip std/core/types/False() : bool ) as @pat@0@2: bool)
//        -> std/core/types/Nothing<a>;
//   };
// }


// lift anonymous function
struct kk_std_core_list__lift_lookup_10367_fun1527__t {
  struct kk_function_s _base;
  kk_std_core_types__tuple2 _uniq_x_10324_0;
  kk_std_core_types__list _uniq_xx_10325_0;
  kk_function_t pred_0;
};
static kk_box_t kk_std_core_list__lift_lookup_10367_fun1527(kk_function_t _fself, kk_box_t _b_x529, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_lookup_10367_fun1527(kk_std_core_types__tuple2 _uniq_x_10324_0, kk_std_core_types__list _uniq_xx_10325_0, kk_function_t pred_0, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_lookup_10367_fun1527__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_lookup_10367_fun1527__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_lookup_10367_fun1527, kk_context());
  _self->_uniq_x_10324_0 = _uniq_x_10324_0;
  _self->_uniq_xx_10325_0 = _uniq_xx_10325_0;
  _self->pred_0 = pred_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_lookup_10367_fun1527(kk_function_t _fself, kk_box_t _b_x529, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_lookup_10367_fun1527__t* _self = kk_function_as(struct kk_std_core_list__lift_lookup_10367_fun1527__t*, _fself, _ctx);
  kk_std_core_types__tuple2 _uniq_x_10324_0 = _self->_uniq_x_10324_0; /* (2578, 2579) */
  kk_std_core_types__list _uniq_xx_10325_0 = _self->_uniq_xx_10325_0; /* list<(2578, 2579)> */
  kk_function_t pred_0 = _self->pred_0; /* (2578) -> 2580 bool */
  kk_drop_match(_self, {kk_std_core_types__tuple2_dup(_uniq_x_10324_0, _ctx);kk_std_core_types__list_dup(_uniq_xx_10325_0, _ctx);kk_function_dup(pred_0, _ctx);}, {}, _ctx)
  bool _y_x10552_0_531 = kk_bool_unbox(_b_x529); /*bool*/;
  kk_std_core_types__maybe _x_x1528 = kk_std_core_list__mlift_lift_lookup_10367_10697(_uniq_x_10324_0, _uniq_xx_10325_0, pred_0, _y_x10552_0_531, _ctx); /*maybe<2579>*/
  return kk_std_core_types__maybe_box(_x_x1528, _ctx);
}

kk_std_core_types__maybe kk_std_core_list__lift_lookup_10367(kk_function_t pred_0, kk_std_core_types__list _uniq_xs_10320, kk_context_t* _ctx) { /* forall<a,b,e> (pred : (a) -> e bool, list<(a, b)>) -> e maybe<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(_uniq_xs_10320, _ctx)) {
    kk_function_drop(pred_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1523 = kk_std_core_types__as_Cons(_uniq_xs_10320, _ctx);
    kk_box_t _box_x527 = _con_x1523->head;
    kk_std_core_types__list _uniq_xx_10325_0 = _con_x1523->tail;
    kk_std_core_types__tuple2 _uniq_x_10324_0 = kk_std_core_types__tuple2_unbox(_box_x527, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10320, _ctx)) {
      kk_std_core_types__tuple2_dup(_uniq_x_10324_0, _ctx);
      kk_box_drop(_box_x527, _ctx);
      kk_datatype_ptr_free(_uniq_xs_10320, _ctx);
    }
    else {
      kk_std_core_types__tuple2_dup(_uniq_x_10324_0, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10325_0, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10320, _ctx);
    }
    bool x_10761;
    kk_function_t _x_x1525 = kk_function_dup(pred_0, _ctx); /*(2578) -> 2580 bool*/
    kk_box_t _x_x1524;
    {
      kk_box_t _x = _uniq_x_10324_0.fst;
      kk_box_dup(_x, _ctx);
      _x_x1524 = _x; /*2578*/
    }
    x_10761 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1525, (_x_x1525, _x_x1524, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1526 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_lookup_10367_fun1527(_uniq_x_10324_0, _uniq_xx_10325_0, pred_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__maybe_unbox(_x_x1526, KK_OWNED, _ctx);
    }
    if (x_10761) {
      kk_function_drop(pred_0, _ctx);
      kk_std_core_types__list_drop(_uniq_xx_10325_0, _ctx);
      kk_box_t _x_x1529;
      {
        kk_box_t _x_0_0 = _uniq_x_10324_0.snd;
        kk_box_dup(_x_0_0, _ctx);
        kk_std_core_types__tuple2_drop(_uniq_x_10324_0, _ctx);
        _x_x1529 = _x_0_0; /*2579*/
      }
      return kk_std_core_types__new_Just(_x_x1529, _ctx);
    }
    {
      kk_std_core_types__tuple2_drop(_uniq_x_10324_0, _ctx);
      { // tailcall
        _uniq_xs_10320 = _uniq_xx_10325_0;
        goto kk__tailcall;
      }
    }
  }
}
 
// monadic lift

kk_integer_t kk_std_core_list__mlift_unroll_index_of_acc_10015_10698(kk_integer_t idx, kk_function_t pred, kk_std_core_types__list xx, bool _y_x10559, kk_context_t* _ctx) { /* forall<a,e> (idx : int, pred : (a) -> e bool, xx : list<a>, bool) -> e int */ 
  if (_y_x10559) {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(pred, _ctx);
    return idx;
  }
  {
    kk_integer_t _x_x1530 = kk_integer_add_small_const(idx, 1, _ctx); /*int*/
    return kk_std_core_list__unroll_index_of_acc_10015(xx, pred, _x_x1530, _ctx);
  }
}


// lift anonymous function
struct kk_std_core_list__unroll_index_of_acc_10015_fun1534__t {
  struct kk_function_s _base;
  kk_integer_t idx_0;
  kk_function_t pred_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_index_of_acc_10015_fun1534(kk_function_t _fself, kk_box_t _b_x533, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_index_of_acc_10015_fun1534(kk_integer_t idx_0, kk_function_t pred_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_index_of_acc_10015_fun1534__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_index_of_acc_10015_fun1534__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_index_of_acc_10015_fun1534, kk_context());
  _self->idx_0 = idx_0;
  _self->pred_0 = pred_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_index_of_acc_10015_fun1534(kk_function_t _fself, kk_box_t _b_x533, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_index_of_acc_10015_fun1534__t* _self = kk_function_as(struct kk_std_core_list__unroll_index_of_acc_10015_fun1534__t*, _fself, _ctx);
  kk_integer_t idx_0 = _self->idx_0; /* int */
  kk_function_t pred_0 = _self->pred_0; /* (2625) -> 2626 bool */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<2625> */
  kk_drop_match(_self, {kk_integer_dup(idx_0, _ctx);kk_function_dup(pred_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10559_0_535 = kk_bool_unbox(_b_x533); /*bool*/;
  kk_integer_t _x_x1535 = kk_std_core_list__mlift_unroll_index_of_acc_10015_10698(idx_0, pred_0, xx_0, _y_x10559_0_535, _ctx); /*int*/
  return kk_integer_box(_x_x1535, _ctx);
}

kk_integer_t kk_std_core_list__unroll_index_of_acc_10015(kk_std_core_types__list xs, kk_function_t pred_0, kk_integer_t idx_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, idx : int) -> e int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1531 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1531->head;
    kk_std_core_types__list xx_0 = _con_x1531->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_0_10764;
    kk_function_t _x_x1532 = kk_function_dup(pred_0, _ctx); /*(2625) -> 2626 bool*/
    x_0_10764 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1532, (_x_x1532, x, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1533 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_index_of_acc_10015_fun1534(idx_0, pred_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_integer_unbox(_x_x1533, _ctx);
    }
    if (x_0_10764) {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(pred_0, _ctx);
      return idx_0;
    }
    { // tailcall
      kk_integer_t _x_x1536 = kk_integer_add_small_const(idx_0, 1, _ctx); /*int*/
      xs = xx_0;
      idx_0 = _x_x1536;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(pred_0, _ctx);
    kk_integer_drop(idx_0, _ctx);
    return kk_integer_from_small(-1);
  }
}
 
// monadic lift

kk_unit_t kk_std_core_list__mlift_unroll_foreach_10016_10699(kk_function_t action, kk_std_core_types__list xx, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (action : (a) -> e (), xx : list<a>, wild_ : ()) -> e () */ 
  kk_std_core_list__unroll_foreach_10016(xx, action, _ctx); return kk_Unit;
}
 
// Invoke `action` for each element of a list


// lift anonymous function
struct kk_std_core_list__unroll_foreach_10016_fun1540__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_foreach_10016_fun1540(kk_function_t _fself, kk_box_t _b_x537, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_foreach_10016_fun1540(kk_function_t action_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foreach_10016_fun1540__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_foreach_10016_fun1540__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_foreach_10016_fun1540, kk_context());
  _self->action_0 = action_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_foreach_10016_fun1540(kk_function_t _fself, kk_box_t _b_x537, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foreach_10016_fun1540__t* _self = kk_function_as(struct kk_std_core_list__unroll_foreach_10016_fun1540__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (2691) -> 2692 () */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<2691> */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_539 = kk_Unit;
  kk_unit_unbox(_b_x537);
  kk_unit_t _x_x1541 = kk_Unit;
  kk_std_core_list__mlift_unroll_foreach_10016_10699(action_0, xx_0, wild___0_539, _ctx);
  return kk_unit_box(_x_x1541);
}

kk_unit_t kk_std_core_list__unroll_foreach_10016(kk_std_core_types__list xs, kk_function_t action_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, action : (a) -> e ()) -> e () */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1537 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1537->head;
    kk_std_core_types__list xx_0 = _con_x1537->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_unit_t x_0_10767 = kk_Unit;
    kk_function_t _x_x1538 = kk_function_dup(action_0, _ctx); /*(2691) -> 2692 ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1538, (_x_x1538, x, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1539 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_foreach_10016_fun1540(action_0, xx_0, _ctx), _ctx); /*2978*/
      kk_unit_unbox(_x_x1539); return kk_Unit;
    }
    { // tailcall
      xs = xx_0;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(action_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_map_while_10017_10700(kk_std_core_types__cctx _acc, kk_function_t action, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10572, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Just(_y_x10572, _ctx)) {
    kk_box_t y = _y_x10572._cons.Just.value;
    kk_std_core_types__list _trmc_x10416 = kk_datatype_null(); /*list<2754>*/;
    kk_std_core_types__list _trmc_x10417 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _trmc_x10416, _ctx); /*list<2754>*/;
    kk_field_addr_t _b_x545_550 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10417, _ctx)->tail, _ctx); /*@field-addr<list<2754>>*/;
    kk_std_core_types__cctx _x_x1542 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10417, _ctx)),_b_x545_550,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_unroll_map_while_10017(xx, action, _x_x1542, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(action, _ctx);
    kk_box_t _x_x1543 = kk_cctx_apply(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1543, KK_OWNED, _ctx);
  }
}
 
// Invoke `action` on each element of a list while `action` returns `Just`


// lift anonymous function
struct kk_std_core_list__trmc_unroll_map_while_10017_fun1548__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t action_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_map_while_10017_fun1548(kk_function_t _fself, kk_box_t _b_x559, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_map_while_10017_fun1548(kk_std_core_types__cctx _acc_0, kk_function_t action_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_map_while_10017_fun1548__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_map_while_10017_fun1548__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_map_while_10017_fun1548, kk_context());
  _self->_acc_0 = _acc_0;
  _self->action_0 = action_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_map_while_10017_fun1548(kk_function_t _fself, kk_box_t _b_x559, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_map_while_10017_fun1548__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_map_while_10017_fun1548__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2754>> */
  kk_function_t action_0 = _self->action_0; /* (2753) -> 2755 maybe<2754> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<2753> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(action_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10572_0_579 = kk_std_core_types__maybe_unbox(_b_x559, KK_OWNED, _ctx); /*maybe<2754>*/;
  kk_std_core_types__list _x_x1549 = kk_std_core_list__mlift_trmc_unroll_map_while_10017_10700(_acc_0, action_0, xx_0, _y_x10572_0_579, _ctx); /*list<2754>*/
  return kk_std_core_types__list_box(_x_x1549, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_map_while_10017(kk_std_core_types__list xs, kk_function_t action_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(action_0, _ctx);
    kk_box_t _x_x1544 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1544, KK_OWNED, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1545 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1545->head;
    kk_std_core_types__list xx_0 = _con_x1545->tail;
    kk_reuse_t _ru_x1254 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1254 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__maybe x_0_10770;
    kk_function_t _x_x1546 = kk_function_dup(action_0, _ctx); /*(2753) -> 2755 maybe<2754>*/
    x_0_10770 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x1546, (_x_x1546, x, _ctx), _ctx); /*maybe<2754>*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1254,kk_context());
      kk_std_core_types__maybe_drop(x_0_10770, _ctx);
      kk_box_t _x_x1547 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_map_while_10017_fun1548(_acc_0, action_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1547, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Just(x_0_10770, _ctx)) {
      kk_box_t y_0 = x_0_10770._cons.Just.value;
      kk_std_core_types__list _trmc_x10416_0 = kk_datatype_null(); /*list<2754>*/;
      kk_std_core_types__list _trmc_x10417_0 = kk_std_core_types__new_Cons(_ru_x1254, kk_field_index_of(struct kk_std_core_types_Cons, tail), y_0, _trmc_x10416_0, _ctx); /*list<2754>*/;
      kk_field_addr_t _b_x565_573 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10417_0, _ctx)->tail, _ctx); /*@field-addr<list<2754>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1550 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10417_0, _ctx)),_b_x565_573,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1550;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1254,kk_context());
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(action_0, _ctx);
      kk_box_t _x_x1551 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1551, KK_OWNED, _ctx);
    }
  }
}
 
// Invoke `action` on each element of a list while `action` returns `Just`

kk_std_core_types__list kk_std_core_list__unroll_map_while_10017(kk_std_core_types__list xs_0, kk_function_t action_1, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1552 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_map_while_10017(xs_0, action_1, _x_x1552, _ctx);
}
 
// monadic lift

kk_unit_t kk_std_core_list__mlift_lift_foreach_indexed_10368_10701(kk_std_core_types__list _uniq_xx_10334, kk_function_t action, kk_ref_t i, kk_unit_t _uniq_x___10335, kk_context_t* _ctx) { /* forall<h,a,e> (list<a>, action : (int, a) -> e (), i : local-var<h,int>, ()) -> <local<h>|e> () */ 
  kk_std_core_list__lift_foreach_indexed_10368(action, i, _uniq_xx_10334, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_list__mlift_lift_foreach_indexed_10368_10702_fun1554__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10334_0;
  kk_function_t action_0;
  kk_ref_t i_0;
};
static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10368_10702_fun1554(kk_function_t _fself, kk_box_t _b_x585, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_mlift_lift_foreach_indexed_10368_10702_fun1554(kk_std_core_types__list _uniq_xx_10334_0, kk_function_t action_0, kk_ref_t i_0, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10368_10702_fun1554__t* _self = kk_function_alloc_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10368_10702_fun1554__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__mlift_lift_foreach_indexed_10368_10702_fun1554, kk_context());
  _self->_uniq_xx_10334_0 = _uniq_xx_10334_0;
  _self->action_0 = action_0;
  _self->i_0 = i_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10368_10702_fun1554(kk_function_t _fself, kk_box_t _b_x585, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10368_10702_fun1554__t* _self = kk_function_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10368_10702_fun1554__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10334_0 = _self->_uniq_xx_10334_0; /* list<2870> */
  kk_function_t action_0 = _self->action_0; /* (int, 2870) -> 2871 () */
  kk_ref_t i_0 = _self->i_0; /* local-var<2864,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10334_0, _ctx);kk_function_dup(action_0, _ctx);kk_ref_dup(i_0, _ctx);}, {}, _ctx)
  kk_unit_t _uniq_x___10335_0_587 = kk_Unit;
  kk_unit_unbox(_b_x585);
  kk_unit_t _x_x1555 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10368_10701(_uniq_xx_10334_0, action_0, i_0, _uniq_x___10335_0_587, _ctx);
  return kk_unit_box(_x_x1555);
}

kk_unit_t kk_std_core_list__mlift_lift_foreach_indexed_10368_10702(kk_std_core_types__list _uniq_xx_10334_0, kk_function_t action_0, kk_ref_t i_0, kk_integer_t _y_x10582, kk_context_t* _ctx) { /* forall<h,a,e> (list<a>, action : (int, a) -> e (), i : local-var<h,int>, int) -> <local<h>|e> () */ 
  kk_integer_t _b_x581_583 = kk_integer_add_small_const(_y_x10582, 1, _ctx); /*int*/;
  kk_unit_t x_10773 = kk_Unit;
  kk_ref_set_borrow(i_0,(kk_integer_box(_b_x581_583, _ctx)),kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1553 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_mlift_lift_foreach_indexed_10368_10702_fun1554(_uniq_xx_10334_0, action_0, i_0, _ctx), _ctx); /*2978*/
    kk_unit_unbox(_x_x1553); return kk_Unit;
  }
  {
    kk_std_core_list__mlift_lift_foreach_indexed_10368_10701(_uniq_xx_10334_0, action_0, i_0, x_10773, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_list__mlift_lift_foreach_indexed_10368_10703_fun1559__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10334_1;
  kk_function_t action_1;
  kk_ref_t i_1;
};
static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10368_10703_fun1559(kk_function_t _fself, kk_box_t _b_x591, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_mlift_lift_foreach_indexed_10368_10703_fun1559(kk_std_core_types__list _uniq_xx_10334_1, kk_function_t action_1, kk_ref_t i_1, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10368_10703_fun1559__t* _self = kk_function_alloc_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10368_10703_fun1559__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__mlift_lift_foreach_indexed_10368_10703_fun1559, kk_context());
  _self->_uniq_xx_10334_1 = _uniq_xx_10334_1;
  _self->action_1 = action_1;
  _self->i_1 = i_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10368_10703_fun1559(kk_function_t _fself, kk_box_t _b_x591, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10368_10703_fun1559__t* _self = kk_function_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10368_10703_fun1559__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10334_1 = _self->_uniq_xx_10334_1; /* list<2870> */
  kk_function_t action_1 = _self->action_1; /* (int, 2870) -> 2871 () */
  kk_ref_t i_1 = _self->i_1; /* local-var<2864,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10334_1, _ctx);kk_function_dup(action_1, _ctx);kk_ref_dup(i_1, _ctx);}, {}, _ctx)
  kk_integer_t _y_x10582_0_593 = kk_integer_unbox(_b_x591, _ctx); /*int*/;
  kk_unit_t _x_x1560 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10368_10702(_uniq_xx_10334_1, action_1, i_1, _y_x10582_0_593, _ctx);
  return kk_unit_box(_x_x1560);
}

kk_unit_t kk_std_core_list__mlift_lift_foreach_indexed_10368_10703(kk_std_core_types__list _uniq_xx_10334_1, kk_function_t action_1, kk_ref_t i_1, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<h,a,e> (list<a>, action : (int, a) -> e (), i : local-var<h,int>, wild_ : ()) -> <local<h>|e> () */ 
  kk_integer_t x_0_10775;
  kk_box_t _x_x1556;
  kk_ref_t _x_x1557 = kk_ref_dup(i_1, _ctx); /*local-var<2864,int>*/
  _x_x1556 = kk_ref_get(_x_x1557,kk_context()); /*294*/
  x_0_10775 = kk_integer_unbox(_x_x1556, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_0_10775, _ctx);
    kk_box_t _x_x1558 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_mlift_lift_foreach_indexed_10368_10703_fun1559(_uniq_xx_10334_1, action_1, i_1, _ctx), _ctx); /*2978*/
    kk_unit_unbox(_x_x1558); return kk_Unit;
  }
  {
    kk_std_core_list__mlift_lift_foreach_indexed_10368_10702(_uniq_xx_10334_1, action_1, i_1, x_0_10775, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_list__mlift_lift_foreach_indexed_10368_10704_fun1563__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10334_2;
  kk_function_t action_2;
  kk_ref_t i_2;
};
static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10368_10704_fun1563(kk_function_t _fself, kk_box_t _b_x595, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_mlift_lift_foreach_indexed_10368_10704_fun1563(kk_std_core_types__list _uniq_xx_10334_2, kk_function_t action_2, kk_ref_t i_2, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10368_10704_fun1563__t* _self = kk_function_alloc_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10368_10704_fun1563__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__mlift_lift_foreach_indexed_10368_10704_fun1563, kk_context());
  _self->_uniq_xx_10334_2 = _uniq_xx_10334_2;
  _self->action_2 = action_2;
  _self->i_2 = i_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10368_10704_fun1563(kk_function_t _fself, kk_box_t _b_x595, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10368_10704_fun1563__t* _self = kk_function_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10368_10704_fun1563__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10334_2 = _self->_uniq_xx_10334_2; /* list<2870> */
  kk_function_t action_2 = _self->action_2; /* (int, 2870) -> 2871 () */
  kk_ref_t i_2 = _self->i_2; /* local-var<2864,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10334_2, _ctx);kk_function_dup(action_2, _ctx);kk_ref_dup(i_2, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_597 = kk_Unit;
  kk_unit_unbox(_b_x595);
  kk_unit_t _x_x1564 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10368_10703(_uniq_xx_10334_2, action_2, i_2, wild___0_597, _ctx);
  return kk_unit_box(_x_x1564);
}

kk_unit_t kk_std_core_list__mlift_lift_foreach_indexed_10368_10704(kk_box_t _uniq_x_10333, kk_std_core_types__list _uniq_xx_10334_2, kk_function_t action_2, kk_ref_t i_2, kk_integer_t j, kk_context_t* _ctx) { /* forall<h,a,e> (a, list<a>, action : (int, a) -> e (), i : local-var<h,int>, j : int) -> <local<h>|e> () */ 
  kk_unit_t x_1_10777 = kk_Unit;
  kk_function_t _x_x1561 = kk_function_dup(action_2, _ctx); /*(int, 2870) -> 2871 ()*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x_x1561, (_x_x1561, j, _uniq_x_10333, _ctx), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1562 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_mlift_lift_foreach_indexed_10368_10704_fun1563(_uniq_xx_10334_2, action_2, i_2, _ctx), _ctx); /*2978*/
    kk_unit_unbox(_x_x1562); return kk_Unit;
  }
  {
    kk_std_core_list__mlift_lift_foreach_indexed_10368_10703(_uniq_xx_10334_2, action_2, i_2, x_1_10777, _ctx); return kk_Unit;
  }
}
 
// lifted local: foreach-indexed, @spec-x10337
// specialized: std/core/list/@unroll-foreach@10016, on parameters @uniq-action@10331, using:
// @uniq-action@10331 = fn<<(local :: H -> X)<(h :: H)>|(e :: E)>>(x: 2870){
//   val j : int;
//   val _ : ();
//   std/core/types/local-set<int,(e :: E),(h :: H)>(i, (std/core/types/@open<(total :: E),<(local :: H -> X)<(h :: H)>|(e :: E)>,(x : int, y : int) -> int,(x : int, y : int) -> <(local :: H -> X)<(h :: H)>|(e :: E)> int>((fn(x@0: int, y: int){
//       (std/core/int/int-add(x@0, y));
//     }))((std/core/types/local-get<int,(h :: H),(e :: E)>(i)), 1)));
// }


// lift anonymous function
struct kk_std_core_list__lift_foreach_indexed_10368_fun1569__t {
  struct kk_function_s _base;
  kk_box_t _uniq_x_10333_0;
  kk_std_core_types__list _uniq_xx_10334_3;
  kk_function_t action_4;
  kk_ref_t i_3;
};
static kk_box_t kk_std_core_list__lift_foreach_indexed_10368_fun1569(kk_function_t _fself, kk_box_t _b_x601, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_foreach_indexed_10368_fun1569(kk_box_t _uniq_x_10333_0, kk_std_core_types__list _uniq_xx_10334_3, kk_function_t action_4, kk_ref_t i_3, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10368_fun1569__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_foreach_indexed_10368_fun1569__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_foreach_indexed_10368_fun1569, kk_context());
  _self->_uniq_x_10333_0 = _uniq_x_10333_0;
  _self->_uniq_xx_10334_3 = _uniq_xx_10334_3;
  _self->action_4 = action_4;
  _self->i_3 = i_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_foreach_indexed_10368_fun1569(kk_function_t _fself, kk_box_t _b_x601, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10368_fun1569__t* _self = kk_function_as(struct kk_std_core_list__lift_foreach_indexed_10368_fun1569__t*, _fself, _ctx);
  kk_box_t _uniq_x_10333_0 = _self->_uniq_x_10333_0; /* 2870 */
  kk_std_core_types__list _uniq_xx_10334_3 = _self->_uniq_xx_10334_3; /* list<2870> */
  kk_function_t action_4 = _self->action_4; /* (int, 2870) -> 2871 () */
  kk_ref_t i_3 = _self->i_3; /* local-var<2864,int> */
  kk_drop_match(_self, {kk_box_dup(_uniq_x_10333_0, _ctx);kk_std_core_types__list_dup(_uniq_xx_10334_3, _ctx);kk_function_dup(action_4, _ctx);kk_ref_dup(i_3, _ctx);}, {}, _ctx)
  kk_integer_t j_0_618 = kk_integer_unbox(_b_x601, _ctx); /*int*/;
  kk_unit_t _x_x1570 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10368_10704(_uniq_x_10333_0, _uniq_xx_10334_3, action_4, i_3, j_0_618, _ctx);
  return kk_unit_box(_x_x1570);
}


// lift anonymous function
struct kk_std_core_list__lift_foreach_indexed_10368_fun1573__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10334_3;
  kk_function_t action_4;
  kk_ref_t i_3;
};
static kk_box_t kk_std_core_list__lift_foreach_indexed_10368_fun1573(kk_function_t _fself, kk_box_t _b_x603, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_foreach_indexed_10368_fun1573(kk_std_core_types__list _uniq_xx_10334_3, kk_function_t action_4, kk_ref_t i_3, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10368_fun1573__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_foreach_indexed_10368_fun1573__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_foreach_indexed_10368_fun1573, kk_context());
  _self->_uniq_xx_10334_3 = _uniq_xx_10334_3;
  _self->action_4 = action_4;
  _self->i_3 = i_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_foreach_indexed_10368_fun1573(kk_function_t _fself, kk_box_t _b_x603, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10368_fun1573__t* _self = kk_function_as(struct kk_std_core_list__lift_foreach_indexed_10368_fun1573__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10334_3 = _self->_uniq_xx_10334_3; /* list<2870> */
  kk_function_t action_4 = _self->action_4; /* (int, 2870) -> 2871 () */
  kk_ref_t i_3 = _self->i_3; /* local-var<2864,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10334_3, _ctx);kk_function_dup(action_4, _ctx);kk_ref_dup(i_3, _ctx);}, {}, _ctx)
  kk_unit_t wild___1_619 = kk_Unit;
  kk_unit_unbox(_b_x603);
  kk_unit_t _x_x1574 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10368_10703(_uniq_xx_10334_3, action_4, i_3, wild___1_619, _ctx);
  return kk_unit_box(_x_x1574);
}


// lift anonymous function
struct kk_std_core_list__lift_foreach_indexed_10368_fun1578__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10334_3;
  kk_function_t action_4;
  kk_ref_t i_3;
};
static kk_box_t kk_std_core_list__lift_foreach_indexed_10368_fun1578(kk_function_t _fself, kk_box_t _b_x607, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_foreach_indexed_10368_fun1578(kk_std_core_types__list _uniq_xx_10334_3, kk_function_t action_4, kk_ref_t i_3, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10368_fun1578__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_foreach_indexed_10368_fun1578__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_foreach_indexed_10368_fun1578, kk_context());
  _self->_uniq_xx_10334_3 = _uniq_xx_10334_3;
  _self->action_4 = action_4;
  _self->i_3 = i_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_foreach_indexed_10368_fun1578(kk_function_t _fself, kk_box_t _b_x607, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10368_fun1578__t* _self = kk_function_as(struct kk_std_core_list__lift_foreach_indexed_10368_fun1578__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10334_3 = _self->_uniq_xx_10334_3; /* list<2870> */
  kk_function_t action_4 = _self->action_4; /* (int, 2870) -> 2871 () */
  kk_ref_t i_3 = _self->i_3; /* local-var<2864,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10334_3, _ctx);kk_function_dup(action_4, _ctx);kk_ref_dup(i_3, _ctx);}, {}, _ctx)
  kk_integer_t _y_x10582_1_620 = kk_integer_unbox(_b_x607, _ctx); /*int*/;
  kk_unit_t _x_x1579 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10368_10702(_uniq_xx_10334_3, action_4, i_3, _y_x10582_1_620, _ctx);
  return kk_unit_box(_x_x1579);
}


// lift anonymous function
struct kk_std_core_list__lift_foreach_indexed_10368_fun1581__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10334_3;
  kk_function_t action_4;
  kk_ref_t i_3;
};
static kk_box_t kk_std_core_list__lift_foreach_indexed_10368_fun1581(kk_function_t _fself, kk_box_t _b_x613, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_foreach_indexed_10368_fun1581(kk_std_core_types__list _uniq_xx_10334_3, kk_function_t action_4, kk_ref_t i_3, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10368_fun1581__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_foreach_indexed_10368_fun1581__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_foreach_indexed_10368_fun1581, kk_context());
  _self->_uniq_xx_10334_3 = _uniq_xx_10334_3;
  _self->action_4 = action_4;
  _self->i_3 = i_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_foreach_indexed_10368_fun1581(kk_function_t _fself, kk_box_t _b_x613, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10368_fun1581__t* _self = kk_function_as(struct kk_std_core_list__lift_foreach_indexed_10368_fun1581__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10334_3 = _self->_uniq_xx_10334_3; /* list<2870> */
  kk_function_t action_4 = _self->action_4; /* (int, 2870) -> 2871 () */
  kk_ref_t i_3 = _self->i_3; /* local-var<2864,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10334_3, _ctx);kk_function_dup(action_4, _ctx);kk_ref_dup(i_3, _ctx);}, {}, _ctx)
  kk_unit_t _uniq_x___10335_1_621 = kk_Unit;
  kk_unit_unbox(_b_x613);
  kk_unit_t _x_x1582 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10368_10701(_uniq_xx_10334_3, action_4, i_3, _uniq_x___10335_1_621, _ctx);
  return kk_unit_box(_x_x1582);
}

kk_unit_t kk_std_core_list__lift_foreach_indexed_10368(kk_function_t action_4, kk_ref_t i_3, kk_std_core_types__list _uniq_xs_10330, kk_context_t* _ctx) { /* forall<h,a,e> (action : (int, a) -> e (), i : local-var<h,int>, list<a>) -> <local<h>|e> () */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10330, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1565 = kk_std_core_types__as_Cons(_uniq_xs_10330, _ctx);
    kk_box_t _uniq_x_10333_0 = _con_x1565->head;
    kk_std_core_types__list _uniq_xx_10334_3 = _con_x1565->tail;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10330, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10330, _ctx);
    }
    else {
      kk_box_dup(_uniq_x_10333_0, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10334_3, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10330, _ctx);
    }
    kk_integer_t x_2_10780;
    kk_box_t _x_x1566;
    kk_ref_t _x_x1567 = kk_ref_dup(i_3, _ctx); /*local-var<2864,int>*/
    _x_x1566 = kk_ref_get(_x_x1567,kk_context()); /*294*/
    x_2_10780 = kk_integer_unbox(_x_x1566, _ctx); /*int*/
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_2_10780, _ctx);
      kk_box_t _x_x1568 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_foreach_indexed_10368_fun1569(_uniq_x_10333_0, _uniq_xx_10334_3, action_4, i_3, _ctx), _ctx); /*2978*/
      kk_unit_unbox(_x_x1568); return kk_Unit;
    }
    {
      kk_unit_t x_3_10783 = kk_Unit;
      kk_function_t _x_x1571 = kk_function_dup(action_4, _ctx); /*(int, 2870) -> 2871 ()*/
      kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x_x1571, (_x_x1571, x_2_10780, _uniq_x_10333_0, _ctx), _ctx);
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1572 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_foreach_indexed_10368_fun1573(_uniq_xx_10334_3, action_4, i_3, _ctx), _ctx); /*2978*/
        kk_unit_unbox(_x_x1572); return kk_Unit;
      }
      {
        kk_integer_t x_4_10787;
        kk_box_t _x_x1575;
        kk_ref_t _x_x1576 = kk_ref_dup(i_3, _ctx); /*local-var<2864,int>*/
        _x_x1575 = kk_ref_get(_x_x1576,kk_context()); /*294*/
        x_4_10787 = kk_integer_unbox(_x_x1575, _ctx); /*int*/
        if (kk_yielding(kk_context())) {
          kk_integer_drop(x_4_10787, _ctx);
          kk_box_t _x_x1577 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_foreach_indexed_10368_fun1578(_uniq_xx_10334_3, action_4, i_3, _ctx), _ctx); /*2978*/
          kk_unit_unbox(_x_x1577); return kk_Unit;
        }
        {
          kk_integer_t _b_x609_611 = kk_integer_add_small_const(x_4_10787, 1, _ctx); /*int*/;
          kk_unit_t x_5_10790 = kk_Unit;
          kk_ref_set_borrow(i_3,(kk_integer_box(_b_x609_611, _ctx)),kk_context());
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x1580 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_foreach_indexed_10368_fun1581(_uniq_xx_10334_3, action_4, i_3, _ctx), _ctx); /*2978*/
            kk_unit_unbox(_x_x1580); return kk_Unit;
          }
          { // tailcall
            _uniq_xs_10330 = _uniq_xx_10334_3;
            goto kk__tailcall;
          }
        }
      }
    }
  }
  {
    kk_ref_drop(i_3, _ctx);
    kk_function_drop(action_4, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// Invoke `action` for each element of a list, passing also the position of the element.

kk_unit_t kk_std_core_list_foreach_indexed(kk_std_core_types__list xs, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, action : (int, a) -> e ()) -> e () */ 
  kk_ref_t loc = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0), _ctx)),kk_context()); /*local-var<2864,int>*/;
  kk_unit_t res = kk_Unit;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(action, _ctx);
  }
  else {
    kk_ref_t _x_x1583 = kk_ref_dup(loc, _ctx); /*local-var<2864,int>*/
    kk_std_core_list__lift_foreach_indexed_10368(action, _x_x1583, xs, _ctx);
  }
  kk_box_t _x_x1584 = kk_std_core_hnd_prompt_local_var(loc, kk_unit_box(res), _ctx); /*9564*/
  kk_unit_unbox(_x_x1584); return kk_Unit;
}
 
// lifted local: intersperse, before

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_intersperse_4952_10018(kk_box_t sep, kk_std_core_types__list ys, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (sep : a, ys : list<a>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1585 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1585->head;
    kk_std_core_types__list yy = _con_x1585->tail;
    kk_reuse_t _ru_x1256 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1256 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _trmc_x10418;
    kk_std_core_types__list _x_x1586 = kk_datatype_null(); /*list<2937>*/
    _trmc_x10418 = kk_std_core_types__new_Cons(_ru_x1256, 0, y, _x_x1586, _ctx); /*list<2937>*/
    kk_field_addr_t _b_x633_638 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10418, _ctx)->tail, _ctx); /*@field-addr<list<2937>>*/;
    { // tailcall
      kk_box_t _x_x1587 = kk_box_dup(sep, _ctx); /*2937*/
      kk_std_core_types__cctx _x_x1588;
      kk_box_t _x_x1589;
      kk_std_core_types__list _x_x1590 = kk_std_core_types__new_Cons(kk_reuse_null, 0, sep, _trmc_x10418, _ctx); /*list<82>*/
      _x_x1589 = kk_std_core_types__list_box(_x_x1590, _ctx); /*0*/
      _x_x1588 = kk_cctx_extend_linear(_acc,_x_x1589,_b_x633_638,kk_context()); /*ctx<0>*/
      sep = _x_x1587;
      ys = yy;
      _acc = _x_x1588;
      goto kk__tailcall;
    }
  }
  {
    kk_box_drop(sep, _ctx);
    kk_box_t _x_x1591 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1591, KK_OWNED, _ctx);
  }
}
 
// lifted local: intersperse, before

kk_std_core_types__list kk_std_core_list__unroll_lift_intersperse_4952_10018(kk_box_t sep_0, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a> (sep : a, ys : list<a>) -> list<a> */ 
  kk_std_core_types__cctx _x_x1592 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_intersperse_4952_10018(sep_0, ys_0, _x_x1592, _ctx);
}
 
// Insert a separator `sep`  between all elements of a list `xs` .

kk_std_core_types__list kk_std_core_list_intersperse(kk_std_core_types__list xs, kk_box_t sep, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, sep : a) -> list<a> */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1593 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1593->head;
    kk_std_core_types__list xx = _con_x1593->tail;
    kk_reuse_t _ru_x1257 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1257 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__list _x_x1594;
    if (kk_std_core_types__is_Nil(xx, _ctx)) {
      kk_box_drop(sep, _ctx);
      _x_x1594 = kk_std_core_types__new_Nil(_ctx); /*forall<a> list<a>*/
    }
    else {
      _x_x1594 = kk_std_core_list__unroll_lift_intersperse_4952_10018(sep, xx, _ctx); /*forall<a> list<a>*/
    }
    return kk_std_core_types__new_Cons(_ru_x1257, 0, x, _x_x1594, _ctx);
  }
  {
    kk_box_drop(sep, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
}
 
// Concatenate all strings in a list

kk_string_t kk_std_core_list_join(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<string>) -> string */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x1596 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x644 = _con_x1596->head;
    kk_std_core_types__list _pat_1 = _con_x1596->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x644);
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      return x;
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x1597 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x645 = _con_x1597->head;
    kk_std_core_types__list _pat_3 = _con_x1597->tail;
    struct kk_std_core_types_Cons* _con_x1598 = kk_std_core_types__as_Cons(_pat_3, _ctx);
    kk_box_t _box_x646 = _con_x1598->head;
    kk_std_core_types__list _pat_4 = _con_x1598->tail;
    if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
      kk_string_t x_0 = kk_string_unbox(_box_x645);
      kk_string_t y = kk_string_unbox(_box_x646);
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
          kk_datatype_ptr_free(_pat_3, _ctx);
        }
        else {
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(_pat_3, _ctx);
        }
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_string_dup(x_0, _ctx);
        kk_string_dup(y, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
    }
  }
  {
    kk_vector_t _x_x1599 = kk_std_core_vector_unvlist(xs, _ctx); /*vector<832>*/
    return kk_string_join(_x_x1599,kk_context());
  }
}
 
// Concatenate all strings in a list

kk_string_t kk_std_core_list_joinsep(kk_std_core_types__list xs, kk_string_t sep, kk_context_t* _ctx) { /* (xs : list<string>, sep : string) -> string */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_string_drop(sep, _ctx);
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x1601 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x647 = _con_x1601->head;
    kk_std_core_types__list _pat_1 = _con_x1601->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x647);
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      kk_string_drop(sep, _ctx);
      return x;
    }
  }
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1602 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x648 = _con_x1602->head;
    kk_std_core_types__list _pat_3 = _con_x1602->tail;
    if (kk_std_core_types__is_Cons(_pat_3, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1603 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x649 = _con_x1603->head;
      kk_std_core_types__list _pat_4 = _con_x1603->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t _x_x1604 = kk_string_dup(sep, _ctx); /*string*/
        kk_string_t _x_x1605 = kk_string_empty(); /*string*/
        if (kk_string_is_eq(_x_x1604,_x_x1605,kk_context())) {
          kk_string_t x_0 = kk_string_unbox(_box_x648);
          kk_string_t y = kk_string_unbox(_box_x649);
          if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
              kk_datatype_ptr_free(_pat_3, _ctx);
            }
            else {
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(_pat_3, _ctx);
            }
            kk_datatype_ptr_free(xs, _ctx);
          }
          else {
            kk_string_dup(x_0, _ctx);
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(xs, _ctx);
          }
          kk_string_drop(sep, _ctx);
          return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
        }
      }
    }
  }
  {
    kk_vector_t _x_x1607 = kk_std_core_vector_unvlist(xs, _ctx); /*vector<832>*/
    return kk_string_join_with(_x_x1607,sep,kk_context());
  }
}
 
// monadic lift

kk_string_t kk_std_core_list__mlift_show_10705(kk_std_core_types__list _c_x10591, kk_context_t* _ctx) { /* (list<string>) -> string */ 
  kk_string_t _x_x1608;
  kk_define_string_literal(, _s_x1609, 1, "[", _ctx)
  _x_x1608 = kk_string_dup(_s_x1609, _ctx); /*string*/
  kk_string_t _x_x1610;
  kk_string_t _x_x1611;
  if (kk_std_core_types__is_Nil(_c_x10591, _ctx)) {
    _x_x1611 = kk_string_empty(); /*string*/
    goto _match_x1612;
  }
  {
    struct kk_std_core_types_Cons* _con_x1614 = kk_std_core_types__as_Cons(_c_x10591, _ctx);
    kk_box_t _box_x650 = _con_x1614->head;
    kk_std_core_types__list _pat_1 = _con_x1614->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x650);
      if kk_likely(kk_datatype_ptr_is_unique(_c_x10591, _ctx)) {
        kk_datatype_ptr_free(_c_x10591, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(_c_x10591, _ctx);
      }
      _x_x1611 = x; /*string*/
      goto _match_x1612;
    }
  }
  if (kk_std_core_types__is_Cons(_c_x10591, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1615 = kk_std_core_types__as_Cons(_c_x10591, _ctx);
    kk_box_t _box_x651 = _con_x1615->head;
    kk_std_core_types__list _pat_3 = _con_x1615->tail;
    if (kk_std_core_types__is_Cons(_pat_3, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1616 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x652 = _con_x1616->head;
      kk_std_core_types__list _pat_4 = _con_x1616->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t _x_x1617;
        kk_define_string_literal(, _s_x1618, 1, ",", _ctx)
        _x_x1617 = kk_string_dup(_s_x1618, _ctx); /*string*/
        kk_string_t _x_x1619 = kk_string_empty(); /*string*/
        if (kk_string_is_eq(_x_x1617,_x_x1619,kk_context())) {
          kk_string_t x_0 = kk_string_unbox(_box_x651);
          kk_string_t y = kk_string_unbox(_box_x652);
          if kk_likely(kk_datatype_ptr_is_unique(_c_x10591, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
              kk_datatype_ptr_free(_pat_3, _ctx);
            }
            else {
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(_pat_3, _ctx);
            }
            kk_datatype_ptr_free(_c_x10591, _ctx);
          }
          else {
            kk_string_dup(x_0, _ctx);
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(_c_x10591, _ctx);
          }
          _x_x1611 = kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx); /*string*/
          goto _match_x1612;
        }
      }
    }
  }
  {
    kk_vector_t _x_x1621 = kk_std_core_vector_unvlist(_c_x10591, _ctx); /*vector<832>*/
    kk_string_t _x_x1622;
    kk_define_string_literal(, _s_x1623, 1, ",", _ctx)
    _x_x1622 = kk_string_dup(_s_x1623, _ctx); /*string*/
    _x_x1611 = kk_string_join_with(_x_x1621,_x_x1622,kk_context()); /*string*/
  }
  _match_x1612: ;
  kk_string_t _x_x1624;
  kk_define_string_literal(, _s_x1625, 1, "]", _ctx)
  _x_x1624 = kk_string_dup(_s_x1625, _ctx); /*string*/
  _x_x1610 = kk_std_core_types__lp__plus__plus__rp_(_x_x1611, _x_x1624, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1608, _x_x1610, _ctx);
}
 
// Show a list


// lift anonymous function
struct kk_std_core_list_show_fun1626__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_show;
};
static kk_box_t kk_std_core_list_show_fun1626(kk_function_t _fself, kk_box_t _b_x655, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_show_fun1626(kk_function_t _implicit_fs_show, kk_context_t* _ctx) {
  struct kk_std_core_list_show_fun1626__t* _self = kk_function_alloc_as(struct kk_std_core_list_show_fun1626__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_show_fun1626, kk_context());
  _self->_implicit_fs_show = _implicit_fs_show;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_show_fun1626(kk_function_t _fself, kk_box_t _b_x655, kk_context_t* _ctx) {
  struct kk_std_core_list_show_fun1626__t* _self = kk_function_as(struct kk_std_core_list_show_fun1626__t*, _fself, _ctx);
  kk_function_t _implicit_fs_show = _self->_implicit_fs_show; /* (3123) -> 3124 string */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_show, _ctx);}, {}, _ctx)
  kk_string_t _x_x1627 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_show, (_implicit_fs_show, _b_x655, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x1627);
}


// lift anonymous function
struct kk_std_core_list_show_fun1629__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_show_fun1629(kk_function_t _fself, kk_box_t _b_x659, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_show_fun1629(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_show_fun1629, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_show_fun1629(kk_function_t _fself, kk_box_t _b_x659, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t _x_x1630;
  kk_std_core_types__list _x_x1631 = kk_std_core_types__list_unbox(_b_x659, KK_OWNED, _ctx); /*list<string>*/
  _x_x1630 = kk_std_core_list__mlift_show_10705(_x_x1631, _ctx); /*string*/
  return kk_string_box(_x_x1630);
}

kk_string_t kk_std_core_list_show(kk_std_core_types__list xs, kk_function_t _implicit_fs_show, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, ?show : (a) -> e string) -> e string */ 
  kk_std_core_types__list x_10795;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(_implicit_fs_show, _ctx);
    x_10795 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
  }
  else {
    x_10795 = kk_std_core_list__unroll_map_10010(xs, kk_std_core_list_new_show_fun1626(_implicit_fs_show, _ctx), _ctx); /*list<string>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10795, _ctx);
    kk_box_t _x_x1628 = kk_std_core_hnd_yield_extend(kk_std_core_list_new_show_fun1629(_ctx), _ctx); /*2978*/
    return kk_string_unbox(_x_x1628);
  }
  {
    kk_string_t _x_x1632;
    kk_define_string_literal(, _s_x1633, 1, "[", _ctx)
    _x_x1632 = kk_string_dup(_s_x1633, _ctx); /*string*/
    kk_string_t _x_x1634;
    kk_string_t _x_x1635;
    if (kk_std_core_types__is_Nil(x_10795, _ctx)) {
      _x_x1635 = kk_string_empty(); /*string*/
      goto _match_x1636;
    }
    {
      struct kk_std_core_types_Cons* _con_x1638 = kk_std_core_types__as_Cons(x_10795, _ctx);
      kk_box_t _box_x660 = _con_x1638->head;
      kk_std_core_types__list _pat_1_0 = _con_x1638->tail;
      if (kk_std_core_types__is_Nil(_pat_1_0, _ctx)) {
        kk_string_t x_0 = kk_string_unbox(_box_x660);
        if kk_likely(kk_datatype_ptr_is_unique(x_10795, _ctx)) {
          kk_datatype_ptr_free(x_10795, _ctx);
        }
        else {
          kk_string_dup(x_0, _ctx);
          kk_datatype_ptr_decref(x_10795, _ctx);
        }
        _x_x1635 = x_0; /*string*/
        goto _match_x1636;
      }
    }
    if (kk_std_core_types__is_Cons(x_10795, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1639 = kk_std_core_types__as_Cons(x_10795, _ctx);
      kk_box_t _box_x661 = _con_x1639->head;
      kk_std_core_types__list _pat_3 = _con_x1639->tail;
      if (kk_std_core_types__is_Cons(_pat_3, _ctx)) {
        struct kk_std_core_types_Cons* _con_x1640 = kk_std_core_types__as_Cons(_pat_3, _ctx);
        kk_box_t _box_x662 = _con_x1640->head;
        kk_std_core_types__list _pat_4 = _con_x1640->tail;
        if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
          kk_string_t _x_x1641;
          kk_define_string_literal(, _s_x1642, 1, ",", _ctx)
          _x_x1641 = kk_string_dup(_s_x1642, _ctx); /*string*/
          kk_string_t _x_x1643 = kk_string_empty(); /*string*/
          if (kk_string_is_eq(_x_x1641,_x_x1643,kk_context())) {
            kk_string_t x_0_0 = kk_string_unbox(_box_x661);
            kk_string_t y = kk_string_unbox(_box_x662);
            if kk_likely(kk_datatype_ptr_is_unique(x_10795, _ctx)) {
              if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
                kk_datatype_ptr_free(_pat_3, _ctx);
              }
              else {
                kk_string_dup(y, _ctx);
                kk_datatype_ptr_decref(_pat_3, _ctx);
              }
              kk_datatype_ptr_free(x_10795, _ctx);
            }
            else {
              kk_string_dup(x_0_0, _ctx);
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(x_10795, _ctx);
            }
            _x_x1635 = kk_std_core_types__lp__plus__plus__rp_(x_0_0, y, _ctx); /*string*/
            goto _match_x1636;
          }
        }
      }
    }
    {
      kk_vector_t _x_x1645 = kk_std_core_vector_unvlist(x_10795, _ctx); /*vector<832>*/
      kk_string_t _x_x1646;
      kk_define_string_literal(, _s_x1647, 1, ",", _ctx)
      _x_x1646 = kk_string_dup(_s_x1647, _ctx); /*string*/
      _x_x1635 = kk_string_join_with(_x_x1645,_x_x1646,kk_context()); /*string*/
    }
    _match_x1636: ;
    kk_string_t _x_x1648;
    kk_define_string_literal(, _s_x1649, 1, "]", _ctx)
    _x_x1648 = kk_string_dup(_s_x1649, _ctx); /*string*/
    _x_x1634 = kk_std_core_types__lp__plus__plus__rp_(_x_x1635, _x_x1648, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x1632, _x_x1634, _ctx);
  }
}
 
// Zip two lists together by pairing the corresponding elements.
// The returned list is only as long as the smallest input list.

kk_std_core_types__list kk_std_core_list__trmc_unroll_zip_10019(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a,b> (xs : list<a>, ys : list<b>, ctx<list<(a, b)>>) -> list<(a, b)> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1650 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1650->head;
    kk_std_core_types__list xx = _con_x1650->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Cons(ys, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1651 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1651->head;
      kk_std_core_types__list yy = _con_x1651->tail;
      kk_reuse_t _ru_x1271 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        _ru_x1271 = (kk_datatype_ptr_reuse(ys, _ctx));
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      kk_std_core_types__list _trmc_x10420 = kk_datatype_null(); /*list<(3222, 3223)>*/;
      kk_std_core_types__list _trmc_x10421;
      kk_box_t _x_x1652;
      kk_std_core_types__tuple2 _x_x1653 = kk_std_core_types__new_Tuple2(x, y, _ctx); /*(129, 130)*/
      _x_x1652 = kk_std_core_types__tuple2_box(_x_x1653, _ctx); /*82*/
      _trmc_x10421 = kk_std_core_types__new_Cons(_ru_x1271, 0, _x_x1652, _trmc_x10420, _ctx); /*list<(3222, 3223)>*/
      kk_field_addr_t _b_x673_680 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10421, _ctx)->tail, _ctx); /*@field-addr<list<(3222, 3223)>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1654 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10421, _ctx)),_b_x673_680,kk_context()); /*ctx<0>*/
        xs = xx;
        ys = yy;
        _acc = _x_x1654;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(xx, _ctx);
      kk_box_drop(x, _ctx);
      kk_box_t _x_x1655 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1655, KK_OWNED, _ctx);
    }
  }
  {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_box_t _x_x1656 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1656, KK_OWNED, _ctx);
  }
}
 
// Zip two lists together by pairing the corresponding elements.
// The returned list is only as long as the smallest input list.

kk_std_core_types__list kk_std_core_list__unroll_zip_10019(kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a,b> (xs : list<a>, ys : list<b>) -> list<(a, b)> */ 
  kk_std_core_types__cctx _x_x1657 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_zip_10019(xs_0, ys_0, _x_x1657, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_zipwith_10020_10706(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list xx, kk_std_core_types__list yy, kk_box_t _trmc_x10422, kk_context_t* _ctx) { /* forall<a,b,c,e> (ctx<list<c>>, f : (a, b) -> e c, xx : list<a>, yy : list<b>, c) -> e list<c> */ 
  kk_std_core_types__list _trmc_x10423 = kk_datatype_null(); /*list<3290>*/;
  kk_std_core_types__list _trmc_x10424 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10422, _trmc_x10423, _ctx); /*list<3290>*/;
  kk_field_addr_t _b_x693_696 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10424, _ctx)->tail, _ctx); /*@field-addr<list<3290>>*/;
  kk_std_core_types__cctx _x_x1658 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10424, _ctx)),_b_x693_696,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_zipwith_10020(xx, yy, f, _x_x1658, _ctx);
}
 
// Zip two lists together by apply a function `f` to all corresponding elements.
// The returned list is only as long as the smallest input list.


// lift anonymous function
struct kk_std_core_list__trmc_unroll_zipwith_10020_fun1663__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list xx_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_zipwith_10020_fun1663(kk_function_t _fself, kk_box_t _b_x701, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_zipwith_10020_fun1663(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list xx_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_zipwith_10020_fun1663__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_zipwith_10020_fun1663__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_zipwith_10020_fun1663, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->xx_0 = xx_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_zipwith_10020_fun1663(kk_function_t _fself, kk_box_t _b_x701, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_zipwith_10020_fun1663__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_zipwith_10020_fun1663__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<3290>> */
  kk_function_t f_0 = _self->f_0; /* (3288, 3289) -> 3291 3290 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<3288> */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<3289> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10422_0_723 = _b_x701; /*3290*/;
  kk_std_core_types__list _x_x1664 = kk_std_core_list__mlift_trmc_unroll_zipwith_10020_10706(_acc_0, f_0, xx_0, yy_0, _trmc_x10422_0_723, _ctx); /*list<3290>*/
  return kk_std_core_types__list_box(_x_x1664, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_zipwith_10020(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c, ctx<list<c>>) -> e list<c> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1659 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1659->head;
    kk_std_core_types__list xx_0 = _con_x1659->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Cons(ys, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1660 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1660->head;
      kk_std_core_types__list yy_0 = _con_x1660->tail;
      kk_reuse_t _ru_x1273 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        _ru_x1273 = (kk_datatype_ptr_reuse(ys, _ctx));
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy_0, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      kk_box_t x_0_10798;
      kk_function_t _x_x1661 = kk_function_dup(f_0, _ctx); /*(3288, 3289) -> 3291 3290*/
      x_0_10798 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1661, (_x_x1661, x, y, _ctx), _ctx); /*3290*/
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_x1273,kk_context());
        kk_box_drop(x_0_10798, _ctx);
        kk_box_t _x_x1662 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_zipwith_10020_fun1663(_acc_0, f_0, xx_0, yy_0, _ctx), _ctx); /*2978*/
        return kk_std_core_types__list_unbox(_x_x1662, KK_OWNED, _ctx);
      }
      {
        kk_std_core_types__list _trmc_x10423_0 = kk_datatype_null(); /*list<3290>*/;
        kk_std_core_types__list _trmc_x10424_0 = kk_std_core_types__new_Cons(_ru_x1273, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0_10798, _trmc_x10423_0, _ctx); /*list<3290>*/;
        kk_field_addr_t _b_x707_715 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10424_0, _ctx)->tail, _ctx); /*@field-addr<list<3290>>*/;
        { // tailcall
          kk_std_core_types__cctx _x_x1665 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10424_0, _ctx)),_b_x707_715,kk_context()); /*ctx<0>*/
          xs = xx_0;
          ys = yy_0;
          _acc_0 = _x_x1665;
          goto kk__tailcall;
        }
      }
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_box_drop(x, _ctx);
      kk_function_drop(f_0, _ctx);
      kk_box_t _x_x1666 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1666, KK_OWNED, _ctx);
    }
  }
  {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1667 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1667, KK_OWNED, _ctx);
  }
}
 
// Zip two lists together by apply a function `f` to all corresponding elements.
// The returned list is only as long as the smallest input list.

kk_std_core_types__list kk_std_core_list__unroll_zipwith_10020(kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c) -> e list<c> */ 
  kk_std_core_types__cctx _x_x1668 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_zipwith_10020(xs_0, ys_0, f_1, _x_x1668, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_lift_zipwith_indexed_4953_10021_10707(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t i_0_10105, kk_std_core_types__list xx, kk_std_core_types__list yy, kk_box_t _trmc_x10425, kk_context_t* _ctx) { /* forall<a,b,c,e> (ctx<list<c>>, f : (int, a, b) -> e c, i@0@10105 : int, xx : list<a>, yy : list<b>, c) -> e list<c> */ 
  kk_std_core_types__list _trmc_x10426 = kk_datatype_null(); /*list<3373>*/;
  kk_std_core_types__list _trmc_x10427 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10425, _trmc_x10426, _ctx); /*list<3373>*/;
  kk_field_addr_t _b_x729_732 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10427, _ctx)->tail, _ctx); /*@field-addr<list<3373>>*/;
  kk_std_core_types__cctx _x_x1669 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10427, _ctx)),_b_x729_732,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_zipwith_indexed_4953_10021(f, i_0_10105, xx, yy, _x_x1669, _ctx);
}
 
// lifted local: zipwith-indexed, zipwith-iter


// lift anonymous function
struct kk_std_core_list__trmc_unroll_lift_zipwith_indexed_4953_10021_fun1675__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t i_0_10105_0;
  kk_std_core_types__list xx_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_lift_zipwith_indexed_4953_10021_fun1675(kk_function_t _fself, kk_box_t _b_x737, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_lift_zipwith_indexed_4953_10021_fun1675(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t i_0_10105_0, kk_std_core_types__list xx_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_zipwith_indexed_4953_10021_fun1675__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_lift_zipwith_indexed_4953_10021_fun1675__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_lift_zipwith_indexed_4953_10021_fun1675, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->i_0_10105_0 = i_0_10105_0;
  _self->xx_0 = xx_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_lift_zipwith_indexed_4953_10021_fun1675(kk_function_t _fself, kk_box_t _b_x737, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_zipwith_indexed_4953_10021_fun1675__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_lift_zipwith_indexed_4953_10021_fun1675__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<3373>> */
  kk_function_t f_0 = _self->f_0; /* (int, 3371, 3372) -> 3374 3373 */
  kk_integer_t i_0_10105_0 = _self->i_0_10105_0; /* int */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<3371> */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<3372> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(i_0_10105_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10425_0_759 = _b_x737; /*3373*/;
  kk_std_core_types__list _x_x1676 = kk_std_core_list__mlift_trmc_unroll_lift_zipwith_indexed_4953_10021_10707(_acc_0, f_0, i_0_10105_0, xx_0, yy_0, _trmc_x10425_0_759, _ctx); /*list<3373>*/
  return kk_std_core_types__list_box(_x_x1676, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_zipwith_indexed_4953_10021(kk_function_t f_0, kk_integer_t i, kk_std_core_types__list xs, kk_std_core_types__list ys, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xs : list<a>, ys : list<b>, ctx<list<c>>) -> e list<c> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1670 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1670->head;
    kk_std_core_types__list xx_0 = _con_x1670->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Cons(ys, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1671 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1671->head;
      kk_std_core_types__list yy_0 = _con_x1671->tail;
      kk_reuse_t _ru_x1275 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        _ru_x1275 = (kk_datatype_ptr_reuse(ys, _ctx));
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy_0, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      kk_integer_t i_0_10105_0;
      kk_integer_t _x_x1672 = kk_integer_dup(i, _ctx); /*int*/
      i_0_10105_0 = kk_integer_add_small_const(_x_x1672, 1, _ctx); /*int*/
      kk_box_t x_0_10801;
      kk_function_t _x_x1673 = kk_function_dup(f_0, _ctx); /*(int, 3371, 3372) -> 3374 3373*/
      x_0_10801 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1673, (_x_x1673, i, x, y, _ctx), _ctx); /*3373*/
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_x1275,kk_context());
        kk_box_drop(x_0_10801, _ctx);
        kk_box_t _x_x1674 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_lift_zipwith_indexed_4953_10021_fun1675(_acc_0, f_0, i_0_10105_0, xx_0, yy_0, _ctx), _ctx); /*2978*/
        return kk_std_core_types__list_unbox(_x_x1674, KK_OWNED, _ctx);
      }
      {
        kk_std_core_types__list _trmc_x10426_0 = kk_datatype_null(); /*list<3373>*/;
        kk_std_core_types__list _trmc_x10427_0 = kk_std_core_types__new_Cons(_ru_x1275, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0_10801, _trmc_x10426_0, _ctx); /*list<3373>*/;
        kk_field_addr_t _b_x743_751 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10427_0, _ctx)->tail, _ctx); /*@field-addr<list<3373>>*/;
        { // tailcall
          kk_std_core_types__cctx _x_x1677 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10427_0, _ctx)),_b_x743_751,kk_context()); /*ctx<0>*/
          i = i_0_10105_0;
          xs = xx_0;
          ys = yy_0;
          _acc_0 = _x_x1677;
          goto kk__tailcall;
        }
      }
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_box_drop(x, _ctx);
      kk_integer_drop(i, _ctx);
      kk_function_drop(f_0, _ctx);
      kk_box_t _x_x1678 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1678, KK_OWNED, _ctx);
    }
  }
  {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_integer_drop(i, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1679 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1679, KK_OWNED, _ctx);
  }
}
 
// lifted local: zipwith-indexed, zipwith-iter

kk_std_core_types__list kk_std_core_list__unroll_lift_zipwith_indexed_4953_10021(kk_function_t f_1, kk_integer_t i_0, kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xs : list<a>, ys : list<b>) -> e list<c> */ 
  kk_std_core_types__cctx _x_x1680 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_zipwith_indexed_4953_10021(f_1, i_0, xs_0, ys_0, _x_x1680, _ctx);
}
 
// lifted local: unzip, iter
// todo: implement TRMC for multiple results

kk_std_core_types__tuple2 kk_std_core_list__unroll_lift_unzip_4954_10022(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_context_t* _ctx) { /* forall<a,b,c,d> (ys : list<(a, b)>, acc1 : cctx<c,list<a>>, acc2 : cctx<d,list<b>>) -> (c, d) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1681 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t _box_x760 = _con_x1681->head;
    kk_std_core_types__tuple2 _pat_0 = kk_std_core_types__tuple2_unbox(_box_x760, KK_BORROWED, _ctx);
    kk_std_core_types__list xx = _con_x1681->tail;
    kk_box_t x = _pat_0.fst;
    kk_box_t y = _pat_0.snd;
    kk_reuse_t _ru_x1276 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      kk_box_dup(x, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_drop(_box_x760, _ctx);
      _ru_x1276 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_box_dup(y, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _cctx_x3433;
    kk_std_core_types__list _x_x1682 = kk_datatype_null(); /*list<3402>*/
    _cctx_x3433 = kk_std_core_types__new_Cons(_ru_x1276, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1682, _ctx); /*list<3402>*/
    kk_field_addr_t _cctx_x3434 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3433, _ctx)->tail, _ctx); /*@field-addr<list<3402>>*/;
    kk_std_core_types__list _cctx_x3473;
    kk_std_core_types__list _x_x1683 = kk_datatype_null(); /*list<3403>*/
    _cctx_x3473 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _x_x1683, _ctx); /*list<3403>*/
    kk_field_addr_t _cctx_x3474 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3473, _ctx)->tail, _ctx); /*@field-addr<list<3403>>*/;
    kk_std_core_types__list _b_x773_781 = _cctx_x3433; /*list<3402>*/;
    kk_field_addr_t _b_x774_782 = _cctx_x3434; /*@field-addr<list<3402>>*/;
    kk_std_core_types__list _b_x775_783 = _cctx_x3473; /*list<3403>*/;
    kk_field_addr_t _b_x776_784 = _cctx_x3474; /*@field-addr<list<3403>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1684;
      kk_std_core_types__cctx _x_x1685 = kk_cctx_create((kk_std_core_types__list_box(_b_x773_781, _ctx)),_b_x774_782,kk_context()); /*cctx<0,1>*/
      _x_x1684 = kk_cctx_compose(acc1,_x_x1685,kk_context()); /*cctx<371,373>*/
      kk_std_core_types__cctx _x_x1686;
      kk_std_core_types__cctx _x_x1687 = kk_cctx_create((kk_std_core_types__list_box(_b_x775_783, _ctx)),_b_x776_784,kk_context()); /*cctx<0,1>*/
      _x_x1686 = kk_cctx_compose(acc2,_x_x1687,kk_context()); /*cctx<371,373>*/
      ys = xx;
      acc1 = _x_x1684;
      acc2 = _x_x1686;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1688 = kk_cctx_apply(acc1,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1689 = kk_cctx_apply(acc2,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    return kk_std_core_types__new_Tuple2(_x_x1688, _x_x1689, _ctx);
  }
}
 
// Unzip a list of pairs into two lists

kk_std_core_types__tuple2 kk_std_core_list_unzip(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a,b> (xs : list<(a, b)>) -> (list<a>, list<b>) */ 
  kk_std_core_types__cctx acc1_10160 = kk_cctx_empty(kk_context()); /*ctx<list<3565>>*/;
  kk_std_core_types__cctx acc2_10161 = kk_cctx_empty(kk_context()); /*ctx<list<3566>>*/;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list _b_x801_803;
    kk_box_t _x_x1692 = kk_cctx_apply(acc1_10160,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    _b_x801_803 = kk_std_core_types__list_unbox(_x_x1692, KK_OWNED, _ctx); /*list<3565>*/
    kk_std_core_types__list _b_x802_804;
    kk_box_t _x_x1693 = kk_cctx_apply(acc2_10161,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    _b_x802_804 = kk_std_core_types__list_unbox(_x_x1693, KK_OWNED, _ctx); /*list<3566>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x801_803, _ctx), kk_std_core_types__list_box(_b_x802_804, _ctx), _ctx);
  }
  {
    return kk_std_core_list__unroll_lift_unzip_4954_10022(xs, acc1_10160, acc2_10161, _ctx);
  }
}
 
// lifted local: unzip3, iter
// todo: implement TRMC for multiple results

kk_std_core_types__tuple3 kk_std_core_list__unroll_lift_unzip3_4955_10023(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_std_core_types__cctx acc3, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,b1> (ys : list<(a, b, c)>, acc1 : cctx<d,list<a>>, acc2 : cctx<a1,list<b>>, acc3 : cctx<b1,list<c>>) -> (d, a1, b1) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1694 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t _box_x809 = _con_x1694->head;
    kk_std_core_types__tuple3 _pat_0 = kk_std_core_types__tuple3_unbox(_box_x809, KK_BORROWED, _ctx);
    kk_std_core_types__list xx = _con_x1694->tail;
    kk_box_t x = _pat_0.fst;
    kk_box_t y = _pat_0.snd;
    kk_box_t z = _pat_0.thd;
    kk_reuse_t _ru_x1277 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      kk_box_dup(x, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_dup(z, _ctx);
      kk_box_drop(_box_x809, _ctx);
      _ru_x1277 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_dup(z, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _cctx_x3624;
    kk_std_core_types__list _x_x1695 = kk_datatype_null(); /*list<3592>*/
    _cctx_x3624 = kk_std_core_types__new_Cons(_ru_x1277, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1695, _ctx); /*list<3592>*/
    kk_field_addr_t _cctx_x3625 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3624, _ctx)->tail, _ctx); /*@field-addr<list<3592>>*/;
    kk_std_core_types__list _cctx_x3664;
    kk_std_core_types__list _x_x1696 = kk_datatype_null(); /*list<3593>*/
    _cctx_x3664 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _x_x1696, _ctx); /*list<3593>*/
    kk_field_addr_t _cctx_x3665 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3664, _ctx)->tail, _ctx); /*@field-addr<list<3593>>*/;
    kk_std_core_types__list _cctx_x3704;
    kk_std_core_types__list _x_x1697 = kk_datatype_null(); /*list<3594>*/
    _cctx_x3704 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), z, _x_x1697, _ctx); /*list<3594>*/
    kk_field_addr_t _cctx_x3705 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3704, _ctx)->tail, _ctx); /*@field-addr<list<3594>>*/;
    kk_std_core_types__list _b_x828_840 = _cctx_x3624; /*list<3592>*/;
    kk_field_addr_t _b_x829_841 = _cctx_x3625; /*@field-addr<list<3592>>*/;
    kk_std_core_types__list _b_x830_842 = _cctx_x3664; /*list<3593>*/;
    kk_field_addr_t _b_x831_843 = _cctx_x3665; /*@field-addr<list<3593>>*/;
    kk_std_core_types__list _b_x832_844 = _cctx_x3704; /*list<3594>*/;
    kk_field_addr_t _b_x833_845 = _cctx_x3705; /*@field-addr<list<3594>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1698;
      kk_std_core_types__cctx _x_x1699 = kk_cctx_create((kk_std_core_types__list_box(_b_x828_840, _ctx)),_b_x829_841,kk_context()); /*cctx<0,1>*/
      _x_x1698 = kk_cctx_compose(acc1,_x_x1699,kk_context()); /*cctx<371,373>*/
      kk_std_core_types__cctx _x_x1700;
      kk_std_core_types__cctx _x_x1701 = kk_cctx_create((kk_std_core_types__list_box(_b_x830_842, _ctx)),_b_x831_843,kk_context()); /*cctx<0,1>*/
      _x_x1700 = kk_cctx_compose(acc2,_x_x1701,kk_context()); /*cctx<371,373>*/
      kk_std_core_types__cctx _x_x1702;
      kk_std_core_types__cctx _x_x1703 = kk_cctx_create((kk_std_core_types__list_box(_b_x832_844, _ctx)),_b_x833_845,kk_context()); /*cctx<0,1>*/
      _x_x1702 = kk_cctx_compose(acc3,_x_x1703,kk_context()); /*cctx<371,373>*/
      ys = xx;
      acc1 = _x_x1698;
      acc2 = _x_x1700;
      acc3 = _x_x1702;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1704 = kk_cctx_apply(acc1,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1705 = kk_cctx_apply(acc2,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1706 = kk_cctx_apply(acc3,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    return kk_std_core_types__new_Tuple3(_x_x1704, _x_x1705, _x_x1706, _ctx);
  }
}
 
// Unzip a list of triples into three lists

kk_std_core_types__tuple3 kk_std_core_list_unzip3(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a,b,c> (xs : list<(a, b, c)>) -> (list<a>, list<b>, list<c>) */ 
  kk_std_core_types__cctx acc1_10163 = kk_cctx_empty(kk_context()); /*ctx<list<3828>>*/;
  kk_std_core_types__cctx acc2_10164 = kk_cctx_empty(kk_context()); /*ctx<list<3829>>*/;
  kk_std_core_types__cctx acc3_10165 = kk_cctx_empty(kk_context()); /*ctx<list<3830>>*/;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list _b_x870_873;
    kk_box_t _x_x1710 = kk_cctx_apply(acc1_10163,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    _b_x870_873 = kk_std_core_types__list_unbox(_x_x1710, KK_OWNED, _ctx); /*list<3828>*/
    kk_std_core_types__list _b_x871_874;
    kk_box_t _x_x1711 = kk_cctx_apply(acc2_10164,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    _b_x871_874 = kk_std_core_types__list_unbox(_x_x1711, KK_OWNED, _ctx); /*list<3829>*/
    kk_std_core_types__list _b_x872_875;
    kk_box_t _x_x1712 = kk_cctx_apply(acc3_10165,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    _b_x872_875 = kk_std_core_types__list_unbox(_x_x1712, KK_OWNED, _ctx); /*list<3830>*/
    return kk_std_core_types__new_Tuple3(kk_std_core_types__list_box(_b_x870_873, _ctx), kk_std_core_types__list_box(_b_x871_874, _ctx), kk_std_core_types__list_box(_b_x872_875, _ctx), _ctx);
  }
  {
    return kk_std_core_list__unroll_lift_unzip3_4955_10023(xs, acc1_10163, acc2_10164, acc3_10165, _ctx);
  }
}
 
// lifted local: unzip4, iter
// todo: implement TRMC for multiple results

kk_std_core_types__tuple4 kk_std_core_list__unroll_lift_unzip4_4956_10024(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_std_core_types__cctx acc3, kk_std_core_types__cctx acc4, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,b1,c1,d1> (ys : list<(a, b, c, d)>, acc1 : cctx<a1,list<a>>, acc2 : cctx<b1,list<b>>, acc3 : cctx<c1,list<c>>, acc4 : cctx<d1,list<d>>) -> (a1, b1, c1, d1) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1713 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t _box_x882 = _con_x1713->head;
    kk_std_core_types__tuple4 _pat_0 = kk_std_core_types__tuple4_unbox(_box_x882, KK_BORROWED, _ctx);
    struct kk_std_core_types_Tuple4* _con_x1714 = kk_std_core_types__as_Tuple4(_pat_0, _ctx);
    kk_std_core_types__list xx = _con_x1713->tail;
    kk_box_t x = _con_x1714->fst;
    kk_box_t y = _con_x1714->snd;
    kk_box_t z = _con_x1714->thd;
    kk_box_t w = _con_x1714->field4;
    kk_reuse_t _ru_x1278 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      kk_box_dup(w, _ctx);
      kk_box_dup(x, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_dup(z, _ctx);
      kk_box_drop(_box_x882, _ctx);
      _ru_x1278 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(w, _ctx);
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_dup(z, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _cctx_x3895;
    kk_std_core_types__list _x_x1715 = kk_datatype_null(); /*list<3862>*/
    _cctx_x3895 = kk_std_core_types__new_Cons(_ru_x1278, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1715, _ctx); /*list<3862>*/
    kk_field_addr_t _cctx_x3896 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3895, _ctx)->tail, _ctx); /*@field-addr<list<3862>>*/;
    kk_std_core_types__list _cctx_x3935;
    kk_std_core_types__list _x_x1716 = kk_datatype_null(); /*list<3863>*/
    _cctx_x3935 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _x_x1716, _ctx); /*list<3863>*/
    kk_field_addr_t _cctx_x3936 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3935, _ctx)->tail, _ctx); /*@field-addr<list<3863>>*/;
    kk_std_core_types__list _cctx_x3975;
    kk_std_core_types__list _x_x1717 = kk_datatype_null(); /*list<3864>*/
    _cctx_x3975 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), z, _x_x1717, _ctx); /*list<3864>*/
    kk_field_addr_t _cctx_x3976 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x3975, _ctx)->tail, _ctx); /*@field-addr<list<3864>>*/;
    kk_std_core_types__list _cctx_x4015;
    kk_std_core_types__list _x_x1718 = kk_datatype_null(); /*list<3865>*/
    _cctx_x4015 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), w, _x_x1718, _ctx); /*list<3865>*/
    kk_field_addr_t _cctx_x4016 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4015, _ctx)->tail, _ctx); /*@field-addr<list<3865>>*/;
    kk_std_core_types__list _b_x907_923 = _cctx_x3895; /*list<3862>*/;
    kk_field_addr_t _b_x908_924 = _cctx_x3896; /*@field-addr<list<3862>>*/;
    kk_std_core_types__list _b_x909_925 = _cctx_x3935; /*list<3863>*/;
    kk_field_addr_t _b_x910_926 = _cctx_x3936; /*@field-addr<list<3863>>*/;
    kk_std_core_types__list _b_x911_927 = _cctx_x3975; /*list<3864>*/;
    kk_field_addr_t _b_x912_928 = _cctx_x3976; /*@field-addr<list<3864>>*/;
    kk_std_core_types__list _b_x913_929 = _cctx_x4015; /*list<3865>*/;
    kk_field_addr_t _b_x914_930 = _cctx_x4016; /*@field-addr<list<3865>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1719;
      kk_std_core_types__cctx _x_x1720 = kk_cctx_create((kk_std_core_types__list_box(_b_x907_923, _ctx)),_b_x908_924,kk_context()); /*cctx<0,1>*/
      _x_x1719 = kk_cctx_compose(acc1,_x_x1720,kk_context()); /*cctx<371,373>*/
      kk_std_core_types__cctx _x_x1721;
      kk_std_core_types__cctx _x_x1722 = kk_cctx_create((kk_std_core_types__list_box(_b_x909_925, _ctx)),_b_x910_926,kk_context()); /*cctx<0,1>*/
      _x_x1721 = kk_cctx_compose(acc2,_x_x1722,kk_context()); /*cctx<371,373>*/
      kk_std_core_types__cctx _x_x1723;
      kk_std_core_types__cctx _x_x1724 = kk_cctx_create((kk_std_core_types__list_box(_b_x911_927, _ctx)),_b_x912_928,kk_context()); /*cctx<0,1>*/
      _x_x1723 = kk_cctx_compose(acc3,_x_x1724,kk_context()); /*cctx<371,373>*/
      kk_std_core_types__cctx _x_x1725;
      kk_std_core_types__cctx _x_x1726 = kk_cctx_create((kk_std_core_types__list_box(_b_x913_929, _ctx)),_b_x914_930,kk_context()); /*cctx<0,1>*/
      _x_x1725 = kk_cctx_compose(acc4,_x_x1726,kk_context()); /*cctx<371,373>*/
      ys = xx;
      acc1 = _x_x1719;
      acc2 = _x_x1721;
      acc3 = _x_x1723;
      acc4 = _x_x1725;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1727 = kk_cctx_apply(acc1,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1728 = kk_cctx_apply(acc2,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1729 = kk_cctx_apply(acc3,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    kk_box_t _x_x1730 = kk_cctx_apply(acc4,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    return kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _x_x1727, _x_x1728, _x_x1729, _x_x1730, _ctx);
  }
}
 
// Unzip a list of quadruples into four lists

kk_std_core_types__tuple4 kk_std_core_list_unzip4(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a,b,c,d> (xs : list<(a, b, c, d)>) -> (list<a>, list<b>, list<c>, list<d>) */ 
  kk_std_core_types__cctx acc1_10167 = kk_cctx_empty(kk_context()); /*ctx<list<4171>>*/;
  kk_std_core_types__cctx acc2_10168 = kk_cctx_empty(kk_context()); /*ctx<list<4172>>*/;
  kk_std_core_types__cctx acc3_10169 = kk_cctx_empty(kk_context()); /*ctx<list<4173>>*/;
  kk_std_core_types__cctx acc4_10170 = kk_cctx_empty(kk_context()); /*ctx<list<4174>>*/;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list _b_x963_967;
    kk_box_t _x_x1735 = kk_cctx_apply(acc1_10167,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    _b_x963_967 = kk_std_core_types__list_unbox(_x_x1735, KK_OWNED, _ctx); /*list<4171>*/
    kk_std_core_types__list _b_x964_968;
    kk_box_t _x_x1736 = kk_cctx_apply(acc2_10168,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    _b_x964_968 = kk_std_core_types__list_unbox(_x_x1736, KK_OWNED, _ctx); /*list<4172>*/
    kk_std_core_types__list _b_x965_969;
    kk_box_t _x_x1737 = kk_cctx_apply(acc3_10169,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    _b_x965_969 = kk_std_core_types__list_unbox(_x_x1737, KK_OWNED, _ctx); /*list<4173>*/
    kk_std_core_types__list _b_x966_970;
    kk_box_t _x_x1738 = kk_cctx_apply(acc4_10170,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*359*/
    _b_x966_970 = kk_std_core_types__list_unbox(_x_x1738, KK_OWNED, _ctx); /*list<4174>*/
    return kk_std_core_types__new_Tuple4(kk_reuse_null, 0, kk_std_core_types__list_box(_b_x963_967, _ctx), kk_std_core_types__list_box(_b_x964_968, _ctx), kk_std_core_types__list_box(_b_x965_969, _ctx), kk_std_core_types__list_box(_b_x966_970, _ctx), _ctx);
  }
  {
    return kk_std_core_list__unroll_lift_unzip4_4956_10024(xs, acc1_10167, acc2_10168, acc3_10169, acc4_10170, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__tuple2 kk_std_core_list__mlift_unroll_lift_span_4957_10025_10708(kk_std_core_types__list acc, kk_function_t predicate, kk_box_t y, kk_std_core_types__list ys, kk_std_core_types__list yy, bool _y_x10609, kk_context_t* _ctx) { /* forall<a,e> (acc : list<a>, predicate : (a) -> e bool, y : a, ys : list<a>, yy : list<a>, bool) -> e (list<a>, list<a>) */ 
  if (_y_x10609) {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_std_core_types__list _x_x1739 = kk_std_core_types__new_Cons(kk_reuse_null, 0, y, acc, _ctx); /*list<82>*/
    return kk_std_core_list__unroll_lift_span_4957_10025(predicate, yy, _x_x1739, _ctx);
  }
  {
    kk_std_core_types__list_drop(yy, _ctx);
    kk_box_drop(y, _ctx);
    kk_function_drop(predicate, _ctx);
    kk_std_core_types__list _b_x979_981;
    if (kk_std_core_types__is_Nil(acc, _ctx)) {
      _b_x979_981 = kk_std_core_types__new_Nil(_ctx); /*list<4264>*/
    }
    else {
      _b_x979_981 = kk_std_core_list__unroll_lift_reverse_append_4948_10003(kk_std_core_types__new_Nil(_ctx), acc, _ctx); /*list<4264>*/
    }
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x979_981, _ctx), kk_std_core_types__list_box(ys, _ctx), _ctx);
  }
}
 
// lifted local: span, span-acc
// todo: implement TRMC with multiple results to avoid the reverse


// lift anonymous function
struct kk_std_core_list__unroll_lift_span_4957_10025_fun1744__t {
  struct kk_function_s _base;
  kk_std_core_types__list acc_0;
  kk_function_t predicate_0;
  kk_box_t y_0;
  kk_std_core_types__list ys_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__unroll_lift_span_4957_10025_fun1744(kk_function_t _fself, kk_box_t _b_x984, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_lift_span_4957_10025_fun1744(kk_std_core_types__list acc_0, kk_function_t predicate_0, kk_box_t y_0, kk_std_core_types__list ys_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_lift_span_4957_10025_fun1744__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_lift_span_4957_10025_fun1744__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_lift_span_4957_10025_fun1744, kk_context());
  _self->acc_0 = acc_0;
  _self->predicate_0 = predicate_0;
  _self->y_0 = y_0;
  _self->ys_0 = ys_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_lift_span_4957_10025_fun1744(kk_function_t _fself, kk_box_t _b_x984, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_lift_span_4957_10025_fun1744__t* _self = kk_function_as(struct kk_std_core_list__unroll_lift_span_4957_10025_fun1744__t*, _fself, _ctx);
  kk_std_core_types__list acc_0 = _self->acc_0; /* list<4264> */
  kk_function_t predicate_0 = _self->predicate_0; /* (4264) -> 4265 bool */
  kk_box_t y_0 = _self->y_0; /* 4264 */
  kk_std_core_types__list ys_0 = _self->ys_0; /* list<4264> */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<4264> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(acc_0, _ctx);kk_function_dup(predicate_0, _ctx);kk_box_dup(y_0, _ctx);kk_std_core_types__list_dup(ys_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  bool _y_x10609_0_994 = kk_bool_unbox(_b_x984); /*bool*/;
  kk_std_core_types__tuple2 _x_x1745 = kk_std_core_list__mlift_unroll_lift_span_4957_10025_10708(acc_0, predicate_0, y_0, ys_0, yy_0, _y_x10609_0_994, _ctx); /*(list<4264>, list<4264>)*/
  return kk_std_core_types__tuple2_box(_x_x1745, _ctx);
}

kk_std_core_types__tuple2 kk_std_core_list__unroll_lift_span_4957_10025(kk_function_t predicate_0, kk_std_core_types__list ys_0, kk_std_core_types__list acc_0, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, ys : list<a>, acc : list<a>) -> e (list<a>, list<a>) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys_0, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1740 = kk_std_core_types__as_Cons(ys_0, _ctx);
    kk_box_t y_0 = _con_x1740->head;
    kk_std_core_types__list yy_0 = _con_x1740->tail;
    kk_box_dup(y_0, _ctx);
    kk_std_core_types__list_dup(yy_0, _ctx);
    bool x_10804;
    kk_function_t _x_x1742 = kk_function_dup(predicate_0, _ctx); /*(4264) -> 4265 bool*/
    kk_box_t _x_x1741 = kk_box_dup(y_0, _ctx); /*4264*/
    x_10804 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1742, (_x_x1742, _x_x1741, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1743 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_lift_span_4957_10025_fun1744(acc_0, predicate_0, y_0, ys_0, yy_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__tuple2_unbox(_x_x1743, KK_OWNED, _ctx);
    }
    if (x_10804) {
      kk_reuse_t _ru_x1279 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(ys_0, _ctx)) {
        kk_std_core_types__list_drop(yy_0, _ctx);
        kk_box_drop(y_0, _ctx);
        _ru_x1279 = (kk_datatype_ptr_reuse(ys_0, _ctx));
      }
      else {
        kk_datatype_ptr_decref(ys_0, _ctx);
      }
      { // tailcall
        kk_std_core_types__list _x_x1746 = kk_std_core_types__new_Cons(_ru_x1279, 0, y_0, acc_0, _ctx); /*list<82>*/
        ys_0 = yy_0;
        acc_0 = _x_x1746;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(yy_0, _ctx);
      kk_box_drop(y_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      kk_std_core_types__list _b_x985_990;
      if (kk_std_core_types__is_Nil(acc_0, _ctx)) {
        _b_x985_990 = kk_std_core_types__new_Nil(_ctx); /*list<4264>*/
      }
      else {
        _b_x985_990 = kk_std_core_list__unroll_lift_reverse_append_4948_10003(kk_std_core_types__new_Nil(_ctx), acc_0, _ctx); /*list<4264>*/
      }
      return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x985_990, _ctx), kk_std_core_types__list_box(ys_0, _ctx), _ctx);
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    kk_std_core_types__list _b_x987_992;
    if (kk_std_core_types__is_Nil(acc_0, _ctx)) {
      _b_x987_992 = kk_std_core_types__new_Nil(_ctx); /*list<4264>*/
    }
    else {
      _b_x987_992 = kk_std_core_list__unroll_lift_reverse_append_4948_10003(kk_std_core_types__new_Nil(_ctx), acc_0, _ctx); /*list<4264>*/
    }
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x987_992, _ctx), kk_std_core_types__list_box(ys_0, _ctx), _ctx);
  }
}

kk_std_core_types__tuple2 kk_std_core_list_span(kk_std_core_types__list xs, kk_function_t predicate, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e (list<a>, list<a>) */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(predicate, _ctx);
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx), kk_std_core_types__list_box(xs, _ctx), _ctx);
  }
  {
    return kk_std_core_list__unroll_lift_span_4957_10025(predicate, xs, kk_std_core_types__new_Nil(_ctx), _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_take_while_10026_10709(kk_std_core_types__cctx _acc, kk_function_t predicate, kk_box_t x, kk_std_core_types__list xx, bool _y_x10617, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, predicate : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 
  if (_y_x10617) {
    kk_std_core_types__list _trmc_x10428 = kk_datatype_null(); /*list<4313>*/;
    kk_std_core_types__list _trmc_x10429 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _trmc_x10428, _ctx); /*list<4313>*/;
    kk_field_addr_t _b_x1008_1013 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10429, _ctx)->tail, _ctx); /*@field-addr<list<4313>>*/;
    kk_std_core_types__cctx _x_x1747 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10429, _ctx)),_b_x1008_1013,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_unroll_take_while_10026(xx, predicate, _x_x1747, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_box_drop(x, _ctx);
    kk_function_drop(predicate, _ctx);
    kk_box_t _x_x1748 = kk_cctx_apply(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1748, KK_OWNED, _ctx);
  }
}
 
// Keep only those initial elements that satisfy `predicate`


// lift anonymous function
struct kk_std_core_list__trmc_unroll_take_while_10026_fun1753__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t predicate_0;
  kk_box_t x_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_take_while_10026_fun1753(kk_function_t _fself, kk_box_t _b_x1020, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_take_while_10026_fun1753(kk_std_core_types__cctx _acc_0, kk_function_t predicate_0, kk_box_t x_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_take_while_10026_fun1753__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_take_while_10026_fun1753__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_take_while_10026_fun1753, kk_context());
  _self->_acc_0 = _acc_0;
  _self->predicate_0 = predicate_0;
  _self->x_0 = x_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_take_while_10026_fun1753(kk_function_t _fself, kk_box_t _b_x1020, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_take_while_10026_fun1753__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_take_while_10026_fun1753__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<4313>> */
  kk_function_t predicate_0 = _self->predicate_0; /* (4313) -> 4314 bool */
  kk_box_t x_0 = _self->x_0; /* 4313 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<4313> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(predicate_0, _ctx);kk_box_dup(x_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10617_0_1042 = kk_bool_unbox(_b_x1020); /*bool*/;
  kk_std_core_types__list _x_x1754 = kk_std_core_list__mlift_trmc_unroll_take_while_10026_10709(_acc_0, predicate_0, x_0, xx_0, _y_x10617_0_1042, _ctx); /*list<4313>*/
  return kk_std_core_types__list_box(_x_x1754, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_take_while_10026(kk_std_core_types__list xs, kk_function_t predicate_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1749 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x_0 = _con_x1749->head;
    kk_std_core_types__list xx_0 = _con_x1749->tail;
    kk_reuse_t _ru_x1280 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1280 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x_0, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_1_10807;
    kk_function_t _x_x1751 = kk_function_dup(predicate_0, _ctx); /*(4313) -> 4314 bool*/
    kk_box_t _x_x1750 = kk_box_dup(x_0, _ctx); /*4313*/
    x_1_10807 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1751, (_x_x1751, _x_x1750, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1280,kk_context());
      kk_box_t _x_x1752 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_take_while_10026_fun1753(_acc_0, predicate_0, x_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1752, KK_OWNED, _ctx);
    }
    if (x_1_10807) {
      kk_std_core_types__list _trmc_x10428_0 = kk_datatype_null(); /*list<4313>*/;
      kk_std_core_types__list _trmc_x10429_0 = kk_std_core_types__new_Cons(_ru_x1280, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0, _trmc_x10428_0, _ctx); /*list<4313>*/;
      kk_field_addr_t _b_x1026_1034 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10429_0, _ctx)->tail, _ctx); /*@field-addr<list<4313>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1755 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10429_0, _ctx)),_b_x1026_1034,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1755;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1280,kk_context());
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_box_drop(x_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      kk_box_t _x_x1756 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1756, KK_OWNED, _ctx);
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    kk_box_t _x_x1757 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1757, KK_OWNED, _ctx);
  }
}
 
// Keep only those initial elements that satisfy `predicate`

kk_std_core_types__list kk_std_core_list__unroll_take_while_10026(kk_std_core_types__list xs_0, kk_function_t predicate_1, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1758 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_take_while_10026(xs_0, predicate_1, _x_x1758, _ctx);
}
 
// Concatenate all strings in a list in reverse order

kk_string_t kk_std_core_list_reverse_join(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<string>) -> string */ 
  kk_std_core_types__list xs_0_10125;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    xs_0_10125 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
  }
  else {
    xs_0_10125 = kk_std_core_list__unroll_lift_reverse_append_4948_10003(kk_std_core_types__new_Nil(_ctx), xs, _ctx); /*list<string>*/
  }
  if (kk_std_core_types__is_Nil(xs_0_10125, _ctx)) {
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x1760 = kk_std_core_types__as_Cons(xs_0_10125, _ctx);
    kk_box_t _box_x1043 = _con_x1760->head;
    kk_std_core_types__list _pat_1_0 = _con_x1760->tail;
    if (kk_std_core_types__is_Nil(_pat_1_0, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x1043);
      if kk_likely(kk_datatype_ptr_is_unique(xs_0_10125, _ctx)) {
        kk_datatype_ptr_free(xs_0_10125, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs_0_10125, _ctx);
      }
      return x;
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x1761 = kk_std_core_types__as_Cons(xs_0_10125, _ctx);
    kk_box_t _box_x1044 = _con_x1761->head;
    kk_std_core_types__list _pat_3 = _con_x1761->tail;
    struct kk_std_core_types_Cons* _con_x1762 = kk_std_core_types__as_Cons(_pat_3, _ctx);
    kk_box_t _box_x1045 = _con_x1762->head;
    kk_std_core_types__list _pat_4 = _con_x1762->tail;
    if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
      kk_string_t x_0 = kk_string_unbox(_box_x1044);
      kk_string_t y = kk_string_unbox(_box_x1045);
      if kk_likely(kk_datatype_ptr_is_unique(xs_0_10125, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
          kk_datatype_ptr_free(_pat_3, _ctx);
        }
        else {
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(_pat_3, _ctx);
        }
        kk_datatype_ptr_free(xs_0_10125, _ctx);
      }
      else {
        kk_string_dup(x_0, _ctx);
        kk_string_dup(y, _ctx);
        kk_datatype_ptr_decref(xs_0_10125, _ctx);
      }
      return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
    }
  }
  {
    kk_vector_t _x_x1763 = kk_std_core_vector_unvlist(xs_0_10125, _ctx); /*vector<832>*/
    return kk_string_join(_x_x1763,kk_context());
  }
}
 
// lifted local: concat, concat-pre

kk_std_core_types__list kk_std_core_list__trmc_lift_concat_4958(kk_std_core_types__list ys, kk_std_core_types__list zss, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, zss : list<list<a>>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1767 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1767->head;
    kk_std_core_types__list yy = _con_x1767->tail;
    kk_reuse_t _ru_x1284 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1284 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _trmc_x10430 = kk_datatype_null(); /*list<4411>*/;
    kk_std_core_types__list _trmc_x10431 = kk_std_core_types__new_Cons(_ru_x1284, 0, y, _trmc_x10430, _ctx); /*list<4411>*/;
    kk_field_addr_t _b_x1051_1057 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10431, _ctx)->tail, _ctx); /*@field-addr<list<4411>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1768 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10431, _ctx)),_b_x1051_1057,kk_context()); /*ctx<0>*/
      ys = yy;
      _acc = _x_x1768;
      goto kk__tailcall;
    }
  }
  if (kk_std_core_types__is_Cons(zss, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1769 = kk_std_core_types__as_Cons(zss, _ctx);
    kk_box_t _box_x1052 = _con_x1769->head;
    kk_std_core_types__list zzs = _con_x1769->tail;
    kk_std_core_types__list zs = kk_std_core_types__list_unbox(_box_x1052, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(zss, _ctx)) {
      kk_datatype_ptr_free(zss, _ctx);
    }
    else {
      kk_std_core_types__list_dup(zs, _ctx);
      kk_std_core_types__list_dup(zzs, _ctx);
      kk_datatype_ptr_decref(zss, _ctx);
    }
    { // tailcall
      ys = zs;
      zss = zzs;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1770 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1770, KK_OWNED, _ctx);
  }
}
 
// lifted local: concat, concat-pre

kk_std_core_types__list kk_std_core_list__lift_concat_4958(kk_std_core_types__list ys_0, kk_std_core_types__list zss_0, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, zss : list<list<a>>) -> list<a> */ 
  kk_std_core_types__cctx _x_x1771 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_concat_4958(ys_0, zss_0, _x_x1771, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_lift_flatmap_4959_10710(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list zz, kk_std_core_types__list ys_1_10132, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e list<b>, zz : list<a>, ys@1@10132 : list<b>) -> e list<b> */ 
  return kk_std_core_list__trmc_lift_flatmap_4959(f, ys_1_10132, zz, _acc, _ctx);
}
 
// lifted local: flatmap, flatmap-pre


// lift anonymous function
struct kk_std_core_list__trmc_lift_flatmap_4959_fun1777__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list zz_0;
};
static kk_box_t kk_std_core_list__trmc_lift_flatmap_4959_fun1777(kk_function_t _fself, kk_box_t _b_x1070, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_lift_flatmap_4959_fun1777(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list zz_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_flatmap_4959_fun1777__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_lift_flatmap_4959_fun1777__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_lift_flatmap_4959_fun1777, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->zz_0 = zz_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_lift_flatmap_4959_fun1777(kk_function_t _fself, kk_box_t _b_x1070, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_flatmap_4959_fun1777__t* _self = kk_function_as(struct kk_std_core_list__trmc_lift_flatmap_4959_fun1777__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<4487>> */
  kk_function_t f_0 = _self->f_0; /* (4486) -> 4488 list<4487> */
  kk_std_core_types__list zz_0 = _self->zz_0; /* list<4486> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(zz_0, _ctx);}, {}, _ctx)
  kk_std_core_types__list ys_1_10132_0_1082 = kk_std_core_types__list_unbox(_b_x1070, KK_OWNED, _ctx); /*list<4487>*/;
  kk_std_core_types__list _x_x1778 = kk_std_core_list__mlift_trmc_lift_flatmap_4959_10710(_acc_0, f_0, zz_0, ys_1_10132_0_1082, _ctx); /*list<4487>*/
  return kk_std_core_types__list_box(_x_x1778, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_lift_flatmap_4959(kk_function_t f_0, kk_std_core_types__list ys, kk_std_core_types__list zs, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1772 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1772->head;
    kk_std_core_types__list yy = _con_x1772->tail;
    kk_reuse_t _ru_x1286 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1286 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _trmc_x10432 = kk_datatype_null(); /*list<4487>*/;
    kk_std_core_types__list _trmc_x10433 = kk_std_core_types__new_Cons(_ru_x1286, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _trmc_x10432, _ctx); /*list<4487>*/;
    kk_field_addr_t _b_x1068_1075 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10433, _ctx)->tail, _ctx); /*@field-addr<list<4487>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1773 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10433, _ctx)),_b_x1068_1075,kk_context()); /*ctx<0>*/
      ys = yy;
      _acc_0 = _x_x1773;
      goto kk__tailcall;
    }
  }
  if (kk_std_core_types__is_Cons(zs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1774 = kk_std_core_types__as_Cons(zs, _ctx);
    kk_box_t z = _con_x1774->head;
    kk_std_core_types__list zz_0 = _con_x1774->tail;
    if kk_likely(kk_datatype_ptr_is_unique(zs, _ctx)) {
      kk_datatype_ptr_free(zs, _ctx);
    }
    else {
      kk_box_dup(z, _ctx);
      kk_std_core_types__list_dup(zz_0, _ctx);
      kk_datatype_ptr_decref(zs, _ctx);
    }
    kk_std_core_types__list x_10810;
    kk_function_t _x_x1775 = kk_function_dup(f_0, _ctx); /*(4486) -> 4488 list<4487>*/
    x_10810 = kk_function_call(kk_std_core_types__list, (kk_function_t, kk_box_t, kk_context_t*), _x_x1775, (_x_x1775, z, _ctx), _ctx); /*list<4487>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_10810, _ctx);
      kk_box_t _x_x1776 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_lift_flatmap_4959_fun1777(_acc_0, f_0, zz_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1776, KK_OWNED, _ctx);
    }
    { // tailcall
      ys = x_10810;
      zs = zz_0;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1779 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1779, KK_OWNED, _ctx);
  }
}
 
// lifted local: flatmap, flatmap-pre

kk_std_core_types__list kk_std_core_list__lift_flatmap_4959(kk_function_t f_1, kk_std_core_types__list ys_0, kk_std_core_types__list zs_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1780 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_flatmap_4959(f_1, ys_0, zs_0, _x_x1780, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_flatmap_maybe_10027_10711(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10631, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Just(_y_x10631, _ctx)) {
    kk_box_t y = _y_x10631._cons.Just.value;
    kk_std_core_types__list _trmc_x10434 = kk_datatype_null(); /*list<4558>*/;
    kk_std_core_types__list _trmc_x10435 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _trmc_x10434, _ctx); /*list<4558>*/;
    kk_field_addr_t _b_x1088_1091 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10435, _ctx)->tail, _ctx); /*@field-addr<list<4558>>*/;
    kk_std_core_types__cctx _x_x1781 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10435, _ctx)),_b_x1088_1091,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_unroll_flatmap_maybe_10027(xx, f, _x_x1781, _ctx);
  }
  {
    return kk_std_core_list__trmc_unroll_flatmap_maybe_10027(xx, f, _acc, _ctx);
  }
}
 
// Concatenate the `Just` result elements from applying a function to all elements.


// lift anonymous function
struct kk_std_core_list__trmc_unroll_flatmap_maybe_10027_fun1785__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_flatmap_maybe_10027_fun1785(kk_function_t _fself, kk_box_t _b_x1096, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_flatmap_maybe_10027_fun1785(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_flatmap_maybe_10027_fun1785__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_flatmap_maybe_10027_fun1785__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_flatmap_maybe_10027_fun1785, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_flatmap_maybe_10027_fun1785(kk_function_t _fself, kk_box_t _b_x1096, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_flatmap_maybe_10027_fun1785__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_flatmap_maybe_10027_fun1785__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<4558>> */
  kk_function_t f_0 = _self->f_0; /* (4557) -> 4559 maybe<4558> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<4557> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10631_0_1114 = kk_std_core_types__maybe_unbox(_b_x1096, KK_OWNED, _ctx); /*maybe<4558>*/;
  kk_std_core_types__list _x_x1786 = kk_std_core_list__mlift_trmc_unroll_flatmap_maybe_10027_10711(_acc_0, f_0, xx_0, _y_x10631_0_1114, _ctx); /*list<4558>*/
  return kk_std_core_types__list_box(_x_x1786, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_flatmap_maybe_10027(kk_std_core_types__list xs, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1782 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1782->head;
    kk_std_core_types__list xx_0 = _con_x1782->tail;
    kk_reuse_t _ru_x1288 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1288 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__maybe x_0_10813;
    kk_function_t _x_x1783 = kk_function_dup(f_0, _ctx); /*(4557) -> 4559 maybe<4558>*/
    x_0_10813 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x1783, (_x_x1783, x, _ctx), _ctx); /*maybe<4558>*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1288,kk_context());
      kk_std_core_types__maybe_drop(x_0_10813, _ctx);
      kk_box_t _x_x1784 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_flatmap_maybe_10027_fun1785(_acc_0, f_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_std_core_types__list_unbox(_x_x1784, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Just(x_0_10813, _ctx)) {
      kk_box_t y_0 = x_0_10813._cons.Just.value;
      kk_std_core_types__list _trmc_x10434_0 = kk_datatype_null(); /*list<4558>*/;
      kk_std_core_types__list _trmc_x10435_0 = kk_std_core_types__new_Cons(_ru_x1288, kk_field_index_of(struct kk_std_core_types_Cons, tail), y_0, _trmc_x10434_0, _ctx); /*list<4558>*/;
      kk_field_addr_t _b_x1102_1108 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10435_0, _ctx)->tail, _ctx); /*@field-addr<list<4558>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1787 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10435_0, _ctx)),_b_x1102_1108,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1787;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1288,kk_context());
      { // tailcall
        xs = xx_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1788 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1788, KK_OWNED, _ctx);
  }
}
 
// Concatenate the `Just` result elements from applying a function to all elements.

kk_std_core_types__list kk_std_core_list__unroll_flatmap_maybe_10027(kk_std_core_types__list xs_0, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1789 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_flatmap_maybe_10027(xs_0, f_1, _x_x1789, _ctx);
}
 
// Concatenate a list of `:maybe` values

kk_std_core_types__list kk_std_core_list__trmc_unroll_concat_maybe_10028(kk_std_core_types__list xs, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<maybe<a>>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1790 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x1115 = _con_x1790->head;
    kk_std_core_types__list xx = _con_x1790->tail;
    kk_std_core_types__maybe x = kk_std_core_types__maybe_unbox(_box_x1115, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x1289 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_std_core_types__maybe_dup(x, _ctx);
      kk_box_drop(_box_x1115, _ctx);
      _ru_x1289 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_std_core_types__maybe_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Just(x, _ctx)) {
      kk_box_t y = x._cons.Just.value;
      kk_std_core_types__list _trmc_x10436 = kk_datatype_null(); /*list<4612>*/;
      kk_std_core_types__list _trmc_x10437 = kk_std_core_types__new_Cons(_ru_x1289, 0, y, _trmc_x10436, _ctx); /*list<4612>*/;
      kk_field_addr_t _b_x1121_1126 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10437, _ctx)->tail, _ctx); /*@field-addr<list<4612>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1791 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10437, _ctx)),_b_x1121_1126,kk_context()); /*ctx<0>*/
        xs = xx;
        _acc = _x_x1791;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1289,kk_context());
      { // tailcall
        xs = xx;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_box_t _x_x1792 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1792, KK_OWNED, _ctx);
  }
}
 
// Concatenate a list of `:maybe` values

kk_std_core_types__list kk_std_core_list__unroll_concat_maybe_10028(kk_std_core_types__list xs_0, kk_context_t* _ctx) { /* forall<a> (xs : list<maybe<a>>) -> list<a> */ 
  kk_std_core_types__cctx _x_x1793 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_concat_maybe_10028(xs_0, _x_x1793, _ctx);
}
 
// Return the last element of a list (or `Nothing` for the empty list)

kk_std_core_types__maybe kk_std_core_list_last(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> maybe<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1794 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_std_core_types__list _pat_0 = _con_x1794->tail;
    if (kk_std_core_types__is_Nil(_pat_0, _ctx)) {
      kk_box_t x = _con_x1794->head;
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_box_dup(x, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      return kk_std_core_types__new_Just(x, _ctx);
    }
  }
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1795 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _pat_2 = _con_x1795->head;
    kk_std_core_types__list xx = _con_x1795->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_box_drop(_pat_2, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    { // tailcall
      xs = xx;
      goto kk__tailcall;
    }
  }
  {
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Return the list without its last element.
// Return an empty list for an empty list.

kk_std_core_types__list kk_std_core_list__trmc_init(kk_std_core_types__list xs, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1796 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_std_core_types__list xx = _con_x1796->tail;
    if (kk_std_core_types__is_Cons(xx, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1797 = kk_std_core_types__as_Cons(xx, _ctx);
      kk_box_t x = _con_x1796->head;
      kk_reuse_t _ru_x1292 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        _ru_x1292 = (kk_datatype_ptr_reuse(xs, _ctx));
      }
      else {
        kk_box_dup(x, _ctx);
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      kk_std_core_types__list _trmc_x10438 = kk_datatype_null(); /*list<4685>*/;
      kk_std_core_types__list _trmc_x10439 = kk_std_core_types__new_Cons(_ru_x1292, 0, x, _trmc_x10438, _ctx); /*list<4685>*/;
      kk_field_addr_t _b_x1137_1142 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10439, _ctx)->tail, _ctx); /*@field-addr<list<4685>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1798 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10439, _ctx)),_b_x1137_1142,kk_context()); /*ctx<0>*/
        xs = xx;
        _acc = _x_x1798;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_std_core_types__list_drop(xs, _ctx);
    kk_box_t _x_x1799 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1799, KK_OWNED, _ctx);
  }
}
 
// Return the list without its last element.
// Return an empty list for an empty list.

kk_std_core_types__list kk_std_core_list_init(kk_std_core_types__list xs_0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> list<a> */ 
  kk_std_core_types__cctx _x_x1800 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_init(xs_0, _x_x1800, _ctx);
}
 
// Get (zero-based) element `n`  of a list. Return a `:maybe` type.

kk_std_core_types__maybe kk_std_core_list__unroll_index_10029(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> maybe<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1801 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1801->head;
    kk_std_core_types__list xx = _con_x1801->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool _match_x1168 = kk_integer_gt_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x1168) {
      kk_box_drop(x, _ctx);
      { // tailcall
        kk_integer_t _x_x1802 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
        xs = xx;
        n = _x_x1802;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(xx, _ctx);
      bool _match_x1169;
      bool _brw_x1170 = kk_integer_eq_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(n, _ctx);
      _match_x1169 = _brw_x1170; /*bool*/
      if (_match_x1169) {
        return kk_std_core_types__new_Just(x, _ctx);
      }
      {
        kk_box_drop(x, _ctx);
        return kk_std_core_types__new_Nothing(_ctx);
      }
    }
  }
  {
    kk_integer_drop(n, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// monadic lift

bool kk_std_core_list__mlift_unroll_all_10030_10712(kk_function_t predicate, kk_std_core_types__list xx, bool _y_x10639, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */ 
  if (_y_x10639) {
    return kk_std_core_list__unroll_all_10030(xx, predicate, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(predicate, _ctx);
    return false;
  }
}
 
// Do all elements satisfy a predicate ?


// lift anonymous function
struct kk_std_core_list__unroll_all_10030_fun1806__t {
  struct kk_function_s _base;
  kk_function_t predicate_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_all_10030_fun1806(kk_function_t _fself, kk_box_t _b_x1149, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_all_10030_fun1806(kk_function_t predicate_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_all_10030_fun1806__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_all_10030_fun1806__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_all_10030_fun1806, kk_context());
  _self->predicate_0 = predicate_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_all_10030_fun1806(kk_function_t _fself, kk_box_t _b_x1149, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_all_10030_fun1806__t* _self = kk_function_as(struct kk_std_core_list__unroll_all_10030_fun1806__t*, _fself, _ctx);
  kk_function_t predicate_0 = _self->predicate_0; /* (4801) -> 4802 bool */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<4801> */
  kk_drop_match(_self, {kk_function_dup(predicate_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10639_0_1151 = kk_bool_unbox(_b_x1149); /*bool*/;
  bool _x_x1807 = kk_std_core_list__mlift_unroll_all_10030_10712(predicate_0, xx_0, _y_x10639_0_1151, _ctx); /*bool*/
  return kk_bool_box(_x_x1807);
}

bool kk_std_core_list__unroll_all_10030(kk_std_core_types__list xs, kk_function_t predicate_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1803 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1803->head;
    kk_std_core_types__list xx_0 = _con_x1803->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_0_10816;
    kk_function_t _x_x1804 = kk_function_dup(predicate_0, _ctx); /*(4801) -> 4802 bool*/
    x_0_10816 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1804, (_x_x1804, x, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1805 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_all_10030_fun1806(predicate_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_bool_unbox(_x_x1805);
    }
    if (x_0_10816) { // tailcall
                     xs = xx_0;
                     goto kk__tailcall;
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      return false;
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    return true;
  }
}
 
// monadic lift

bool kk_std_core_list__mlift_unroll_any_10031_10713(kk_function_t predicate, kk_std_core_types__list xx, bool _y_x10645, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */ 
  if (_y_x10645) {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(predicate, _ctx);
    return true;
  }
  {
    return kk_std_core_list__unroll_any_10031(xx, predicate, _ctx);
  }
}
 
// Are there any elements in a list that satisfy a predicate ?


// lift anonymous function
struct kk_std_core_list__unroll_any_10031_fun1811__t {
  struct kk_function_s _base;
  kk_function_t predicate_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_any_10031_fun1811(kk_function_t _fself, kk_box_t _b_x1153, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_any_10031_fun1811(kk_function_t predicate_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_any_10031_fun1811__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_any_10031_fun1811__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_any_10031_fun1811, kk_context());
  _self->predicate_0 = predicate_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_any_10031_fun1811(kk_function_t _fself, kk_box_t _b_x1153, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_any_10031_fun1811__t* _self = kk_function_as(struct kk_std_core_list__unroll_any_10031_fun1811__t*, _fself, _ctx);
  kk_function_t predicate_0 = _self->predicate_0; /* (4839) -> 4840 bool */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<4839> */
  kk_drop_match(_self, {kk_function_dup(predicate_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10645_0_1155 = kk_bool_unbox(_b_x1153); /*bool*/;
  bool _x_x1812 = kk_std_core_list__mlift_unroll_any_10031_10713(predicate_0, xx_0, _y_x10645_0_1155, _ctx); /*bool*/
  return kk_bool_box(_x_x1812);
}

bool kk_std_core_list__unroll_any_10031(kk_std_core_types__list xs, kk_function_t predicate_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1808 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1808->head;
    kk_std_core_types__list xx_0 = _con_x1808->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_0_10819;
    kk_function_t _x_x1809 = kk_function_dup(predicate_0, _ctx); /*(4839) -> 4840 bool*/
    x_0_10819 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1809, (_x_x1809, x, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1810 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_any_10031_fun1811(predicate_0, xx_0, _ctx), _ctx); /*2978*/
      return kk_bool_unbox(_x_x1810);
    }
    if (x_0_10819) {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      return true;
    }
    { // tailcall
      xs = xx_0;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    return false;
  }
}
 
// lifted local: sum, @spec-x10346
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10341, using:
// @uniq-f@10341 = std/core/int/(+)

kk_integer_t kk_std_core_list__lift_sum_10369(kk_std_core_types__list _uniq_xs_10339, kk_integer_t _uniq_z_10340, kk_context_t* _ctx) { /* (list<int>, int) -> int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10339, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1813 = kk_std_core_types__as_Cons(_uniq_xs_10339, _ctx);
    kk_box_t _box_x1156 = _con_x1813->head;
    kk_std_core_types__list _uniq_xx_10344 = _con_x1813->tail;
    kk_integer_t _uniq_x_10343 = kk_integer_unbox(_box_x1156, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10339, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10339, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10343, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10344, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10339, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x1814 = kk_std_core_int__lp__plus__rp_(_uniq_z_10340, _uniq_x_10343, _ctx); /*int*/
      _uniq_xs_10339 = _uniq_xx_10344;
      _uniq_z_10340 = _x_x1814;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10340;
  }
}
 
// lifted local: minimum, @spec-x10354
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10349, using:
// @uniq-f@10349 = std/core/int/min

kk_integer_t kk_std_core_list__lift_minimum_10370(kk_std_core_types__list _uniq_xs_10347, kk_integer_t _uniq_z_10348, kk_context_t* _ctx) { /* (list<int>, int) -> int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10347, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1815 = kk_std_core_types__as_Cons(_uniq_xs_10347, _ctx);
    kk_box_t _box_x1157 = _con_x1815->head;
    kk_std_core_types__list _uniq_xx_10352 = _con_x1815->tail;
    kk_integer_t _uniq_x_10351 = kk_integer_unbox(_box_x1157, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10347, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10347, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10351, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10352, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10347, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x1816 = kk_std_core_int_min(_uniq_z_10348, _uniq_x_10351, _ctx); /*int*/
      _uniq_xs_10347 = _uniq_xx_10352;
      _uniq_z_10348 = _x_x1816;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10348;
  }
}
 
// Returns the smallest element of a list of integers (or `default` (=`0`) for the empty list)

kk_integer_t kk_std_core_list_minimum(kk_std_core_types__list xs, kk_std_core_types__optional kkloc_default, kk_context_t* _ctx) { /* (xs : list<int>, default : ? int) -> int */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    if (kk_std_core_types__is_Optional(kkloc_default, _ctx)) {
      kk_box_t _box_x1158 = kkloc_default._cons._Optional.value;
      kk_integer_t _uniq_default_4871 = kk_integer_unbox(_box_x1158, _ctx);
      kk_integer_dup(_uniq_default_4871, _ctx);
      kk_std_core_types__optional_drop(kkloc_default, _ctx);
      return _uniq_default_4871;
    }
    {
      kk_std_core_types__optional_drop(kkloc_default, _ctx);
      return kk_integer_from_small(0);
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x1817 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x1159 = _con_x1817->head;
    kk_std_core_types__list xx = _con_x1817->tail;
    kk_integer_t x = kk_integer_unbox(_box_x1159, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_integer_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__optional_drop(kkloc_default, _ctx);
    if (kk_std_core_types__is_Nil(xx, _ctx)) {
      return x;
    }
    {
      return kk_std_core_list__lift_minimum_10370(xx, x, _ctx);
    }
  }
}
 
// lifted local: maximum, @spec-x10362
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10357, using:
// @uniq-f@10357 = std/core/int/max

kk_integer_t kk_std_core_list__lift_maximum_10371(kk_std_core_types__list _uniq_xs_10355, kk_integer_t _uniq_z_10356, kk_context_t* _ctx) { /* (list<int>, int) -> int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10355, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1818 = kk_std_core_types__as_Cons(_uniq_xs_10355, _ctx);
    kk_box_t _box_x1160 = _con_x1818->head;
    kk_std_core_types__list _uniq_xx_10360 = _con_x1818->tail;
    kk_integer_t _uniq_x_10359 = kk_integer_unbox(_box_x1160, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10355, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10355, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10359, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10360, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10355, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x1819 = kk_std_core_int_max(_uniq_z_10356, _uniq_x_10359, _ctx); /*int*/
      _uniq_xs_10355 = _uniq_xx_10360;
      _uniq_z_10356 = _x_x1819;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10356;
  }
}
 
// Returns the largest element of a list of integers (or `default` (=`0`) for the empty list)

kk_integer_t kk_std_core_list_maximum(kk_std_core_types__list xs, kk_std_core_types__optional kkloc_default, kk_context_t* _ctx) { /* (xs : list<int>, default : ? int) -> int */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    if (kk_std_core_types__is_Optional(kkloc_default, _ctx)) {
      kk_box_t _box_x1161 = kkloc_default._cons._Optional.value;
      kk_integer_t _uniq_default_4901 = kk_integer_unbox(_box_x1161, _ctx);
      kk_integer_dup(_uniq_default_4901, _ctx);
      kk_std_core_types__optional_drop(kkloc_default, _ctx);
      return _uniq_default_4901;
    }
    {
      kk_std_core_types__optional_drop(kkloc_default, _ctx);
      return kk_integer_from_small(0);
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x1820 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x1162 = _con_x1820->head;
    kk_std_core_types__list xx = _con_x1820->tail;
    kk_integer_t x = kk_integer_unbox(_box_x1162, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_integer_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__optional_drop(kkloc_default, _ctx);
    if (kk_std_core_types__is_Nil(xx, _ctx)) {
      return x;
    }
    {
      return kk_std_core_list__lift_maximum_10371(xx, x, _ctx);
    }
  }
}
 
// Join a list of strings with newlines

kk_string_t kk_std_core_list_unlines(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<string>) -> string */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x1824 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x1163 = _con_x1824->head;
    kk_std_core_types__list _pat_1 = _con_x1824->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x1163);
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      return x;
    }
  }
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1825 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x1164 = _con_x1825->head;
    kk_std_core_types__list _pat_3 = _con_x1825->tail;
    if (kk_std_core_types__is_Cons(_pat_3, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1826 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x1165 = _con_x1826->head;
      kk_std_core_types__list _pat_4 = _con_x1826->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t _x_x1827;
        kk_define_string_literal(, _s_x1828, 1, "\n", _ctx)
        _x_x1827 = kk_string_dup(_s_x1828, _ctx); /*string*/
        kk_string_t _x_x1829 = kk_string_empty(); /*string*/
        if (kk_string_is_eq(_x_x1827,_x_x1829,kk_context())) {
          kk_string_t x_0 = kk_string_unbox(_box_x1164);
          kk_string_t y = kk_string_unbox(_box_x1165);
          if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
              kk_datatype_ptr_free(_pat_3, _ctx);
            }
            else {
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(_pat_3, _ctx);
            }
            kk_datatype_ptr_free(xs, _ctx);
          }
          else {
            kk_string_dup(x_0, _ctx);
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(xs, _ctx);
          }
          return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
        }
      }
    }
  }
  {
    kk_vector_t _x_x1831 = kk_std_core_vector_unvlist(xs, _ctx); /*vector<832>*/
    kk_string_t _x_x1832;
    kk_define_string_literal(, _s_x1833, 1, "\n", _ctx)
    _x_x1832 = kk_string_dup(_s_x1833, _ctx); /*string*/
    return kk_string_join_with(_x_x1831,_x_x1832,kk_context());
  }
}

// initialization
void kk_std_core_list__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_undiv__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_exn__init(_ctx);
  kk_std_core_char__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_vector__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_list__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_vector__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_char__done(_ctx);
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_undiv__done(_ctx);
  kk_std_core_types__done(_ctx);
}
