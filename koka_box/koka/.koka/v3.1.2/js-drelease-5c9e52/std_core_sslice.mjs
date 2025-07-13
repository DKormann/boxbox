// Koka generated module: std/core/sslice, koka version: 3.1.2
"use strict";
 
// imports
import * as $std_core_types from './std_core_types.mjs';
import * as $std_core_undiv from './std_core_undiv.mjs';
import * as $std_core_unsafe from './std_core_unsafe.mjs';
import * as $std_core_hnd from './std_core_hnd.mjs';
import * as $std_core_int from './std_core_int.mjs';
import * as $std_core_string from './std_core_string.mjs';
 
// externals
/*---------------------------------------------------------------------------
  Copyright 2012-2024, Microsoft Research, Daan Leijen.
  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/
function _slice_to_string(sl) {
  if (sl.start===0 && sl.len===sl.str.length) return sl.str;
  return sl.str.substr(sl.start,sl.len);
}
function _sslice_first( s ) {
  var len;
  if (s.length===0) len = 0;
  else if ($std_core_string._is_high_surrogate(s.charCodeAt(0))) len = 2
  else len = 1;
  return { str: s, start: 0, len: len };
}
function _sslice_last( s ) {
  var len;
  if (s.length===0) len = 0;
  else if ($std_core_string._is_low_surrogate(s.charCodeAt(s.length-1))) len = 2
  else len = 1;
  return { str: s, start: s.length-len, len: len };
}
function _sslice_count(slice) {
  if (slice.len<=0) return 0;
  var count = 0;
  var end = slice.start + slice.len;
  $std_core_string._char_iter(slice.str, slice.start, function(c,i,nexti) {
    count++;
    return (nexti >= end);
  });
  return count;
}
// Extend the length of slice
function _sslice_extend( slice, count ) {
  if (count===0) return slice;
  var idx = slice.start + slice.len;
  if (count > 0) {
    $std_core_string._char_iter(slice.str, idx, function(c,i,nexti) {
      count--;
      idx = nexti;
      return (count <= 0);
    });
  }
  else {
    $std_core_string._char_reviter(slice.str, idx-1, function(c,i,nexti) {
      count++;
      idx = i;
      return (count >= 0 || idx <= slice.start);
    });
  }
  return { str: slice.str, start: slice.start, len: (idx > slice.start ? idx - slice.start : 0) };
}
// advance the start position of a slice
function _sslice_advance( slice, count ) {
  if (count===0) return slice;
  var idx = slice.start;
  var end = slice.start + slice.len;
  var slicecount = _sslice_count(slice); // todo: optimize by caching the character count?
  if (count > 0) {
    var extra = 0;
    $std_core_string._char_iter(slice.str, idx, function(c,i,nexti) {
      extra++;
      idx = nexti;
      return (extra >= count);
    });
    if (extra < slicecount && idx < end) { // optimize
      return _sslice_extend({ str: slice.str, start: idx, len: end-idx }, extra);
    }
  }
  else {
    var extra = 0;
    $std_core_string._char_reviter(slice.str, idx-1, function(c,i,nexti) {
      extra++;
      idx = i;
      return (extra >= -count);
    });
    if (extra < slicecount && idx < slice.start) {  // optimize
      return _sslice_extend({ str: slice.str, start: idx, len: slice.start-idx }, slicecount - extra);
    }
  }
  return _sslice_extend( { str: slice.str, start: idx, len: 0 }, slicecount );
}
// iterate through a slice
function _sslice_next( slice ) {
  if (slice.len <= 0) return null;
  var c = slice.str.charCodeAt(slice.start);
  var n = 1;
  if ($std_core_string._is_high_surrogate(c) && slice.len > 1) {
    var lo = slice.str.charCodeAt(slice.start+1);
    if ($std_core_string._is_low_surrogate(lo)) {
      c = $std_core_string._from_surrogate(c,lo);
      n = 2;
    }
  }
  return $std_core_types.Just( {fst: c, snd: { str: slice.str, start: slice.start+n, len: slice.len-n }} );
}
// return the common prefix of two strings
function _sslice_common_prefix( s, t, upto ) {
  var i;
  var max = Math.min(s.length,t.length);
  for(i = 0; i < max && upto > 0; i++) {
    var c = s.charCodeAt(i);
    if (c !== t.charCodeAt(i)) break;
    if (!$std_core_string._is_low_surrogate(c)) upto--; // count characters
  }
  return { str: s, start: 0, len: i };
}
 
// type declarations
// type sslice
export function Sslice(str, start, len) /* (str : string, start : int, len : int) -> sslice */  {
  return { str: str, start: start, len: len };
}
 
// declarations
 
 
// Automatically generated. Retrieves the `str` constructor field of the `:sslice` type.
export function sslice_fs_str(sslice) /* (sslice : sslice) -> string */  {
  return sslice.str;
}
 
 
// Automatically generated. Retrieves the `start` constructor field of the `:sslice` type.
export function sslice_fs_start(sslice) /* (sslice : sslice) -> int */  {
  return sslice.start;
}
 
 
// Automatically generated. Retrieves the `len` constructor field of the `:sslice` type.
export function sslice_fs_len(sslice) /* (sslice : sslice) -> int */  {
  return sslice.len;
}
 
export function sslice_fs__copy(_this, str, start, len) /* (sslice, str : ? string, start : ? int, len : ? int) -> sslice */  {
  if (str !== undefined) {
    var _x0 = str;
  }
  else {
    var _x0 = _this.str;
  }
  if (start !== undefined) {
    var _x1 = start;
  }
  else {
    var _x1 = _this.start;
  }
  if (len !== undefined) {
    var _x2 = len;
  }
  else {
    var _x2 = _this.len;
  }
  return Sslice(_x0, _x1, _x2);
}
 
 
// Internal export for the regex module
export function _new_sslice(str, start, len) /* (str : string, start : int, len : int) -> sslice */  {
  return Sslice(str, start, len);
}
 
 
// O(n). Copy the `slice` argument into a fresh string.
// Takes O(1) time if the slice covers the entire string.
export function string(slice_0) /* (slice : sslice) -> string */  {
  return _slice_to_string(slice_0);
}
 
 
// Equality based on contents of the slice
// O(`n`+`m`) where `n` and `m` are the lengths of the two strings
export function _lp__eq__eq__rp_(slice1, slice2) /* (slice1 : sslice, slice2 : sslice) -> bool */  {
  var _x3 = Object.is((slice1.str),(slice2.str));
  if (_x3) {
    if ($std_core_types._int_eq((slice1.start),(slice2.start))) {
      if ($std_core_types._int_eq((slice1.len),(slice2.len))) {
        return true;
      }
      else {
        return ((string(slice1)) === (string(slice2)));
      }
    }
    else {
      return ((string(slice1)) === (string(slice2)));
    }
  }
  else {
    return ((string(slice1)) === (string(slice2)));
  }
}
 
 
// Inequality based on contents of the slice
// O(`n`+`m`) where `n` and `m` are the lengths of the two strings
export function _lp__excl__eq__rp_(slice1, slice2) /* (slice1 : sslice, slice2 : sslice) -> bool */  {
   
  var b_10003 = _lp__eq__eq__rp_(slice1, slice2);
  return (b_10003) ? false : true;
}
 
 
// Equality of slices at the same offset and length on an equal string
// (The strings do not have to be referentially identical though)
export function _lp__eq__eq__eq__rp_(slice1, slice2) /* (slice1 : sslice, slice2 : sslice) -> bool */  {
  if ($std_core_types._int_eq((slice1.start),(slice2.start))) {
    return ($std_core_types._int_eq((slice1.len),(slice2.len))) ? ((slice1.str) === (slice2.str)) : false;
  }
  else {
    return false;
  }
}
 
 
// Inequality of slices at the same offset and length on the same string.
// (The strings do not have to be referentially identical though)
export function _lp__excl__eq__eq__rp_(slice1, slice2) /* (slice1 : sslice, slice2 : sslice) -> bool */  {
   
  var b_10004 = _lp__eq__eq__eq__rp_(slice1, slice2);
  return (b_10004) ? false : true;
}
 
 
// O(n). Return the number of characters in a string slice
export function count(slice_0) /* (slice : sslice) -> int */  {
  return _sslice_count(slice_0);
}
 
export function first1(s) /* (s : string) -> sslice */  {
  return _sslice_first(s);
}
 
export function last1(s) /* (s : string) -> sslice */  {
  return _sslice_last(s);
}
 
 
// O(1). The entire string as a slice
export function slice(s) /* (s : string) -> sslice */  {
  return Sslice(s, 0, s.length);
}
 
 
// If the slice is not empty,
// return the first character, and a new slice that is advanced by 1.
export function next(slice_0) /* (slice : sslice) -> maybe<(char, sslice)> */  {
  return _sslice_next(slice_0);
}
 
 
// monadic lift
export function _mlift_foreach_while_10275(action, rest, _y_x10243) /* forall<a,e> (action : (c : char) -> e maybe<a>, rest : sslice, maybe<a>) -> e maybe<a> */  {
  if (_y_x10243 === null) {
    return foreach_while(rest, action);
  }
  else {
    return _y_x10243;
  }
}
 
 
// Apply a function for each character in a string slice.
// If `action` returns `Just`, the function returns immediately with that result.
export function foreach_while(slice_0, action_0) /* forall<a,e> (slice : sslice, action : (c : char) -> e maybe<a>) -> e maybe<a> */  { tailcall: while(1)
{
  var _x4 = next(slice_0);
  if (_x4 === null) {
    return $std_core_types.Nothing;
  }
  else {
     
    var x_10284 = action_0(_x4.value.fst);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10243_0 /* maybe<441> */ ) {
        return _mlift_foreach_while_10275(action_0, _x4.value.snd, _y_x10243_0);
      });
    }
    else {
      if (x_10284 === null) {
        {
          // tail call
          slice_0 = _x4.value.snd;
          continue tailcall;
        }
      }
      else {
        return x_10284;
      }
    }
  }
}}
 
 
// Invoke a function for each character in a string.
// If `action` returns `Just`, the function returns immediately with that result.
export function string_fs_foreach_while(s, action) /* forall<a,e> (s : string, action : (c : char) -> e maybe<a>) -> e maybe<a> */  {
  return foreach_while(Sslice(s, 0, s.length), action);
}
 
 
// monadic lift
export function _mlift_lift_foreach_10234_10276(_uniq_rest_10198, action, wild__) /* forall<_a,e> (sslice, action : (c : char) -> e (), wild_ : ()) -> e maybe<_a> */  {
  var _x5 = $std_core_types.Nothing;
  if (_x5 === null) {
    return _lift_foreach_10234(action, _uniq_rest_10198);
  }
  else {
    return _x5;
  }
}
 
 
// lifted local: foreach, @spec-x10204
// specialized: std/core/sslice/foreach-while, on parameters @uniq-action@10193, using:
// @uniq-action@10193 = fn<(e :: E)>(c: char){
//   val _ : ()
//         = action(c);
//   std/core/types/Nothing<_a>;
// }
export function _lift_foreach_10234(action_0, _uniq_slice_0_10192) /* forall<_a,e> (action : (c : char) -> e (), sslice) -> e maybe<_a> */  { tailcall: while(1)
{
  var _x6 = next(_uniq_slice_0_10192);
  if (_x6 === null) {
    return $std_core_types.Nothing;
  }
  else {
     
    var x_10287 = action_0(_x6.value.fst);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(wild___0 /* () */ ) {
        return _mlift_lift_foreach_10234_10276(_x6.value.snd, action_0, wild___0);
      });
    }
    else {
      var _x7 = $std_core_types.Nothing;
      if (_x7 === null) {
        {
          // tail call
          _uniq_slice_0_10192 = _x6.value.snd;
          continue tailcall;
        }
      }
      else {
        return _x7;
      }
    }
  }
}}
 
 
// monadic lift
export function _mlift_foreach_10277(wild___0) /* forall<_a,e> (wild_@0 : maybe<_a>) -> e () */  {
  return $std_core_types.Unit;
}
 
 
// Apply a function for each character in a string slice.
export function foreach(slice_0, action) /* forall<e> (slice : sslice, action : (c : char) -> e ()) -> e () */  {
   
  var x_10290 = _lift_foreach_10234(action, slice_0);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(wild___0 /* maybe<_505> */ ) {
      return $std_core_types.Unit;
    });
  }
  else {
    return $std_core_types.Unit;
  }
}
 
 
// monadic lift
export function string_fs__mlift_lift_foreach_10235_10278(_uniq_rest_10212, action, wild__) /* forall<_a,e> (sslice, action : (c : char) -> e (), wild_ : ()) -> e maybe<_a> */  {
  var _x8 = $std_core_types.Nothing;
  if (_x8 === null) {
    return string_fs__lift_foreach_10235(action, _uniq_rest_10212);
  }
  else {
    return _x8;
  }
}
 
 
// lifted local: string/foreach, @spec-x10218
// specialized: std/core/sslice/foreach-while, on parameters @uniq-action@10207, using:
// @uniq-action@10207 = fn<(e :: E)>(c: char){
//   val _ : ()
//         = action(c);
//   std/core/types/Nothing<_a>;
// }
export function string_fs__lift_foreach_10235(action_0, _uniq_slice_0_10206) /* forall<_a,e> (action : (c : char) -> e (), sslice) -> e maybe<_a> */  { tailcall: while(1)
{
  var _x9 = next(_uniq_slice_0_10206);
  if (_x9 === null) {
    return $std_core_types.Nothing;
  }
  else {
     
    var x_10294 = action_0(_x9.value.fst);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(wild___0 /* () */ ) {
        return string_fs__mlift_lift_foreach_10235_10278(_x9.value.snd, action_0, wild___0);
      });
    }
    else {
      var _x10 = $std_core_types.Nothing;
      if (_x10 === null) {
        {
          // tail call
          _uniq_slice_0_10206 = _x9.value.snd;
          continue tailcall;
        }
      }
      else {
        return _x10;
      }
    }
  }
}}
 
 
// monadic lift
export function string_fs__mlift_foreach_10279(wild___0) /* forall<_a,e> (wild_@0 : maybe<_a>) -> e () */  {
  return $std_core_types.Unit;
}
 
 
// Invoke a function for each character in a string
export function string_fs_foreach(s, action) /* forall<e> (s : string, action : (c : char) -> e ()) -> e () */  {
   
  var slice_0_10005 = Sslice(s, 0, s.length);
   
  var x_10297 = string_fs__lift_foreach_10235(action, slice_0_10005);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(wild___0 /* maybe<_505> */ ) {
      return $std_core_types.Unit;
    });
  }
  else {
    return $std_core_types.Unit;
  }
}
 
 
// monadic lift
export function pred_fs__mlift_lift_count_10236_10280(cnt, _y_x10260) /* forall<h,e> (cnt : local-var<h,int>, int) -> <local<h>|e> () */  {
  return ((cnt).value = ($std_core_types._int_add(_y_x10260,1)));
}
 
 
// monadic lift
export function pred_fs__mlift_lift_count_10236_10281(_uniq_rest_10226, cnt_0, pred, _c_x10262) /* forall<_a,h,e> (sslice, cnt : local-var<h,int>, pred : (char) -> e bool, ()) -> maybe<_a> */  {
  var _x11 = $std_core_types.Nothing;
  if (_x11 === null) {
    return pred_fs__lift_count_10236(cnt_0, pred, _uniq_rest_10226);
  }
  else {
    return _x11;
  }
}
 
 
// monadic lift
export function pred_fs__mlift_lift_count_10236_10282(_uniq_rest_10226_0, cnt_1, pred_0, _y_x10259) /* forall<_a,h,e> (sslice, cnt : local-var<h,int>, pred : (char) -> e bool, bool) -> <local<h>|e> maybe<_a> */  {
   
  if (_y_x10259) {
     
    var x_0_10303 = ((cnt_1).value);
    if ($std_core_hnd._yielding()) {
      var x_10301 = $std_core_hnd.yield_extend(function(_y_x10260_0 /* int */ ) {
        return pred_fs__mlift_lift_count_10236_10280(cnt_1, _y_x10260_0);
      });
    }
    else {
      var x_10301 = pred_fs__mlift_lift_count_10236_10280(cnt_1, x_0_10303);
    }
  }
  else {
    var x_10301 = $std_core_types.Unit;
  }
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(_c_x10262_0 /* () */ ) {
      return pred_fs__mlift_lift_count_10236_10281(_uniq_rest_10226_0, cnt_1, pred_0, _c_x10262_0);
    });
  }
  else {
    return pred_fs__mlift_lift_count_10236_10281(_uniq_rest_10226_0, cnt_1, pred_0, x_10301);
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
export function pred_fs__lift_count_10236(cnt_2, pred_1, _uniq_slice_0_10220) /* forall<_a,h,e> (cnt : local-var<h,int>, pred : (char) -> e bool, sslice) -> <local<h>|e> maybe<_a> */  { tailcall: while(1)
{
  var _x12 = next(_uniq_slice_0_10220);
  if (_x12 === null) {
    return $std_core_types.Nothing;
  }
  else {
     
    var x_1_10305 = pred_1(_x12.value.fst);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10259_0 /* bool */ ) {
        return pred_fs__mlift_lift_count_10236_10282(_x12.value.snd, cnt_2, pred_1, _y_x10259_0);
      });
    }
    else {
       
      if (x_1_10305) {
         
        var x_3_10312 = ((cnt_2).value);
        if ($std_core_hnd._yielding()) {
          var x_2_10309 = $std_core_hnd.yield_extend(function(_y_x10260_1 /* int */ ) {
            return pred_fs__mlift_lift_count_10236_10280(cnt_2, _y_x10260_1);
          });
        }
        else {
          var x_2_10309 = pred_fs__mlift_lift_count_10236_10280(cnt_2, x_3_10312);
        }
      }
      else {
        var x_2_10309 = $std_core_types.Unit;
      }
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(_c_x10262_1 /* () */ ) {
          return pred_fs__mlift_lift_count_10236_10281(_x12.value.snd, cnt_2, pred_1, _c_x10262_1);
        });
      }
      else {
        var _x13 = $std_core_types.Nothing;
        if (_x13 === null) {
          {
            // tail call
            _uniq_slice_0_10220 = _x12.value.snd;
            continue tailcall;
          }
        }
        else {
          return _x13;
        }
      }
    }
  }
}}
 
 
// monadic lift
export function pred_fs__mlift_count_10283(cnt, wild___0) /* forall<_a,h,e> (cnt : local-var<h,int>, wild_@0 : maybe<_a>) -> <local<h>|e> int */  {
  return ((cnt).value);
}
 
 
// Count the number of times a predicate is true for each character in a string
export function pred_fs_count(s, pred) /* forall<e> (s : string, pred : (char) -> e bool) -> e int */  {
  return function() {
     
    var loc = { value: 0 };
     
    var slice_0_10010 = Sslice(s, 0, s.length);
     
    var x_10316 = pred_fs__lift_count_10236(loc, pred, slice_0_10010);
     
    if ($std_core_hnd._yielding()) {
      var res = $std_core_hnd.yield_extend(function(wild___0 /* maybe<_505> */ ) {
        return ((loc).value);
      });
    }
    else {
      var res = ((loc).value);
    }
    return $std_core_hnd.prompt_local_var(loc, res);
  }();
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
export function advance(slice_0, count_0) /* (slice : sslice, count : int) -> sslice */  {
  return _sslice_advance(slice_0,count_0);
}
 
 
// O(`count`). Extend a string slice by `count` characters up to the end of the string.
// A negative `count` shrinks the slice up to the empty slice.
// For example:
//
// * `"abc".first.extend(1).string == "ab"`
// * `"abc".last.extend(-1).string == ""`
//
export function extend(slice_0, count_0) /* (slice : sslice, count : int) -> sslice */  {
  return _sslice_extend(slice_0,count_0);
}
 
 
// O(`n`). The first `n` (default = `1`) characters in a string.
export function first(s, n) /* (s : string, n : ? int) -> sslice */  {
   
  var slice_0 = first1(s);
  var _x15 = (n !== undefined) ? n : 1;
  var _x14 = $std_core_types._int_eq(_x15,1);
  if (_x14) {
    return slice_0;
  }
  else {
    var _x16 = (n !== undefined) ? n : 1;
    return extend(slice_0, $std_core_types._int_sub(_x16,1));
  }
}
 
 
// O(`n`). The last `n` (default = `1`) characters in a string
export function last(s, n) /* (s : string, n : ? int) -> sslice */  {
   
  var slice_0 = last1(s);
  var _x18 = (n !== undefined) ? n : 1;
  var _x17 = $std_core_types._int_eq(_x18,1);
  if (_x17) {
    return slice_0;
  }
  else {
    var _x19 = (n !== undefined) ? n : 1;
    var _x20 = (n !== undefined) ? n : 1;
    return extend(advance(slice_0, $std_core_types._int_sub(1,_x19)), $std_core_types._int_sub(_x20,1));
  }
}
 
 
// O(1). Return the string slice from the start of a string up to the
// start of `slice` argument.
export function before(slice_0) /* (slice : sslice) -> sslice */  {
  return Sslice(slice_0.str, 0, slice_0.start);
}
 
 
// O(1). Return the string slice from the end of `slice` argument
// to the end of the string.
export function after(slice_0) /* (slice : sslice) -> sslice */  {
   
  var x_0_10020 = (slice_0.str).length;
   
  var y_0_10021 = $std_core_types._int_add((slice_0.start),(slice_0.len));
  return Sslice(slice_0.str, $std_core_types._int_add((slice_0.start),(slice_0.len)), $std_core_types._int_sub(x_0_10020,y_0_10021));
}
 
 
// Convert the first character of a string to uppercase.
export function capitalize(s) /* (s : string) -> string */  {
   
  var slice_0_1 = first1(s);
   
  var _x23 = undefined;
  var _x22 = (_x23 !== undefined) ? _x23 : 1;
  var _x21 = $std_core_types._int_eq(_x22,1);
  if (_x21) {
    var slice_0_0_10028 = slice_0_1;
  }
  else {
    var _x25 = undefined;
    var _x24 = (_x25 !== undefined) ? _x25 : 1;
    var slice_0_0_10028 = extend(slice_0_1, $std_core_types._int_sub(_x24,1));
  }
   
  var slice_0 = first1(s);
  var _x24 = undefined;
  var _x23 = (_x24 !== undefined) ? _x24 : 1;
  var _x22 = $std_core_types._int_eq(_x23,1);
  if (_x22) {
    var _x21 = slice_0;
  }
  else {
    var _x26 = undefined;
    var _x25 = (_x26 !== undefined) ? _x26 : 1;
    var _x21 = extend(slice_0, $std_core_types._int_sub(_x25,1));
  }
   
  var x_1_10035 = (slice_0_0_10028.str).length;
   
  var y_1_10036 = $std_core_types._int_add((slice_0_0_10028.start),(slice_0_0_10028.len));
  var _x27 = Sslice(slice_0_0_10028.str, $std_core_types._int_add((slice_0_0_10028.start),(slice_0_0_10028.len)), $std_core_types._int_sub(x_1_10035,y_1_10036));
  return $std_core_types._lp__plus__plus__rp_($std_core_string.to_upper(string(_x21)), string(_x27));
}
 
 
// An empty slice
export var empty;
var empty = Sslice("", 0, 0);
 
 
// Is a slice empty?
export function is_empty(slice_0) /* (slice : sslice) -> bool */  {
   
  var _x28 = slice_0.len;
  var b_10039 = $std_core_types._int_gt(_x28,0);
  return (b_10039) ? false : true;
}
 
 
// An invalid slice
export var invalid;
var invalid = Sslice("", -1, 0);
 
 
// Is a slice invalid?
export function is_valid(slice_0) /* (slice : sslice) -> bool */  {
  var _x28 = slice_0.start;
  return $std_core_types._int_ge(_x28,0);
}
 
 
// Is a slice not empty?
export function is_notempty(slice_0) /* (slice : sslice) -> bool */  {
  var _x29 = slice_0.len;
  return $std_core_types._int_gt(_x29,0);
}
 
 
// Return the first character of a string as a string (or the empty string)
export function head(s) /* (s : string) -> string */  {
   
  var slice_0 = first1(s);
  var _x33 = undefined;
  var _x32 = (_x33 !== undefined) ? _x33 : 1;
  var _x31 = $std_core_types._int_eq(_x32,1);
  if (_x31) {
    var _x30 = slice_0;
  }
  else {
    var _x35 = undefined;
    var _x34 = (_x35 !== undefined) ? _x35 : 1;
    var _x30 = extend(slice_0, $std_core_types._int_sub(_x34,1));
  }
  return string(_x30);
}
 
 
// Return the tail of a string (or the empty string)
export function tail(s) /* (s : string) -> string */  {
   
  var slice_0_0 = first1(s);
   
  var _x38 = undefined;
  var _x37 = (_x38 !== undefined) ? _x38 : 1;
  var _x36 = $std_core_types._int_eq(_x37,1);
  if (_x36) {
    var slice_0_10049 = slice_0_0;
  }
  else {
    var _x40 = undefined;
    var _x39 = (_x40 !== undefined) ? _x40 : 1;
    var slice_0_10049 = extend(slice_0_0, $std_core_types._int_sub(_x39,1));
  }
   
  var x_0_10056 = (slice_0_10049.str).length;
   
  var y_0_10057 = $std_core_types._int_add((slice_0_10049.start),(slice_0_10049.len));
  var _x36 = Sslice(slice_0_10049.str, $std_core_types._int_add((slice_0_10049.start),(slice_0_10049.len)), $std_core_types._int_sub(x_0_10056,y_0_10057));
  return string(_x36);
}
 
 
// Return the common prefix of two strings (upto `upto` characters (default is minimum length of the two strings))
export function common_prefix(s, t, upto) /* (s : string, t : string, upto : ? int) -> sslice */  {
  var _x37 = (upto !== undefined) ? upto : -1;
  return _sslice_common_prefix(s,t,_x37);
}
 
 
// Truncates a slice to length 0
export function truncate(slice_0) /* (slice : sslice) -> sslice */  {
  var _x38 = slice_0.str;
  var _x39 = slice_0.start;
  return Sslice(_x38, _x39, 0);
}
 
 
// Truncate a string to `count` characters.
export function string_fs_truncate(s, count_0) /* (s : string, count : int) -> string */  {
   
  var slice_0 = first1(s);
  var _x43 = undefined;
  var _x42 = (_x43 !== undefined) ? _x43 : 1;
  var _x41 = $std_core_types._int_eq(_x42,1);
  if (_x41) {
    var _x40 = slice_0;
  }
  else {
    var _x45 = undefined;
    var _x44 = (_x45 !== undefined) ? _x45 : 1;
    var _x40 = extend(slice_0, $std_core_types._int_sub(_x44,1));
  }
  return string(extend(_x40, $std_core_types._int_sub(count_0,1)));
}
 
 
// Gets up to (`end`-`start`) characters from the slice beginning from `start`.
// If either start or end is negative, returns the original slice
export function subslice(slice_0, start, end) /* (slice : sslice, start : int, end : int) -> sslice */  {
  if ($std_core_types._int_lt(start,0)) {
    return slice_0;
  }
  else {
    if ($std_core_types._int_lt(end,0)) {
      return slice_0;
    }
    else {
       
      var slice_0_0_10068 = advance(slice_0, start);
      var _x46 = slice_0_0_10068.str;
      var _x47 = slice_0_0_10068.start;
      return extend(Sslice(_x46, _x47, 0), $std_core_types._int_sub(end,start));
    }
  }
}
 
 
// Gets a slice that only includes up to n characters from the start of the slice.
export function take(slice_0, n) /* (slice : sslice, n : int) -> sslice */  {
  if ($std_core_types._int_le(n,0)) {
    return slice_0;
  }
  else {
    var _x48 = slice_0.str;
    var _x49 = slice_0.start;
    return extend(Sslice(_x48, _x49, 0), n);
  }
}
 
 
// Gets a slice that drops the first n characters, shrinking the length of the slice by n accordingly.
// If the slice does not have n characters, then the slice is shrunk to an empty slice.
//
// If maintaining the length of the slice is important, use `advance` instead.
export function drop(slice_0, n) /* (slice : sslice, n : int) -> sslice */  {
  if ($std_core_types._int_le(n,0)) {
    return slice_0;
  }
  else {
     
    var slice_0_0_10076 = advance(slice_0, n);
     
    var x_10079 = count(slice_0);
    var _x50 = slice_0_0_10076.str;
    var _x51 = slice_0_0_10076.start;
    return extend(Sslice(_x50, _x51, 0), $std_core_types._int_sub(x_10079,n));
  }
}
 
 
// Return the first character of a string (or `Nothing` for the empty string).
export function head_char(s) /* (s : string) -> maybe<char> */  {
  return foreach_while(Sslice(s, 0, s.length), $std_core_types.Just);
}
 
 
// O(n). If it occurs, return the position of substring `sub` in `s`, tupled with
// the position just following the substring `sub`.
export function find(s, sub) /* (s : string, sub : string) -> maybe<sslice> */  {
   
  var i = $std_core_types._int_from_int32((((s).indexOf(sub) + 1)));
  if ($std_core_types._int_iszero(i)) {
    return $std_core_types.Nothing;
  }
  else {
    return $std_core_types.Just(Sslice(s, $std_core_types._int_sub(i,1), sub.length));
  }
}
 
 
// Return the last index of substring `sub` in `s` if it occurs.
export function find_last(s, sub) /* (s : string, sub : string) -> maybe<sslice> */  {
   
  var i = $std_core_types._int_from_int32((((s).lastIndexOf(sub) + 1)));
  if ($std_core_types._int_iszero(i)) {
    return $std_core_types.Nothing;
  }
  else {
    return $std_core_types.Just(Sslice(s, $std_core_types._int_sub(i,1), sub.length));
  }
}
 
 
// Is `pre`  a prefix of `s`? If so, returns a slice
// of `s` following `pre` up to the end of `s`.
export function starts_with(s, pre) /* (s : string, pre : string) -> maybe<sslice> */  {
  if ((s.substr(0,pre.length) === pre)) {
     
    var x_10085 = s.length;
     
    var y_10086 = pre.length;
    return $std_core_types.Just(Sslice(s, pre.length, $std_core_types._int_sub(x_10085,y_10086)));
  }
  else {
    return $std_core_types.Nothing;
  }
}
 
export function xends_with(s, post) /* (s : string, post : string) -> bool */  {
  return ((s).indexOf(post, (s).length - (post).length) !== -1);
}
 
 
// Does string `s`  end with `post`?
// If so, returns a slice of `s` from the start up to the `post` string at the end.
export function ends_with(s, post) /* (s : string, post : string) -> maybe<sslice> */  {
  var _x52 = xends_with(s, post);
  if (_x52) {
     
    var x_10087 = s.length;
     
    var y_10088 = post.length;
    return $std_core_types.Just(Sslice(s, 0, $std_core_types._int_sub(x_10087,y_10088)));
  }
  else {
    return $std_core_types.Nothing;
  }
}
 
 
// Trim off a substring `sub` while `s` starts with that string.
export function trim_left(s, sub) /* (s : string, sub : string) -> string */  { tailcall: while(1)
{
  if ((sub === (""))) {
    return s;
  }
  else {
    var _x53 = starts_with(s, sub);
    if (_x53 !== null) {
      {
        // tail call
        var _x54 = string(_x53.value);
        s = _x54;
        continue tailcall;
      }
    }
    else {
      return s;
    }
  }
}}
 
 
// Trim off a substring `sub` while `s` ends with that string.
export function trim_right(s, sub) /* (s : string, sub : string) -> string */  { tailcall: while(1)
{
  if ((sub === (""))) {
    return s;
  }
  else {
    var _x55 = ends_with(s, sub);
    if (_x55 !== null) {
      {
        // tail call
        var _x56 = string(_x55.value);
        s = _x56;
        continue tailcall;
      }
    }
    else {
      return s;
    }
  }
}}