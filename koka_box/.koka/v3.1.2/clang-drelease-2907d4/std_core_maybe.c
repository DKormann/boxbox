// Koka generated module: std/core/maybe, koka version: 3.1.2, platform: 64-bit
#include "std_core_maybe.h"
 
// Get the value of the `Just` constructor or raise an exception

kk_box_t kk_std_core_maybe_unjust(kk_std_core_types__maybe m, kk_context_t* _ctx) { /* forall<a> (m : maybe<a>) -> exn a */ 
  if (kk_std_core_types__is_Just(m, _ctx)) {
    kk_box_t x = m._cons.Just.value;
    return x;
  }
  {
    kk_std_core_hnd__ev ev_10112 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    {
      struct kk_std_core_hnd_Ev* _con_x41 = kk_std_core_hnd__as_Ev(ev_10112, _ctx);
      kk_box_t _box_x0 = _con_x41->hnd;
      int32_t m_0 = _con_x41->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x0, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x38;
      kk_std_core_hnd__clause1 _brw_x40 = kk_std_core_exn__select_throw_exn(h, _ctx); /*hnd/clause1<exception,403,exn,404,405>*/;
      kk_std_core_exn__exn_drop(h, _ctx);
      _match_x38 = _brw_x40; /*hnd/clause1<exception,403,exn,404,405>*/
      {
        kk_function_t _fun_unbox_x4 = _match_x38.clause;
        kk_box_t _x_x42;
        kk_std_core_exn__exception _x_x43;
        kk_string_t _x_x44;
        kk_define_string_literal(, _s_x45, 43, "unexpected Nothing in std/core/maybe/unjust", _ctx)
        _x_x44 = kk_string_dup(_s_x45, _ctx); /*string*/
        kk_std_core_exn__exception_info _x_x46;
        kk_std_core_types__optional _match_x39 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x39, _ctx)) {
          kk_box_t _box_x8 = _match_x39._cons._Optional.value;
          kk_std_core_exn__exception_info _uniq_info_473 = kk_std_core_exn__exception_info_unbox(_box_x8, KK_BORROWED, _ctx);
          kk_std_core_exn__exception_info_dup(_uniq_info_473, _ctx);
          kk_std_core_types__optional_drop(_match_x39, _ctx);
          _x_x46 = _uniq_info_473; /*exception-info*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x39, _ctx);
          _x_x46 = kk_std_core_exn__new_ExnError(_ctx); /*exception-info*/
        }
        _x_x43 = kk_std_core_exn__new_Exception(_x_x44, _x_x46, _ctx); /*exception*/
        _x_x42 = kk_std_core_exn__exception_box(_x_x43, _ctx); /*45*/
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x4, (_fun_unbox_x4, m_0, ev_10112, _x_x42, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_std_core_maybe_map_fun48__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_maybe_map_fun48(kk_function_t _fself, kk_box_t _b_x10, kk_context_t* _ctx);
static kk_function_t kk_std_core_maybe_new_map_fun48(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_maybe_map_fun48, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_maybe_map_fun48(kk_function_t _fself, kk_box_t _b_x10, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_box_t _y_x10106_12 = _b_x10; /*183*/;
  kk_std_core_types__maybe _x_x49 = kk_std_core_types__new_Just(_y_x10106_12, _ctx); /*maybe<1264>*/
  return kk_std_core_types__maybe_box(_x_x49, _ctx);
}

kk_std_core_types__maybe kk_std_core_maybe_map(kk_std_core_types__maybe m, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (m : maybe<a>, f : (a) -> e b) -> e maybe<b> */ 
  if (kk_std_core_types__is_Nothing(m, _ctx)) {
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_box_t x = m._cons.Just.value;
    kk_box_t x_0_10115 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx), _ctx); /*183*/;
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10115, _ctx);
      kk_box_t _x_x47 = kk_std_core_hnd_yield_extend(kk_std_core_maybe_new_map_fun48(_ctx), _ctx); /*2978*/
      return kk_std_core_types__maybe_unbox(_x_x47, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_types__new_Just(x_0_10115, _ctx);
    }
  }
}
 
// Equality on `:maybe`

bool kk_std_core_maybe__lp__eq__eq__rp_(kk_std_core_types__maybe mb1, kk_std_core_types__maybe mb2, kk_function_t _implicit_fs__lp__eq__eq__rp_, kk_context_t* _ctx) { /* forall<a> (mb1 : maybe<a>, mb2 : maybe<a>, ?(==) : (a, a) -> bool) -> bool */ 
  if (kk_std_core_types__is_Just(mb1, _ctx)) {
    kk_box_t x = mb1._cons.Just.value;
    if (kk_std_core_types__is_Just(mb2, _ctx)) {
      kk_box_t y = mb2._cons.Just.value;
      return kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs__lp__eq__eq__rp_, (_implicit_fs__lp__eq__eq__rp_, x, y, _ctx), _ctx);
    }
    {
      kk_function_drop(_implicit_fs__lp__eq__eq__rp_, _ctx);
      kk_box_drop(x, _ctx);
      return false;
    }
  }
  {
    kk_function_drop(_implicit_fs__lp__eq__eq__rp_, _ctx);
    if (kk_std_core_types__is_Nothing(mb2, _ctx)) {
      return true;
    }
    {
      kk_std_core_types__maybe_drop(mb2, _ctx);
      return false;
    }
  }
}
 
// Order on `:maybe` values

kk_std_core_types__order kk_std_core_maybe_cmp(kk_std_core_types__maybe mb1, kk_std_core_types__maybe mb2, kk_function_t _implicit_fs_cmp, kk_context_t* _ctx) { /* forall<a> (mb1 : maybe<a>, mb2 : maybe<a>, ?cmp : (a, a) -> order) -> order */ 
  if (kk_std_core_types__is_Just(mb1, _ctx)) {
    kk_box_t x = mb1._cons.Just.value;
    if (kk_std_core_types__is_Just(mb2, _ctx)) {
      kk_box_t y = mb2._cons.Just.value;
      return kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_cmp, (_implicit_fs_cmp, x, y, _ctx), _ctx);
    }
    {
      kk_function_drop(_implicit_fs_cmp, _ctx);
      kk_box_drop(x, _ctx);
      return kk_std_core_types__new_Gt(_ctx);
    }
  }
  {
    kk_function_drop(_implicit_fs_cmp, _ctx);
    if (kk_std_core_types__is_Nothing(mb2, _ctx)) {
      return kk_std_core_types__new_Eq(_ctx);
    }
    {
      kk_std_core_types__maybe_drop(mb2, _ctx);
      return kk_std_core_types__new_Lt(_ctx);
    }
  }
}
 
// Order two `:maybe` values in ascending order

kk_std_core_types__order2 kk_std_core_maybe_order2(kk_std_core_types__maybe mb1, kk_std_core_types__maybe mb2, kk_function_t _implicit_fs_order2, kk_context_t* _ctx) { /* forall<a> (mb1 : maybe<a>, mb2 : maybe<a>, ?order2 : (a, a) -> order2<a>) -> order2<maybe<a>> */ 
  if (kk_std_core_types__is_Just(mb1, _ctx)) {
    kk_box_t x = mb1._cons.Just.value;
    if (kk_std_core_types__is_Just(mb2, _ctx)) {
      kk_box_t y = mb2._cons.Just.value;
      kk_std_core_types__order2 _match_x36;
      kk_function_t _x_x50 = kk_function_dup(_implicit_fs_order2, _ctx); /*(414, 414) -> order2<414>*/
      _match_x36 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x50, (_x_x50, x, y, _ctx), _ctx); /*order2<414>*/
      if (kk_std_core_types__is_Eq2(_match_x36, _ctx)) {
        kk_box_t z = _match_x36._cons.Eq2.eq;
        kk_box_t _x_x51;
        kk_std_core_types__maybe _x_x52 = kk_std_core_types__new_Just(z, _ctx); /*maybe<1421>*/
        _x_x51 = kk_std_core_types__maybe_box(_x_x52, _ctx); /*102*/
        return kk_std_core_types__new_Eq2(_x_x51, _ctx);
      }
      if (kk_std_core_types__is_Lt2(_match_x36, _ctx)) {
        kk_box_t l = _match_x36._cons.Lt2.lt;
        kk_box_t g = _match_x36._cons.Lt2.gt;
        kk_box_t _x_x53;
        kk_std_core_types__maybe _x_x54 = kk_std_core_types__new_Just(l, _ctx); /*maybe<1444>*/
        _x_x53 = kk_std_core_types__maybe_box(_x_x54, _ctx); /*102*/
        kk_box_t _x_x55;
        kk_std_core_types__maybe _x_x56 = kk_std_core_types__new_Just(g, _ctx); /*maybe<1444>*/
        _x_x55 = kk_std_core_types__maybe_box(_x_x56, _ctx); /*102*/
        return kk_std_core_types__new_Lt2(_x_x53, _x_x55, _ctx);
      }
      {
        kk_box_t l_0 = _match_x36._cons.Gt2.lt;
        kk_box_t g_0 = _match_x36._cons.Gt2.gt;
        kk_box_t _x_x57;
        kk_std_core_types__maybe _x_x58 = kk_std_core_types__new_Just(l_0, _ctx); /*maybe<1467>*/
        _x_x57 = kk_std_core_types__maybe_box(_x_x58, _ctx); /*102*/
        kk_box_t _x_x59;
        kk_std_core_types__maybe _x_x60 = kk_std_core_types__new_Just(g_0, _ctx); /*maybe<1467>*/
        _x_x59 = kk_std_core_types__maybe_box(_x_x60, _ctx); /*102*/
        return kk_std_core_types__new_Gt2(_x_x57, _x_x59, _ctx);
      }
    }
    {
      kk_box_t _x_x61;
      kk_std_core_types__maybe _x_x62 = kk_std_core_types__new_Just(x, _ctx); /*maybe<1486>*/
      _x_x61 = kk_std_core_types__maybe_box(_x_x62, _ctx); /*102*/
      return kk_std_core_types__new_Gt2(kk_std_core_types__maybe_box(kk_std_core_types__new_Nothing(_ctx), _ctx), _x_x61, _ctx);
    }
  }
  {
    return kk_std_core_types__new_Lt2(kk_std_core_types__maybe_box(kk_std_core_types__new_Nothing(_ctx), _ctx), kk_std_core_types__maybe_box(mb2, _ctx), _ctx);
  }
}
 
// Show a `:maybe` type


// lift anonymous function
struct kk_std_core_maybe_show_fun69__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_maybe_show_fun69(kk_function_t _fself, kk_box_t _b_x32, kk_context_t* _ctx);
static kk_function_t kk_std_core_maybe_new_show_fun69(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_maybe_show_fun69, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_maybe_show_fun69(kk_function_t _fself, kk_box_t _b_x32, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_string_t _y_x10108_34 = kk_string_unbox(_b_x32); /*string*/;
  kk_string_t _x_x70;
  kk_string_t _x_x71;
  kk_define_string_literal(, _s_x72, 5, "Just(", _ctx)
  _x_x71 = kk_string_dup(_s_x72, _ctx); /*string*/
  kk_string_t _x_x73;
  kk_string_t _x_x74;
  kk_define_string_literal(, _s_x75, 1, ")", _ctx)
  _x_x74 = kk_string_dup(_s_x75, _ctx); /*string*/
  _x_x73 = kk_std_core_types__lp__plus__plus__rp_(_y_x10108_34, _x_x74, _ctx); /*string*/
  _x_x70 = kk_std_core_types__lp__plus__plus__rp_(_x_x71, _x_x73, _ctx); /*string*/
  return kk_string_box(_x_x70);
}

kk_string_t kk_std_core_maybe_show(kk_std_core_types__maybe mb, kk_function_t _implicit_fs_show, kk_context_t* _ctx) { /* forall<a,e> (mb : maybe<a>, ?show : (a) -> e string) -> e string */ 
  if (kk_std_core_types__is_Just(mb, _ctx)) {
    kk_box_t x = mb._cons.Just.value;
    kk_string_t x_0_10119 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_show, (_implicit_fs_show, x, _ctx), _ctx); /*string*/;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_10119, _ctx);
      kk_box_t _x_x68 = kk_std_core_hnd_yield_extend(kk_std_core_maybe_new_show_fun69(_ctx), _ctx); /*2978*/
      return kk_string_unbox(_x_x68);
    }
    {
      kk_string_t _x_x76;
      kk_define_string_literal(, _s_x77, 5, "Just(", _ctx)
      _x_x76 = kk_string_dup(_s_x77, _ctx); /*string*/
      kk_string_t _x_x78;
      kk_string_t _x_x79;
      kk_define_string_literal(, _s_x80, 1, ")", _ctx)
      _x_x79 = kk_string_dup(_s_x80, _ctx); /*string*/
      _x_x78 = kk_std_core_types__lp__plus__plus__rp_(x_0_10119, _x_x79, _ctx); /*string*/
      return kk_std_core_types__lp__plus__plus__rp_(_x_x76, _x_x78, _ctx);
    }
  }
  {
    kk_function_drop(_implicit_fs_show, _ctx);
    kk_define_string_literal(, _s_x81, 7, "Nothing", _ctx)
    return kk_string_dup(_s_x81, _ctx);
  }
}

// initialization
void kk_std_core_maybe__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_exn__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_maybe__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
