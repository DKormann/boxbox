// Koka generated module: std/core/either, koka version: 3.1.2
"use strict";
 
// imports
import * as $std_core_types from './std_core_types.mjs';
import * as $std_core_hnd from './std_core_hnd.mjs';
 
// externals
 
// type declarations
 
// declarations
 
 
// Convert a `:either` to a `:maybe` type discarding the value of the `Left` constructor
// and using `Just` for the `Right` constructor.
export function maybe(e) /* forall<a,b> (e : either<a,b>) -> maybe<b> */  {
  if (e._tag === 1) {
    return $std_core_types.Nothing;
  }
  else {
    return $std_core_types.Just(e.right);
  }
}
 
 
// monadic lift
export function _mlift_map_10105(_y_x10100) /* forall<a,b,e> (b) -> e either<a,b> */  {
  return $std_core_types.Right(_y_x10100);
}
 
 
// Map over the `Right` component of an `:either` type.
export function map(e, f) /* forall<a,b,c,e> (e : either<a,b>, f : (b) -> e c) -> e either<a,c> */  {
  if (e._tag === 2) {
     
    var x_0_10108 = f(e.right);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10100 /* 126 */ ) {
        return $std_core_types.Right(_y_x10100);
      });
    }
    else {
      return $std_core_types.Right(x_0_10108);
    }
  }
  else {
    return $std_core_types.Left(e.left);
  }
}
 
 
// monadic lift
export function _mlift_show_10106(_y_x10102) /* forall<e> (string) -> e string */  {
  return $std_core_types._lp__plus__plus__rp_("Right(", $std_core_types._lp__plus__plus__rp_(_y_x10102, ")"));
}
 
 
// monadic lift
export function _mlift_show_10107(_y_x10103) /* forall<e> (string) -> e string */  {
  return $std_core_types._lp__plus__plus__rp_("Left(", $std_core_types._lp__plus__plus__rp_(_y_x10103, ")"));
}
 
 
// Show an `:either` type
export function show(e, _implicit_fs_left_fs_show, _implicit_fs_right_fs_show) /* forall<a,b,e> (e : either<a,b>, ?left/show : (a) -> e string, ?right/show : (b) -> e string) -> e string */  {
  if (e._tag === 2) {
     
    var x_0_10112 = _implicit_fs_right_fs_show(e.right);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10102 /* string */ ) {
        return $std_core_types._lp__plus__plus__rp_("Right(", $std_core_types._lp__plus__plus__rp_(_y_x10102, ")"));
      });
    }
    else {
      return $std_core_types._lp__plus__plus__rp_("Right(", $std_core_types._lp__plus__plus__rp_(x_0_10112, ")"));
    }
  }
  else {
     
    var x_1_10116 = _implicit_fs_left_fs_show(e.left);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10103 /* string */ ) {
        return $std_core_types._lp__plus__plus__rp_("Left(", $std_core_types._lp__plus__plus__rp_(_y_x10103, ")"));
      });
    }
    else {
      return $std_core_types._lp__plus__plus__rp_("Left(", $std_core_types._lp__plus__plus__rp_(x_1_10116, ")"));
    }
  }
}