// Koka generated module: std/core/show, koka version: 3.1.2
"use strict";
 
// imports
import * as $std_core_types from './std_core_types.mjs';
import * as $std_core_hnd from './std_core_hnd.mjs';
import * as $std_core_int from './std_core_int.mjs';
import * as $std_core_char from './std_core_char.mjs';
import * as $std_core_string from './std_core_string.mjs';
import * as $std_core_sslice from './std_core_sslice.mjs';
import * as $std_core_list from './std_core_list.mjs';
 
// externals
 
// type declarations
 
// declarations
 
 
// Generic show: shows the internal representation of an object as a string
// Note: this breaks parametricity so it should not be public
export function gshow(_arg_x1) /* forall<a> (a) -> string */  {
  return _arg_x1.toString();
}
 
export function int_show_hex(i, use_capitals) /* (i : int, use-capitals : bool) -> string */  {
  return $std_core_types._int_showhex(i,use_capitals);
}
 
 
// Show an `:int` as a hexadecimal value.\
// The `width`  parameter specifies how wide the hex value is where `"0"`  is used to align.\
// The `use-capitals` parameter (= `True`) determines if captical letters should be used to display the hexadecimal digits.\
// The `pre` (=`"0x"`) is an optional prefix for the number (goes between the sign and the number).
export function show_hex(i, width, use_capitals, pre) /* (i : int, width : ? int, use-capitals : ? bool, pre : ? string) -> string */  {
   
  var _x0 = (use_capitals !== undefined) ? use_capitals : true;
  var s_10000 = int_show_hex($std_core_types._int_abs(i), _x0);
   
  var n = $std_core_string.count(s_10000);
  var _x0 = ($std_core_types._int_lt(i,0)) ? "-" : "";
  var _x1 = (pre !== undefined) ? pre : "0x";
  var _x4 = (width !== undefined) ? width : 1;
  var _x3 = $std_core_types._int_le(_x4,n);
  if (_x3) {
    var _x2 = s_10000;
  }
  else {
     
    var s_0_10011 = $std_core_string.char_fs_string(0x0030);
     
    var _x5 = (width !== undefined) ? width : 1;
    var n_0_10012 = $std_core_types._int_sub(_x5,n);
    var _x2 = $std_core_types._lp__plus__plus__rp_($std_core_string.repeatz(s_0_10011, $std_core_int.ssize__t(n_0_10012)), s_10000);
  }
  return $std_core_types._lp__plus__plus__rp_(_x0, $std_core_types._lp__plus__plus__rp_(_x1, _x2));
}
 
 
// Show a character as a string
export function show_char(c) /* (c : char) -> string */  {
  if ((c < 0x0020)) {
    if ((c === 0x000A)) {
      return "\\n";
    }
    else {
      if ((c === 0x000D)) {
        return "\\r";
      }
      else {
        if ((c === 0x0009)) {
          return "\\t";
        }
        else {
          var _x5 = $std_core_types._int_le(c,255);
          if (_x5) {
             
            var _arg_x229 = c;
             
            var _x7 = undefined;
            var _x6 = (_x7 !== undefined) ? _x7 : true;
            var s_10007 = int_show_hex($std_core_types._int_abs(_arg_x229), _x6);
             
            var n = $std_core_string.count(s_10007);
            var _x6 = ($std_core_types._int_lt(_arg_x229,0)) ? "-" : "";
            if ($std_core_types._int_le(2,n)) {
              var _x7 = s_10007;
            }
            else {
               
              var s_0_10011 = $std_core_string.char_fs_string(0x0030);
               
              var n_0_10012 = $std_core_types._int_sub(2,n);
              var _x7 = $std_core_types._lp__plus__plus__rp_($std_core_string.repeatz(s_0_10011, $std_core_int.ssize__t(n_0_10012)), s_10007);
            }
            return $std_core_types._lp__plus__plus__rp_("\\x", $std_core_types._lp__plus__plus__rp_(_x6, $std_core_types._lp__plus__plus__rp_("", _x7)));
          }
          else {
            var _x8 = $std_core_types._int_le(c,65535);
            if (_x8) {
               
              var _arg_x281 = c;
               
              var _x10 = undefined;
              var _x9 = (_x10 !== undefined) ? _x10 : true;
              var s_0_10014 = int_show_hex($std_core_types._int_abs(_arg_x281), _x9);
               
              var n_0 = $std_core_string.count(s_0_10014);
              var _x9 = ($std_core_types._int_lt(_arg_x281,0)) ? "-" : "";
              if ($std_core_types._int_le(4,n_0)) {
                var _x10 = s_0_10014;
              }
              else {
                 
                var s_0_10011_0 = $std_core_string.char_fs_string(0x0030);
                 
                var n_0_10012_0 = $std_core_types._int_sub(4,n_0);
                var _x10 = $std_core_types._lp__plus__plus__rp_($std_core_string.repeatz(s_0_10011_0, $std_core_int.ssize__t(n_0_10012_0)), s_0_10014);
              }
              return $std_core_types._lp__plus__plus__rp_("\\u", $std_core_types._lp__plus__plus__rp_(_x9, $std_core_types._lp__plus__plus__rp_("", _x10)));
            }
            else {
               
              var _arg_x323 = c;
               
              var _x12 = undefined;
              var _x11 = (_x12 !== undefined) ? _x12 : true;
              var s_1_10021 = int_show_hex($std_core_types._int_abs(_arg_x323), _x11);
               
              var n_1 = $std_core_string.count(s_1_10021);
              var _x11 = ($std_core_types._int_lt(_arg_x323,0)) ? "-" : "";
              if ($std_core_types._int_le(6,n_1)) {
                var _x12 = s_1_10021;
              }
              else {
                 
                var s_0_10011_1 = $std_core_string.char_fs_string(0x0030);
                 
                var n_0_10012_1 = $std_core_types._int_sub(6,n_1);
                var _x12 = $std_core_types._lp__plus__plus__rp_($std_core_string.repeatz(s_0_10011_1, $std_core_int.ssize__t(n_0_10012_1)), s_1_10021);
              }
              return $std_core_types._lp__plus__plus__rp_("\\U", $std_core_types._lp__plus__plus__rp_(_x11, $std_core_types._lp__plus__plus__rp_("", _x12)));
            }
          }
        }
      }
    }
  }
  else {
    if ((c > 0x007E)) {
      if ((c === 0x000A)) {
        return "\\n";
      }
      else {
        if ((c === 0x000D)) {
          return "\\r";
        }
        else {
          if ((c === 0x0009)) {
            return "\\t";
          }
          else {
            var _x13 = $std_core_types._int_le(c,255);
            if (_x13) {
               
              var _arg_x229_0 = c;
               
              var _x15 = undefined;
              var _x14 = (_x15 !== undefined) ? _x15 : true;
              var s_2_10028 = int_show_hex($std_core_types._int_abs(_arg_x229_0), _x14);
               
              var n_2 = $std_core_string.count(s_2_10028);
              var _x14 = ($std_core_types._int_lt(_arg_x229_0,0)) ? "-" : "";
              if ($std_core_types._int_le(2,n_2)) {
                var _x15 = s_2_10028;
              }
              else {
                 
                var s_0_10011_2 = $std_core_string.char_fs_string(0x0030);
                 
                var n_0_10012_2 = $std_core_types._int_sub(2,n_2);
                var _x15 = $std_core_types._lp__plus__plus__rp_($std_core_string.repeatz(s_0_10011_2, $std_core_int.ssize__t(n_0_10012_2)), s_2_10028);
              }
              return $std_core_types._lp__plus__plus__rp_("\\x", $std_core_types._lp__plus__plus__rp_(_x14, $std_core_types._lp__plus__plus__rp_("", _x15)));
            }
            else {
              var _x16 = $std_core_types._int_le(c,65535);
              if (_x16) {
                 
                var _arg_x281_0 = c;
                 
                var _x18 = undefined;
                var _x17 = (_x18 !== undefined) ? _x18 : true;
                var s_3_10035 = int_show_hex($std_core_types._int_abs(_arg_x281_0), _x17);
                 
                var n_3 = $std_core_string.count(s_3_10035);
                var _x17 = ($std_core_types._int_lt(_arg_x281_0,0)) ? "-" : "";
                if ($std_core_types._int_le(4,n_3)) {
                  var _x18 = s_3_10035;
                }
                else {
                   
                  var s_0_10011_3 = $std_core_string.char_fs_string(0x0030);
                   
                  var n_0_10012_3 = $std_core_types._int_sub(4,n_3);
                  var _x18 = $std_core_types._lp__plus__plus__rp_($std_core_string.repeatz(s_0_10011_3, $std_core_int.ssize__t(n_0_10012_3)), s_3_10035);
                }
                return $std_core_types._lp__plus__plus__rp_("\\u", $std_core_types._lp__plus__plus__rp_(_x17, $std_core_types._lp__plus__plus__rp_("", _x18)));
              }
              else {
                 
                var _arg_x323_0 = c;
                 
                var _x20 = undefined;
                var _x19 = (_x20 !== undefined) ? _x20 : true;
                var s_4_10042 = int_show_hex($std_core_types._int_abs(_arg_x323_0), _x19);
                 
                var n_4 = $std_core_string.count(s_4_10042);
                var _x19 = ($std_core_types._int_lt(_arg_x323_0,0)) ? "-" : "";
                if ($std_core_types._int_le(6,n_4)) {
                  var _x20 = s_4_10042;
                }
                else {
                   
                  var s_0_10011_4 = $std_core_string.char_fs_string(0x0030);
                   
                  var n_0_10012_4 = $std_core_types._int_sub(6,n_4);
                  var _x20 = $std_core_types._lp__plus__plus__rp_($std_core_string.repeatz(s_0_10011_4, $std_core_int.ssize__t(n_0_10012_4)), s_4_10042);
                }
                return $std_core_types._lp__plus__plus__rp_("\\U", $std_core_types._lp__plus__plus__rp_(_x19, $std_core_types._lp__plus__plus__rp_("", _x20)));
              }
            }
          }
        }
      }
    }
    else {
      if ((c === 0x0027)) {
        return "\\\'";
      }
      else {
        if ((c === 0x0022)) {
          return "\\\"";
        }
        else {
          if ((c === 0x005C)) {
            return "\\\\";
          }
          else {
            return $std_core_string.char_fs_string(c);
          }
        }
      }
    }
  }
}
 
 
// Show a `:char` as a character literal
export function char_fs_show(c) /* (c : char) -> string */  {
  return $std_core_types._lp__plus__plus__rp_("\'", $std_core_types._lp__plus__plus__rp_(show_char(c), "\'"));
}
 
 
// lifted local: string/@lift-show@10158, string/show, @spec-x10157
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10152, using:
// @uniq-f@10152 = std/core/show/show-char
export function string_fs__trmc_lift_show_10159(_uniq_xs_10151, _acc) /* (list<char>, ctx<list<string>>) -> list<string> */  { tailcall: while(1)
{
  if (_uniq_xs_10151 !== null) {
     
    var _trmc_x10160 = show_char(_uniq_xs_10151.head);
     
    var _trmc_x10161 = undefined;
     
    var _trmc_x10162 = $std_core_types.Cons(_trmc_x10160, _trmc_x10161);
    {
      // tail call
      var _x21 = $std_core_types._cctx_extend(_acc,_trmc_x10162,({obj: _trmc_x10162, field_name: "tail"}));
      _uniq_xs_10151 = _uniq_xs_10151.tail;
      _acc = _x21;
      continue tailcall;
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
  }
}}
 
 
// lifted local: string/@lift-show@10158, string/show, @spec-x10157
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10152, using:
// @uniq-f@10152 = std/core/show/show-char
export function string_fs__lift_show_10159(_uniq_xs_10151_0) /* (list<char>) -> list<string> */  {
  return string_fs__trmc_lift_show_10159(_uniq_xs_10151_0, $std_core_types._cctx_empty());
}
 
 
// lifted local: string/show, @spec-x10150
// specialized: std/core/list/map, on parameters @uniq-f@10147, using:
// @uniq-f@10147 = std/core/show/show-char
export function string_fs__lift_show_10158(_uniq_xs_10146) /* (list<char>) -> list<string> */  {
  if (_uniq_xs_10146 === null) {
    return $std_core_types.Nil;
  }
  else {
    return string_fs__lift_show_10159(_uniq_xs_10146);
  }
}
 
 
// Show a string as a string literal
export function string_fs_show(s) /* (s : string) -> string */  {
   
  var xs_10045 = string_fs__lift_show_10158($std_core_string.list(s));
  if (xs_10045 === null) {
    var _x22 = "";
  }
  else if (xs_10045 !== null && xs_10045.tail === null) {
    var _x22 = xs_10045.head;
  }
  else if (xs_10045 !== null && xs_10045.tail !== null && xs_10045.tail.tail === null) {
    var _x22 = $std_core_types._lp__plus__plus__rp_(xs_10045.head, xs_10045.tail.head);
  }
  else {
    var _x22 = ((($std_core_vector.unvlist(xs_10045))).join(''));
  }
  return $std_core_types._lp__plus__plus__rp_("\"", $std_core_types._lp__plus__plus__rp_(_x22, "\""));
}
 
 
// Show an `:sslice` as a string literal
export function sslice_fs_show(s) /* (s : sslice/sslice) -> string */  {
  return string_fs_show($std_core_sslice.string(s));
}