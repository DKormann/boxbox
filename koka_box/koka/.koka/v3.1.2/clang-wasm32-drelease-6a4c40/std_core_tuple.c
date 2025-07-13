// Koka generated module: std/core/tuple, koka version: 3.1.2, platform: 32-bit
#include "std_core_tuple.h"
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs__mlift_map_10130_fun124__t {
  struct kk_function_s _base;
  kk_box_t _y_x10100;
};
static kk_box_t kk_std_core_tuple_tuple2_fs__mlift_map_10130_fun124(kk_function_t _fself, kk_box_t _b_x1, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs__new_mlift_map_10130_fun124(kk_box_t _y_x10100, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs__mlift_map_10130_fun124__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs__mlift_map_10130_fun124__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs__mlift_map_10130_fun124, kk_context());
  _self->_y_x10100 = _y_x10100;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple2_fs__mlift_map_10130_fun124(kk_function_t _fself, kk_box_t _b_x1, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs__mlift_map_10130_fun124__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs__mlift_map_10130_fun124__t*, _fself, _ctx);
  kk_box_t _y_x10100 = _self->_y_x10100; /* 238 */
  kk_drop_match(_self, {kk_box_dup(_y_x10100, _ctx);}, {}, _ctx)
  kk_box_t _y_x10101_3 = _b_x1; /*238*/;
  kk_std_core_types__tuple2 _x_x125 = kk_std_core_types__new_Tuple2(_y_x10100, _y_x10101_3, _ctx); /*(129, 130)*/
  return kk_std_core_types__tuple2_box(_x_x125, _ctx);
}

kk_std_core_types__tuple2 kk_std_core_tuple_tuple2_fs__mlift_map_10130(kk_function_t f, kk_std_core_types__tuple2 t, kk_box_t _y_x10100, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, t : (a, a), b) -> e (b, b) */ 
  kk_box_t x_10143;
  kk_box_t _x_x122;
  {
    kk_box_t _x_0 = t.snd;
    kk_box_dup(_x_0, _ctx);
    kk_std_core_types__tuple2_drop(t, _ctx);
    _x_x122 = _x_0; /*237*/
  }
  x_10143 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x_x122, _ctx), _ctx); /*238*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10143, _ctx);
    kk_box_t _x_x123 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple2_fs__new_mlift_map_10130_fun124(_y_x10100, _ctx), _ctx); /*2978*/
    return kk_std_core_types__tuple2_unbox(_x_x123, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_types__new_Tuple2(_y_x10100, x_10143, _ctx);
  }
}
 
// Map a function over a tuple of elements of the same type.


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs_map_fun129__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple2 t;
};
static kk_box_t kk_std_core_tuple_tuple2_fs_map_fun129(kk_function_t _fself, kk_box_t _b_x5, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs_new_map_fun129(kk_function_t f, kk_std_core_types__tuple2 t, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_map_fun129__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs_map_fun129__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs_map_fun129, kk_context());
  _self->f = f;
  _self->t = t;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple2_fs_map_fun129(kk_function_t _fself, kk_box_t _b_x5, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_map_fun129__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs_map_fun129__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (237) -> 239 238 */
  kk_std_core_types__tuple2 t = _self->t; /* (237, 237) */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_std_core_types__tuple2_dup(t, _ctx);}, {}, _ctx)
  kk_box_t _y_x10100_10 = _b_x5; /*238*/;
  kk_std_core_types__tuple2 _x_x130 = kk_std_core_tuple_tuple2_fs__mlift_map_10130(f, t, _y_x10100_10, _ctx); /*(238, 238)*/
  return kk_std_core_types__tuple2_box(_x_x130, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs_map_fun133__t {
  struct kk_function_s _base;
  kk_box_t x_10147;
};
static kk_box_t kk_std_core_tuple_tuple2_fs_map_fun133(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs_new_map_fun133(kk_box_t x_10147, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_map_fun133__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs_map_fun133__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs_map_fun133, kk_context());
  _self->x_10147 = x_10147;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple2_fs_map_fun133(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_map_fun133__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs_map_fun133__t*, _fself, _ctx);
  kk_box_t x_10147 = _self->x_10147; /* 238 */
  kk_drop_match(_self, {kk_box_dup(x_10147, _ctx);}, {}, _ctx)
  kk_box_t _y_x10101_11 = _b_x7; /*238*/;
  kk_std_core_types__tuple2 _x_x134 = kk_std_core_types__new_Tuple2(x_10147, _y_x10101_11, _ctx); /*(129, 130)*/
  return kk_std_core_types__tuple2_box(_x_x134, _ctx);
}

kk_std_core_types__tuple2 kk_std_core_tuple_tuple2_fs_map(kk_std_core_types__tuple2 t, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (t : (a, a), f : (a) -> e b) -> e (b, b) */ 
  kk_box_t x_10147;
  kk_function_t _x_x127 = kk_function_dup(f, _ctx); /*(237) -> 239 238*/
  kk_box_t _x_x126;
  {
    kk_box_t _x = t.fst;
    kk_box_dup(_x, _ctx);
    _x_x126 = _x; /*237*/
  }
  x_10147 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x127, (_x_x127, _x_x126, _ctx), _ctx); /*238*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10147, _ctx);
    kk_box_t _x_x128 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple2_fs_new_map_fun129(f, t, _ctx), _ctx); /*2978*/
    return kk_std_core_types__tuple2_unbox(_x_x128, KK_OWNED, _ctx);
  }
  {
    kk_box_t x_0_10150;
    kk_box_t _x_x131;
    {
      kk_box_t _x_0 = t.snd;
      kk_box_dup(_x_0, _ctx);
      kk_std_core_types__tuple2_drop(t, _ctx);
      _x_x131 = _x_0; /*237*/
    }
    x_0_10150 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x_x131, _ctx), _ctx); /*238*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10150, _ctx);
      kk_box_t _x_x132 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple2_fs_new_map_fun133(x_10147, _ctx), _ctx); /*2978*/
      return kk_std_core_types__tuple2_unbox(_x_x132, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_types__new_Tuple2(x_10147, x_0_10150, _ctx);
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs__mlift_map_10132_fun137__t {
  struct kk_function_s _base;
  kk_box_t _y_x10102;
  kk_box_t _y_x10103;
};
static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_map_10132_fun137(kk_function_t _fself, kk_box_t _b_x13, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs__new_mlift_map_10132_fun137(kk_box_t _y_x10102, kk_box_t _y_x10103, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_map_10132_fun137__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs__mlift_map_10132_fun137__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs__mlift_map_10132_fun137, kk_context());
  _self->_y_x10102 = _y_x10102;
  _self->_y_x10103 = _y_x10103;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_map_10132_fun137(kk_function_t _fself, kk_box_t _b_x13, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_map_10132_fun137__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs__mlift_map_10132_fun137__t*, _fself, _ctx);
  kk_box_t _y_x10102 = _self->_y_x10102; /* 385 */
  kk_box_t _y_x10103 = _self->_y_x10103; /* 385 */
  kk_drop_match(_self, {kk_box_dup(_y_x10102, _ctx);kk_box_dup(_y_x10103, _ctx);}, {}, _ctx)
  kk_box_t _y_x10104_15 = _b_x13; /*385*/;
  kk_std_core_types__tuple3 _x_x138 = kk_std_core_types__new_Tuple3(_y_x10102, _y_x10103, _y_x10104_15, _ctx); /*(136, 137, 138)*/
  return kk_std_core_types__tuple3_box(_x_x138, _ctx);
}

kk_std_core_types__tuple3 kk_std_core_tuple_tuple3_fs__mlift_map_10132(kk_box_t _y_x10102, kk_function_t f, kk_std_core_types__tuple3 t, kk_box_t _y_x10103, kk_context_t* _ctx) { /* forall<a,b,e> (b, f : (a) -> e b, t : (a, a, a), b) -> e (b, b, b) */ 
  kk_box_t x_10155;
  kk_box_t _x_x135;
  {
    kk_box_t _x_1 = t.thd;
    kk_box_dup(_x_1, _ctx);
    kk_std_core_types__tuple3_drop(t, _ctx);
    _x_x135 = _x_1; /*384*/
  }
  x_10155 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x_x135, _ctx), _ctx); /*385*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10155, _ctx);
    kk_box_t _x_x136 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs__new_mlift_map_10132_fun137(_y_x10102, _y_x10103, _ctx), _ctx); /*2978*/
    return kk_std_core_types__tuple3_unbox(_x_x136, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_types__new_Tuple3(_y_x10102, _y_x10103, x_10155, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs__mlift_map_10133_fun142__t {
  struct kk_function_s _base;
  kk_box_t _y_x10102;
  kk_function_t f;
  kk_std_core_types__tuple3 t;
};
static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_map_10133_fun142(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs__new_mlift_map_10133_fun142(kk_box_t _y_x10102, kk_function_t f, kk_std_core_types__tuple3 t, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_map_10133_fun142__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs__mlift_map_10133_fun142__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs__mlift_map_10133_fun142, kk_context());
  _self->_y_x10102 = _y_x10102;
  _self->f = f;
  _self->t = t;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_map_10133_fun142(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_map_10133_fun142__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs__mlift_map_10133_fun142__t*, _fself, _ctx);
  kk_box_t _y_x10102 = _self->_y_x10102; /* 385 */
  kk_function_t f = _self->f; /* (384) -> 386 385 */
  kk_std_core_types__tuple3 t = _self->t; /* (384, 384, 384) */
  kk_drop_match(_self, {kk_box_dup(_y_x10102, _ctx);kk_function_dup(f, _ctx);kk_std_core_types__tuple3_dup(t, _ctx);}, {}, _ctx)
  kk_box_t _y_x10103_19 = _b_x17; /*385*/;
  kk_std_core_types__tuple3 _x_x143 = kk_std_core_tuple_tuple3_fs__mlift_map_10132(_y_x10102, f, t, _y_x10103_19, _ctx); /*(385, 385, 385)*/
  return kk_std_core_types__tuple3_box(_x_x143, _ctx);
}

kk_std_core_types__tuple3 kk_std_core_tuple_tuple3_fs__mlift_map_10133(kk_function_t f, kk_std_core_types__tuple3 t, kk_box_t _y_x10102, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, t : (a, a, a), b) -> e (b, b, b) */ 
  kk_box_t x_10160;
  kk_function_t _x_x140 = kk_function_dup(f, _ctx); /*(384) -> 386 385*/
  kk_box_t _x_x139;
  {
    kk_box_t _x_0 = t.snd;
    kk_box_dup(_x_0, _ctx);
    _x_x139 = _x_0; /*384*/
  }
  x_10160 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x140, (_x_x140, _x_x139, _ctx), _ctx); /*385*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10160, _ctx);
    kk_box_t _x_x141 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs__new_mlift_map_10133_fun142(_y_x10102, f, t, _ctx), _ctx); /*2978*/
    return kk_std_core_types__tuple3_unbox(_x_x141, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_tuple_tuple3_fs__mlift_map_10132(_y_x10102, f, t, x_10160, _ctx);
  }
}
 
// Map a function over a triple of elements of the same type.


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs_map_fun147__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple3 t;
};
static kk_box_t kk_std_core_tuple_tuple3_fs_map_fun147(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs_new_map_fun147(kk_function_t f, kk_std_core_types__tuple3 t, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_map_fun147__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs_map_fun147__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs_map_fun147, kk_context());
  _self->f = f;
  _self->t = t;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs_map_fun147(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_map_fun147__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs_map_fun147__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (384) -> 386 385 */
  kk_std_core_types__tuple3 t = _self->t; /* (384, 384, 384) */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_std_core_types__tuple3_dup(t, _ctx);}, {}, _ctx)
  kk_box_t _y_x10102_29 = _b_x21; /*385*/;
  kk_std_core_types__tuple3 _x_x148 = kk_std_core_tuple_tuple3_fs__mlift_map_10133(f, t, _y_x10102_29, _ctx); /*(385, 385, 385)*/
  return kk_std_core_types__tuple3_box(_x_x148, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs_map_fun152__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple3 t;
  kk_box_t x_10162;
};
static kk_box_t kk_std_core_tuple_tuple3_fs_map_fun152(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs_new_map_fun152(kk_function_t f, kk_std_core_types__tuple3 t, kk_box_t x_10162, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_map_fun152__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs_map_fun152__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs_map_fun152, kk_context());
  _self->f = f;
  _self->t = t;
  _self->x_10162 = x_10162;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs_map_fun152(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_map_fun152__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs_map_fun152__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (384) -> 386 385 */
  kk_std_core_types__tuple3 t = _self->t; /* (384, 384, 384) */
  kk_box_t x_10162 = _self->x_10162; /* 385 */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_std_core_types__tuple3_dup(t, _ctx);kk_box_dup(x_10162, _ctx);}, {}, _ctx)
  kk_box_t _y_x10103_30 = _b_x23; /*385*/;
  kk_std_core_types__tuple3 _x_x153 = kk_std_core_tuple_tuple3_fs__mlift_map_10132(x_10162, f, t, _y_x10103_30, _ctx); /*(385, 385, 385)*/
  return kk_std_core_types__tuple3_box(_x_x153, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs_map_fun156__t {
  struct kk_function_s _base;
  kk_box_t x_0_10165;
  kk_box_t x_10162;
};
static kk_box_t kk_std_core_tuple_tuple3_fs_map_fun156(kk_function_t _fself, kk_box_t _b_x25, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs_new_map_fun156(kk_box_t x_0_10165, kk_box_t x_10162, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_map_fun156__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs_map_fun156__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs_map_fun156, kk_context());
  _self->x_0_10165 = x_0_10165;
  _self->x_10162 = x_10162;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs_map_fun156(kk_function_t _fself, kk_box_t _b_x25, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_map_fun156__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs_map_fun156__t*, _fself, _ctx);
  kk_box_t x_0_10165 = _self->x_0_10165; /* 385 */
  kk_box_t x_10162 = _self->x_10162; /* 385 */
  kk_drop_match(_self, {kk_box_dup(x_0_10165, _ctx);kk_box_dup(x_10162, _ctx);}, {}, _ctx)
  kk_box_t _y_x10104_31 = _b_x25; /*385*/;
  kk_std_core_types__tuple3 _x_x157 = kk_std_core_types__new_Tuple3(x_10162, x_0_10165, _y_x10104_31, _ctx); /*(136, 137, 138)*/
  return kk_std_core_types__tuple3_box(_x_x157, _ctx);
}

kk_std_core_types__tuple3 kk_std_core_tuple_tuple3_fs_map(kk_std_core_types__tuple3 t, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (t : (a, a, a), f : (a) -> e b) -> e (b, b, b) */ 
  kk_box_t x_10162;
  kk_function_t _x_x145 = kk_function_dup(f, _ctx); /*(384) -> 386 385*/
  kk_box_t _x_x144;
  {
    kk_box_t _x = t.fst;
    kk_box_dup(_x, _ctx);
    _x_x144 = _x; /*384*/
  }
  x_10162 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x145, (_x_x145, _x_x144, _ctx), _ctx); /*385*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10162, _ctx);
    kk_box_t _x_x146 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs_new_map_fun147(f, t, _ctx), _ctx); /*2978*/
    return kk_std_core_types__tuple3_unbox(_x_x146, KK_OWNED, _ctx);
  }
  {
    kk_box_t x_0_10165;
    kk_function_t _x_x150 = kk_function_dup(f, _ctx); /*(384) -> 386 385*/
    kk_box_t _x_x149;
    {
      kk_box_t _x_0 = t.snd;
      kk_box_dup(_x_0, _ctx);
      _x_x149 = _x_0; /*384*/
    }
    x_0_10165 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x150, (_x_x150, _x_x149, _ctx), _ctx); /*385*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10165, _ctx);
      kk_box_t _x_x151 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs_new_map_fun152(f, t, x_10162, _ctx), _ctx); /*2978*/
      return kk_std_core_types__tuple3_unbox(_x_x151, KK_OWNED, _ctx);
    }
    {
      kk_box_t x_1_10168;
      kk_box_t _x_x154;
      {
        kk_box_t _x_1 = t.thd;
        kk_box_dup(_x_1, _ctx);
        kk_std_core_types__tuple3_drop(t, _ctx);
        _x_x154 = _x_1; /*384*/
      }
      x_1_10168 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x_x154, _ctx), _ctx); /*385*/
      if (kk_yielding(kk_context())) {
        kk_box_drop(x_1_10168, _ctx);
        kk_box_t _x_x155 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs_new_map_fun156(x_0_10165, x_10162, _ctx), _ctx); /*2978*/
        return kk_std_core_types__tuple3_unbox(_x_x155, KK_OWNED, _ctx);
      }
      {
        return kk_std_core_types__new_Tuple3(x_10162, x_0_10165, x_1_10168, _ctx);
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__mlift_map_10135_fun161__t {
  struct kk_function_s _base;
  kk_box_t _y_x10105;
  kk_box_t _y_x10106;
  kk_box_t _y_x10107;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_map_10135_fun161(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__new_mlift_map_10135_fun161(kk_box_t _y_x10105, kk_box_t _y_x10106, kk_box_t _y_x10107, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_map_10135_fun161__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__mlift_map_10135_fun161__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__mlift_map_10135_fun161, kk_context());
  _self->_y_x10105 = _y_x10105;
  _self->_y_x10106 = _y_x10106;
  _self->_y_x10107 = _y_x10107;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_map_10135_fun161(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_map_10135_fun161__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__mlift_map_10135_fun161__t*, _fself, _ctx);
  kk_box_t _y_x10105 = _self->_y_x10105; /* 572 */
  kk_box_t _y_x10106 = _self->_y_x10106; /* 572 */
  kk_box_t _y_x10107 = _self->_y_x10107; /* 572 */
  kk_drop_match(_self, {kk_box_dup(_y_x10105, _ctx);kk_box_dup(_y_x10106, _ctx);kk_box_dup(_y_x10107, _ctx);}, {}, _ctx)
  kk_box_t _y_x10108_35 = _b_x33; /*572*/;
  kk_std_core_types__tuple4 _x_x162 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _y_x10105, _y_x10106, _y_x10107, _y_x10108_35, _ctx); /*(1708, 1709, 1710, 1711)*/
  return kk_std_core_types__tuple4_box(_x_x162, _ctx);
}

kk_std_core_types__tuple4 kk_std_core_tuple_tuple4_fs__mlift_map_10135(kk_box_t _y_x10105, kk_box_t _y_x10106, kk_function_t f, kk_std_core_types__tuple4 t, kk_box_t _y_x10107, kk_context_t* _ctx) { /* forall<a,b,e> (b, b, f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 
  kk_box_t x_10174;
  kk_box_t _x_x158;
  {
    struct kk_std_core_types_Tuple4* _con_x159 = kk_std_core_types__as_Tuple4(t, _ctx);
    kk_box_t _pat_0_2 = _con_x159->fst;
    kk_box_t _pat_1_2 = _con_x159->snd;
    kk_box_t _pat_2_2 = _con_x159->thd;
    kk_box_t _x_2 = _con_x159->field4;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      kk_box_drop(_pat_2_2, _ctx);
      kk_box_drop(_pat_1_2, _ctx);
      kk_box_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_box_dup(_x_2, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x158 = _x_2; /*571*/
  }
  x_10174 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x_x158, _ctx), _ctx); /*572*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10174, _ctx);
    kk_box_t _x_x160 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__new_mlift_map_10135_fun161(_y_x10105, _y_x10106, _y_x10107, _ctx), _ctx); /*2978*/
    return kk_std_core_types__tuple4_unbox(_x_x160, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _y_x10105, _y_x10106, _y_x10107, x_10174, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__mlift_map_10136_fun167__t {
  struct kk_function_s _base;
  kk_box_t _y_x10105;
  kk_box_t _y_x10106;
  kk_function_t f;
  kk_std_core_types__tuple4 t;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_map_10136_fun167(kk_function_t _fself, kk_box_t _b_x37, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__new_mlift_map_10136_fun167(kk_box_t _y_x10105, kk_box_t _y_x10106, kk_function_t f, kk_std_core_types__tuple4 t, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_map_10136_fun167__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__mlift_map_10136_fun167__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__mlift_map_10136_fun167, kk_context());
  _self->_y_x10105 = _y_x10105;
  _self->_y_x10106 = _y_x10106;
  _self->f = f;
  _self->t = t;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_map_10136_fun167(kk_function_t _fself, kk_box_t _b_x37, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_map_10136_fun167__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__mlift_map_10136_fun167__t*, _fself, _ctx);
  kk_box_t _y_x10105 = _self->_y_x10105; /* 572 */
  kk_box_t _y_x10106 = _self->_y_x10106; /* 572 */
  kk_function_t f = _self->f; /* (571) -> 573 572 */
  kk_std_core_types__tuple4 t = _self->t; /* (571, 571, 571, 571) */
  kk_drop_match(_self, {kk_box_dup(_y_x10105, _ctx);kk_box_dup(_y_x10106, _ctx);kk_function_dup(f, _ctx);kk_std_core_types__tuple4_dup(t, _ctx);}, {}, _ctx)
  kk_box_t _y_x10107_39 = _b_x37; /*572*/;
  kk_std_core_types__tuple4 _x_x168 = kk_std_core_tuple_tuple4_fs__mlift_map_10135(_y_x10105, _y_x10106, f, t, _y_x10107_39, _ctx); /*(572, 572, 572, 572)*/
  return kk_std_core_types__tuple4_box(_x_x168, _ctx);
}

kk_std_core_types__tuple4 kk_std_core_tuple_tuple4_fs__mlift_map_10136(kk_box_t _y_x10105, kk_function_t f, kk_std_core_types__tuple4 t, kk_box_t _y_x10106, kk_context_t* _ctx) { /* forall<a,b,e> (b, f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 
  kk_box_t x_10180;
  kk_function_t _x_x165 = kk_function_dup(f, _ctx); /*(571) -> 573 572*/
  kk_box_t _x_x163;
  {
    struct kk_std_core_types_Tuple4* _con_x164 = kk_std_core_types__as_Tuple4(t, _ctx);
    kk_box_t _x_1 = _con_x164->thd;
    kk_box_dup(_x_1, _ctx);
    _x_x163 = _x_1; /*571*/
  }
  x_10180 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x165, (_x_x165, _x_x163, _ctx), _ctx); /*572*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10180, _ctx);
    kk_box_t _x_x166 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__new_mlift_map_10136_fun167(_y_x10105, _y_x10106, f, t, _ctx), _ctx); /*2978*/
    return kk_std_core_types__tuple4_unbox(_x_x166, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_tuple_tuple4_fs__mlift_map_10135(_y_x10105, _y_x10106, f, t, x_10180, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__mlift_map_10137_fun173__t {
  struct kk_function_s _base;
  kk_box_t _y_x10105;
  kk_function_t f;
  kk_std_core_types__tuple4 t;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_map_10137_fun173(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__new_mlift_map_10137_fun173(kk_box_t _y_x10105, kk_function_t f, kk_std_core_types__tuple4 t, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_map_10137_fun173__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__mlift_map_10137_fun173__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__mlift_map_10137_fun173, kk_context());
  _self->_y_x10105 = _y_x10105;
  _self->f = f;
  _self->t = t;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_map_10137_fun173(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_map_10137_fun173__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__mlift_map_10137_fun173__t*, _fself, _ctx);
  kk_box_t _y_x10105 = _self->_y_x10105; /* 572 */
  kk_function_t f = _self->f; /* (571) -> 573 572 */
  kk_std_core_types__tuple4 t = _self->t; /* (571, 571, 571, 571) */
  kk_drop_match(_self, {kk_box_dup(_y_x10105, _ctx);kk_function_dup(f, _ctx);kk_std_core_types__tuple4_dup(t, _ctx);}, {}, _ctx)
  kk_box_t _y_x10106_43 = _b_x41; /*572*/;
  kk_std_core_types__tuple4 _x_x174 = kk_std_core_tuple_tuple4_fs__mlift_map_10136(_y_x10105, f, t, _y_x10106_43, _ctx); /*(572, 572, 572, 572)*/
  return kk_std_core_types__tuple4_box(_x_x174, _ctx);
}

kk_std_core_types__tuple4 kk_std_core_tuple_tuple4_fs__mlift_map_10137(kk_function_t f, kk_std_core_types__tuple4 t, kk_box_t _y_x10105, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 
  kk_box_t x_10182;
  kk_function_t _x_x171 = kk_function_dup(f, _ctx); /*(571) -> 573 572*/
  kk_box_t _x_x169;
  {
    struct kk_std_core_types_Tuple4* _con_x170 = kk_std_core_types__as_Tuple4(t, _ctx);
    kk_box_t _x_0 = _con_x170->snd;
    kk_box_dup(_x_0, _ctx);
    _x_x169 = _x_0; /*571*/
  }
  x_10182 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x171, (_x_x171, _x_x169, _ctx), _ctx); /*572*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10182, _ctx);
    kk_box_t _x_x172 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__new_mlift_map_10137_fun173(_y_x10105, f, t, _ctx), _ctx); /*2978*/
    return kk_std_core_types__tuple4_unbox(_x_x172, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_tuple_tuple4_fs__mlift_map_10136(_y_x10105, f, t, x_10182, _ctx);
  }
}
 
// Map a function over a quadruple of elements of the same type.


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_map_fun179__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple4 t;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_map_fun179(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_map_fun179(kk_function_t f, kk_std_core_types__tuple4 t, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_map_fun179__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_map_fun179__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_map_fun179, kk_context());
  _self->f = f;
  _self->t = t;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_map_fun179(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_map_fun179__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_map_fun179__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (571) -> 573 572 */
  kk_std_core_types__tuple4 t = _self->t; /* (571, 571, 571, 571) */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_std_core_types__tuple4_dup(t, _ctx);}, {}, _ctx)
  kk_box_t _y_x10105_56 = _b_x45; /*572*/;
  kk_std_core_types__tuple4 _x_x180 = kk_std_core_tuple_tuple4_fs__mlift_map_10137(f, t, _y_x10105_56, _ctx); /*(572, 572, 572, 572)*/
  return kk_std_core_types__tuple4_box(_x_x180, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_map_fun185__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple4 t;
  kk_box_t x_10184;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_map_fun185(kk_function_t _fself, kk_box_t _b_x47, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_map_fun185(kk_function_t f, kk_std_core_types__tuple4 t, kk_box_t x_10184, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_map_fun185__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_map_fun185__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_map_fun185, kk_context());
  _self->f = f;
  _self->t = t;
  _self->x_10184 = x_10184;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_map_fun185(kk_function_t _fself, kk_box_t _b_x47, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_map_fun185__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_map_fun185__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (571) -> 573 572 */
  kk_std_core_types__tuple4 t = _self->t; /* (571, 571, 571, 571) */
  kk_box_t x_10184 = _self->x_10184; /* 572 */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_std_core_types__tuple4_dup(t, _ctx);kk_box_dup(x_10184, _ctx);}, {}, _ctx)
  kk_box_t _y_x10106_57 = _b_x47; /*572*/;
  kk_std_core_types__tuple4 _x_x186 = kk_std_core_tuple_tuple4_fs__mlift_map_10136(x_10184, f, t, _y_x10106_57, _ctx); /*(572, 572, 572, 572)*/
  return kk_std_core_types__tuple4_box(_x_x186, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_map_fun191__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple4 t;
  kk_box_t x_0_10187;
  kk_box_t x_10184;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_map_fun191(kk_function_t _fself, kk_box_t _b_x49, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_map_fun191(kk_function_t f, kk_std_core_types__tuple4 t, kk_box_t x_0_10187, kk_box_t x_10184, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_map_fun191__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_map_fun191__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_map_fun191, kk_context());
  _self->f = f;
  _self->t = t;
  _self->x_0_10187 = x_0_10187;
  _self->x_10184 = x_10184;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_map_fun191(kk_function_t _fself, kk_box_t _b_x49, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_map_fun191__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_map_fun191__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (571) -> 573 572 */
  kk_std_core_types__tuple4 t = _self->t; /* (571, 571, 571, 571) */
  kk_box_t x_0_10187 = _self->x_0_10187; /* 572 */
  kk_box_t x_10184 = _self->x_10184; /* 572 */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_std_core_types__tuple4_dup(t, _ctx);kk_box_dup(x_0_10187, _ctx);kk_box_dup(x_10184, _ctx);}, {}, _ctx)
  kk_box_t _y_x10107_58 = _b_x49; /*572*/;
  kk_std_core_types__tuple4 _x_x192 = kk_std_core_tuple_tuple4_fs__mlift_map_10135(x_10184, x_0_10187, f, t, _y_x10107_58, _ctx); /*(572, 572, 572, 572)*/
  return kk_std_core_types__tuple4_box(_x_x192, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_map_fun196__t {
  struct kk_function_s _base;
  kk_box_t x_0_10187;
  kk_box_t x_10184;
  kk_box_t x_1_10190;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_map_fun196(kk_function_t _fself, kk_box_t _b_x51, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_map_fun196(kk_box_t x_0_10187, kk_box_t x_10184, kk_box_t x_1_10190, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_map_fun196__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_map_fun196__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_map_fun196, kk_context());
  _self->x_0_10187 = x_0_10187;
  _self->x_10184 = x_10184;
  _self->x_1_10190 = x_1_10190;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_map_fun196(kk_function_t _fself, kk_box_t _b_x51, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_map_fun196__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_map_fun196__t*, _fself, _ctx);
  kk_box_t x_0_10187 = _self->x_0_10187; /* 572 */
  kk_box_t x_10184 = _self->x_10184; /* 572 */
  kk_box_t x_1_10190 = _self->x_1_10190; /* 572 */
  kk_drop_match(_self, {kk_box_dup(x_0_10187, _ctx);kk_box_dup(x_10184, _ctx);kk_box_dup(x_1_10190, _ctx);}, {}, _ctx)
  kk_box_t _y_x10108_59 = _b_x51; /*572*/;
  kk_std_core_types__tuple4 _x_x197 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, x_10184, x_0_10187, x_1_10190, _y_x10108_59, _ctx); /*(1708, 1709, 1710, 1711)*/
  return kk_std_core_types__tuple4_box(_x_x197, _ctx);
}

kk_std_core_types__tuple4 kk_std_core_tuple_tuple4_fs_map(kk_std_core_types__tuple4 t, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (t : (a, a, a, a), f : (a) -> e b) -> e (b, b, b, b) */ 
  kk_box_t x_10184;
  kk_function_t _x_x177 = kk_function_dup(f, _ctx); /*(571) -> 573 572*/
  kk_box_t _x_x175;
  {
    struct kk_std_core_types_Tuple4* _con_x176 = kk_std_core_types__as_Tuple4(t, _ctx);
    kk_box_t _x = _con_x176->fst;
    kk_box_dup(_x, _ctx);
    _x_x175 = _x; /*571*/
  }
  x_10184 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x177, (_x_x177, _x_x175, _ctx), _ctx); /*572*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10184, _ctx);
    kk_box_t _x_x178 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs_new_map_fun179(f, t, _ctx), _ctx); /*2978*/
    return kk_std_core_types__tuple4_unbox(_x_x178, KK_OWNED, _ctx);
  }
  {
    kk_box_t x_0_10187;
    kk_function_t _x_x183 = kk_function_dup(f, _ctx); /*(571) -> 573 572*/
    kk_box_t _x_x181;
    {
      struct kk_std_core_types_Tuple4* _con_x182 = kk_std_core_types__as_Tuple4(t, _ctx);
      kk_box_t _x_0 = _con_x182->snd;
      kk_box_dup(_x_0, _ctx);
      _x_x181 = _x_0; /*571*/
    }
    x_0_10187 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x183, (_x_x183, _x_x181, _ctx), _ctx); /*572*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10187, _ctx);
      kk_box_t _x_x184 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs_new_map_fun185(f, t, x_10184, _ctx), _ctx); /*2978*/
      return kk_std_core_types__tuple4_unbox(_x_x184, KK_OWNED, _ctx);
    }
    {
      kk_box_t x_1_10190;
      kk_function_t _x_x189 = kk_function_dup(f, _ctx); /*(571) -> 573 572*/
      kk_box_t _x_x187;
      {
        struct kk_std_core_types_Tuple4* _con_x188 = kk_std_core_types__as_Tuple4(t, _ctx);
        kk_box_t _x_1 = _con_x188->thd;
        kk_box_dup(_x_1, _ctx);
        _x_x187 = _x_1; /*571*/
      }
      x_1_10190 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x189, (_x_x189, _x_x187, _ctx), _ctx); /*572*/
      if (kk_yielding(kk_context())) {
        kk_box_drop(x_1_10190, _ctx);
        kk_box_t _x_x190 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs_new_map_fun191(f, t, x_0_10187, x_10184, _ctx), _ctx); /*2978*/
        return kk_std_core_types__tuple4_unbox(_x_x190, KK_OWNED, _ctx);
      }
      {
        kk_box_t x_2_10193;
        kk_box_t _x_x193;
        {
          struct kk_std_core_types_Tuple4* _con_x194 = kk_std_core_types__as_Tuple4(t, _ctx);
          kk_box_t _pat_0_2_0 = _con_x194->fst;
          kk_box_t _pat_1_2 = _con_x194->snd;
          kk_box_t _pat_2_2 = _con_x194->thd;
          kk_box_t _x_2 = _con_x194->field4;
          if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
            kk_box_drop(_pat_2_2, _ctx);
            kk_box_drop(_pat_1_2, _ctx);
            kk_box_drop(_pat_0_2_0, _ctx);
            kk_datatype_ptr_free(t, _ctx);
          }
          else {
            kk_box_dup(_x_2, _ctx);
            kk_datatype_ptr_decref(t, _ctx);
          }
          _x_x193 = _x_2; /*571*/
        }
        x_2_10193 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x_x193, _ctx), _ctx); /*572*/
        if (kk_yielding(kk_context())) {
          kk_box_drop(x_2_10193, _ctx);
          kk_box_t _x_x195 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs_new_map_fun196(x_0_10187, x_10184, x_1_10190, _ctx), _ctx); /*2978*/
          return kk_std_core_types__tuple4_unbox(_x_x195, KK_OWNED, _ctx);
        }
        {
          return kk_std_core_types__new_Tuple4(kk_reuse_null, 0, x_10184, x_0_10187, x_1_10190, x_2_10193, _ctx);
        }
      }
    }
  }
}
 
// Element-wise tuple equality

bool kk_std_core_tuple_tuple2_fs__lp__eq__eq__rp_(kk_std_core_types__tuple2 _pat_x29__22, kk_std_core_types__tuple2 _pat_x29__39, kk_function_t _implicit_fs_fst_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_context_t* _ctx) { /* forall<a,b> ((a, b), (a, b), ?fst/(==) : (a, a) -> bool, ?snd/(==) : (b, b) -> bool) -> bool */ 
  {
    kk_box_t x1 = _pat_x29__22.fst;
    kk_box_t y1 = _pat_x29__22.snd;
    {
      kk_box_t x2 = _pat_x29__39.fst;
      kk_box_t y2 = _pat_x29__39.snd;
      bool _match_x104 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_fst_fs__lp__eq__eq__rp_, (_implicit_fs_fst_fs__lp__eq__eq__rp_, x1, x2, _ctx), _ctx); /*bool*/;
      if (_match_x104) {
        return kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs__lp__eq__eq__rp_, (_implicit_fs_snd_fs__lp__eq__eq__rp_, y1, y2, _ctx), _ctx);
      }
      {
        kk_function_drop(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);
        kk_box_drop(y2, _ctx);
        kk_box_drop(y1, _ctx);
        return false;
      }
    }
  }
}
 
// Element-wise triple equality

bool kk_std_core_tuple_tuple3_fs__lp__eq__eq__rp_(kk_std_core_types__tuple3 _pat_x33__22, kk_std_core_types__tuple3 _pat_x33__44, kk_function_t _implicit_fs_fst_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_context_t* _ctx) { /* forall<a,b,c> ((a, b, c), (a, b, c), ?fst/(==) : (a, a) -> bool, ?snd/(==) : (b, b) -> bool, ?thd/(==) : (c, c) -> bool) -> bool */ 
  {
    kk_box_t x1 = _pat_x33__22.fst;
    kk_box_t y1 = _pat_x33__22.snd;
    kk_box_t z1 = _pat_x33__22.thd;
    {
      kk_box_t x2 = _pat_x33__44.fst;
      kk_box_t y2 = _pat_x33__44.snd;
      kk_box_t z2 = _pat_x33__44.thd;
      bool _match_x102 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_fst_fs__lp__eq__eq__rp_, (_implicit_fs_fst_fs__lp__eq__eq__rp_, x1, x2, _ctx), _ctx); /*bool*/;
      if (_match_x102) {
        bool _match_x103 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs__lp__eq__eq__rp_, (_implicit_fs_snd_fs__lp__eq__eq__rp_, y1, y2, _ctx), _ctx); /*bool*/;
        if (_match_x103) {
          return kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs__lp__eq__eq__rp_, (_implicit_fs_thd_fs__lp__eq__eq__rp_, z1, z2, _ctx), _ctx);
        }
        {
          kk_function_drop(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);
          kk_box_drop(z2, _ctx);
          kk_box_drop(z1, _ctx);
          return false;
        }
      }
      {
        kk_function_drop(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);
        kk_function_drop(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);
        kk_box_drop(z2, _ctx);
        kk_box_drop(z1, _ctx);
        kk_box_drop(y2, _ctx);
        kk_box_drop(y1, _ctx);
        return false;
      }
    }
  }
}
 
// Order on tuples

kk_std_core_types__order kk_std_core_tuple_tuple2_fs_cmp(kk_std_core_types__tuple2 _pat_x38__21, kk_std_core_types__tuple2 _pat_x38__38, kk_function_t _implicit_fs_fst_fs_cmp, kk_function_t _implicit_fs_snd_fs_cmp, kk_context_t* _ctx) { /* forall<a,b> ((a, b), (a, b), ?fst/cmp : (a, a) -> order, ?snd/cmp : (b, b) -> order) -> order */ 
  {
    kk_box_t x1 = _pat_x38__21.fst;
    kk_box_t y1 = _pat_x38__21.snd;
    {
      kk_box_t x2 = _pat_x38__38.fst;
      kk_box_t y2 = _pat_x38__38.snd;
      kk_std_core_types__order _match_x101 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_fst_fs_cmp, (_implicit_fs_fst_fs_cmp, x1, x2, _ctx), _ctx); /*order*/;
      if (kk_std_core_types__is_Eq(_match_x101, _ctx)) {
        return kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_cmp, (_implicit_fs_snd_fs_cmp, y1, y2, _ctx), _ctx);
      }
      {
        kk_function_drop(_implicit_fs_snd_fs_cmp, _ctx);
        kk_box_drop(y2, _ctx);
        kk_box_drop(y1, _ctx);
        return _match_x101;
      }
    }
  }
}
 
// Order on triples

kk_std_core_types__order kk_std_core_tuple_tuple3_fs_cmp(kk_std_core_types__tuple3 _pat_x44__26, kk_std_core_types__tuple3 _pat_x44__48, kk_function_t _implicit_fs_fst_fs_cmp, kk_function_t _implicit_fs_snd_fs_cmp, kk_function_t _implicit_fs_thd_fs_cmp, kk_context_t* _ctx) { /* forall<a,b,c> ((a, b, c), (a, b, c), ?fst/cmp : (a, a) -> order, ?snd/cmp : (b, b) -> order, ?thd/cmp : (c, c) -> order) -> order */ 
  {
    kk_box_t x1 = _pat_x44__26.fst;
    kk_box_t y1 = _pat_x44__26.snd;
    kk_box_t z1 = _pat_x44__26.thd;
    {
      kk_box_t x2 = _pat_x44__48.fst;
      kk_box_t y2 = _pat_x44__48.snd;
      kk_box_t z2 = _pat_x44__48.thd;
      kk_std_core_types__order _match_x99;
      kk_function_t _x_x198 = kk_function_dup(_implicit_fs_fst_fs_cmp, _ctx); /*(833, 833) -> order*/
      _match_x99 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x198, (_x_x198, x1, x2, _ctx), _ctx); /*order*/
      if (kk_std_core_types__is_Eq(_match_x99, _ctx)) {
        kk_std_core_types__order _match_x100;
        kk_function_t _x_x199 = kk_function_dup(_implicit_fs_snd_fs_cmp, _ctx); /*(834, 834) -> order*/
        _match_x100 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x199, (_x_x199, y1, y2, _ctx), _ctx); /*order*/
        if (kk_std_core_types__is_Eq(_match_x100, _ctx)) {
          kk_function_t _x_x200 = kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx); /*(835, 835) -> order*/
          return kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x200, (_x_x200, z1, z2, _ctx), _ctx);
        }
        {
          kk_box_drop(z2, _ctx);
          kk_box_drop(z1, _ctx);
          return _match_x100;
        }
      }
      {
        kk_box_drop(z2, _ctx);
        kk_box_drop(z1, _ctx);
        kk_box_drop(y2, _ctx);
        kk_box_drop(y1, _ctx);
        return _match_x99;
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs__mlift_show_10139_fun212__t {
  struct kk_function_s _base;
  kk_string_t _y_x10109;
};
static kk_string_t kk_std_core_tuple_tuple2_fs__mlift_show_10139_fun212(kk_function_t _fself, kk_string_t _y_x10110, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs__new_mlift_show_10139_fun212(kk_string_t _y_x10109, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs__mlift_show_10139_fun212__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs__mlift_show_10139_fun212__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs__mlift_show_10139_fun212, kk_context());
  _self->_y_x10109 = _y_x10109;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_string_t kk_std_core_tuple_tuple2_fs__mlift_show_10139_fun212(kk_function_t _fself, kk_string_t _y_x10110, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs__mlift_show_10139_fun212__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs__mlift_show_10139_fun212__t*, _fself, _ctx);
  kk_string_t _y_x10109 = _self->_y_x10109; /* string */
  kk_drop_match(_self, {kk_string_dup(_y_x10109, _ctx);}, {}, _ctx)
  kk_string_t _x_x213;
  kk_define_string_literal(, _s_x214, 1, "(", _ctx)
  _x_x213 = kk_string_dup(_s_x214, _ctx); /*string*/
  kk_string_t _x_x215;
  kk_string_t _x_x216;
  kk_string_t _x_x217;
  kk_define_string_literal(, _s_x218, 1, ",", _ctx)
  _x_x217 = kk_string_dup(_s_x218, _ctx); /*string*/
  kk_string_t _x_x219;
  kk_string_t _x_x220;
  kk_define_string_literal(, _s_x221, 1, ")", _ctx)
  _x_x220 = kk_string_dup(_s_x221, _ctx); /*string*/
  _x_x219 = kk_std_core_types__lp__plus__plus__rp_(_y_x10110, _x_x220, _ctx); /*string*/
  _x_x216 = kk_std_core_types__lp__plus__plus__rp_(_x_x217, _x_x219, _ctx); /*string*/
  _x_x215 = kk_std_core_types__lp__plus__plus__rp_(_y_x10109, _x_x216, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x213, _x_x215, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs__mlift_show_10139_fun223__t {
  struct kk_function_s _base;
  kk_function_t next_10201;
};
static kk_box_t kk_std_core_tuple_tuple2_fs__mlift_show_10139_fun223(kk_function_t _fself, kk_box_t _b_x61, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs__new_mlift_show_10139_fun223(kk_function_t next_10201, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs__mlift_show_10139_fun223__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs__mlift_show_10139_fun223__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs__mlift_show_10139_fun223, kk_context());
  _self->next_10201 = next_10201;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple2_fs__mlift_show_10139_fun223(kk_function_t _fself, kk_box_t _b_x61, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs__mlift_show_10139_fun223__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs__mlift_show_10139_fun223__t*, _fself, _ctx);
  kk_function_t next_10201 = _self->next_10201; /* (string) -> 1018 string */
  kk_drop_match(_self, {kk_function_dup(next_10201, _ctx);}, {}, _ctx)
  kk_string_t _x_x224;
  kk_string_t _x_x225 = kk_string_unbox(_b_x61); /*string*/
  _x_x224 = kk_function_call(kk_string_t, (kk_function_t, kk_string_t, kk_context_t*), next_10201, (next_10201, _x_x225, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x224);
}

kk_string_t kk_std_core_tuple_tuple2_fs__mlift_show_10139(kk_std_core_types__tuple2 x, kk_function_t _implicit_fs_snd_fs_show, kk_string_t _y_x10109, kk_context_t* _ctx) { /* forall<a,b,e> (x : (a, b), ?snd/show : (b) -> e string, string) -> e string */ 
  kk_string_t x_0_10200;
  kk_box_t _x_x211;
  {
    kk_box_t _x_0 = x.snd;
    kk_box_dup(_x_0, _ctx);
    kk_std_core_types__tuple2_drop(x, _ctx);
    _x_x211 = _x_0; /*1017*/
  }
  x_0_10200 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_show, (_implicit_fs_snd_fs_show, _x_x211, _ctx), _ctx); /*string*/
  kk_function_t next_10201 = kk_std_core_tuple_tuple2_fs__new_mlift_show_10139_fun212(_y_x10109, _ctx); /*(string) -> 1018 string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10200, _ctx);
    kk_box_t _x_x222 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple2_fs__new_mlift_show_10139_fun223(next_10201, _ctx), _ctx); /*2978*/
    return kk_string_unbox(_x_x222);
  }
  {
    return kk_function_call(kk_string_t, (kk_function_t, kk_string_t, kk_context_t*), next_10201, (next_10201, x_0_10200, _ctx), _ctx);
  }
}
 
// Show a tuple


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs_show_fun228__t {
  struct kk_function_s _base;
  kk_std_core_types__tuple2 x;
  kk_function_t _implicit_fs_snd_fs_show;
};
static kk_box_t kk_std_core_tuple_tuple2_fs_show_fun228(kk_function_t _fself, kk_box_t _b_x64, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs_new_show_fun228(kk_std_core_types__tuple2 x, kk_function_t _implicit_fs_snd_fs_show, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_show_fun228__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs_show_fun228__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs_show_fun228, kk_context());
  _self->x = x;
  _self->_implicit_fs_snd_fs_show = _implicit_fs_snd_fs_show;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple2_fs_show_fun228(kk_function_t _fself, kk_box_t _b_x64, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_show_fun228__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs_show_fun228__t*, _fself, _ctx);
  kk_std_core_types__tuple2 x = _self->x; /* (1016, 1017) */
  kk_function_t _implicit_fs_snd_fs_show = _self->_implicit_fs_snd_fs_show; /* (1017) -> 1018 string */
  kk_drop_match(_self, {kk_std_core_types__tuple2_dup(x, _ctx);kk_function_dup(_implicit_fs_snd_fs_show, _ctx);}, {}, _ctx)
  kk_string_t _y_x10109_69 = kk_string_unbox(_b_x64); /*string*/;
  kk_string_t _x_x229 = kk_std_core_tuple_tuple2_fs__mlift_show_10139(x, _implicit_fs_snd_fs_show, _y_x10109_69, _ctx); /*string*/
  return kk_string_box(_x_x229);
}


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs_show_fun232__t {
  struct kk_function_s _base;
  kk_string_t x_0_10204;
};
static kk_box_t kk_std_core_tuple_tuple2_fs_show_fun232(kk_function_t _fself, kk_box_t _b_x66, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs_new_show_fun232(kk_string_t x_0_10204, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_show_fun232__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs_show_fun232__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs_show_fun232, kk_context());
  _self->x_0_10204 = x_0_10204;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple2_fs_show_fun232(kk_function_t _fself, kk_box_t _b_x66, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_show_fun232__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs_show_fun232__t*, _fself, _ctx);
  kk_string_t x_0_10204 = _self->x_0_10204; /* string */
  kk_drop_match(_self, {kk_string_dup(x_0_10204, _ctx);}, {}, _ctx)
  kk_string_t _y_x10110_70 = kk_string_unbox(_b_x66); /*string*/;
  kk_string_t _x_x233;
  kk_string_t _x_x234;
  kk_define_string_literal(, _s_x235, 1, "(", _ctx)
  _x_x234 = kk_string_dup(_s_x235, _ctx); /*string*/
  kk_string_t _x_x236;
  kk_string_t _x_x237;
  kk_string_t _x_x238;
  kk_define_string_literal(, _s_x239, 1, ",", _ctx)
  _x_x238 = kk_string_dup(_s_x239, _ctx); /*string*/
  kk_string_t _x_x240;
  kk_string_t _x_x241;
  kk_define_string_literal(, _s_x242, 1, ")", _ctx)
  _x_x241 = kk_string_dup(_s_x242, _ctx); /*string*/
  _x_x240 = kk_std_core_types__lp__plus__plus__rp_(_y_x10110_70, _x_x241, _ctx); /*string*/
  _x_x237 = kk_std_core_types__lp__plus__plus__rp_(_x_x238, _x_x240, _ctx); /*string*/
  _x_x236 = kk_std_core_types__lp__plus__plus__rp_(x_0_10204, _x_x237, _ctx); /*string*/
  _x_x233 = kk_std_core_types__lp__plus__plus__rp_(_x_x234, _x_x236, _ctx); /*string*/
  return kk_string_box(_x_x233);
}

kk_string_t kk_std_core_tuple_tuple2_fs_show(kk_std_core_types__tuple2 x, kk_function_t _implicit_fs_fst_fs_show, kk_function_t _implicit_fs_snd_fs_show, kk_context_t* _ctx) { /* forall<a,b,e> (x : (a, b), ?fst/show : (a) -> e string, ?snd/show : (b) -> e string) -> e string */ 
  kk_string_t x_0_10204;
  kk_box_t _x_x226;
  {
    kk_box_t _x = x.fst;
    kk_box_dup(_x, _ctx);
    _x_x226 = _x; /*1016*/
  }
  x_0_10204 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_fst_fs_show, (_implicit_fs_fst_fs_show, _x_x226, _ctx), _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10204, _ctx);
    kk_box_t _x_x227 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple2_fs_new_show_fun228(x, _implicit_fs_snd_fs_show, _ctx), _ctx); /*2978*/
    return kk_string_unbox(_x_x227);
  }
  {
    kk_string_t x_1_10207;
    kk_box_t _x_x230;
    {
      kk_box_t _x_0 = x.snd;
      kk_box_dup(_x_0, _ctx);
      kk_std_core_types__tuple2_drop(x, _ctx);
      _x_x230 = _x_0; /*1017*/
    }
    x_1_10207 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_show, (_implicit_fs_snd_fs_show, _x_x230, _ctx), _ctx); /*string*/
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_1_10207, _ctx);
      kk_box_t _x_x231 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple2_fs_new_show_fun232(x_0_10204, _ctx), _ctx); /*2978*/
      return kk_string_unbox(_x_x231);
    }
    {
      kk_string_t _x_x243;
      kk_define_string_literal(, _s_x244, 1, "(", _ctx)
      _x_x243 = kk_string_dup(_s_x244, _ctx); /*string*/
      kk_string_t _x_x245;
      kk_string_t _x_x246;
      kk_string_t _x_x247;
      kk_define_string_literal(, _s_x248, 1, ",", _ctx)
      _x_x247 = kk_string_dup(_s_x248, _ctx); /*string*/
      kk_string_t _x_x249;
      kk_string_t _x_x250;
      kk_define_string_literal(, _s_x251, 1, ")", _ctx)
      _x_x250 = kk_string_dup(_s_x251, _ctx); /*string*/
      _x_x249 = kk_std_core_types__lp__plus__plus__rp_(x_1_10207, _x_x250, _ctx); /*string*/
      _x_x246 = kk_std_core_types__lp__plus__plus__rp_(_x_x247, _x_x249, _ctx); /*string*/
      _x_x245 = kk_std_core_types__lp__plus__plus__rp_(x_0_10204, _x_x246, _ctx); /*string*/
      return kk_std_core_types__lp__plus__plus__rp_(_x_x243, _x_x245, _ctx);
    }
  }
}
 
// monadic lift

kk_string_t kk_std_core_tuple_tuple3_fs__mlift_show_10140(kk_string_t _y_x10111, kk_string_t _y_x10112, kk_string_t _y_x10113, kk_context_t* _ctx) { /* forall<e> (string, string, string) -> e string */ 
  kk_string_t _x_x252;
  kk_define_string_literal(, _s_x253, 1, "(", _ctx)
  _x_x252 = kk_string_dup(_s_x253, _ctx); /*string*/
  kk_string_t _x_x254;
  kk_string_t _x_x255;
  kk_string_t _x_x256;
  kk_define_string_literal(, _s_x257, 1, ",", _ctx)
  _x_x256 = kk_string_dup(_s_x257, _ctx); /*string*/
  kk_string_t _x_x258;
  kk_string_t _x_x259;
  kk_string_t _x_x260;
  kk_define_string_literal(, _s_x261, 1, ",", _ctx)
  _x_x260 = kk_string_dup(_s_x261, _ctx); /*string*/
  kk_string_t _x_x262;
  kk_string_t _x_x263;
  kk_define_string_literal(, _s_x264, 1, ")", _ctx)
  _x_x263 = kk_string_dup(_s_x264, _ctx); /*string*/
  _x_x262 = kk_std_core_types__lp__plus__plus__rp_(_y_x10113, _x_x263, _ctx); /*string*/
  _x_x259 = kk_std_core_types__lp__plus__plus__rp_(_x_x260, _x_x262, _ctx); /*string*/
  _x_x258 = kk_std_core_types__lp__plus__plus__rp_(_y_x10112, _x_x259, _ctx); /*string*/
  _x_x255 = kk_std_core_types__lp__plus__plus__rp_(_x_x256, _x_x258, _ctx); /*string*/
  _x_x254 = kk_std_core_types__lp__plus__plus__rp_(_y_x10111, _x_x255, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x252, _x_x254, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs__mlift_show_10141_fun267__t {
  struct kk_function_s _base;
  kk_string_t _y_x10111;
  kk_string_t _y_x10112;
};
static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_show_10141_fun267(kk_function_t _fself, kk_box_t _b_x72, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs__new_mlift_show_10141_fun267(kk_string_t _y_x10111, kk_string_t _y_x10112, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_show_10141_fun267__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs__mlift_show_10141_fun267__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs__mlift_show_10141_fun267, kk_context());
  _self->_y_x10111 = _y_x10111;
  _self->_y_x10112 = _y_x10112;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_show_10141_fun267(kk_function_t _fself, kk_box_t _b_x72, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_show_10141_fun267__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs__mlift_show_10141_fun267__t*, _fself, _ctx);
  kk_string_t _y_x10111 = _self->_y_x10111; /* string */
  kk_string_t _y_x10112 = _self->_y_x10112; /* string */
  kk_drop_match(_self, {kk_string_dup(_y_x10111, _ctx);kk_string_dup(_y_x10112, _ctx);}, {}, _ctx)
  kk_string_t _y_x10113_74 = kk_string_unbox(_b_x72); /*string*/;
  kk_string_t _x_x268 = kk_std_core_tuple_tuple3_fs__mlift_show_10140(_y_x10111, _y_x10112, _y_x10113_74, _ctx); /*string*/
  return kk_string_box(_x_x268);
}

kk_string_t kk_std_core_tuple_tuple3_fs__mlift_show_10141(kk_string_t _y_x10111, kk_std_core_types__tuple3 x, kk_function_t _implicit_fs_thd_fs_show, kk_string_t _y_x10112, kk_context_t* _ctx) { /* forall<a,b,c,e> (string, x : (a, b, c), ?thd/show : (c) -> e string, string) -> e string */ 
  kk_string_t x_0_10212;
  kk_box_t _x_x265;
  {
    kk_box_t _x_1 = x.thd;
    kk_box_dup(_x_1, _ctx);
    kk_std_core_types__tuple3_drop(x, _ctx);
    _x_x265 = _x_1; /*1259*/
  }
  x_0_10212 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs_show, (_implicit_fs_thd_fs_show, _x_x265, _ctx), _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10212, _ctx);
    kk_box_t _x_x266 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs__new_mlift_show_10141_fun267(_y_x10111, _y_x10112, _ctx), _ctx); /*2978*/
    return kk_string_unbox(_x_x266);
  }
  {
    return kk_std_core_tuple_tuple3_fs__mlift_show_10140(_y_x10111, _y_x10112, x_0_10212, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs__mlift_show_10142_fun271__t {
  struct kk_function_s _base;
  kk_string_t _y_x10111;
  kk_std_core_types__tuple3 x;
  kk_function_t _implicit_fs_thd_fs_show;
};
static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_show_10142_fun271(kk_function_t _fself, kk_box_t _b_x76, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs__new_mlift_show_10142_fun271(kk_string_t _y_x10111, kk_std_core_types__tuple3 x, kk_function_t _implicit_fs_thd_fs_show, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_show_10142_fun271__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs__mlift_show_10142_fun271__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs__mlift_show_10142_fun271, kk_context());
  _self->_y_x10111 = _y_x10111;
  _self->x = x;
  _self->_implicit_fs_thd_fs_show = _implicit_fs_thd_fs_show;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_show_10142_fun271(kk_function_t _fself, kk_box_t _b_x76, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_show_10142_fun271__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs__mlift_show_10142_fun271__t*, _fself, _ctx);
  kk_string_t _y_x10111 = _self->_y_x10111; /* string */
  kk_std_core_types__tuple3 x = _self->x; /* (1257, 1258, 1259) */
  kk_function_t _implicit_fs_thd_fs_show = _self->_implicit_fs_thd_fs_show; /* (1259) -> 1260 string */
  kk_drop_match(_self, {kk_string_dup(_y_x10111, _ctx);kk_std_core_types__tuple3_dup(x, _ctx);kk_function_dup(_implicit_fs_thd_fs_show, _ctx);}, {}, _ctx)
  kk_string_t _y_x10112_78 = kk_string_unbox(_b_x76); /*string*/;
  kk_string_t _x_x272 = kk_std_core_tuple_tuple3_fs__mlift_show_10141(_y_x10111, x, _implicit_fs_thd_fs_show, _y_x10112_78, _ctx); /*string*/
  return kk_string_box(_x_x272);
}

kk_string_t kk_std_core_tuple_tuple3_fs__mlift_show_10142(kk_std_core_types__tuple3 x, kk_function_t _implicit_fs_snd_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_string_t _y_x10111, kk_context_t* _ctx) { /* forall<a,b,c,e> (x : (a, b, c), ?snd/show : (b) -> e string, ?thd/show : (c) -> e string, string) -> e string */ 
  kk_string_t x_0_10214;
  kk_box_t _x_x269;
  {
    kk_box_t _x_0 = x.snd;
    kk_box_dup(_x_0, _ctx);
    _x_x269 = _x_0; /*1258*/
  }
  x_0_10214 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_show, (_implicit_fs_snd_fs_show, _x_x269, _ctx), _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10214, _ctx);
    kk_box_t _x_x270 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs__new_mlift_show_10142_fun271(_y_x10111, x, _implicit_fs_thd_fs_show, _ctx), _ctx); /*2978*/
    return kk_string_unbox(_x_x270);
  }
  {
    return kk_std_core_tuple_tuple3_fs__mlift_show_10141(_y_x10111, x, _implicit_fs_thd_fs_show, x_0_10214, _ctx);
  }
}
 
// Show a triple


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs_show_fun275__t {
  struct kk_function_s _base;
  kk_std_core_types__tuple3 x;
  kk_function_t _implicit_fs_snd_fs_show;
  kk_function_t _implicit_fs_thd_fs_show;
};
static kk_box_t kk_std_core_tuple_tuple3_fs_show_fun275(kk_function_t _fself, kk_box_t _b_x80, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs_new_show_fun275(kk_std_core_types__tuple3 x, kk_function_t _implicit_fs_snd_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_show_fun275__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs_show_fun275__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs_show_fun275, kk_context());
  _self->x = x;
  _self->_implicit_fs_snd_fs_show = _implicit_fs_snd_fs_show;
  _self->_implicit_fs_thd_fs_show = _implicit_fs_thd_fs_show;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs_show_fun275(kk_function_t _fself, kk_box_t _b_x80, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_show_fun275__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs_show_fun275__t*, _fself, _ctx);
  kk_std_core_types__tuple3 x = _self->x; /* (1257, 1258, 1259) */
  kk_function_t _implicit_fs_snd_fs_show = _self->_implicit_fs_snd_fs_show; /* (1258) -> 1260 string */
  kk_function_t _implicit_fs_thd_fs_show = _self->_implicit_fs_thd_fs_show; /* (1259) -> 1260 string */
  kk_drop_match(_self, {kk_std_core_types__tuple3_dup(x, _ctx);kk_function_dup(_implicit_fs_snd_fs_show, _ctx);kk_function_dup(_implicit_fs_thd_fs_show, _ctx);}, {}, _ctx)
  kk_string_t _y_x10111_88 = kk_string_unbox(_b_x80); /*string*/;
  kk_string_t _x_x276 = kk_std_core_tuple_tuple3_fs__mlift_show_10142(x, _implicit_fs_snd_fs_show, _implicit_fs_thd_fs_show, _y_x10111_88, _ctx); /*string*/
  return kk_string_box(_x_x276);
}


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs_show_fun279__t {
  struct kk_function_s _base;
  kk_std_core_types__tuple3 x;
  kk_string_t x_0_10216;
  kk_function_t _implicit_fs_thd_fs_show;
};
static kk_box_t kk_std_core_tuple_tuple3_fs_show_fun279(kk_function_t _fself, kk_box_t _b_x82, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs_new_show_fun279(kk_std_core_types__tuple3 x, kk_string_t x_0_10216, kk_function_t _implicit_fs_thd_fs_show, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_show_fun279__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs_show_fun279__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs_show_fun279, kk_context());
  _self->x = x;
  _self->x_0_10216 = x_0_10216;
  _self->_implicit_fs_thd_fs_show = _implicit_fs_thd_fs_show;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs_show_fun279(kk_function_t _fself, kk_box_t _b_x82, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_show_fun279__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs_show_fun279__t*, _fself, _ctx);
  kk_std_core_types__tuple3 x = _self->x; /* (1257, 1258, 1259) */
  kk_string_t x_0_10216 = _self->x_0_10216; /* string */
  kk_function_t _implicit_fs_thd_fs_show = _self->_implicit_fs_thd_fs_show; /* (1259) -> 1260 string */
  kk_drop_match(_self, {kk_std_core_types__tuple3_dup(x, _ctx);kk_string_dup(x_0_10216, _ctx);kk_function_dup(_implicit_fs_thd_fs_show, _ctx);}, {}, _ctx)
  kk_string_t _y_x10112_89 = kk_string_unbox(_b_x82); /*string*/;
  kk_string_t _x_x280 = kk_std_core_tuple_tuple3_fs__mlift_show_10141(x_0_10216, x, _implicit_fs_thd_fs_show, _y_x10112_89, _ctx); /*string*/
  return kk_string_box(_x_x280);
}


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs_show_fun283__t {
  struct kk_function_s _base;
  kk_string_t x_0_10216;
  kk_string_t x_1_10219;
};
static kk_box_t kk_std_core_tuple_tuple3_fs_show_fun283(kk_function_t _fself, kk_box_t _b_x84, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs_new_show_fun283(kk_string_t x_0_10216, kk_string_t x_1_10219, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_show_fun283__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs_show_fun283__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs_show_fun283, kk_context());
  _self->x_0_10216 = x_0_10216;
  _self->x_1_10219 = x_1_10219;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs_show_fun283(kk_function_t _fself, kk_box_t _b_x84, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_show_fun283__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs_show_fun283__t*, _fself, _ctx);
  kk_string_t x_0_10216 = _self->x_0_10216; /* string */
  kk_string_t x_1_10219 = _self->x_1_10219; /* string */
  kk_drop_match(_self, {kk_string_dup(x_0_10216, _ctx);kk_string_dup(x_1_10219, _ctx);}, {}, _ctx)
  kk_string_t _y_x10113_90 = kk_string_unbox(_b_x84); /*string*/;
  kk_string_t _x_x284 = kk_std_core_tuple_tuple3_fs__mlift_show_10140(x_0_10216, x_1_10219, _y_x10113_90, _ctx); /*string*/
  return kk_string_box(_x_x284);
}

kk_string_t kk_std_core_tuple_tuple3_fs_show(kk_std_core_types__tuple3 x, kk_function_t _implicit_fs_fst_fs_show, kk_function_t _implicit_fs_snd_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_context_t* _ctx) { /* forall<a,b,c,e> (x : (a, b, c), ?fst/show : (a) -> e string, ?snd/show : (b) -> e string, ?thd/show : (c) -> e string) -> e string */ 
  kk_string_t x_0_10216;
  kk_box_t _x_x273;
  {
    kk_box_t _x = x.fst;
    kk_box_dup(_x, _ctx);
    _x_x273 = _x; /*1257*/
  }
  x_0_10216 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_fst_fs_show, (_implicit_fs_fst_fs_show, _x_x273, _ctx), _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10216, _ctx);
    kk_box_t _x_x274 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs_new_show_fun275(x, _implicit_fs_snd_fs_show, _implicit_fs_thd_fs_show, _ctx), _ctx); /*2978*/
    return kk_string_unbox(_x_x274);
  }
  {
    kk_string_t x_1_10219;
    kk_box_t _x_x277;
    {
      kk_box_t _x_0 = x.snd;
      kk_box_dup(_x_0, _ctx);
      _x_x277 = _x_0; /*1258*/
    }
    x_1_10219 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_show, (_implicit_fs_snd_fs_show, _x_x277, _ctx), _ctx); /*string*/
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_1_10219, _ctx);
      kk_box_t _x_x278 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs_new_show_fun279(x, x_0_10216, _implicit_fs_thd_fs_show, _ctx), _ctx); /*2978*/
      return kk_string_unbox(_x_x278);
    }
    {
      kk_string_t x_2_10222;
      kk_box_t _x_x281;
      {
        kk_box_t _x_1 = x.thd;
        kk_box_dup(_x_1, _ctx);
        kk_std_core_types__tuple3_drop(x, _ctx);
        _x_x281 = _x_1; /*1259*/
      }
      x_2_10222 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs_show, (_implicit_fs_thd_fs_show, _x_x281, _ctx), _ctx); /*string*/
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_2_10222, _ctx);
        kk_box_t _x_x282 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs_new_show_fun283(x_0_10216, x_1_10219, _ctx), _ctx); /*2978*/
        return kk_string_unbox(_x_x282);
      }
      {
        kk_string_t _x_x285;
        kk_define_string_literal(, _s_x286, 1, "(", _ctx)
        _x_x285 = kk_string_dup(_s_x286, _ctx); /*string*/
        kk_string_t _x_x287;
        kk_string_t _x_x288;
        kk_string_t _x_x289;
        kk_define_string_literal(, _s_x290, 1, ",", _ctx)
        _x_x289 = kk_string_dup(_s_x290, _ctx); /*string*/
        kk_string_t _x_x291;
        kk_string_t _x_x292;
        kk_string_t _x_x293;
        kk_define_string_literal(, _s_x294, 1, ",", _ctx)
        _x_x293 = kk_string_dup(_s_x294, _ctx); /*string*/
        kk_string_t _x_x295;
        kk_string_t _x_x296;
        kk_define_string_literal(, _s_x297, 1, ")", _ctx)
        _x_x296 = kk_string_dup(_s_x297, _ctx); /*string*/
        _x_x295 = kk_std_core_types__lp__plus__plus__rp_(x_2_10222, _x_x296, _ctx); /*string*/
        _x_x292 = kk_std_core_types__lp__plus__plus__rp_(_x_x293, _x_x295, _ctx); /*string*/
        _x_x291 = kk_std_core_types__lp__plus__plus__rp_(x_1_10219, _x_x292, _ctx); /*string*/
        _x_x288 = kk_std_core_types__lp__plus__plus__rp_(_x_x289, _x_x291, _ctx); /*string*/
        _x_x287 = kk_std_core_types__lp__plus__plus__rp_(x_0_10216, _x_x288, _ctx); /*string*/
        return kk_std_core_types__lp__plus__plus__rp_(_x_x285, _x_x287, _ctx);
      }
    }
  }
}

// initialization
void kk_std_core_tuple__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_tuple__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
