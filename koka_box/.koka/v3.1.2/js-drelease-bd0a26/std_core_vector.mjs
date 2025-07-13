// Koka generated module: std/core/vector, koka version: 3.1.2
"use strict";
 
// imports
import * as $std_core_types from './std_core_types.mjs';
import * as $std_core_undiv from './std_core_undiv.mjs';
import * as $std_core_hnd from './std_core_hnd.mjs';
import * as $std_core_exn from './std_core_exn.mjs';
import * as $std_core_int from './std_core_int.mjs';
 
// externals
/*---------------------------------------------------------------------------
  Copyright 2012-2023, Microsoft Research, Daan Leijen.
  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/
// Create a list with from a vector in constant stack space
export function _vlist(elems,tail) {
  var xs = tail || $std_core_types.Nil;
  if (elems!=null && elems.length>0) {
    for(var i = elems.length - 1; i >= 0; i--) {
      var elem = elems[i];
      if (elem !== undefined) xs = $std_core_types.Cons(elem,xs);
    }
  }
  return xs;
}
// Create an array from a list with constant stack space
export function _unvlist(list) {
  var elems = [];
  while(list) {
    elems.push(list.head);
    list = list.tail;
  }
  return elems;
}
// Create a vector with a default value
export function _vector_initz(n, x) {
  if (n<=0) return [];
  var a = new Array(n);
  for(var i = 0; i < n; i++) {
    a[i] = x;
  }
  return a;
}
// Create a vector with a function initializer
export function _vector_initf(n, f) {
  if (n<=0) return [];
  var a = new Array(n);
  for(var i = 0; i < n; i++) {
    a[i] = f(i);
  }
  return a;
}
// Index a vector
export function _vector_at( v, i ) {
  var j = _int_to_number(i);
  var x = v[j];
  if (x === undefined) { $std_core_exn.exn_error_range(); }
  return x;
}
 
// type declarations
 
// declarations
 
 
// Create a new vector of length `n`  with initial elements `init`` .
export function vector_alloc(n, init) /* forall<a,e> (n : ssize_t, init : a) -> e vector<a> */  {
  return _vector_initz(n,init);
}
 
 
// Create a new vector of length `n`  with initial elements given by a total function `f` .
export function vector_alloc_total(n, f) /* forall<a> (n : ssize_t, f : (ssize_t) -> a) -> vector<a> */  {
  return _vector_initf(n,f);
}
 
 
// Return the element at position `index`  in vector `v`.
// Raise an out of bounds exception if `index < 0`  or `index >= v.length`.
export function _index(v, index) /* forall<a> (v : vector<a>, index : int) -> exn a */  {
   
  var idx = $std_core_int.ssize__t(index);
  var _x0 = (idx < (((v).length)));
  if (_x0) {
    return (v)[idx];
  }
  else {
    return $std_core_exn.$throw("index out of bounds", $std_core_exn.ExnRange);
  }
}
 
 
// Return the element at position `index` in vector `v`, or `Nothing` if out of bounds
export function at(v, index) /* forall<a> (v : vector<a>, index : int) -> maybe<a> */  {
   
  var idx = $std_core_int.ssize__t(index);
  var _x1 = (idx < (((v).length)));
  if (_x1) {
    return $std_core_types.Just((v)[idx]);
  }
  else {
    return $std_core_types.Nothing;
  }
}
 
 
// Return the length of a vector.
export function length(v) /* forall<a> (v : vector<a>) -> int */  {
  return $std_core_types._int_from_int32((((v).length)));
}
 
 
// Create a new vector of length `n`  with initial elements `default` .
export function vector(n, $default) /* forall<a> (n : int, default : a) -> vector<a> */  {
  return vector_alloc($std_core_int.ssize__t(n), $default);
}
 
 
// Create a new vector of length `n`  with initial elements given by _total_ function `f`.
// (can be more efficient than `vector-init`)
export function vector_init_total(n, f) /* forall<a,e> (n : int, f : (int) -> a) -> e vector<a> */  {
  return vector_alloc_total($std_core_int.ssize__t(n), function(i /* ssize_t */ ) {
      return f($std_core_types._int_from_int32(i));
    });
}
 
export function ssize__t_fs_incr(i) /* (i : ssize_t) -> ssize_t */  {
  return (i + 1);
}
 
 
// monadic lift
export function _mlift_lift_forz_868_10244(action, i, n, wild__) /* forall<e> (action : (ssize_t) -> e (), i : ssize_t, n : ssize_t, wild_ : ()) -> e () */  {
   
  var i_0_10000 = ssize__t_fs_incr(i);
  return _lift_forz_868(action, n, i_0_10000);
}
 
 
// lifted local: forz, rep
export function _lift_forz_868(action_0, n_0, i_0) /* forall<e> (action : (ssize_t) -> e (), n : ssize_t, i : ssize_t) -> e () */  { tailcall: while(1)
{
  if ((i_0 < n_0)) {
     
    var x_10254 = action_0(i_0);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(wild___0 /* () */ ) {
        return _mlift_lift_forz_868_10244(action_0, i_0, n_0, wild___0);
      });
    }
    else {
       
      var i_0_10000_0 = ssize__t_fs_incr(i_0);
      {
        // tail call
        i_0 = i_0_10000_0;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types.Unit;
  }
}}
 
 
// Executes `action` `n` times for each integer between [`0`,`n`)  (excluding `n` ).
// If `n <= 0`  the function returns without any call to `action` .
export function forz(n, action) /* forall<e> (n : ssize_t, action : (ssize_t) -> e ()) -> e () */  {
   
  var i = 0;
  return _lift_forz_868(action, n, i);
}
 
 
// monadic lift
export function _mlift_lift_vector_init_10176_10245(_uniq_i_10122, _uniq_n_10121, f, v, _y_x10213) /* forall<a,e> (ssize_t, ssize_t, f : (int) -> e a, v : vector<a>, a) -> e () */  {
   
  var _uniq_x___10124 = (v)[_uniq_i_10122] = _y_x10213;
   
  var _uniq_i_0_10000_10125 = ssize__t_fs_incr(_uniq_i_10122);
  return _lift_vector_init_10176(f, v, _uniq_n_10121, _uniq_i_0_10000_10125);
}
 
 
// lifted local: vector-init, @spec-x10127
// specialized: std/core/vector/@lift-forz@868, on parameters @uniq-action@10120, using:
// @uniq-action@10120 = fn<(e :: E)>(i@0: ssize_t){
//   std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, i : ssize_t, x : a) -> (),(v : (vector :: V -> V)<a>, i : ssize_t, x : a) -> (e :: E) ()>((std/core/vector/unsafe-assign<a>))(v, i@0, (f((std/core/types/@open<(total :: E),(e :: E),(i : ssize_t) -> int,(i : ssize_t) -> (e :: E) int>(std/core/int/ssize_t/int)(i@0)))));
// }
export function _lift_vector_init_10176(f_0, v_0, _uniq_n_10121_0, _uniq_i_10122_0) /* forall<a,e> (f : (int) -> e a, v : vector<a>, ssize_t, ssize_t) -> e () */  { tailcall: while(1)
{
  if ((_uniq_i_10122_0 < _uniq_n_10121_0)) {
     
    var x_10257 = f_0($std_core_types._int_from_int32(_uniq_i_10122_0));
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10213_0 /* 512 */ ) {
        return _mlift_lift_vector_init_10176_10245(_uniq_i_10122_0, _uniq_n_10121_0, f_0, v_0, _y_x10213_0);
      });
    }
    else {
       
      var _uniq_x___10124_0 = (v_0)[_uniq_i_10122_0] = x_10257;
       
      var _uniq_i_0_10000_10125_0 = ssize__t_fs_incr(_uniq_i_10122_0);
      {
        // tail call
        _uniq_i_10122_0 = _uniq_i_0_10000_10125_0;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types.Unit;
  }
}}
 
 
// monadic lift
export function _mlift_vector_init_10246(v, wild__) /* forall<a,e> (v : vector<a>, wild_ : ()) -> e vector<a> */  {
  return v;
}
 
 
// Create a new vector of length `n`  with initial elements given by function `f` which can have a control effect.
export function vector_init(n, f) /* forall<a,e> (n : int, f : (int) -> e a) -> e vector<a> */  {
   
  var len = $std_core_int.ssize__t(n);
   
  var v = Array(len);
   
  var i = 0;
   
  var x_10260 = _lift_vector_init_10176(f, v, len, i);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(wild__ /* () */ ) {
      return v;
    });
  }
  else {
    return v;
  }
}
 
 
// monadic lift
export function _mlift_lift_foreach_indexedz_10177_10247(_uniq_i_10131, _uniq_n_10130, f, v, _uniq_x___10133) /* forall<a,e> (ssize_t, ssize_t, f : (ssize_t, a) -> e (), v : vector<a>, ()) -> e () */  {
   
  var _uniq_i_0_10000_10134 = ssize__t_fs_incr(_uniq_i_10131);
  return _lift_foreach_indexedz_10177(f, v, _uniq_n_10130, _uniq_i_0_10000_10134);
}
 
 
// lifted local: foreach-indexedz, @spec-x10136
// specialized: std/core/vector/@lift-forz@868, on parameters @uniq-action@10129, using:
// @uniq-action@10129 = fn<(e :: E)>(i@0: ssize_t){
//   f(i@0, (std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, index : ssize_t) -> a,(v : (vector :: V -> V)<a>, index : ssize_t) -> (e :: E) a>((std/core/vector/unsafe-idx<a>))(v, i@0)));
// }
export function _lift_foreach_indexedz_10177(f_0, v_0, _uniq_n_10130_0, _uniq_i_10131_0) /* forall<a,e> (f : (ssize_t, a) -> e (), v : vector<a>, ssize_t, ssize_t) -> e () */  { tailcall: while(1)
{
  if ((_uniq_i_10131_0 < _uniq_n_10130_0)) {
     
    var x_10265 = f_0(_uniq_i_10131_0, (v_0)[_uniq_i_10131_0]);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_uniq_x___10133_0 /* () */ ) {
        return _mlift_lift_foreach_indexedz_10177_10247(_uniq_i_10131_0, _uniq_n_10130_0, f_0, v_0, _uniq_x___10133_0);
      });
    }
    else {
       
      var _uniq_i_0_10000_10134_0 = ssize__t_fs_incr(_uniq_i_10131_0);
      {
        // tail call
        _uniq_i_10131_0 = _uniq_i_0_10000_10134_0;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types.Unit;
  }
}}
 
export function foreach_indexedz(v, f) /* forall<a,e> (v : vector<a>, f : (ssize_t, a) -> e ()) -> e () */  {
   
  var n_10003 = ((v).length);
   
  var i = 0;
  return _lift_foreach_indexedz_10177(f, v, n_10003, i);
}
 
 
// monadic lift
export function _mlift_lift_foreach_10178_10248(_uniq_i_10140, _uniq_n_10139, f, v, _uniq_x___10142) /* forall<a,e> (ssize_t, ssize_t, f : (a) -> e (), v : vector<a>, ()) -> e () */  {
   
  var _uniq_i_0_10000_10143 = ssize__t_fs_incr(_uniq_i_10140);
  return _lift_foreach_10178(f, v, _uniq_n_10139, _uniq_i_0_10000_10143);
}
 
 
// lifted local: foreach, @spec-x10145
// specialized: std/core/vector/@lift-forz@868, on parameters @uniq-action@10138, using:
// @uniq-action@10138 = fn<(e :: E)>(i@0: ssize_t){
//   val x@10015 : a
//         = std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, index : ssize_t) -> a,(v : (vector :: V -> V)<a>, index : ssize_t) -> (e :: E) a>((std/core/vector/unsafe-idx<a>))(v, i@0);
//   f(x@10015);
// }
export function _lift_foreach_10178(f_0, v_0, _uniq_n_10139_0, _uniq_i_10140_0) /* forall<a,e> (f : (a) -> e (), v : vector<a>, ssize_t, ssize_t) -> e () */  { tailcall: while(1)
{
  if ((_uniq_i_10140_0 < _uniq_n_10139_0)) {
     
    var x_10015 = (v_0)[_uniq_i_10140_0];
     
    var x_10268 = f_0(x_10015);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_uniq_x___10142_0 /* () */ ) {
        return _mlift_lift_foreach_10178_10248(_uniq_i_10140_0, _uniq_n_10139_0, f_0, v_0, _uniq_x___10142_0);
      });
    }
    else {
       
      var _uniq_i_0_10000_10143_0 = ssize__t_fs_incr(_uniq_i_10140_0);
      {
        // tail call
        _uniq_i_10140_0 = _uniq_i_0_10000_10143_0;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types.Unit;
  }
}}
 
 
// Invoke a function `f` for each element in a vector `v`
export function foreach(v, f) /* forall<a,e> (v : vector<a>, f : (a) -> e ()) -> e () */  {
   
  var n_10003 = ((v).length);
   
  var i = 0;
  return _lift_foreach_10178(f, v, n_10003, i);
}
 
 
// monadic lift
export function _mlift_lift_foreach_indexed_10179_10249(_uniq_i_10149, _uniq_n_10148, f, v, _uniq_x___10151) /* forall<a,e> (ssize_t, ssize_t, f : (int, a) -> e (), v : vector<a>, ()) -> e () */  {
   
  var _uniq_i_0_10000_10152 = ssize__t_fs_incr(_uniq_i_10149);
  return _lift_foreach_indexed_10179(f, v, _uniq_n_10148, _uniq_i_0_10000_10152);
}
 
 
// lifted local: foreach-indexed, @spec-x10154
// specialized: std/core/vector/@lift-forz@868, on parameters @uniq-action@10147, using:
// @uniq-action@10147 = fn<(e :: E)>(i@0: ssize_t){
//   val x@10017 : a
//         = std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, index : ssize_t) -> a,(v : (vector :: V -> V)<a>, index : ssize_t) -> (e :: E) a>((std/core/vector/unsafe-idx<a>))(v, i@0);
//   f((std/core/types/@open<(total :: E),(e :: E),(i : ssize_t) -> int,(i : ssize_t) -> (e :: E) int>(std/core/int/ssize_t/int)(i@0)), x@10017);
// }
export function _lift_foreach_indexed_10179(f_0, v_0, _uniq_n_10148_0, _uniq_i_10149_0) /* forall<a,e> (f : (int, a) -> e (), v : vector<a>, ssize_t, ssize_t) -> e () */  { tailcall: while(1)
{
  if ((_uniq_i_10149_0 < _uniq_n_10148_0)) {
     
    var x_10017 = (v_0)[_uniq_i_10149_0];
     
    var x_10271 = f_0($std_core_types._int_from_int32(_uniq_i_10149_0), x_10017);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_uniq_x___10151_0 /* () */ ) {
        return _mlift_lift_foreach_indexed_10179_10249(_uniq_i_10149_0, _uniq_n_10148_0, f_0, v_0, _uniq_x___10151_0);
      });
    }
    else {
       
      var _uniq_i_0_10000_10152_0 = ssize__t_fs_incr(_uniq_i_10149_0);
      {
        // tail call
        _uniq_i_10149_0 = _uniq_i_0_10000_10152_0;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types.Unit;
  }
}}
 
 
// Invoke a function `f` for each element in a vector `v`
export function foreach_indexed(v, f) /* forall<a,e> (v : vector<a>, f : (int, a) -> e ()) -> e () */  {
   
  var n_10003 = ((v).length);
   
  var i = 0;
  return _lift_foreach_indexed_10179(f, v, n_10003, i);
}
 
 
// monadic lift
export function _mlift_lift_for_whilez_869_10250(action, i, n, _y_x10229) /* forall<a,e> (action : (ssize_t) -> e maybe<a>, i : ssize_t, n : ssize_t, maybe<a>) -> e maybe<a> */  {
  if (_y_x10229 === null) {
     
    var i_0_10005 = ssize__t_fs_incr(i);
    return _lift_for_whilez_869(action, n, i_0_10005);
  }
  else {
    return $std_core_types.Just(_y_x10229.value);
  }
}
 
 
// lifted local: for-whilez, rep
export function _lift_for_whilez_869(action_0, n_0, i_0) /* forall<a,e> (action : (ssize_t) -> e maybe<a>, n : ssize_t, i : ssize_t) -> e maybe<a> */  { tailcall: while(1)
{
  if ((i_0 < n_0)) {
     
    var x_0_10274 = action_0(i_0);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10229_0 /* maybe<664> */ ) {
        return _mlift_lift_for_whilez_869_10250(action_0, i_0, n_0, _y_x10229_0);
      });
    }
    else {
      if (x_0_10274 === null) {
         
        var i_0_10005_0 = ssize__t_fs_incr(i_0);
        {
          // tail call
          i_0 = i_0_10005_0;
          continue tailcall;
        }
      }
      else {
        return $std_core_types.Just(x_0_10274.value);
      }
    }
  }
  else {
    return $std_core_types.Nothing;
  }
}}
 
 
// Executes `action` at most `n` times for each integer between `0`  upto `n`  (excluding `n` ).
// If `n <= 0`  the function returns without any call to `action` .
// If `action` returns `Just`, the iteration is stopped and the result returned
export function for_whilez(n, action) /* forall<a,e> (n : ssize_t, action : (ssize_t) -> e maybe<a>) -> e maybe<a> */  {
   
  var i = 0;
  return _lift_for_whilez_869(action, n, i);
}
 
 
// monadic lift
export function _mlift_lift_foreach_while_10180_10251(_uniq_i_10158, _uniq_n_10157, f, v, _y_x10234) /* forall<a,b,e> (ssize_t, ssize_t, f : (a) -> e maybe<b>, v : vector<a>, maybe<b>) -> e maybe<b> */  {
  if (_y_x10234 === null) {
     
    var _uniq_i_0_10005_10161 = ssize__t_fs_incr(_uniq_i_10158);
    return _lift_foreach_while_10180(f, v, _uniq_n_10157, _uniq_i_0_10005_10161);
  }
  else {
    return $std_core_types.Just(_y_x10234.value);
  }
}
 
 
// lifted local: foreach-while, @spec-x10165
// specialized: std/core/vector/@lift-for-whilez@869, on parameters @uniq-action@10156, using:
// @uniq-action@10156 = fn<(e :: E)>(i@0: ssize_t){
//   f((std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, index : ssize_t) -> a,(v : (vector :: V -> V)<a>, index : ssize_t) -> (e :: E) a>((std/core/vector/unsafe-idx<a>))(v, i@0)));
// }
export function _lift_foreach_while_10180(f_0, v_0, _uniq_n_10157_0, _uniq_i_10158_0) /* forall<a,b,e> (f : (a) -> e maybe<b>, v : vector<a>, ssize_t, ssize_t) -> e maybe<b> */  { tailcall: while(1)
{
  if ((_uniq_i_10158_0 < _uniq_n_10157_0)) {
     
    var x_10277 = f_0((v_0)[_uniq_i_10158_0]);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10234_0 /* maybe<707> */ ) {
        return _mlift_lift_foreach_while_10180_10251(_uniq_i_10158_0, _uniq_n_10157_0, f_0, v_0, _y_x10234_0);
      });
    }
    else {
      if (x_10277 === null) {
         
        var _uniq_i_0_10005_10161_0 = ssize__t_fs_incr(_uniq_i_10158_0);
        {
          // tail call
          _uniq_i_10158_0 = _uniq_i_0_10005_10161_0;
          continue tailcall;
        }
      }
      else {
        return $std_core_types.Just(x_10277.value);
      }
    }
  }
  else {
    return $std_core_types.Nothing;
  }
}}
 
 
// Invoke a function `f` for each element in a vector `v`.
// If `f` returns `Just`, the iteration is stopped early and the result is returned.
export function foreach_while(v, f) /* forall<a,b,e> (v : vector<a>, f : (a) -> e maybe<b>) -> e maybe<b> */  {
   
  var n_10006 = ((v).length);
   
  var i = 0;
  return _lift_foreach_while_10180(f, v, n_10006, i);
}
 
 
// monadic lift
export function _mlift_lift_map_10181_10252(_uniq_i_10169, _uniq_n_10168, f, v, w, _y_x10239) /* forall<a,b,e> (ssize_t, ssize_t, f : (a) -> e b, v : vector<a>, w : vector<b>, b) -> e () */  {
   
  var _uniq_x___10171 = (w)[_uniq_i_10169] = _y_x10239;
   
  var _uniq_i_0_10000_10172 = ssize__t_fs_incr(_uniq_i_10169);
  return _lift_map_10181(f, v, w, _uniq_n_10168, _uniq_i_0_10000_10172);
}
 
 
// lifted local: map, @spec-x10174
// specialized: std/core/vector/@lift-forz@868, on parameters @uniq-action@10167, using:
// @uniq-action@10167 = fn<(e :: E)>(i@0: ssize_t){
//   val x@10019 : a
//         = std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, index : ssize_t) -> a,(v : (vector :: V -> V)<a>, index : ssize_t) -> (e :: E) a>((std/core/vector/unsafe-idx<a>))(v, i@0);
//   std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, i : ssize_t, x : a) -> (),(v : (vector :: V -> V)<a>, i : ssize_t, x : a) -> (e :: E) ()>((std/core/vector/unsafe-assign<a>))(w, i@0, (f(x@10019)));
// }
export function _lift_map_10181(f_0, v_0, w_0, _uniq_n_10168_0, _uniq_i_10169_0) /* forall<a,b,e> (f : (a) -> e b, v : vector<a>, w : vector<b>, ssize_t, ssize_t) -> e () */  { tailcall: while(1)
{
  if ((_uniq_i_10169_0 < _uniq_n_10168_0)) {
     
    var x_10019 = (v_0)[_uniq_i_10169_0];
     
    var x_10280 = f_0(x_10019);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10239_0 /* 765 */ ) {
        return _mlift_lift_map_10181_10252(_uniq_i_10169_0, _uniq_n_10168_0, f_0, v_0, w_0, _y_x10239_0);
      });
    }
    else {
       
      var _uniq_x___10171_0 = (w_0)[_uniq_i_10169_0] = x_10280;
       
      var _uniq_i_0_10000_10172_0 = ssize__t_fs_incr(_uniq_i_10169_0);
      {
        // tail call
        _uniq_i_10169_0 = _uniq_i_0_10000_10172_0;
        continue tailcall;
      }
    }
  }
  else {
    return $std_core_types.Unit;
  }
}}
 
 
// monadic lift
export function _mlift_map_10253(w, wild__) /* forall<a,e> (w : vector<a>, wild_ : ()) -> e vector<a> */  {
  return w;
}
 
 
// Apply a total function `f` to each element in a vector `v`
export function map(v, f) /* forall<a,b,e> (v : vector<a>, f : (a) -> e b) -> e vector<b> */  {
   
  var w = Array(($std_core_int.ssize__t($std_core_types._int_from_int32((((v).length))))));
   
  var n_10003 = ((v).length);
   
  var i = 0;
   
  var x_10283 = _lift_map_10181(f, v, w, n_10003, i);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(wild__ /* () */ ) {
      return w;
    });
  }
  else {
    return w;
  }
}
 
 
// Convert a vector to a list with an optional tail.
export function vlist(v, tail) /* forall<a> (v : vector<a>, tail : ? (list<a>)) -> list<a> */  {
  var _x2 = (tail !== undefined) ? tail : $std_core_types.Nil;
  return _vlist(v,_x2);
}
 
 
// Convert a vector to a list.
export function list(v) /* forall<a> (v : vector<a>) -> list<a> */  {
  return vlist(v);
}
 
export function unvlist(xs) /* forall<a> (xs : list<a>) -> vector<a> */  {
  return _unvlist(xs);
}
 
 
// Convert a list to a vector.
export function list_fs_vector(xs) /* forall<a> (xs : list<a>) -> vector<a> */  {
  return unvlist(xs);
}
 
export function ssize__t_fs_is_zero(i) /* (i : ssize_t) -> bool */  {
  return (i === 0);
}
 
export function ssize__t_fs_decr(i) /* (i : ssize_t) -> ssize_t */  {
  return (i - 1);
}