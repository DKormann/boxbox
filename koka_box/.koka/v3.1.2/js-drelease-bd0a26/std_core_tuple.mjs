// Koka generated module: std/core/tuple, koka version: 3.1.2
"use strict";
 
// imports
import * as $std_core_types from './std_core_types.mjs';
import * as $std_core_hnd from './std_core_hnd.mjs';
 
// externals
 
// type declarations
 
// declarations
 
 
// monadic lift
export function tuple2_fs__mlift_map_10129(_y_x10100, _y_x10101) /* forall<a,e> (a, a) -> e (a, a) */  {
  return $std_core_types.Tuple2(_y_x10100, _y_x10101);
}
 
 
// monadic lift
export function tuple2_fs__mlift_map_10130(f, t, _y_x10100) /* forall<a,b,e> (f : (a) -> e b, t : (a, a), b) -> e (b, b) */  {
   
  var _x0 = t.snd;
  var x_10143 = f(_x0);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(_y_x10101 /* 238 */ ) {
      return $std_core_types.Tuple2(_y_x10100, _y_x10101);
    });
  }
  else {
    return $std_core_types.Tuple2(_y_x10100, x_10143);
  }
}
 
 
// Map a function over a tuple of elements of the same type.
export function tuple2_fs_map(t, f) /* forall<a,b,e> (t : (a, a), f : (a) -> e b) -> e (b, b) */  {
   
  var _x0 = t.fst;
  var x_10147 = f(_x0);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(_y_x10100 /* 238 */ ) {
      return tuple2_fs__mlift_map_10130(f, t, _y_x10100);
    });
  }
  else {
     
    var _x0 = t.snd;
    var x_0_10150 = f(_x0);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10101 /* 238 */ ) {
        return $std_core_types.Tuple2(x_10147, _y_x10101);
      });
    }
    else {
      return $std_core_types.Tuple2(x_10147, x_0_10150);
    }
  }
}
 
 
// monadic lift
export function tuple3_fs__mlift_map_10131(_y_x10102, _y_x10103, _y_x10104) /* forall<a,e> (a, a, a) -> e (a, a, a) */  {
  return $std_core_types.Tuple3(_y_x10102, _y_x10103, _y_x10104);
}
 
 
// monadic lift
export function tuple3_fs__mlift_map_10132(_y_x10102, f, t, _y_x10103) /* forall<a,b,e> (b, f : (a) -> e b, t : (a, a, a), b) -> e (b, b, b) */  {
   
  var _x0 = t.thd;
  var x_10155 = f(_x0);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(_y_x10104 /* 385 */ ) {
      return $std_core_types.Tuple3(_y_x10102, _y_x10103, _y_x10104);
    });
  }
  else {
    return $std_core_types.Tuple3(_y_x10102, _y_x10103, x_10155);
  }
}
 
 
// monadic lift
export function tuple3_fs__mlift_map_10133(f, t, _y_x10102) /* forall<a,b,e> (f : (a) -> e b, t : (a, a, a), b) -> e (b, b, b) */  {
   
  var _x0 = t.snd;
  var x_10160 = f(_x0);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(_y_x10103 /* 385 */ ) {
      return tuple3_fs__mlift_map_10132(_y_x10102, f, t, _y_x10103);
    });
  }
  else {
    return tuple3_fs__mlift_map_10132(_y_x10102, f, t, x_10160);
  }
}
 
 
// Map a function over a triple of elements of the same type.
export function tuple3_fs_map(t, f) /* forall<a,b,e> (t : (a, a, a), f : (a) -> e b) -> e (b, b, b) */  {
   
  var _x0 = t.fst;
  var x_10162 = f(_x0);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(_y_x10102 /* 385 */ ) {
      return tuple3_fs__mlift_map_10133(f, t, _y_x10102);
    });
  }
  else {
     
    var _x0 = t.snd;
    var x_0_10165 = f(_x0);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10103 /* 385 */ ) {
        return tuple3_fs__mlift_map_10132(x_10162, f, t, _y_x10103);
      });
    }
    else {
       
      var _x0 = t.thd;
      var x_1_10168 = f(_x0);
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(_y_x10104 /* 385 */ ) {
          return $std_core_types.Tuple3(x_10162, x_0_10165, _y_x10104);
        });
      }
      else {
        return $std_core_types.Tuple3(x_10162, x_0_10165, x_1_10168);
      }
    }
  }
}
 
 
// monadic lift
export function tuple4_fs__mlift_map_10134(_y_x10105, _y_x10106, _y_x10107, _y_x10108) /* forall<a,e> (a, a, a, a) -> e (a, a, a, a) */  {
  return $std_core_types.Tuple4(_y_x10105, _y_x10106, _y_x10107, _y_x10108);
}
 
 
// monadic lift
export function tuple4_fs__mlift_map_10135(_y_x10105, _y_x10106, f, t, _y_x10107) /* forall<a,b,e> (b, b, f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */  {
   
  var _x0 = t.field4;
  var x_10174 = f(_x0);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(_y_x10108 /* 572 */ ) {
      return $std_core_types.Tuple4(_y_x10105, _y_x10106, _y_x10107, _y_x10108);
    });
  }
  else {
    return $std_core_types.Tuple4(_y_x10105, _y_x10106, _y_x10107, x_10174);
  }
}
 
 
// monadic lift
export function tuple4_fs__mlift_map_10136(_y_x10105, f, t, _y_x10106) /* forall<a,b,e> (b, f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */  {
   
  var _x0 = t.thd;
  var x_10180 = f(_x0);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(_y_x10107 /* 572 */ ) {
      return tuple4_fs__mlift_map_10135(_y_x10105, _y_x10106, f, t, _y_x10107);
    });
  }
  else {
    return tuple4_fs__mlift_map_10135(_y_x10105, _y_x10106, f, t, x_10180);
  }
}
 
 
// monadic lift
export function tuple4_fs__mlift_map_10137(f, t, _y_x10105) /* forall<a,b,e> (f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */  {
   
  var _x0 = t.snd;
  var x_10182 = f(_x0);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(_y_x10106 /* 572 */ ) {
      return tuple4_fs__mlift_map_10136(_y_x10105, f, t, _y_x10106);
    });
  }
  else {
    return tuple4_fs__mlift_map_10136(_y_x10105, f, t, x_10182);
  }
}
 
 
// Map a function over a quadruple of elements of the same type.
export function tuple4_fs_map(t, f) /* forall<a,b,e> (t : (a, a, a, a), f : (a) -> e b) -> e (b, b, b, b) */  {
   
  var _x0 = t.fst;
  var x_10184 = f(_x0);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(_y_x10105 /* 572 */ ) {
      return tuple4_fs__mlift_map_10137(f, t, _y_x10105);
    });
  }
  else {
     
    var _x0 = t.snd;
    var x_0_10187 = f(_x0);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10106 /* 572 */ ) {
        return tuple4_fs__mlift_map_10136(x_10184, f, t, _y_x10106);
      });
    }
    else {
       
      var _x0 = t.thd;
      var x_1_10190 = f(_x0);
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(_y_x10107 /* 572 */ ) {
          return tuple4_fs__mlift_map_10135(x_10184, x_0_10187, f, t, _y_x10107);
        });
      }
      else {
         
        var _x0 = t.field4;
        var x_2_10193 = f(_x0);
        if ($std_core_hnd._yielding()) {
          return $std_core_hnd.yield_extend(function(_y_x10108 /* 572 */ ) {
            return $std_core_types.Tuple4(x_10184, x_0_10187, x_1_10190, _y_x10108);
          });
        }
        else {
          return $std_core_types.Tuple4(x_10184, x_0_10187, x_1_10190, x_2_10193);
        }
      }
    }
  }
}
 
 
// Element-wise tuple equality
export function tuple2_fs__lp__eq__eq__rp_(_pat_x29__22, _pat_x29__39, _implicit_fs_fst_fs__lp__eq__eq__rp_, _implicit_fs_snd_fs__lp__eq__eq__rp_) /* forall<a,b> ((a, b), (a, b), ?fst/(==) : (a, a) -> bool, ?snd/(==) : (b, b) -> bool) -> bool */  {
  var _x0 = _implicit_fs_fst_fs__lp__eq__eq__rp_(_pat_x29__22.fst, _pat_x29__39.fst);
  if (_x0) {
    return _implicit_fs_snd_fs__lp__eq__eq__rp_(_pat_x29__22.snd, _pat_x29__39.snd);
  }
  else {
    return false;
  }
}
 
 
// Element-wise triple equality
export function tuple3_fs__lp__eq__eq__rp_(_pat_x33__22, _pat_x33__44, _implicit_fs_fst_fs__lp__eq__eq__rp_, _implicit_fs_snd_fs__lp__eq__eq__rp_, _implicit_fs_thd_fs__lp__eq__eq__rp_) /* forall<a,b,c> ((a, b, c), (a, b, c), ?fst/(==) : (a, a) -> bool, ?snd/(==) : (b, b) -> bool, ?thd/(==) : (c, c) -> bool) -> bool */  {
  var _x1 = _implicit_fs_fst_fs__lp__eq__eq__rp_(_pat_x33__22.fst, _pat_x33__44.fst);
  if (_x1) {
    var _x2 = _implicit_fs_snd_fs__lp__eq__eq__rp_(_pat_x33__22.snd, _pat_x33__44.snd);
    if (_x2) {
      return _implicit_fs_thd_fs__lp__eq__eq__rp_(_pat_x33__22.thd, _pat_x33__44.thd);
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}
 
 
// Order on tuples
export function tuple2_fs_cmp(_pat_x38__21, _pat_x38__38, _implicit_fs_fst_fs_cmp, _implicit_fs_snd_fs_cmp) /* forall<a,b> ((a, b), (a, b), ?fst/cmp : (a, a) -> order, ?snd/cmp : (b, b) -> order) -> order */  {
  var _x3 = _implicit_fs_fst_fs_cmp(_pat_x38__21.fst, _pat_x38__38.fst);
  if (_x3 === 2) {
    return _implicit_fs_snd_fs_cmp(_pat_x38__21.snd, _pat_x38__38.snd);
  }
  else {
    return _x3;
  }
}
 
 
// Order on triples
export function tuple3_fs_cmp(_pat_x44__26, _pat_x44__48, _implicit_fs_fst_fs_cmp, _implicit_fs_snd_fs_cmp, _implicit_fs_thd_fs_cmp) /* forall<a,b,c> ((a, b, c), (a, b, c), ?fst/cmp : (a, a) -> order, ?snd/cmp : (b, b) -> order, ?thd/cmp : (c, c) -> order) -> order */  {
  var _x4 = _implicit_fs_fst_fs_cmp(_pat_x44__26.fst, _pat_x44__48.fst);
  if (_x4 === 2) {
    var _x5 = _implicit_fs_snd_fs_cmp(_pat_x44__26.snd, _pat_x44__48.snd);
    if (_x5 === 2) {
      return _implicit_fs_thd_fs_cmp(_pat_x44__26.thd, _pat_x44__48.thd);
    }
    else {
      return _x5;
    }
  }
  else {
    return _x4;
  }
}
 
 
// Convert a unit value `()` to a string
export function unit_fs_show(u) /* (u : ()) -> string */  {
  return "()";
}
 
 
// monadic lift
export function tuple2_fs__mlift_show_10138(_y_x10109, _y_x10110) /* forall<e> (string, string) -> e string */  {
  return $std_core_types._lp__plus__plus__rp_("(", $std_core_types._lp__plus__plus__rp_(_y_x10109, $std_core_types._lp__plus__plus__rp_(",", $std_core_types._lp__plus__plus__rp_(_y_x10110, ")"))));
}
 
 
// monadic lift
export function tuple2_fs__mlift_show_10139(x, _implicit_fs_snd_fs_show, _y_x10109) /* forall<a,b,e> (x : (a, b), ?snd/show : (b) -> e string, string) -> e string */  {
   
  var _x6 = x.snd;
  var x_0_10200 = _implicit_fs_snd_fs_show(_x6);
   
  function next_10201(_y_x10110) /* (string) -> 1018 string */  {
    return $std_core_types._lp__plus__plus__rp_("(", $std_core_types._lp__plus__plus__rp_(_y_x10109, $std_core_types._lp__plus__plus__rp_(",", $std_core_types._lp__plus__plus__rp_(_y_x10110, ")"))));
  }
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(next_10201);
  }
  else {
    return next_10201(x_0_10200);
  }
}
 
 
// Show a tuple
export function tuple2_fs_show(x, _implicit_fs_fst_fs_show, _implicit_fs_snd_fs_show) /* forall<a,b,e> (x : (a, b), ?fst/show : (a) -> e string, ?snd/show : (b) -> e string) -> e string */  {
   
  var _x6 = x.fst;
  var x_0_10204 = _implicit_fs_fst_fs_show(_x6);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(_y_x10109 /* string */ ) {
      return tuple2_fs__mlift_show_10139(x, _implicit_fs_snd_fs_show, _y_x10109);
    });
  }
  else {
     
    var _x6 = x.snd;
    var x_1_10207 = _implicit_fs_snd_fs_show(_x6);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10110 /* string */ ) {
        return $std_core_types._lp__plus__plus__rp_("(", $std_core_types._lp__plus__plus__rp_(x_0_10204, $std_core_types._lp__plus__plus__rp_(",", $std_core_types._lp__plus__plus__rp_(_y_x10110, ")"))));
      });
    }
    else {
      return $std_core_types._lp__plus__plus__rp_("(", $std_core_types._lp__plus__plus__rp_(x_0_10204, $std_core_types._lp__plus__plus__rp_(",", $std_core_types._lp__plus__plus__rp_(x_1_10207, ")"))));
    }
  }
}
 
 
// monadic lift
export function tuple3_fs__mlift_show_10140(_y_x10111, _y_x10112, _y_x10113) /* forall<e> (string, string, string) -> e string */  {
  return $std_core_types._lp__plus__plus__rp_("(", $std_core_types._lp__plus__plus__rp_(_y_x10111, $std_core_types._lp__plus__plus__rp_(",", $std_core_types._lp__plus__plus__rp_(_y_x10112, $std_core_types._lp__plus__plus__rp_(",", $std_core_types._lp__plus__plus__rp_(_y_x10113, ")"))))));
}
 
 
// monadic lift
export function tuple3_fs__mlift_show_10141(_y_x10111, x, _implicit_fs_thd_fs_show, _y_x10112) /* forall<a,b,c,e> (string, x : (a, b, c), ?thd/show : (c) -> e string, string) -> e string */  {
   
  var _x6 = x.thd;
  var x_0_10212 = _implicit_fs_thd_fs_show(_x6);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(_y_x10113 /* string */ ) {
      return tuple3_fs__mlift_show_10140(_y_x10111, _y_x10112, _y_x10113);
    });
  }
  else {
    return tuple3_fs__mlift_show_10140(_y_x10111, _y_x10112, x_0_10212);
  }
}
 
 
// monadic lift
export function tuple3_fs__mlift_show_10142(x, _implicit_fs_snd_fs_show, _implicit_fs_thd_fs_show, _y_x10111) /* forall<a,b,c,e> (x : (a, b, c), ?snd/show : (b) -> e string, ?thd/show : (c) -> e string, string) -> e string */  {
   
  var _x6 = x.snd;
  var x_0_10214 = _implicit_fs_snd_fs_show(_x6);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(_y_x10112 /* string */ ) {
      return tuple3_fs__mlift_show_10141(_y_x10111, x, _implicit_fs_thd_fs_show, _y_x10112);
    });
  }
  else {
    return tuple3_fs__mlift_show_10141(_y_x10111, x, _implicit_fs_thd_fs_show, x_0_10214);
  }
}
 
 
// Show a triple
export function tuple3_fs_show(x, _implicit_fs_fst_fs_show, _implicit_fs_snd_fs_show, _implicit_fs_thd_fs_show) /* forall<a,b,c,e> (x : (a, b, c), ?fst/show : (a) -> e string, ?snd/show : (b) -> e string, ?thd/show : (c) -> e string) -> e string */  {
   
  var _x6 = x.fst;
  var x_0_10216 = _implicit_fs_fst_fs_show(_x6);
  if ($std_core_hnd._yielding()) {
    return $std_core_hnd.yield_extend(function(_y_x10111 /* string */ ) {
      return tuple3_fs__mlift_show_10142(x, _implicit_fs_snd_fs_show, _implicit_fs_thd_fs_show, _y_x10111);
    });
  }
  else {
     
    var _x6 = x.snd;
    var x_1_10219 = _implicit_fs_snd_fs_show(_x6);
    if ($std_core_hnd._yielding()) {
      return $std_core_hnd.yield_extend(function(_y_x10112 /* string */ ) {
        return tuple3_fs__mlift_show_10141(x_0_10216, x, _implicit_fs_thd_fs_show, _y_x10112);
      });
    }
    else {
       
      var _x6 = x.thd;
      var x_2_10222 = _implicit_fs_thd_fs_show(_x6);
      if ($std_core_hnd._yielding()) {
        return $std_core_hnd.yield_extend(function(_y_x10113 /* string */ ) {
          return tuple3_fs__mlift_show_10140(x_0_10216, x_1_10219, _y_x10113);
        });
      }
      else {
        return $std_core_types._lp__plus__plus__rp_("(", $std_core_types._lp__plus__plus__rp_(x_0_10216, $std_core_types._lp__plus__plus__rp_(",", $std_core_types._lp__plus__plus__rp_(x_1_10219, $std_core_types._lp__plus__plus__rp_(",", $std_core_types._lp__plus__plus__rp_(x_2_10222, ")"))))));
      }
    }
  }
}
 
 
// _deprecated_, use `tuple2/show` instead
export function show_tuple(x, showfst, showsnd) /* forall<a,b,e> (x : (a, b), showfst : (a) -> e string, showsnd : (b) -> e string) -> e string */  {
  return tuple2_fs_show(x, showfst, showsnd);
}