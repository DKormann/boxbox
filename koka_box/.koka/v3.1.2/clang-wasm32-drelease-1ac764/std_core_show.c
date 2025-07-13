// Koka generated module: std/core/show, koka version: 3.1.2, platform: 32-bit
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
  kk_string_t _x_x80;
  bool _match_x78 = kk_integer_lt_borrow(i,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x78) {
    kk_define_string_literal(, _s_x81, 1, "-", _ctx)
    _x_x80 = kk_string_dup(_s_x81, _ctx); /*string*/
  }
  else {
    _x_x80 = kk_string_empty(); /*string*/
  }
  kk_string_t _x_x83;
  kk_char_t _b_x3_4 = '0'; /*char*/;
  kk_string_t _x_x84;
  if (kk_std_core_types__is_Optional(pre, _ctx)) {
    kk_box_t _box_x0 = pre._cons._Optional.value;
    kk_string_t _uniq_pre_66 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_pre_66, _ctx);
    kk_std_core_types__optional_drop(pre, _ctx);
    _x_x84 = _uniq_pre_66; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(pre, _ctx);
    kk_define_string_literal(, _s_x85, 2, "0x", _ctx)
    _x_x84 = kk_string_dup(_s_x85, _ctx); /*string*/
  }
  kk_string_t _x_x86;
  kk_string_t _own_x76;
  kk_integer_t _x_x87 = kk_integer_abs(i,kk_context()); /*int*/
  bool _x_x88;
  if (kk_std_core_types__is_Optional(use_capitals, _ctx)) {
    kk_box_t _box_x1 = use_capitals._cons._Optional.value;
    bool _uniq_use_capitals_62 = kk_bool_unbox(_box_x1);
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    _x_x88 = _uniq_use_capitals_62; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    _x_x88 = true; /*bool*/
  }
  _own_x76 = kk_std_core_show_int_show_hex(_x_x87, _x_x88, _ctx); /*string*/
  kk_integer_t _brw_x75;
  if (kk_std_core_types__is_Optional(width, _ctx)) {
    kk_box_t _box_x2 = width._cons._Optional.value;
    kk_integer_t _uniq_width_58 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_width_58, _ctx);
    kk_std_core_types__optional_drop(width, _ctx);
    _brw_x75 = _uniq_width_58; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(width, _ctx);
    _brw_x75 = kk_integer_from_small(1); /*int*/
  }
  kk_string_t _brw_x77;
  kk_std_core_types__optional _x_x89 = kk_std_core_types__new_Optional(kk_char_box(_b_x3_4, _ctx), _ctx); /*? 7*/
  _brw_x77 = kk_std_core_string_pad_left(_own_x76, _brw_x75, _x_x89, _ctx); /*string*/
  kk_integer_drop(_brw_x75, _ctx);
  _x_x86 = _brw_x77; /*string*/
  _x_x83 = kk_std_core_types__lp__plus__plus__rp_(_x_x84, _x_x86, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x80, _x_x83, _ctx);
}
 
// Show a character as a string

kk_string_t kk_std_core_show_show_char(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> string */ 
  bool _match_x50 = (c < (' ')); /*bool*/;
  if (_match_x50) {
    bool _match_x65 = (c == 0x000A); /*bool*/;
    if (_match_x65) {
      kk_define_string_literal(, _s_x90, 2, "\\n", _ctx)
      return kk_string_dup(_s_x90, _ctx);
    }
    {
      bool _match_x66 = (c == 0x000D); /*bool*/;
      if (_match_x66) {
        kk_define_string_literal(, _s_x91, 2, "\\r", _ctx)
        return kk_string_dup(_s_x91, _ctx);
      }
      {
        bool _match_x67 = (c == 0x0009); /*bool*/;
        if (_match_x67) {
          kk_define_string_literal(, _s_x92, 2, "\\t", _ctx)
          return kk_string_dup(_s_x92, _ctx);
        }
        {
          bool _match_x68;
          kk_integer_t _brw_x73 = kk_integer_from_int(c,kk_context()); /*int*/;
          bool _brw_x74 = kk_integer_lte_borrow(_brw_x73,(kk_integer_from_small(255)),kk_context()); /*bool*/;
          kk_integer_drop(_brw_x73, _ctx);
          _match_x68 = _brw_x74; /*bool*/
          if (_match_x68) {
            kk_integer_t _arg_x229 = kk_integer_from_int(c,kk_context()); /*int*/;
            kk_integer_t _b_x5_17 = kk_integer_from_small(2); /*int*/;
            kk_string_t _b_x6_18 = kk_string_empty(); /*string*/;
            kk_string_t _x_x94;
            kk_define_string_literal(, _s_x95, 2, "\\x", _ctx)
            _x_x94 = kk_string_dup(_s_x95, _ctx); /*string*/
            kk_string_t _x_x96;
            kk_std_core_types__optional _x_x97 = kk_std_core_types__new_Optional(kk_integer_box(_b_x5_17, _ctx), _ctx); /*? 7*/
            kk_std_core_types__optional _x_x98 = kk_std_core_types__new_Optional(kk_string_box(_b_x6_18), _ctx); /*? 7*/
            _x_x96 = kk_std_core_show_show_hex(_arg_x229, _x_x97, kk_std_core_types__new_None(_ctx), _x_x98, _ctx); /*string*/
            return kk_std_core_types__lp__plus__plus__rp_(_x_x94, _x_x96, _ctx);
          }
          {
            bool _match_x69;
            kk_integer_t _brw_x71 = kk_integer_from_int(c,kk_context()); /*int*/;
            kk_integer_t _brw_x70 = kk_integer_from_int(65535, _ctx); /*int*/;
            bool _brw_x72 = kk_integer_lte_borrow(_brw_x71,_brw_x70,kk_context()); /*bool*/;
            kk_integer_drop(_brw_x71, _ctx);
            kk_integer_drop(_brw_x70, _ctx);
            _match_x69 = _brw_x72; /*bool*/
            if (_match_x69) {
              kk_integer_t _arg_x281 = kk_integer_from_int(c,kk_context()); /*int*/;
              kk_integer_t _b_x7_19 = kk_integer_from_small(4); /*int*/;
              kk_string_t _b_x8_20 = kk_string_empty(); /*string*/;
              kk_string_t _x_x100;
              kk_define_string_literal(, _s_x101, 2, "\\u", _ctx)
              _x_x100 = kk_string_dup(_s_x101, _ctx); /*string*/
              kk_string_t _x_x102;
              kk_std_core_types__optional _x_x103 = kk_std_core_types__new_Optional(kk_integer_box(_b_x7_19, _ctx), _ctx); /*? 7*/
              kk_std_core_types__optional _x_x104 = kk_std_core_types__new_Optional(kk_string_box(_b_x8_20), _ctx); /*? 7*/
              _x_x102 = kk_std_core_show_show_hex(_arg_x281, _x_x103, kk_std_core_types__new_None(_ctx), _x_x104, _ctx); /*string*/
              return kk_std_core_types__lp__plus__plus__rp_(_x_x100, _x_x102, _ctx);
            }
            {
              kk_integer_t _arg_x323 = kk_integer_from_int(c,kk_context()); /*int*/;
              kk_integer_t _b_x9_21 = kk_integer_from_small(6); /*int*/;
              kk_string_t _b_x10_22 = kk_string_empty(); /*string*/;
              kk_string_t _x_x106;
              kk_define_string_literal(, _s_x107, 2, "\\U", _ctx)
              _x_x106 = kk_string_dup(_s_x107, _ctx); /*string*/
              kk_string_t _x_x108;
              kk_std_core_types__optional _x_x109 = kk_std_core_types__new_Optional(kk_integer_box(_b_x9_21, _ctx), _ctx); /*? 7*/
              kk_std_core_types__optional _x_x110 = kk_std_core_types__new_Optional(kk_string_box(_b_x10_22), _ctx); /*? 7*/
              _x_x108 = kk_std_core_show_show_hex(_arg_x323, _x_x109, kk_std_core_types__new_None(_ctx), _x_x110, _ctx); /*string*/
              return kk_std_core_types__lp__plus__plus__rp_(_x_x106, _x_x108, _ctx);
            }
          }
        }
      }
    }
  }
  {
    bool _match_x51 = (c > ('~')); /*bool*/;
    if (_match_x51) {
      bool _match_x55 = (c == 0x000A); /*bool*/;
      if (_match_x55) {
        kk_define_string_literal(, _s_x111, 2, "\\n", _ctx)
        return kk_string_dup(_s_x111, _ctx);
      }
      {
        bool _match_x56 = (c == 0x000D); /*bool*/;
        if (_match_x56) {
          kk_define_string_literal(, _s_x112, 2, "\\r", _ctx)
          return kk_string_dup(_s_x112, _ctx);
        }
        {
          bool _match_x57 = (c == 0x0009); /*bool*/;
          if (_match_x57) {
            kk_define_string_literal(, _s_x113, 2, "\\t", _ctx)
            return kk_string_dup(_s_x113, _ctx);
          }
          {
            bool _match_x58;
            kk_integer_t _brw_x63 = kk_integer_from_int(c,kk_context()); /*int*/;
            bool _brw_x64 = kk_integer_lte_borrow(_brw_x63,(kk_integer_from_small(255)),kk_context()); /*bool*/;
            kk_integer_drop(_brw_x63, _ctx);
            _match_x58 = _brw_x64; /*bool*/
            if (_match_x58) {
              kk_integer_t _arg_x229_0 = kk_integer_from_int(c,kk_context()); /*int*/;
              kk_integer_t _b_x11_23 = kk_integer_from_small(2); /*int*/;
              kk_string_t _b_x12_24 = kk_string_empty(); /*string*/;
              kk_string_t _x_x115;
              kk_define_string_literal(, _s_x116, 2, "\\x", _ctx)
              _x_x115 = kk_string_dup(_s_x116, _ctx); /*string*/
              kk_string_t _x_x117;
              kk_std_core_types__optional _x_x118 = kk_std_core_types__new_Optional(kk_integer_box(_b_x11_23, _ctx), _ctx); /*? 7*/
              kk_std_core_types__optional _x_x119 = kk_std_core_types__new_Optional(kk_string_box(_b_x12_24), _ctx); /*? 7*/
              _x_x117 = kk_std_core_show_show_hex(_arg_x229_0, _x_x118, kk_std_core_types__new_None(_ctx), _x_x119, _ctx); /*string*/
              return kk_std_core_types__lp__plus__plus__rp_(_x_x115, _x_x117, _ctx);
            }
            {
              bool _match_x59;
              kk_integer_t _brw_x61 = kk_integer_from_int(c,kk_context()); /*int*/;
              kk_integer_t _brw_x60 = kk_integer_from_int(65535, _ctx); /*int*/;
              bool _brw_x62 = kk_integer_lte_borrow(_brw_x61,_brw_x60,kk_context()); /*bool*/;
              kk_integer_drop(_brw_x61, _ctx);
              kk_integer_drop(_brw_x60, _ctx);
              _match_x59 = _brw_x62; /*bool*/
              if (_match_x59) {
                kk_integer_t _arg_x281_0 = kk_integer_from_int(c,kk_context()); /*int*/;
                kk_integer_t _b_x13_25 = kk_integer_from_small(4); /*int*/;
                kk_string_t _b_x14_26 = kk_string_empty(); /*string*/;
                kk_string_t _x_x121;
                kk_define_string_literal(, _s_x122, 2, "\\u", _ctx)
                _x_x121 = kk_string_dup(_s_x122, _ctx); /*string*/
                kk_string_t _x_x123;
                kk_std_core_types__optional _x_x124 = kk_std_core_types__new_Optional(kk_integer_box(_b_x13_25, _ctx), _ctx); /*? 7*/
                kk_std_core_types__optional _x_x125 = kk_std_core_types__new_Optional(kk_string_box(_b_x14_26), _ctx); /*? 7*/
                _x_x123 = kk_std_core_show_show_hex(_arg_x281_0, _x_x124, kk_std_core_types__new_None(_ctx), _x_x125, _ctx); /*string*/
                return kk_std_core_types__lp__plus__plus__rp_(_x_x121, _x_x123, _ctx);
              }
              {
                kk_integer_t _arg_x323_0 = kk_integer_from_int(c,kk_context()); /*int*/;
                kk_integer_t _b_x15_27 = kk_integer_from_small(6); /*int*/;
                kk_string_t _b_x16_28 = kk_string_empty(); /*string*/;
                kk_string_t _x_x127;
                kk_define_string_literal(, _s_x128, 2, "\\U", _ctx)
                _x_x127 = kk_string_dup(_s_x128, _ctx); /*string*/
                kk_string_t _x_x129;
                kk_std_core_types__optional _x_x130 = kk_std_core_types__new_Optional(kk_integer_box(_b_x15_27, _ctx), _ctx); /*? 7*/
                kk_std_core_types__optional _x_x131 = kk_std_core_types__new_Optional(kk_string_box(_b_x16_28), _ctx); /*? 7*/
                _x_x129 = kk_std_core_show_show_hex(_arg_x323_0, _x_x130, kk_std_core_types__new_None(_ctx), _x_x131, _ctx); /*string*/
                return kk_std_core_types__lp__plus__plus__rp_(_x_x127, _x_x129, _ctx);
              }
            }
          }
        }
      }
    }
    {
      bool _match_x52 = (c == ('\'')); /*bool*/;
      if (_match_x52) {
        kk_define_string_literal(, _s_x132, 2, "\\\'", _ctx)
        return kk_string_dup(_s_x132, _ctx);
      }
      {
        bool _match_x53 = (c == ('"')); /*bool*/;
        if (_match_x53) {
          kk_define_string_literal(, _s_x133, 2, "\\\"", _ctx)
          return kk_string_dup(_s_x133, _ctx);
        }
        {
          bool _match_x54 = (c == ('\\')); /*bool*/;
          if (_match_x54) {
            kk_define_string_literal(, _s_x134, 2, "\\\\", _ctx)
            return kk_string_dup(_s_x134, _ctx);
          }
          {
            return kk_std_core_string_char_fs_string(c, _ctx);
          }
        }
      }
    }
  }
}
 
// lifted local: string/@lift-show@10112, string/show, @spec-x10111
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10106, using:
// @uniq-f@10106 = std/core/show/show-char

kk_std_core_types__list kk_std_core_show_string_fs__trmc_lift_show_10113(kk_std_core_types__list _uniq_xs_10105, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<char>, ctx<list<string>>) -> list<string> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10105, _ctx)) {
    struct kk_std_core_types_Cons* _con_x141 = kk_std_core_types__as_Cons(_uniq_xs_10105, _ctx);
    kk_box_t _box_x29 = _con_x141->head;
    kk_std_core_types__list _uniq_xx_10109 = _con_x141->tail;
    kk_char_t _uniq_x_10108 = kk_char_unbox(_box_x29, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x79 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10105, _ctx)) {
      kk_box_drop(_box_x29, _ctx);
      _ru_x79 = (kk_datatype_ptr_reuse(_uniq_xs_10105, _ctx));
    }
    else {
      kk_std_core_types__list_dup(_uniq_xx_10109, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10105, _ctx);
    }
    kk_string_t _trmc_x10114 = kk_std_core_show_show_char(_uniq_x_10108, _ctx); /*string*/;
    kk_std_core_types__list _trmc_x10115 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10116 = kk_std_core_types__new_Cons(_ru_x79, 0, kk_string_box(_trmc_x10114), _trmc_x10115, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x39_44 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10116, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x142 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10116, _ctx)),_b_x39_44,kk_context()); /*ctx<0>*/
      _uniq_xs_10105 = _uniq_xx_10109;
      _acc = _x_x142;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x143 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x143, KK_OWNED, _ctx);
  }
}
 
// lifted local: string/@lift-show@10112, string/show, @spec-x10111
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10106, using:
// @uniq-f@10106 = std/core/show/show-char

kk_std_core_types__list kk_std_core_show_string_fs__lift_show_10113(kk_std_core_types__list _uniq_xs_10105_0, kk_context_t* _ctx) { /* (list<char>) -> list<string> */ 
  kk_std_core_types__cctx _x_x144 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_show_string_fs__trmc_lift_show_10113(_uniq_xs_10105_0, _x_x144, _ctx);
}
 
// lifted local: string/show, @spec-x10104
// specialized: std/core/list/map, on parameters @uniq-f@10101, using:
// @uniq-f@10101 = std/core/show/show-char

kk_std_core_types__list kk_std_core_show_string_fs__lift_show_10112(kk_std_core_types__list _uniq_xs_10100, kk_context_t* _ctx) { /* (list<char>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10100, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_show_string_fs__lift_show_10113(_uniq_xs_10100, _ctx);
  }
}
 
// Show a string as a string literal

kk_string_t kk_std_core_show_string_fs_show(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_string_t _x_x145;
  kk_define_string_literal(, _s_x146, 1, "\"", _ctx)
  _x_x145 = kk_string_dup(_s_x146, _ctx); /*string*/
  kk_string_t _x_x147;
  kk_string_t _x_x148;
  kk_std_core_types__list _x_x149;
  kk_std_core_types__list _x_x150 = kk_std_core_string_list(s, _ctx); /*list<char>*/
  _x_x149 = kk_std_core_show_string_fs__lift_show_10112(_x_x150, _ctx); /*list<string>*/
  _x_x148 = kk_std_core_list_join(_x_x149, _ctx); /*string*/
  kk_string_t _x_x151;
  kk_define_string_literal(, _s_x152, 1, "\"", _ctx)
  _x_x151 = kk_string_dup(_s_x152, _ctx); /*string*/
  _x_x147 = kk_std_core_types__lp__plus__plus__rp_(_x_x148, _x_x151, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x145, _x_x147, _ctx);
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
