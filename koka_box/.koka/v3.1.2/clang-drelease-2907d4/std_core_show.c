// Koka generated module: std/core/show, koka version: 3.1.2, platform: 64-bit
#include "std_core_show.h"
 
// Generic show: shows the internal representation of an object as a string
// Note: this breaks parametricity so it should not be public

kk_string_t kk_std_core_show_gshow(kk_box_t _arg_x1, kk_context_t* _ctx) { /* forall<a> (a) -> string */ 
  return kk_show_any(_arg_x1,kk_context());
}

kk_string_t kk_std_core_show_int_show_hex(kk_integer_t i, bool use_capitals, kk_context_t* _ctx) { /* (i : int, use-capitals : bool) -> string */ 
  return kk_integer_to_hex_string(i,use_capitals,kk_context());
}
 
// Show an `:int` as a hexadecimal value.
// The `width`  parameter specifies how wide the hex value is where `"0"`  is used to align.
// The `use-capitals` parameter (= `True`) determines if captical letters should be used to display the hexadecimal digits.
// The `pre` (=`"0x"`) is an optional prefix for the number (goes between the sign and the number).

kk_string_t kk_std_core_show_show_hex(kk_integer_t i, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx) { /* (i : int, width : ? int, use-capitals : ? bool, pre : ? string) -> string */ 
  kk_string_t s_10000;
  kk_integer_t _x_x92;
  kk_integer_t _x_x93 = kk_integer_dup(i, _ctx); /*int*/
  _x_x92 = kk_integer_abs(_x_x93,kk_context()); /*int*/
  bool _x_x94;
  if (kk_std_core_types__is_Optional(use_capitals, _ctx)) {
    kk_box_t _box_x0 = use_capitals._cons._Optional.value;
    bool _uniq_use_capitals_62 = kk_bool_unbox(_box_x0);
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    _x_x94 = _uniq_use_capitals_62; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    _x_x94 = true; /*bool*/
  }
  s_10000 = kk_std_core_show_int_show_hex(_x_x92, _x_x94, _ctx); /*string*/
  kk_integer_t n;
  kk_string_t _x_x95 = kk_string_dup(s_10000, _ctx); /*string*/
  n = kk_std_core_string_count(_x_x95, _ctx); /*int*/
  kk_string_t _x_x96;
  bool _match_x86;
  bool _brw_x87 = kk_integer_lt_borrow(i,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(i, _ctx);
  _match_x86 = _brw_x87; /*bool*/
  if (_match_x86) {
    kk_define_string_literal(, _s_x97, 1, "-", _ctx)
    _x_x96 = kk_string_dup(_s_x97, _ctx); /*string*/
  }
  else {
    _x_x96 = kk_string_empty(); /*string*/
  }
  kk_string_t _x_x99;
  kk_string_t _x_x100;
  if (kk_std_core_types__is_Optional(pre, _ctx)) {
    kk_box_t _box_x1 = pre._cons._Optional.value;
    kk_string_t _uniq_pre_66 = kk_string_unbox(_box_x1);
    kk_string_dup(_uniq_pre_66, _ctx);
    kk_std_core_types__optional_drop(pre, _ctx);
    _x_x100 = _uniq_pre_66; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(pre, _ctx);
    kk_define_string_literal(, _s_x101, 2, "0x", _ctx)
    _x_x100 = kk_string_dup(_s_x101, _ctx); /*string*/
  }
  kk_string_t _x_x102;
  bool _match_x83;
  kk_integer_t _brw_x84;
  if (kk_std_core_types__is_Optional(width, _ctx)) {
    kk_box_t _box_x2 = width._cons._Optional.value;
    kk_integer_t _uniq_width_58 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_width_58, _ctx);
    _brw_x84 = _uniq_width_58; /*int*/
  }
  else {
    _brw_x84 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x85 = kk_integer_lte_borrow(_brw_x84,n,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x84, _ctx);
  _match_x83 = _brw_x85; /*bool*/
  if (_match_x83) {
    kk_std_core_types__optional_drop(width, _ctx);
    kk_integer_drop(n, _ctx);
    _x_x102 = s_10000; /*string*/
  }
  else {
    kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
    kk_integer_t n_0_10012;
    kk_integer_t _x_x103;
    if (kk_std_core_types__is_Optional(width, _ctx)) {
      kk_box_t _box_x3 = width._cons._Optional.value;
      kk_integer_t _uniq_width_58_0 = kk_integer_unbox(_box_x3, _ctx);
      kk_integer_dup(_uniq_width_58_0, _ctx);
      kk_std_core_types__optional_drop(width, _ctx);
      _x_x103 = _uniq_width_58_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(width, _ctx);
      _x_x103 = kk_integer_from_small(1); /*int*/
    }
    n_0_10012 = kk_integer_sub(_x_x103,n,kk_context()); /*int*/
    kk_string_t _x_x104 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
    _x_x102 = kk_std_core_types__lp__plus__plus__rp_(_x_x104, s_10000, _ctx); /*string*/
  }
  _x_x99 = kk_std_core_types__lp__plus__plus__rp_(_x_x100, _x_x102, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x96, _x_x99, _ctx);
}
 
// Show a character as a string

kk_string_t kk_std_core_show_show_char(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> string */ 
  bool _match_x34 = (c < (' ')); /*bool*/;
  if (_match_x34) {
    bool _match_x61 = (c == 0x000A); /*bool*/;
    if (_match_x61) {
      kk_define_string_literal(, _s_x105, 2, "\\n", _ctx)
      return kk_string_dup(_s_x105, _ctx);
    }
    {
      bool _match_x62 = (c == 0x000D); /*bool*/;
      if (_match_x62) {
        kk_define_string_literal(, _s_x106, 2, "\\r", _ctx)
        return kk_string_dup(_s_x106, _ctx);
      }
      {
        bool _match_x63 = (c == 0x0009); /*bool*/;
        if (_match_x63) {
          kk_define_string_literal(, _s_x107, 2, "\\t", _ctx)
          return kk_string_dup(_s_x107, _ctx);
        }
        {
          bool _match_x64;
          kk_integer_t _brw_x81 = kk_integer_from_int(c,kk_context()); /*int*/;
          bool _brw_x82 = kk_integer_lte_borrow(_brw_x81,(kk_integer_from_small(255)),kk_context()); /*bool*/;
          kk_integer_drop(_brw_x81, _ctx);
          _match_x64 = _brw_x82; /*bool*/
          if (_match_x64) {
            kk_integer_t _arg_x229 = kk_integer_from_int(c,kk_context()); /*int*/;
            kk_string_t s_10007;
            kk_integer_t _x_x108;
            kk_integer_t _x_x109 = kk_integer_dup(_arg_x229, _ctx); /*int*/
            _x_x108 = kk_integer_abs(_x_x109,kk_context()); /*int*/
            bool _x_x110;
            kk_std_core_types__optional _match_x80 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
            if (kk_std_core_types__is_Optional(_match_x80, _ctx)) {
              kk_box_t _box_x4 = _match_x80._cons._Optional.value;
              bool _uniq_use_capitals_62 = kk_bool_unbox(_box_x4);
              kk_std_core_types__optional_drop(_match_x80, _ctx);
              _x_x110 = _uniq_use_capitals_62; /*bool*/
            }
            else {
              kk_std_core_types__optional_drop(_match_x80, _ctx);
              _x_x110 = true; /*bool*/
            }
            s_10007 = kk_std_core_show_int_show_hex(_x_x108, _x_x110, _ctx); /*string*/
            kk_integer_t n;
            kk_string_t _x_x111 = kk_string_dup(s_10007, _ctx); /*string*/
            n = kk_std_core_string_count(_x_x111, _ctx); /*int*/
            kk_string_t _x_x112;
            kk_define_string_literal(, _s_x113, 2, "\\x", _ctx)
            _x_x112 = kk_string_dup(_s_x113, _ctx); /*string*/
            kk_string_t _x_x114;
            kk_string_t _x_x115;
            bool _match_x78;
            bool _brw_x79 = kk_integer_lt_borrow(_arg_x229,(kk_integer_from_small(0)),kk_context()); /*bool*/;
            kk_integer_drop(_arg_x229, _ctx);
            _match_x78 = _brw_x79; /*bool*/
            if (_match_x78) {
              kk_define_string_literal(, _s_x116, 1, "-", _ctx)
              _x_x115 = kk_string_dup(_s_x116, _ctx); /*string*/
            }
            else {
              _x_x115 = kk_string_empty(); /*string*/
            }
            kk_string_t _x_x118;
            kk_string_t _x_x119 = kk_string_empty(); /*string*/
            kk_string_t _x_x121;
            bool _match_x77 = kk_integer_lte_borrow((kk_integer_from_small(2)),n,kk_context()); /*bool*/;
            if (_match_x77) {
              kk_integer_drop(n, _ctx);
              _x_x121 = s_10007; /*string*/
            }
            else {
              kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
              kk_integer_t n_0_10012 = kk_integer_sub((kk_integer_from_small(2)),n,kk_context()); /*int*/;
              kk_string_t _x_x122 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
              _x_x121 = kk_std_core_types__lp__plus__plus__rp_(_x_x122, s_10007, _ctx); /*string*/
            }
            _x_x118 = kk_std_core_types__lp__plus__plus__rp_(_x_x119, _x_x121, _ctx); /*string*/
            _x_x114 = kk_std_core_types__lp__plus__plus__rp_(_x_x115, _x_x118, _ctx); /*string*/
            return kk_std_core_types__lp__plus__plus__rp_(_x_x112, _x_x114, _ctx);
          }
          {
            bool _match_x65;
            kk_integer_t _brw_x75 = kk_integer_from_int(c,kk_context()); /*int*/;
            kk_integer_t _brw_x74 = kk_integer_from_int(65535, _ctx); /*int*/;
            bool _brw_x76 = kk_integer_lte_borrow(_brw_x75,_brw_x74,kk_context()); /*bool*/;
            kk_integer_drop(_brw_x75, _ctx);
            kk_integer_drop(_brw_x74, _ctx);
            _match_x65 = _brw_x76; /*bool*/
            if (_match_x65) {
              kk_integer_t _arg_x281 = kk_integer_from_int(c,kk_context()); /*int*/;
              kk_string_t s_0_10014;
              kk_integer_t _x_x123;
              kk_integer_t _x_x124 = kk_integer_dup(_arg_x281, _ctx); /*int*/
              _x_x123 = kk_integer_abs(_x_x124,kk_context()); /*int*/
              bool _x_x125;
              kk_std_core_types__optional _match_x73 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
              if (kk_std_core_types__is_Optional(_match_x73, _ctx)) {
                kk_box_t _box_x5 = _match_x73._cons._Optional.value;
                bool _uniq_use_capitals_62_0 = kk_bool_unbox(_box_x5);
                kk_std_core_types__optional_drop(_match_x73, _ctx);
                _x_x125 = _uniq_use_capitals_62_0; /*bool*/
              }
              else {
                kk_std_core_types__optional_drop(_match_x73, _ctx);
                _x_x125 = true; /*bool*/
              }
              s_0_10014 = kk_std_core_show_int_show_hex(_x_x123, _x_x125, _ctx); /*string*/
              kk_integer_t n_0;
              kk_string_t _x_x126 = kk_string_dup(s_0_10014, _ctx); /*string*/
              n_0 = kk_std_core_string_count(_x_x126, _ctx); /*int*/
              kk_string_t _x_x127;
              kk_define_string_literal(, _s_x128, 2, "\\u", _ctx)
              _x_x127 = kk_string_dup(_s_x128, _ctx); /*string*/
              kk_string_t _x_x129;
              kk_string_t _x_x130;
              bool _match_x71;
              bool _brw_x72 = kk_integer_lt_borrow(_arg_x281,(kk_integer_from_small(0)),kk_context()); /*bool*/;
              kk_integer_drop(_arg_x281, _ctx);
              _match_x71 = _brw_x72; /*bool*/
              if (_match_x71) {
                kk_define_string_literal(, _s_x131, 1, "-", _ctx)
                _x_x130 = kk_string_dup(_s_x131, _ctx); /*string*/
              }
              else {
                _x_x130 = kk_string_empty(); /*string*/
              }
              kk_string_t _x_x133;
              kk_string_t _x_x134 = kk_string_empty(); /*string*/
              kk_string_t _x_x136;
              bool _match_x70 = kk_integer_lte_borrow((kk_integer_from_small(4)),n_0,kk_context()); /*bool*/;
              if (_match_x70) {
                kk_integer_drop(n_0, _ctx);
                _x_x136 = s_0_10014; /*string*/
              }
              else {
                kk_string_t s_0_10011_0 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
                kk_integer_t n_0_10012_0 = kk_integer_sub((kk_integer_from_small(4)),n_0,kk_context()); /*int*/;
                kk_string_t _x_x137 = kk_std_core_string_repeatz(s_0_10011_0, kk_std_core_int_ssize__t(n_0_10012_0, _ctx), _ctx); /*string*/
                _x_x136 = kk_std_core_types__lp__plus__plus__rp_(_x_x137, s_0_10014, _ctx); /*string*/
              }
              _x_x133 = kk_std_core_types__lp__plus__plus__rp_(_x_x134, _x_x136, _ctx); /*string*/
              _x_x129 = kk_std_core_types__lp__plus__plus__rp_(_x_x130, _x_x133, _ctx); /*string*/
              return kk_std_core_types__lp__plus__plus__rp_(_x_x127, _x_x129, _ctx);
            }
            {
              kk_integer_t _arg_x323 = kk_integer_from_int(c,kk_context()); /*int*/;
              kk_string_t s_1_10021;
              kk_integer_t _x_x138;
              kk_integer_t _x_x139 = kk_integer_dup(_arg_x323, _ctx); /*int*/
              _x_x138 = kk_integer_abs(_x_x139,kk_context()); /*int*/
              bool _x_x140;
              kk_std_core_types__optional _match_x69 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
              if (kk_std_core_types__is_Optional(_match_x69, _ctx)) {
                kk_box_t _box_x6 = _match_x69._cons._Optional.value;
                bool _uniq_use_capitals_62_1 = kk_bool_unbox(_box_x6);
                kk_std_core_types__optional_drop(_match_x69, _ctx);
                _x_x140 = _uniq_use_capitals_62_1; /*bool*/
              }
              else {
                kk_std_core_types__optional_drop(_match_x69, _ctx);
                _x_x140 = true; /*bool*/
              }
              s_1_10021 = kk_std_core_show_int_show_hex(_x_x138, _x_x140, _ctx); /*string*/
              kk_integer_t n_1;
              kk_string_t _x_x141 = kk_string_dup(s_1_10021, _ctx); /*string*/
              n_1 = kk_std_core_string_count(_x_x141, _ctx); /*int*/
              kk_string_t _x_x142;
              kk_define_string_literal(, _s_x143, 2, "\\U", _ctx)
              _x_x142 = kk_string_dup(_s_x143, _ctx); /*string*/
              kk_string_t _x_x144;
              kk_string_t _x_x145;
              bool _match_x67;
              bool _brw_x68 = kk_integer_lt_borrow(_arg_x323,(kk_integer_from_small(0)),kk_context()); /*bool*/;
              kk_integer_drop(_arg_x323, _ctx);
              _match_x67 = _brw_x68; /*bool*/
              if (_match_x67) {
                kk_define_string_literal(, _s_x146, 1, "-", _ctx)
                _x_x145 = kk_string_dup(_s_x146, _ctx); /*string*/
              }
              else {
                _x_x145 = kk_string_empty(); /*string*/
              }
              kk_string_t _x_x148;
              kk_string_t _x_x149 = kk_string_empty(); /*string*/
              kk_string_t _x_x151;
              bool _match_x66 = kk_integer_lte_borrow((kk_integer_from_small(6)),n_1,kk_context()); /*bool*/;
              if (_match_x66) {
                kk_integer_drop(n_1, _ctx);
                _x_x151 = s_1_10021; /*string*/
              }
              else {
                kk_string_t s_0_10011_1 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
                kk_integer_t n_0_10012_1 = kk_integer_sub((kk_integer_from_small(6)),n_1,kk_context()); /*int*/;
                kk_string_t _x_x152 = kk_std_core_string_repeatz(s_0_10011_1, kk_std_core_int_ssize__t(n_0_10012_1, _ctx), _ctx); /*string*/
                _x_x151 = kk_std_core_types__lp__plus__plus__rp_(_x_x152, s_1_10021, _ctx); /*string*/
              }
              _x_x148 = kk_std_core_types__lp__plus__plus__rp_(_x_x149, _x_x151, _ctx); /*string*/
              _x_x144 = kk_std_core_types__lp__plus__plus__rp_(_x_x145, _x_x148, _ctx); /*string*/
              return kk_std_core_types__lp__plus__plus__rp_(_x_x142, _x_x144, _ctx);
            }
          }
        }
      }
    }
  }
  {
    bool _match_x35 = (c > ('~')); /*bool*/;
    if (_match_x35) {
      bool _match_x39 = (c == 0x000A); /*bool*/;
      if (_match_x39) {
        kk_define_string_literal(, _s_x153, 2, "\\n", _ctx)
        return kk_string_dup(_s_x153, _ctx);
      }
      {
        bool _match_x40 = (c == 0x000D); /*bool*/;
        if (_match_x40) {
          kk_define_string_literal(, _s_x154, 2, "\\r", _ctx)
          return kk_string_dup(_s_x154, _ctx);
        }
        {
          bool _match_x41 = (c == 0x0009); /*bool*/;
          if (_match_x41) {
            kk_define_string_literal(, _s_x155, 2, "\\t", _ctx)
            return kk_string_dup(_s_x155, _ctx);
          }
          {
            bool _match_x42;
            kk_integer_t _brw_x59 = kk_integer_from_int(c,kk_context()); /*int*/;
            bool _brw_x60 = kk_integer_lte_borrow(_brw_x59,(kk_integer_from_small(255)),kk_context()); /*bool*/;
            kk_integer_drop(_brw_x59, _ctx);
            _match_x42 = _brw_x60; /*bool*/
            if (_match_x42) {
              kk_integer_t _arg_x229_0 = kk_integer_from_int(c,kk_context()); /*int*/;
              kk_string_t s_2_10028;
              kk_integer_t _x_x156;
              kk_integer_t _x_x157 = kk_integer_dup(_arg_x229_0, _ctx); /*int*/
              _x_x156 = kk_integer_abs(_x_x157,kk_context()); /*int*/
              bool _x_x158;
              kk_std_core_types__optional _match_x58 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
              if (kk_std_core_types__is_Optional(_match_x58, _ctx)) {
                kk_box_t _box_x7 = _match_x58._cons._Optional.value;
                bool _uniq_use_capitals_62_2 = kk_bool_unbox(_box_x7);
                kk_std_core_types__optional_drop(_match_x58, _ctx);
                _x_x158 = _uniq_use_capitals_62_2; /*bool*/
              }
              else {
                kk_std_core_types__optional_drop(_match_x58, _ctx);
                _x_x158 = true; /*bool*/
              }
              s_2_10028 = kk_std_core_show_int_show_hex(_x_x156, _x_x158, _ctx); /*string*/
              kk_integer_t n_2;
              kk_string_t _x_x159 = kk_string_dup(s_2_10028, _ctx); /*string*/
              n_2 = kk_std_core_string_count(_x_x159, _ctx); /*int*/
              kk_string_t _x_x160;
              kk_define_string_literal(, _s_x161, 2, "\\x", _ctx)
              _x_x160 = kk_string_dup(_s_x161, _ctx); /*string*/
              kk_string_t _x_x162;
              kk_string_t _x_x163;
              bool _match_x56;
              bool _brw_x57 = kk_integer_lt_borrow(_arg_x229_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
              kk_integer_drop(_arg_x229_0, _ctx);
              _match_x56 = _brw_x57; /*bool*/
              if (_match_x56) {
                kk_define_string_literal(, _s_x164, 1, "-", _ctx)
                _x_x163 = kk_string_dup(_s_x164, _ctx); /*string*/
              }
              else {
                _x_x163 = kk_string_empty(); /*string*/
              }
              kk_string_t _x_x166;
              kk_string_t _x_x167 = kk_string_empty(); /*string*/
              kk_string_t _x_x169;
              bool _match_x55 = kk_integer_lte_borrow((kk_integer_from_small(2)),n_2,kk_context()); /*bool*/;
              if (_match_x55) {
                kk_integer_drop(n_2, _ctx);
                _x_x169 = s_2_10028; /*string*/
              }
              else {
                kk_string_t s_0_10011_2 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
                kk_integer_t n_0_10012_2 = kk_integer_sub((kk_integer_from_small(2)),n_2,kk_context()); /*int*/;
                kk_string_t _x_x170 = kk_std_core_string_repeatz(s_0_10011_2, kk_std_core_int_ssize__t(n_0_10012_2, _ctx), _ctx); /*string*/
                _x_x169 = kk_std_core_types__lp__plus__plus__rp_(_x_x170, s_2_10028, _ctx); /*string*/
              }
              _x_x166 = kk_std_core_types__lp__plus__plus__rp_(_x_x167, _x_x169, _ctx); /*string*/
              _x_x162 = kk_std_core_types__lp__plus__plus__rp_(_x_x163, _x_x166, _ctx); /*string*/
              return kk_std_core_types__lp__plus__plus__rp_(_x_x160, _x_x162, _ctx);
            }
            {
              bool _match_x43;
              kk_integer_t _brw_x53 = kk_integer_from_int(c,kk_context()); /*int*/;
              kk_integer_t _brw_x52 = kk_integer_from_int(65535, _ctx); /*int*/;
              bool _brw_x54 = kk_integer_lte_borrow(_brw_x53,_brw_x52,kk_context()); /*bool*/;
              kk_integer_drop(_brw_x53, _ctx);
              kk_integer_drop(_brw_x52, _ctx);
              _match_x43 = _brw_x54; /*bool*/
              if (_match_x43) {
                kk_integer_t _arg_x281_0 = kk_integer_from_int(c,kk_context()); /*int*/;
                kk_string_t s_3_10035;
                kk_integer_t _x_x171;
                kk_integer_t _x_x172 = kk_integer_dup(_arg_x281_0, _ctx); /*int*/
                _x_x171 = kk_integer_abs(_x_x172,kk_context()); /*int*/
                bool _x_x173;
                kk_std_core_types__optional _match_x51 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
                if (kk_std_core_types__is_Optional(_match_x51, _ctx)) {
                  kk_box_t _box_x8 = _match_x51._cons._Optional.value;
                  bool _uniq_use_capitals_62_3 = kk_bool_unbox(_box_x8);
                  kk_std_core_types__optional_drop(_match_x51, _ctx);
                  _x_x173 = _uniq_use_capitals_62_3; /*bool*/
                }
                else {
                  kk_std_core_types__optional_drop(_match_x51, _ctx);
                  _x_x173 = true; /*bool*/
                }
                s_3_10035 = kk_std_core_show_int_show_hex(_x_x171, _x_x173, _ctx); /*string*/
                kk_integer_t n_3;
                kk_string_t _x_x174 = kk_string_dup(s_3_10035, _ctx); /*string*/
                n_3 = kk_std_core_string_count(_x_x174, _ctx); /*int*/
                kk_string_t _x_x175;
                kk_define_string_literal(, _s_x176, 2, "\\u", _ctx)
                _x_x175 = kk_string_dup(_s_x176, _ctx); /*string*/
                kk_string_t _x_x177;
                kk_string_t _x_x178;
                bool _match_x49;
                bool _brw_x50 = kk_integer_lt_borrow(_arg_x281_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                kk_integer_drop(_arg_x281_0, _ctx);
                _match_x49 = _brw_x50; /*bool*/
                if (_match_x49) {
                  kk_define_string_literal(, _s_x179, 1, "-", _ctx)
                  _x_x178 = kk_string_dup(_s_x179, _ctx); /*string*/
                }
                else {
                  _x_x178 = kk_string_empty(); /*string*/
                }
                kk_string_t _x_x181;
                kk_string_t _x_x182 = kk_string_empty(); /*string*/
                kk_string_t _x_x184;
                bool _match_x48 = kk_integer_lte_borrow((kk_integer_from_small(4)),n_3,kk_context()); /*bool*/;
                if (_match_x48) {
                  kk_integer_drop(n_3, _ctx);
                  _x_x184 = s_3_10035; /*string*/
                }
                else {
                  kk_string_t s_0_10011_3 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
                  kk_integer_t n_0_10012_3 = kk_integer_sub((kk_integer_from_small(4)),n_3,kk_context()); /*int*/;
                  kk_string_t _x_x185 = kk_std_core_string_repeatz(s_0_10011_3, kk_std_core_int_ssize__t(n_0_10012_3, _ctx), _ctx); /*string*/
                  _x_x184 = kk_std_core_types__lp__plus__plus__rp_(_x_x185, s_3_10035, _ctx); /*string*/
                }
                _x_x181 = kk_std_core_types__lp__plus__plus__rp_(_x_x182, _x_x184, _ctx); /*string*/
                _x_x177 = kk_std_core_types__lp__plus__plus__rp_(_x_x178, _x_x181, _ctx); /*string*/
                return kk_std_core_types__lp__plus__plus__rp_(_x_x175, _x_x177, _ctx);
              }
              {
                kk_integer_t _arg_x323_0 = kk_integer_from_int(c,kk_context()); /*int*/;
                kk_string_t s_4_10042;
                kk_integer_t _x_x186;
                kk_integer_t _x_x187 = kk_integer_dup(_arg_x323_0, _ctx); /*int*/
                _x_x186 = kk_integer_abs(_x_x187,kk_context()); /*int*/
                bool _x_x188;
                kk_std_core_types__optional _match_x47 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
                if (kk_std_core_types__is_Optional(_match_x47, _ctx)) {
                  kk_box_t _box_x9 = _match_x47._cons._Optional.value;
                  bool _uniq_use_capitals_62_4 = kk_bool_unbox(_box_x9);
                  kk_std_core_types__optional_drop(_match_x47, _ctx);
                  _x_x188 = _uniq_use_capitals_62_4; /*bool*/
                }
                else {
                  kk_std_core_types__optional_drop(_match_x47, _ctx);
                  _x_x188 = true; /*bool*/
                }
                s_4_10042 = kk_std_core_show_int_show_hex(_x_x186, _x_x188, _ctx); /*string*/
                kk_integer_t n_4;
                kk_string_t _x_x189 = kk_string_dup(s_4_10042, _ctx); /*string*/
                n_4 = kk_std_core_string_count(_x_x189, _ctx); /*int*/
                kk_string_t _x_x190;
                kk_define_string_literal(, _s_x191, 2, "\\U", _ctx)
                _x_x190 = kk_string_dup(_s_x191, _ctx); /*string*/
                kk_string_t _x_x192;
                kk_string_t _x_x193;
                bool _match_x45;
                bool _brw_x46 = kk_integer_lt_borrow(_arg_x323_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                kk_integer_drop(_arg_x323_0, _ctx);
                _match_x45 = _brw_x46; /*bool*/
                if (_match_x45) {
                  kk_define_string_literal(, _s_x194, 1, "-", _ctx)
                  _x_x193 = kk_string_dup(_s_x194, _ctx); /*string*/
                }
                else {
                  _x_x193 = kk_string_empty(); /*string*/
                }
                kk_string_t _x_x196;
                kk_string_t _x_x197 = kk_string_empty(); /*string*/
                kk_string_t _x_x199;
                bool _match_x44 = kk_integer_lte_borrow((kk_integer_from_small(6)),n_4,kk_context()); /*bool*/;
                if (_match_x44) {
                  kk_integer_drop(n_4, _ctx);
                  _x_x199 = s_4_10042; /*string*/
                }
                else {
                  kk_string_t s_0_10011_4 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
                  kk_integer_t n_0_10012_4 = kk_integer_sub((kk_integer_from_small(6)),n_4,kk_context()); /*int*/;
                  kk_string_t _x_x200 = kk_std_core_string_repeatz(s_0_10011_4, kk_std_core_int_ssize__t(n_0_10012_4, _ctx), _ctx); /*string*/
                  _x_x199 = kk_std_core_types__lp__plus__plus__rp_(_x_x200, s_4_10042, _ctx); /*string*/
                }
                _x_x196 = kk_std_core_types__lp__plus__plus__rp_(_x_x197, _x_x199, _ctx); /*string*/
                _x_x192 = kk_std_core_types__lp__plus__plus__rp_(_x_x193, _x_x196, _ctx); /*string*/
                return kk_std_core_types__lp__plus__plus__rp_(_x_x190, _x_x192, _ctx);
              }
            }
          }
        }
      }
    }
    {
      bool _match_x36 = (c == ('\'')); /*bool*/;
      if (_match_x36) {
        kk_define_string_literal(, _s_x201, 2, "\\\'", _ctx)
        return kk_string_dup(_s_x201, _ctx);
      }
      {
        bool _match_x37 = (c == ('"')); /*bool*/;
        if (_match_x37) {
          kk_define_string_literal(, _s_x202, 2, "\\\"", _ctx)
          return kk_string_dup(_s_x202, _ctx);
        }
        {
          bool _match_x38 = (c == ('\\')); /*bool*/;
          if (_match_x38) {
            kk_define_string_literal(, _s_x203, 2, "\\\\", _ctx)
            return kk_string_dup(_s_x203, _ctx);
          }
          {
            return kk_std_core_string_char_fs_string(c, _ctx);
          }
        }
      }
    }
  }
}
 
// lifted local: string/@lift-show@10158, string/show, @spec-x10157
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10152, using:
// @uniq-f@10152 = std/core/show/show-char

kk_std_core_types__list kk_std_core_show_string_fs__trmc_lift_show_10159(kk_std_core_types__list _uniq_xs_10151, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<char>, ctx<list<string>>) -> list<string> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10151, _ctx)) {
    struct kk_std_core_types_Cons* _con_x210 = kk_std_core_types__as_Cons(_uniq_xs_10151, _ctx);
    kk_box_t _box_x10 = _con_x210->head;
    kk_std_core_types__list _uniq_xx_10155 = _con_x210->tail;
    kk_char_t _uniq_x_10154 = kk_char_unbox(_box_x10, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x88 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10151, _ctx)) {
      _ru_x88 = (kk_datatype_ptr_reuse(_uniq_xs_10151, _ctx));
    }
    else {
      kk_std_core_types__list_dup(_uniq_xx_10155, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10151, _ctx);
    }
    kk_string_t _trmc_x10160 = kk_std_core_show_show_char(_uniq_x_10154, _ctx); /*string*/;
    kk_std_core_types__list _trmc_x10161 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10162 = kk_std_core_types__new_Cons(_ru_x88, 0, kk_string_box(_trmc_x10160), _trmc_x10161, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x20_25 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10162, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x211 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10162, _ctx)),_b_x20_25,kk_context()); /*ctx<0>*/
      _uniq_xs_10151 = _uniq_xx_10155;
      _acc = _x_x211;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x212 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x212, KK_OWNED, _ctx);
  }
}
 
// lifted local: string/@lift-show@10158, string/show, @spec-x10157
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10152, using:
// @uniq-f@10152 = std/core/show/show-char

kk_std_core_types__list kk_std_core_show_string_fs__lift_show_10159(kk_std_core_types__list _uniq_xs_10151_0, kk_context_t* _ctx) { /* (list<char>) -> list<string> */ 
  kk_std_core_types__cctx _x_x213 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_show_string_fs__trmc_lift_show_10159(_uniq_xs_10151_0, _x_x213, _ctx);
}
 
// lifted local: string/show, @spec-x10150
// specialized: std/core/list/map, on parameters @uniq-f@10147, using:
// @uniq-f@10147 = std/core/show/show-char

kk_std_core_types__list kk_std_core_show_string_fs__lift_show_10158(kk_std_core_types__list _uniq_xs_10146, kk_context_t* _ctx) { /* (list<char>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10146, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_show_string_fs__lift_show_10159(_uniq_xs_10146, _ctx);
  }
}
 
// Show a string as a string literal

kk_string_t kk_std_core_show_string_fs_show(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_std_core_types__list xs_10045;
  kk_std_core_types__list _x_x214 = kk_std_core_string_list(s, _ctx); /*list<char>*/
  xs_10045 = kk_std_core_show_string_fs__lift_show_10158(_x_x214, _ctx); /*list<string>*/
  kk_string_t _x_x215;
  kk_define_string_literal(, _s_x216, 1, "\"", _ctx)
  _x_x215 = kk_string_dup(_s_x216, _ctx); /*string*/
  kk_string_t _x_x217;
  kk_string_t _x_x218;
  if (kk_std_core_types__is_Nil(xs_10045, _ctx)) {
    _x_x218 = kk_string_empty(); /*string*/
    goto _match_x219;
  }
  {
    struct kk_std_core_types_Cons* _con_x221 = kk_std_core_types__as_Cons(xs_10045, _ctx);
    kk_box_t _box_x31 = _con_x221->head;
    kk_std_core_types__list _pat_1 = _con_x221->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x31);
      if kk_likely(kk_datatype_ptr_is_unique(xs_10045, _ctx)) {
        kk_datatype_ptr_free(xs_10045, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs_10045, _ctx);
      }
      _x_x218 = x; /*string*/
      goto _match_x219;
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x222 = kk_std_core_types__as_Cons(xs_10045, _ctx);
    kk_box_t _box_x32 = _con_x222->head;
    kk_std_core_types__list _pat_3 = _con_x222->tail;
    struct kk_std_core_types_Cons* _con_x223 = kk_std_core_types__as_Cons(_pat_3, _ctx);
    kk_box_t _box_x33 = _con_x223->head;
    kk_std_core_types__list _pat_4 = _con_x223->tail;
    if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
      kk_string_t x_0 = kk_string_unbox(_box_x32);
      kk_string_t y = kk_string_unbox(_box_x33);
      if kk_likely(kk_datatype_ptr_is_unique(xs_10045, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
          kk_datatype_ptr_free(_pat_3, _ctx);
        }
        else {
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(_pat_3, _ctx);
        }
        kk_datatype_ptr_free(xs_10045, _ctx);
      }
      else {
        kk_string_dup(x_0, _ctx);
        kk_string_dup(y, _ctx);
        kk_datatype_ptr_decref(xs_10045, _ctx);
      }
      _x_x218 = kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx); /*string*/
      goto _match_x219;
    }
  }
  {
    kk_vector_t _x_x224 = kk_std_core_vector_unvlist(xs_10045, _ctx); /*vector<832>*/
    _x_x218 = kk_string_join(_x_x224,kk_context()); /*string*/
  }
  _match_x219: ;
  kk_string_t _x_x225;
  kk_define_string_literal(, _s_x226, 1, "\"", _ctx)
  _x_x225 = kk_string_dup(_s_x226, _ctx); /*string*/
  _x_x217 = kk_std_core_types__lp__plus__plus__rp_(_x_x218, _x_x225, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x215, _x_x217, _ctx);
}

// initialization
void kk_std_core_show__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_char__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_sslice__init(_ctx);
  kk_std_core_list__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_show__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_list__done(_ctx);
  kk_std_core_sslice__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_char__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
