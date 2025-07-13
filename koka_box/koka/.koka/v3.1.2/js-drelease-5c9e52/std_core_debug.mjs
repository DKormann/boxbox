// Koka generated module: std/core/debug, koka version: 3.1.2
"use strict";
 
// imports
import * as $std_core_types from './std_core_types.mjs';
import * as $std_core_unsafe from './std_core_unsafe.mjs';
import * as $std_core_hnd from './std_core_hnd.mjs';
import * as $std_core_string from './std_core_string.mjs';
import * as $std_core_console from './std_core_console.mjs';
 
// externals
 
// type declarations
 
// declarations
 
 
// Compilation constant that is replaced with the current file's module name
export var file_fs_kk_module;
var file_fs_kk_module = "";
 
 
// Compilation constant that is replaced with the current line number
export var file_fs_kk_line;
var file_fs_kk_line = "";
 
 
// Compilation constant that is replaced with the current file name
export var file_fs_kk_file;
var file_fs_kk_file = "";
 
export function file_fs_kk_file_line(_implicit_fs_kk_file, _implicit_fs_kk_line) /* (?kk-file : string, ?kk-line : string) -> string */  {
  return $std_core_types._lp__plus__plus__rp_(_implicit_fs_kk_file, $std_core_types._lp__plus__plus__rp_("(", $std_core_types._lp__plus__plus__rp_(_implicit_fs_kk_line, ")")));
}
 
export function xtrace(message) /* (message : string) -> () */  {
  return $std_core_console._trace(message);
}
 
export function xtrace_any(message, x) /* forall<a> (message : string, x : a) -> () */  {
  return $std_core_console._trace_any(message,x);
}
 
export var trace_enabled;
var trace_enabled = { value: true };
 
 
// Trace a message used for debug purposes.
// The behaviour is system dependent. On a browser and node it uses
// `console.log`  by default.
// Disabled if `notrace` is called.
export function trace(message) /* (message : string) -> () */  {
  var _x0 = trace_enabled.value;
  if (_x0) {
    return xtrace(message);
  }
  else {
    return $std_core_types.Unit;
  }
}
 
export function trace_info(message, _implicit_fs_kk_file_line) /* (message : string, ?kk-file-line : string) -> () */  {
   
  var message_0_10002 = $std_core_types._lp__plus__plus__rp_(_implicit_fs_kk_file_line, $std_core_types._lp__plus__plus__rp_(": ", message));
  var _x1 = trace_enabled.value;
  if (_x1) {
    return xtrace(message_0_10002);
  }
  else {
    return $std_core_types.Unit;
  }
}
 
export function trace_show(x, _implicit_fs_show, _implicit_fs_kk_file_line) /* forall<a> (x : a, ?show : (a) -> string, ?kk-file-line : string) -> () */  {
   
  var message_10006 = _implicit_fs_show(x);
   
  var message_0_10002 = $std_core_types._lp__plus__plus__rp_(_implicit_fs_kk_file_line, $std_core_types._lp__plus__plus__rp_(": ", message_10006));
  var _x2 = trace_enabled.value;
  if (_x2) {
    return xtrace(message_0_10002);
  }
  else {
    return $std_core_types.Unit;
  }
}
 
export function trace_any(message, x) /* forall<a> (message : string, x : a) -> () */  {
  var _x3 = trace_enabled.value;
  if (_x3) {
    return xtrace_any(message, x);
  }
  else {
    return $std_core_types.Unit;
  }
}
 
 
// Disable tracing completely.
export function notrace() /* () -> (st<global>) () */  {
  return ((trace_enabled).value = false);
}
 
export function unsafe_assert_fail(msg) /* (msg : string) -> () */  {
  return function() { throw new Error("assertion failed: " + msg) }();
}
 
export function assert(message, condition, _implicit_fs_kk_file_line) /* (message : string, condition : bool, ?kk-file-line : string) -> () */  {
  if (condition) {
    return $std_core_types.Unit;
  }
  else {
    return unsafe_assert_fail($std_core_types._lp__plus__plus__rp_(_implicit_fs_kk_file_line, $std_core_types._lp__plus__plus__rp_(": ", message)));
  }
}
 
 
// Explicitly trigger a breakpoint
export function breakpoint() /* () -> ndet () */  {
  return (function(){ debugger; })();
}