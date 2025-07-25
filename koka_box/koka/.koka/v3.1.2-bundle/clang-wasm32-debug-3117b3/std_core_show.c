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
  kk_string_t _x_x63;
  bool _match_x62 = kk_integer_lt_borrow(i,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x62) {
    kk_define_string_literal(, _s_x64, 1, "-", _ctx)
    _x_x63 = kk_string_dup(_s_x64, _ctx); /*string*/
  }
  else {
    _x_x63 = kk_string_empty(); /*string*/
  }
  kk_string_t _x_x66;
  kk_char_t _b_x3_4 = '0'; /*char*/;
  kk_string_t _x_x67;
  if (kk_std_core_types__is_Optional(pre, _ctx)) {
    kk_box_t _box_x0 = pre._cons._Optional.value;
    kk_string_t _uniq_pre_66 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_pre_66, _ctx);
    kk_std_core_types__optional_drop(pre, _ctx);
    _x_x67 = _uniq_pre_66; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(pre, _ctx);
    kk_define_string_literal(, _s_x68, 2, "0x", _ctx)
    _x_x67 = kk_string_dup(_s_x68, _ctx); /*string*/
  }
  kk_string_t _x_x69;
  kk_string_t _own_x60;
  kk_integer_t _x_x70 = kk_integer_abs(i,kk_context()); /*int*/
  bool _x_x71;
  if (kk_std_core_types__is_Optional(use_capitals, _ctx)) {
    kk_box_t _box_x1 = use_capitals._cons._Optional.value;
    bool _uniq_use_capitals_62 = kk_bool_unbox(_box_x1);
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    _x_x71 = _uniq_use_capitals_62; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    _x_x71 = true; /*bool*/
  }
  _own_x60 = kk_std_core_show_int_show_hex(_x_x70, _x_x71, _ctx); /*string*/
  kk_integer_t _brw_x59;
  if (kk_std_core_types__is_Optional(width, _ctx)) {
    kk_box_t _box_x2 = width._cons._Optional.value;
    kk_integer_t _uniq_width_58 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_width_58, _ctx);
    kk_std_core_types__optional_drop(width, _ctx);
    _brw_x59 = _uniq_width_58; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(width, _ctx);
    _brw_x59 = kk_integer_from_small(1); /*int*/
  }
  kk_string_t _brw_x61;
  kk_std_core_types__optional _x_x72 = kk_std_core_types__new_Optional(kk_char_box(_b_x3_4, _ctx), _ctx); /*? 7*/
  _brw_x61 = kk_std_core_string_pad_left(_own_x60, _brw_x59, _x_x72, _ctx); /*string*/
  kk_integer_drop(_brw_x59, _ctx);
  _x_x69 = _brw_x61; /*string*/
  _x_x66 = kk_std_core_types__lp__plus__plus__rp_(_x_x67, _x_x69, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x63, _x_x66, _ctx);
}
 
// Show a character as a string

kk_string_t kk_std_core_show_show_char(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> string */ 
  bool _match_x34 = (c < (' ')); /*bool*/;
  if (_match_x34) {
    bool _match_x49 = (c == 0x000A); /*bool*/;
    if (_match_x49) {
      kk_define_string_literal(, _s_x73, 2, "\\n", _ctx)
      return kk_string_dup(_s_x73, _ctx);
    }
    {
      bool _match_x50 = (c == 0x000D); /*bool*/;
      if (_match_x50) {
        kk_define_string_literal(, _s_x74, 2, "\\r", _ctx)
        return kk_string_dup(_s_x74, _ctx);
      }
      {
        bool _match_x51 = (c == 0x0009); /*bool*/;
        if (_match_x51) {
          kk_define_string_literal(, _s_x75, 2, "\\t", _ctx)
          return kk_string_dup(_s_x75, _ctx);
        }
        {
          bool _match_x52;
          kk_integer_t _brw_x57 = kk_integer_from_int(c,kk_context()); /*int*/;
          bool _brw_x58 = kk_integer_lte_borrow(_brw_x57,(kk_integer_from_small(255)),kk_context()); /*bool*/;
          kk_integer_drop(_brw_x57, _ctx);
          _match_x52 = _brw_x58; /*bool*/
          if (_match_x52) {
            kk_integer_t _arg_x229 = kk_integer_from_int(c,kk_context()); /*int*/;
            kk_integer_t _b_x5_17 = kk_integer_from_small(2); /*int*/;
            kk_string_t _b_x6_18 = kk_string_empty(); /*string*/;
            kk_string_t _x_x77;
            kk_define_string_literal(, _s_x78, 2, "\\x", _ctx)
            _x_x77 = kk_string_dup(_s_x78, _ctx); /*string*/
            kk_string_t _x_x79;
            kk_std_core_types__optional _x_x80 = kk_std_core_types__new_Optional(kk_integer_box(_b_x5_17, _ctx), _ctx); /*? 7*/
            kk_std_core_types__optional _x_x81 = kk_std_core_types__new_Optional(kk_string_box(_b_x6_18), _ctx); /*? 7*/
            _x_x79 = kk_std_core_show_show_hex(_arg_x229, _x_x80, kk_std_core_types__new_None(_ctx), _x_x81, _ctx); /*string*/
            return kk_std_core_types__lp__plus__plus__rp_(_x_x77, _x_x79, _ctx);
          }
          {
            bool _match_x53;
            kk_integer_t _brw_x55 = kk_integer_from_int(c,kk_context()); /*int*/;
            kk_integer_t _brw_x54 = kk_integer_from_int(65535, _ctx); /*int*/;
            bool _brw_x56 = kk_integer_lte_borrow(_brw_x55,_brw_x54,kk_context()); /*bool*/;
            kk_integer_drop(_brw_x55, _ctx);
            kk_integer_drop(_brw_x54, _ctx);
            _match_x53 = _brw_x56; /*bool*/
            if (_match_x53) {
              kk_integer_t _arg_x281 = kk_integer_from_int(c,kk_context()); /*int*/;
              kk_integer_t _b_x7_19 = kk_integer_from_small(4); /*int*/;
              kk_string_t _b_x8_20 = kk_string_empty(); /*string*/;
              kk_string_t _x_x83;
              kk_define_string_literal(, _s_x84, 2, "\\u", _ctx)
              _x_x83 = kk_string_dup(_s_x84, _ctx); /*string*/
              kk_string_t _x_x85;
              kk_std_core_types__optional _x_x86 = kk_std_core_types__new_Optional(kk_integer_box(_b_x7_19, _ctx), _ctx); /*? 7*/
              kk_std_core_types__optional _x_x87 = kk_std_core_types__new_Optional(kk_string_box(_b_x8_20), _ctx); /*? 7*/
              _x_x85 = kk_std_core_show_show_hex(_arg_x281, _x_x86, kk_std_core_types__new_None(_ctx), _x_x87, _ctx); /*string*/
              return kk_std_core_types__lp__plus__plus__rp_(_x_x83, _x_x85, _ctx);
            }
            {
              kk_integer_t _arg_x323 = kk_integer_from_int(c,kk_context()); /*int*/;
              kk_integer_t _b_x9_21 = kk_integer_from_small(6); /*int*/;
              kk_string_t _b_x10_22 = kk_string_empty(); /*string*/;
              kk_string_t _x_x89;
              kk_define_string_literal(, _s_x90, 2, "\\U", _ctx)
              _x_x89 = kk_string_dup(_s_x90, _ctx); /*string*/
              kk_string_t _x_x91;
              kk_std_core_types__optional _x_x92 = kk_std_core_types__new_Optional(kk_integer_box(_b_x9_21, _ctx), _ctx); /*? 7*/
              kk_std_core_types__optional _x_x93 = kk_std_core_types__new_Optional(kk_string_box(_b_x10_22), _ctx); /*? 7*/
              _x_x91 = kk_std_core_show_show_hex(_arg_x323, _x_x92, kk_std_core_types__new_None(_ctx), _x_x93, _ctx); /*string*/
              return kk_std_core_types__lp__plus__plus__rp_(_x_x89, _x_x91, _ctx);
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
        kk_define_string_literal(, _s_x94, 2, "\\n", _ctx)
        return kk_string_dup(_s_x94, _ctx);
      }
      {
        bool _match_x40 = (c == 0x000D); /*bool*/;
        if (_match_x40) {
          kk_define_string_literal(, _s_x95, 2, "\\r", _ctx)
          return kk_string_dup(_s_x95, _ctx);
        }
        {
          bool _match_x41 = (c == 0x0009); /*bool*/;
          if (_match_x41) {
            kk_define_string_literal(, _s_x96, 2, "\\t", _ctx)
            return kk_string_dup(_s_x96, _ctx);
          }
          {
            bool _match_x42;
            kk_integer_t _brw_x47 = kk_integer_from_int(c,kk_context()); /*int*/;
            bool _brw_x48 = kk_integer_lte_borrow(_brw_x47,(kk_integer_from_small(255)),kk_context()); /*bool*/;
            kk_integer_drop(_brw_x47, _ctx);
            _match_x42 = _brw_x48; /*bool*/
            if (_match_x42) {
              kk_integer_t _arg_x229_0 = kk_integer_from_int(c,kk_context()); /*int*/;
              kk_integer_t _b_x11_23 = kk_integer_from_small(2); /*int*/;
              kk_string_t _b_x12_24 = kk_string_empty(); /*string*/;
              kk_string_t _x_x98;
              kk_define_string_literal(, _s_x99, 2, "\\x", _ctx)
              _x_x98 = kk_string_dup(_s_x99, _ctx); /*string*/
              kk_string_t _x_x100;
              kk_std_core_types__optional _x_x101 = kk_std_core_types__new_Optional(kk_integer_box(_b_x11_23, _ctx), _ctx); /*? 7*/
              kk_std_core_types__optional _x_x102 = kk_std_core_types__new_Optional(kk_string_box(_b_x12_24), _ctx); /*? 7*/
              _x_x100 = kk_std_core_show_show_hex(_arg_x229_0, _x_x101, kk_std_core_types__new_None(_ctx), _x_x102, _ctx); /*string*/
              return kk_std_core_types__lp__plus__plus__rp_(_x_x98, _x_x100, _ctx);
            }
            {
              bool _match_x43;
              kk_integer_t _brw_x45 = kk_integer_from_int(c,kk_context()); /*int*/;
              kk_integer_t _brw_x44 = kk_integer_from_int(65535, _ctx); /*int*/;
              bool _brw_x46 = kk_integer_lte_borrow(_brw_x45,_brw_x44,kk_context()); /*bool*/;
              kk_integer_drop(_brw_x45, _ctx);
              kk_integer_drop(_brw_x44, _ctx);
              _match_x43 = _brw_x46; /*bool*/
              if (_match_x43) {
                kk_integer_t _arg_x281_0 = kk_integer_from_int(c,kk_context()); /*int*/;
                kk_integer_t _b_x13_25 = kk_integer_from_small(4); /*int*/;
                kk_string_t _b_x14_26 = kk_string_empty(); /*string*/;
                kk_string_t _x_x104;
                kk_define_string_literal(, _s_x105, 2, "\\u", _ctx)
                _x_x104 = kk_string_dup(_s_x105, _ctx); /*string*/
                kk_string_t _x_x106;
                kk_std_core_types__optional _x_x107 = kk_std_core_types__new_Optional(kk_integer_box(_b_x13_25, _ctx), _ctx); /*? 7*/
                kk_std_core_types__optional _x_x108 = kk_std_core_types__new_Optional(kk_string_box(_b_x14_26), _ctx); /*? 7*/
                _x_x106 = kk_std_core_show_show_hex(_arg_x281_0, _x_x107, kk_std_core_types__new_None(_ctx), _x_x108, _ctx); /*string*/
                return kk_std_core_types__lp__plus__plus__rp_(_x_x104, _x_x106, _ctx);
              }
              {
                kk_integer_t _arg_x323_0 = kk_integer_from_int(c,kk_context()); /*int*/;
                kk_integer_t _b_x15_27 = kk_integer_from_small(6); /*int*/;
                kk_string_t _b_x16_28 = kk_string_empty(); /*string*/;
                kk_string_t _x_x110;
                kk_define_string_literal(, _s_x111, 2, "\\U", _ctx)
                _x_x110 = kk_string_dup(_s_x111, _ctx); /*string*/
                kk_string_t _x_x112;
                kk_std_core_types__optional _x_x113 = kk_std_core_types__new_Optional(kk_integer_box(_b_x15_27, _ctx), _ctx); /*? 7*/
                kk_std_core_types__optional _x_x114 = kk_std_core_types__new_Optional(kk_string_box(_b_x16_28), _ctx); /*? 7*/
                _x_x112 = kk_std_core_show_show_hex(_arg_x323_0, _x_x113, kk_std_core_types__new_None(_ctx), _x_x114, _ctx); /*string*/
                return kk_std_core_types__lp__plus__plus__rp_(_x_x110, _x_x112, _ctx);
              }
            }
          }
        }
      }
    }
    {
      bool _match_x36 = (c == ('\'')); /*bool*/;
      if (_match_x36) {
        kk_define_string_literal(, _s_x115, 2, "\\\'", _ctx)
        return kk_string_dup(_s_x115, _ctx);
      }
      {
        bool _match_x37 = (c == ('"')); /*bool*/;
        if (_match_x37) {
          kk_define_string_literal(, _s_x116, 2, "\\\"", _ctx)
          return kk_string_dup(_s_x116, _ctx);
        }
        {
          bool _match_x38 = (c == ('\\')); /*bool*/;
          if (_match_x38) {
            kk_define_string_literal(, _s_x117, 2, "\\\\", _ctx)
            return kk_string_dup(_s_x117, _ctx);
          }
          {
            return kk_std_core_string_char_fs_string(c, _ctx);
          }
        }
      }
    }
  }
}
 
// Show a string as a string literal


// lift anonymous function
struct kk_std_core_show_string_fs_show_fun128__t {
  struct kk_function_s _base;
};
static kk_string_t kk_std_core_show_string_fs_show_fun128(kk_function_t _fself, kk_char_t _x1_x127, kk_context_t* _ctx);
static kk_function_t kk_std_core_show_string_fs_new_show_fun128(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_show_string_fs_show_fun128, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_string_t kk_std_core_show_string_fs_show_fun128(kk_function_t _fself, kk_char_t _x1_x127, kk_context_t* _ctx) {
  kk_unused(_fself);
  return kk_std_core_show_show_char(_x1_x127, _ctx);
}


// lift anonymous function
struct kk_std_core_show_string_fs_show_fun131__t {
  struct kk_function_s _base;
  kk_function_t _b_x30_33;
};
static kk_box_t kk_std_core_show_string_fs_show_fun131(kk_function_t _fself, kk_box_t _b_x31, kk_context_t* _ctx);
static kk_function_t kk_std_core_show_string_fs_new_show_fun131(kk_function_t _b_x30_33, kk_context_t* _ctx) {
  struct kk_std_core_show_string_fs_show_fun131__t* _self = kk_function_alloc_as(struct kk_std_core_show_string_fs_show_fun131__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_show_string_fs_show_fun131, kk_context());
  _self->_b_x30_33 = _b_x30_33;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_show_string_fs_show_fun131(kk_function_t _fself, kk_box_t _b_x31, kk_context_t* _ctx) {
  struct kk_std_core_show_string_fs_show_fun131__t* _self = kk_function_as(struct kk_std_core_show_string_fs_show_fun131__t*, _fself, _ctx);
  kk_function_t _b_x30_33 = _self->_b_x30_33; /* (c : char) -> string */
  kk_drop_match(_self, {kk_function_dup(_b_x30_33, _ctx);}, {}, _ctx)
  kk_string_t _x_x132;
  kk_char_t _x_x133 = kk_char_unbox(_b_x31, KK_OWNED, _ctx); /*char*/
  _x_x132 = kk_function_call(kk_string_t, (kk_function_t, kk_char_t, kk_context_t*), _b_x30_33, (_b_x30_33, _x_x133, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x132);
}

kk_string_t kk_std_core_show_string_fs_show(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_string_t _x_x124;
  kk_define_string_literal(, _s_x125, 1, "\"", _ctx)
  _x_x124 = kk_string_dup(_s_x125, _ctx); /*string*/
  kk_string_t _x_x126;
  kk_std_core_types__list _b_x29_32 = kk_std_core_string_list(s, _ctx); /*list<char>*/;
  kk_function_t _b_x30_33 = kk_std_core_show_string_fs_new_show_fun128(_ctx); /*(c : char) -> string*/;
  kk_string_t _x_x129;
  kk_std_core_types__list _x_x130 = kk_std_core_list_map(_b_x29_32, kk_std_core_show_string_fs_new_show_fun131(_b_x30_33, _ctx), _ctx); /*list<1969>*/
  _x_x129 = kk_std_core_list_join(_x_x130, _ctx); /*string*/
  kk_string_t _x_x134;
  kk_define_string_literal(, _s_x135, 1, "\"", _ctx)
  _x_x134 = kk_string_dup(_s_x135, _ctx); /*string*/
  _x_x126 = kk_std_core_types__lp__plus__plus__rp_(_x_x129, _x_x134, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x124, _x_x126, _ctx);
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
