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
export function _lift_length_4947(ys, acc) /* forall<a> (ys : list<a>, acc : int) -> int */  { tailcall: while(1)
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
 
 
// Returns the length of a list.
export function length(xs) /* forall<a> (xs : list<a>) -> int */  {
  return _lift_length_4947(xs, 0);
}
 
 
// Element-wise list equality
export function _lp__eq__eq__rp_(xs, ys, _implicit_fs__lp__eq__eq__rp_) /* forall<a> (xs : list<a>, ys : list<a>, ?(==) : (a, a) -> bool) -> bool */  { tailcall: while(1)
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
 
 
// Order on lists
export function cmp(xs, ys, _implicit_fs_cmp) /* forall<a> (xs : list<a>, ys : list<a>, ?cmp : (a, a) -> order) -> order */  { tailcall: while(1)
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
 
 
// Take the first `n` elements of a list (or fewer if the list is shorter than `n`)
export function _trmc_take(xs, n, _acc) /* forall<a> (xs : list<a>, n : int, ctx<list<a>>) -> list<a> */  { tailcall: while(1)
{
  if (xs !== null) {
    if ($std_core_types._int_gt(n,0)){
       
      var _trmc_x10055 = undefined;
       
      var _trmc_x10056 = $std_core_types.Cons(xs.head, _trmc_x10055);
      {
        // tail call
        var _x3 = $std_core_types._int_sub(n,1);
        var _x4 = $std_core_types._cctx_extend(_acc,_trmc_x10056,({obj: _trmc_x10056, field_name: "tail"}));
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
export function _lift_reverse_append_4948(acc, ys) /* forall<a> (acc : list<a>, ys : list<a>) -> list<a> */  { tailcall: while(1)
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
 
 
// Efficiently reverse a list `xs` and append it to `tl`:
// `reverse-append(xs,tl) == reserve(xs) ++ tl
export function reverse_append(xs, tl) /* forall<a> (xs : list<a>, tl : list<a>) -> list<a> */  {
  return _lift_reverse_append_4948(tl, xs);
}
 
 
// Reverse a list.
export function reverse(xs) /* forall<a> (xs : list<a>) -> list<a> */  {
  return _lift_reverse_append_4948($std_core_types.Nil, xs);
}
 
 
// Append two lists.
export function _trmc_append(xs, ys, _acc) /* forall<a> (xs : list<a>, ys : list<a>, ctx<list<a>>) -> list<a> */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var _trmc_x10057 = undefined;
     
    var _trmc_x10058 = $std_core_types.Cons(xs.head, _trmc_x10057);
    {
      // tail call
      var _x7 = $std_core_types._cctx_extend(_acc,_trmc_x10058,({obj: _trmc_x10058, field_name: "tail"}));
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
export function append(xs_0, ys_0) /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */  {
  return _trmc_append(xs_0, ys_0, $std_core_types._cctx_empty());
}
 
 
// Append two lists.
export function _lp__plus__plus__rp_(xs, ys) /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */  {
  return append(xs, ys);
}
 
 
// monadic lift
export function _mlift_foldl_10404(f, xx, _y_x10147) /* forall<a,b,e> (f : (b, a) -> e b, xx : list<a>, b) -> e b */  {
  return foldl(xx, _y_x10147, f);
}
 
 
// Fold a list from the left, i.e. `foldl([1,2],0,(+)) == (0+1)+2`
// Since `foldl` is tail recursive, it is preferred over `foldr` when using an associative function `f`
export function foldl(xs, z, f_0) /* forall<a,b,e> (xs : list<a>, z : b, f : (b, a) -> e b) -> e b */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_0_10448 = f_0(z, xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10147_0 /* 1073 */ ) {
        return _mlift_foldl_10404(f_0, xs.tail, _y_x10147_0);
      });
    }
    else {
      {
        // tail call
        xs = xs.tail;
        z = x_0_10448;
        continue tailcall;
      }
    }
  }
  else {
    return z;
  }
}}
 
 
// Fold a list from the right, i.e. `foldr([1,2],0,(+)) == 1+(2+0)`
// Note, `foldr` is less efficient than `foldl` as it reverses the list first.
export function foldr(xs, z, f) /* forall<a,b,e> (xs : list<a>, z : b, f : (a, b) -> e b) -> e b */  {
  return foldl(_lift_reverse_append_4948($std_core_types.Nil, xs), z, function(x /* 1117 */ , y /* 1116 */ ) {
      return f(y, x);
    });
}
 
export function foldl1(xs, f) /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */  {
  if (xs !== null) {
    return foldl(xs.tail, xs.head, f);
  }
  else {
    return $std_core_hnd._open_at2($std_core_hnd._evv_index($std_core_exn._tag_exn), $std_core_exn.$throw, "unexpected Nil in std/core/foldl1");
  }
}
 
export function foldr1(xs, f) /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */  {
   
  var xs_0_10010 = _lift_reverse_append_4948($std_core_types.Nil, xs);
  if (xs_0_10010 !== null) {
    return foldl(xs_0_10010.tail, xs_0_10010.head, f);
  }
  else {
    return $std_core_hnd._open_at2($std_core_hnd._evv_index($std_core_exn._tag_exn), $std_core_exn.$throw, "unexpected Nil in std/core/foldl1");
  }
}
 
 
// split a list at position `n`
export function split(xs, n) /* forall<a> (xs : list<a>, n : int) -> (list<a>, list<a>) */  {
  return $std_core_types.Tuple2(take(xs, n), drop(xs, n));
}
 
 
// monadic lift
export function _mlift_drop_while_10405(predicate, xs, xx, _y_x10158) /* forall<a,e> (predicate : (a) -> e bool, xs : list<a>, xx : list<a>, bool) -> e list<a> */  {
  if (_y_x10158) {
    return drop_while(xx, predicate);
  }
  else {
    return xs;
  }
}
 
 
// Drop all initial elements that satisfy `predicate`
export function drop_while(xs_0, predicate_0) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */  { tailcall: while(1)
{
  if (xs_0 !== null) {
     
    var x_0_10451 = predicate_0(xs_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10158_0 /* bool */ ) {
        return _mlift_drop_while_10405(predicate_0, xs_0, xs_0.tail, _y_x10158_0);
      });
    }
    else {
      if (x_0_10451) {
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
 
 
// monadic lift
export function _mlift_trmc_filter_10406(_acc, pred, x, xx, _y_x10162) /* forall<a,e> (ctx<list<a>>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */  {
  if (_y_x10162) {
     
    var _trmc_x10059 = undefined;
     
    var _trmc_x10060 = $std_core_types.Cons(x, _trmc_x10059);
    return _trmc_filter(xx, pred, $std_core_types._cctx_extend(_acc,_trmc_x10060,({obj: _trmc_x10060, field_name: "tail"})));
  }
  else {
    return _trmc_filter(xx, pred, _acc);
  }
}
 
 
// monadic lift
export function _mlift_trmcm_filter_10407(_accm, pred_0, x_0, xx_0, _y_x10167) /* forall<a,e> ((list<a>) -> list<a>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */  {
  if (_y_x10167) {
    return _trmcm_filter(xx_0, pred_0, function(_trmc_x10062 /* list<1325> */ ) {
        return _accm($std_core_types.Cons(x_0, _trmc_x10062));
      });
  }
  else {
    return _trmcm_filter(xx_0, pred_0, _accm);
  }
}
 
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filter([1,2,3],odd?) == [1,3]`
export function _trmc_filter(xs, pred_1, _acc_0) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, ctx<list<a>>) -> e list<a> */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_2_10454 = pred_1(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10162_0 /* bool */ ) {
        return _mlift_trmc_filter_10406(_acc_0, pred_1, xs.head, xs.tail, _y_x10162_0);
      });
    }
    else {
      if (x_2_10454) {
         
        var _trmc_x10059_0 = undefined;
         
        var _trmc_x10060_0 = $std_core_types.Cons(xs.head, _trmc_x10059_0);
        {
          // tail call
          var _x8 = $std_core_types._cctx_extend(_acc_0,_trmc_x10060_0,({obj: _trmc_x10060_0, field_name: "tail"}));
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
export function _trmcm_filter(xs_0, pred_2, _accm_0) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, (list<a>) -> list<a>) -> e list<a> */  { tailcall: while(1)
{
  if (xs_0 !== null) {
     
    var x_4_10457 = pred_2(xs_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10167_0 /* bool */ ) {
        return _mlift_trmcm_filter_10407(_accm_0, pred_2, xs_0.head, xs_0.tail, _y_x10167_0);
      });
    }
    else {
      if (x_4_10457) {
        {
          // tail call
          var _x11 = function(__at_accm_09 /* (list<1325>) -> list<1325> */ , _x_310 /* 1325 */ ) {
            return function(_trmc_x10062_0 /* list<1325> */ ) {
              return __at_accm_09($std_core_types.Cons(_x_310, _trmc_x10062_0));
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
export function filter(xs_1, pred_3) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e list<a> */  {
  var _x12 = $std_core_hnd._evv_is_affine();
  if (_x12) {
    return _trmc_filter(xs_1, pred_3, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_filter(xs_1, pred_3, function(_trmc_x10061 /* list<1325> */ ) {
        return _trmc_x10061;
      });
  }
}
 
 
// monadic lift
export function _mlift_trmc_filter_map_10408(_acc, pred, xx, _y_x10175) /* forall<a,b,e> (ctx<list<b>>, pred : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */  {
  if (_y_x10175 === null) {
    return _trmc_filter_map(xx, pred, _acc);
  }
  else {
     
    var _trmc_x10063 = undefined;
     
    var _trmc_x10064 = $std_core_types.Cons(_y_x10175.value, _trmc_x10063);
    return _trmc_filter_map(xx, pred, $std_core_types._cctx_extend(_acc,_trmc_x10064,({obj: _trmc_x10064, field_name: "tail"})));
  }
}
 
 
// monadic lift
export function _mlift_trmcm_filter_map_10409(_accm, pred_0, xx_0, _y_x10180) /* forall<a,b,e> ((list<b>) -> list<b>, pred : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */  {
  if (_y_x10180 === null) {
    return _trmcm_filter_map(xx_0, pred_0, _accm);
  }
  else {
    return _trmcm_filter_map(xx_0, pred_0, function(_trmc_x10066 /* list<1393> */ ) {
        return _accm($std_core_types.Cons(_y_x10180.value, _trmc_x10066));
      });
  }
}
 
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if i.odd? then Nothing else Just(i*i) }) == [4]`
export function _trmc_filter_map(xs, pred_1, _acc_0) /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */  { tailcall: while(1)
{
  if (xs === null) {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
  else {
     
    var x_0_10460 = pred_1(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10175_0 /* maybe<1393> */ ) {
        return _mlift_trmc_filter_map_10408(_acc_0, pred_1, xs.tail, _y_x10175_0);
      });
    }
    else {
      if (x_0_10460 === null) {
        {
          // tail call
          xs = xs.tail;
          continue tailcall;
        }
      }
      else {
         
        var _trmc_x10063_0 = undefined;
         
        var _trmc_x10064_0 = $std_core_types.Cons(x_0_10460.value, _trmc_x10063_0);
        {
          // tail call
          var _x13 = $std_core_types._cctx_extend(_acc_0,_trmc_x10064_0,({obj: _trmc_x10064_0, field_name: "tail"}));
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
export function _trmcm_filter_map(xs_0, pred_2, _accm_0) /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>, (list<b>) -> list<b>) -> e list<b> */  { tailcall: while(1)
{
  if (xs_0 === null) {
    return _accm_0($std_core_types.Nil);
  }
  else {
     
    var x_2_10463 = pred_2(xs_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10180_0 /* maybe<1393> */ ) {
        return _mlift_trmcm_filter_map_10409(_accm_0, pred_2, xs_0.tail, _y_x10180_0);
      });
    }
    else {
      if (x_2_10463 === null) {
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
            return function(_trmc_x10066_0 /* list<1393> */ ) {
              return __at_accm_014($std_core_types.Cons(_y_215, _trmc_x10066_0));
            };
          }(_accm_0, x_2_10463.value);
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
export function filter_map(xs_1, pred_3) /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>) -> e list<b> */  {
  var _x17 = $std_core_hnd._evv_is_affine();
  if (_x17) {
    return _trmc_filter_map(xs_1, pred_3, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_filter_map(xs_1, pred_3, function(_trmc_x10065 /* list<1393> */ ) {
        return _trmc_x10065;
      });
  }
}
 
 
// monadic lift
export function _mlift_foreach_while_10410(action, xx, _y_x10188) /* forall<a,b,e> (action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e maybe<b> */  {
  if (_y_x10188 === null) {
    return foreach_while(xx, action);
  }
  else {
    return _y_x10188;
  }
}
 
 
// Invoke `action` for each element of a list while `action` return `Nothing`
export function foreach_while(xs, action_0) /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e maybe<b> */  { tailcall: while(1)
{
  if (xs === null) {
    return $std_core_types.Nothing;
  }
  else {
     
    var x_0_10466 = action_0(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10188_0 /* maybe<1454> */ ) {
        return _mlift_foreach_while_10410(action_0, xs.tail, _y_x10188_0);
      });
    }
    else {
      if (x_0_10466 === null) {
        {
          // tail call
          xs = xs.tail;
          continue tailcall;
        }
      }
      else {
        return x_0_10466;
      }
    }
  }
}}
 
 
// monadic lift
export function _mlift_find_10411(x, _y_x10192) /* forall<a,e> (x : a, bool) -> e maybe<a> */  {
  if (_y_x10192) {
    return $std_core_types.Just(x);
  }
  else {
    return $std_core_types.Nothing;
  }
}
 
 
// Find the first element satisfying some predicate
export function find(xs, pred) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e maybe<a> */  {
  return foreach_while(xs, function(x /* 1515 */ ) {
       
      var x_0_10469 = pred(x);
       
      function next_10470(_y_x10192) /* (bool) -> 1516 maybe<1515> */  {
        if (_y_x10192) {
          return $std_core_types.Just(x);
        }
        else {
          return $std_core_types.Nothing;
        }
      }
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(next_10470);
      }
      else {
        return next_10470(x_0_10469);
      }
    });
}
 
 
// Find the first element satisfying some predicate and return it.
export function find_maybe(xs, pred) /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>) -> e maybe<b> */  {
  return foreach_while(xs, pred);
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
     
    var _trmc_x10067 = undefined;
     
    var _trmc_x10068 = $std_core_types.Cons(lo, _trmc_x10067);
    {
      // tail call
      var _x18 = $std_core_types._int_add(lo,1);
      var _x19 = $std_core_types._cctx_extend(_acc,_trmc_x10068,({obj: _trmc_x10068, field_name: "tail"}));
      lo = _x18;
      _acc = _x19;
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
export function _mlift_trmc_map_10412(_acc, f, xx, _trmc_x10069) /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e b, xx : list<a>, b) -> e list<b> */  {
   
  var _trmc_x10070 = undefined;
   
  var _trmc_x10071 = $std_core_types.Cons(_trmc_x10069, _trmc_x10070);
  return _trmc_map(xx, f, $std_core_types._cctx_extend(_acc,_trmc_x10071,({obj: _trmc_x10071, field_name: "tail"})));
}
 
 
// monadic lift
export function _mlift_trmcm_map_10413(_accm, f_0, xx_0, _trmc_x10074) /* forall<a,b,e> ((list<b>) -> list<b>, f : (a) -> e b, xx : list<a>, b) -> e list<b> */  {
  return _trmcm_map(xx_0, f_0, function(_trmc_x10073 /* list<1969> */ ) {
      return _accm($std_core_types.Cons(_trmc_x10074, _trmc_x10073));
    });
}
 
 
// Apply a function `f` to each element of the input list in sequence.
export function _trmc_map(xs, f_1, _acc_0) /* forall<a,b,e> (xs : list<a>, f : (a) -> e b, ctx<list<b>>) -> e list<b> */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_0_10473 = f_1(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10069_0 /* 1969 */ ) {
        return _mlift_trmc_map_10412(_acc_0, f_1, xs.tail, _trmc_x10069_0);
      });
    }
    else {
       
      var _trmc_x10070_0 = undefined;
       
      var _trmc_x10071_0 = $std_core_types.Cons(x_0_10473, _trmc_x10070_0);
      {
        // tail call
        var _x20 = $std_core_types._cctx_extend(_acc_0,_trmc_x10071_0,({obj: _trmc_x10071_0, field_name: "tail"}));
        xs = xs.tail;
        _acc_0 = _x20;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
}}
 
 
// Apply a function `f` to each element of the input list in sequence.
export function _trmcm_map(xs_0, f_2, _accm_0) /* forall<a,b,e> (xs : list<a>, f : (a) -> e b, (list<b>) -> list<b>) -> e list<b> */  { tailcall: while(1)
{
  if (xs_0 !== null) {
     
    var x_2_10476 = f_2(xs_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10074_0 /* 1969 */ ) {
        return _mlift_trmcm_map_10413(_accm_0, f_2, xs_0.tail, _trmc_x10074_0);
      });
    }
    else {
      {
        // tail call
        var _x23 = function(__at_accm_021 /* (list<1969>) -> list<1969> */ , _x_2_1047622 /* 1969 */ ) {
          return function(_trmc_x10073_0 /* list<1969> */ ) {
            return __at_accm_021($std_core_types.Cons(_x_2_1047622, _trmc_x10073_0));
          };
        }(_accm_0, x_2_10476);
        xs_0 = xs_0.tail;
        _accm_0 = _x23;
        continue tailcall;
      }
    }
  }
  else {
    return _accm_0($std_core_types.Nil);
  }
}}
 
 
// Apply a function `f` to each element of the input list in sequence.
export function map(xs_1, f_3) /* forall<a,b,e> (xs : list<a>, f : (a) -> e b) -> e list<b> */  {
  var _x24 = $std_core_hnd._evv_is_affine();
  if (_x24) {
    return _trmc_map(xs_1, f_3, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_map(xs_1, f_3, function(_trmc_x10072 /* list<1969> */ ) {
        return _trmc_x10072;
      });
  }
}
 
 
// Create a list of characters from `lo`  to `hi`  (including `hi`).
export function char_fs_list(lo, hi) /* (lo : char, hi : char) -> list<char> */  {
  return map(list(lo, hi), (function(_x25) {
      return (_x25);
    }));
}
 
 
// monadic lift
export function function_fs__mlift_trmc_list_10414(_acc, f, hi, lo, _trmc_x10075) /* forall<a,e> (ctx<list<a>>, f : (int) -> e a, hi : int, lo : int, a) -> e list<a> */  {
   
  var _trmc_x10076 = undefined;
   
  var _trmc_x10077 = $std_core_types.Cons(_trmc_x10075, _trmc_x10076);
  return function_fs__trmc_list($std_core_types._int_add(lo,1), hi, f, $std_core_types._cctx_extend(_acc,_trmc_x10077,({obj: _trmc_x10077, field_name: "tail"})));
}
 
 
// monadic lift
export function function_fs__mlift_trmcm_list_10415(_accm, f_0, hi_0, lo_0, _trmc_x10080) /* forall<a,e> ((list<a>) -> list<a>, f : (int) -> e a, hi : int, lo : int, a) -> e list<a> */  {
  return function_fs__trmcm_list($std_core_types._int_add(lo_0,1), hi_0, f_0, function(_trmc_x10079 /* list<1754> */ ) {
      return _accm($std_core_types.Cons(_trmc_x10080, _trmc_x10079));
    });
}
 
 
// Applies a function `f` to list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.
export function function_fs__trmc_list(lo_1, hi_1, f_1, _acc_0) /* forall<a,e> (lo : int, hi : int, f : (int) -> e a, ctx<list<a>>) -> e list<a> */  { tailcall: while(1)
{
  if ($std_core_types._int_le(lo_1,hi_1)) {
     
    var x_10479 = f_1(lo_1);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10075_0 /* 1754 */ ) {
        return function_fs__mlift_trmc_list_10414(_acc_0, f_1, hi_1, lo_1, _trmc_x10075_0);
      });
    }
    else {
       
      var _trmc_x10076_0 = undefined;
       
      var _trmc_x10077_0 = $std_core_types.Cons(x_10479, _trmc_x10076_0);
      {
        // tail call
        var _x26 = $std_core_types._int_add(lo_1,1);
        var _x27 = $std_core_types._cctx_extend(_acc_0,_trmc_x10077_0,({obj: _trmc_x10077_0, field_name: "tail"}));
        lo_1 = _x26;
        _acc_0 = _x27;
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
     
    var x_0_10482 = f_2(lo_2);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10080_0 /* 1754 */ ) {
        return function_fs__mlift_trmcm_list_10415(_accm_0, f_2, hi_2, lo_2, _trmc_x10080_0);
      });
    }
    else {
      {
        // tail call
        var _x30 = $std_core_types._int_add(lo_2,1);
        var _x31 = function(__at_accm_028 /* (list<1754>) -> list<1754> */ , _x_0_1048229 /* 1754 */ ) {
          return function(_trmc_x10079_0 /* list<1754> */ ) {
            return __at_accm_028($std_core_types.Cons(_x_0_1048229, _trmc_x10079_0));
          };
        }(_accm_0, x_0_10482);
        lo_2 = _x30;
        _accm_0 = _x31;
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
  var _x32 = $std_core_hnd._evv_is_affine();
  if (_x32) {
    return function_fs__trmc_list(lo_3, hi_3, f_3, $std_core_types._cctx_empty());
  }
  else {
    return function_fs__trmcm_list(lo_3, hi_3, f_3, function(_trmc_x10078 /* list<1754> */ ) {
        return _trmc_x10078;
      });
  }
}
 
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.
export function stride_fs__trmc_list(lo, hi, stride, _acc) /* (lo : int, hi : int, stride : int, ctx<list<int>>) -> list<int> */  { tailcall: while(1)
{
  if ($std_core_types._int_le(lo,hi)) {
     
    var _trmc_x10081 = undefined;
     
    var _trmc_x10082 = $std_core_types.Cons(lo, _trmc_x10081);
    {
      // tail call
      var _x33 = $std_core_types._int_add(lo,stride);
      var _x34 = $std_core_types._cctx_extend(_acc,_trmc_x10082,({obj: _trmc_x10082, field_name: "tail"}));
      lo = _x33;
      _acc = _x34;
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
export function stridefunction_fs__mlift_trmc_list_10416(_acc, f, hi, lo, stride, _trmc_x10083) /* forall<a,e> (ctx<list<a>>, f : (int) -> e a, hi : int, lo : int, stride : int, a) -> e list<a> */  {
   
  var _trmc_x10084 = undefined;
   
  var _trmc_x10085 = $std_core_types.Cons(_trmc_x10083, _trmc_x10084);
  return stridefunction_fs__trmc_list($std_core_types._int_add(lo,stride), hi, stride, f, $std_core_types._cctx_extend(_acc,_trmc_x10085,({obj: _trmc_x10085, field_name: "tail"})));
}
 
 
// monadic lift
export function stridefunction_fs__mlift_trmcm_list_10417(_accm, f_0, hi_0, lo_0, stride_0, _trmc_x10088) /* forall<a,e> ((list<a>) -> list<a>, f : (int) -> e a, hi : int, lo : int, stride : int, a) -> e list<a> */  {
  return stridefunction_fs__trmcm_list($std_core_types._int_add(lo_0,stride_0), hi_0, stride_0, f_0, function(_trmc_x10087 /* list<1873> */ ) {
      return _accm($std_core_types.Cons(_trmc_x10088, _trmc_x10087));
    });
}
 
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.
export function stridefunction_fs__trmc_list(lo_1, hi_1, stride_1, f_1, _acc_0) /* forall<a,e> (lo : int, hi : int, stride : int, f : (int) -> e a, ctx<list<a>>) -> e list<a> */  { tailcall: while(1)
{
  if ($std_core_types._int_le(lo_1,hi_1)) {
     
    var x_10485 = f_1(lo_1);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10083_0 /* 1873 */ ) {
        return stridefunction_fs__mlift_trmc_list_10416(_acc_0, f_1, hi_1, lo_1, stride_1, _trmc_x10083_0);
      });
    }
    else {
       
      var _trmc_x10084_0 = undefined;
       
      var _trmc_x10085_0 = $std_core_types.Cons(x_10485, _trmc_x10084_0);
      {
        // tail call
        var _x35 = $std_core_types._int_add(lo_1,stride_1);
        var _x36 = $std_core_types._cctx_extend(_acc_0,_trmc_x10085_0,({obj: _trmc_x10085_0, field_name: "tail"}));
        lo_1 = _x35;
        _acc_0 = _x36;
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
     
    var x_0_10488 = f_2(lo_2);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10088_0 /* 1873 */ ) {
        return stridefunction_fs__mlift_trmcm_list_10417(_accm_0, f_2, hi_2, lo_2, stride_2, _trmc_x10088_0);
      });
    }
    else {
      {
        // tail call
        var _x39 = $std_core_types._int_add(lo_2,stride_2);
        var _x40 = function(__at_accm_037 /* (list<1873>) -> list<1873> */ , _x_0_1048838 /* 1873 */ ) {
          return function(_trmc_x10087_0 /* list<1873> */ ) {
            return __at_accm_037($std_core_types.Cons(_x_0_1048838, _trmc_x10087_0));
          };
        }(_accm_0, x_0_10488);
        lo_2 = _x39;
        _accm_0 = _x40;
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
  var _x41 = $std_core_hnd._evv_is_affine();
  if (_x41) {
    return stridefunction_fs__trmc_list(lo_3, hi_3, stride_3, f_3, $std_core_types._cctx_empty());
  }
  else {
    return stridefunction_fs__trmcm_list(lo_3, hi_3, stride_3, f_3, function(_trmc_x10086 /* list<1873> */ ) {
        return _trmc_x10086;
      });
  }
}
 
 
// Apply a function `f` to each character in a string
export function string_fs_map(s, f) /* forall<e> (s : string, f : (char) -> e char) -> e string */  {
   
  var x_10491 = map($std_core_string.list(s), f);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend($std_core_string.listchar_fs_string);
  }
  else {
    return $std_core_string.listchar_fs_string(x_10491);
  }
}
 
 
// monadic lift
export function _mlift_trmc_lift_map_indexed_4949_10418(_acc, f, i_0_10018, yy, _trmc_x10089) /* forall<a,b,e> (ctx<list<b>>, f : (idx : int, value : a) -> e b, i@0@10018 : int, yy : list<a>, b) -> e list<b> */  {
   
  var _trmc_x10090 = undefined;
   
  var _trmc_x10091 = $std_core_types.Cons(_trmc_x10089, _trmc_x10090);
  return _trmc_lift_map_indexed_4949(f, yy, i_0_10018, $std_core_types._cctx_extend(_acc,_trmc_x10091,({obj: _trmc_x10091, field_name: "tail"})));
}
 
 
// monadic lift
export function _mlift_trmcm_lift_map_indexed_4949_10419(_accm, f_0, i_0_10018_0, yy_0, _trmc_x10094) /* forall<a,b,e> ((list<b>) -> list<b>, f : (idx : int, value : a) -> e b, i@0@10018 : int, yy : list<a>, b) -> e list<b> */  {
  return _trmcm_lift_map_indexed_4949(f_0, yy_0, i_0_10018_0, function(_trmc_x10093 /* list<2069> */ ) {
      return _accm($std_core_types.Cons(_trmc_x10094, _trmc_x10093));
    });
}
 
 
// lifted local: map-indexed, map-idx
export function _trmc_lift_map_indexed_4949(f_1, ys, i, _acc_0) /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int, ctx<list<b>>) -> e list<b> */  { tailcall: while(1)
{
  if (ys !== null) {
     
    var i_0_10018_1 = $std_core_types._int_add(i,1);
     
    var x_10493 = f_1(i, ys.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10089_0 /* 2069 */ ) {
        return _mlift_trmc_lift_map_indexed_4949_10418(_acc_0, f_1, i_0_10018_1, ys.tail, _trmc_x10089_0);
      });
    }
    else {
       
      var _trmc_x10090_0 = undefined;
       
      var _trmc_x10091_0 = $std_core_types.Cons(x_10493, _trmc_x10090_0);
      {
        // tail call
        var _x42 = $std_core_types._cctx_extend(_acc_0,_trmc_x10091_0,({obj: _trmc_x10091_0, field_name: "tail"}));
        ys = ys.tail;
        i = i_0_10018_1;
        _acc_0 = _x42;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
}}
 
 
// lifted local: map-indexed, map-idx
export function _trmcm_lift_map_indexed_4949(f_2, ys_0, i_0, _accm_0) /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int, (list<b>) -> list<b>) -> e list<b> */  { tailcall: while(1)
{
  if (ys_0 !== null) {
     
    var i_0_10018_2 = $std_core_types._int_add(i_0,1);
     
    var x_0_10496 = f_2(i_0, ys_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10094_0 /* 2069 */ ) {
        return _mlift_trmcm_lift_map_indexed_4949_10419(_accm_0, f_2, i_0_10018_2, ys_0.tail, _trmc_x10094_0);
      });
    }
    else {
      {
        // tail call
        var _x45 = function(__at_accm_043 /* (list<2069>) -> list<2069> */ , _x_0_1049644 /* 2069 */ ) {
          return function(_trmc_x10093_0 /* list<2069> */ ) {
            return __at_accm_043($std_core_types.Cons(_x_0_1049644, _trmc_x10093_0));
          };
        }(_accm_0, x_0_10496);
        ys_0 = ys_0.tail;
        i_0 = i_0_10018_2;
        _accm_0 = _x45;
        continue tailcall;
      }
    }
  }
  else {
    return _accm_0($std_core_types.Nil);
  }
}}
 
 
// lifted local: map-indexed, map-idx
export function _lift_map_indexed_4949(f_3, ys_1, i_1) /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int) -> e list<b> */  {
  var _x46 = $std_core_hnd._evv_is_affine();
  if (_x46) {
    return _trmc_lift_map_indexed_4949(f_3, ys_1, i_1, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_lift_map_indexed_4949(f_3, ys_1, i_1, function(_trmc_x10092 /* list<2069> */ ) {
        return _trmc_x10092;
      });
  }
}
 
 
// Apply a function `f` to each element of the input list in sequence where takes
// both the index of the current element and the element itself as arguments.
export function map_indexed(xs, f) /* forall<a,b,e> (xs : list<a>, f : (idx : int, value : a) -> e b) -> e list<b> */  {
  return _lift_map_indexed_4949(f, xs, 0);
}
 
 
// monadic lift
export function _mlift_trmc_lift_map_peek_4950_10420(_acc, f, yy, _trmc_x10095) /* forall<a,b,e> (ctx<list<b>>, f : (value : a, rest : list<a>) -> e b, yy : list<a>, b) -> e list<b> */  {
   
  var _trmc_x10096 = undefined;
   
  var _trmc_x10097 = $std_core_types.Cons(_trmc_x10095, _trmc_x10096);
  return _trmc_lift_map_peek_4950(f, yy, $std_core_types._cctx_extend(_acc,_trmc_x10097,({obj: _trmc_x10097, field_name: "tail"})));
}
 
 
// monadic lift
export function _mlift_trmcm_lift_map_peek_4950_10421(_accm, f_0, yy_0, _trmc_x10100) /* forall<a,b,e> ((list<b>) -> list<b>, f : (value : a, rest : list<a>) -> e b, yy : list<a>, b) -> e list<b> */  {
  return _trmcm_lift_map_peek_4950(f_0, yy_0, function(_trmc_x10099 /* list<2121> */ ) {
      return _accm($std_core_types.Cons(_trmc_x10100, _trmc_x10099));
    });
}
 
 
// lifted local: map-peek, mappeek
export function _trmc_lift_map_peek_4950(f_1, ys, _acc_0) /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>, ctx<list<b>>) -> e list<b> */  { tailcall: while(1)
{
  if (ys !== null) {
     
    var x_10499 = f_1(ys.head, ys.tail);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10095_0 /* 2121 */ ) {
        return _mlift_trmc_lift_map_peek_4950_10420(_acc_0, f_1, ys.tail, _trmc_x10095_0);
      });
    }
    else {
       
      var _trmc_x10096_0 = undefined;
       
      var _trmc_x10097_0 = $std_core_types.Cons(x_10499, _trmc_x10096_0);
      {
        // tail call
        var _x47 = $std_core_types._cctx_extend(_acc_0,_trmc_x10097_0,({obj: _trmc_x10097_0, field_name: "tail"}));
        ys = ys.tail;
        _acc_0 = _x47;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
}}
 
 
// lifted local: map-peek, mappeek
export function _trmcm_lift_map_peek_4950(f_2, ys_0, _accm_0) /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>, (list<b>) -> list<b>) -> e list<b> */  { tailcall: while(1)
{
  if (ys_0 !== null) {
     
    var x_0_10502 = f_2(ys_0.head, ys_0.tail);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10100_0 /* 2121 */ ) {
        return _mlift_trmcm_lift_map_peek_4950_10421(_accm_0, f_2, ys_0.tail, _trmc_x10100_0);
      });
    }
    else {
      {
        // tail call
        var _x50 = function(__at_accm_048 /* (list<2121>) -> list<2121> */ , _x_0_1050249 /* 2121 */ ) {
          return function(_trmc_x10099_0 /* list<2121> */ ) {
            return __at_accm_048($std_core_types.Cons(_x_0_1050249, _trmc_x10099_0));
          };
        }(_accm_0, x_0_10502);
        ys_0 = ys_0.tail;
        _accm_0 = _x50;
        continue tailcall;
      }
    }
  }
  else {
    return _accm_0($std_core_types.Nil);
  }
}}
 
 
// lifted local: map-peek, mappeek
export function _lift_map_peek_4950(f_3, ys_1) /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>) -> e list<b> */  {
  var _x51 = $std_core_hnd._evv_is_affine();
  if (_x51) {
    return _trmc_lift_map_peek_4950(f_3, ys_1, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_lift_map_peek_4950(f_3, ys_1, function(_trmc_x10098 /* list<2121> */ ) {
        return _trmc_x10098;
      });
  }
}
 
 
// Apply a function `f` to each element of the input list in sequence where `f` takes
// both the current element and the tail list as arguments.
export function map_peek(xs, f) /* forall<a,b,e> (xs : list<a>, f : (value : a, rest : list<a>) -> e b) -> e list<b> */  {
  return _lift_map_peek_4950(f, xs);
}
 
 
// monadic lift
export function _mlift_trmc_lift_map_indexed_peek_4951_10422(_acc, f, i_0_10021, yy, _trmc_x10101) /* forall<a,b,e> (ctx<list<b>>, f : (idx : int, value : a, rest : list<a>) -> e b, i@0@10021 : int, yy : list<a>, b) -> e list<b> */  {
   
  var _trmc_x10102 = undefined;
   
  var _trmc_x10103 = $std_core_types.Cons(_trmc_x10101, _trmc_x10102);
  return _trmc_lift_map_indexed_peek_4951(f, yy, i_0_10021, $std_core_types._cctx_extend(_acc,_trmc_x10103,({obj: _trmc_x10103, field_name: "tail"})));
}
 
 
// monadic lift
export function _mlift_trmcm_lift_map_indexed_peek_4951_10423(_accm, f_0, i_0_10021_0, yy_0, _trmc_x10106) /* forall<a,b,e> ((list<b>) -> list<b>, f : (idx : int, value : a, rest : list<a>) -> e b, i@0@10021 : int, yy : list<a>, b) -> e list<b> */  {
  return _trmcm_lift_map_indexed_peek_4951(f_0, yy_0, i_0_10021_0, function(_trmc_x10105 /* list<2183> */ ) {
      return _accm($std_core_types.Cons(_trmc_x10106, _trmc_x10105));
    });
}
 
 
// lifted local: map-indexed-peek, mapidx
export function _trmc_lift_map_indexed_peek_4951(f_1, ys, i, _acc_0) /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int, ctx<list<b>>) -> e list<b> */  { tailcall: while(1)
{
  if (ys !== null) {
     
    var i_0_10021_1 = $std_core_types._int_add(i,1);
     
    var x_10505 = f_1(i, ys.head, ys.tail);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10101_0 /* 2183 */ ) {
        return _mlift_trmc_lift_map_indexed_peek_4951_10422(_acc_0, f_1, i_0_10021_1, ys.tail, _trmc_x10101_0);
      });
    }
    else {
       
      var _trmc_x10102_0 = undefined;
       
      var _trmc_x10103_0 = $std_core_types.Cons(x_10505, _trmc_x10102_0);
      {
        // tail call
        var _x52 = $std_core_types._cctx_extend(_acc_0,_trmc_x10103_0,({obj: _trmc_x10103_0, field_name: "tail"}));
        ys = ys.tail;
        i = i_0_10021_1;
        _acc_0 = _x52;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
}}
 
 
// lifted local: map-indexed-peek, mapidx
export function _trmcm_lift_map_indexed_peek_4951(f_2, ys_0, i_0, _accm_0) /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int, (list<b>) -> list<b>) -> e list<b> */  { tailcall: while(1)
{
  if (ys_0 !== null) {
     
    var i_0_10021_2 = $std_core_types._int_add(i_0,1);
     
    var x_0_10508 = f_2(i_0, ys_0.head, ys_0.tail);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_trmc_x10106_0 /* 2183 */ ) {
        return _mlift_trmcm_lift_map_indexed_peek_4951_10423(_accm_0, f_2, i_0_10021_2, ys_0.tail, _trmc_x10106_0);
      });
    }
    else {
      {
        // tail call
        var _x55 = function(__at_accm_053 /* (list<2183>) -> list<2183> */ , _x_0_1050854 /* 2183 */ ) {
          return function(_trmc_x10105_0 /* list<2183> */ ) {
            return __at_accm_053($std_core_types.Cons(_x_0_1050854, _trmc_x10105_0));
          };
        }(_accm_0, x_0_10508);
        ys_0 = ys_0.tail;
        i_0 = i_0_10021_2;
        _accm_0 = _x55;
        continue tailcall;
      }
    }
  }
  else {
    return _accm_0($std_core_types.Nil);
  }
}}
 
 
// lifted local: map-indexed-peek, mapidx
export function _lift_map_indexed_peek_4951(f_3, ys_1, i_1) /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int) -> e list<b> */  {
  var _x56 = $std_core_hnd._evv_is_affine();
  if (_x56) {
    return _trmc_lift_map_indexed_peek_4951(f_3, ys_1, i_1, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_lift_map_indexed_peek_4951(f_3, ys_1, i_1, function(_trmc_x10104 /* list<2183> */ ) {
        return _trmc_x10104;
      });
  }
}
 
 
// Apply a function `f` to each element of the input list in sequence where takes
// both the index of the current element, the element itself, and the tail list as arguments.
export function map_indexed_peek(xs, f) /* forall<a,b,e> (xs : list<a>, f : (idx : int, value : a, rest : list<a>) -> e b) -> e list<b> */  {
  return _lift_map_indexed_peek_4951(f, xs, 0);
}
 
 
// Create a list of `n` repeated elements `x`
export function _trmc_replicate(x, n, _acc) /* forall<a> (x : a, n : int, ctx<list<a>>) -> list<a> */  { tailcall: while(1)
{
  if ($std_core_types._int_gt(n,0)) {
     
    var _trmc_x10107 = undefined;
     
    var _trmc_x10108 = $std_core_types.Cons(x, _trmc_x10107);
    {
      // tail call
      var _x57 = $std_core_types._int_sub(n,1);
      var _x58 = $std_core_types._cctx_extend(_acc,_trmc_x10108,({obj: _trmc_x10108, field_name: "tail"}));
      n = _x57;
      _acc = _x58;
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
export function _mlift_remove_10424(_y_x10253) /* forall<e> (bool) -> e bool */  {
  return (_y_x10253) ? false : true;
}
 
 
// Remove those elements of a list that satisfy the given predicate `pred`.
// For example: `remove([1,2,3],odd?) == [2]`
export function remove(xs, pred) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e list<a> */  {
  return filter(xs, function(x /* 2269 */ ) {
       
      var x_0_10511 = pred(x);
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(_y_x10253 /* bool */ ) {
          return (_y_x10253) ? false : true;
        });
      }
      else {
        return (x_0_10511) ? false : true;
      }
    });
}
 
 
// monadic lift
export function _mlift_partition_acc_10425(acc1, acc2, pred, x, xx, _y_x10255) /* forall<a,e> (acc1 : ctx<list<a>>, acc2 : ctx<list<a>>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e (list<a>, list<a>) */  {
  if (_y_x10255) {
     
    var _cctx_x2361 = $std_core_types.Cons(x, undefined);
     
    var _cctx_x2362 = {obj: _cctx_x2361, field_name: "tail"};
    return partition_acc(xx, pred, $std_core_types._cctx_compose(acc1,($std_core_types._cctx_create(_cctx_x2361,_cctx_x2362))), acc2);
  }
  else {
     
    var _cctx_x2404 = $std_core_types.Cons(x, undefined);
     
    var _cctx_x2405 = {obj: _cctx_x2404, field_name: "tail"};
    return partition_acc(xx, pred, acc1, $std_core_types._cctx_compose(acc2,($std_core_types._cctx_create(_cctx_x2404,_cctx_x2405))));
  }
}
 
export function partition_acc(xs, pred_0, acc1_0, acc2_0) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, acc1 : ctx<list<a>>, acc2 : ctx<list<a>>) -> e (list<a>, list<a>) */  { tailcall: while(1)
{
  if (xs === null) {
    return $std_core_types.Tuple2($std_core_types._cctx_apply(acc1_0,($std_core_types.Nil)), $std_core_types._cctx_apply(acc2_0,($std_core_types.Nil)));
  }
  else {
     
    var x_1_10514 = pred_0(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10255_0 /* bool */ ) {
        return _mlift_partition_acc_10425(acc1_0, acc2_0, pred_0, xs.head, xs.tail, _y_x10255_0);
      });
    }
    else {
      if (x_1_10514) {
         
        var _cctx_x2361_0 = $std_core_types.Cons(xs.head, undefined);
         
        var _cctx_x2362_0 = {obj: _cctx_x2361_0, field_name: "tail"};
        {
          // tail call
          var _x59 = $std_core_types._cctx_compose(acc1_0,($std_core_types._cctx_create(_cctx_x2361_0,_cctx_x2362_0)));
          xs = xs.tail;
          acc1_0 = _x59;
          continue tailcall;
        }
      }
      else {
         
        var _cctx_x2404_0 = $std_core_types.Cons(xs.head, undefined);
         
        var _cctx_x2405_0 = {obj: _cctx_x2404_0, field_name: "tail"};
        {
          // tail call
          var _x60 = $std_core_types._cctx_compose(acc2_0,($std_core_types._cctx_create(_cctx_x2404_0,_cctx_x2405_0)));
          xs = xs.tail;
          acc2_0 = _x60;
          continue tailcall;
        }
      }
    }
  }
}}
 
 
// Partition a list in two lists where the first list contains
// those elements that satisfy the given predicate `pred`.
// For example: `partition([1,2,3],odd?) == ([1,3],[2])`
export function partition(xs, pred) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e (list<a>, list<a>) */  {
  return partition_acc(xs, pred, $std_core_types._cctx_empty(), $std_core_types._cctx_empty());
}
 
 
// monadic lift
export function _mlift_lookup_10426(kv, _y_x10261) /* forall<a,b,e> (kv : (a, b), bool) -> e maybe<b> */  {
  if (_y_x10261) {
    var _x61 = kv.snd;
    return $std_core_types.Just(_x61);
  }
  else {
    return $std_core_types.Nothing;
  }
}
 
 
// Lookup the first element satisfying some predicate
export function lookup(xs, pred) /* forall<a,b,e> (xs : list<(a, b)>, pred : (a) -> e bool) -> e maybe<b> */  {
  return foreach_while(xs, function(kv /* (2578, 2579) */ ) {
       
      var _x62 = kv.fst;
      var x_10517 = pred(_x62);
       
      function next_10518(_y_x10261) /* (bool) -> 2580 maybe<2579> */  {
        if (_y_x10261) {
          var _x63 = kv.snd;
          return $std_core_types.Just(_x63);
        }
        else {
          return $std_core_types.Nothing;
        }
      }
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(next_10518);
      }
      else {
        return next_10518(x_10517);
      }
    });
}
 
 
// monadic lift
export function _mlift_index_of_acc_10427(idx, pred, xx, _y_x10264) /* forall<a,e> (idx : int, pred : (a) -> e bool, xx : list<a>, bool) -> e int */  {
  if (_y_x10264) {
    return idx;
  }
  else {
    return index_of_acc(xx, pred, $std_core_types._int_add(idx,1));
  }
}
 
export function index_of_acc(xs, pred_0, idx_0) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, idx : int) -> e int */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_0_10521 = pred_0(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10264_0 /* bool */ ) {
        return _mlift_index_of_acc_10427(idx_0, pred_0, xs.tail, _y_x10264_0);
      });
    }
    else {
      if (x_0_10521) {
        return idx_0;
      }
      else {
        {
          // tail call
          var _x62 = $std_core_types._int_add(idx_0,1);
          xs = xs.tail;
          idx_0 = _x62;
          continue tailcall;
        }
      }
    }
  }
  else {
    return -1;
  }
}}
 
 
// Returns the index of the first element where `pred` holds, or `-1` if no such element exists.
export function index_of(xs, pred) /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e int */  {
  return index_of_acc(xs, pred, 0);
}
 
 
// monadic lift
export function _mlift_foreach_10428(action, xx, wild__) /* forall<a,e> (action : (a) -> e (), xx : list<a>, wild_ : ()) -> e () */  {
  return foreach(xx, action);
}
 
 
// Invoke `action` for each element of a list
export function foreach(xs, action_0) /* forall<a,e> (xs : list<a>, action : (a) -> e ()) -> e () */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_0_10524 = action_0(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(wild___0 /* () */ ) {
        return _mlift_foreach_10428(action_0, xs.tail, wild___0);
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
 
 
// monadic lift
export function _mlift_trmc_map_while_10429(_acc, action, xx, _y_x10272) /* forall<a,b,e> (ctx<list<b>>, action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */  {
  if (_y_x10272 !== null) {
     
    var _trmc_x10109 = undefined;
     
    var _trmc_x10110 = $std_core_types.Cons(_y_x10272.value, _trmc_x10109);
    return _trmc_map_while(xx, action, $std_core_types._cctx_extend(_acc,_trmc_x10110,({obj: _trmc_x10110, field_name: "tail"})));
  }
  else {
    return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
  }
}
 
 
// monadic lift
export function _mlift_trmcm_map_while_10430(_accm, action_0, xx_0, _y_x10276) /* forall<a,b,e> ((list<b>) -> list<b>, action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */  {
  if (_y_x10276 !== null) {
    return _trmcm_map_while(xx_0, action_0, function(_trmc_x10112 /* list<2754> */ ) {
        return _accm($std_core_types.Cons(_y_x10276.value, _trmc_x10112));
      });
  }
  else {
    return _accm($std_core_types.Nil);
  }
}
 
 
// Invoke `action` on each element of a list while `action` returns `Just`
export function _trmc_map_while(xs, action_1, _acc_0) /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */  { tailcall: while(1)
{
  if (xs === null) {
    return $std_core_types._cctx_apply(_acc_0,($std_core_types.Nil));
  }
  else {
     
    var x_0_10527 = action_1(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10272_0 /* maybe<2754> */ ) {
        return _mlift_trmc_map_while_10429(_acc_0, action_1, xs.tail, _y_x10272_0);
      });
    }
    else {
      if (x_0_10527 !== null) {
         
        var _trmc_x10109_0 = undefined;
         
        var _trmc_x10110_0 = $std_core_types.Cons(x_0_10527.value, _trmc_x10109_0);
        {
          // tail call
          var _x63 = $std_core_types._cctx_extend(_acc_0,_trmc_x10110_0,({obj: _trmc_x10110_0, field_name: "tail"}));
          xs = xs.tail;
          _acc_0 = _x63;
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
export function _trmcm_map_while(xs_0, action_2, _accm_0) /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>, (list<b>) -> list<b>) -> e list<b> */  { tailcall: while(1)
{
  if (xs_0 === null) {
    return _accm_0($std_core_types.Nil);
  }
  else {
     
    var x_2_10530 = action_2(xs_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10276_0 /* maybe<2754> */ ) {
        return _mlift_trmcm_map_while_10430(_accm_0, action_2, xs_0.tail, _y_x10276_0);
      });
    }
    else {
      if (x_2_10530 !== null) {
        {
          // tail call
          var _x66 = function(__at_accm_064 /* (list<2754>) -> list<2754> */ , _y_265 /* 2754 */ ) {
            return function(_trmc_x10112_0 /* list<2754> */ ) {
              return __at_accm_064($std_core_types.Cons(_y_265, _trmc_x10112_0));
            };
          }(_accm_0, x_2_10530.value);
          xs_0 = xs_0.tail;
          _accm_0 = _x66;
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
export function map_while(xs_1, action_3) /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e list<b> */  {
  var _x67 = $std_core_hnd._evv_is_affine();
  if (_x67) {
    return _trmc_map_while(xs_1, action_3, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_map_while(xs_1, action_3, function(_trmc_x10111 /* list<2754> */ ) {
        return _trmc_x10111;
      });
  }
}
 
 
// monadic lift
export function _mlift_foreach_indexed_10431(i, _y_x10286) /* forall<h,e> (i : local-var<h,int>, int) -> <local<h>|e> () */  {
  return ((i).value = ($std_core_types._int_add(_y_x10286,1)));
}
 
 
// monadic lift
export function _mlift_foreach_indexed_10432(i, wild__) /* forall<h,e> (i : local-var<h,int>, wild_ : ()) -> <local<h>|e> () */  {
   
  var x_10533 = ((i).value);
   
  function next_10534(_y_x10286) /* (int) -> <local<2864>|2871> () */  {
    return ((i).value = ($std_core_types._int_add(_y_x10286,1)));
  }
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(next_10534);
  }
  else {
    return next_10534(x_10533);
  }
}
 
 
// monadic lift
export function _mlift_foreach_indexed_10433(action, i, x, j) /* forall<h,a,e> (action : (int, a) -> e (), i : local-var<h,int>, x : a, j : int) -> <local<h>|e> () */  {
   
  var x_0_10537 = action(j, x);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(wild__ /* () */ ) {
      return _mlift_foreach_indexed_10432(i, wild__);
    });
  }
  else {
    return _mlift_foreach_indexed_10432(i, x_0_10537);
  }
}
 
 
// Invoke `action` for each element of a list, passing also the position of the element.
export function foreach_indexed(xs, action) /* forall<a,e> (xs : list<a>, action : (int, a) -> e ()) -> e () */  {
  return function() {
     
    var loc = { value: 0 };
     
    var res = foreach(xs, function(x /* 2870 */ ) {
         
        var x_0_10542 = ((loc).value);
        if ($std_core_hnd._yielding()) {
          return $std_core_hnd.yield_extend(function(j /* int */ ) {
            return _mlift_foreach_indexed_10433(action, loc, x, j);
          });
        }
        else {
          return _mlift_foreach_indexed_10433(action, loc, x, x_0_10542);
        }
      });
    return $std_core_hnd.prompt_local_var(loc, res);
  }();
}
 
 
// lifted local: intersperse, before
export function _trmc_lift_intersperse_4952(sep, ys, _acc) /* forall<a> (sep : a, ys : list<a>, ctx<list<a>>) -> list<a> */  { tailcall: while(1)
{
  if (ys !== null) {
     
    var _trmc_x10113 = $std_core_types.Cons(ys.head, undefined);
    {
      // tail call
      var _x68 = $std_core_types._cctx_extend(_acc,($std_core_types.Cons(sep, _trmc_x10113)),({obj: _trmc_x10113, field_name: "tail"}));
      ys = ys.tail;
      _acc = _x68;
      continue tailcall;
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
  }
}}
 
 
// lifted local: intersperse, before
export function _lift_intersperse_4952(sep_0, ys_0) /* forall<a> (sep : a, ys : list<a>) -> list<a> */  {
  return _trmc_lift_intersperse_4952(sep_0, ys_0, $std_core_types._cctx_empty());
}
 
 
// Insert a separator `sep`  between all elements of a list `xs` .
export function intersperse(xs, sep) /* forall<a> (xs : list<a>, sep : a) -> list<a> */  {
  if (xs !== null) {
    return $std_core_types.Cons(xs.head, _lift_intersperse_4952(sep, xs.tail));
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
export function _mlift_show_10434(_y_x10291) /* forall<e> (list<string>) -> e string */  {
  match: {
    if (_y_x10291 === null) {
      var _x69 = "";
      break match;
    }
    if (_y_x10291 !== null && _y_x10291.tail === null) {
      var _x69 = _y_x10291.head;
      break match;
    }
    if (_y_x10291 !== null && _y_x10291.tail !== null && _y_x10291.tail.tail === null) {
      if (((",") === (""))){
        var _x69 = $std_core_types._lp__plus__plus__rp_(_y_x10291.head, _y_x10291.tail.head);
        break match;
      }
    }
    var _x69 = ((($std_core_vector.unvlist(_y_x10291))).join((",")));
  }
  return $std_core_types._lp__plus__plus__rp_("[", $std_core_types._lp__plus__plus__rp_(_x69, "]"));
}
 
 
// Show a list
export function show(xs, _implicit_fs_show) /* forall<a,e> (xs : list<a>, ?show : (a) -> e string) -> e string */  {
   
  var x_10544 = map(xs, _implicit_fs_show);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(_y_x10291 /* list<string> */ ) {
      return _mlift_show_10434(_y_x10291);
    });
  }
  else {
    match: {
      if (x_10544 === null) {
        var _x70 = "";
        break match;
      }
      if (x_10544 !== null && x_10544.tail === null) {
        var _x70 = x_10544.head;
        break match;
      }
      if (x_10544 !== null && x_10544.tail !== null && x_10544.tail.tail === null) {
        if (((",") === (""))){
          var _x70 = $std_core_types._lp__plus__plus__rp_(x_10544.head, x_10544.tail.head);
          break match;
        }
      }
      var _x70 = ((($std_core_vector.unvlist(x_10544))).join((",")));
    }
    return $std_core_types._lp__plus__plus__rp_("[", $std_core_types._lp__plus__plus__rp_(_x70, "]"));
  }
}
 
 
// _deprecated_, use `list/show` instead.
export function show_list(xs, show_elem) /* forall<a,e> (xs : list<a>, show-elem : (a) -> e string) -> e string */  {
  return show(xs, show_elem);
}
 
 
// Zip two lists together by pairing the corresponding elements.
// The returned list is only as long as the smallest input list.
export function _trmc_zip(xs, ys, _acc) /* forall<a,b> (xs : list<a>, ys : list<b>, ctx<list<(a, b)>>) -> list<(a, b)> */  { tailcall: while(1)
{
  if (xs !== null) {
    if (ys !== null) {
       
      var _trmc_x10115 = undefined;
       
      var _trmc_x10116 = $std_core_types.Cons($std_core_types.Tuple2(xs.head, ys.head), _trmc_x10115);
      {
        // tail call
        var _x71 = $std_core_types._cctx_extend(_acc,_trmc_x10116,({obj: _trmc_x10116, field_name: "tail"}));
        xs = xs.tail;
        ys = ys.tail;
        _acc = _x71;
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
export function zip(xs_0, ys_0) /* forall<a,b> (xs : list<a>, ys : list<b>) -> list<(a, b)> */  {
  return _trmc_zip(xs_0, ys_0, $std_core_types._cctx_empty());
}
 
 
// monadic lift
export function _mlift_trmc_zipwith_10435(_acc, f, xx, yy, _trmc_x10117) /* forall<a,b,c,e> (ctx<list<c>>, f : (a, b) -> e c, xx : list<a>, yy : list<b>, c) -> e list<c> */  {
   
  var _trmc_x10118 = undefined;
   
  var _trmc_x10119 = $std_core_types.Cons(_trmc_x10117, _trmc_x10118);
  return _trmc_zipwith(xx, yy, f, $std_core_types._cctx_extend(_acc,_trmc_x10119,({obj: _trmc_x10119, field_name: "tail"})));
}
 
 
// monadic lift
export function _mlift_trmcm_zipwith_10436(_accm, f_0, xx_0, yy_0, _trmc_x10122) /* forall<a,b,c,e> ((list<c>) -> list<c>, f : (a, b) -> e c, xx : list<a>, yy : list<b>, c) -> e list<c> */  {
  return _trmcm_zipwith(xx_0, yy_0, f_0, function(_trmc_x10121 /* list<3290> */ ) {
      return _accm($std_core_types.Cons(_trmc_x10122, _trmc_x10121));
    });
}
 
 
// Zip two lists together by apply a function `f` to all corresponding elements.
// The returned list is only as long as the smallest input list.
export function _trmc_zipwith(xs, ys, f_1, _acc_0) /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c, ctx<list<c>>) -> e list<c> */  { tailcall: while(1)
{
  if (xs !== null) {
    if (ys !== null) {
       
      var x_0_10547 = f_1(xs.head, ys.head);
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(_trmc_x10117_0 /* 3290 */ ) {
          return _mlift_trmc_zipwith_10435(_acc_0, f_1, xs.tail, ys.tail, _trmc_x10117_0);
        });
      }
      else {
         
        var _trmc_x10118_0 = undefined;
         
        var _trmc_x10119_0 = $std_core_types.Cons(x_0_10547, _trmc_x10118_0);
        {
          // tail call
          var _x72 = $std_core_types._cctx_extend(_acc_0,_trmc_x10119_0,({obj: _trmc_x10119_0, field_name: "tail"}));
          xs = xs.tail;
          ys = ys.tail;
          _acc_0 = _x72;
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
export function _trmcm_zipwith(xs_0, ys_0, f_2, _accm_0) /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c, (list<c>) -> list<c>) -> e list<c> */  { tailcall: while(1)
{
  if (xs_0 !== null) {
    if (ys_0 !== null) {
       
      var x_2_10550 = f_2(xs_0.head, ys_0.head);
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(_trmc_x10122_0 /* 3290 */ ) {
          return _mlift_trmcm_zipwith_10436(_accm_0, f_2, xs_0.tail, ys_0.tail, _trmc_x10122_0);
        });
      }
      else {
        {
          // tail call
          var _x75 = function(__at_accm_073 /* (list<3290>) -> list<3290> */ , _x_2_1055074 /* 3290 */ ) {
            return function(_trmc_x10121_0 /* list<3290> */ ) {
              return __at_accm_073($std_core_types.Cons(_x_2_1055074, _trmc_x10121_0));
            };
          }(_accm_0, x_2_10550);
          xs_0 = xs_0.tail;
          ys_0 = ys_0.tail;
          _accm_0 = _x75;
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
export function zipwith(xs_1, ys_1, f_3) /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c) -> e list<c> */  {
  var _x76 = $std_core_hnd._evv_is_affine();
  if (_x76) {
    return _trmc_zipwith(xs_1, ys_1, f_3, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_zipwith(xs_1, ys_1, f_3, function(_trmc_x10120 /* list<3290> */ ) {
        return _trmc_x10120;
      });
  }
}
 
 
// monadic lift
export function _mlift_trmc_lift_zipwith_indexed_4953_10437(_acc, f, i_0_10029, xx, yy, _trmc_x10123) /* forall<a,b,c,e> (ctx<list<c>>, f : (int, a, b) -> e c, i@0@10029 : int, xx : list<a>, yy : list<b>, c) -> e list<c> */  {
   
  var _trmc_x10124 = undefined;
   
  var _trmc_x10125 = $std_core_types.Cons(_trmc_x10123, _trmc_x10124);
  return _trmc_lift_zipwith_indexed_4953(f, i_0_10029, xx, yy, $std_core_types._cctx_extend(_acc,_trmc_x10125,({obj: _trmc_x10125, field_name: "tail"})));
}
 
 
// monadic lift
export function _mlift_trmcm_lift_zipwith_indexed_4953_10438(_accm, f_0, i_0_10029_0, xx_0, yy_0, _trmc_x10128) /* forall<a,b,c,e> ((list<c>) -> list<c>, f : (int, a, b) -> e c, i@0@10029 : int, xx : list<a>, yy : list<b>, c) -> e list<c> */  {
  return _trmcm_lift_zipwith_indexed_4953(f_0, i_0_10029_0, xx_0, yy_0, function(_trmc_x10127 /* list<3373> */ ) {
      return _accm($std_core_types.Cons(_trmc_x10128, _trmc_x10127));
    });
}
 
 
// lifted local: zipwith-indexed, zipwith-iter
export function _trmc_lift_zipwith_indexed_4953(f_1, i, xs, ys, _acc_0) /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xs : list<a>, ys : list<b>, ctx<list<c>>) -> e list<c> */  { tailcall: while(1)
{
  if (xs !== null) {
    if (ys !== null) {
       
      var i_0_10029_1 = $std_core_types._int_add(i,1);
       
      var x_0_10553 = f_1(i, xs.head, ys.head);
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(_trmc_x10123_0 /* 3373 */ ) {
          return _mlift_trmc_lift_zipwith_indexed_4953_10437(_acc_0, f_1, i_0_10029_1, xs.tail, ys.tail, _trmc_x10123_0);
        });
      }
      else {
         
        var _trmc_x10124_0 = undefined;
         
        var _trmc_x10125_0 = $std_core_types.Cons(x_0_10553, _trmc_x10124_0);
        {
          // tail call
          var _x77 = $std_core_types._cctx_extend(_acc_0,_trmc_x10125_0,({obj: _trmc_x10125_0, field_name: "tail"}));
          i = i_0_10029_1;
          xs = xs.tail;
          ys = ys.tail;
          _acc_0 = _x77;
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
export function _trmcm_lift_zipwith_indexed_4953(f_2, i_0, xs_0, ys_0, _accm_0) /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xs : list<a>, ys : list<b>, (list<c>) -> list<c>) -> e list<c> */  { tailcall: while(1)
{
  if (xs_0 !== null) {
    if (ys_0 !== null) {
       
      var i_0_10029_2 = $std_core_types._int_add(i_0,1);
       
      var x_2_10556 = f_2(i_0, xs_0.head, ys_0.head);
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(_trmc_x10128_0 /* 3373 */ ) {
          return _mlift_trmcm_lift_zipwith_indexed_4953_10438(_accm_0, f_2, i_0_10029_2, xs_0.tail, ys_0.tail, _trmc_x10128_0);
        });
      }
      else {
        {
          // tail call
          var _x80 = function(__at_accm_078 /* (list<3373>) -> list<3373> */ , _x_2_1055679 /* 3373 */ ) {
            return function(_trmc_x10127_0 /* list<3373> */ ) {
              return __at_accm_078($std_core_types.Cons(_x_2_1055679, _trmc_x10127_0));
            };
          }(_accm_0, x_2_10556);
          i_0 = i_0_10029_2;
          xs_0 = xs_0.tail;
          ys_0 = ys_0.tail;
          _accm_0 = _x80;
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
export function _lift_zipwith_indexed_4953(f_3, i_1, xs_1, ys_1) /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xs : list<a>, ys : list<b>) -> e list<c> */  {
  var _x81 = $std_core_hnd._evv_is_affine();
  if (_x81) {
    return _trmc_lift_zipwith_indexed_4953(f_3, i_1, xs_1, ys_1, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_lift_zipwith_indexed_4953(f_3, i_1, xs_1, ys_1, function(_trmc_x10126 /* list<3373> */ ) {
        return _trmc_x10126;
      });
  }
}
 
 
// Zip two lists together by apply a function `f` to all corresponding elements
// and their index in the list.
// The returned list is only as long as the smallest input list.
export function zipwith_indexed(xs0, ys0, f) /* forall<a,b,c,e> (xs0 : list<a>, ys0 : list<b>, f : (int, a, b) -> e c) -> e list<c> */  {
  return _lift_zipwith_indexed_4953(f, 0, xs0, ys0);
}
 
 
// lifted local: unzip, iter
// todo: implement TRMC for multiple results
export function _lift_unzip_4954(ys, acc1, acc2) /* forall<a,b,c,d> (ys : list<(a, b)>, acc1 : cctx<c,list<a>>, acc2 : cctx<d,list<b>>) -> (c, d) */  { tailcall: while(1)
{
  if (ys !== null) {
     
    var _cctx_x3433 = $std_core_types.Cons(ys.head.fst, undefined);
     
    var _cctx_x3434 = {obj: _cctx_x3433, field_name: "tail"};
     
    var _cctx_x3473 = $std_core_types.Cons(ys.head.snd, undefined);
     
    var _cctx_x3474 = {obj: _cctx_x3473, field_name: "tail"};
    {
      // tail call
      var _x82 = $std_core_types._cctx_compose(acc1,($std_core_types._cctx_create(_cctx_x3433,_cctx_x3434)));
      var _x83 = $std_core_types._cctx_compose(acc2,($std_core_types._cctx_create(_cctx_x3473,_cctx_x3474)));
      ys = ys.tail;
      acc1 = _x82;
      acc2 = _x83;
      continue tailcall;
    }
  }
  else {
    return $std_core_types.Tuple2($std_core_types._cctx_apply(acc1,($std_core_types.Nil)), $std_core_types._cctx_apply(acc2,($std_core_types.Nil)));
  }
}}
 
 
// Unzip a list of pairs into two lists
export function unzip(xs) /* forall<a,b> (xs : list<(a, b)>) -> (list<a>, list<b>) */  {
  return _lift_unzip_4954(xs, $std_core_types._cctx_empty(), $std_core_types._cctx_empty());
}
 
 
// lifted local: unzip3, iter
// todo: implement TRMC for multiple results
export function _lift_unzip3_4955(ys, acc1, acc2, acc3) /* forall<a,b,c,d,a1,b1> (ys : list<(a, b, c)>, acc1 : cctx<d,list<a>>, acc2 : cctx<a1,list<b>>, acc3 : cctx<b1,list<c>>) -> (d, a1, b1) */  { tailcall: while(1)
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
      var _x84 = $std_core_types._cctx_compose(acc1,($std_core_types._cctx_create(_cctx_x3624,_cctx_x3625)));
      var _x85 = $std_core_types._cctx_compose(acc2,($std_core_types._cctx_create(_cctx_x3664,_cctx_x3665)));
      var _x86 = $std_core_types._cctx_compose(acc3,($std_core_types._cctx_create(_cctx_x3704,_cctx_x3705)));
      ys = ys.tail;
      acc1 = _x84;
      acc2 = _x85;
      acc3 = _x86;
      continue tailcall;
    }
  }
  else {
    return $std_core_types.Tuple3($std_core_types._cctx_apply(acc1,($std_core_types.Nil)), $std_core_types._cctx_apply(acc2,($std_core_types.Nil)), $std_core_types._cctx_apply(acc3,($std_core_types.Nil)));
  }
}}
 
 
// Unzip a list of triples into three lists
export function unzip3(xs) /* forall<a,b,c> (xs : list<(a, b, c)>) -> (list<a>, list<b>, list<c>) */  {
  return _lift_unzip3_4955(xs, $std_core_types._cctx_empty(), $std_core_types._cctx_empty(), $std_core_types._cctx_empty());
}
 
 
// lifted local: unzip4, iter
// todo: implement TRMC for multiple results
export function _lift_unzip4_4956(ys, acc1, acc2, acc3, acc4) /* forall<a,b,c,d,a1,b1,c1,d1> (ys : list<(a, b, c, d)>, acc1 : cctx<a1,list<a>>, acc2 : cctx<b1,list<b>>, acc3 : cctx<c1,list<c>>, acc4 : cctx<d1,list<d>>) -> (a1, b1, c1, d1) */  { tailcall: while(1)
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
      var _x87 = $std_core_types._cctx_compose(acc1,($std_core_types._cctx_create(_cctx_x3895,_cctx_x3896)));
      var _x88 = $std_core_types._cctx_compose(acc2,($std_core_types._cctx_create(_cctx_x3935,_cctx_x3936)));
      var _x89 = $std_core_types._cctx_compose(acc3,($std_core_types._cctx_create(_cctx_x3975,_cctx_x3976)));
      var _x90 = $std_core_types._cctx_compose(acc4,($std_core_types._cctx_create(_cctx_x4015,_cctx_x4016)));
      ys = ys.tail;
      acc1 = _x87;
      acc2 = _x88;
      acc3 = _x89;
      acc4 = _x90;
      continue tailcall;
    }
  }
  else {
    return $std_core_types.Tuple4($std_core_types._cctx_apply(acc1,($std_core_types.Nil)), $std_core_types._cctx_apply(acc2,($std_core_types.Nil)), $std_core_types._cctx_apply(acc3,($std_core_types.Nil)), $std_core_types._cctx_apply(acc4,($std_core_types.Nil)));
  }
}}
 
 
// Unzip a list of quadruples into four lists
export function unzip4(xs) /* forall<a,b,c,d> (xs : list<(a, b, c, d)>) -> (list<a>, list<b>, list<c>, list<d>) */  {
  return _lift_unzip4_4956(xs, $std_core_types._cctx_empty(), $std_core_types._cctx_empty(), $std_core_types._cctx_empty(), $std_core_types._cctx_empty());
}
 
 
// monadic lift
export function _mlift_lift_span_4957_10439(acc, predicate, y, ys, yy, _y_x10316) /* forall<a,e> (acc : list<a>, predicate : (a) -> e bool, y : a, ys : list<a>, yy : list<a>, bool) -> e (list<a>, list<a>) */  {
  if (_y_x10316) {
    return _lift_span_4957(predicate, yy, $std_core_types.Cons(y, acc));
  }
  else {
    return $std_core_types.Tuple2(_lift_reverse_append_4948($std_core_types.Nil, acc), ys);
  }
}
 
 
// lifted local: span, span-acc
// todo: implement TRMC with multiple results to avoid the reverse
export function _lift_span_4957(predicate_0, ys_0, acc_0) /* forall<a,e> (predicate : (a) -> e bool, ys : list<a>, acc : list<a>) -> e (list<a>, list<a>) */  { tailcall: while(1)
{
  if (ys_0 !== null) {
     
    var x_10559 = predicate_0(ys_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10316_0 /* bool */ ) {
        return _mlift_lift_span_4957_10439(acc_0, predicate_0, ys_0.head, ys_0, ys_0.tail, _y_x10316_0);
      });
    }
    else {
      if (x_10559) {
        {
          // tail call
          var _x91 = $std_core_types.Cons(ys_0.head, acc_0);
          ys_0 = ys_0.tail;
          acc_0 = _x91;
          continue tailcall;
        }
      }
      else {
        return $std_core_types.Tuple2(_lift_reverse_append_4948($std_core_types.Nil, acc_0), ys_0);
      }
    }
  }
  else {
    return $std_core_types.Tuple2(_lift_reverse_append_4948($std_core_types.Nil, acc_0), ys_0);
  }
}}
 
export function span(xs, predicate) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e (list<a>, list<a>) */  {
  return _lift_span_4957(predicate, xs, $std_core_types.Nil);
}
 
 
// monadic lift
export function _mlift_trmc_take_while_10440(_acc, predicate, x, xx, _y_x10321) /* forall<a,e> (ctx<list<a>>, predicate : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */  {
  if (_y_x10321) {
     
    var _trmc_x10129 = undefined;
     
    var _trmc_x10130 = $std_core_types.Cons(x, _trmc_x10129);
    return _trmc_take_while(xx, predicate, $std_core_types._cctx_extend(_acc,_trmc_x10130,({obj: _trmc_x10130, field_name: "tail"})));
  }
  else {
    return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
  }
}
 
 
// monadic lift
export function _mlift_trmcm_take_while_10441(_accm, predicate_0, x_0, xx_0, _y_x10325) /* forall<a,e> ((list<a>) -> list<a>, predicate : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */  {
  if (_y_x10325) {
    return _trmcm_take_while(xx_0, predicate_0, function(_trmc_x10132 /* list<4313> */ ) {
        return _accm($std_core_types.Cons(x_0, _trmc_x10132));
      });
  }
  else {
    return _accm($std_core_types.Nil);
  }
}
 
 
// Keep only those initial elements that satisfy `predicate`
export function _trmc_take_while(xs, predicate_1, _acc_0) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool, ctx<list<a>>) -> e list<a> */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_2_10562 = predicate_1(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10321_0 /* bool */ ) {
        return _mlift_trmc_take_while_10440(_acc_0, predicate_1, xs.head, xs.tail, _y_x10321_0);
      });
    }
    else {
      if (x_2_10562) {
         
        var _trmc_x10129_0 = undefined;
         
        var _trmc_x10130_0 = $std_core_types.Cons(xs.head, _trmc_x10129_0);
        {
          // tail call
          var _x92 = $std_core_types._cctx_extend(_acc_0,_trmc_x10130_0,({obj: _trmc_x10130_0, field_name: "tail"}));
          xs = xs.tail;
          _acc_0 = _x92;
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
export function _trmcm_take_while(xs_0, predicate_2, _accm_0) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool, (list<a>) -> list<a>) -> e list<a> */  { tailcall: while(1)
{
  if (xs_0 !== null) {
     
    var x_4_10565 = predicate_2(xs_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10325_0 /* bool */ ) {
        return _mlift_trmcm_take_while_10441(_accm_0, predicate_2, xs_0.head, xs_0.tail, _y_x10325_0);
      });
    }
    else {
      if (x_4_10565) {
        {
          // tail call
          var _x95 = function(__at_accm_093 /* (list<4313>) -> list<4313> */ , _x_394 /* 4313 */ ) {
            return function(_trmc_x10132_0 /* list<4313> */ ) {
              return __at_accm_093($std_core_types.Cons(_x_394, _trmc_x10132_0));
            };
          }(_accm_0, xs_0.head);
          xs_0 = xs_0.tail;
          _accm_0 = _x95;
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
export function take_while(xs_1, predicate_3) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */  {
  var _x96 = $std_core_hnd._evv_is_affine();
  if (_x96) {
    return _trmc_take_while(xs_1, predicate_3, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_take_while(xs_1, predicate_3, function(_trmc_x10131 /* list<4313> */ ) {
        return _trmc_x10131;
      });
  }
}
 
 
// Concatenate all strings in a list in reverse order
export function reverse_join(xs) /* (xs : list<string>) -> string */  {
   
  var xs_0_10038 = _lift_reverse_append_4948($std_core_types.Nil, xs);
  if (xs_0_10038 === null) {
    return "";
  }
  else if (xs_0_10038 !== null && xs_0_10038.tail === null) {
    return xs_0_10038.head;
  }
  else if (xs_0_10038 !== null && xs_0_10038.tail !== null && xs_0_10038.tail.tail === null) {
    return $std_core_types._lp__plus__plus__rp_(xs_0_10038.head, xs_0_10038.tail.head);
  }
  else {
    return ((($std_core_vector.unvlist(xs_0_10038))).join(''));
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
     
    var _trmc_x10133 = undefined;
     
    var _trmc_x10134 = $std_core_types.Cons(ys.head, _trmc_x10133);
    {
      // tail call
      var _x97 = $std_core_types._cctx_extend(_acc,_trmc_x10134,({obj: _trmc_x10134, field_name: "tail"}));
      ys = ys.tail;
      _acc = _x97;
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
export function _mlift_trmc_lift_flatmap_4959_10442(_acc, f, zz, ys_1_10045) /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e list<b>, zz : list<a>, ys@1@10045 : list<b>) -> e list<b> */  {
  return _trmc_lift_flatmap_4959(f, ys_1_10045, zz, _acc);
}
 
 
// monadic lift
export function _mlift_trmcm_lift_flatmap_4959_10443(_accm, f_0, zz_0, ys_1_10045_0) /* forall<a,b,e> ((list<b>) -> list<b>, f : (a) -> e list<b>, zz : list<a>, ys@1@10045 : list<b>) -> e list<b> */  {
  return _trmcm_lift_flatmap_4959(f_0, ys_1_10045_0, zz_0, _accm);
}
 
 
// lifted local: flatmap, flatmap-pre
export function _trmc_lift_flatmap_4959(f_1, ys, zs, _acc_0) /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>, ctx<list<b>>) -> e list<b> */  { tailcall: while(1)
{
  if (ys !== null) {
     
    var _trmc_x10135 = undefined;
     
    var _trmc_x10136 = $std_core_types.Cons(ys.head, _trmc_x10135);
    {
      // tail call
      var _x98 = $std_core_types._cctx_extend(_acc_0,_trmc_x10136,({obj: _trmc_x10136, field_name: "tail"}));
      ys = ys.tail;
      _acc_0 = _x98;
      continue tailcall;
    }
  }
  else {
    if (zs !== null) {
       
      var x_10568 = f_1(zs.head);
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(ys_1_10045_1 /* list<4487> */ ) {
          return _mlift_trmc_lift_flatmap_4959_10442(_acc_0, f_1, zs.tail, ys_1_10045_1);
        });
      }
      else {
        {
          // tail call
          ys = x_10568;
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
      var _x101 = function(__at_accm_099 /* (list<4487>) -> list<4487> */ , _y_0100 /* 4487 */ ) {
        return function(_trmc_x10138 /* list<4487> */ ) {
          return __at_accm_099($std_core_types.Cons(_y_0100, _trmc_x10138));
        };
      }(_accm_0, ys_0.head);
      ys_0 = ys_0.tail;
      _accm_0 = _x101;
      continue tailcall;
    }
  }
  else {
    if (zs_0 !== null) {
       
      var x_0_10571 = f_2(zs_0.head);
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(ys_1_10045_3 /* list<4487> */ ) {
          return _mlift_trmcm_lift_flatmap_4959_10443(_accm_0, f_2, zs_0.tail, ys_1_10045_3);
        });
      }
      else {
        {
          // tail call
          ys_0 = x_0_10571;
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
  var _x102 = $std_core_hnd._evv_is_affine();
  if (_x102) {
    return _trmc_lift_flatmap_4959(f_3, ys_1, zs_1, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_lift_flatmap_4959(f_3, ys_1, zs_1, function(_trmc_x10137 /* list<4487> */ ) {
        return _trmc_x10137;
      });
  }
}
 
 
// Concatenate the result lists from applying a function to all elements.
export function flatmap(xs, f) /* forall<a,b,e> (xs : list<a>, f : (a) -> e list<b>) -> e list<b> */  {
  return _lift_flatmap_4959(f, $std_core_types.Nil, xs);
}
 
 
// monadic lift
export function _mlift_trmc_flatmap_maybe_10444(_acc, f, xx, _y_x10346) /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */  {
  if (_y_x10346 !== null) {
     
    var _trmc_x10139 = undefined;
     
    var _trmc_x10140 = $std_core_types.Cons(_y_x10346.value, _trmc_x10139);
    return _trmc_flatmap_maybe(xx, f, $std_core_types._cctx_extend(_acc,_trmc_x10140,({obj: _trmc_x10140, field_name: "tail"})));
  }
  else {
    return _trmc_flatmap_maybe(xx, f, _acc);
  }
}
 
 
// monadic lift
export function _mlift_trmcm_flatmap_maybe_10445(_accm, f_0, xx_0, _y_x10351) /* forall<a,b,e> ((list<b>) -> list<b>, f : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */  {
  if (_y_x10351 !== null) {
    return _trmcm_flatmap_maybe(xx_0, f_0, function(_trmc_x10142 /* list<4558> */ ) {
        return _accm($std_core_types.Cons(_y_x10351.value, _trmc_x10142));
      });
  }
  else {
    return _trmcm_flatmap_maybe(xx_0, f_0, _accm);
  }
}
 
 
// Concatenate the `Just` result elements from applying a function to all elements.
export function _trmc_flatmap_maybe(xs, f_1, _acc_0) /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_0_10574 = f_1(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10346_0 /* maybe<4558> */ ) {
        return _mlift_trmc_flatmap_maybe_10444(_acc_0, f_1, xs.tail, _y_x10346_0);
      });
    }
    else {
      if (x_0_10574 !== null) {
         
        var _trmc_x10139_0 = undefined;
         
        var _trmc_x10140_0 = $std_core_types.Cons(x_0_10574.value, _trmc_x10139_0);
        {
          // tail call
          var _x103 = $std_core_types._cctx_extend(_acc_0,_trmc_x10140_0,({obj: _trmc_x10140_0, field_name: "tail"}));
          xs = xs.tail;
          _acc_0 = _x103;
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
export function _trmcm_flatmap_maybe(xs_0, f_2, _accm_0) /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>, (list<b>) -> list<b>) -> e list<b> */  { tailcall: while(1)
{
  if (xs_0 !== null) {
     
    var x_2_10577 = f_2(xs_0.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10351_0 /* maybe<4558> */ ) {
        return _mlift_trmcm_flatmap_maybe_10445(_accm_0, f_2, xs_0.tail, _y_x10351_0);
      });
    }
    else {
      if (x_2_10577 !== null) {
        {
          // tail call
          var _x106 = function(__at_accm_0104 /* (list<4558>) -> list<4558> */ , _y_2105 /* 4558 */ ) {
            return function(_trmc_x10142_0 /* list<4558> */ ) {
              return __at_accm_0104($std_core_types.Cons(_y_2105, _trmc_x10142_0));
            };
          }(_accm_0, x_2_10577.value);
          xs_0 = xs_0.tail;
          _accm_0 = _x106;
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
export function flatmap_maybe(xs_1, f_3) /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>) -> e list<b> */  {
  var _x107 = $std_core_hnd._evv_is_affine();
  if (_x107) {
    return _trmc_flatmap_maybe(xs_1, f_3, $std_core_types._cctx_empty());
  }
  else {
    return _trmcm_flatmap_maybe(xs_1, f_3, function(_trmc_x10141 /* list<4558> */ ) {
        return _trmc_x10141;
      });
  }
}
 
 
// Concatenate a list of `:maybe` values
export function _trmc_concat_maybe(xs, _acc) /* forall<a> (xs : list<maybe<a>>, ctx<list<a>>) -> list<a> */  { tailcall: while(1)
{
  if (xs !== null) {
    if (xs.head !== null) {
       
      var _trmc_x10143 = undefined;
       
      var _trmc_x10144 = $std_core_types.Cons(xs.head.value, _trmc_x10143);
      {
        // tail call
        var _x108 = $std_core_types._cctx_extend(_acc,_trmc_x10144,({obj: _trmc_x10144, field_name: "tail"}));
        xs = xs.tail;
        _acc = _x108;
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
export function concat_maybe(xs_0) /* forall<a> (xs : list<maybe<a>>) -> list<a> */  {
  return _trmc_concat_maybe(xs_0, $std_core_types._cctx_empty());
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
     
    var _trmc_x10145 = undefined;
     
    var _trmc_x10146 = $std_core_types.Cons(xs.head, _trmc_x10145);
    {
      // tail call
      var _x109 = $std_core_types._cctx_extend(_acc,_trmc_x10146,({obj: _trmc_x10146, field_name: "tail"}));
      xs = xs.tail;
      _acc = _x109;
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
export function _index(xs, n) /* forall<a> (xs : list<a>, n : int) -> maybe<a> */  { tailcall: while(1)
{
  if (xs !== null) {
    if ($std_core_types._int_gt(n,0)) {
      {
        // tail call
        var _x110 = $std_core_types._int_sub(n,1);
        xs = xs.tail;
        n = _x110;
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
 
 
// monadic lift
export function _mlift_all_10446(predicate, xx, _y_x10359) /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */  {
  if (_y_x10359) {
    return all(xx, predicate);
  }
  else {
    return false;
  }
}
 
 
// Do all elements satisfy a predicate ?
export function all(xs, predicate_0) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_0_10580 = predicate_0(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10359_0 /* bool */ ) {
        return _mlift_all_10446(predicate_0, xs.tail, _y_x10359_0);
      });
    }
    else {
      if (x_0_10580) {
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
 
 
// monadic lift
export function _mlift_any_10447(predicate, xx, _y_x10363) /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */  {
  if (_y_x10363) {
    return true;
  }
  else {
    return any(xx, predicate);
  }
}
 
 
// Are there any elements in a list that satisfy a predicate ?
export function any(xs, predicate_0) /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */  { tailcall: while(1)
{
  if (xs !== null) {
     
    var x_0_10583 = predicate_0(xs.head);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10363_0 /* bool */ ) {
        return _mlift_any_10447(predicate_0, xs.tail, _y_x10363_0);
      });
    }
    else {
      if (x_0_10583) {
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
 
 
// Return the sum of a list of integers
export function sum(xs) /* (xs : list<int>) -> int */  {
  return foldl(xs, 0, $std_core_int._lp__plus__rp_);
}
 
 
// Returns the smallest element of a list of integers (or `default` (=`0`) for the empty list)
export function minimum(xs, $default) /* (xs : list<int>, default : ? int) -> int */  {
  if (xs === null) {
    return ($default !== undefined) ? $default : 0;
  }
  else {
    return foldl(xs.tail, xs.head, $std_core_int.min);
  }
}
 
 
// Returns the largest element of a list of integers (or `default` (=`0`) for the empty list)
export function maximum(xs, $default) /* (xs : list<int>, default : ? int) -> int */  {
  if (xs === null) {
    return ($default !== undefined) ? $default : 0;
  }
  else {
    return foldl(xs.tail, xs.head, $std_core_int.max);
  }
}
 
 
// Split a string into a list of lines
export function lines(s) /* (s : string) -> list<string> */  {
   
  var v_10013 = ((s).split(("\n")));
  return $std_core_vector.vlist(v_10013);
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