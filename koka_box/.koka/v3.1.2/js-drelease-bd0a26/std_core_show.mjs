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
  var _x0 = ($std_core_types._int_lt(i,0)) ? "-" : "";
  var _x1 = (pre !== undefined) ? pre : "0x";
  var _x2 = (use_capitals !== undefined) ? use_capitals : true;
  var _x3 = (width !== undefined) ? width : 1;
  return $std_core_types._lp__plus__plus__rp_(_x0, $std_core_types._lp__plus__plus__rp_(_x1, $std_core_string.pad_left(int_show_hex($std_core_types._int_abs(i), _x2), _x3, 0x0030)));
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
          var _x4 = $std_core_types._int_le(c,255);
          if (_x4) {
             
            var _arg_x229 = c;
            return $std_core_types._lp__plus__plus__rp_("\\x", show_hex(_arg_x229, 2, undefined, ""));
          }
          else {
            var _x5 = $std_core_types._int_le(c,65535);
            if (_x5) {
               
              var _arg_x281 = c;
              return $std_core_types._lp__plus__plus__rp_("\\u", show_hex(_arg_x281, 4, undefined, ""));
            }
            else {
               
              var _arg_x323 = c;
              return $std_core_types._lp__plus__plus__rp_("\\U", show_hex(_arg_x323, 6, undefined, ""));
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
            var _x6 = $std_core_types._int_le(c,255);
            if (_x6) {
               
              var _arg_x229_0 = c;
              return $std_core_types._lp__plus__plus__rp_("\\x", show_hex(_arg_x229_0, 2, undefined, ""));
            }
            else {
              var _x7 = $std_core_types._int_le(c,65535);
              if (_x7) {
                 
                var _arg_x281_0 = c;
                return $std_core_types._lp__plus__plus__rp_("\\u", show_hex(_arg_x281_0, 4, undefined, ""));
              }
              else {
                 
                var _arg_x323_0 = c;
                return $std_core_types._lp__plus__plus__rp_("\\U", show_hex(_arg_x323_0, 6, undefined, ""));
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
 
 
// lifted local: string/@lift-show@10112, string/show, @spec-x10111
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10106, using:
// @uniq-f@10106 = std/core/show/show-char
export function string_fs__trmc_lift_show_10113(_uniq_xs_10105, _acc) /* (list<char>, ctx<list<string>>) -> list<string> */  { tailcall: while(1)
{
  if (_uniq_xs_10105 !== null) {
     
    var _trmc_x10114 = show_char(_uniq_xs_10105.head);
     
    var _trmc_x10115 = undefined;
     
    var _trmc_x10116 = $std_core_types.Cons(_trmc_x10114, _trmc_x10115);
    {
      // tail call
      var _x8 = $std_core_types._cctx_extend(_acc,_trmc_x10116,({obj: _trmc_x10116, field_name: "tail"}));
      _uniq_xs_10105 = _uniq_xs_10105.tail;
      _acc = _x8;
      continue tailcall;
    }
  }
  else {
    return $std_core_types._cctx_apply(_acc,($std_core_types.Nil));
  }
}}
 
 
// lifted local: string/@lift-show@10112, string/show, @spec-x10111
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10106, using:
// @uniq-f@10106 = std/core/show/show-char
export function string_fs__lift_show_10113(_uniq_xs_10105_0) /* (list<char>) -> list<string> */  {
  return string_fs__trmc_lift_show_10113(_uniq_xs_10105_0, $std_core_types._cctx_empty());
}
 
 
// lifted local: string/show, @spec-x10104
// specialized: std/core/list/map, on parameters @uniq-f@10101, using:
// @uniq-f@10101 = std/core/show/show-char
export function string_fs__lift_show_10112(_uniq_xs_10100) /* (list<char>) -> list<string> */  {
  if (_uniq_xs_10100 === null) {
    return $std_core_types.Nil;
  }
  else {
    return string_fs__lift_show_10113(_uniq_xs_10100);
  }
}
 
 
// Show a string as a string literal
export function string_fs_show(s) /* (s : string) -> string */  {
  return $std_core_types._lp__plus__plus__rp_("\"", $std_core_types._lp__plus__plus__rp_($std_core_list.join(string_fs__lift_show_10112($std_core_string.list(s))), "\""));
}
 
 
// Show an `:sslice` as a string literal
export function sslice_fs_show(s) /* (s : sslice/sslice) -> string */  {
  return string_fs_show($std_core_sslice.string(s));
}