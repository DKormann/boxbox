// Koka generated module: std/core/list, koka version: 3.1.2
"use strict";
 
// imports
import * as $std_core_types from './std_core_types.mjs';
import * as $std_core_undiv from './std_core_undiv.mjs';
import * as $std_core_hnd from './std_core_hnd.mjs';
import * as $std_core_exn from './std_core_exn.mjs';
import * as $std_core_char from './std_core_char.mjs';
import * as $std_core_string from './std_core_string.mjs';
import * as $std_core_int from './std_core_int.mjs';
import * as $std_core_vector from './std_core_vector.mjs';
 
// externals
 
// type declarations
 
// declarations
 
 
// Return the head of list if the list is not empty.
export function head(xs) /* forall<a> (xs : list<a>) -> maybe<a> */  {
  if (xs !== null) {
    return $std_core_types.Just(xs.head);
  }
  else {
    return $std_core_types.Nothing;
  }
}
 
 
// Return the head of list with a default value in case the list is empty.
export function default_fs_head(xs, $default) /* forall<a> (xs : list<a>, default : a) -> a */  {
  return (xs !== null) ? xs.head : $default;
}
 
 
// Return the tail of list. Returns the empty list if `xs` is empty.
export function tail(xs) /* forall<a> (xs : list<a>) -> list<a> */  {
  return (xs !== null) ? xs.tail : $std_core_types.Nil;
}
 
 
// Is the list empty?
export function is_empty(xs) /* forall<a> (xs : list<a>) -> bool */  {
  return (xs === null);
}
 
 
// Returns a singleton list.
export function single(x) /* forall<a> (x : a) -> list<a> */  {
  return $std_core_types.Cons(x, $std_core_types.Nil);
}
 
 
// lifted local: length, len
export function _unroll_lift_length_4947_10000(ys, acc) /* forall<a> (ys : list<a>, acc : int) -> int */  { tailcall: while(1)
{
  if (ys !== null) {
    {
      // tail call
      var _x0 = $std_core_types._int_add(acc,1);
      ys = ys.tail;
      acc = _x0;
      continue tailcall;
    }
  }
  else {
    return acc;
  }
}}
 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-length@4947@10000
export function _lift_length_4947(ys, acc) /* forall<a> (ys : list<a>, acc : int) -> int */  {
  if (ys === null) {
    return acc;
  }
  else {
    return _unroll_lift_length_4947_10000(ys, acc);
  }
}
 
 
// Returns the length of a list.
export function length(xs) /* forall<a> (xs : list<a>) -> int */  {
  if (xs === null) {
    return 0;
  }
  else {
    return _unroll_lift_length_4947_10000(xs, 0);
  }
}
 
 
// Element-wise list equality
export function _lp__at_unroll_x_10001_eq__eq__rp_(xs, ys, _implicit_fs__lp__eq__eq__rp_) /* forall<a> (xs : list<a>, ys : list<a>, ?(==) : (a, a) -> bool) -> bool */  { tailcall: while(1)
{
  if (xs !== null) {
    if (ys === null) {
      return false;
    }
    else {
      var _x1 = _implicit_fs__lp__eq__eq__rp_(xs.head, ys.head);
      if (_x1) {
        {
          // tail call
          xs = xs.tail;
          ys = ys.tail;
          continue tailcall;
        }
      }
      else {
        return false;
      }
    }
  }
  else {
    return (ys === null);
  }
}}
 
 
// unrolling of singleton matches of std/core/list/(@unroll-x@10001==)
export function _lp__eq__eq__rp_(xs, ys, _implicit_fs__lp__eq__eq__rp_) /* forall<a> (xs : list<a>, ys : list<a>, ?(==) : (a, a) -> bool) -> bool */  {
  if (xs === null) {
    return (ys === null);
  }
  else {
    return _lp__at_unroll_x_10001_eq__eq__rp_(xs, ys, _implicit_fs__lp__eq__eq__rp_);
  }
}
 
 
// Order on lists
export function _unroll_cmp_10002(xs, ys, _implicit_fs_cmp) /* forall<a> (xs : list<a>, ys : list<a>, ?cmp : (a, a) -> order) -> order */  { tailcall: while(1)
{
  if (xs !== null) {
    if (ys === null) {
      return $std_core_types.Gt;
    }
    else {
      var _x2 = _implicit_fs_cmp(xs.head, ys.head);
      if (_x2 === 2) {
        {
          // tail call
          xs = xs.tail;
          ys = ys.tail;
          continue tailcall;
        }
      }
      else {
        return _x2;
      }
    }
  }
  else {
    return (ys === null) ? $std_core_types.Eq : $std_core_types.Lt;
  }
}}
 
 
// unrolling of singleton matches of std/core/list/@unroll-cmp@10002
export function cmp(xs, ys, _implicit_fs_cmp) /* forall<a> (xs : list<a>, ys : list<a>, ?cmp : (a, a) -> order) -> order */  {
  if (xs === null) {
    return (ys === null) ? $std_core_types.Eq : $std_core_types.Lt;
  }
  else {
    return _unroll_cmp_10002(xs, ys, _implicit_fs_cmp);
  }
}
 
 
// Take the first `n` elements of a list (or fewer if the list is shorter than `n`)
export function _trmc_take(xs, n, _acc) /* forall<a> (xs : list<a>, n : int, ctx<list<a>>) -> list<a> */  { tailcall: while(1)
{
  if (xs !== null) {
    if ($std_core_types._int_gt(n,0)){
       
      var _trmc_x10379 = undefined;
       
      var _trmc_x10380 = $std_core_types.Cons(xs.head, _trmc_x10379);
      {
        // tail call
        var _x3 = $std_core_types._int_sub(n,1);
        var _x4 = $std_core_types._cctx_extend(_acc,_trmc_x10380,({obj: _trmc_x10380, field_name: "tail"}));
        xs = xs.tail;
        n = _x3;
        _acc = _x4;
        continue tailcall;
      }
    }
  }
  return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
}}
 
 
// Take the first `n` elements of a list (or fewer if the list is shorter than `n`)
export function take(xs_0, n_0) /* forall<a> (xs : list<a>, n : int) -> list<a> */  {
  return _trmc_take(xs_0, n_0, $std_core_types._cctx_empty());
}
 
 
// Drop the first `n` elements of a list (or fewer if the list is shorter than `n`)
export function drop(xs, n) /* forall<a> (xs : list<a>, n : int) -> list<a> */  { tailcall: while(1)
{
  if (xs !== null) {
    if ($std_core_types._int_gt(n,0)){
      {
        // tail call
        var _x5 = $std_core_types._int_sub(n,1);
        xs = xs.tail;
        n = _x5;
        continue tailcall;
      }
    }
  }
  return xs;
}}
 
 
// lifted local: reverse-append, reverse-acc
export function _unroll_lift_reverse_append_4948_10003(acc, ys) /* forall<a> (acc : list<a>, ys : list<a>) -> list<a> */  { tailcall: while(1)
{
  if (ys !== null) {
    {
      // tail call
      var _x6 = $std_core_types.Cons(ys.head, acc);
      acc = _x6;
      ys = ys.tail;
      continue tailcall;
    }
  }
  else {
    return acc;
  }
}}
 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-reverse-append@4948@10003
export function _lift_reverse_append_4948(acc, ys) /* forall<a> (acc : list<a>, ys : list<a>) -> list<a> */  {
  if (ys === null) {
    return acc;
  }
  else {
    return _unroll_lift_reverse_append_4948_10003(acc, ys);
  }
}
 
 
// Efficiently reverse a list `xs` and append it to `tl`:
// `reverse-append(xs,tl) == reserve(xs) ++ tl
export function reverse_append(xs, tl) /* forall<a> (xs : list<a>, tl : list<a>) -> list<a> */  {
  if (xs === null) {
    return tl;
  }
  else {
    return _unroll_lift_reverse_append_4948_10003(tl, xs);
  }
}
 
 
// Reverse a list.
export function reverse(xs) /* forall<a> (xs : list<a>) -> list<a> */  {
  if (xs === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_lift_reverse_append_4948_10003($std_core_types.Nil, xs);
  }
}
 
 
// Append two lists.
export function _trmc_unroll_append_10004(xs, ys, _acc) /* forall<a> (xs : list<a>, ys : list<a>, ctx<list<a>>) -> list<a> */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var _trmc_x10381 = undefined;
     
    var _trmc_x10382 = $std_core_types.Cons(xs.head, _trmc_x10381);
    {
      // tail call
      var _x7 = $std_core_types._cctx_extend(_acc,_trmc_x10382,({obj: _trmc_x10382, field_name: "tail"}));
      xs = xs.tail;
      _acc = _x7;
      continue tailcall;
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc,ys);
  }
}}
 
 
// Append two lists.
export function _unroll_append_10004(xs_0, ys_0) /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */  {
  return _trmc_unroll_append_10004(xs_0, ys_0, $std_core_types._cctx_empty());
}
 
 
// unrolling of singleton matches of std/core/list/@unroll-append@10004
export function append(xs, ys) /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */  {
  if (xs === null) {
    return ys;
  }
  else {
    return _unroll_append_10004(xs, ys);
  }
}
 
 
// Append two lists.
export function _lp__plus__plus__rp_(xs, ys) /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */  {
  if (xs === null) {
    return ys;
  }
  else {
    return _unroll_append_10004(xs, ys);
  }
}
 
 
// monadic lift
export function _mlift_unroll_foldl_10005_10821(f, xx, _y_x10478) /* forall<a,b,e> (f : (b, a) -> e b, xx : list<a>, b) -> e b */  {
  return _unroll_foldl_10005(xx, _y_x10478, f);
}
 
 
// Fold a list from the left, i.e. `foldl([1,2],0,(+)) == (0+1)+2`
// Since `foldl` is tail recursive, it is preferred over `foldr` when using an associative function `f`
export function _unroll_foldl_10005(xs, z, f_0) /* forall<a,b,e> (xs : list<a>, z : b, f : (b, a) -> e b) -> e b */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_0_10868 = f_0(z, xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10478_0 /* 1073 */ ) {
        return _mlift_unroll_foldl_10005_10821(f_0, xs.tail, _y_x10478_0);
      });
    }
    else {
      {
        // tail call
        xs = xs.tail;
        z = x_0_10868;
        continue tailcall;
      }
    }
  }
  else {
    return z;
  }
}}
 
 
// unrolling of singleton matches of std/core/list/@unroll-foldl@10005
export function foldl(xs, z, f) /* forall<a,b,e> (xs : list<a>, z : b, f : (b, a) -> e b) -> e b */  {
  if (xs === null) {
    return z;
  }
  else {
    return _unroll_foldl_10005(xs, z, f);
  }
}
 
 
// monadic lift
export function _mlift_lift_foldr_10363_10822(_uniq_xx_10288, f, _uniq_z_10284_0_10373) /* forall<a,b,e> (list<a>, f : (a, b) -> e b, b) -> e b */  {
  return _lift_foldr_10363(f, _uniq_xx_10288, _uniq_z_10284_0_10373);
}
 
 
// lifted local: foldr, @spec-x10290
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10285, using:
// @uniq-f@10285 = fn<(e :: E)>(x: 1117, y: 1116){
//   f(y, x);
// }
export function _lift_foldr_10363(f_0, _uniq_xs_10283, _uniq_z_10284) /* forall<a,b,e> (f : (a, b) -> e b, list<a>, b) -> e b */  { tailcall: while(1)
{
  if (_uniq_xs_10283 !== null) {
     
    var x_10871 = f_0(_uniq_xs_10283.head, _uniq_z_10284);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_uniq_z_10284_0_10373_0 /* 1117 */ ) {
        return _mlift_lift_foldr_10363_10822(_uniq_xs_10283.tail, f_0, _uniq_z_10284_0_10373_0);
      });
    }
    else {
      {
        // tail call
        _uniq_xs_10283 = _uniq_xs_10283.tail;
        _uniq_z_10284 = x_10871;
        continue tailcall;
      }
    }
  }
  else {
    return _uniq_z_10284;
  }
}}
 
 
// Fold a list from the right, i.e. `foldr([1,2],0,(+)) == 1+(2+0)`
// Note, `foldr` is less efficient than `foldl` as it reverses the list first.
export function foldr(xs, z, f) /* forall<a,b,e> (xs : list<a>, z : b, f : (a, b) -> e b) -> e b */  {
   
  if (xs === null) {
    var xs_0_10042 = $std_core_types.Nil;
  }
  else {
    var xs_0_10042 = _unroll_lift_reverse_append_4948_10003($std_core_types.Nil, xs);
  }
  if (xs_0_10042 === null) {
    return z;
  }
  else {
    return _lift_foldr_10363(f, xs_0_10042, z);
  }
}
 
export function foldl1(xs, f) /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */  {
  if (xs !== null) {
    if (xs.tail === null) {
      return xs.head;
    }
    else {
      return _unroll_foldl_10005(xs.tail, xs.head, f);
    }
  }
  else {
     
    var i_10874 = $std_core_hnd._evv_index($std_core_exn._tag_exn);
     
    var w = $std_core_hnd._evv_swap_create1(i_10874);
     
    var ev_10878 = $std_core_hnd._evv_at(0);
     
    var _x8 = $std_core_exn._select_throw_exn(ev_10878.hnd);
    var _x10 = undefined;
    var _x9 = (_x10 !== undefined) ? _x10 : $std_core_exn.ExnError;
    var y = _x8(ev_10878.marker, ev_10878, $std_core_exn.Exception("unexpected Nil in std/core/foldl1", _x9));
     
    $std_core_hnd._evv_set(w);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_cont(function(cont /* (9215) -> <exn|1166> 1165 */ , res /* 9215 */ ) {
        return $std_core_hnd.open_at1(i_10874, cont, res);
      });
    }
    else {
      return y;
    }
  }
}
 
export function foldr1(xs, f) /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */  {
   
  var w = $std_core_hnd._evv_swap_create0();
   
  if (xs === null) {
    var x = $std_core_types.Nil;
  }
  else {
    var x = _unroll_lift_reverse_append_4948_10003($std_core_types.Nil, xs);
  }
   
  var keep = $std_core_hnd._evv_set(w);
  if (x !== null) {
    if (x.tail === null) {
      return x.head;
    }
    else {
      return _unroll_foldl_10005(x.tail, x.head, f);
    }
  }
  else {
     
    var i_10883 = $std_core_hnd._evv_index($std_core_exn._tag_exn);
     
    var w_0 = $std_core_hnd._evv_swap_create1(i_10883);
     
    var ev_10887 = $std_core_hnd._evv_at(0);
     
    var _x8 = $std_core_exn._select_throw_exn(ev_10887.hnd);
    var _x10 = undefined;
    var _x9 = (_x10 !== undefined) ? _x10 : $std_core_exn.ExnError;
    var y = _x8(ev_10887.marker, ev_10887, $std_core_exn.Exception("unexpected Nil in std/core/foldl1", _x9));
     
    $std_core_hnd._evv_set(w_0);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_cont(function(cont /* (9215) -> <exn|1196> 1195 */ , res /* 9215 */ ) {
        return $std_core_hnd.open_at1(i_10883, cont, res);
      });
    }
    else {
      return y;
    }
  }
}
 
 
// split a list at position `n`
export function split(xs, n) /* forall<a> (xs : list<a>, n : int) -> (list<a>, list<a>) */  {
  return $std_core_types.Tuple2(take(xs, n), drop(xs, n));
}
 
 
// monadic lift
export function _mlift_unroll_drop_while_10006_10823(predicate, xs, xx, _y_x10498) /* forall<a,e> (predicate : (a) -> e bool, xs : list<a>, xx : list<a>, bool) -> e list<a> */  {
  if (_y_x10498) {
    return _unroll_drop_while_10006(xx, predicate);
  }
  else {
    return xs;
  }
}
 
 
// Drop all initial elements that satisfy `predicate`
export function _unroll_drop_while_10006(xs_0, predicate_0) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */  { tailcall: while(1)
{
  if (xs_0 !== null) {
     
    var x_0_10890 = predicate_0(xs_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10498_0 /* bool */ ) {
        return _mlift_unroll_drop_while_10006_10823(predicate_0, xs_0, xs_0.tail, _y_x10498_0);
      });
    }
    else {
      if (x_0_10890) {
        {
          // tail call
          xs_0 = xs_0.tail;
          continue tailcall;
        }
      }
      else {
        return xs_0;
      }
    }
  }
  else {
    return $std_core_types.Nil;
  }
}}
 
 
// unrolling of singleton matches of std/core/list/@unroll-drop-while@10006
export function drop_while(xs, predicate) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */  {
  if (xs === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_drop_while_10006(xs, predicate);
  }
}
 
 
// monadic lift
export function _mlift_trmc_unroll_filter_10007_10824(_acc, pred, x, xx, _y_x10504) /* forall<a,e> (ctx<list<a>>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */  {
  if (_y_x10504) {
     
    var _trmc_x10383 = undefined;
     
    var _trmc_x10384 = $std_core_types.Cons(x, _trmc_x10383);
    return _trmc_unroll_filter_10007(xx, pred, $std_core_types._cctx_extend(_acc,_trmc_x10384,({obj: _trmc_x10384, field_name: "tail"})));
  }
  else {
    return _trmc_unroll_filter_10007(xx, pred, _acc);
  }
}
 
 
// monadic lift
export function _mlift_trmcm_unroll_filter_10007_10825(_accm, pred_0, x_0, xx_0, _y_x10509) /* forall<a,e> ((list<a>) -> list<a>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */  {
  if (_y_x10509) {
    return _trmcm_unroll_filter_10007(xx_0, pred_0, function(_trmc_x10386 /* list<1325> */ ) {
        return _accm($std_core_types.Cons(x_0, _trmc_x10386));
      });
  }
  else {
    return _trmcm_unroll_filter_10007(xx_0, pred_0, _accm);
  }
}
 
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filter([1,2,3],odd?) == [1,3]`
export function _trmc_unroll_filter_10007(xs, pred_1, _acc_0) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, ctx<list<a>>) -> e list<a> */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_2_10893 = pred_1(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10504_0 /* bool */ ) {
        return _mlift_trmc_unroll_filter_10007_10824(_acc_0, pred_1, xs.head, xs.tail, _y_x10504_0);
      });
    }
    else {
      if (x_2_10893) {
         
        var _trmc_x10383_0 = undefined;
         
        var _trmc_x10384_0 = $std_core_types.Cons(xs.head, _trmc_x10383_0);
        {
          // tail call
          var _x8 = $std_core_types._cctx_extend(_acc_0,_trmc_x10384_0,({obj: _trmc_x10384_0, field_name: "tail"}));
          xs = xs.tail;
          _acc_0 = _x8;
          continue tailcall;
        }
      }
      else {
        {
          // tail call
          xs = xs.tail;
          continue tailcall;
        }
      }
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
}}
 
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filter([1,2,3],odd?) == [1,3]`
export function _trmcm_unroll_filter_10007(xs_0, pred_2, _accm_0) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, (list<a>) -> list<a>) -> e list<a> */  { tailcall: while(1)
{
  if (xs_0 !== null) {
     
    var x_4_10896 = pred_2(xs_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10509_0 /* bool */ ) {
        return _mlift_trmcm_unroll_filter_10007_10825(_accm_0, pred_2, xs_0.head, xs_0.tail, _y_x10509_0);
      });
    }
    else {
      if (x_4_10896) {
        {
          // tail call
          var _x11 = function(__at_accm_09 /* (list<1325>) -> list<1325> */ , _x_310 /* 1325 */ ) {
            return function(_trmc_x10386_0 /* list<1325> */ ) {
              return __at_accm_09($std_core_types.Cons(_x_310, _trmc_x10386_0));
            };
          }(_accm_0, xs_0.head);
          xs_0 = xs_0.tail;
          _accm_0 = _x11;
          continue tailcall;
        }
      }
      else {
        {
          // tail call
          xs_0 = xs_0.tail;
          continue tailcall;
        }
      }
    }
  }
  else {
    return _accm_0($std_core_types.Nil);
  }
}}
 
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filter([1,2,3],odd?) == [1,3]`
export function _unroll_filter_10007(xs_1, pred_3) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e list<a> */  {
  var _x12 = $std_core_hnd._evv_is_affine();
  if (_x12) {
    return _trmc_unroll_filter_10007(xs_1, pred_3, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_unroll_filter_10007(xs_1, pred_3, function(_trmc_x10385 /* list<1325> */ ) {
        return _trmc_x10385;
      });
  }
}
 
 
// unrolling of singleton matches of std/core/list/@unroll-filter@10007
export function filter(xs, pred) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e list<a> */  {
  if (xs === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_filter_10007(xs, pred);
  }
}
 
 
// monadic lift
export function _mlift_trmc_unroll_filter_map_10008_10826(_acc, pred, xx, _y_x10519) /* forall<a,b,e> (ctx<list<b>>, pred : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */  {
  if (_y_x10519 === null) {
    return _trmc_unroll_filter_map_10008(xx, pred, _acc);
  }
  else {
     
    var _trmc_x10387 = undefined;
     
    var _trmc_x10388 = $std_core_types.Cons(_y_x10519.value, _trmc_x10387);
    return _trmc_unroll_filter_map_10008(xx, pred, $std_core_types._cctx_extend(_acc,_trmc_x10388,({obj: _trmc_x10388, field_name: "tail"})));
  }
}
 
 
// monadic lift
export function _mlift_trmcm_unroll_filter_map_10008_10827(_accm, pred_0, xx_0, _y_x10524) /* forall<a,b,e> ((list<b>) -> list<b>, pred : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */  {
  if (_y_x10524 === null) {
    return _trmcm_unroll_filter_map_10008(xx_0, pred_0, _accm);
  }
  else {
    return _trmcm_unroll_filter_map_10008(xx_0, pred_0, function(_trmc_x10390 /* list<1393> */ ) {
        return _accm($std_core_types.Cons(_y_x10524.value, _trmc_x10390));
      });
  }
}
 
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if i.odd? then Nothing else Just(i*i) }) == [4]`
export function _trmc_unroll_filter_map_10008(xs, pred_1, _acc_0) /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */  { tailcall: while(1)
{
  if (xs === null) {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
  else {
     
    var x_0_10899 = pred_1(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10519_0 /* maybe<1393> */ ) {
        return _mlift_trmc_unroll_filter_map_10008_10826(_acc_0, pred_1, xs.tail, _y_x10519_0);
      });
    }
    else {
      if (x_0_10899 === null) {
        {
          // tail call
          xs = xs.tail;
          continue tailcall;
        }
      }
      else {
         
        var _trmc_x10387_0 = undefined;
         
        var _trmc_x10388_0 = $std_core_types.Cons(x_0_10899.value, _trmc_x10387_0);
        {
          // tail call
          var _x13 = $std_core_types._cctx_extend(_acc_0,_trmc_x10388_0,({obj: _trmc_x10388_0, field_name: "tail"}));
          xs = xs.tail;
          _acc_0 = _x13;
          continue tailcall;
        }
      }
    }
  }
}}
 
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if i.odd? then Nothing else Just(i*i) }) == [4]`
export function _trmcm_unroll_filter_map_10008(xs_0, pred_2, _accm_0) /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>, (list<b>) -> list<b>) -> e list<b> */  { tailcall: while(1)
{
  if (xs_0 === null) {
    return _accm_0($std_core_types.Nil);
  }
  else {
     
    var x_2_10902 = pred_2(xs_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10524_0 /* maybe<1393> */ ) {
        return _mlift_trmcm_unroll_filter_map_10008_10827(_accm_0, pred_2, xs_0.tail, _y_x10524_0);
      });
    }
    else {
      if (x_2_10902 === null) {
        {
          // tail call
          xs_0 = xs_0.tail;
          continue tailcall;
        }
      }
      else {
        {
          // tail call
          var _x16 = function(__at_accm_014 /* (list<1393>) -> list<1393> */ , _y_215 /* 1393 */ ) {
            return function(_trmc_x10390_0 /* list<1393> */ ) {
              return __at_accm_014($std_core_types.Cons(_y_215, _trmc_x10390_0));
            };
          }(_accm_0, x_2_10902.value);
          xs_0 = xs_0.tail;
          _accm_0 = _x16;
          continue tailcall;
        }
      }
    }
  }
}}
 
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if i.odd? then Nothing else Just(i*i) }) == [4]`
export function _unroll_filter_map_10008(xs_1, pred_3) /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>) -> e list<b> */  {
  var _x17 = $std_core_hnd._evv_is_affine();
  if (_x17) {
    return _trmc_unroll_filter_map_10008(xs_1, pred_3, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_unroll_filter_map_10008(xs_1, pred_3, function(_trmc_x10389 /* list<1393> */ ) {
        return _trmc_x10389;
      });
  }
}
 
 
// unrolling of singleton matches of std/core/list/@unroll-filter-map@10008
export function filter_map(xs, pred) /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>) -> e list<b> */  {
  if (xs === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_filter_map_10008(xs, pred);
  }
}
 
 
// monadic lift
export function _mlift_unroll_foreach_while_10009_10828(action, xx, _y_x10534) /* forall<a,b,e> (action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e maybe<b> */  {
  if (_y_x10534 === null) {
    return _unroll_foreach_while_10009(xx, action);
  }
  else {
    return _y_x10534;
  }
}
 
 
// Invoke `action` for each element of a list while `action` return `Nothing`
export function _unroll_foreach_while_10009(xs, action_0) /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e maybe<b> */  { tailcall: while(1)
{
  if (xs === null) {
    return $std_core_types.Nothing;
  }
  else {
     
    var x_0_10905 = action_0(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10534_0 /* maybe<1454> */ ) {
        return _mlift_unroll_foreach_while_10009_10828(action_0, xs.tail, _y_x10534_0);
      });
    }
    else {
      if (x_0_10905 === null) {
        {
          // tail call
          xs = xs.tail;
          continue tailcall;
        }
      }
      else {
        return x_0_10905;
      }
    }
  }
}}
 
 
// unrolling of singleton matches of std/core/list/@unroll-foreach-while@10009
export function foreach_while(xs, action) /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e maybe<b> */  {
  if (xs === null) {
    return $std_core_types.Nothing;
  }
  else {
    return _unroll_foreach_while_10009(xs, action);
  }
}
 
 
// monadic lift
export function _mlift_lift_find_10364_10829(_uniq_x_10297, _uniq_xx_10298, pred, _y_x10540) /* forall<a,e> (a, list<a>, pred : (a) -> e bool, bool) -> e maybe<a> */  {
  if (_y_x10540) {
    return $std_core_types.Just(_uniq_x_10297);
  }
  else {
    var _x18 = $std_core_types.Nothing;
    if (_x18 === null) {
      return _lift_find_10364(pred, _uniq_xx_10298);
    }
    else {
      return _x18;
    }
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
export function _lift_find_10364(pred_0, _uniq_xs_10293) /* forall<a,e> (pred : (a) -> e bool, list<a>) -> e maybe<a> */  { tailcall: while(1)
{
  if (_uniq_xs_10293 === null) {
    return $std_core_types.Nothing;
  }
  else {
     
    var x_10908 = pred_0(_uniq_xs_10293.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10540_0 /* bool */ ) {
        return _mlift_lift_find_10364_10829(_uniq_xs_10293.head, _uniq_xs_10293.tail, pred_0, _y_x10540_0);
      });
    }
    else {
      if (x_10908) {
        return $std_core_types.Just(_uniq_xs_10293.head);
      }
      else {
        var _x19 = $std_core_types.Nothing;
        if (_x19 === null) {
          {
            // tail call
            _uniq_xs_10293 = _uniq_xs_10293.tail;
            continue tailcall;
          }
        }
        else {
          return _x19;
        }
      }
    }
  }
}}
 
 
// Find the first element satisfying some predicate
export function find(xs, pred) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e maybe<a> */  {
  if (xs === null) {
    return $std_core_types.Nothing;
  }
  else {
    return _lift_find_10364(pred, xs);
  }
}
 
 
// Find the first element satisfying some predicate and return it.
export function find_maybe(xs, pred) /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>) -> e maybe<b> */  {
  if (xs === null) {
    return $std_core_types.Nothing;
  }
  else {
    return _unroll_foreach_while_10009(xs, pred);
  }
}
 
 
// Convert a `:maybe` type to a list type.
export function maybe_fs_list(m) /* forall<a> (m : maybe<a>) -> list<a> */  {
  if (m === null) {
    return $std_core_types.Nil;
  }
  else {
    return $std_core_types.Cons(m.value, $std_core_types.Nil);
  }
}
 
 
// Returns an integer list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.
export function _trmc_list(lo, hi, _acc) /* (lo : int, hi : int, ctx<list<int>>) -> list<int> */  { tailcall: while(1)
{
  if ($std_core_types._int_le(lo,hi)) {
     
    var _trmc_x10391 = undefined;
     
    var _trmc_x10392 = $std_core_types.Cons(lo, _trmc_x10391);
    {
      // tail call
      var _x20 = $std_core_types._int_add(lo,1);
      var _x21 = $std_core_types._cctx_extend(_acc,_trmc_x10392,({obj: _trmc_x10392, field_name: "tail"}));
      lo = _x20;
      _acc = _x21;
      continue tailcall;
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
  }
}}
 
 
// Returns an integer list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.
export function list(lo_0, hi_0) /* (lo : int, hi : int) -> list<int> */  {
  return _trmc_list(lo_0, hi_0, $std_core_types._cctx_empty());
}
 
 
// monadic lift
export function _mlift_trmc_unroll_map_10010_10830(_acc, f, xx, _trmc_x10393) /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e b, xx : list<a>, b) -> e list<b> */  {
   
  var _trmc_x10394 = undefined;
   
  var _trmc_x10395 = $std_core_types.Cons(_trmc_x10393, _trmc_x10394);
  return _trmc_unroll_map_10010(xx, f, $std_core_types._cctx_extend(_acc,_trmc_x10395,({obj: _trmc_x10395, field_name: "tail"})));
}
 
 
// monadic lift
export function _mlift_trmcm_unroll_map_10010_10831(_accm, f_0, xx_0, _trmc_x10398) /* forall<a,b,e> ((list<b>) -> list<b>, f : (a) -> e b, xx : list<a>, b) -> e list<b> */  {
  return _trmcm_unroll_map_10010(xx_0, f_0, function(_trmc_x10397 /* list<1969> */ ) {
      return _accm($std_core_types.Cons(_trmc_x10398, _trmc_x10397));
    });
}
 
 
// Apply a function `f` to each element of the input list in sequence.
export function _trmc_unroll_map_10010(xs, f_1, _acc_0) /* forall<a,b,e> (xs : list<a>, f : (a) -> e b, ctx<list<b>>) -> e list<b> */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_0_10911 = f_1(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10393_0 /* 1969 */ ) {
        return _mlift_trmc_unroll_map_10010_10830(_acc_0, f_1, xs.tail, _trmc_x10393_0);
      });
    }
    else {
       
      var _trmc_x10394_0 = undefined;
       
      var _trmc_x10395_0 = $std_core_types.Cons(x_0_10911, _trmc_x10394_0);
      {
        // tail call
        var _x22 = $std_core_types._cctx_extend(_acc_0,_trmc_x10395_0,({obj: _trmc_x10395_0, field_name: "tail"}));
        xs = xs.tail;
        _acc_0 = _x22;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
}}
 
 
// Apply a function `f` to each element of the input list in sequence.
export function _trmcm_unroll_map_10010(xs_0, f_2, _accm_0) /* forall<a,b,e> (xs : list<a>, f : (a) -> e b, (list<b>) -> list<b>) -> e list<b> */  { tailcall: while(1)
{
  if (xs_0 !== null) {
     
    var x_2_10914 = f_2(xs_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10398_0 /* 1969 */ ) {
        return _mlift_trmcm_unroll_map_10010_10831(_accm_0, f_2, xs_0.tail, _trmc_x10398_0);
      });
    }
    else {
      {
        // tail call
        var _x25 = function(__at_accm_023 /* (list<1969>) -> list<1969> */ , _x_2_1091424 /* 1969 */ ) {
          return function(_trmc_x10397_0 /* list<1969> */ ) {
            return __at_accm_023($std_core_types.Cons(_x_2_1091424, _trmc_x10397_0));
          };
        }(_accm_0, x_2_10914);
        xs_0 = xs_0.tail;
        _accm_0 = _x25;
        continue tailcall;
      }
    }
  }
  else {
    return _accm_0($std_core_types.Nil);
  }
}}
 
 
// Apply a function `f` to each element of the input list in sequence.
export function _unroll_map_10010(xs_1, f_3) /* forall<a,b,e> (xs : list<a>, f : (a) -> e b) -> e list<b> */  {
  var _x26 = $std_core_hnd._evv_is_affine();
  if (_x26) {
    return _trmc_unroll_map_10010(xs_1, f_3, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_unroll_map_10010(xs_1, f_3, function(_trmc_x10396 /* list<1969> */ ) {
        return _trmc_x10396;
      });
  }
}
 
 
// unrolling of singleton matches of std/core/list/@unroll-map@10010
export function map(xs, f) /* forall<a,b,e> (xs : list<a>, f : (a) -> e b) -> e list<b> */  {
  if (xs === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_map_10010(xs, f);
  }
}
 
 
// lifted local: char/list, @spec-x10309
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10304, using:
// @uniq-f@10304 = std/core/char/int/char
export function char_fs__trmc_lift_list_10365(_uniq_xs_10303, _acc) /* (list<int>, ctx<list<char>>) -> list<char> */  { tailcall: while(1)
{
  if (_uniq_xs_10303 !== null) {
     
    var _trmc_x10399 = ((_uniq_xs_10303.head));
     
    var _trmc_x10400 = undefined;
     
    var _trmc_x10401 = $std_core_types.Cons(_trmc_x10399, _trmc_x10400);
    {
      // tail call
      var _x27 = $std_core_types._cctx_extend(_acc,_trmc_x10401,({obj: _trmc_x10401, field_name: "tail"}));
      _uniq_xs_10303 = _uniq_xs_10303.tail;
      _acc = _x27;
      continue tailcall;
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
  }
}}
 
 
// lifted local: char/list, @spec-x10309
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10304, using:
// @uniq-f@10304 = std/core/char/int/char
export function char_fs__lift_list_10365(_uniq_xs_10303_0) /* (list<int>) -> list<char> */  {
  return char_fs__trmc_lift_list_10365(_uniq_xs_10303_0, $std_core_types._cctx_empty());
}
 
 
// Create a list of characters from `lo`  to `hi`  (including `hi`).
export function char_fs_list(lo, hi) /* (lo : char, hi : char) -> list<char> */  {
   
  var xs_10062 = list(lo, hi);
  if (xs_10062 === null) {
    return $std_core_types.Nil;
  }
  else {
    return char_fs__lift_list_10365(xs_10062);
  }
}
 
 
// monadic lift
export function function_fs__mlift_trmc_list_10832(_acc, f, hi, lo, _trmc_x10402) /* forall<a,e> (ctx<list<a>>, f : (int) -> e a, hi : int, lo : int, a) -> e list<a> */  {
   
  var _trmc_x10403 = undefined;
   
  var _trmc_x10404 = $std_core_types.Cons(_trmc_x10402, _trmc_x10403);
  return function_fs__trmc_list($std_core_types._int_add(lo,1), hi, f, $std_core_types._cctx_extend(_acc,_trmc_x10404,({obj: _trmc_x10404, field_name: "tail"})));
}
 
 
// monadic lift
export function function_fs__mlift_trmcm_list_10833(_accm, f_0, hi_0, lo_0, _trmc_x10407) /* forall<a,e> ((list<a>) -> list<a>, f : (int) -> e a, hi : int, lo : int, a) -> e list<a> */  {
  return function_fs__trmcm_list($std_core_types._int_add(lo_0,1), hi_0, f_0, function(_trmc_x10406 /* list<1754> */ ) {
      return _accm($std_core_types.Cons(_trmc_x10407, _trmc_x10406));
    });
}
 
 
// Applies a function `f` to list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.
export function function_fs__trmc_list(lo_1, hi_1, f_1, _acc_0) /* forall<a,e> (lo : int, hi : int, f : (int) -> e a, ctx<list<a>>) -> e list<a> */  { tailcall: while(1)
{
  if ($std_core_types._int_le(lo_1,hi_1)) {
     
    var x_10917 = f_1(lo_1);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10402_0 /* 1754 */ ) {
        return function_fs__mlift_trmc_list_10832(_acc_0, f_1, hi_1, lo_1, _trmc_x10402_0);
      });
    }
    else {
       
      var _trmc_x10403_0 = undefined;
       
      var _trmc_x10404_0 = $std_core_types.Cons(x_10917, _trmc_x10403_0);
      {
        // tail call
        var _x28 = $std_core_types._int_add(lo_1,1);
        var _x29 = $std_core_types._cctx_extend(_acc_0,_trmc_x10404_0,({obj: _trmc_x10404_0, field_name: "tail"}));
        lo_1 = _x28;
        _acc_0 = _x29;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
}}
 
 
// Applies a function `f` to list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.
export function function_fs__trmcm_list(lo_2, hi_2, f_2, _accm_0) /* forall<a,e> (lo : int, hi : int, f : (int) -> e a, (list<a>) -> list<a>) -> e list<a> */  { tailcall: while(1)
{
  if ($std_core_types._int_le(lo_2,hi_2)) {
     
    var x_0_10920 = f_2(lo_2);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10407_0 /* 1754 */ ) {
        return function_fs__mlift_trmcm_list_10833(_accm_0, f_2, hi_2, lo_2, _trmc_x10407_0);
      });
    }
    else {
      {
        // tail call
        var _x32 = $std_core_types._int_add(lo_2,1);
        var _x33 = function(__at_accm_030 /* (list<1754>) -> list<1754> */ , _x_0_1092031 /* 1754 */ ) {
          return function(_trmc_x10406_0 /* list<1754> */ ) {
            return __at_accm_030($std_core_types.Cons(_x_0_1092031, _trmc_x10406_0));
          };
        }(_accm_0, x_0_10920);
        lo_2 = _x32;
        _accm_0 = _x33;
        continue tailcall;
      }
    }
  }
  else {
    return _accm_0($std_core_types.Nil);
  }
}}
 
 
// Applies a function `f` to list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.
export function function_fs_list(lo_3, hi_3, f_3) /* forall<a,e> (lo : int, hi : int, f : (int) -> e a) -> e list<a> */  {
  var _x34 = $std_core_hnd._evv_is_affine();
  if (_x34) {
    return function_fs__trmc_list(lo_3, hi_3, f_3, $std_core_types._cctx_empty());
  }
  else {
    return function_fs__trmcm_list(lo_3, hi_3, f_3, function(_trmc_x10405 /* list<1754> */ ) {
        return _trmc_x10405;
      });
  }
}
 
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.
export function stride_fs__trmc_list(lo, hi, stride, _acc) /* (lo : int, hi : int, stride : int, ctx<list<int>>) -> list<int> */  { tailcall: while(1)
{
  if ($std_core_types._int_le(lo,hi)) {
     
    var _trmc_x10408 = undefined;
     
    var _trmc_x10409 = $std_core_types.Cons(lo, _trmc_x10408);
    {
      // tail call
      var _x35 = $std_core_types._int_add(lo,stride);
      var _x36 = $std_core_types._cctx_extend(_acc,_trmc_x10409,({obj: _trmc_x10409, field_name: "tail"}));
      lo = _x35;
      _acc = _x36;
      continue tailcall;
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
  }
}}
 
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.
export function stride_fs_list(lo_0, hi_0, stride_0) /* (lo : int, hi : int, stride : int) -> list<int> */  {
  return stride_fs__trmc_list(lo_0, hi_0, stride_0, $std_core_types._cctx_empty());
}
 
 
// monadic lift
export function stridefunction_fs__mlift_trmc_list_10834(_acc, f, hi, lo, stride, _trmc_x10410) /* forall<a,e> (ctx<list<a>>, f : (int) -> e a, hi : int, lo : int, stride : int, a) -> e list<a> */  {
   
  var _trmc_x10411 = undefined;
   
  var _trmc_x10412 = $std_core_types.Cons(_trmc_x10410, _trmc_x10411);
  return stridefunction_fs__trmc_list($std_core_types._int_add(lo,stride), hi, stride, f, $std_core_types._cctx_extend(_acc,_trmc_x10412,({obj: _trmc_x10412, field_name: "tail"})));
}
 
 
// monadic lift
export function stridefunction_fs__mlift_trmcm_list_10835(_accm, f_0, hi_0, lo_0, stride_0, _trmc_x10415) /* forall<a,e> ((list<a>) -> list<a>, f : (int) -> e a, hi : int, lo : int, stride : int, a) -> e list<a> */  {
  return stridefunction_fs__trmcm_list($std_core_types._int_add(lo_0,stride_0), hi_0, stride_0, f_0, function(_trmc_x10414 /* list<1873> */ ) {
      return _accm($std_core_types.Cons(_trmc_x10415, _trmc_x10414));
    });
}
 
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.
export function stridefunction_fs__trmc_list(lo_1, hi_1, stride_1, f_1, _acc_0) /* forall<a,e> (lo : int, hi : int, stride : int, f : (int) -> e a, ctx<list<a>>) -> e list<a> */  { tailcall: while(1)
{
  if ($std_core_types._int_le(lo_1,hi_1)) {
     
    var x_10923 = f_1(lo_1);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10410_0 /* 1873 */ ) {
        return stridefunction_fs__mlift_trmc_list_10834(_acc_0, f_1, hi_1, lo_1, stride_1, _trmc_x10410_0);
      });
    }
    else {
       
      var _trmc_x10411_0 = undefined;
       
      var _trmc_x10412_0 = $std_core_types.Cons(x_10923, _trmc_x10411_0);
      {
        // tail call
        var _x37 = $std_core_types._int_add(lo_1,stride_1);
        var _x38 = $std_core_types._cctx_extend(_acc_0,_trmc_x10412_0,({obj: _trmc_x10412_0, field_name: "tail"}));
        lo_1 = _x37;
        _acc_0 = _x38;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
}}
 
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.
export function stridefunction_fs__trmcm_list(lo_2, hi_2, stride_2, f_2, _accm_0) /* forall<a,e> (lo : int, hi : int, stride : int, f : (int) -> e a, (list<a>) -> list<a>) -> e list<a> */  { tailcall: while(1)
{
  if ($std_core_types._int_le(lo_2,hi_2)) {
     
    var x_0_10926 = f_2(lo_2);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10415_0 /* 1873 */ ) {
        return stridefunction_fs__mlift_trmcm_list_10835(_accm_0, f_2, hi_2, lo_2, stride_2, _trmc_x10415_0);
      });
    }
    else {
      {
        // tail call
        var _x41 = $std_core_types._int_add(lo_2,stride_2);
        var _x42 = function(__at_accm_039 /* (list<1873>) -> list<1873> */ , _x_0_1092640 /* 1873 */ ) {
          return function(_trmc_x10414_0 /* list<1873> */ ) {
            return __at_accm_039($std_core_types.Cons(_x_0_1092640, _trmc_x10414_0));
          };
        }(_accm_0, x_0_10926);
        lo_2 = _x41;
        _accm_0 = _x42;
        continue tailcall;
      }
    }
  }
  else {
    return _accm_0($std_core_types.Nil);
  }
}}
 
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.
export function stridefunction_fs_list(lo_3, hi_3, stride_3, f_3) /* forall<a,e> (lo : int, hi : int, stride : int, f : (int) -> e a) -> e list<a> */  {
  var _x43 = $std_core_hnd._evv_is_affine();
  if (_x43) {
    return stridefunction_fs__trmc_list(lo_3, hi_3, stride_3, f_3, $std_core_types._cctx_empty());
  }
  else {
    return stridefunction_fs__trmcm_list(lo_3, hi_3, stride_3, f_3, function(_trmc_x10413 /* list<1873> */ ) {
        return _trmc_x10413;
      });
  }
}
 
 
// Apply a function `f` to each character in a string
export function string_fs_map(s, f) /* forall<e> (s : string, f : (char) -> e char) -> e string */  {
   
  var xs_10066 = $std_core_string.list(s);
   
  if (xs_10066 === null) {
    var x_10929 = $std_core_types.Nil;
  }
  else {
    var x_10929 = _unroll_map_10010(xs_10066, f);
  }
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend($std_core_string.listchar_fs_string);
  }
  else {
    return $std_core_string.listchar_fs_string(x_10929);
  }
}
 
 
// monadic lift
export function _mlift_trmc_unroll_lift_map_indexed_4949_10011_10836(_acc, f, i_0_10069, yy, _trmc_x10416) /* forall<a,b,e> (ctx<list<b>>, f : (idx : int, value : a) -> e b, i@0@10069 : int, yy : list<a>, b) -> e list<b> */  {
   
  var _trmc_x10417 = undefined;
   
  var _trmc_x10418 = $std_core_types.Cons(_trmc_x10416, _trmc_x10417);
  return _trmc_unroll_lift_map_indexed_4949_10011(f, yy, i_0_10069, $std_core_types._cctx_extend(_acc,_trmc_x10418,({obj: _trmc_x10418, field_name: "tail"})));
}
 
 
// monadic lift
export function _mlift_trmcm_unroll_lift_map_indexed_4949_10011_10837(_accm, f_0, i_0_10069_0, yy_0, _trmc_x10421) /* forall<a,b,e> ((list<b>) -> list<b>, f : (idx : int, value : a) -> e b, i@0@10069 : int, yy : list<a>, b) -> e list<b> */  {
  return _trmcm_unroll_lift_map_indexed_4949_10011(f_0, yy_0, i_0_10069_0, function(_trmc_x10420 /* list<2069> */ ) {
      return _accm($std_core_types.Cons(_trmc_x10421, _trmc_x10420));
    });
}
 
 
// lifted local: map-indexed, map-idx
export function _trmc_unroll_lift_map_indexed_4949_10011(f_1, ys, i, _acc_0) /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int, ctx<list<b>>) -> e list<b> */  { tailcall: while(1)
{
  if (ys !== null) {
     
    var i_0_10069_1 = $std_core_types._int_add(i,1);
     
    var x_10931 = f_1(i, ys.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10416_0 /* 2069 */ ) {
        return _mlift_trmc_unroll_lift_map_indexed_4949_10011_10836(_acc_0, f_1, i_0_10069_1, ys.tail, _trmc_x10416_0);
      });
    }
    else {
       
      var _trmc_x10417_0 = undefined;
       
      var _trmc_x10418_0 = $std_core_types.Cons(x_10931, _trmc_x10417_0);
      {
        // tail call
        var _x44 = $std_core_types._cctx_extend(_acc_0,_trmc_x10418_0,({obj: _trmc_x10418_0, field_name: "tail"}));
        ys = ys.tail;
        i = i_0_10069_1;
        _acc_0 = _x44;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
}}
 
 
// lifted local: map-indexed, map-idx
export function _trmcm_unroll_lift_map_indexed_4949_10011(f_2, ys_0, i_0, _accm_0) /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int, (list<b>) -> list<b>) -> e list<b> */  { tailcall: while(1)
{
  if (ys_0 !== null) {
     
    var i_0_10069_2 = $std_core_types._int_add(i_0,1);
     
    var x_0_10934 = f_2(i_0, ys_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10421_0 /* 2069 */ ) {
        return _mlift_trmcm_unroll_lift_map_indexed_4949_10011_10837(_accm_0, f_2, i_0_10069_2, ys_0.tail, _trmc_x10421_0);
      });
    }
    else {
      {
        // tail call
        var _x47 = function(__at_accm_045 /* (list<2069>) -> list<2069> */ , _x_0_1093446 /* 2069 */ ) {
          return function(_trmc_x10420_0 /* list<2069> */ ) {
            return __at_accm_045($std_core_types.Cons(_x_0_1093446, _trmc_x10420_0));
          };
        }(_accm_0, x_0_10934);
        ys_0 = ys_0.tail;
        i_0 = i_0_10069_2;
        _accm_0 = _x47;
        continue tailcall;
      }
    }
  }
  else {
    return _accm_0($std_core_types.Nil);
  }
}}
 
 
// lifted local: map-indexed, map-idx
export function _unroll_lift_map_indexed_4949_10011(f_3, ys_1, i_1) /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int) -> e list<b> */  {
  var _x48 = $std_core_hnd._evv_is_affine();
  if (_x48) {
    return _trmc_unroll_lift_map_indexed_4949_10011(f_3, ys_1, i_1, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_unroll_lift_map_indexed_4949_10011(f_3, ys_1, i_1, function(_trmc_x10419 /* list<2069> */ ) {
        return _trmc_x10419;
      });
  }
}
 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-map-indexed@4949@10011
export function _lift_map_indexed_4949(f, ys, i) /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int) -> e list<b> */  {
  if (ys === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_lift_map_indexed_4949_10011(f, ys, i);
  }
}
 
 
// Apply a function `f` to each element of the input list in sequence where takes
// both the index of the current element and the element itself as arguments.
export function map_indexed(xs, f) /* forall<a,b,e> (xs : list<a>, f : (idx : int, value : a) -> e b) -> e list<b> */  {
  if (xs === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_lift_map_indexed_4949_10011(f, xs, 0);
  }
}
 
 
// monadic lift
export function _mlift_trmc_unroll_lift_map_peek_4950_10012_10838(_acc, f, yy, _trmc_x10422) /* forall<a,b,e> (ctx<list<b>>, f : (value : a, rest : list<a>) -> e b, yy : list<a>, b) -> e list<b> */  {
   
  var _trmc_x10423 = undefined;
   
  var _trmc_x10424 = $std_core_types.Cons(_trmc_x10422, _trmc_x10423);
  return _trmc_unroll_lift_map_peek_4950_10012(f, yy, $std_core_types._cctx_extend(_acc,_trmc_x10424,({obj: _trmc_x10424, field_name: "tail"})));
}
 
 
// monadic lift
export function _mlift_trmcm_unroll_lift_map_peek_4950_10012_10839(_accm, f_0, yy_0, _trmc_x10427) /* forall<a,b,e> ((list<b>) -> list<b>, f : (value : a, rest : list<a>) -> e b, yy : list<a>, b) -> e list<b> */  {
  return _trmcm_unroll_lift_map_peek_4950_10012(f_0, yy_0, function(_trmc_x10426 /* list<2121> */ ) {
      return _accm($std_core_types.Cons(_trmc_x10427, _trmc_x10426));
    });
}
 
 
// lifted local: map-peek, mappeek
export function _trmc_unroll_lift_map_peek_4950_10012(f_1, ys, _acc_0) /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>, ctx<list<b>>) -> e list<b> */  { tailcall: while(1)
{
  if (ys !== null) {
     
    var x_10937 = f_1(ys.head, ys.tail);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10422_0 /* 2121 */ ) {
        return _mlift_trmc_unroll_lift_map_peek_4950_10012_10838(_acc_0, f_1, ys.tail, _trmc_x10422_0);
      });
    }
    else {
       
      var _trmc_x10423_0 = undefined;
       
      var _trmc_x10424_0 = $std_core_types.Cons(x_10937, _trmc_x10423_0);
      {
        // tail call
        var _x49 = $std_core_types._cctx_extend(_acc_0,_trmc_x10424_0,({obj: _trmc_x10424_0, field_name: "tail"}));
        ys = ys.tail;
        _acc_0 = _x49;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
}}
 
 
// lifted local: map-peek, mappeek
export function _trmcm_unroll_lift_map_peek_4950_10012(f_2, ys_0, _accm_0) /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>, (list<b>) -> list<b>) -> e list<b> */  { tailcall: while(1)
{
  if (ys_0 !== null) {
     
    var x_0_10940 = f_2(ys_0.head, ys_0.tail);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10427_0 /* 2121 */ ) {
        return _mlift_trmcm_unroll_lift_map_peek_4950_10012_10839(_accm_0, f_2, ys_0.tail, _trmc_x10427_0);
      });
    }
    else {
      {
        // tail call
        var _x52 = function(__at_accm_050 /* (list<2121>) -> list<2121> */ , _x_0_1094051 /* 2121 */ ) {
          return function(_trmc_x10426_0 /* list<2121> */ ) {
            return __at_accm_050($std_core_types.Cons(_x_0_1094051, _trmc_x10426_0));
          };
        }(_accm_0, x_0_10940);
        ys_0 = ys_0.tail;
        _accm_0 = _x52;
        continue tailcall;
      }
    }
  }
  else {
    return _accm_0($std_core_types.Nil);
  }
}}
 
 
// lifted local: map-peek, mappeek
export function _unroll_lift_map_peek_4950_10012(f_3, ys_1) /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>) -> e list<b> */  {
  var _x53 = $std_core_hnd._evv_is_affine();
  if (_x53) {
    return _trmc_unroll_lift_map_peek_4950_10012(f_3, ys_1, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_unroll_lift_map_peek_4950_10012(f_3, ys_1, function(_trmc_x10425 /* list<2121> */ ) {
        return _trmc_x10425;
      });
  }
}
 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-map-peek@4950@10012
export function _lift_map_peek_4950(f, ys) /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>) -> e list<b> */  {
  if (ys === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_lift_map_peek_4950_10012(f, ys);
  }
}
 
 
// Apply a function `f` to each element of the input list in sequence where `f` takes
// both the current element and the tail list as arguments.
export function map_peek(xs, f) /* forall<a,b,e> (xs : list<a>, f : (value : a, rest : list<a>) -> e b) -> e list<b> */  {
  if (xs === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_lift_map_peek_4950_10012(f, xs);
  }
}
 
 
// monadic lift
export function _mlift_trmc_unroll_lift_map_indexed_peek_4951_10013_10840(_acc, f, i_0_10077, yy, _trmc_x10428) /* forall<a,b,e> (ctx<list<b>>, f : (idx : int, value : a, rest : list<a>) -> e b, i@0@10077 : int, yy : list<a>, b) -> e list<b> */  {
   
  var _trmc_x10429 = undefined;
   
  var _trmc_x10430 = $std_core_types.Cons(_trmc_x10428, _trmc_x10429);
  return _trmc_unroll_lift_map_indexed_peek_4951_10013(f, yy, i_0_10077, $std_core_types._cctx_extend(_acc,_trmc_x10430,({obj: _trmc_x10430, field_name: "tail"})));
}
 
 
// monadic lift
export function _mlift_trmcm_unroll_lift_map_indexed_peek_4951_10013_10841(_accm, f_0, i_0_10077_0, yy_0, _trmc_x10433) /* forall<a,b,e> ((list<b>) -> list<b>, f : (idx : int, value : a, rest : list<a>) -> e b, i@0@10077 : int, yy : list<a>, b) -> e list<b> */  {
  return _trmcm_unroll_lift_map_indexed_peek_4951_10013(f_0, yy_0, i_0_10077_0, function(_trmc_x10432 /* list<2183> */ ) {
      return _accm($std_core_types.Cons(_trmc_x10433, _trmc_x10432));
    });
}
 
 
// lifted local: map-indexed-peek, mapidx
export function _trmc_unroll_lift_map_indexed_peek_4951_10013(f_1, ys, i, _acc_0) /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int, ctx<list<b>>) -> e list<b> */  { tailcall: while(1)
{
  if (ys !== null) {
     
    var i_0_10077_1 = $std_core_types._int_add(i,1);
     
    var x_10943 = f_1(i, ys.head, ys.tail);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10428_0 /* 2183 */ ) {
        return _mlift_trmc_unroll_lift_map_indexed_peek_4951_10013_10840(_acc_0, f_1, i_0_10077_1, ys.tail, _trmc_x10428_0);
      });
    }
    else {
       
      var _trmc_x10429_0 = undefined;
       
      var _trmc_x10430_0 = $std_core_types.Cons(x_10943, _trmc_x10429_0);
      {
        // tail call
        var _x54 = $std_core_types._cctx_extend(_acc_0,_trmc_x10430_0,({obj: _trmc_x10430_0, field_name: "tail"}));
        ys = ys.tail;
        i = i_0_10077_1;
        _acc_0 = _x54;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
}}
 
 
// lifted local: map-indexed-peek, mapidx
export function _trmcm_unroll_lift_map_indexed_peek_4951_10013(f_2, ys_0, i_0, _accm_0) /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int, (list<b>) -> list<b>) -> e list<b> */  { tailcall: while(1)
{
  if (ys_0 !== null) {
     
    var i_0_10077_2 = $std_core_types._int_add(i_0,1);
     
    var x_0_10946 = f_2(i_0, ys_0.head, ys_0.tail);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10433_0 /* 2183 */ ) {
        return _mlift_trmcm_unroll_lift_map_indexed_peek_4951_10013_10841(_accm_0, f_2, i_0_10077_2, ys_0.tail, _trmc_x10433_0);
      });
    }
    else {
      {
        // tail call
        var _x57 = function(__at_accm_055 /* (list<2183>) -> list<2183> */ , _x_0_1094656 /* 2183 */ ) {
          return function(_trmc_x10432_0 /* list<2183> */ ) {
            return __at_accm_055($std_core_types.Cons(_x_0_1094656, _trmc_x10432_0));
          };
        }(_accm_0, x_0_10946);
        ys_0 = ys_0.tail;
        i_0 = i_0_10077_2;
        _accm_0 = _x57;
        continue tailcall;
      }
    }
  }
  else {
    return _accm_0($std_core_types.Nil);
  }
}}
 
 
// lifted local: map-indexed-peek, mapidx
export function _unroll_lift_map_indexed_peek_4951_10013(f_3, ys_1, i_1) /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int) -> e list<b> */  {
  var _x58 = $std_core_hnd._evv_is_affine();
  if (_x58) {
    return _trmc_unroll_lift_map_indexed_peek_4951_10013(f_3, ys_1, i_1, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_unroll_lift_map_indexed_peek_4951_10013(f_3, ys_1, i_1, function(_trmc_x10431 /* list<2183> */ ) {
        return _trmc_x10431;
      });
  }
}
 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-map-indexed-peek@4951@10013
export function _lift_map_indexed_peek_4951(f, ys, i) /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int) -> e list<b> */  {
  if (ys === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_lift_map_indexed_peek_4951_10013(f, ys, i);
  }
}
 
 
// Apply a function `f` to each element of the input list in sequence where takes
// both the index of the current element, the element itself, and the tail list as arguments.
export function map_indexed_peek(xs, f) /* forall<a,b,e> (xs : list<a>, f : (idx : int, value : a, rest : list<a>) -> e b) -> e list<b> */  {
  if (xs === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_lift_map_indexed_peek_4951_10013(f, xs, 0);
  }
}
 
 
// Create a list of `n` repeated elements `x`
export function _trmc_replicate(x, n, _acc) /* forall<a> (x : a, n : int, ctx<list<a>>) -> list<a> */  { tailcall: while(1)
{
  if ($std_core_types._int_gt(n,0)) {
     
    var _trmc_x10434 = undefined;
     
    var _trmc_x10435 = $std_core_types.Cons(x, _trmc_x10434);
    {
      // tail call
      var _x59 = $std_core_types._int_sub(n,1);
      var _x60 = $std_core_types._cctx_extend(_acc,_trmc_x10435,({obj: _trmc_x10435, field_name: "tail"}));
      n = _x59;
      _acc = _x60;
      continue tailcall;
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
  }
}}
 
 
// Create a list of `n` repeated elements `x`
export function replicate(x_0, n_0) /* forall<a> (x : a, n : int) -> list<a> */  {
  return _trmc_replicate(x_0, n_0, $std_core_types._cctx_empty());
}
 
 
// monadic lift
export function _mlift_trmc_lift_remove_10366_10842(_acc, _uniq_x_10313, _uniq_xx_10314, pred, _y_x10619) /* forall<a,e> (ctx<list<a>>, a, list<a>, pred : (a) -> e bool, bool) -> e list<a> */  {
  if (_y_x10619) {
    return _trmc_lift_remove_10366(pred, _uniq_xx_10314, _acc);
  }
  else {
     
    var _trmc_x10436 = undefined;
     
    var _trmc_x10437 = $std_core_types.Cons(_uniq_x_10313, _trmc_x10436);
    return _trmc_lift_remove_10366(pred, _uniq_xx_10314, $std_core_types._cctx_extend(_acc,_trmc_x10437,({obj: _trmc_x10437, field_name: "tail"})));
  }
}
 
 
// monadic lift
export function _mlift_trmcm_lift_remove_10366_10843(_accm, _uniq_x_10313_0, _uniq_xx_10314_0, pred_0, _y_x10624) /* forall<a,e> ((list<a>) -> list<a>, a, list<a>, pred : (a) -> e bool, bool) -> e list<a> */  {
  if (_y_x10624) {
    return _trmcm_lift_remove_10366(pred_0, _uniq_xx_10314_0, _accm);
  }
  else {
    return _trmcm_lift_remove_10366(pred_0, _uniq_xx_10314_0, function(_trmc_x10439 /* list<2269> */ ) {
        return _accm($std_core_types.Cons(_uniq_x_10313_0, _trmc_x10439));
      });
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
export function _trmc_lift_remove_10366(pred_1, _uniq_xs_10310, _acc_0) /* forall<a,e> (pred : (a) -> e bool, list<a>, ctx<list<a>>) -> e list<a> */  { tailcall: while(1)
{
  if (_uniq_xs_10310 !== null) {
     
    var x_10949 = pred_1(_uniq_xs_10310.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10619_0 /* bool */ ) {
        return _mlift_trmc_lift_remove_10366_10842(_acc_0, _uniq_xs_10310.head, _uniq_xs_10310.tail, pred_1, _y_x10619_0);
      });
    }
    else {
      if (x_10949) {
        {
          // tail call
          _uniq_xs_10310 = _uniq_xs_10310.tail;
          continue tailcall;
        }
      }
      else {
         
        var _trmc_x10436_0 = undefined;
         
        var _trmc_x10437_0 = $std_core_types.Cons(_uniq_xs_10310.head, _trmc_x10436_0);
        {
          // tail call
          var _x61 = $std_core_types._cctx_extend(_acc_0,_trmc_x10437_0,({obj: _trmc_x10437_0, field_name: "tail"}));
          _uniq_xs_10310 = _uniq_xs_10310.tail;
          _acc_0 = _x61;
          continue tailcall;
        }
      }
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
}}
 
 
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
export function _trmcm_lift_remove_10366(pred_2, _uniq_xs_10310_0, _accm_0) /* forall<a,e> (pred : (a) -> e bool, list<a>, (list<a>) -> list<a>) -> e list<a> */  { tailcall: while(1)
{
  if (_uniq_xs_10310_0 !== null) {
     
    var x_0_10952 = pred_2(_uniq_xs_10310_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10624_0 /* bool */ ) {
        return _mlift_trmcm_lift_remove_10366_10843(_accm_0, _uniq_xs_10310_0.head, _uniq_xs_10310_0.tail, pred_2, _y_x10624_0);
      });
    }
    else {
      if (x_0_10952) {
        {
          // tail call
          _uniq_xs_10310_0 = _uniq_xs_10310_0.tail;
          continue tailcall;
        }
      }
      else {
        {
          // tail call
          var _x64 = function(__at_accm_062 /* (list<2269>) -> list<2269> */ , __at_uniq_x_10313_263 /* 2269 */ ) {
            return function(_trmc_x10439_0 /* list<2269> */ ) {
              return __at_accm_062($std_core_types.Cons(__at_uniq_x_10313_263, _trmc_x10439_0));
            };
          }(_accm_0, _uniq_xs_10310_0.head);
          _uniq_xs_10310_0 = _uniq_xs_10310_0.tail;
          _accm_0 = _x64;
          continue tailcall;
        }
      }
    }
  }
  else {
    return _accm_0($std_core_types.Nil);
  }
}}
 
 
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
export function _lift_remove_10366(pred_3, _uniq_xs_10310_1) /* forall<a,e> (pred : (a) -> e bool, list<a>) -> e list<a> */  {
  var _x65 = $std_core_hnd._evv_is_affine();
  if (_x65) {
    return _trmc_lift_remove_10366(pred_3, _uniq_xs_10310_1, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_lift_remove_10366(pred_3, _uniq_xs_10310_1, function(_trmc_x10438 /* list<2269> */ ) {
        return _trmc_x10438;
      });
  }
}
 
 
// Remove those elements of a list that satisfy the given predicate `pred`.
// For example: `remove([1,2,3],odd?) == [2]`
export function remove(xs, pred) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e list<a> */  {
  if (xs === null) {
    return $std_core_types.Nil;
  }
  else {
    return _lift_remove_10366(pred, xs);
  }
}
 
 
// monadic lift
export function _mlift_unroll_partition_acc_10014_10844(acc1, acc2, pred, x, xx, _y_x10634) /* forall<a,e> (acc1 : ctx<list<a>>, acc2 : ctx<list<a>>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e (list<a>, list<a>) */  {
  if (_y_x10634) {
     
    var _cctx_x2361 = $std_core_types.Cons(x, undefined);
     
    var _cctx_x2362 = {obj: _cctx_x2361, field_name: "tail"};
    return _unroll_partition_acc_10014(xx, pred, $std_core_types._cctx_compose(acc1,($std_core_types._cctx_create(_cctx_x2361,_cctx_x2362))), acc2);
  }
  else {
     
    var _cctx_x2404 = $std_core_types.Cons(x, undefined);
     
    var _cctx_x2405 = {obj: _cctx_x2404, field_name: "tail"};
    return _unroll_partition_acc_10014(xx, pred, acc1, $std_core_types._cctx_compose(acc2,($std_core_types._cctx_create(_cctx_x2404,_cctx_x2405))));
  }
}
 
export function _unroll_partition_acc_10014(xs, pred_0, acc1_0, acc2_0) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, acc1 : ctx<list<a>>, acc2 : ctx<list<a>>) -> e (list<a>, list<a>) */  { tailcall: while(1)
{
  if (xs === null) {
    return $std_core_types.Tuple2($std_core_types._cctx_apply(acc1_0,($std_core_types.Nil)), $std_core_types._cctx_apply(acc2_0,($std_core_types.Nil)));
  }
  else {
     
    var x_1_10955 = pred_0(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10634_0 /* bool */ ) {
        return _mlift_unroll_partition_acc_10014_10844(acc1_0, acc2_0, pred_0, xs.head, xs.tail, _y_x10634_0);
      });
    }
    else {
      if (x_1_10955) {
         
        var _cctx_x2361_0 = $std_core_types.Cons(xs.head, undefined);
         
        var _cctx_x2362_0 = {obj: _cctx_x2361_0, field_name: "tail"};
        {
          // tail call
          var _x66 = $std_core_types._cctx_compose(acc1_0,($std_core_types._cctx_create(_cctx_x2361_0,_cctx_x2362_0)));
          xs = xs.tail;
          acc1_0 = _x66;
          continue tailcall;
        }
      }
      else {
         
        var _cctx_x2404_0 = $std_core_types.Cons(xs.head, undefined);
         
        var _cctx_x2405_0 = {obj: _cctx_x2404_0, field_name: "tail"};
        {
          // tail call
          var _x67 = $std_core_types._cctx_compose(acc2_0,($std_core_types._cctx_create(_cctx_x2404_0,_cctx_x2405_0)));
          xs = xs.tail;
          acc2_0 = _x67;
          continue tailcall;
        }
      }
    }
  }
}}
 
 
// unrolling of singleton matches of std/core/list/@unroll-partition-acc@10014
export function partition_acc(xs, pred, acc1, acc2) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, acc1 : ctx<list<a>>, acc2 : ctx<list<a>>) -> e (list<a>, list<a>) */  {
  if (xs === null) {
    return $std_core_types.Tuple2($std_core_types._cctx_apply(acc1,($std_core_types.Nil)), $std_core_types._cctx_apply(acc2,($std_core_types.Nil)));
  }
  else {
    return _unroll_partition_acc_10014(xs, pred, acc1, acc2);
  }
}
 
 
// Partition a list in two lists where the first list contains
// those elements that satisfy the given predicate `pred`.
// For example: `partition([1,2,3],odd?) == ([1,3],[2])`
export function partition(xs, pred) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e (list<a>, list<a>) */  {
   
  var acc1_10086 = $std_core_types._cctx_empty();
   
  var acc2_10087 = $std_core_types._cctx_empty();
  if (xs === null) {
    return $std_core_types.Tuple2($std_core_types._cctx_apply(acc1_10086,($std_core_types.Nil)), $std_core_types._cctx_apply(acc2_10087,($std_core_types.Nil)));
  }
  else {
    return _unroll_partition_acc_10014(xs, pred, acc1_10086, acc2_10087);
  }
}
 
 
// monadic lift
export function _mlift_lift_lookup_10367_10845(_uniq_x_10324, _uniq_xx_10325, pred, _y_x10643) /* forall<a,b,e> ((a, b), list<(a, b)>, pred : (a) -> e bool, bool) -> e maybe<b> */  {
  if (_y_x10643) {
    var _x68 = _uniq_x_10324.snd;
    return $std_core_types.Just(_x68);
  }
  else {
    var _x69 = $std_core_types.Nothing;
    if (_x69 === null) {
      return _lift_lookup_10367(pred, _uniq_xx_10325);
    }
    else {
      return _x69;
    }
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
export function _lift_lookup_10367(pred_0, _uniq_xs_10320) /* forall<a,b,e> (pred : (a) -> e bool, list<(a, b)>) -> e maybe<b> */  { tailcall: while(1)
{
  if (_uniq_xs_10320 === null) {
    return $std_core_types.Nothing;
  }
  else {
     
    var _x70 = _uniq_xs_10320.head.fst;
    var x_10958 = pred_0(_x70);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10643_0 /* bool */ ) {
        return _mlift_lift_lookup_10367_10845(_uniq_xs_10320.head, _uniq_xs_10320.tail, pred_0, _y_x10643_0);
      });
    }
    else {
      if (x_10958) {
        var _x70 = _uniq_xs_10320.head.snd;
        return $std_core_types.Just(_x70);
      }
      else {
        var _x71 = $std_core_types.Nothing;
        if (_x71 === null) {
          {
            // tail call
            _uniq_xs_10320 = _uniq_xs_10320.tail;
            continue tailcall;
          }
        }
        else {
          return _x71;
        }
      }
    }
  }
}}
 
 
// Lookup the first element satisfying some predicate
export function lookup(xs, pred) /* forall<a,b,e> (xs : list<(a, b)>, pred : (a) -> e bool) -> e maybe<b> */  {
  if (xs === null) {
    return $std_core_types.Nothing;
  }
  else {
    return _lift_lookup_10367(pred, xs);
  }
}
 
 
// monadic lift
export function _mlift_unroll_index_of_acc_10015_10846(idx, pred, xx, _y_x10650) /* forall<a,e> (idx : int, pred : (a) -> e bool, xx : list<a>, bool) -> e int */  {
  if (_y_x10650) {
    return idx;
  }
  else {
    return _unroll_index_of_acc_10015(xx, pred, $std_core_types._int_add(idx,1));
  }
}
 
export function _unroll_index_of_acc_10015(xs, pred_0, idx_0) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, idx : int) -> e int */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_0_10961 = pred_0(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10650_0 /* bool */ ) {
        return _mlift_unroll_index_of_acc_10015_10846(idx_0, pred_0, xs.tail, _y_x10650_0);
      });
    }
    else {
      if (x_0_10961) {
        return idx_0;
      }
      else {
        {
          // tail call
          var _x72 = $std_core_types._int_add(idx_0,1);
          xs = xs.tail;
          idx_0 = _x72;
          continue tailcall;
        }
      }
    }
  }
  else {
    return -1;
  }
}}
 
 
// unrolling of singleton matches of std/core/list/@unroll-index-of-acc@10015
export function index_of_acc(xs, pred, idx) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, idx : int) -> e int */  {
  if (xs === null) {
    return -1;
  }
  else {
    return _unroll_index_of_acc_10015(xs, pred, idx);
  }
}
 
 
// Returns the index of the first element where `pred` holds, or `-1` if no such element exists.
export function index_of(xs, pred) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e int */  {
  if (xs === null) {
    return -1;
  }
  else {
    return _unroll_index_of_acc_10015(xs, pred, 0);
  }
}
 
 
// monadic lift
export function _mlift_unroll_foreach_10016_10847(action, xx, wild__) /* forall<a,e> (action : (a) -> e (), xx : list<a>, wild_ : ()) -> e () */  {
  return _unroll_foreach_10016(xx, action);
}
 
 
// Invoke `action` for each element of a list
export function _unroll_foreach_10016(xs, action_0) /* forall<a,e> (xs : list<a>, action : (a) -> e ()) -> e () */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_0_10964 = action_0(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(wild___0 /* () */ ) {
        return _mlift_unroll_foreach_10016_10847(action_0, xs.tail, wild___0);
      });
    }
    else {
      {
        // tail call
        xs = xs.tail;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types.Unit;
  }
}}
 
 
// unrolling of singleton matches of std/core/list/@unroll-foreach@10016
export function foreach(xs, action) /* forall<a,e> (xs : list<a>, action : (a) -> e ()) -> e () */  {
  if (xs === null) {
    return $std_core_types.Unit;
  }
  else {
    return _unroll_foreach_10016(xs, action);
  }
}
 
 
// monadic lift
export function _mlift_trmc_unroll_map_while_10017_10848(_acc, action, xx, _y_x10663) /* forall<a,b,e> (ctx<list<b>>, action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */  {
  if (_y_x10663 !== null) {
     
    var _trmc_x10440 = undefined;
     
    var _trmc_x10441 = $std_core_types.Cons(_y_x10663.value, _trmc_x10440);
    return _trmc_unroll_map_while_10017(xx, action, $std_core_types._cctx_extend(_acc,_trmc_x10441,({obj: _trmc_x10441, field_name: "tail"})));
  }
  else {
    return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
  }
}
 
 
// monadic lift
export function _mlift_trmcm_unroll_map_while_10017_10849(_accm, action_0, xx_0, _y_x10667) /* forall<a,b,e> ((list<b>) -> list<b>, action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */  {
  if (_y_x10667 !== null) {
    return _trmcm_unroll_map_while_10017(xx_0, action_0, function(_trmc_x10443 /* list<2754> */ ) {
        return _accm($std_core_types.Cons(_y_x10667.value, _trmc_x10443));
      });
  }
  else {
    return _accm($std_core_types.Nil);
  }
}
 
 
// Invoke `action` on each element of a list while `action` returns `Just`
export function _trmc_unroll_map_while_10017(xs, action_1, _acc_0) /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */  { tailcall: while(1)
{
  if (xs === null) {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
  else {
     
    var x_0_10967 = action_1(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10663_0 /* maybe<2754> */ ) {
        return _mlift_trmc_unroll_map_while_10017_10848(_acc_0, action_1, xs.tail, _y_x10663_0);
      });
    }
    else {
      if (x_0_10967 !== null) {
         
        var _trmc_x10440_0 = undefined;
         
        var _trmc_x10441_0 = $std_core_types.Cons(x_0_10967.value, _trmc_x10440_0);
        {
          // tail call
          var _x73 = $std_core_types._cctx_extend(_acc_0,_trmc_x10441_0,({obj: _trmc_x10441_0, field_name: "tail"}));
          xs = xs.tail;
          _acc_0 = _x73;
          continue tailcall;
        }
      }
      else {
        return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
      }
    }
  }
}}
 
 
// Invoke `action` on each element of a list while `action` returns `Just`
export function _trmcm_unroll_map_while_10017(xs_0, action_2, _accm_0) /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>, (list<b>) -> list<b>) -> e list<b> */  { tailcall: while(1)
{
  if (xs_0 === null) {
    return _accm_0($std_core_types.Nil);
  }
  else {
     
    var x_2_10970 = action_2(xs_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10667_0 /* maybe<2754> */ ) {
        return _mlift_trmcm_unroll_map_while_10017_10849(_accm_0, action_2, xs_0.tail, _y_x10667_0);
      });
    }
    else {
      if (x_2_10970 !== null) {
        {
          // tail call
          var _x76 = function(__at_accm_074 /* (list<2754>) -> list<2754> */ , _y_275 /* 2754 */ ) {
            return function(_trmc_x10443_0 /* list<2754> */ ) {
              return __at_accm_074($std_core_types.Cons(_y_275, _trmc_x10443_0));
            };
          }(_accm_0, x_2_10970.value);
          xs_0 = xs_0.tail;
          _accm_0 = _x76;
          continue tailcall;
        }
      }
      else {
        return _accm_0($std_core_types.Nil);
      }
    }
  }
}}
 
 
// Invoke `action` on each element of a list while `action` returns `Just`
export function _unroll_map_while_10017(xs_1, action_3) /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e list<b> */  {
  var _x77 = $std_core_hnd._evv_is_affine();
  if (_x77) {
    return _trmc_unroll_map_while_10017(xs_1, action_3, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_unroll_map_while_10017(xs_1, action_3, function(_trmc_x10442 /* list<2754> */ ) {
        return _trmc_x10442;
      });
  }
}
 
 
// unrolling of singleton matches of std/core/list/@unroll-map-while@10017
export function map_while(xs, action) /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e list<b> */  {
  if (xs === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_map_while_10017(xs, action);
  }
}
 
 
// monadic lift
export function _mlift_lift_foreach_indexed_10368_10850(_uniq_xx_10334, action, i, _uniq_x___10335) /* forall<h,a,e> (list<a>, action : (int, a) -> e (), i : local-var<h,int>, ()) -> <local<h>|e> () */  {
  return _lift_foreach_indexed_10368(action, i, _uniq_xx_10334);
}
 
 
// monadic lift
export function _mlift_lift_foreach_indexed_10368_10851(_uniq_xx_10334_0, action_0, i_0, _y_x10679) /* forall<h,a,e> (list<a>, action : (int, a) -> e (), i : local-var<h,int>, int) -> <local<h>|e> () */  {
   
  var x_10973 = ((i_0).value = ($std_core_types._int_add(_y_x10679,1)));
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(_uniq_x___10335_0 /* () */ ) {
      return _mlift_lift_foreach_indexed_10368_10850(_uniq_xx_10334_0, action_0, i_0, _uniq_x___10335_0);
    });
  }
  else {
    return _mlift_lift_foreach_indexed_10368_10850(_uniq_xx_10334_0, action_0, i_0, x_10973);
  }
}
 
 
// monadic lift
export function _mlift_lift_foreach_indexed_10368_10852(_uniq_xx_10334_1, action_1, i_1, wild__) /* forall<h,a,e> (list<a>, action : (int, a) -> e (), i : local-var<h,int>, wild_ : ()) -> <local<h>|e> () */  {
   
  var x_0_10975 = ((i_1).value);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(_y_x10679_0 /* int */ ) {
      return _mlift_lift_foreach_indexed_10368_10851(_uniq_xx_10334_1, action_1, i_1, _y_x10679_0);
    });
  }
  else {
    return _mlift_lift_foreach_indexed_10368_10851(_uniq_xx_10334_1, action_1, i_1, x_0_10975);
  }
}
 
 
// monadic lift
export function _mlift_lift_foreach_indexed_10368_10853(_uniq_x_10333, _uniq_xx_10334_2, action_2, i_2, j) /* forall<h,a,e> (a, list<a>, action : (int, a) -> e (), i : local-var<h,int>, j : int) -> <local<h>|e> () */  {
   
  var x_1_10977 = action_2(j, _uniq_x_10333);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(wild___0 /* () */ ) {
      return _mlift_lift_foreach_indexed_10368_10852(_uniq_xx_10334_2, action_2, i_2, wild___0);
    });
  }
  else {
    return _mlift_lift_foreach_indexed_10368_10852(_uniq_xx_10334_2, action_2, i_2, x_1_10977);
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
export function _lift_foreach_indexed_10368(action_4, i_3, _uniq_xs_10330) /* forall<h,a,e> (action : (int, a) -> e (), i : local-var<h,int>, list<a>) -> <local<h>|e> () */  { tailcall: while(1)
{
  if (_uniq_xs_10330 !== null) {
     
    var x_2_10980 = ((i_3).value);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(j_0 /* int */ ) {
        return _mlift_lift_foreach_indexed_10368_10853(_uniq_xs_10330.head, _uniq_xs_10330.tail, action_4, i_3, j_0);
      });
    }
    else {
       
      var x_3_10983 = action_4(x_2_10980, _uniq_xs_10330.head);
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(wild___1 /* () */ ) {
          return _mlift_lift_foreach_indexed_10368_10852(_uniq_xs_10330.tail, action_4, i_3, wild___1);
        });
      }
      else {
         
        var x_4_10987 = ((i_3).value);
        if ($std_core_hnd._yielding()) {
          return $std_core_hnd.yield_extend(function(_y_x10679_1 /* int */ ) {
            return _mlift_lift_foreach_indexed_10368_10851(_uniq_xs_10330.tail, action_4, i_3, _y_x10679_1);
          });
        }
        else {
           
          var x_5_10990 = ((i_3).value = ($std_core_types._int_add(x_4_10987,1)));
          if ($std_core_hnd._yielding()) {
            return $std_core_hnd.yield_extend(function(_uniq_x___10335_1 /* () */ ) {
              return _mlift_lift_foreach_indexed_10368_10850(_uniq_xs_10330.tail, action_4, i_3, _uniq_x___10335_1);
            });
          }
          else {
            {
              // tail call
              _uniq_xs_10330 = _uniq_xs_10330.tail;
              continue tailcall;
            }
          }
        }
      }
    }
  }
  else {
    return $std_core_types.Unit;
  }
}}
 
 
// Invoke `action` for each element of a list, passing also the position of the element.
export function foreach_indexed(xs, action) /* forall<a,e> (xs : list<a>, action : (int, a) -> e ()) -> e () */  {
  return function() {
     
    var loc = { value: 0 };
     
    if (xs === null) {
      var res = $std_core_types.Unit;
    }
    else {
      var res = _lift_foreach_indexed_10368(action, loc, xs);
    }
    return $std_core_hnd.prompt_local_var(loc, res);
  }();
}
 
 
// lifted local: intersperse, before
export function _trmc_unroll_lift_intersperse_4952_10018(sep, ys, _acc) /* forall<a> (sep : a, ys : list<a>, ctx<list<a>>) -> list<a> */  { tailcall: while(1)
{
  if (ys !== null) {
     
    var _trmc_x10444 = $std_core_types.Cons(ys.head, undefined);
    {
      // tail call
      var _x78 = $std_core_types._cctx_extend(_acc,($std_core_types.Cons(sep, _trmc_x10444)),({obj: _trmc_x10444, field_name: "tail"}));
      ys = ys.tail;
      _acc = _x78;
      continue tailcall;
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
  }
}}
 
 
// lifted local: intersperse, before
export function _unroll_lift_intersperse_4952_10018(sep_0, ys_0) /* forall<a> (sep : a, ys : list<a>) -> list<a> */  {
  return _trmc_unroll_lift_intersperse_4952_10018(sep_0, ys_0, $std_core_types._cctx_empty());
}
 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-intersperse@4952@10018
export function _lift_intersperse_4952(sep, ys) /* forall<a> (sep : a, ys : list<a>) -> list<a> */  {
  if (ys === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_lift_intersperse_4952_10018(sep, ys);
  }
}
 
 
// Insert a separator `sep`  between all elements of a list `xs` .
export function intersperse(xs, sep) /* forall<a> (xs : list<a>, sep : a) -> list<a> */  {
  if (xs !== null) {
    if (xs.tail === null) {
      var _x79 = $std_core_types.Nil;
    }
    else {
      var _x79 = _unroll_lift_intersperse_4952_10018(sep, xs.tail);
    }
    return $std_core_types.Cons(xs.head, _x79);
  }
  else {
    return $std_core_types.Nil;
  }
}
 
 
// Concatenate all strings in a list
export function join(xs) /* (xs : list<string>) -> string */  {
  if (xs === null) {
    return "";
  }
  else if (xs !== null && xs.tail === null) {
    return xs.head;
  }
  else if (xs !== null && xs.tail !== null && xs.tail.tail === null) {
    return $std_core_types._lp__plus__plus__rp_(xs.head, xs.tail.head);
  }
  else {
    return ((($std_core_vector.unvlist(xs))).join(''));
  }
}
 
 
// Concatenate all strings in a list
export function joinsep(xs, sep) /* (xs : list<string>, sep : string) -> string */  {
  if (xs === null) {
    return "";
  }
  if (xs !== null && xs.tail === null) {
    return xs.head;
  }
  if (xs !== null && xs.tail !== null && xs.tail.tail === null) {
    if ((sep === (""))){
      return $std_core_types._lp__plus__plus__rp_(xs.head, xs.tail.head);
    }
  }
  return ((($std_core_vector.unvlist(xs))).join(sep));
}
 
 
// Concatenate all strings in a list using a specific separator
export function joinsep_fs_join(xs, sep) /* (xs : list<string>, sep : string) -> string */  {
  return joinsep(xs, sep);
}
 
 
// monadic lift
export function _mlift_show_10854(_c_x10688) /* (list<string>) -> string */  {
  match: {
    if (_c_x10688 === null) {
      var _x80 = "";
      break match;
    }
    if (_c_x10688 !== null && _c_x10688.tail === null) {
      var _x80 = _c_x10688.head;
      break match;
    }
    if (_c_x10688 !== null && _c_x10688.tail !== null && _c_x10688.tail.tail === null) {
      if (((",") === (""))){
        var _x80 = $std_core_types._lp__plus__plus__rp_(_c_x10688.head, _c_x10688.tail.head);
        break match;
      }
    }
    var _x80 = ((($std_core_vector.unvlist(_c_x10688))).join((",")));
  }
  return $std_core_types._lp__plus__plus__rp_("[", $std_core_types._lp__plus__plus__rp_(_x80, "]"));
}
 
 
// Show a list
export function show(xs, _implicit_fs_show) /* forall<a,e> (xs : list<a>, ?show : (a) -> e string) -> e string */  {
   
  if (xs === null) {
    var x_10995 = $std_core_types.Nil;
  }
  else {
    var x_10995 = _unroll_map_10010(xs, _implicit_fs_show);
  }
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(_mlift_show_10854);
  }
  else {
    match: {
      if (x_10995 === null) {
        var _x81 = "";
        break match;
      }
      if (x_10995 !== null && x_10995.tail === null) {
        var _x81 = x_10995.head;
        break match;
      }
      if (x_10995 !== null && x_10995.tail !== null && x_10995.tail.tail === null) {
        if (((",") === (""))){
          var _x81 = $std_core_types._lp__plus__plus__rp_(x_10995.head, x_10995.tail.head);
          break match;
        }
      }
      var _x81 = ((($std_core_vector.unvlist(x_10995))).join((",")));
    }
    return $std_core_types._lp__plus__plus__rp_("[", $std_core_types._lp__plus__plus__rp_(_x81, "]"));
  }
}
 
 
// _deprecated_, use `list/show` instead.
export function show_list(xs, show_elem) /* forall<a,e> (xs : list<a>, show-elem : (a) -> e string) -> e string */  {
  return show(xs, show_elem);
}
 
 
// Zip two lists together by pairing the corresponding elements.
// The returned list is only as long as the smallest input list.
export function _trmc_unroll_zip_10019(xs, ys, _acc) /* forall<a,b> (xs : list<a>, ys : list<b>, ctx<list<(a, b)>>) -> list<(a, b)> */  { tailcall: while(1)
{
  if (xs !== null) {
    if (ys !== null) {
       
      var _trmc_x10446 = undefined;
       
      var _trmc_x10447 = $std_core_types.Cons($std_core_types.Tuple2(xs.head, ys.head), _trmc_x10446);
      {
        // tail call
        var _x82 = $std_core_types._cctx_extend(_acc,_trmc_x10447,({obj: _trmc_x10447, field_name: "tail"}));
        xs = xs.tail;
        ys = ys.tail;
        _acc = _x82;
        continue tailcall;
      }
    }
    else {
      return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
  }
}}
 
 
// Zip two lists together by pairing the corresponding elements.
// The returned list is only as long as the smallest input list.
export function _unroll_zip_10019(xs_0, ys_0) /* forall<a,b> (xs : list<a>, ys : list<b>) -> list<(a, b)> */  {
  return _trmc_unroll_zip_10019(xs_0, ys_0, $std_core_types._cctx_empty());
}
 
 
// unrolling of singleton matches of std/core/list/@unroll-zip@10019
export function zip(xs, ys) /* forall<a,b> (xs : list<a>, ys : list<b>) -> list<(a, b)> */  {
  if (xs === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_zip_10019(xs, ys);
  }
}
 
 
// monadic lift
export function _mlift_trmc_unroll_zipwith_10020_10855(_acc, f, xx, yy, _trmc_x10448) /* forall<a,b,c,e> (ctx<list<c>>, f : (a, b) -> e c, xx : list<a>, yy : list<b>, c) -> e list<c> */  {
   
  var _trmc_x10449 = undefined;
   
  var _trmc_x10450 = $std_core_types.Cons(_trmc_x10448, _trmc_x10449);
  return _trmc_unroll_zipwith_10020(xx, yy, f, $std_core_types._cctx_extend(_acc,_trmc_x10450,({obj: _trmc_x10450, field_name: "tail"})));
}
 
 
// monadic lift
export function _mlift_trmcm_unroll_zipwith_10020_10856(_accm, f_0, xx_0, yy_0, _trmc_x10453) /* forall<a,b,c,e> ((list<c>) -> list<c>, f : (a, b) -> e c, xx : list<a>, yy : list<b>, c) -> e list<c> */  {
  return _trmcm_unroll_zipwith_10020(xx_0, yy_0, f_0, function(_trmc_x10452 /* list<3290> */ ) {
      return _accm($std_core_types.Cons(_trmc_x10453, _trmc_x10452));
    });
}
 
 
// Zip two lists together by apply a function `f` to all corresponding elements.
// The returned list is only as long as the smallest input list.
export function _trmc_unroll_zipwith_10020(xs, ys, f_1, _acc_0) /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c, ctx<list<c>>) -> e list<c> */  { tailcall: while(1)
{
  if (xs !== null) {
    if (ys !== null) {
       
      var x_0_10998 = f_1(xs.head, ys.head);
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(_trmc_x10448_0 /* 3290 */ ) {
          return _mlift_trmc_unroll_zipwith_10020_10855(_acc_0, f_1, xs.tail, ys.tail, _trmc_x10448_0);
        });
      }
      else {
         
        var _trmc_x10449_0 = undefined;
         
        var _trmc_x10450_0 = $std_core_types.Cons(x_0_10998, _trmc_x10449_0);
        {
          // tail call
          var _x83 = $std_core_types._cctx_extend(_acc_0,_trmc_x10450_0,({obj: _trmc_x10450_0, field_name: "tail"}));
          xs = xs.tail;
          ys = ys.tail;
          _acc_0 = _x83;
          continue tailcall;
        }
      }
    }
    else {
      return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
}}
 
 
// Zip two lists together by apply a function `f` to all corresponding elements.
// The returned list is only as long as the smallest input list.
export function _trmcm_unroll_zipwith_10020(xs_0, ys_0, f_2, _accm_0) /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c, (list<c>) -> list<c>) -> e list<c> */  { tailcall: while(1)
{
  if (xs_0 !== null) {
    if (ys_0 !== null) {
       
      var x_2_11001 = f_2(xs_0.head, ys_0.head);
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(_trmc_x10453_0 /* 3290 */ ) {
          return _mlift_trmcm_unroll_zipwith_10020_10856(_accm_0, f_2, xs_0.tail, ys_0.tail, _trmc_x10453_0);
        });
      }
      else {
        {
          // tail call
          var _x86 = function(__at_accm_084 /* (list<3290>) -> list<3290> */ , _x_2_1100185 /* 3290 */ ) {
            return function(_trmc_x10452_0 /* list<3290> */ ) {
              return __at_accm_084($std_core_types.Cons(_x_2_1100185, _trmc_x10452_0));
            };
          }(_accm_0, x_2_11001);
          xs_0 = xs_0.tail;
          ys_0 = ys_0.tail;
          _accm_0 = _x86;
          continue tailcall;
        }
      }
    }
    else {
      return _accm_0($std_core_types.Nil);
    }
  }
  else {
    return _accm_0($std_core_types.Nil);
  }
}}
 
 
// Zip two lists together by apply a function `f` to all corresponding elements.
// The returned list is only as long as the smallest input list.
export function _unroll_zipwith_10020(xs_1, ys_1, f_3) /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c) -> e list<c> */  {
  var _x87 = $std_core_hnd._evv_is_affine();
  if (_x87) {
    return _trmc_unroll_zipwith_10020(xs_1, ys_1, f_3, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_unroll_zipwith_10020(xs_1, ys_1, f_3, function(_trmc_x10451 /* list<3290> */ ) {
        return _trmc_x10451;
      });
  }
}
 
 
// unrolling of singleton matches of std/core/list/@unroll-zipwith@10020
export function zipwith(xs, ys, f) /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c) -> e list<c> */  {
  if (xs === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_zipwith_10020(xs, ys, f);
  }
}
 
 
// monadic lift
export function _mlift_trmc_unroll_lift_zipwith_indexed_4953_10021_10857(_acc, f, i_0_10105, xx, yy, _trmc_x10454) /* forall<a,b,c,e> (ctx<list<c>>, f : (int, a, b) -> e c, i@0@10105 : int, xx : list<a>, yy : list<b>, c) -> e list<c> */  {
   
  var _trmc_x10455 = undefined;
   
  var _trmc_x10456 = $std_core_types.Cons(_trmc_x10454, _trmc_x10455);
  return _trmc_unroll_lift_zipwith_indexed_4953_10021(f, i_0_10105, xx, yy, $std_core_types._cctx_extend(_acc,_trmc_x10456,({obj: _trmc_x10456, field_name: "tail"})));
}
 
 
// monadic lift
export function _mlift_trmcm_unroll_lift_zipwith_indexed_4953_10021_10858(_accm, f_0, i_0_10105_0, xx_0, yy_0, _trmc_x10459) /* forall<a,b,c,e> ((list<c>) -> list<c>, f : (int, a, b) -> e c, i@0@10105 : int, xx : list<a>, yy : list<b>, c) -> e list<c> */  {
  return _trmcm_unroll_lift_zipwith_indexed_4953_10021(f_0, i_0_10105_0, xx_0, yy_0, function(_trmc_x10458 /* list<3373> */ ) {
      return _accm($std_core_types.Cons(_trmc_x10459, _trmc_x10458));
    });
}
 
 
// lifted local: zipwith-indexed, zipwith-iter
export function _trmc_unroll_lift_zipwith_indexed_4953_10021(f_1, i, xs, ys, _acc_0) /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xs : list<a>, ys : list<b>, ctx<list<c>>) -> e list<c> */  { tailcall: while(1)
{
  if (xs !== null) {
    if (ys !== null) {
       
      var i_0_10105_1 = $std_core_types._int_add(i,1);
       
      var x_0_11004 = f_1(i, xs.head, ys.head);
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(_trmc_x10454_0 /* 3373 */ ) {
          return _mlift_trmc_unroll_lift_zipwith_indexed_4953_10021_10857(_acc_0, f_1, i_0_10105_1, xs.tail, ys.tail, _trmc_x10454_0);
        });
      }
      else {
         
        var _trmc_x10455_0 = undefined;
         
        var _trmc_x10456_0 = $std_core_types.Cons(x_0_11004, _trmc_x10455_0);
        {
          // tail call
          var _x88 = $std_core_types._cctx_extend(_acc_0,_trmc_x10456_0,({obj: _trmc_x10456_0, field_name: "tail"}));
          i = i_0_10105_1;
          xs = xs.tail;
          ys = ys.tail;
          _acc_0 = _x88;
          continue tailcall;
        }
      }
    }
    else {
      return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
}}
 
 
// lifted local: zipwith-indexed, zipwith-iter
export function _trmcm_unroll_lift_zipwith_indexed_4953_10021(f_2, i_0, xs_0, ys_0, _accm_0) /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xs : list<a>, ys : list<b>, (list<c>) -> list<c>) -> e list<c> */  { tailcall: while(1)
{
  if (xs_0 !== null) {
    if (ys_0 !== null) {
       
      var i_0_10105_2 = $std_core_types._int_add(i_0,1);
       
      var x_2_11007 = f_2(i_0, xs_0.head, ys_0.head);
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(_trmc_x10459_0 /* 3373 */ ) {
          return _mlift_trmcm_unroll_lift_zipwith_indexed_4953_10021_10858(_accm_0, f_2, i_0_10105_2, xs_0.tail, ys_0.tail, _trmc_x10459_0);
        });
      }
      else {
        {
          // tail call
          var _x91 = function(__at_accm_089 /* (list<3373>) -> list<3373> */ , _x_2_1100790 /* 3373 */ ) {
            return function(_trmc_x10458_0 /* list<3373> */ ) {
              return __at_accm_089($std_core_types.Cons(_x_2_1100790, _trmc_x10458_0));
            };
          }(_accm_0, x_2_11007);
          i_0 = i_0_10105_2;
          xs_0 = xs_0.tail;
          ys_0 = ys_0.tail;
          _accm_0 = _x91;
          continue tailcall;
        }
      }
    }
    else {
      return _accm_0($std_core_types.Nil);
    }
  }
  else {
    return _accm_0($std_core_types.Nil);
  }
}}
 
 
// lifted local: zipwith-indexed, zipwith-iter
export function _unroll_lift_zipwith_indexed_4953_10021(f_3, i_1, xs_1, ys_1) /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xs : list<a>, ys : list<b>) -> e list<c> */  {
  var _x92 = $std_core_hnd._evv_is_affine();
  if (_x92) {
    return _trmc_unroll_lift_zipwith_indexed_4953_10021(f_3, i_1, xs_1, ys_1, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_unroll_lift_zipwith_indexed_4953_10021(f_3, i_1, xs_1, ys_1, function(_trmc_x10457 /* list<3373> */ ) {
        return _trmc_x10457;
      });
  }
}
 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-zipwith-indexed@4953@10021
export function _lift_zipwith_indexed_4953(f, i, xs, ys) /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xs : list<a>, ys : list<b>) -> e list<c> */  {
  if (xs === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_lift_zipwith_indexed_4953_10021(f, i, xs, ys);
  }
}
 
 
// Zip two lists together by apply a function `f` to all corresponding elements
// and their index in the list.
// The returned list is only as long as the smallest input list.
export function zipwith_indexed(xs0, ys0, f) /* forall<a,b,c,e> (xs0 : list<a>, ys0 : list<b>, f : (int, a, b) -> e c) -> e list<c> */  {
  if (xs0 === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_lift_zipwith_indexed_4953_10021(f, 0, xs0, ys0);
  }
}
 
 
// lifted local: unzip, iter
// todo: implement TRMC for multiple results
export function _unroll_lift_unzip_4954_10022(ys, acc1, acc2) /* forall<a,b,c,d> (ys : list<(a, b)>, acc1 : cctx<c,list<a>>, acc2 : cctx<d,list<b>>) -> (c, d) */  { tailcall: while(1)
{
  if (ys !== null) {
     
    var _cctx_x3433 = $std_core_types.Cons(ys.head.fst, undefined);
     
    var _cctx_x3434 = {obj: _cctx_x3433, field_name: "tail"};
     
    var _cctx_x3473 = $std_core_types.Cons(ys.head.snd, undefined);
     
    var _cctx_x3474 = {obj: _cctx_x3473, field_name: "tail"};
    {
      // tail call
      var _x93 = $std_core_types._cctx_compose(acc1,($std_core_types._cctx_create(_cctx_x3433,_cctx_x3434)));
      var _x94 = $std_core_types._cctx_compose(acc2,($std_core_types._cctx_create(_cctx_x3473,_cctx_x3474)));
      ys = ys.tail;
      acc1 = _x93;
      acc2 = _x94;
      continue tailcall;
    }
  }
  else {
    return $std_core_types.Tuple2($std_core_types._cctx_apply(acc1,($std_core_types.Nil)), $std_core_types._cctx_apply(acc2,($std_core_types.Nil)));
  }
}}
 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-unzip@4954@10022
export function _lift_unzip_4954(ys, acc1, acc2) /* forall<a,b,c,d> (ys : list<(a, b)>, acc1 : cctx<c,list<a>>, acc2 : cctx<d,list<b>>) -> (c, d) */  {
  if (ys === null) {
    return $std_core_types.Tuple2($std_core_types._cctx_apply(acc1,($std_core_types.Nil)), $std_core_types._cctx_apply(acc2,($std_core_types.Nil)));
  }
  else {
    return _unroll_lift_unzip_4954_10022(ys, acc1, acc2);
  }
}
 
 
// Unzip a list of pairs into two lists
export function unzip(xs) /* forall<a,b> (xs : list<(a, b)>) -> (list<a>, list<b>) */  {
   
  var acc1_10160 = $std_core_types._cctx_empty();
   
  var acc2_10161 = $std_core_types._cctx_empty();
  if (xs === null) {
    return $std_core_types.Tuple2($std_core_types._cctx_apply(acc1_10160,($std_core_types.Nil)), $std_core_types._cctx_apply(acc2_10161,($std_core_types.Nil)));
  }
  else {
    return _unroll_lift_unzip_4954_10022(xs, acc1_10160, acc2_10161);
  }
}
 
 
// lifted local: unzip3, iter
// todo: implement TRMC for multiple results
export function _unroll_lift_unzip3_4955_10023(ys, acc1, acc2, acc3) /* forall<a,b,c,d,a1,b1> (ys : list<(a, b, c)>, acc1 : cctx<d,list<a>>, acc2 : cctx<a1,list<b>>, acc3 : cctx<b1,list<c>>) -> (d, a1, b1) */  { tailcall: while(1)
{
  if (ys !== null) {
     
    var _cctx_x3624 = $std_core_types.Cons(ys.head.fst, undefined);
     
    var _cctx_x3625 = {obj: _cctx_x3624, field_name: "tail"};
     
    var _cctx_x3664 = $std_core_types.Cons(ys.head.snd, undefined);
     
    var _cctx_x3665 = {obj: _cctx_x3664, field_name: "tail"};
     
    var _cctx_x3704 = $std_core_types.Cons(ys.head.thd, undefined);
     
    var _cctx_x3705 = {obj: _cctx_x3704, field_name: "tail"};
    {
      // tail call
      var _x95 = $std_core_types._cctx_compose(acc1,($std_core_types._cctx_create(_cctx_x3624,_cctx_x3625)));
      var _x96 = $std_core_types._cctx_compose(acc2,($std_core_types._cctx_create(_cctx_x3664,_cctx_x3665)));
      var _x97 = $std_core_types._cctx_compose(acc3,($std_core_types._cctx_create(_cctx_x3704,_cctx_x3705)));
      ys = ys.tail;
      acc1 = _x95;
      acc2 = _x96;
      acc3 = _x97;
      continue tailcall;
    }
  }
  else {
    return $std_core_types.Tuple3($std_core_types._cctx_apply(acc1,($std_core_types.Nil)), $std_core_types._cctx_apply(acc2,($std_core_types.Nil)), $std_core_types._cctx_apply(acc3,($std_core_types.Nil)));
  }
}}
 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-unzip3@4955@10023
export function _lift_unzip3_4955(ys, acc1, acc2, acc3) /* forall<a,b,c,d,a1,b1> (ys : list<(a, b, c)>, acc1 : cctx<d,list<a>>, acc2 : cctx<a1,list<b>>, acc3 : cctx<b1,list<c>>) -> (d, a1, b1) */  {
  if (ys === null) {
    return $std_core_types.Tuple3($std_core_types._cctx_apply(acc1,($std_core_types.Nil)), $std_core_types._cctx_apply(acc2,($std_core_types.Nil)), $std_core_types._cctx_apply(acc3,($std_core_types.Nil)));
  }
  else {
    return _unroll_lift_unzip3_4955_10023(ys, acc1, acc2, acc3);
  }
}
 
 
// Unzip a list of triples into three lists
export function unzip3(xs) /* forall<a,b,c> (xs : list<(a, b, c)>) -> (list<a>, list<b>, list<c>) */  {
   
  var acc1_10163 = $std_core_types._cctx_empty();
   
  var acc2_10164 = $std_core_types._cctx_empty();
   
  var acc3_10165 = $std_core_types._cctx_empty();
  if (xs === null) {
    return $std_core_types.Tuple3($std_core_types._cctx_apply(acc1_10163,($std_core_types.Nil)), $std_core_types._cctx_apply(acc2_10164,($std_core_types.Nil)), $std_core_types._cctx_apply(acc3_10165,($std_core_types.Nil)));
  }
  else {
    return _unroll_lift_unzip3_4955_10023(xs, acc1_10163, acc2_10164, acc3_10165);
  }
}
 
 
// lifted local: unzip4, iter
// todo: implement TRMC for multiple results
export function _unroll_lift_unzip4_4956_10024(ys, acc1, acc2, acc3, acc4) /* forall<a,b,c,d,a1,b1,c1,d1> (ys : list<(a, b, c, d)>, acc1 : cctx<a1,list<a>>, acc2 : cctx<b1,list<b>>, acc3 : cctx<c1,list<c>>, acc4 : cctx<d1,list<d>>) -> (a1, b1, c1, d1) */  { tailcall: while(1)
{
  if (ys !== null) {
     
    var _cctx_x3895 = $std_core_types.Cons(ys.head.fst, undefined);
     
    var _cctx_x3896 = {obj: _cctx_x3895, field_name: "tail"};
     
    var _cctx_x3935 = $std_core_types.Cons(ys.head.snd, undefined);
     
    var _cctx_x3936 = {obj: _cctx_x3935, field_name: "tail"};
     
    var _cctx_x3975 = $std_core_types.Cons(ys.head.thd, undefined);
     
    var _cctx_x3976 = {obj: _cctx_x3975, field_name: "tail"};
     
    var _cctx_x4015 = $std_core_types.Cons(ys.head.field4, undefined);
     
    var _cctx_x4016 = {obj: _cctx_x4015, field_name: "tail"};
    {
      // tail call
      var _x98 = $std_core_types._cctx_compose(acc1,($std_core_types._cctx_create(_cctx_x3895,_cctx_x3896)));
      var _x99 = $std_core_types._cctx_compose(acc2,($std_core_types._cctx_create(_cctx_x3935,_cctx_x3936)));
      var _x100 = $std_core_types._cctx_compose(acc3,($std_core_types._cctx_create(_cctx_x3975,_cctx_x3976)));
      var _x101 = $std_core_types._cctx_compose(acc4,($std_core_types._cctx_create(_cctx_x4015,_cctx_x4016)));
      ys = ys.tail;
      acc1 = _x98;
      acc2 = _x99;
      acc3 = _x100;
      acc4 = _x101;
      continue tailcall;
    }
  }
  else {
    return $std_core_types.Tuple4($std_core_types._cctx_apply(acc1,($std_core_types.Nil)), $std_core_types._cctx_apply(acc2,($std_core_types.Nil)), $std_core_types._cctx_apply(acc3,($std_core_types.Nil)), $std_core_types._cctx_apply(acc4,($std_core_types.Nil)));
  }
}}
 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-unzip4@4956@10024
export function _lift_unzip4_4956(ys, acc1, acc2, acc3, acc4) /* forall<a,b,c,d,a1,b1,c1,d1> (ys : list<(a, b, c, d)>, acc1 : cctx<a1,list<a>>, acc2 : cctx<b1,list<b>>, acc3 : cctx<c1,list<c>>, acc4 : cctx<d1,list<d>>) -> (a1, b1, c1, d1) */  {
  if (ys === null) {
    return $std_core_types.Tuple4($std_core_types._cctx_apply(acc1,($std_core_types.Nil)), $std_core_types._cctx_apply(acc2,($std_core_types.Nil)), $std_core_types._cctx_apply(acc3,($std_core_types.Nil)), $std_core_types._cctx_apply(acc4,($std_core_types.Nil)));
  }
  else {
    return _unroll_lift_unzip4_4956_10024(ys, acc1, acc2, acc3, acc4);
  }
}
 
 
// Unzip a list of quadruples into four lists
export function unzip4(xs) /* forall<a,b,c,d> (xs : list<(a, b, c, d)>) -> (list<a>, list<b>, list<c>, list<d>) */  {
   
  var acc1_10167 = $std_core_types._cctx_empty();
   
  var acc2_10168 = $std_core_types._cctx_empty();
   
  var acc3_10169 = $std_core_types._cctx_empty();
   
  var acc4_10170 = $std_core_types._cctx_empty();
  if (xs === null) {
    return $std_core_types.Tuple4($std_core_types._cctx_apply(acc1_10167,($std_core_types.Nil)), $std_core_types._cctx_apply(acc2_10168,($std_core_types.Nil)), $std_core_types._cctx_apply(acc3_10169,($std_core_types.Nil)), $std_core_types._cctx_apply(acc4_10170,($std_core_types.Nil)));
  }
  else {
    return _unroll_lift_unzip4_4956_10024(xs, acc1_10167, acc2_10168, acc3_10169, acc4_10170);
  }
}
 
 
// monadic lift
export function _mlift_unroll_lift_span_4957_10025_10859(acc, predicate, y, ys, yy, _y_x10718) /* forall<a,e> (acc : list<a>, predicate : (a) -> e bool, y : a, ys : list<a>, yy : list<a>, bool) -> e (list<a>, list<a>) */  {
  if (_y_x10718) {
    return _unroll_lift_span_4957_10025(predicate, yy, $std_core_types.Cons(y, acc));
  }
  else {
    if (acc === null) {
      var _x102 = $std_core_types.Nil;
    }
    else {
      var _x102 = _unroll_lift_reverse_append_4948_10003($std_core_types.Nil, acc);
    }
    return $std_core_types.Tuple2(_x102, ys);
  }
}
 
 
// lifted local: span, span-acc
// todo: implement TRMC with multiple results to avoid the reverse
export function _unroll_lift_span_4957_10025(predicate_0, ys_0, acc_0) /* forall<a,e> (predicate : (a) -> e bool, ys : list<a>, acc : list<a>) -> e (list<a>, list<a>) */  { tailcall: while(1)
{
  if (ys_0 !== null) {
     
    var x_11010 = predicate_0(ys_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10718_0 /* bool */ ) {
        return _mlift_unroll_lift_span_4957_10025_10859(acc_0, predicate_0, ys_0.head, ys_0, ys_0.tail, _y_x10718_0);
      });
    }
    else {
      if (x_11010) {
        {
          // tail call
          var _x103 = $std_core_types.Cons(ys_0.head, acc_0);
          ys_0 = ys_0.tail;
          acc_0 = _x103;
          continue tailcall;
        }
      }
      else {
        if (acc_0 === null) {
          var _x104 = $std_core_types.Nil;
        }
        else {
          var _x104 = _unroll_lift_reverse_append_4948_10003($std_core_types.Nil, acc_0);
        }
        return $std_core_types.Tuple2(_x104, ys_0);
      }
    }
  }
  else {
    if (acc_0 === null) {
      var _x105 = $std_core_types.Nil;
    }
    else {
      var _x105 = _unroll_lift_reverse_append_4948_10003($std_core_types.Nil, acc_0);
    }
    return $std_core_types.Tuple2(_x105, ys_0);
  }
}}
 
 
// unrolling of singleton matches of std/core/list/@unroll-lift-span@4957@10025
export function _lift_span_4957(predicate, ys, acc) /* forall<a,e> (predicate : (a) -> e bool, ys : list<a>, acc : list<a>) -> e (list<a>, list<a>) */  {
  if (ys === null) {
    if (acc === null) {
      var _x106 = $std_core_types.Nil;
    }
    else {
      var _x106 = _unroll_lift_reverse_append_4948_10003($std_core_types.Nil, acc);
    }
    return $std_core_types.Tuple2(_x106, ys);
  }
  else {
    return _unroll_lift_span_4957_10025(predicate, ys, acc);
  }
}
 
export function span(xs, predicate) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e (list<a>, list<a>) */  {
  if (xs === null) {
    var _x108 = $std_core_types.Nil;
    if (_x108 === null) {
      var _x107 = $std_core_types.Nil;
    }
    else {
      var _x107 = _unroll_lift_reverse_append_4948_10003($std_core_types.Nil, $std_core_types.Nil);
    }
    return $std_core_types.Tuple2(_x107, xs);
  }
  else {
    return _unroll_lift_span_4957_10025(predicate, xs, $std_core_types.Nil);
  }
}
 
 
// monadic lift
export function _mlift_trmc_unroll_take_while_10026_10860(_acc, predicate, x, xx, _y_x10726) /* forall<a,e> (ctx<list<a>>, predicate : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */  {
  if (_y_x10726) {
     
    var _trmc_x10460 = undefined;
     
    var _trmc_x10461 = $std_core_types.Cons(x, _trmc_x10460);
    return _trmc_unroll_take_while_10026(xx, predicate, $std_core_types._cctx_extend(_acc,_trmc_x10461,({obj: _trmc_x10461, field_name: "tail"})));
  }
  else {
    return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
  }
}
 
 
// monadic lift
export function _mlift_trmcm_unroll_take_while_10026_10861(_accm, predicate_0, x_0, xx_0, _y_x10730) /* forall<a,e> ((list<a>) -> list<a>, predicate : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */  {
  if (_y_x10730) {
    return _trmcm_unroll_take_while_10026(xx_0, predicate_0, function(_trmc_x10463 /* list<4313> */ ) {
        return _accm($std_core_types.Cons(x_0, _trmc_x10463));
      });
  }
  else {
    return _accm($std_core_types.Nil);
  }
}
 
 
// Keep only those initial elements that satisfy `predicate`
export function _trmc_unroll_take_while_10026(xs, predicate_1, _acc_0) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool, ctx<list<a>>) -> e list<a> */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_2_11013 = predicate_1(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10726_0 /* bool */ ) {
        return _mlift_trmc_unroll_take_while_10026_10860(_acc_0, predicate_1, xs.head, xs.tail, _y_x10726_0);
      });
    }
    else {
      if (x_2_11013) {
         
        var _trmc_x10460_0 = undefined;
         
        var _trmc_x10461_0 = $std_core_types.Cons(xs.head, _trmc_x10460_0);
        {
          // tail call
          var _x109 = $std_core_types._cctx_extend(_acc_0,_trmc_x10461_0,({obj: _trmc_x10461_0, field_name: "tail"}));
          xs = xs.tail;
          _acc_0 = _x109;
          continue tailcall;
        }
      }
      else {
        return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
      }
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
}}
 
 
// Keep only those initial elements that satisfy `predicate`
export function _trmcm_unroll_take_while_10026(xs_0, predicate_2, _accm_0) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool, (list<a>) -> list<a>) -> e list<a> */  { tailcall: while(1)
{
  if (xs_0 !== null) {
     
    var x_4_11016 = predicate_2(xs_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10730_0 /* bool */ ) {
        return _mlift_trmcm_unroll_take_while_10026_10861(_accm_0, predicate_2, xs_0.head, xs_0.tail, _y_x10730_0);
      });
    }
    else {
      if (x_4_11016) {
        {
          // tail call
          var _x112 = function(__at_accm_0110 /* (list<4313>) -> list<4313> */ , _x_3111 /* 4313 */ ) {
            return function(_trmc_x10463_0 /* list<4313> */ ) {
              return __at_accm_0110($std_core_types.Cons(_x_3111, _trmc_x10463_0));
            };
          }(_accm_0, xs_0.head);
          xs_0 = xs_0.tail;
          _accm_0 = _x112;
          continue tailcall;
        }
      }
      else {
        return _accm_0($std_core_types.Nil);
      }
    }
  }
  else {
    return _accm_0($std_core_types.Nil);
  }
}}
 
 
// Keep only those initial elements that satisfy `predicate`
export function _unroll_take_while_10026(xs_1, predicate_3) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */  {
  var _x113 = $std_core_hnd._evv_is_affine();
  if (_x113) {
    return _trmc_unroll_take_while_10026(xs_1, predicate_3, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_unroll_take_while_10026(xs_1, predicate_3, function(_trmc_x10462 /* list<4313> */ ) {
        return _trmc_x10462;
      });
  }
}
 
 
// unrolling of singleton matches of std/core/list/@unroll-take-while@10026
export function take_while(xs, predicate) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */  {
  if (xs === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_take_while_10026(xs, predicate);
  }
}
 
 
// Concatenate all strings in a list in reverse order
export function reverse_join(xs) /* (xs : list<string>) -> string */  {
   
  if (xs === null) {
    var xs_0_10125 = $std_core_types.Nil;
  }
  else {
    var xs_0_10125 = _unroll_lift_reverse_append_4948_10003($std_core_types.Nil, xs);
  }
  if (xs_0_10125 === null) {
    return "";
  }
  else if (xs_0_10125 !== null && xs_0_10125.tail === null) {
    return xs_0_10125.head;
  }
  else if (xs_0_10125 !== null && xs_0_10125.tail !== null && xs_0_10125.tail.tail === null) {
    return $std_core_types._lp__plus__plus__rp_(xs_0_10125.head, xs_0_10125.tail.head);
  }
  else {
    return ((($std_core_vector.unvlist(xs_0_10125))).join(''));
  }
}
 
 
// Append `end` to each string in the list `xs` and join them all together.\
// `join-end([],end) === ""`\
// `join-end(["a","b"],"/") === "a/b/"`
export function join_end(xs, end) /* (xs : list<string>, end : string) -> string */  {
  if (xs === null) {
    return "";
  }
  else {
    return $std_core_types._lp__plus__plus__rp_(joinsep(xs, end), end);
  }
}
 
 
// lifted local: concat, concat-pre
export function _trmc_lift_concat_4958(ys, zss, _acc) /* forall<a> (ys : list<a>, zss : list<list<a>>, ctx<list<a>>) -> list<a> */  { tailcall: while(1)
{
  if (ys !== null) {
     
    var _trmc_x10464 = undefined;
     
    var _trmc_x10465 = $std_core_types.Cons(ys.head, _trmc_x10464);
    {
      // tail call
      var _x114 = $std_core_types._cctx_extend(_acc,_trmc_x10465,({obj: _trmc_x10465, field_name: "tail"}));
      ys = ys.tail;
      _acc = _x114;
      continue tailcall;
    }
  }
  else {
    if (zss !== null) {
      {
        // tail call
        ys = zss.head;
        zss = zss.tail;
        continue tailcall;
      }
    }
    else {
      return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
    }
  }
}}
 
 
// lifted local: concat, concat-pre
export function _lift_concat_4958(ys_0, zss_0) /* forall<a> (ys : list<a>, zss : list<list<a>>) -> list<a> */  {
  return _trmc_lift_concat_4958(ys_0, zss_0, $std_core_types._cctx_empty());
}
 
 
// Concatenate all lists in a list (e.g. flatten the list). (tail-recursive)
export function concat(xss) /* forall<a> (xss : list<list<a>>) -> list<a> */  {
  return _lift_concat_4958($std_core_types.Nil, xss);
}
 
 
// monadic lift
export function _mlift_trmc_lift_flatmap_4959_10862(_acc, f, zz, ys_1_10132) /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e list<b>, zz : list<a>, ys@1@10132 : list<b>) -> e list<b> */  {
  return _trmc_lift_flatmap_4959(f, ys_1_10132, zz, _acc);
}
 
 
// monadic lift
export function _mlift_trmcm_lift_flatmap_4959_10863(_accm, f_0, zz_0, ys_1_10132_0) /* forall<a,b,e> ((list<b>) -> list<b>, f : (a) -> e list<b>, zz : list<a>, ys@1@10132 : list<b>) -> e list<b> */  {
  return _trmcm_lift_flatmap_4959(f_0, ys_1_10132_0, zz_0, _accm);
}
 
 
// lifted local: flatmap, flatmap-pre
export function _trmc_lift_flatmap_4959(f_1, ys, zs, _acc_0) /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>, ctx<list<b>>) -> e list<b> */  { tailcall: while(1)
{
  if (ys !== null) {
     
    var _trmc_x10466 = undefined;
     
    var _trmc_x10467 = $std_core_types.Cons(ys.head, _trmc_x10466);
    {
      // tail call
      var _x115 = $std_core_types._cctx_extend(_acc_0,_trmc_x10467,({obj: _trmc_x10467, field_name: "tail"}));
      ys = ys.tail;
      _acc_0 = _x115;
      continue tailcall;
    }
  }
  else {
    if (zs !== null) {
       
      var x_11019 = f_1(zs.head);
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(ys_1_10132_1 /* list<4487> */ ) {
          return _mlift_trmc_lift_flatmap_4959_10862(_acc_0, f_1, zs.tail, ys_1_10132_1);
        });
      }
      else {
        {
          // tail call
          ys = x_11019;
          zs = zs.tail;
          continue tailcall;
        }
      }
    }
    else {
      return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
    }
  }
}}
 
 
// lifted local: flatmap, flatmap-pre
export function _trmcm_lift_flatmap_4959(f_2, ys_0, zs_0, _accm_0) /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>, (list<b>) -> list<b>) -> e list<b> */  { tailcall: while(1)
{
  if (ys_0 !== null) {
    {
      // tail call
      var _x118 = function(__at_accm_0116 /* (list<4487>) -> list<4487> */ , _y_0117 /* 4487 */ ) {
        return function(_trmc_x10469 /* list<4487> */ ) {
          return __at_accm_0116($std_core_types.Cons(_y_0117, _trmc_x10469));
        };
      }(_accm_0, ys_0.head);
      ys_0 = ys_0.tail;
      _accm_0 = _x118;
      continue tailcall;
    }
  }
  else {
    if (zs_0 !== null) {
       
      var x_0_11022 = f_2(zs_0.head);
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(ys_1_10132_3 /* list<4487> */ ) {
          return _mlift_trmcm_lift_flatmap_4959_10863(_accm_0, f_2, zs_0.tail, ys_1_10132_3);
        });
      }
      else {
        {
          // tail call
          ys_0 = x_0_11022;
          zs_0 = zs_0.tail;
          continue tailcall;
        }
      }
    }
    else {
      return _accm_0($std_core_types.Nil);
    }
  }
}}
 
 
// lifted local: flatmap, flatmap-pre
export function _lift_flatmap_4959(f_3, ys_1, zs_1) /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>) -> e list<b> */  {
  var _x119 = $std_core_hnd._evv_is_affine();
  if (_x119) {
    return _trmc_lift_flatmap_4959(f_3, ys_1, zs_1, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_lift_flatmap_4959(f_3, ys_1, zs_1, function(_trmc_x10468 /* list<4487> */ ) {
        return _trmc_x10468;
      });
  }
}
 
 
// Concatenate the result lists from applying a function to all elements.
export function flatmap(xs, f) /* forall<a,b,e> (xs : list<a>, f : (a) -> e list<b>) -> e list<b> */  {
  return _lift_flatmap_4959(f, $std_core_types.Nil, xs);
}
 
 
// monadic lift
export function _mlift_trmc_unroll_flatmap_maybe_10027_10864(_acc, f, xx, _y_x10753) /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */  {
  if (_y_x10753 !== null) {
     
    var _trmc_x10470 = undefined;
     
    var _trmc_x10471 = $std_core_types.Cons(_y_x10753.value, _trmc_x10470);
    return _trmc_unroll_flatmap_maybe_10027(xx, f, $std_core_types._cctx_extend(_acc,_trmc_x10471,({obj: _trmc_x10471, field_name: "tail"})));
  }
  else {
    return _trmc_unroll_flatmap_maybe_10027(xx, f, _acc);
  }
}
 
 
// monadic lift
export function _mlift_trmcm_unroll_flatmap_maybe_10027_10865(_accm, f_0, xx_0, _y_x10758) /* forall<a,b,e> ((list<b>) -> list<b>, f : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */  {
  if (_y_x10758 !== null) {
    return _trmcm_unroll_flatmap_maybe_10027(xx_0, f_0, function(_trmc_x10473 /* list<4558> */ ) {
        return _accm($std_core_types.Cons(_y_x10758.value, _trmc_x10473));
      });
  }
  else {
    return _trmcm_unroll_flatmap_maybe_10027(xx_0, f_0, _accm);
  }
}
 
 
// Concatenate the `Just` result elements from applying a function to all elements.
export function _trmc_unroll_flatmap_maybe_10027(xs, f_1, _acc_0) /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_0_11025 = f_1(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10753_0 /* maybe<4558> */ ) {
        return _mlift_trmc_unroll_flatmap_maybe_10027_10864(_acc_0, f_1, xs.tail, _y_x10753_0);
      });
    }
    else {
      if (x_0_11025 !== null) {
         
        var _trmc_x10470_0 = undefined;
         
        var _trmc_x10471_0 = $std_core_types.Cons(x_0_11025.value, _trmc_x10470_0);
        {
          // tail call
          var _x120 = $std_core_types._cctx_extend(_acc_0,_trmc_x10471_0,({obj: _trmc_x10471_0, field_name: "tail"}));
          xs = xs.tail;
          _acc_0 = _x120;
          continue tailcall;
        }
      }
      else {
        {
          // tail call
          xs = xs.tail;
          continue tailcall;
        }
      }
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
}}
 
 
// Concatenate the `Just` result elements from applying a function to all elements.
export function _trmcm_unroll_flatmap_maybe_10027(xs_0, f_2, _accm_0) /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>, (list<b>) -> list<b>) -> e list<b> */  { tailcall: while(1)
{
  if (xs_0 !== null) {
     
    var x_2_11028 = f_2(xs_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10758_0 /* maybe<4558> */ ) {
        return _mlift_trmcm_unroll_flatmap_maybe_10027_10865(_accm_0, f_2, xs_0.tail, _y_x10758_0);
      });
    }
    else {
      if (x_2_11028 !== null) {
        {
          // tail call
          var _x123 = function(__at_accm_0121 /* (list<4558>) -> list<4558> */ , _y_2122 /* 4558 */ ) {
            return function(_trmc_x10473_0 /* list<4558> */ ) {
              return __at_accm_0121($std_core_types.Cons(_y_2122, _trmc_x10473_0));
            };
          }(_accm_0, x_2_11028.value);
          xs_0 = xs_0.tail;
          _accm_0 = _x123;
          continue tailcall;
        }
      }
      else {
        {
          // tail call
          xs_0 = xs_0.tail;
          continue tailcall;
        }
      }
    }
  }
  else {
    return _accm_0($std_core_types.Nil);
  }
}}
 
 
// Concatenate the `Just` result elements from applying a function to all elements.
export function _unroll_flatmap_maybe_10027(xs_1, f_3) /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>) -> e list<b> */  {
  var _x124 = $std_core_hnd._evv_is_affine();
  if (_x124) {
    return _trmc_unroll_flatmap_maybe_10027(xs_1, f_3, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_unroll_flatmap_maybe_10027(xs_1, f_3, function(_trmc_x10472 /* list<4558> */ ) {
        return _trmc_x10472;
      });
  }
}
 
 
// unrolling of singleton matches of std/core/list/@unroll-flatmap-maybe@10027
export function flatmap_maybe(xs, f) /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>) -> e list<b> */  {
  if (xs === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_flatmap_maybe_10027(xs, f);
  }
}
 
 
// Concatenate a list of `:maybe` values
export function _trmc_unroll_concat_maybe_10028(xs, _acc) /* forall<a> (xs : list<maybe<a>>, ctx<list<a>>) -> list<a> */  { tailcall: while(1)
{
  if (xs !== null) {
    if (xs.head !== null) {
       
      var _trmc_x10474 = undefined;
       
      var _trmc_x10475 = $std_core_types.Cons(xs.head.value, _trmc_x10474);
      {
        // tail call
        var _x125 = $std_core_types._cctx_extend(_acc,_trmc_x10475,({obj: _trmc_x10475, field_name: "tail"}));
        xs = xs.tail;
        _acc = _x125;
        continue tailcall;
      }
    }
    else {
      {
        // tail call
        xs = xs.tail;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
  }
}}
 
 
// Concatenate a list of `:maybe` values
export function _unroll_concat_maybe_10028(xs_0) /* forall<a> (xs : list<maybe<a>>) -> list<a> */  {
  return _trmc_unroll_concat_maybe_10028(xs_0, $std_core_types._cctx_empty());
}
 
 
// unrolling of singleton matches of std/core/list/@unroll-concat-maybe@10028
export function concat_maybe(xs) /* forall<a> (xs : list<maybe<a>>) -> list<a> */  {
  if (xs === null) {
    return $std_core_types.Nil;
  }
  else {
    return _unroll_concat_maybe_10028(xs);
  }
}
 
 
// Return the last element of a list (or `Nothing` for the empty list)
export function last(xs) /* forall<a> (xs : list<a>) -> maybe<a> */  { tailcall: while(1)
{
  if (xs !== null && xs.tail === null) {
    return $std_core_types.Just(xs.head);
  }
  else if (xs !== null) {
    {
      // tail call
      xs = xs.tail;
      continue tailcall;
    }
  }
  else {
    return $std_core_types.Nothing;
  }
}}
 
 
// Return the list without its last element.
// Return an empty list for an empty list.
export function _trmc_init(xs, _acc) /* forall<a> (xs : list<a>, ctx<list<a>>) -> list<a> */  { tailcall: while(1)
{
  if (xs !== null && xs.tail !== null) {
     
    var _trmc_x10476 = undefined;
     
    var _trmc_x10477 = $std_core_types.Cons(xs.head, _trmc_x10476);
    {
      // tail call
      var _x126 = $std_core_types._cctx_extend(_acc,_trmc_x10477,({obj: _trmc_x10477, field_name: "tail"}));
      xs = xs.tail;
      _acc = _x126;
      continue tailcall;
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
  }
}}
 
 
// Return the list without its last element.
// Return an empty list for an empty list.
export function init(xs_0) /* forall<a> (xs : list<a>) -> list<a> */  {
  return _trmc_init(xs_0, $std_core_types._cctx_empty());
}
 
 
// Get (zero-based) element `n`  of a list. Return a `:maybe` type.
export function _unroll_index_10029(xs, n) /* forall<a> (xs : list<a>, n : int) -> maybe<a> */  { tailcall: while(1)
{
  if (xs !== null) {
    if ($std_core_types._int_gt(n,0)) {
      {
        // tail call
        var _x127 = $std_core_types._int_sub(n,1);
        xs = xs.tail;
        n = _x127;
        continue tailcall;
      }
    }
    else {
      if ($std_core_types._int_eq(n,0)) {
        return $std_core_types.Just(xs.head);
      }
      else {
        return $std_core_types.Nothing;
      }
    }
  }
  else {
    return $std_core_types.Nothing;
  }
}}
 
 
// unrolling of singleton matches of std/core/list/@unroll-index@10029
export function _index(xs, n) /* forall<a> (xs : list<a>, n : int) -> maybe<a> */  {
  if (xs === null) {
    return $std_core_types.Nothing;
  }
  else {
    return _unroll_index_10029(xs, n);
  }
}
 
 
// monadic lift
export function _mlift_unroll_all_10030_10866(predicate, xx, _y_x10768) /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */  {
  if (_y_x10768) {
    return _unroll_all_10030(xx, predicate);
  }
  else {
    return false;
  }
}
 
 
// Do all elements satisfy a predicate ?
export function _unroll_all_10030(xs, predicate_0) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_0_11031 = predicate_0(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10768_0 /* bool */ ) {
        return _mlift_unroll_all_10030_10866(predicate_0, xs.tail, _y_x10768_0);
      });
    }
    else {
      if (x_0_11031) {
        {
          // tail call
          xs = xs.tail;
          continue tailcall;
        }
      }
      else {
        return false;
      }
    }
  }
  else {
    return true;
  }
}}
 
 
// unrolling of singleton matches of std/core/list/@unroll-all@10030
export function all(xs, predicate) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */  {
  if (xs === null) {
    return true;
  }
  else {
    return _unroll_all_10030(xs, predicate);
  }
}
 
 
// monadic lift
export function _mlift_unroll_any_10031_10867(predicate, xx, _y_x10774) /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */  {
  if (_y_x10774) {
    return true;
  }
  else {
    return _unroll_any_10031(xx, predicate);
  }
}
 
 
// Are there any elements in a list that satisfy a predicate ?
export function _unroll_any_10031(xs, predicate_0) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_0_11034 = predicate_0(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10774_0 /* bool */ ) {
        return _mlift_unroll_any_10031_10867(predicate_0, xs.tail, _y_x10774_0);
      });
    }
    else {
      if (x_0_11034) {
        return true;
      }
      else {
        {
          // tail call
          xs = xs.tail;
          continue tailcall;
        }
      }
    }
  }
  else {
    return false;
  }
}}
 
 
// unrolling of singleton matches of std/core/list/@unroll-any@10031
export function any(xs, predicate) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */  {
  if (xs === null) {
    return false;
  }
  else {
    return _unroll_any_10031(xs, predicate);
  }
}
 
 
// lifted local: sum, @spec-x10346
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10341, using:
// @uniq-f@10341 = std/core/int/(+)
export function _lift_sum_10369(_uniq_xs_10339, _uniq_z_10340) /* (list<int>, int) -> int */  { tailcall: while(1)
{
  if (_uniq_xs_10339 !== null) {
    {
      // tail call
      var _x128 = $std_core_int._lp__plus__rp_(_uniq_z_10340, _uniq_xs_10339.head);
      _uniq_xs_10339 = _uniq_xs_10339.tail;
      _uniq_z_10340 = _x128;
      continue tailcall;
    }
  }
  else {
    return _uniq_z_10340;
  }
}}
 
 
// Return the sum of a list of integers
export function sum(xs) /* (xs : list<int>) -> int */  {
  if (xs === null) {
    return 0;
  }
  else {
    return _lift_sum_10369(xs, 0);
  }
}
 
 
// lifted local: minimum, @spec-x10354
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10349, using:
// @uniq-f@10349 = std/core/int/min
export function _lift_minimum_10370(_uniq_xs_10347, _uniq_z_10348) /* (list<int>, int) -> int */  { tailcall: while(1)
{
  if (_uniq_xs_10347 !== null) {
    {
      // tail call
      var _x129 = $std_core_int.min(_uniq_z_10348, _uniq_xs_10347.head);
      _uniq_xs_10347 = _uniq_xs_10347.tail;
      _uniq_z_10348 = _x129;
      continue tailcall;
    }
  }
  else {
    return _uniq_z_10348;
  }
}}
 
 
// Returns the smallest element of a list of integers (or `default` (=`0`) for the empty list)
export function minimum(xs, $default) /* (xs : list<int>, default : ? int) -> int */  {
  if (xs === null) {
    return ($default !== undefined) ? $default : 0;
  }
  else {
    if (xs.tail === null) {
      return xs.head;
    }
    else {
      return _lift_minimum_10370(xs.tail, xs.head);
    }
  }
}
 
 
// lifted local: maximum, @spec-x10362
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10357, using:
// @uniq-f@10357 = std/core/int/max
export function _lift_maximum_10371(_uniq_xs_10355, _uniq_z_10356) /* (list<int>, int) -> int */  { tailcall: while(1)
{
  if (_uniq_xs_10355 !== null) {
    {
      // tail call
      var _x130 = $std_core_int.max(_uniq_z_10356, _uniq_xs_10355.head);
      _uniq_xs_10355 = _uniq_xs_10355.tail;
      _uniq_z_10356 = _x130;
      continue tailcall;
    }
  }
  else {
    return _uniq_z_10356;
  }
}}
 
 
// Returns the largest element of a list of integers (or `default` (=`0`) for the empty list)
export function maximum(xs, $default) /* (xs : list<int>, default : ? int) -> int */  {
  if (xs === null) {
    return ($default !== undefined) ? $default : 0;
  }
  else {
    if (xs.tail === null) {
      return xs.head;
    }
    else {
      return _lift_maximum_10371(xs.tail, xs.head);
    }
  }
}
 
 
// Split a string into a list of lines
export function lines(s) /* (s : string) -> list<string> */  {
   
  var v_10019 = ((s).split(("\n")));
  return $std_core_vector.vlist(v_10019);
}
 
 
// Join a list of strings with newlines
export function unlines(xs) /* (xs : list<string>) -> string */  {
  if (xs === null) {
    return "";
  }
  if (xs !== null && xs.tail === null) {
    return xs.head;
  }
  if (xs !== null && xs.tail !== null && xs.tail.tail === null) {
    if ((("\n") === (""))){
      return $std_core_types._lp__plus__plus__rp_(xs.head, xs.tail.head);
    }
  }
  return ((($std_core_vector.unvlist(xs))).join(("\n")));
}