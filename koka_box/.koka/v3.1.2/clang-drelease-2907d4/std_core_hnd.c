// Koka generated module: std/core/hnd, koka version: 3.1.2, platform: 64-bit
#include "std_core_hnd.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2021, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/
/*
typedef datatype_t kk_std_core_hnd__ev;
struct kk_std_core_hnd_Ev {
  kk_std_core_hnd__htag htag;
  kk_box_t hnd;
  // kk_cfc_t cfc;  // control flow context
  kk_std_core_hnd__evv hevv;
  kk_std_core_hnd__marker marker;
};
*/


// Note. We no longer support cfc for `evv_is_affine` in the C backend since we always use context paths now.
//
// typedef int32_t kk_cfc_t;

// static kk_cfc_t kk_handler_cfc_borrow( kk_box_t h, kk_context_t* ctx ) {
//   kk_box_t b = kk_block_field(kk_ptr_unbox(h,ctx),0);  // first field of the handler is the cfc
//   return kk_integer_clamp32_borrow(kk_integer_unbox(b,ctx),ctx);
// }


static kk_evv_vector_t kk_evv_vector_alloc(kk_ssize_t length, kk_context_t* ctx) {
  kk_assert_internal(length>=0);
  kk_evv_vector_t v = (kk_evv_vector_t)kk_block_alloc(kk_ssizeof(struct kk_evv_vector_s) + (length-1)*kk_ssizeof(kk_std_core_hnd__ev_t), length, KK_TAG_EVV_VECTOR, ctx);
  // v->cfc = kk_integer_from_int32(cfc,ctx);
  return v;
}

static kk_std_core_hnd__ev* kk_evv_vector_buf(kk_evv_vector_t vec, kk_ssize_t* len) {
  if (len != NULL) { *len = kk_block_scan_fsize(&vec->_block); }
  return &vec->vec[0];
}

static kk_std_core_hnd__ev* kk_evv_as_vec(kk_evv_t evv, kk_ssize_t* len, kk_std_core_hnd__ev* single, kk_context_t* ctx) {
  if (kk_evv_is_vector(evv,ctx)) {
    kk_evv_vector_t vec = kk_evv_as_vector(evv,ctx);
    *len = kk_block_scan_fsize(&vec->_block);
    return &vec->vec[0];
  }
  else {
    // single evidence
    *single = kk_evv_as_ev(evv,ctx);
    *len = 1;
    return single;
  }
}

// kk_std_core_hnd__ev kk_ev_none(kk_context_t* ctx) {
//   static kk_std_core_hnd__ev ev_none_singleton = { kk_datatype_null_init };
//   if (kk_datatype_is_null(ev_none_singleton)) {
//     ev_none_singleton = kk_std_core_hnd__new_Ev(
//       kk_reuse_null,
//       0, // cpath
//       kk_std_core_hnd__new_Htag(kk_string_empty(),ctx), // tag ""
//       0,                                                // marker 0
//       kk_box_null(),                                    // no handler
//       // -1,                                               // bot
//       kk_evv_empty(ctx),
//       ctx
//     );
//   }
//   return kk_std_core_hnd__ev_dup(ev_none_singleton,ctx);
// }


kk_ssize_t kk_evv_index( struct kk_std_core_hnd_Htag htag, kk_context_t* ctx ) {
  // todo: drop htag?
  kk_ssize_t len;
  kk_std_core_hnd__ev single;
  kk_std_core_hnd__ev* vec = kk_evv_as_vec(ctx->evv,&len,&single,ctx);
  for(kk_ssize_t i = 0; i < len; i++) {
    struct kk_std_core_hnd_Ev* ev = kk_std_core_hnd__as_Ev(vec[i],ctx);
    if (kk_string_cmp_borrow(htag.tagname,ev->htag.tagname,ctx) <= 0) return i; // break on insertion point
  }
  //string_t evvs = kk_evv_show(dup_datatype_as(kk_evv_t,ctx->evv),ctx);
  //fatal_error(EFAULT,"cannot find tag '%s' in: %s", string_cbuf_borrow(htag.htag), string_cbuf_borrow(evvs));
  //drop_string_t(evvs,ctx);
  return len;
}


// static inline kk_cfc_t kk_cfc_lub(kk_cfc_t cfc1, kk_cfc_t cfc2) {
//   if (cfc1 < 0) return cfc2;
//   else if (cfc1+cfc2 == 1) return 2;
//   else if (cfc1>cfc2) return cfc1;
//   else return cfc2;
// }

// static inline struct kk_std_core_hnd_Ev* kk_evv_as_Ev( kk_evv_t evv, kk_context_t* ctx ) {
//   return kk_std_core_hnd__as_Ev(kk_evv_as_ev(evv,ctx),ctx);
// }


// static kk_cfc_t kk_evv_cfc_of_borrow(kk_evv_t evv, kk_context_t* ctx) {
//   if (kk_evv_is_vector(evv,ctx)) {
//     kk_cfc_t cfc = -1;
//     kk_ssize_t len;
//     kk_std_core_hnd__ev single;
//     kk_std_core_hnd__ev* vec = kk_evv_as_vec(ctx->evv,&len,&single,ctx);
//     for(kk_ssize_t i = 0; i < len; i++) {
//       struct kk_std_core_hnd_Ev* ev = kk_std_core_hnd__as_Ev(vec[i],ctx);
//       cfc = kk_cfc_lub(cfc, kk_handler_cfc_borrow(ev->hnd,ctx));
//     }
//     return cfc;
//   }
//   else {
//     struct kk_std_core_hnd_Ev* ev = kk_evv_as_Ev(evv,ctx);
//     return kk_handler_cfc_borrow(ev->hnd,ctx);
//   }
// }

bool kk_evv_is_affine(kk_context_t* ctx) {
  return false;
  // return (kk_evv_cfc_of_borrow(ctx->evv,ctx) <= 2);
}


// static void kk_evv_update_cfc_borrow(kk_evv_t evv, kk_cfc_t cfc, kk_context_t* ctx) {
//   kk_assert_internal(!kk_evv_is_empty(evv,ctx)); // should never happen (as named handlers are always in some context)
//   if (kk_evv_is_vector(evv,ctx)) {
//     kk_evv_vector_t vec = kk_evv_as_vector(evv,ctx);
//     vec->cfc = kk_integer_from_int32(kk_cfc_lub(kk_integer_clamp32_borrow(vec->cfc,ctx),cfc), ctx);
//   }
//   else {
//     struct kk_std_core_hnd_Ev* ev = kk_evv_as_Ev(evv,ctx);
//     ev->cfc = kk_cfc_lub(ev->cfc,cfc);
//   }
// }

kk_evv_t kk_evv_insert(kk_evv_t evvd, kk_std_core_hnd__ev evd, kk_context_t* ctx) {
  struct kk_std_core_hnd_Ev* ev = kk_std_core_hnd__as_Ev(evd,ctx);
  // update ev with parent evidence vector (either at init, or due to non-scoped resumptions)
  kk_marker_t marker = ev->marker;
  if (marker==0) { kk_std_core_hnd__ev_drop(evd,ctx); return evvd; } // ev-none
  kk_evv_drop(ev->hevv,ctx);
  ev->hevv = kk_evv_dup(evvd,ctx); // fixme: update in-place
  if (marker<0) { // negative marker is used for named evidence; this means this evidence should not be inserted into the evidence vector
    // kk_evv_update_cfc_borrow(evvd,ev->cfc,ctx); // update cfc in-place for named evidence
    kk_std_core_hnd__ev_drop(evd,ctx);
    return evvd;
  }
  // for regular handler evidence, insert ev
  kk_ssize_t n;
  kk_std_core_hnd__ev single;
  kk_std_core_hnd__ev* const evv1 = kk_evv_as_vec(evvd, &n, &single, ctx);
  if (n == 0) {
    // use ev directly as the evidence vector
    kk_evv_drop(evvd, ctx);
    return kk_ev_as_evv(evd,ctx);
  }
  else {
    // create evidence vector
    // const kk_cfc_t cfc = kk_cfc_lub(kk_evv_cfc_of_borrow(evvd, ctx), ev->cfc);
    // ev->cfc = cfc; // update in place
    kk_evv_vector_t vec2 = kk_evv_vector_alloc(n+1, /* cfc,*/ ctx);
    kk_std_core_hnd__ev* const evv2 = kk_evv_vector_buf(vec2, NULL);
    kk_ssize_t i;
    for (i = 0; i < n; i++) {
      struct kk_std_core_hnd_Ev* ev1 = kk_std_core_hnd__as_Ev(evv1[i],ctx);
      if (kk_string_cmp_borrow(ev->htag.tagname, ev1->htag.tagname,ctx) <= 0) break;
      evv2[i] = kk_std_core_hnd__ev_dup(evv1[i],ctx);
    }
    evv2[i] = evd;
    for (; i < n; i++) {
      evv2[i+1] = kk_std_core_hnd__ev_dup(evv1[i],ctx);
    }
    kk_evv_drop(evvd, ctx);  // assigned to evidence already
    return kk_datatype_from_base(vec2,ctx);
  }
}

kk_evv_t kk_evv_delete(kk_evv_t evvd, kk_ssize_t index, bool behind, kk_context_t* ctx) {
  kk_ssize_t n;
  kk_std_core_hnd__ev single;
  const kk_std_core_hnd__ev* evv1 = kk_evv_as_vec(evvd, &n, &single, ctx);
  if (n <= 1) {
    kk_evv_drop(evvd,ctx);
    return kk_evv_empty(ctx);
  }
  if (behind) index++;
  kk_assert_internal(index < n);
  // todo: copy without dupping (and later dropping) when possible
  // const kk_cfc_t cfc1 = kk_evv_cfc_of_borrow(evvd,ctx);
  kk_evv_vector_t const vec2 = kk_evv_vector_alloc(n-1,/*cfc1,*/ ctx);
  kk_std_core_hnd__ev* const evv2 = kk_evv_vector_buf(vec2,NULL);
  kk_ssize_t i;
  for(i = 0; i < index; i++) {
    evv2[i] = kk_std_core_hnd__ev_dup(evv1[i],ctx);
  }
  for(; i < n-1; i++) {
    evv2[i] = kk_std_core_hnd__ev_dup(evv1[i+1],ctx);
  }
  struct kk_std_core_hnd_Ev* ev = kk_std_core_hnd__as_Ev(evv1[index],ctx);
  // if (ev->cfc >= cfc1) {
  //   kk_cfc_t cfc = kk_std_core_hnd__as_Ev(evv2[0],ctx)->cfc;
  //   for(i = 1; i < n-1; i++) {
  //     cfc = kk_cfc_lub(cfc,kk_std_core_hnd__as_Ev(evv2[i],ctx)->cfc);
  //   }
  //   vec2->cfc = kk_integer_from_int32(cfc,ctx);
  // }
  kk_evv_drop(evvd,ctx);
  return kk_datatype_from_base(vec2,ctx);
}

kk_evv_t kk_evv_create(kk_evv_t evv1, kk_vector_t indices, kk_context_t* ctx) {
  kk_ssize_t len;
  kk_box_t* elems = kk_vector_buf_borrow(indices,&len,ctx); // borrows
  kk_evv_vector_t evv2 = kk_evv_vector_alloc(len,/* kk_evv_cfc_of_borrow(evv1,ctx),*/ ctx);
  kk_std_core_hnd__ev* buf2 = kk_evv_vector_buf(evv2,NULL);
  kk_assert_internal(kk_evv_is_vector(evv1,ctx));
  kk_ssize_t len1;
  kk_std_core_hnd__ev single;
  kk_std_core_hnd__ev* buf1 = kk_evv_as_vec(evv1,&len1,&single,ctx);
  for(kk_ssize_t i = 0; i < len; i++) {
    kk_ssize_t idx = kk_ssize_unbox(elems[i],KK_BORROWED,ctx);
    kk_assert_internal(idx < len1);
    buf2[i] = kk_std_core_hnd__ev_dup( buf1[idx], ctx );
  }
  kk_vector_drop(indices,ctx);
  kk_evv_drop(evv1,ctx);
  return kk_datatype_from_base(evv2,ctx);
}

kk_evv_t kk_evv_swap_create( kk_vector_t indices, kk_context_t* ctx ) {
  kk_ssize_t len;
  kk_box_t* vec = kk_vector_buf_borrow(indices,&len,ctx);
  if (len==0) {
    kk_vector_drop(indices,ctx);
    return kk_evv_swap_create0(ctx);
  }
  if (len==1) {
    kk_ssize_t i = kk_ssize_unbox(vec[0],KK_BORROWED,ctx);
    kk_vector_drop(indices,ctx);
    return kk_evv_swap_create1(i,ctx);
  }
  return kk_evv_swap( kk_evv_create(kk_evv_dup(ctx->evv,ctx),indices,ctx), ctx );
}


kk_string_t kk_evv_show(kk_evv_t evv, kk_context_t* ctx) {
  return kk_string_alloc_dup_valid_utf8("(not yet implemented: kk_evv_show)",ctx);
}


/*-----------------------------------------------------------------------
  Compose continuations
-----------------------------------------------------------------------*/

struct kcompose_fun_s {
  struct kk_function_s _base;
  kk_box_t      count;
  kk_function_t conts[1];
};

// kleisli composition of continuations
static kk_box_t kcompose( kk_function_t fself, kk_box_t x, kk_context_t* ctx) {
  struct kcompose_fun_s* self = kk_function_as(struct kcompose_fun_s*,fself,ctx);
  kk_intx_t count = kk_intf_unbox(self->count);
  kk_function_t* conts = &self->conts[0];
  // call each continuation in order
  for(kk_intx_t i = 0; i < count; i++) {
    // todo: take uniqueness of fself into account to avoid dup_function
    kk_function_t f = kk_function_dup(conts[i],ctx);
    x = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, ctx), ctx);
    if (kk_yielding(ctx)) {
      // if yielding, `yield_next` all continuations that still need to be done
      while(++i < count) {
        // todo: if fself is unique, we could copy without dup?
        kk_yield_extend(kk_function_dup(conts[i],ctx),ctx);
      }
      kk_function_drop(fself,ctx);
      kk_box_drop(x,ctx);     // still drop even though we yield as it may release a boxed value type?
      return kk_box_any(ctx); // return yielding
    }
  }
  kk_function_drop(fself,ctx);
  return x;
}

static kk_function_t new_kcompose( kk_function_t* conts, kk_intf_t count, kk_context_t* ctx ) {
  if (count==0) return kk_function_id(ctx);
  if (count==1) return conts[0];
  struct kcompose_fun_s* f = kk_block_as(struct kcompose_fun_s*,
                               kk_block_alloc(kk_ssizeof(struct kcompose_fun_s) - kk_ssizeof(kk_function_t) + (count*kk_ssizeof(kk_function_t)),
                                 2 + count /* scan size */, KK_TAG_FUNCTION, ctx));
  f->_base.fun = kk_kkfun_ptr_box(&kcompose,ctx);
  f->count = kk_intf_box(count);
  kk_memcpy(f->conts, conts, count * kk_ssizeof(kk_function_t));
  return kk_datatype_from_base(&f->_base,ctx);
}

/*-----------------------------------------------------------------------
  Yield extension
-----------------------------------------------------------------------*/

kk_box_t kk_yield_extend( kk_function_t next, kk_context_t* ctx ) {
  kk_yield_t* yield = &ctx->yield;
  kk_assert_internal(kk_yielding(ctx));  // cannot extend if not yielding
  if (kk_unlikely(kk_yielding_final(ctx))) {
    // todo: can we optimize this so `next` is never allocated in the first place?
    kk_function_drop(next,ctx); // ignore extension if never resuming
  }
  else {
    if (kk_unlikely(yield->conts_count >= KK_YIELD_CONT_MAX)) {
      // alloc a function to compose all continuations in the array
      kk_function_t comp = new_kcompose( yield->conts, yield->conts_count, ctx );
      yield->conts[0] = comp;
      yield->conts_count = 1;
    }
    yield->conts[yield->conts_count++] = next;
  }
  return kk_box_any(ctx);
}

// cont_apply: \x -> f(cont,x)
struct cont_apply_fun_s {
  struct kk_function_s _base;
  kk_function_t f;
  kk_function_t cont;
};

static kk_box_t cont_apply( kk_function_t fself, kk_box_t x, kk_context_t* ctx ) {
  struct cont_apply_fun_s* self = kk_function_as(struct cont_apply_fun_s*, fself, ctx);
  kk_function_t f = self->f;
  kk_function_t cont = self->cont;
  kk_drop_match(self,{kk_function_dup(f,ctx);kk_function_dup(cont,ctx);},{},ctx);
  return kk_function_call( kk_box_t, (kk_function_t, kk_function_t, kk_box_t, kk_context_t* ctx), f, (f, cont, x, ctx), ctx);
}

static kk_function_t kk_new_cont_apply( kk_function_t f, kk_function_t cont, kk_context_t* ctx ) {
  struct cont_apply_fun_s* self = kk_function_alloc_as(struct cont_apply_fun_s, 3, ctx);
  self->_base.fun = kk_kkfun_ptr_box(&cont_apply,ctx);
  self->f = f;
  self->cont = cont;
  return kk_datatype_from_base(&self->_base,ctx);
}

// Unlike `yield_extend`, `yield_cont` gets access to the current continuation. This is used in `yield_prompt`.
kk_box_t kk_yield_cont( kk_function_t f, kk_context_t* ctx ) {
  kk_yield_t* yield = &ctx->yield;
  kk_assert_internal(kk_yielding(ctx)); // cannot extend if not yielding
  if (kk_unlikely(kk_yielding_final(ctx))) {
    kk_function_drop(f,ctx); // ignore extension if never resuming
  }
  else {
    kk_function_t cont = new_kcompose(yield->conts, yield->conts_count, ctx);
    yield->conts_count = 1;
    yield->conts[0] = kk_new_cont_apply(f, cont, ctx);
  }
  return kk_box_any(ctx);
}

kk_function_t kk_yield_to( kk_marker_t m, kk_function_t clause, kk_context_t* ctx ) {
  kk_yield_t* yield = &ctx->yield;
  kk_assert_internal(!kk_yielding(ctx)); // already yielding
  ctx->yielding = KK_YIELD_NORMAL;
  yield->marker = m;
  yield->clause = clause;
  yield->conts_count = 0;
  return kk_datatype_unbox(kk_box_any(ctx));
}

kk_box_t kk_yield_final( kk_marker_t m, kk_function_t clause, kk_context_t* ctx ) {
  kk_yield_to(m,clause,ctx);
  ctx->yielding = KK_YIELD_FINAL;
  return kk_box_any(ctx);
}

kk_box_t kk_fatal_resume_final(kk_context_t* ctx) {
  kk_fatal_error(EFAULT,"trying to resume a finalized resumption");
  return kk_box_any(ctx);
}

static kk_box_t _fatal_resume_final(kk_function_t self, kk_context_t* ctx) {
  kk_function_drop(self,ctx);
  return kk_fatal_resume_final(ctx);
}
static kk_function_t fun_fatal_resume_final(kk_context_t* ctx) {
  kk_define_static_function(f,_fatal_resume_final,ctx);
  return kk_function_dup(f,ctx);
}


struct kk_std_core_hnd_yld_s kk_yield_prompt( kk_marker_t m, kk_context_t* ctx ) {
  kk_yield_t* yield = &ctx->yield;
  if (ctx->yielding == KK_YIELD_NONE) {
    return kk_std_core_hnd__new_Pure(ctx);
  }
  else if (yield->marker != m) {
    return (ctx->yielding == KK_YIELD_FINAL ? kk_std_core_hnd__new_YieldingFinal(ctx) : kk_std_core_hnd__new_Yielding(ctx));
  }
  else {
    kk_function_t cont = (ctx->yielding == KK_YIELD_FINAL ? fun_fatal_resume_final(ctx) : new_kcompose(yield->conts, yield->conts_count, ctx));
    kk_function_t clause = yield->clause;
    ctx->yielding = KK_YIELD_NONE;
    #ifndef NDEBUG
    kk_memset(yield,0,kk_ssizeof(kk_yield_t));
    #endif
    return kk_std_core_hnd__new_Yield(clause, cont, ctx);
  }
}

kk_unit_t  kk_evv_guard(kk_evv_t evv, kk_context_t* ctx) {
  bool eq = kk_datatype_eq(ctx->evv,evv);
  kk_evv_drop(evv,ctx);
  if (!eq) {
    // todo: improve error message with diagnostics
    kk_fatal_error(EFAULT,"trying to resume outside the (handler) scope of the original handler");
  }
  return kk_Unit;
}

typedef struct yield_info_s {
  struct kk_std_core_hnd__yield_info_s _base;
  kk_function_t clause;
  kk_function_t conts[KK_YIELD_CONT_MAX];
  kk_intf_t     conts_count;
  kk_marker_t   marker;
  int8_t        yielding;
}* yield_info_t;

kk_std_core_hnd__yield_info kk_yield_capture(kk_context_t* ctx) {
  kk_assert_internal(kk_yielding(ctx));
  yield_info_t yld = kk_block_alloc_as(struct yield_info_s, 1 + KK_YIELD_CONT_MAX, (kk_tag_t)1, ctx);
  yld->clause = ctx->yield.clause;
  kk_ssize_t i = 0;
  for( ; i < ctx->yield.conts_count; i++) {
    yld->conts[i] = ctx->yield.conts[i];
  }
  for( ; i < KK_YIELD_CONT_MAX; i++) {
    yld->conts[i] = kk_function_null(ctx);
  }
  yld->conts_count = ctx->yield.conts_count;
  yld->marker = ctx->yield.marker;
  yld->yielding = ctx->yielding;
  ctx->yielding = 0;
  ctx->yield.conts_count = 0;
  return kk_datatype_from_base(&yld->_base,ctx);
}

kk_box_t kk_yield_reyield( kk_std_core_hnd__yield_info yldinfo, kk_context_t* ctx) {
  kk_assert_internal(!kk_yielding(ctx));
  yield_info_t yld = kk_datatype_as_assert(yield_info_t, yldinfo, (kk_tag_t)1, ctx);
  ctx->yield.clause = kk_function_dup(yld->clause,ctx);
  ctx->yield.marker = yld->marker;
  ctx->yield.conts_count = yld->conts_count;
  ctx->yielding = yld->yielding;
  for(kk_ssize_t i = 0; i < yld->conts_count; i++) {
    ctx->yield.conts[i] = kk_function_dup(yld->conts[i],ctx);
  }
  kk_constructor_drop(yld,ctx);
  return kk_box_any(ctx);
}


kk_std_core_hnd__htag kk_std_core_hnd_htag_fs__copy(kk_std_core_hnd__htag _this, kk_std_core_types__optional tagname, kk_context_t* _ctx) { /* forall<a> (htag<a>, tagname : ? string) -> htag<a> */ 
  kk_string_t _x_x274;
  if (kk_std_core_types__is_Optional(tagname, _ctx)) {
    kk_box_t _box_x0 = tagname._cons._Optional.value;
    kk_string_t _uniq_tagname_1879 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_tagname_1879, _ctx);
    kk_std_core_types__optional_drop(tagname, _ctx);
    kk_std_core_hnd__htag_drop(_this, _ctx);
    _x_x274 = _uniq_tagname_1879; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(tagname, _ctx);
    {
      kk_string_t _x = _this.tagname;
      _x_x274 = _x; /*string*/
    }
  }
  return kk_std_core_hnd__new_Htag(_x_x274, _ctx);
}

kk_std_core_hnd__ev kk_std_core_hnd_ev_fs__copy(kk_std_core_hnd__ev _this, kk_std_core_types__optional htag, int32_t marker, kk_box_t hnd, kk_evv_t hevv, kk_context_t* _ctx) { /* forall<a,e,b> (ev<a>, htag : ? (htag<a>), marker : marker<e,b>, hnd : a<e,b>, hevv : evv<e>) -> ev<a> */ 
  kk_std_core_hnd__htag _x_x276;
  if (kk_std_core_types__is_Optional(htag, _ctx)) {
    kk_box_t _box_x1 = htag._cons._Optional.value;
    kk_std_core_hnd__htag _uniq_htag_1930 = kk_std_core_hnd__htag_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_hnd__htag_dup(_uniq_htag_1930, _ctx);
    kk_std_core_types__optional_drop(htag, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x276 = _uniq_htag_1930; /*hnd/htag<1955>*/
  }
  else {
    kk_std_core_types__optional_drop(htag, _ctx);
    {
      struct kk_std_core_hnd_Ev* _con_x277 = kk_std_core_hnd__as_Ev(_this, _ctx);
      kk_std_core_hnd__htag _x = _con_x277->htag;
      kk_box_t _pat_1_0 = _con_x277->hnd;
      kk_evv_t _pat_2 = _con_x277->hevv;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_evv_drop(_pat_2, _ctx);
        kk_box_drop(_pat_1_0, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_std_core_hnd__htag_dup(_x, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x276 = _x; /*hnd/htag<1955>*/
    }
  }
  return kk_std_core_hnd__new_Ev(kk_reuse_null, 0, _x_x276, marker, hnd, hevv, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause0_fs__copy_fun279__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x7;
};
static kk_box_t kk_std_core_hnd_clause0_fs__copy_fun279(kk_function_t _fself, int32_t _b_x11, kk_std_core_hnd__ev _b_x12, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_clause0_fs__new_copy_fun279(kk_box_t _fun_unbox_x7, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause0_fs__copy_fun279__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause0_fs__copy_fun279__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause0_fs__copy_fun279, kk_context());
  _self->_fun_unbox_x7 = _fun_unbox_x7;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause0_fs__copy_fun279(kk_function_t _fself, int32_t _b_x11, kk_std_core_hnd__ev _b_x12, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause0_fs__copy_fun279__t* _self = kk_function_as(struct kk_std_core_hnd_clause0_fs__copy_fun279__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x7 = _self->_fun_unbox_x7; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x7, _ctx);}, {}, _ctx)
  kk_function_t _x_x280 = kk_function_unbox(_fun_unbox_x7, _ctx); /*(8, 9) -> 2059 10*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x280, (_x_x280, kk_int32_box(_b_x11, _ctx), kk_std_core_hnd__ev_box(_b_x12, _ctx), _ctx), _ctx);
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause0_fs__copy(kk_std_core_hnd__clause0 _this, kk_std_core_types__optional clause, kk_context_t* _ctx) { /* forall<a,b,e,c> (clause0<a,b,e,c>, clause : ? ((marker<e,c>, ev<b>) -> e a)) -> clause0<a,b,e,c> */ 
  kk_function_t _x_x278;
  if (kk_std_core_types__is_Optional(clause, _ctx)) {
    kk_box_t _fun_unbox_x7 = clause._cons._Optional.value;
    kk_box_dup(_fun_unbox_x7, _ctx);
    kk_std_core_types__optional_drop(clause, _ctx);
    kk_std_core_hnd__clause0_drop(_this, _ctx);
    _x_x278 = kk_std_core_hnd_clause0_fs__new_copy_fun279(_fun_unbox_x7, _ctx); /*(hnd/marker<2059,2060>, hnd/ev<2058>) -> 2059 10*/
  }
  else {
    kk_std_core_types__optional_drop(clause, _ctx);
    {
      kk_function_t _x = _this.clause;
      _x_x278 = _x; /*(hnd/marker<2059,2060>, hnd/ev<2058>) -> 2059 10*/
    }
  }
  return kk_std_core_hnd__new_Clause0(_x_x278, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause1_fs__copy_fun282__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x20;
};
static kk_box_t kk_std_core_hnd_clause1_fs__copy_fun282(kk_function_t _fself, int32_t _b_x25, kk_std_core_hnd__ev _b_x26, kk_box_t _b_x27, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_clause1_fs__new_copy_fun282(kk_box_t _fun_unbox_x20, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause1_fs__copy_fun282__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause1_fs__copy_fun282__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause1_fs__copy_fun282, kk_context());
  _self->_fun_unbox_x20 = _fun_unbox_x20;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause1_fs__copy_fun282(kk_function_t _fself, int32_t _b_x25, kk_std_core_hnd__ev _b_x26, kk_box_t _b_x27, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause1_fs__copy_fun282__t* _self = kk_function_as(struct kk_std_core_hnd_clause1_fs__copy_fun282__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x20 = _self->_fun_unbox_x20; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x20, _ctx);}, {}, _ctx)
  kk_function_t _x_x283 = kk_function_unbox(_fun_unbox_x20, _ctx); /*(21, 22, 23) -> 2187 24*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), _x_x283, (_x_x283, kk_int32_box(_b_x25, _ctx), kk_std_core_hnd__ev_box(_b_x26, _ctx), _b_x27, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause1_fs__copy(kk_std_core_hnd__clause1 _this, kk_std_core_types__optional clause, kk_context_t* _ctx) { /* forall<a,b,c,e,d> (clause1<a,b,c,e,d>, clause : ? ((marker<e,d>, ev<c>, a) -> e b)) -> clause1<a,b,c,e,d> */ 
  kk_function_t _x_x281;
  if (kk_std_core_types__is_Optional(clause, _ctx)) {
    kk_box_t _fun_unbox_x20 = clause._cons._Optional.value;
    kk_box_dup(_fun_unbox_x20, _ctx);
    kk_std_core_types__optional_drop(clause, _ctx);
    kk_std_core_hnd__clause1_drop(_this, _ctx);
    _x_x281 = kk_std_core_hnd_clause1_fs__new_copy_fun282(_fun_unbox_x20, _ctx); /*(hnd/marker<2187,2188>, hnd/ev<2186>, 2184) -> 2187 24*/
  }
  else {
    kk_std_core_types__optional_drop(clause, _ctx);
    {
      kk_function_t _x = _this.clause;
      _x_x281 = _x; /*(hnd/marker<2187,2188>, hnd/ev<2186>, 2184) -> 2187 24*/
    }
  }
  return kk_std_core_hnd__new_Clause1(_x_x281, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause2_fs__copy_fun285__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x37;
};
static kk_box_t kk_std_core_hnd_clause2_fs__copy_fun285(kk_function_t _fself, int32_t _b_x43, kk_std_core_hnd__ev _b_x44, kk_box_t _b_x45, kk_box_t _b_x46, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_clause2_fs__new_copy_fun285(kk_box_t _fun_unbox_x37, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause2_fs__copy_fun285__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause2_fs__copy_fun285__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause2_fs__copy_fun285, kk_context());
  _self->_fun_unbox_x37 = _fun_unbox_x37;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause2_fs__copy_fun285(kk_function_t _fself, int32_t _b_x43, kk_std_core_hnd__ev _b_x44, kk_box_t _b_x45, kk_box_t _b_x46, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause2_fs__copy_fun285__t* _self = kk_function_as(struct kk_std_core_hnd_clause2_fs__copy_fun285__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x37 = _self->_fun_unbox_x37; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x37, _ctx);}, {}, _ctx)
  kk_function_t _x_x286 = kk_function_unbox(_fun_unbox_x37, _ctx); /*(38, 39, 40, 41) -> 2341 42*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), _x_x286, (_x_x286, kk_int32_box(_b_x43, _ctx), kk_std_core_hnd__ev_box(_b_x44, _ctx), _b_x45, _b_x46, _ctx), _ctx);
}

kk_std_core_hnd__clause2 kk_std_core_hnd_clause2_fs__copy(kk_std_core_hnd__clause2 _this, kk_std_core_types__optional clause, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (clause2<a,b,c,d,e,a1>, clause : ? ((marker<e,a1>, ev<d>, a, b) -> e c)) -> clause2<a,b,c,d,e,a1> */ 
  kk_function_t _x_x284;
  if (kk_std_core_types__is_Optional(clause, _ctx)) {
    kk_box_t _fun_unbox_x37 = clause._cons._Optional.value;
    kk_box_dup(_fun_unbox_x37, _ctx);
    kk_std_core_types__optional_drop(clause, _ctx);
    kk_std_core_hnd__clause2_drop(_this, _ctx);
    _x_x284 = kk_std_core_hnd_clause2_fs__new_copy_fun285(_fun_unbox_x37, _ctx); /*(hnd/marker<2341,2342>, hnd/ev<2340>, 2337, 2338) -> 2341 42*/
  }
  else {
    kk_std_core_types__optional_drop(clause, _ctx);
    {
      kk_function_t _x = _this.clause;
      _x_x284 = _x; /*(hnd/marker<2341,2342>, hnd/ev<2340>, 2337, 2338) -> 2341 42*/
    }
  }
  return kk_std_core_hnd__new_Clause2(_x_x284, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_resume_context_fs__copy_fun288__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x50;
};
static kk_box_t kk_std_core_hnd_resume_context_fs__copy_fun288(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x53, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_resume_context_fs__new_copy_fun288(kk_box_t _fun_unbox_x50, kk_context_t* _ctx) {
  struct kk_std_core_hnd_resume_context_fs__copy_fun288__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_resume_context_fs__copy_fun288__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_resume_context_fs__copy_fun288, kk_context());
  _self->_fun_unbox_x50 = _fun_unbox_x50;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_resume_context_fs__copy_fun288(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x53, kk_context_t* _ctx) {
  struct kk_std_core_hnd_resume_context_fs__copy_fun288__t* _self = kk_function_as(struct kk_std_core_hnd_resume_context_fs__copy_fun288__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x50 = _self->_fun_unbox_x50; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x50, _ctx);}, {}, _ctx)
  kk_function_t _x_x289 = kk_function_unbox(_fun_unbox_x50, _ctx); /*(51) -> 2512 52*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x289, (_x_x289, kk_std_core_hnd__resume_result_box(_b_x53, _ctx), _ctx), _ctx);
}

kk_std_core_hnd__resume_context kk_std_core_hnd_resume_context_fs__copy(kk_std_core_hnd__resume_context _this, kk_std_core_types__optional k, kk_context_t* _ctx) { /* forall<a,e,e1,b> (resume-context<a,e,e1,b>, k : ? ((resume-result<a,b>) -> e b)) -> resume-context<a,e,e1,b> */ 
  kk_function_t _x_x287;
  if (kk_std_core_types__is_Optional(k, _ctx)) {
    kk_box_t _fun_unbox_x50 = k._cons._Optional.value;
    kk_box_dup(_fun_unbox_x50, _ctx);
    kk_std_core_types__optional_drop(k, _ctx);
    kk_std_core_hnd__resume_context_drop(_this, _ctx);
    _x_x287 = kk_std_core_hnd_resume_context_fs__new_copy_fun288(_fun_unbox_x50, _ctx); /*(hnd/resume-result<2511,2514>) -> 2512 52*/
  }
  else {
    kk_std_core_types__optional_drop(k, _ctx);
    {
      kk_function_t _x = _this.k;
      _x_x287 = _x; /*(hnd/resume-result<2511,2514>) -> 2512 52*/
    }
  }
  return kk_std_core_hnd__new_Resume_context(_x_x287, _ctx);
}
 
// Are two markers equal?

bool kk_std_core_hnd_eq_marker(int32_t x, int32_t y, kk_context_t* _ctx) { /* forall<a,b,e,e1> (x : marker<e,a>, y : marker<e1,b>) -> bool */ 
  return x==y;
}
 
// Evidence equality compares the markers.

bool kk_std_core_hnd_ev_fs__lp__eq__eq__rp_(kk_std_core_hnd__ev _pat_x141__18, kk_std_core_hnd__ev _pat_x141__37, kk_context_t* _ctx) { /* forall<a> (ev<a>, ev<a>) -> bool */ 
  {
    struct kk_std_core_hnd_Ev* _con_x290 = kk_std_core_hnd__as_Ev(_pat_x141__18, _ctx);
    kk_std_core_hnd__htag _pat_0 = _con_x290->htag;
    int32_t m1 = _con_x290->marker;
    kk_box_t _pat_1 = _con_x290->hnd;
    kk_evv_t _pat_2 = _con_x290->hevv;
    if kk_likely(kk_datatype_ptr_is_unique(_pat_x141__18, _ctx)) {
      kk_evv_drop(_pat_2, _ctx);
      kk_box_drop(_pat_1, _ctx);
      kk_std_core_hnd__htag_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(_pat_x141__18, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_pat_x141__18, _ctx);
    }
    {
      struct kk_std_core_hnd_Ev* _con_x291 = kk_std_core_hnd__as_Ev(_pat_x141__37, _ctx);
      kk_std_core_hnd__htag _pat_4 = _con_x291->htag;
      int32_t m2 = _con_x291->marker;
      kk_box_t _pat_5 = _con_x291->hnd;
      kk_evv_t _pat_6 = _con_x291->hevv;
      if kk_likely(kk_datatype_ptr_is_unique(_pat_x141__37, _ctx)) {
        kk_evv_drop(_pat_6, _ctx);
        kk_box_drop(_pat_5, _ctx);
        kk_std_core_hnd__htag_drop(_pat_4, _ctx);
        kk_datatype_ptr_free(_pat_x141__37, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_x141__37, _ctx);
      }
      return kk_std_core_hnd_eq_marker(m1, m2, _ctx);
    }
  }
}

int32_t kk_std_core_hnd_fresh_marker(kk_context_t* _ctx) { /* forall<a,e> () -> marker<e,a> */ 
  return kk_marker_unique(kk_context());
}

int32_t kk_std_core_hnd_fresh_marker_named(kk_context_t* _ctx) { /* forall<a,e> () -> marker<e,a> */ 
  return -kk_marker_unique(kk_context());
}
 
// Insert new evidence into the given evidence vector.

kk_evv_t kk_std_core_hnd_evv_insert(kk_evv_t evv, kk_std_core_hnd__ev ev, kk_context_t* _ctx) { /* forall<e,e1,a> (evv : evv<e>, ev : ev<a>) -> e evv<e1> */ 
  return kk_evv_insert(evv,ev,kk_context());
}
 
// show evidence for debug purposes

kk_string_t kk_std_core_hnd_evv_show(kk_evv_t evv, kk_context_t* _ctx) { /* forall<e> (evv : evv<e>) -> string */ 
  return kk_evv_show(evv,kk_context());
}
 
// Is an evidence vector unchanged? (i.e. as pointer equality).
// This is used to avoid copying in common cases.

bool kk_std_core_hnd_evv_eq(kk_evv_t evv0, kk_evv_t evv1, kk_context_t* _ctx) { /* forall<e> (evv0 : evv<e>, evv1 : evv<e>) -> bool */ 
  return kk_evv_eq(evv0,evv1,kk_context());
}
 
// (dynamically) find evidence insertion/deletion index in the evidence vector
// The compiler optimizes `@evv-index` to a static index when apparent from the effect type.

kk_ssize_t kk_std_core_hnd__evv_index(kk_std_core_hnd__htag htag, kk_context_t* _ctx) { /* forall<e,a> (htag : htag<a>) -> e ev-index */ 
  return kk_evv_index(htag,kk_context());
}
 
// Get the current evidence vector.

kk_evv_t kk_std_core_hnd_evv_get(kk_context_t* _ctx) { /* forall<e> () -> e evv<e> */ 
  return kk_evv_get(kk_context());
}
 
// Does the current evidence vector consist solely of affine handlers?
// This is called in backends that do not have context paths (like javascript)
// to optimize TRMC (where we can use faster update-in-place TRMC if we know the
// operations are all affine). As such, it is always safe to return `false`.
//
// control flow context:
//                 -1: none: bottom
//                   /
// 0: except: never resumes   1: linear: resumes exactly once
//                   \          /
//           2: affine: resumes never or once
//                        |
//     3: multi: resumes never, once, or multiple times
//

bool kk_std_core_hnd__evv_is_affine(kk_context_t* _ctx) { /* () -> bool */ 
  return kk_evv_is_affine(kk_context());
}
 
// Remove evidence at index `i` of the current evidence vector, and return the old one.
// (used by `mask`)

kk_evv_t kk_std_core_hnd_evv_swap_delete(kk_ssize_t i, bool behind, kk_context_t* _ctx) { /* forall<e,e1> (i : ev-index, behind : bool) -> e1 evv<e> */ 
  return kk_evv_swap_delete(i,behind,kk_context());
}
 
// Swap the current evidence vector with a new vector consisting of evidence
// at indices `indices` in the current vector.

kk_evv_t kk_std_core_hnd_evv_swap_create(kk_vector_t indices, kk_context_t* _ctx) { /* forall<e> (indices : vector<ev-index>) -> e evv<e> */ 
  return kk_evv_swap_create(indices,kk_context());
}

kk_box_t kk_std_core_hnd_yield_extend(kk_function_t next, kk_context_t* _ctx) { /* forall<a,b,e> (next : (a) -> e b) -> e b */ 
  return kk_yield_extend(next,kk_context());
}

kk_box_t kk_std_core_hnd_yield_cont(kk_function_t f, kk_context_t* _ctx) { /* forall<a,e,b> (f : forall<c> ((c) -> e a, c) -> e b) -> e b */ 
  return kk_yield_cont(f,kk_context());
}

kk_std_core_hnd__yld kk_std_core_hnd_yield_prompt(int32_t m, kk_context_t* _ctx) { /* forall<a,e,b> (m : marker<e,b>) -> yld<e,a,b> */ 
  return kk_yield_prompt(m,kk_context());
}

kk_function_t kk_std_core_hnd_yield_to_prim(int32_t m, kk_function_t clause, kk_context_t* _ctx) { /* forall<a,e,e1,b> (m : marker<e1,b>, clause : ((resume-result<a,b>) -> e1 b) -> e1 b) -> e (() -> a) */ 
  return kk_yield_to(m,clause,kk_context());
}

kk_box_t kk_std_core_hnd_yield_to_final(int32_t m, kk_function_t clause, kk_context_t* _ctx) { /* forall<a,e,e1,b> (m : marker<e1,b>, clause : ((resume-result<a,b>) -> e1 b) -> e1 b) -> e a */ 
  return kk_yield_final(m,clause,kk_context());
}


// lift anonymous function
struct kk_std_core_hnd_yield_to_fun292__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_hnd_yield_to_fun292(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_yield_to_fun292(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_hnd_yield_to_fun292, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_hnd_yield_to_fun292(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_function_t _x_x293 = kk_function_unbox(_b_x55, _ctx); /*() -> 3284 56*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x_x293, (_x_x293, _ctx), _ctx);
}

kk_box_t kk_std_core_hnd_yield_to(int32_t m, kk_function_t clause, kk_context_t* _ctx) { /* forall<a,e,b> (m : marker<e,b>, clause : ((resume-result<a,b>) -> e b) -> e b) -> e a */ 
  kk_function_t g = kk_std_core_hnd_yield_to_prim(m, clause, _ctx); /*() -> 3283*/;
  kk_function_drop(g, _ctx);
  return kk_std_core_hnd_yield_extend(kk_std_core_hnd_new_yield_to_fun292(_ctx), _ctx);
}

kk_std_core_hnd__yield_info kk_std_core_hnd_yield_capture(kk_context_t* _ctx) { /* forall<e> () -> e yield-info */ 
  return kk_yield_capture(kk_context());
}

kk_box_t kk_std_core_hnd_unsafe_reyield(kk_std_core_hnd__yield_info yld, kk_context_t* _ctx) { /* forall<a,e> (yld : yield-info) -> e a */ 
  return kk_yield_reyield(yld,kk_context());
}

kk_unit_t kk_std_core_hnd_guard(kk_evv_t w, kk_context_t* _ctx) { /* forall<e> (w : evv<e>) -> e () */ 
  kk_evv_guard(w,kk_context()); return kk_Unit;
}

kk_box_t kk_std_core_hnd_resume_final(kk_context_t* _ctx) { /* forall<a> () -> a */ 
  return kk_fatal_resume_final(kk_context());
}


// lift anonymous function
struct kk_std_core_hnd_prompt_fun296__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
  kk_function_t ret;
  kk_evv_t w0;
  kk_evv_t w1;
  int32_t m;
};
static kk_box_t kk_std_core_hnd_prompt_fun296(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun296(kk_std_core_hnd__ev ev, kk_function_t ret, kk_evv_t w0, kk_evv_t w1, int32_t m, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun296__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun296__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun296, kk_context());
  _self->ev = ev;
  _self->ret = ret;
  _self->w0 = w0;
  _self->w1 = w1;
  _self->m = m;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_prompt_fun296(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun296__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun296__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<3691> */
  kk_function_t ret = _self->ret; /* (3689) -> 3690 3692 */
  kk_evv_t w0 = _self->w0; /* hnd/evv<3690> */
  kk_evv_t w1 = _self->w1; /* hnd/evv<3690> */
  int32_t m = _self->m; /* hnd/marker<3690,3692> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);kk_function_dup(ret, _ctx);kk_evv_dup(w0, _ctx);kk_evv_dup(w1, _ctx);kk_skip_dup(m, _ctx);}, {}, _ctx)
  kk_evv_t w0_sq_ = kk_std_core_hnd_evv_get(_ctx); /*hnd/evv<3690>*/;
  kk_evv_t w1_sq_;
  bool _match_x263;
  kk_evv_t _x_x297 = kk_evv_dup(w0_sq_, _ctx); /*hnd/evv<3690>*/
  _match_x263 = kk_std_core_hnd_evv_eq(w0, _x_x297, _ctx); /*bool*/
  if (_match_x263) {
    w1_sq_ = w1; /*hnd/evv<3690>*/
  }
  else {
    kk_evv_drop(w1, _ctx);
    kk_evv_t _x_x298 = kk_evv_dup(w0_sq_, _ctx); /*hnd/evv<3690>*/
    kk_std_core_hnd__ev _x_x299 = kk_std_core_hnd__ev_dup(ev, _ctx); /*hnd/ev<3691>*/
    w1_sq_ = kk_std_core_hnd_evv_insert(_x_x298, _x_x299, _ctx); /*hnd/evv<3690>*/
  }
  kk_unit_t ___1 = kk_Unit;
  kk_evv_t _x_x300 = kk_evv_dup(w1_sq_, _ctx); /*hnd/evv<3690>*/
  kk_evv_set(_x_x300,kk_context());
  kk_box_t _x_x301 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*3689*/
  return kk_std_core_hnd_prompt(w0_sq_, w1_sq_, ev, m, ret, _x_x301, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_prompt_fun302__t {
  struct kk_function_s _base;
  kk_function_t cont_0;
  kk_std_core_hnd__ev ev;
  kk_function_t ret;
  kk_evv_t w0;
  kk_evv_t w1;
  int32_t m;
};
static kk_box_t kk_std_core_hnd_prompt_fun302(kk_function_t _fself, kk_std_core_hnd__resume_result r, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun302(kk_function_t cont_0, kk_std_core_hnd__ev ev, kk_function_t ret, kk_evv_t w0, kk_evv_t w1, int32_t m, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun302__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun302__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun302, kk_context());
  _self->cont_0 = cont_0;
  _self->ev = ev;
  _self->ret = ret;
  _self->w0 = w0;
  _self->w1 = w1;
  _self->m = m;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_prompt_fun308__t {
  struct kk_function_s _base;
  kk_box_t x;
};
static kk_box_t kk_std_core_hnd_prompt_fun308(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun308(kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun308__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun308__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun308, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_prompt_fun308(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun308__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun308__t*, _fself, _ctx);
  kk_box_t x = _self->x; /* 3489 */
  kk_drop_match(_self, {kk_box_dup(x, _ctx);}, {}, _ctx)
  return x;
}


// lift anonymous function
struct kk_std_core_hnd_prompt_fun309__t {
  struct kk_function_s _base;
  kk_box_t x_0;
};
static kk_box_t kk_std_core_hnd_prompt_fun309(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun309(kk_box_t x_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun309__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun309__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun309, kk_context());
  _self->x_0 = x_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_prompt_fun309(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun309__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun309__t*, _fself, _ctx);
  kk_box_t x_0 = _self->x_0; /* 3489 */
  kk_drop_match(_self, {kk_box_dup(x_0, _ctx);}, {}, _ctx)
  return x_0;
}


// lift anonymous function
struct kk_std_core_hnd_prompt_fun315__t {
  struct kk_function_s _base;
  kk_box_t x_1_0;
  int32_t m;
};
static kk_box_t kk_std_core_hnd_prompt_fun315(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun315(kk_box_t x_1_0, int32_t m, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun315__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun315__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun315, kk_context());
  _self->x_1_0 = x_1_0;
  _self->m = m;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_prompt_fun316__t {
  struct kk_function_s _base;
  kk_box_t x_1_0;
};
static kk_box_t kk_std_core_hnd_prompt_fun316(kk_function_t _fself, kk_function_t ___wildcard_x405__85, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun316(kk_box_t x_1_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun316__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun316__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun316, kk_context());
  _self->x_1_0 = x_1_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_prompt_fun316(kk_function_t _fself, kk_function_t ___wildcard_x405__85, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun316__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun316__t*, _fself, _ctx);
  kk_box_t x_1_0 = _self->x_1_0; /* 3692 */
  kk_drop_match(_self, {kk_box_dup(x_1_0, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x405__85, _ctx);
  return x_1_0;
}
static kk_box_t kk_std_core_hnd_prompt_fun315(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun315__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun315__t*, _fself, _ctx);
  kk_box_t x_1_0 = _self->x_1_0; /* 3692 */
  int32_t m = _self->m; /* hnd/marker<3690,3692> */
  kk_drop_match(_self, {kk_box_dup(x_1_0, _ctx);kk_skip_dup(m, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_hnd_new_prompt_fun316(x_1_0, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_prompt_fun302(kk_function_t _fself, kk_std_core_hnd__resume_result r, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun302__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun302__t*, _fself, _ctx);
  kk_function_t cont_0 = _self->cont_0; /* (() -> 3489) -> 3690 3689 */
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<3691> */
  kk_function_t ret = _self->ret; /* (3689) -> 3690 3692 */
  kk_evv_t w0 = _self->w0; /* hnd/evv<3690> */
  kk_evv_t w1 = _self->w1; /* hnd/evv<3690> */
  int32_t m = _self->m; /* hnd/marker<3690,3692> */
  kk_drop_match(_self, {kk_function_dup(cont_0, _ctx);kk_std_core_hnd__ev_dup(ev, _ctx);kk_function_dup(ret, _ctx);kk_evv_dup(w0, _ctx);kk_evv_dup(w1, _ctx);kk_skip_dup(m, _ctx);}, {}, _ctx)
  if (kk_std_core_hnd__is_Deep(r, _ctx)) {
    kk_box_t x = r._cons.Deep.result;
    kk_evv_t w0_0_sq_ = kk_std_core_hnd_evv_get(_ctx); /*hnd/evv<3690>*/;
    kk_evv_t w1_0_sq_;
    bool _match_x262;
    kk_evv_t _x_x303 = kk_evv_dup(w0_0_sq_, _ctx); /*hnd/evv<3690>*/
    _match_x262 = kk_std_core_hnd_evv_eq(w0, _x_x303, _ctx); /*bool*/
    if (_match_x262) {
      w1_0_sq_ = w1; /*hnd/evv<3690>*/
    }
    else {
      kk_evv_drop(w1, _ctx);
      kk_evv_t _x_x304 = kk_evv_dup(w0_0_sq_, _ctx); /*hnd/evv<3690>*/
      kk_std_core_hnd__ev _x_x305 = kk_std_core_hnd__ev_dup(ev, _ctx); /*hnd/ev<3691>*/
      w1_0_sq_ = kk_std_core_hnd_evv_insert(_x_x304, _x_x305, _ctx); /*hnd/evv<3690>*/
    }
    kk_unit_t ___2 = kk_Unit;
    kk_evv_t _x_x306 = kk_evv_dup(w1_0_sq_, _ctx); /*hnd/evv<3690>*/
    kk_evv_set(_x_x306,kk_context());
    kk_box_t _x_x307 = kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), cont_0, (cont_0, kk_std_core_hnd_new_prompt_fun308(x, _ctx), _ctx), _ctx); /*3689*/
    return kk_std_core_hnd_prompt(w0_0_sq_, w1_0_sq_, ev, m, ret, _x_x307, _ctx);
  }
  if (kk_std_core_hnd__is_Shallow(r, _ctx)) {
    kk_box_t x_0 = r._cons.Shallow.result;
    kk_evv_drop(w1, _ctx);
    kk_evv_drop(w0, _ctx);
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_box_t x_1_10006 = kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), cont_0, (cont_0, kk_std_core_hnd_new_prompt_fun309(x_0, _ctx), _ctx), _ctx); /*3689*/;
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_1_10006, _ctx);
      return kk_std_core_hnd_yield_extend(ret, _ctx);
    }
    {
      return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), ret, (ret, x_1_10006, _ctx), _ctx);
    }
  }
  {
    kk_box_t x_1_0 = r._cons.Finalize.result;
    kk_evv_t w0_1_sq_ = kk_std_core_hnd_evv_get(_ctx); /*hnd/evv<3690>*/;
    kk_evv_t w1_1_sq_;
    bool _match_x260;
    kk_evv_t _x_x310 = kk_evv_dup(w0_1_sq_, _ctx); /*hnd/evv<3690>*/
    _match_x260 = kk_std_core_hnd_evv_eq(w0, _x_x310, _ctx); /*bool*/
    if (_match_x260) {
      w1_1_sq_ = w1; /*hnd/evv<3690>*/
    }
    else {
      kk_evv_drop(w1, _ctx);
      kk_evv_t _x_x311 = kk_evv_dup(w0_1_sq_, _ctx); /*hnd/evv<3690>*/
      kk_std_core_hnd__ev _x_x312 = kk_std_core_hnd__ev_dup(ev, _ctx); /*hnd/ev<3691>*/
      w1_1_sq_ = kk_std_core_hnd_evv_insert(_x_x311, _x_x312, _ctx); /*hnd/evv<3690>*/
    }
    kk_unit_t ___3 = kk_Unit;
    kk_evv_t _x_x313 = kk_evv_dup(w1_1_sq_, _ctx); /*hnd/evv<3690>*/
    kk_evv_set(_x_x313,kk_context());
    kk_box_t _x_x314 = kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), cont_0, (cont_0, kk_std_core_hnd_new_prompt_fun315(x_1_0, m, _ctx), _ctx), _ctx); /*3689*/
    return kk_std_core_hnd_prompt(w0_1_sq_, w1_1_sq_, ev, m, ret, _x_x314, _ctx);
  }
}

kk_box_t kk_std_core_hnd_prompt(kk_evv_t w0, kk_evv_t w1, kk_std_core_hnd__ev ev, int32_t m, kk_function_t ret, kk_box_t result, kk_context_t* _ctx) { /* forall<a,e,b,c> (w0 : evv<e>, w1 : evv<e>, ev : ev<b>, m : marker<e,c>, ret : (a) -> e c, result : a) -> e c */ 
  kk_unit_t __ = kk_Unit;
  kk_evv_t _x_x294 = kk_evv_dup(w1, _ctx); /*hnd/evv<3690>*/
  kk_std_core_hnd_guard(_x_x294, _ctx);
  kk_unit_t ___0 = kk_Unit;
  kk_evv_t _x_x295 = kk_evv_dup(w0, _ctx); /*hnd/evv<3690>*/
  kk_evv_set(_x_x295,kk_context());
  kk_std_core_hnd__yld _match_x259 = kk_std_core_hnd_yield_prompt(m, _ctx); /*hnd/yld<3138,3137,3139>*/;
  if (kk_std_core_hnd__is_Pure(_match_x259, _ctx)) {
    kk_evv_drop(w1, _ctx);
    kk_evv_drop(w0, _ctx);
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), ret, (ret, result, _ctx), _ctx);
  }
  if (kk_std_core_hnd__is_YieldingFinal(_match_x259, _ctx)) {
    kk_evv_drop(w1, _ctx);
    kk_evv_drop(w0, _ctx);
    kk_function_drop(ret, _ctx);
    kk_box_drop(result, _ctx);
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return kk_box_any(kk_context());
  }
  if (kk_std_core_hnd__is_Yielding(_match_x259, _ctx)) {
    kk_box_drop(result, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_prompt_fun296(ev, ret, w0, w1, m, _ctx), _ctx);
  }
  {
    kk_function_t clause = _match_x259._cons.Yield.clause;
    kk_function_t cont_0 = _match_x259._cons.Yield.cont;
    kk_box_drop(result, _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), clause, (clause, kk_std_core_hnd_new_prompt_fun302(cont_0, ev, ret, w0, w1, m, _ctx), _ctx), _ctx);
  }
}

kk_box_t kk_std_core_hnd__hhandle(kk_std_core_hnd__htag tag, kk_box_t h, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,e1,b,c> (tag : htag<b>, h : b<e,c>, ret : (a) -> e c, action : () -> e1 a) -> e c */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_get(_ctx); /*hnd/evv<3802>*/;
  int32_t m = kk_std_core_hnd_fresh_marker(_ctx); /*hnd/marker<3802,3805>*/;
  kk_std_core_hnd__ev ev;
  kk_evv_t _x_x317 = kk_evv_dup(w0, _ctx); /*hnd/evv<3802>*/
  ev = kk_std_core_hnd__new_Ev(kk_reuse_null, 0, tag, m, h, _x_x317, _ctx); /*hnd/ev<3804>*/
  kk_evv_t w1;
  kk_evv_t _x_x318 = kk_evv_dup(w0, _ctx); /*hnd/evv<3802>*/
  kk_std_core_hnd__ev _x_x319 = kk_std_core_hnd__ev_dup(ev, _ctx); /*hnd/ev<3804>*/
  w1 = kk_std_core_hnd_evv_insert(_x_x318, _x_x319, _ctx); /*hnd/evv<3802>*/
  kk_unit_t __ = kk_Unit;
  kk_evv_t _x_x320 = kk_evv_dup(w1, _ctx); /*hnd/evv<3802>*/
  kk_evv_set(_x_x320,kk_context());
  kk_box_t _x_x321 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*3801*/
  return kk_std_core_hnd_prompt(w0, w1, ev, m, ret, _x_x321, _ctx);
}

kk_box_t kk_std_core_hnd__named_handle(kk_std_core_hnd__htag tag, kk_box_t h, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,e1,b,c> (tag : htag<b>, h : b<e,c>, ret : (a) -> e c, action : (ev<b>) -> e1 a) -> e c */ 
  int32_t m = kk_std_core_hnd_fresh_marker_named(_ctx); /*hnd/marker<3902,3905>*/;
  kk_evv_t w0 = kk_std_core_hnd_evv_get(_ctx); /*hnd/evv<3902>*/;
  kk_std_core_hnd__ev ev;
  kk_evv_t _x_x322 = kk_evv_dup(w0, _ctx); /*hnd/evv<3902>*/
  ev = kk_std_core_hnd__new_Ev(kk_reuse_null, 0, tag, m, h, _x_x322, _ctx); /*hnd/ev<3904>*/
  kk_evv_t _x_x323 = kk_evv_dup(w0, _ctx); /*hnd/evv<3902>*/
  kk_std_core_hnd__ev _x_x324 = kk_std_core_hnd__ev_dup(ev, _ctx); /*hnd/ev<3904>*/
  kk_box_t _x_x325 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__ev, kk_context_t*), action, (action, ev, _ctx), _ctx); /*3901*/
  return kk_std_core_hnd_prompt(_x_x323, w0, _x_x324, m, ret, _x_x325, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_mask_at1_fun326__t {
  struct kk_function_s _base;
  kk_ssize_t i;
  bool behind;
};
static kk_box_t kk_std_core_hnd_mask_at1_fun326(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_mask_at1_fun326(kk_ssize_t i, bool behind, kk_context_t* _ctx) {
  struct kk_std_core_hnd_mask_at1_fun326__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_mask_at1_fun326__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_mask_at1_fun326, kk_context());
  _self->i = i;
  _self->behind = behind;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_mask_at1_fun326(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_mask_at1_fun326__t* _self = kk_function_as(struct kk_std_core_hnd_mask_at1_fun326__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  bool behind = _self->behind; /* bool */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);kk_skip_dup(behind, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_mask_at1(i, behind, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd_mask_at1(kk_ssize_t i, bool behind, kk_function_t action, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,e1> (i : ev-index, behind : bool, action : (a) -> e b, x : a) -> e1 b */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(i, behind, _ctx); /*hnd/evv<_3930>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), action, (action, x, _ctx), _ctx); /*4019*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_mask_at1_fun326(i, behind, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__mask_at_fun327__t {
  struct kk_function_s _base;
  kk_ssize_t i;
  bool behind;
};
static kk_box_t kk_std_core_hnd__mask_at_fun327(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_mask_at_fun327(kk_ssize_t i, bool behind, kk_context_t* _ctx) {
  struct kk_std_core_hnd__mask_at_fun327__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__mask_at_fun327__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__mask_at_fun327, kk_context());
  _self->i = i;
  _self->behind = behind;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__mask_at_fun327(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__mask_at_fun327__t* _self = kk_function_as(struct kk_std_core_hnd__mask_at_fun327__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  bool behind = _self->behind; /* bool */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);kk_skip_dup(behind, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_mask_at1(i, behind, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__mask_at(kk_ssize_t i, bool behind, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,e1> (i : ev-index, behind : bool, action : () -> e a) -> e1 a */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(i, behind, _ctx); /*hnd/evv<_4042>*/;
  kk_box_t x = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*4118*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(x, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_mask_at_fun327(i, behind, _ctx), _ctx);
  }
  {
    return x;
  }
}


// lift anonymous function
struct kk_std_core_hnd_prompt_local_var_fun329__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_box_t v;
};
static kk_box_t kk_std_core_hnd_prompt_local_var_fun329(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_local_var_fun329(kk_ref_t loc, kk_box_t v, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_local_var_fun329__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_local_var_fun329__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_local_var_fun329, kk_context());
  _self->loc = loc;
  _self->v = v;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_prompt_local_var_fun329(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_local_var_fun329__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_local_var_fun329__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<4278,4275> */
  kk_box_t v = _self->v; /* 4275 */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);kk_box_dup(v, _ctx);}, {}, _ctx)
  kk_unit_t ___0 = kk_Unit;
  kk_ref_set_borrow(loc,v,kk_context());
  kk_box_t _x_x330 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, x, _ctx), _ctx); /*4276*/
  return kk_std_core_hnd_prompt_local_var(loc, _x_x330, _ctx);
}

kk_box_t kk_std_core_hnd_prompt_local_var(kk_ref_t loc, kk_box_t res, kk_context_t* _ctx) { /* forall<a,b,h> (loc : local-var<h,a>, res : b) -> <div,local<h>> b */ 
  if (kk_yielding(kk_context())) {
    kk_box_drop(res, _ctx);
    kk_box_t v;
    kk_ref_t _x_x328 = kk_ref_dup(loc, _ctx); /*local-var<4278,4275>*/
    v = kk_ref_get(_x_x328,kk_context()); /*4275*/
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_prompt_local_var_fun329(loc, v, _ctx), _ctx);
  }
  {
    kk_ref_drop(loc, _ctx);
    return res;
  }
}


// lift anonymous function
struct kk_std_core_hnd_finally_prompt_fun332__t {
  struct kk_function_s _base;
  kk_function_t fin;
};
static kk_box_t kk_std_core_hnd_finally_prompt_fun332(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_finally_prompt_fun332(kk_function_t fin, kk_context_t* _ctx) {
  struct kk_std_core_hnd_finally_prompt_fun332__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_finally_prompt_fun332__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_finally_prompt_fun332, kk_context());
  _self->fin = fin;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_finally_prompt_fun332(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_finally_prompt_fun332__t* _self = kk_function_as(struct kk_std_core_hnd_finally_prompt_fun332__t*, _fself, _ctx);
  kk_function_t fin = _self->fin; /* () -> 4479 () */
  kk_drop_match(_self, {kk_function_dup(fin, _ctx);}, {}, _ctx)
  kk_box_t _x_x333 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, x, _ctx), _ctx); /*4478*/
  return kk_std_core_hnd_finally_prompt(fin, _x_x333, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_finally_prompt_fun334__t {
  struct kk_function_s _base;
  kk_std_core_hnd__yield_info yld;
};
static kk_box_t kk_std_core_hnd_finally_prompt_fun334(kk_function_t _fself, kk_box_t ___wildcard_x485__43, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_finally_prompt_fun334(kk_std_core_hnd__yield_info yld, kk_context_t* _ctx) {
  struct kk_std_core_hnd_finally_prompt_fun334__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_finally_prompt_fun334__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_finally_prompt_fun334, kk_context());
  _self->yld = yld;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_finally_prompt_fun334(kk_function_t _fself, kk_box_t ___wildcard_x485__43, kk_context_t* _ctx) {
  struct kk_std_core_hnd_finally_prompt_fun334__t* _self = kk_function_as(struct kk_std_core_hnd_finally_prompt_fun334__t*, _fself, _ctx);
  kk_std_core_hnd__yield_info yld = _self->yld; /* hnd/yield-info */
  kk_drop_match(_self, {kk_std_core_hnd__yield_info_dup(yld, _ctx);}, {}, _ctx)
  kk_box_drop(___wildcard_x485__43, _ctx);
  return kk_std_core_hnd_unsafe_reyield(yld, _ctx);
}

kk_box_t kk_std_core_hnd_finally_prompt(kk_function_t fin, kk_box_t res, kk_context_t* _ctx) { /* forall<a,e> (fin : () -> e (), res : a) -> e a */ 
  if (kk_yielding(kk_context())) {
    kk_box_drop(res, _ctx);
    bool _match_x255 = kk_yielding_non_final(kk_context()); /*bool*/;
    if (_match_x255) {
      return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_finally_prompt_fun332(fin, _ctx), _ctx);
    }
    {
      kk_std_core_hnd__yield_info yld = kk_std_core_hnd_yield_capture(_ctx); /*hnd/yield-info*/;
      kk_unit_t ___0 = kk_Unit;
      kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), fin, (fin, _ctx), _ctx);
      if (kk_yielding(kk_context())) {
        return kk_std_core_hnd_yield_extend(kk_std_core_hnd_new_finally_prompt_fun334(yld, _ctx), _ctx);
      }
      {
        return kk_std_core_hnd_unsafe_reyield(yld, _ctx);
      }
    }
  }
  {
    kk_unit_t __ = kk_Unit;
    kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), fin, (fin, _ctx), _ctx);
    return res;
  }
}


// lift anonymous function
struct kk_std_core_hnd_initially_prompt_fun336__t {
  struct kk_function_s _base;
  kk_ref_t count;
  kk_function_t init;
};
static kk_box_t kk_std_core_hnd_initially_prompt_fun336(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_initially_prompt_fun336(kk_ref_t count, kk_function_t init, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_prompt_fun336__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_initially_prompt_fun336__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_initially_prompt_fun336, kk_context());
  _self->count = count;
  _self->init = init;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_initially_prompt_fun342__t {
  struct kk_function_s _base;
  kk_function_t cont;
  kk_function_t init;
  kk_box_t x;
};
static kk_box_t kk_std_core_hnd_initially_prompt_fun342(kk_function_t _fself, kk_box_t ___wildcard_x526__35, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_initially_prompt_fun342(kk_function_t cont, kk_function_t init, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_prompt_fun342__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_initially_prompt_fun342__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_initially_prompt_fun342, kk_context());
  _self->cont = cont;
  _self->init = init;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_initially_prompt_fun342(kk_function_t _fself, kk_box_t ___wildcard_x526__35, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_prompt_fun342__t* _self = kk_function_as(struct kk_std_core_hnd_initially_prompt_fun342__t*, _fself, _ctx);
  kk_function_t cont = _self->cont; /* (4671) -> 4681 4680 */
  kk_function_t init = _self->init; /* (int) -> 4681 () */
  kk_box_t x = _self->x; /* 4671 */
  kk_drop_match(_self, {kk_function_dup(cont, _ctx);kk_function_dup(init, _ctx);kk_box_dup(x, _ctx);}, {}, _ctx)
  kk_box_drop(___wildcard_x526__35, _ctx);
  kk_box_t _x_x343 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, x, _ctx), _ctx); /*4680*/
  return kk_std_core_hnd_initially_prompt(init, _x_x343, _ctx);
}
static kk_box_t kk_std_core_hnd_initially_prompt_fun336(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_prompt_fun336__t* _self = kk_function_as(struct kk_std_core_hnd_initially_prompt_fun336__t*, _fself, _ctx);
  kk_ref_t count = _self->count; /* ref<global,int> */
  kk_function_t init = _self->init; /* (int) -> 4681 () */
  kk_drop_match(_self, {kk_ref_dup(count, _ctx);kk_function_dup(init, _ctx);}, {}, _ctx)
  kk_integer_t cnt;
  kk_box_t _x_x337;
  kk_ref_t _x_x338 = kk_ref_dup(count, _ctx); /*ref<global,int>*/
  _x_x337 = kk_ref_get(_x_x338,kk_context()); /*209*/
  cnt = kk_integer_unbox(_x_x337, _ctx); /*int*/
  kk_integer_t _b_x64_66;
  kk_integer_t _x_x339 = kk_integer_dup(cnt, _ctx); /*int*/
  _b_x64_66 = kk_integer_add(_x_x339,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x254 = kk_Unit;
  kk_ref_set_borrow(count,(kk_integer_box(_b_x64_66, _ctx)),kk_context());
  kk_ref_drop(count, _ctx);
  _brw_x254;
  kk_unit_t ___1 = kk_Unit;
  bool _match_x252 = kk_integer_eq_borrow(cnt,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x252) {
    kk_integer_drop(cnt, _ctx);
  }
  else {
    kk_unit_t r = kk_Unit;
    kk_function_t _x_x340 = kk_function_dup(init, _ctx); /*(int) -> 4681 ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x340, (_x_x340, cnt, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t ___0;
      kk_function_t _x_x341;
      kk_function_dup(cont, _ctx);
      kk_function_dup(init, _ctx);
      kk_box_dup(x, _ctx);
      _x_x341 = kk_std_core_hnd_new_initially_prompt_fun342(cont, init, x, _ctx); /*(_4627) -> 4681 759*/
      ___0 = kk_std_core_hnd_yield_extend(_x_x341, _ctx); /*4680*/
      kk_box_drop(___0, _ctx);
    }
    else {
      
    }
  }
  kk_box_t _x_x344 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, x, _ctx), _ctx); /*4680*/
  return kk_std_core_hnd_initially_prompt(init, _x_x344, _ctx);
}

kk_box_t kk_std_core_hnd_initially_prompt(kk_function_t init, kk_box_t res, kk_context_t* _ctx) { /* forall<a,e> (init : (int) -> e (), res : a) -> e a */ 
  bool _match_x251 = kk_yielding_non_final(kk_context()); /*bool*/;
  if (_match_x251) {
    kk_box_drop(res, _ctx);
    kk_ref_t count = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0), _ctx)),kk_context()); /*ref<global,int>*/;
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_initially_prompt_fun336(count, init, _ctx), _ctx);
  }
  {
    kk_function_drop(init, _ctx);
    return res;
  }
}


// lift anonymous function
struct kk_std_core_hnd_initially_fun346__t {
  struct kk_function_s _base;
  kk_function_t action;
  kk_function_t init;
};
static kk_box_t kk_std_core_hnd_initially_fun346(kk_function_t _fself, kk_box_t _b_x68, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_initially_fun346(kk_function_t action, kk_function_t init, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_fun346__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_initially_fun346__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_initially_fun346, kk_context());
  _self->action = action;
  _self->init = init;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_initially_fun346(kk_function_t _fself, kk_box_t _b_x68, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_fun346__t* _self = kk_function_as(struct kk_std_core_hnd_initially_fun346__t*, _fself, _ctx);
  kk_function_t action = _self->action; /* () -> 4735 4734 */
  kk_function_t init = _self->init; /* (int) -> 4735 () */
  kk_drop_match(_self, {kk_function_dup(action, _ctx);kk_function_dup(init, _ctx);}, {}, _ctx)
  kk_box_drop(_b_x68, _ctx);
  kk_box_t _x_x347 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*4734*/
  return kk_std_core_hnd_initially_prompt(init, _x_x347, _ctx);
}

kk_box_t kk_std_core_hnd_initially(kk_function_t init, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (init : (int) -> e (), action : () -> e a) -> e a */ 
  kk_unit_t __ = kk_Unit;
  kk_function_t _x_x345 = kk_function_dup(init, _ctx); /*(int) -> 4735 ()*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x345, (_x_x345, kk_integer_from_small(0), _ctx), _ctx);
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_std_core_hnd_new_initially_fun346(action, init, _ctx), _ctx);
  }
  {
    kk_box_t _x_x348 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*4734*/
    return kk_std_core_hnd_initially_prompt(init, _x_x348, _ctx);
  }
}

kk_evv_t kk_std_core_hnd_evv_swap_with(kk_std_core_hnd__ev ev, kk_context_t* _ctx) { /* forall<a,e> (ev : ev<a>) -> evv<e> */ 
  kk_evv_t _x_x353;
  {
    struct kk_std_core_hnd_Ev* _con_x354 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_std_core_hnd__htag _pat_0 = _con_x354->htag;
    kk_box_t _pat_2 = _con_x354->hnd;
    kk_evv_t w = _con_x354->hevv;
    if kk_likely(kk_datatype_ptr_is_unique(ev, _ctx)) {
      kk_box_drop(_pat_2, _ctx);
      kk_std_core_hnd__htag_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(ev, _ctx);
    }
    else {
      kk_evv_dup(w, _ctx);
      kk_datatype_ptr_decref(ev, _ctx);
    }
    _x_x353 = w; /*hnd/evv<5010>*/
  }
  return kk_evv_swap(_x_x353,kk_context());
}
 
// extra under1x to make under1 inlineable


// lift anonymous function
struct kk_std_core_hnd_under1x_fun357__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under1x_fun357(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under1x_fun357(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under1x_fun357__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under1x_fun357__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under1x_fun357, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_under1x_fun357(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under1x_fun357__t* _self = kk_function_as(struct kk_std_core_hnd_under1x_fun357__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<5129> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd_under1x(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,c> (ev : ev<c>, op : (a) -> e b, x : a) -> e b */ 
  kk_evv_t w0;
  kk_evv_t _x_x355;
  {
    struct kk_std_core_hnd_Ev* _con_x356 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x356->hevv;
    kk_evv_dup(w, _ctx);
    _x_x355 = w; /*hnd/evv<5010>*/
  }
  w0 = kk_evv_swap(_x_x355,kk_context()); /*hnd/evv<_5055>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), op, (op, x, _ctx), _ctx); /*5127*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under1x_fun357(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0,kk_context());
    return y;
  }
}
extern kk_box_t kk_std_core_hnd_under1_fun360(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under1_fun360__t* _self = kk_function_as(struct kk_std_core_hnd_under1_fun360__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<5227> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont, res, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control_raw1_fun361__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw1_fun361(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x593__16, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw1_fun361(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw1_fun361__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw1_fun361__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw1_fun361, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control_raw1_fun362__t {
  struct kk_function_s _base;
  kk_function_t op;
  kk_box_t x;
};
static kk_box_t kk_std_core_hnd_clause_control_raw1_fun362(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw1_fun362(kk_function_t op, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw1_fun362__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw1_fun362__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw1_fun362, kk_context());
  _self->op = op;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control_raw1_fun362(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw1_fun362__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw1_fun362__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x : 5309, r : hnd/resume-context<5310,5311,5312,5314>) -> 5311 5314 */
  kk_box_t x = _self->x; /* 5309 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);kk_box_dup(x, _ctx);}, {}, _ctx)
  kk_std_core_hnd__resume_context _x_x363 = kk_std_core_hnd__new_Resume_context(k, _ctx); /*hnd/resume-context<83,84,85,86>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_std_core_hnd__resume_context, kk_context_t*), op, (op, x, _x_x363, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control_raw1_fun361(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x593__16, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw1_fun361__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw1_fun361__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x : 5309, r : hnd/resume-context<5310,5311,5312,5314>) -> 5311 5314 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x593__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control_raw1_fun362(op, x, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_control_raw1(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,e,e1,c,d> (op : (x : a, r : resume-context<b,e,e1,d>) -> e d) -> clause1<a,b,c,e,d> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_control_raw1_fun361(op, _ctx), _ctx);
}

kk_box_t kk_std_core_hnd_protect_check(kk_ref_t resumed, kk_function_t k, kk_box_t res, kk_context_t* _ctx) { /* forall<a,e,b> (resumed : ref<global,bool>, k : (resume-result<a,b>) -> e b, res : b) -> e b */ 
  bool did_resume;
  kk_box_t _x_x364 = kk_ref_get(resumed,kk_context()); /*209*/
  did_resume = kk_bool_unbox(_x_x364); /*bool*/
  if (did_resume) {
    kk_function_drop(k, _ctx);
    return res;
  }
  {
    kk_std_core_hnd__resume_result _x_x365 = kk_std_core_hnd__new_Finalize(res, _ctx); /*hnd/resume-result<74,75>*/
    return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x365, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_core_hnd_protect_fun367__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_protect_fun367(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_protect_fun367(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect_fun367__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_protect_fun367__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_protect_fun367, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_protect_fun367(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect_fun367__t* _self = kk_function_as(struct kk_std_core_hnd_protect_fun367__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<5566,5568>) -> 5567 5568 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x246 = kk_Unit;
  kk_ref_set_borrow(resumed,(kk_bool_box(true)),kk_context());
  kk_ref_drop(resumed, _ctx);
  _brw_x246;
  kk_std_core_hnd__resume_result _x_x368 = kk_std_core_hnd__new_Deep(ret, _ctx); /*hnd/resume-result<74,75>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x368, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_protect_fun369__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_protect_fun369(kk_function_t _fself, kk_box_t xres, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_protect_fun369(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect_fun369__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_protect_fun369__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_protect_fun369, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_protect_fun369(kk_function_t _fself, kk_box_t xres, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect_fun369__t* _self = kk_function_as(struct kk_std_core_hnd_protect_fun369__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<5566,5568>) -> 5567 5568 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_protect_check(resumed, k, xres, _ctx);
}

kk_box_t kk_std_core_hnd_protect(kk_box_t x, kk_function_t clause, kk_function_t k, kk_context_t* _ctx) { /* forall<a,b,e,c> (x : a, clause : (x : a, k : (b) -> e c) -> e c, k : (resume-result<b,c>) -> e c) -> e c */ 
  kk_ref_t resumed = kk_ref_alloc((kk_bool_box(false)),kk_context()); /*ref<global,bool>*/;
  kk_box_t res;
  kk_function_t _x_x366;
  kk_function_dup(k, _ctx);
  kk_ref_dup(resumed, _ctx);
  _x_x366 = kk_std_core_hnd_new_protect_fun367(k, resumed, _ctx); /*(ret : 5566) -> 5567 5568*/
  res = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_function_t, kk_context_t*), clause, (clause, x, _x_x366, _ctx), _ctx); /*5568*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(res, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_core_hnd_new_protect_fun369(k, resumed, _ctx), _ctx);
  }
  {
    return kk_std_core_hnd_protect_check(resumed, k, res, _ctx);
  }
}
extern kk_box_t kk_std_core_hnd_clause_control1_fun371(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control1_fun371__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control1_fun371__t*, _fself, _ctx);
  kk_function_t clause = _self->clause; /* (x : 5645, k : (5646) -> 5647 5649) -> 5647 5649 */
  kk_box_t x = _self->x; /* 5645 */
  kk_drop_match(_self, {kk_function_dup(clause, _ctx);kk_box_dup(x, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_protect(x, clause, k, _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_control1_fun370(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x623__16, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control1_fun370__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control1_fun370__t*, _fself, _ctx);
  kk_function_t clause = _self->clause; /* (x : 5645, k : (5646) -> 5647 5649) -> 5647 5649 */
  kk_drop_match(_self, {kk_function_dup(clause, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x623__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control1_fun371(clause, x, _ctx), _ctx);
}
 
// tail-resumptive clause: resumes exactly once at the end
// (these can be executed 'in-place' without capturing a resumption)


// lift anonymous function
struct kk_std_core_hnd_clause_tail1_fun372__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_tail1_fun372(kk_function_t _fself, int32_t ___wildcard_x628__14, kk_std_core_hnd__ev ev, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail1_fun372(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail1_fun372__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail1_fun372__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail1_fun372, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_tail1_fun375__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_clause_tail1_fun375(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail1_fun375(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail1_fun375__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail1_fun375__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail1_fun375, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_tail1_fun375(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail1_fun375__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail1_fun375__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<5720> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont, res, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_tail1_fun372(kk_function_t _fself, int32_t ___wildcard_x628__14, kk_std_core_hnd__ev ev, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail1_fun372__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail1_fun372__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (5721) -> 5718 5722 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_evv_t w0;
  kk_evv_t _x_x373;
  {
    struct kk_std_core_hnd_Ev* _con_x374 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x374->hevv;
    kk_evv_dup(w, _ctx);
    _x_x373 = w; /*hnd/evv<5010>*/
  }
  w0 = kk_evv_swap(_x_x373,kk_context()); /*hnd/evv<_5153>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), op, (op, x, _ctx), _ctx); /*5722*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_clause_tail1_fun375(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0,kk_context());
    return y;
  }
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail1(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c,d> (op : (c) -> e d) -> clause1<c,d,b,e,a> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_tail1_fun372(op, _ctx), _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_tail_noop1_fun376(kk_function_t _fself, int32_t ___wildcard_x633__14, kk_std_core_hnd__ev ___wildcard_x633__17, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop1_fun376__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail_noop1_fun376__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (5780) -> 5777 5781 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x633__17, (KK_I32(3)), _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), op, (op, x, _ctx), _ctx);
}
 
// clause that never resumes (e.g. an exception handler)
// (these do not need to capture a resumption and execute finally clauses upfront)


// lift anonymous function
struct kk_std_core_hnd_clause_never1_fun377__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never1_fun377(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x638__16, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never1_fun377(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never1_fun377__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never1_fun377__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never1_fun377, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_never1_fun378__t {
  struct kk_function_s _base;
  kk_function_t op;
  kk_box_t x;
};
static kk_box_t kk_std_core_hnd_clause_never1_fun378(kk_function_t _fself, kk_function_t ___wildcard_x638__45, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never1_fun378(kk_function_t op, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never1_fun378__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never1_fun378__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never1_fun378, kk_context());
  _self->op = op;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_never1_fun378(kk_function_t _fself, kk_function_t ___wildcard_x638__45, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never1_fun378__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never1_fun378__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (5851) -> 5853 5855 */
  kk_box_t x = _self->x; /* 5851 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);kk_box_dup(x, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x638__45, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), op, (op, x, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_never1_fun377(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x638__16, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never1_fun377__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never1_fun377__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (5851) -> 5853 5855 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x638__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_hnd_new_clause_never1_fun378(op, x, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_never1(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,e,c,d> (op : (a) -> e d) -> clause1<a,b,c,e,d> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_never1_fun377(op, _ctx), _ctx);
}
extern kk_box_t kk_std_core_hnd_under0_fun385(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under0_fun385__t* _self = kk_function_as(struct kk_std_core_hnd_under0_fun385__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<6019> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont_0, res_0, _ctx);
}
extern kk_box_t kk_std_core_hnd_under0_fun382(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under0_fun382__t* _self = kk_function_as(struct kk_std_core_hnd_under0_fun382__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<6019> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  kk_evv_t w0_0;
  kk_evv_t _x_x383;
  {
    struct kk_std_core_hnd_Ev* _con_x384 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w_0 = _con_x384->hevv;
    kk_evv_dup(w_0, _ctx);
    _x_x383 = w_0; /*hnd/evv<5010>*/
  }
  w0_0 = kk_evv_swap(_x_x383,kk_context()); /*hnd/evv<_5153>*/
  kk_box_t y_0 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*6017*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y_0, _ctx);
    kk_evv_drop(w0_0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under0_fun385(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0_0,kk_context());
    return y_0;
  }
}


// lift anonymous function
struct kk_std_core_hnd_clause_control_raw0_fun386__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw0_fun386(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x664__16, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw0_fun386(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw0_fun386__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw0_fun386__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw0_fun386, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control_raw0_fun387__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw0_fun387(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw0_fun387(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw0_fun387__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw0_fun387__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw0_fun387, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control_raw0_fun387(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw0_fun387__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw0_fun387__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (hnd/resume-context<6091,6092,6093,6095>) -> 6092 6095 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_std_core_hnd__resume_context _x_x388 = kk_std_core_hnd__new_Resume_context(k, _ctx); /*hnd/resume-context<83,84,85,86>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_context, kk_context_t*), op, (op, _x_x388, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control_raw0_fun386(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x664__16, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw0_fun386__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw0_fun386__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (hnd/resume-context<6091,6092,6093,6095>) -> 6092 6095 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x664__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control_raw0_fun387(op, _ctx), _ctx);
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause_control_raw0(kk_function_t op, kk_context_t* _ctx) { /* forall<a,e,e1,b,c> (op : (resume-context<a,e,e1,c>) -> e c) -> clause0<a,b,e,c> */ 
  return kk_std_core_hnd__new_Clause0(kk_std_core_hnd_new_clause_control_raw0_fun386(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control0_fun389__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control0_fun389(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x672__16, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control0_fun389(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun389__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control0_fun389__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control0_fun389, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control0_fun390__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control0_fun390(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control0_fun390(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun390__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control0_fun390__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control0_fun390, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control0_fun392__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_clause_control0_fun392(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control0_fun392(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun392__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control0_fun392__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control0_fun392, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control0_fun392(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun392__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control0_fun392__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<6172,6175>) -> 6173 6175 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x240 = kk_Unit;
  kk_ref_set_borrow(resumed,(kk_bool_box(true)),kk_context());
  kk_ref_drop(resumed, _ctx);
  _brw_x240;
  kk_std_core_hnd__resume_result _x_x393 = kk_std_core_hnd__new_Deep(ret, _ctx); /*hnd/resume-result<74,75>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x393, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control0_fun394__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_clause_control0_fun394(kk_function_t _fself, kk_box_t xres, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control0_fun394(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun394__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control0_fun394__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control0_fun394, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control0_fun394(kk_function_t _fself, kk_box_t xres, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun394__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control0_fun394__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<6172,6175>) -> 6173 6175 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_protect_check(resumed, k, xres, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control0_fun390(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun390__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control0_fun390__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* ((6172) -> 6173 6175) -> 6173 6175 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_ref_t resumed = kk_ref_alloc((kk_bool_box(false)),kk_context()); /*ref<global,bool>*/;
  kk_box_t res;
  kk_function_t _x_x391;
  kk_function_dup(k, _ctx);
  kk_ref_dup(resumed, _ctx);
  _x_x391 = kk_std_core_hnd_new_clause_control0_fun392(k, resumed, _ctx); /*(ret : 6172) -> 6173 6175*/
  res = kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), op, (op, _x_x391, _ctx), _ctx); /*6175*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(res, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_core_hnd_new_clause_control0_fun394(k, resumed, _ctx), _ctx);
  }
  {
    return kk_std_core_hnd_protect_check(resumed, k, res, _ctx);
  }
}
static kk_box_t kk_std_core_hnd_clause_control0_fun389(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x672__16, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun389__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control0_fun389__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* ((6172) -> 6173 6175) -> 6173 6175 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x672__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control0_fun390(op, _ctx), _ctx);
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause_control0(kk_function_t op, kk_context_t* _ctx) { /* forall<a,e,b,c> (op : ((a) -> e c) -> e c) -> clause0<a,b,e,c> */ 
  return kk_std_core_hnd__new_Clause0(kk_std_core_hnd_new_clause_control0_fun389(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_tail0_fun395__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_tail0_fun395(kk_function_t _fself, int32_t ___wildcard_x676__14, kk_std_core_hnd__ev ev, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail0_fun395(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun395__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail0_fun395__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail0_fun395, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_tail0_fun398__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_clause_tail0_fun398(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail0_fun398(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun398__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail0_fun398__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail0_fun398, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_tail0_fun401__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_clause_tail0_fun401(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail0_fun401(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun401__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail0_fun401__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail0_fun401, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_tail0_fun401(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun401__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail0_fun401__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<6233> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont_0, res_0, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_tail0_fun398(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun398__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail0_fun398__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<6233> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  kk_evv_t w0_0;
  kk_evv_t _x_x399;
  {
    struct kk_std_core_hnd_Ev* _con_x400 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w_0 = _con_x400->hevv;
    kk_evv_dup(w_0, _ctx);
    _x_x399 = w_0; /*hnd/evv<5010>*/
  }
  w0_0 = kk_evv_swap(_x_x399,kk_context()); /*hnd/evv<_5153>*/
  kk_box_t y_0 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*6234*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y_0, _ctx);
    kk_evv_drop(w0_0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_clause_tail0_fun401(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0_0,kk_context());
    return y_0;
  }
}
static kk_box_t kk_std_core_hnd_clause_tail0_fun395(kk_function_t _fself, int32_t ___wildcard_x676__14, kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun395__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail0_fun395__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* () -> 6231 6234 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_evv_t w0;
  kk_evv_t _x_x396;
  {
    struct kk_std_core_hnd_Ev* _con_x397 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x397->hevv;
    kk_evv_dup(w, _ctx);
    _x_x396 = w; /*hnd/evv<5010>*/
  }
  w0 = kk_evv_swap(_x_x396,kk_context()); /*hnd/evv<_5955>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), op, (op, _ctx), _ctx); /*6234*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_clause_tail0_fun398(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return y;
  }
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause_tail0(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c> (op : () -> e c) -> clause0<c,b,e,a> */ 
  return kk_std_core_hnd__new_Clause0(kk_std_core_hnd_new_clause_tail0_fun395(op, _ctx), _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_tail_noop0_fun402(kk_function_t _fself, int32_t ___wildcard_x679__14, kk_std_core_hnd__ev ___wildcard_x679__17, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop0_fun402__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail_noop0_fun402__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* () -> 6279 6282 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x679__17, (KK_I32(3)), _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), op, (op, _ctx), _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_value_fun403(kk_function_t _fself, int32_t ___wildcard_x682__14, kk_std_core_hnd__ev ___wildcard_x682__17, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_value_fun403__t* _self = kk_function_as(struct kk_std_core_hnd_clause_value_fun403__t*, _fself, _ctx);
  kk_box_t v = _self->v; /* 6327 */
  kk_drop_match(_self, {kk_box_dup(v, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x682__17, (KK_I32(3)), _ctx);
  return v;
}


// lift anonymous function
struct kk_std_core_hnd_clause_never0_fun404__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never0_fun404(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x685__16, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never0_fun404(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never0_fun404__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never0_fun404__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never0_fun404, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_never0_fun405__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never0_fun405(kk_function_t _fself, kk_function_t ___wildcard_x685__43, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never0_fun405(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never0_fun405__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never0_fun405__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never0_fun405, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_never0_fun405(kk_function_t _fself, kk_function_t ___wildcard_x685__43, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never0_fun405__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never0_fun405__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* () -> 6391 6393 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x685__43, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), op, (op, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_never0_fun404(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x685__16, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never0_fun404__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never0_fun404__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* () -> 6391 6393 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x685__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_hnd_new_clause_never0_fun405(op, _ctx), _ctx);
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause_never0(kk_function_t op, kk_context_t* _ctx) { /* forall<a,e,b,c> (op : () -> e c) -> clause0<a,b,e,c> */ 
  return kk_std_core_hnd__new_Clause0(kk_std_core_hnd_new_clause_never0_fun404(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_under2_fun408__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under2_fun408(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under2_fun408(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under2_fun408__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under2_fun408__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under2_fun408, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_under2_fun411__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under2_fun411(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under2_fun411(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under2_fun411__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under2_fun411__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under2_fun411, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_under2_fun411(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under2_fun411__t* _self = kk_function_as(struct kk_std_core_hnd_under2_fun411__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<6491> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont_0, res_0, _ctx);
}
static kk_box_t kk_std_core_hnd_under2_fun408(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under2_fun408__t* _self = kk_function_as(struct kk_std_core_hnd_under2_fun408__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<6491> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  kk_evv_t w0_0;
  kk_evv_t _x_x409;
  {
    struct kk_std_core_hnd_Ev* _con_x410 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w_0 = _con_x410->hevv;
    kk_evv_dup(w_0, _ctx);
    _x_x409 = w_0; /*hnd/evv<5010>*/
  }
  w0_0 = kk_evv_swap(_x_x409,kk_context()); /*hnd/evv<_5153>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*6489*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0_0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under2_fun411(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0_0,kk_context());
    return y;
  }
}

kk_box_t kk_std_core_hnd_under2(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) { /* forall<a,b,c,e,d> (ev : ev<d>, op : (a, b) -> e c, x1 : a, x2 : b) -> e c */ 
  kk_evv_t w0;
  kk_evv_t _x_x406;
  {
    struct kk_std_core_hnd_Ev* _con_x407 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x407->hevv;
    kk_evv_dup(w, _ctx);
    _x_x406 = w; /*hnd/evv<5010>*/
  }
  w0 = kk_evv_swap(_x_x406,kk_context()); /*hnd/evv<_6419>*/
  kk_box_t z = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, _ctx), _ctx); /*6489*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(z, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under2_fun408(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return z;
  }
}


// lift anonymous function
struct kk_std_core_hnd_protect2_fun413__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_protect2_fun413(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_protect2_fun413(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect2_fun413__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_protect2_fun413__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_protect2_fun413, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_protect2_fun413(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect2_fun413__t* _self = kk_function_as(struct kk_std_core_hnd_protect2_fun413__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<6634,6636>) -> 6635 6636 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x234 = kk_Unit;
  kk_ref_set_borrow(resumed,(kk_bool_box(true)),kk_context());
  kk_ref_drop(resumed, _ctx);
  _brw_x234;
  kk_std_core_hnd__resume_result _x_x414 = kk_std_core_hnd__new_Deep(ret, _ctx); /*hnd/resume-result<74,75>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x414, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_protect2_fun415__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_protect2_fun415(kk_function_t _fself, kk_box_t xres, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_protect2_fun415(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect2_fun415__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_protect2_fun415__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_protect2_fun415, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_protect2_fun415(kk_function_t _fself, kk_box_t xres, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect2_fun415__t* _self = kk_function_as(struct kk_std_core_hnd_protect2_fun415__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<6634,6636>) -> 6635 6636 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_protect_check(resumed, k, xres, _ctx);
}

kk_box_t kk_std_core_hnd_protect2(kk_box_t x1, kk_box_t x2, kk_function_t clause, kk_function_t k, kk_context_t* _ctx) { /* forall<a,b,c,e,d> (x1 : a, x2 : b, clause : (x : a, x : b, k : (c) -> e d) -> e d, k : (resume-result<c,d>) -> e d) -> e d */ 
  kk_ref_t resumed = kk_ref_alloc((kk_bool_box(false)),kk_context()); /*ref<global,bool>*/;
  kk_box_t res;
  kk_function_t _x_x412;
  kk_function_dup(k, _ctx);
  kk_ref_dup(resumed, _ctx);
  _x_x412 = kk_std_core_hnd_new_protect2_fun413(k, resumed, _ctx); /*(ret : 6634) -> 6635 6636*/
  res = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_function_t, kk_context_t*), clause, (clause, x1, x2, _x_x412, _ctx), _ctx); /*6636*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(res, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_core_hnd_new_protect2_fun415(k, resumed, _ctx), _ctx);
  }
  {
    return kk_std_core_hnd_protect_check(resumed, k, res, _ctx);
  }
}
extern kk_box_t kk_std_core_hnd_clause_control2_fun417(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control2_fun417__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control2_fun417__t*, _fself, _ctx);
  kk_function_t clause = _self->clause; /* (x1 : 6726, x2 : 6727, k : (6728) -> 6729 6731) -> 6729 6731 */
  kk_box_t x1 = _self->x1; /* 6726 */
  kk_box_t x2 = _self->x2; /* 6727 */
  kk_drop_match(_self, {kk_function_dup(clause, _ctx);kk_box_dup(x1, _ctx);kk_box_dup(x2, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_protect2(x1, x2, clause, k, _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_control2_fun416(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x711__16, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control2_fun416__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control2_fun416__t*, _fself, _ctx);
  kk_function_t clause = _self->clause; /* (x1 : 6726, x2 : 6727, k : (6728) -> 6729 6731) -> 6729 6731 */
  kk_drop_match(_self, {kk_function_dup(clause, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x711__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control2_fun417(clause, x1, x2, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control_raw2_fun418__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw2_fun418(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x715__16, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw2_fun418(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw2_fun418__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw2_fun418__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw2_fun418, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control_raw2_fun419__t {
  struct kk_function_s _base;
  kk_function_t op;
  kk_box_t x1;
  kk_box_t x2;
};
static kk_box_t kk_std_core_hnd_clause_control_raw2_fun419(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw2_fun419(kk_function_t op, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw2_fun419__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw2_fun419__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw2_fun419, kk_context());
  _self->op = op;
  _self->x1 = x1;
  _self->x2 = x2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control_raw2_fun419(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw2_fun419__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw2_fun419__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x1 : 6827, x2 : 6828, r : hnd/resume-context<6829,6830,6831,6833>) -> 6830 6833 */
  kk_box_t x1 = _self->x1; /* 6827 */
  kk_box_t x2 = _self->x2; /* 6828 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);kk_box_dup(x1, _ctx);kk_box_dup(x2, _ctx);}, {}, _ctx)
  kk_std_core_hnd__resume_context _x_x420 = kk_std_core_hnd__new_Resume_context(k, _ctx); /*hnd/resume-context<83,84,85,86>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_std_core_hnd__resume_context, kk_context_t*), op, (op, x1, x2, _x_x420, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control_raw2_fun418(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x715__16, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw2_fun418__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw2_fun418__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x1 : 6827, x2 : 6828, r : hnd/resume-context<6829,6830,6831,6833>) -> 6830 6833 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x715__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control_raw2_fun419(op, x1, x2, _ctx), _ctx);
}

kk_std_core_hnd__clause2 kk_std_core_hnd_clause_control_raw2(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,e,e1,d,a1> (op : (x1 : a, x2 : b, r : resume-context<c,e,e1,a1>) -> e a1) -> clause2<a,b,c,d,e,a1> */ 
  return kk_std_core_hnd__new_Clause2(kk_std_core_hnd_new_clause_control_raw2_fun418(op, _ctx), _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_tail2_fun421(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ev, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail2_fun421__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail2_fun421__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (6921, 6922) -> 6918 6923 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under2(ev, op, x1, x2, _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_tail_noop2_fun422(kk_function_t _fself, int32_t ___wildcard_x721__14, kk_std_core_hnd__ev ___wildcard_x721__17, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop2_fun422__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail_noop2_fun422__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (6991, 6992) -> 6988 6993 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x721__17, (KK_I32(3)), _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_never2_fun424__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never2_fun424(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x729__16, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never2_fun424(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never2_fun424__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never2_fun424__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never2_fun424, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_never2_fun425__t {
  struct kk_function_s _base;
  kk_function_t op;
  kk_box_t x1;
  kk_box_t x2;
};
static kk_box_t kk_std_core_hnd_clause_never2_fun425(kk_function_t _fself, kk_function_t ___wildcard_x729__49, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never2_fun425(kk_function_t op, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never2_fun425__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never2_fun425__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never2_fun425, kk_context());
  _self->op = op;
  _self->x1 = x1;
  _self->x2 = x2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_never2_fun425(kk_function_t _fself, kk_function_t ___wildcard_x729__49, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never2_fun425__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never2_fun425__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (7170, 7171) -> 7173 7175 */
  kk_box_t x1 = _self->x1; /* 7170 */
  kk_box_t x2 = _self->x2; /* 7171 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);kk_box_dup(x1, _ctx);kk_box_dup(x2, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x729__49, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_never2_fun424(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x729__16, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never2_fun424__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never2_fun424__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (7170, 7171) -> 7173 7175 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x729__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_hnd_new_clause_never2_fun425(op, x1, x2, _ctx), _ctx);
}

kk_std_core_hnd__clause2 kk_std_core_hnd_clause_never2(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,e,d,a1> (op : (a, b) -> e a1) -> clause2<a,b,c,d,e,a1> */ 
  return kk_std_core_hnd__new_Clause2(kk_std_core_hnd_new_clause_never2_fun424(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control_raw3_fun427__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw3_fun427(kk_function_t _fself, int32_t _b_x92, kk_std_core_hnd__ev _b_x93, kk_box_t _b_x94, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw3_fun427(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw3_fun427__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw3_fun427__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw3_fun427, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control_raw3_fun428__t {
  struct kk_function_s _base;
  kk_box_t _b_x94;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw3_fun428(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw3_fun428(kk_box_t _b_x94, kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw3_fun428__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw3_fun428__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw3_fun428, kk_context());
  _self->_b_x94 = _b_x94;
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control_raw3_fun428(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw3_fun428__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw3_fun428__t*, _fself, _ctx);
  kk_box_t _b_x94 = _self->_b_x94; /* 45 */
  kk_function_t op = _self->op; /* (x1 : 7340, x2 : 7341, x3 : 7342, r : hnd/resume-context<7343,7344,7345,7347>) -> 7344 7347 */
  kk_drop_match(_self, {kk_box_dup(_b_x94, _ctx);kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple3 _match_x230 = kk_std_core_types__tuple3_unbox(_b_x94, KK_OWNED, _ctx); /*(7340, 7341, 7342)*/;
  {
    kk_box_t x1 = _match_x230.fst;
    kk_box_t x2 = _match_x230.snd;
    kk_box_t x3 = _match_x230.thd;
    kk_std_core_hnd__resume_context _x_x429 = kk_std_core_hnd__new_Resume_context(k, _ctx); /*hnd/resume-context<83,84,85,86>*/
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_std_core_hnd__resume_context, kk_context_t*), op, (op, x1, x2, x3, _x_x429, _ctx), _ctx);
  }
}
static kk_box_t kk_std_core_hnd_clause_control_raw3_fun427(kk_function_t _fself, int32_t _b_x92, kk_std_core_hnd__ev _b_x93, kk_box_t _b_x94, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw3_fun427__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw3_fun427__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x1 : 7340, x2 : 7341, x3 : 7342, r : hnd/resume-context<7343,7344,7345,7347>) -> 7344 7347 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x93, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(_b_x92, kk_std_core_hnd_new_clause_control_raw3_fun428(_b_x94, op, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_control_raw3(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,d,e,e1,a1,b1> (op : (x1 : a, x2 : b, x3 : c, r : resume-context<d,e,e1,b1>) -> e b1) -> clause1<(a, b, c),d,a1,e,b1> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_control_raw3_fun427(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control3_fun430__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control3_fun430(kk_function_t _fself, int32_t _b_x106, kk_std_core_hnd__ev _b_x107, kk_box_t _b_x108, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control3_fun430(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun430__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control3_fun430__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control3_fun430, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control3_fun431__t {
  struct kk_function_s _base;
  kk_box_t _b_x108;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control3_fun431(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control3_fun431(kk_box_t _b_x108, kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun431__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control3_fun431__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control3_fun431, kk_context());
  _self->_b_x108 = _b_x108;
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control3_fun433__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_clause_control3_fun433(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control3_fun433(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun433__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control3_fun433__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control3_fun433, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control3_fun433(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun433__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control3_fun433__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<7430,7433>) -> 7431 7433 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x229 = kk_Unit;
  kk_ref_set_borrow(resumed,(kk_bool_box(true)),kk_context());
  kk_ref_drop(resumed, _ctx);
  _brw_x229;
  kk_std_core_hnd__resume_result _x_x434 = kk_std_core_hnd__new_Deep(ret, _ctx); /*hnd/resume-result<74,75>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x434, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control3_fun435__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_clause_control3_fun435(kk_function_t _fself, kk_box_t xres, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control3_fun435(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun435__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control3_fun435__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control3_fun435, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control3_fun435(kk_function_t _fself, kk_box_t xres, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun435__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control3_fun435__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<7430,7433>) -> 7431 7433 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_protect_check(resumed, k, xres, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control3_fun431(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun431__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control3_fun431__t*, _fself, _ctx);
  kk_box_t _b_x108 = _self->_b_x108; /* 45 */
  kk_function_t op = _self->op; /* (x1 : 7427, x2 : 7428, x3 : 7429, k : (7430) -> 7431 7433) -> 7431 7433 */
  kk_drop_match(_self, {kk_box_dup(_b_x108, _ctx);kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_ref_t resumed = kk_ref_alloc((kk_bool_box(false)),kk_context()); /*ref<global,bool>*/;
  kk_box_t res;
  kk_std_core_types__tuple3 _match_x228 = kk_std_core_types__tuple3_unbox(_b_x108, KK_OWNED, _ctx); /*(7427, 7428, 7429)*/;
  {
    kk_box_t x1 = _match_x228.fst;
    kk_box_t x2 = _match_x228.snd;
    kk_box_t x3 = _match_x228.thd;
    kk_function_t _x_x432;
    kk_function_dup(k, _ctx);
    kk_ref_dup(resumed, _ctx);
    _x_x432 = kk_std_core_hnd_new_clause_control3_fun433(k, resumed, _ctx); /*(ret : 7430) -> 7431 7433*/
    res = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_function_t, kk_context_t*), op, (op, x1, x2, x3, _x_x432, _ctx), _ctx); /*7433*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_drop(res, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_core_hnd_new_clause_control3_fun435(k, resumed, _ctx), _ctx);
  }
  {
    return kk_std_core_hnd_protect_check(resumed, k, res, _ctx);
  }
}
static kk_box_t kk_std_core_hnd_clause_control3_fun430(kk_function_t _fself, int32_t _b_x106, kk_std_core_hnd__ev _b_x107, kk_box_t _b_x108, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun430__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control3_fun430__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x1 : 7427, x2 : 7428, x3 : 7429, k : (7430) -> 7431 7433) -> 7431 7433 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x107, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(_b_x106, kk_std_core_hnd_new_clause_control3_fun431(_b_x108, op, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_control3(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1,b1> (op : (x1 : a, x2 : b, x3 : c, k : (d) -> e b1) -> e b1) -> clause1<(a, b, c),d,a1,e,b1> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_control3_fun430(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_tail3_fun436__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_tail3_fun436(kk_function_t _fself, int32_t _b_x114, kk_std_core_hnd__ev _b_x115, kk_box_t _b_x116, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail3_fun436(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail3_fun436__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail3_fun436__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail3_fun436, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_tail3_fun439__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev _b_x115;
};
static kk_box_t kk_std_core_hnd_clause_tail3_fun439(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail3_fun439(kk_std_core_hnd__ev _b_x115, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail3_fun439__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail3_fun439__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail3_fun439, kk_context());
  _self->_b_x115 = _b_x115;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_tail3_fun439(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail3_fun439__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail3_fun439__t*, _fself, _ctx);
  kk_std_core_hnd__ev _b_x115 = _self->_b_x115; /* hnd/ev<47> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(_b_x115, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(_b_x115, cont, res, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_tail3_fun436(kk_function_t _fself, int32_t _b_x114, kk_std_core_hnd__ev _b_x115, kk_box_t _b_x116, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail3_fun436__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail3_fun436__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (7512, 7513, 7514) -> 7509 7515 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_evv_t w0;
  kk_evv_t _x_x437;
  {
    struct kk_std_core_hnd_Ev* _con_x438 = kk_std_core_hnd__as_Ev(_b_x115, _ctx);
    kk_evv_t w = _con_x438->hevv;
    kk_evv_dup(w, _ctx);
    _x_x437 = w; /*hnd/evv<5010>*/
  }
  w0 = kk_evv_swap(_x_x437,kk_context()); /*hnd/evv<_5153>*/
  kk_box_t y;
  kk_std_core_types__tuple3 _match_x226 = kk_std_core_types__tuple3_unbox(_b_x116, KK_OWNED, _ctx); /*(7512, 7513, 7514)*/;
  {
    kk_box_t x1 = _match_x226.fst;
    kk_box_t x2 = _match_x226.snd;
    kk_box_t x3 = _match_x226.thd;
    y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, _ctx), _ctx); /*7515*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_clause_tail3_fun439(_b_x115, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(_b_x115, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0,kk_context());
    return y;
  }
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail3(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c,d,a1,b1> (op : (c, d, a1) -> e b1) -> clause1<(c, d, a1),b1,b,e,a> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_tail3_fun436(op, _ctx), _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_tail_noop3_fun440(kk_function_t _fself, int32_t _b_x122, kk_std_core_hnd__ev _b_x123, kk_box_t _b_x124, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop3_fun440__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail_noop3_fun440__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (7594, 7595, 7596) -> 7591 7597 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x123, (KK_I32(3)), _ctx);
  kk_std_core_types__tuple3 _match_x224 = kk_std_core_types__tuple3_unbox(_b_x124, KK_OWNED, _ctx); /*(7594, 7595, 7596)*/;
  {
    kk_box_t x1 = _match_x224.fst;
    kk_box_t x2 = _match_x224.snd;
    kk_box_t x3 = _match_x224.thd;
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_core_hnd_clause_never3_fun441__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never3_fun441(kk_function_t _fself, int32_t _b_x130, kk_std_core_hnd__ev _b_x131, kk_box_t _b_x132, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never3_fun441(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never3_fun441__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never3_fun441__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never3_fun441, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_never3_fun442__t {
  struct kk_function_s _base;
  kk_box_t _b_x132;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never3_fun442(kk_function_t _fself, kk_function_t ___wildcard_x638__45, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never3_fun442(kk_box_t _b_x132, kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never3_fun442__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never3_fun442__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never3_fun442, kk_context());
  _self->_b_x132 = _b_x132;
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_never3_fun442(kk_function_t _fself, kk_function_t ___wildcard_x638__45, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never3_fun442__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never3_fun442__t*, _fself, _ctx);
  kk_box_t _b_x132 = _self->_b_x132; /* 45 */
  kk_function_t op = _self->op; /* (7673, 7674, 7675) -> 7677 7679 */
  kk_drop_match(_self, {kk_box_dup(_b_x132, _ctx);kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x638__45, _ctx);
  kk_std_core_types__tuple3 _match_x223 = kk_std_core_types__tuple3_unbox(_b_x132, KK_OWNED, _ctx); /*(7673, 7674, 7675)*/;
  {
    kk_box_t x1 = _match_x223.fst;
    kk_box_t x2 = _match_x223.snd;
    kk_box_t x3 = _match_x223.thd;
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, _ctx), _ctx);
  }
}
static kk_box_t kk_std_core_hnd_clause_never3_fun441(kk_function_t _fself, int32_t _b_x130, kk_std_core_hnd__ev _b_x131, kk_box_t _b_x132, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never3_fun441__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never3_fun441__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (7673, 7674, 7675) -> 7677 7679 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x131, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(_b_x130, kk_std_core_hnd_new_clause_never3_fun442(_b_x132, op, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_never3(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1,b1> (op : (a, b, c) -> e b1) -> clause1<(a, b, c),d,a1,e,b1> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_never3_fun441(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_under3_fun448__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under3_fun448(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under3_fun448(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under3_fun448__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under3_fun448__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under3_fun448, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_under3_fun451__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under3_fun451(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under3_fun451(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under3_fun451__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under3_fun451__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under3_fun451, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_under3_fun451(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under3_fun451__t* _self = kk_function_as(struct kk_std_core_hnd_under3_fun451__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<7884> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont_0, res_0, _ctx);
}
static kk_box_t kk_std_core_hnd_under3_fun448(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under3_fun448__t* _self = kk_function_as(struct kk_std_core_hnd_under3_fun448__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<7884> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  kk_evv_t w0_0;
  kk_evv_t _x_x449;
  {
    struct kk_std_core_hnd_Ev* _con_x450 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w_0 = _con_x450->hevv;
    kk_evv_dup(w_0, _ctx);
    _x_x449 = w_0; /*hnd/evv<5010>*/
  }
  w0_0 = kk_evv_swap(_x_x449,kk_context()); /*hnd/evv<_5153>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*7882*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0_0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under3_fun451(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0_0,kk_context());
    return y;
  }
}

kk_box_t kk_std_core_hnd_under3(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (ev : ev<a1>, op : (a, b, c) -> e d, x1 : a, x2 : b, x3 : c) -> e d */ 
  kk_evv_t w0;
  kk_evv_t _x_x446;
  {
    struct kk_std_core_hnd_Ev* _con_x447 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x447->hevv;
    kk_evv_dup(w, _ctx);
    _x_x446 = w; /*hnd/evv<5010>*/
  }
  w0 = kk_evv_swap(_x_x446,kk_context()); /*hnd/evv<_7808>*/
  kk_box_t z = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, _ctx), _ctx); /*7882*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(z, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under3_fun448(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return z;
  }
}


// lift anonymous function
struct kk_std_core_hnd_clause_control4_fun452__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control4_fun452(kk_function_t _fself, int32_t _b_x151, kk_std_core_hnd__ev _b_x152, kk_box_t _b_x153, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control4_fun452(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun452__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control4_fun452__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control4_fun452, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control4_fun453__t {
  struct kk_function_s _base;
  kk_box_t _b_x153;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control4_fun453(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control4_fun453(kk_box_t _b_x153, kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun453__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control4_fun453__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control4_fun453, kk_context());
  _self->_b_x153 = _b_x153;
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control4_fun456__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_clause_control4_fun456(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control4_fun456(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun456__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control4_fun456__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control4_fun456, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control4_fun456(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun456__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control4_fun456__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<7966,7969>) -> 7967 7969 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x219 = kk_Unit;
  kk_ref_set_borrow(resumed,(kk_bool_box(true)),kk_context());
  kk_ref_drop(resumed, _ctx);
  _brw_x219;
  kk_std_core_hnd__resume_result _x_x457 = kk_std_core_hnd__new_Deep(ret, _ctx); /*hnd/resume-result<74,75>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x457, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control4_fun458__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_clause_control4_fun458(kk_function_t _fself, kk_box_t xres, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control4_fun458(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun458__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control4_fun458__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control4_fun458, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control4_fun458(kk_function_t _fself, kk_box_t xres, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun458__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control4_fun458__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<7966,7969>) -> 7967 7969 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_protect_check(resumed, k, xres, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control4_fun453(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun453__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control4_fun453__t*, _fself, _ctx);
  kk_box_t _b_x153 = _self->_b_x153; /* 45 */
  kk_function_t op = _self->op; /* (x1 : 7962, x2 : 7963, x3 : 7964, x4 : 7965, k : (7966) -> 7967 7969) -> 7967 7969 */
  kk_drop_match(_self, {kk_box_dup(_b_x153, _ctx);kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_ref_t resumed = kk_ref_alloc((kk_bool_box(false)),kk_context()); /*ref<global,bool>*/;
  kk_box_t res;
  kk_std_core_types__tuple4 _match_x218 = kk_std_core_types__tuple4_unbox(_b_x153, KK_OWNED, _ctx); /*(7962, 7963, 7964, 7965)*/;
  {
    struct kk_std_core_types_Tuple4* _con_x454 = kk_std_core_types__as_Tuple4(_match_x218, _ctx);
    kk_box_t x1 = _con_x454->fst;
    kk_box_t x2 = _con_x454->snd;
    kk_box_t x3 = _con_x454->thd;
    kk_box_t x4 = _con_x454->field4;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x218, _ctx)) {
      kk_datatype_ptr_free(_match_x218, _ctx);
    }
    else {
      kk_box_dup(x1, _ctx);
      kk_box_dup(x2, _ctx);
      kk_box_dup(x3, _ctx);
      kk_box_dup(x4, _ctx);
      kk_datatype_ptr_decref(_match_x218, _ctx);
    }
    kk_function_t _x_x455;
    kk_function_dup(k, _ctx);
    kk_ref_dup(resumed, _ctx);
    _x_x455 = kk_std_core_hnd_new_clause_control4_fun456(k, resumed, _ctx); /*(ret : 7966) -> 7967 7969*/
    res = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_function_t, kk_context_t*), op, (op, x1, x2, x3, x4, _x_x455, _ctx), _ctx); /*7969*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_drop(res, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_core_hnd_new_clause_control4_fun458(k, resumed, _ctx), _ctx);
  }
  {
    return kk_std_core_hnd_protect_check(resumed, k, res, _ctx);
  }
}
static kk_box_t kk_std_core_hnd_clause_control4_fun452(kk_function_t _fself, int32_t _b_x151, kk_std_core_hnd__ev _b_x152, kk_box_t _b_x153, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun452__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control4_fun452__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x1 : 7962, x2 : 7963, x3 : 7964, x4 : 7965, k : (7966) -> 7967 7969) -> 7967 7969 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x152, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(_b_x151, kk_std_core_hnd_new_clause_control4_fun453(_b_x153, op, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_control4(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,e,b1,c1> (op : (x1 : a, x2 : b, x3 : c, x4 : d, k : (a1) -> e c1) -> e c1) -> clause1<(a, b, c, d),a1,b1,e,c1> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_control4_fun452(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_tail4_fun459__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_tail4_fun459(kk_function_t _fself, int32_t _b_x159, kk_std_core_hnd__ev _b_x160, kk_box_t _b_x161, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail4_fun459(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail4_fun459__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail4_fun459__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail4_fun459, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_tail4_fun463__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev _b_x160;
};
static kk_box_t kk_std_core_hnd_clause_tail4_fun463(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail4_fun463(kk_std_core_hnd__ev _b_x160, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail4_fun463__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail4_fun463__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail4_fun463, kk_context());
  _self->_b_x160 = _b_x160;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_tail4_fun463(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail4_fun463__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail4_fun463__t*, _fself, _ctx);
  kk_std_core_hnd__ev _b_x160 = _self->_b_x160; /* hnd/ev<47> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(_b_x160, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(_b_x160, cont, res, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_tail4_fun459(kk_function_t _fself, int32_t _b_x159, kk_std_core_hnd__ev _b_x160, kk_box_t _b_x161, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail4_fun459__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail4_fun459__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (8056, 8057, 8058, 8059) -> 8053 8060 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_evv_t w0;
  kk_evv_t _x_x460;
  {
    struct kk_std_core_hnd_Ev* _con_x461 = kk_std_core_hnd__as_Ev(_b_x160, _ctx);
    kk_evv_t w = _con_x461->hevv;
    kk_evv_dup(w, _ctx);
    _x_x460 = w; /*hnd/evv<5010>*/
  }
  w0 = kk_evv_swap(_x_x460,kk_context()); /*hnd/evv<_5153>*/
  kk_box_t y;
  kk_std_core_types__tuple4 _match_x216 = kk_std_core_types__tuple4_unbox(_b_x161, KK_OWNED, _ctx); /*(8056, 8057, 8058, 8059)*/;
  {
    struct kk_std_core_types_Tuple4* _con_x462 = kk_std_core_types__as_Tuple4(_match_x216, _ctx);
    kk_box_t x1 = _con_x462->fst;
    kk_box_t x2 = _con_x462->snd;
    kk_box_t x3 = _con_x462->thd;
    kk_box_t x4 = _con_x462->field4;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x216, _ctx)) {
      kk_datatype_ptr_free(_match_x216, _ctx);
    }
    else {
      kk_box_dup(x1, _ctx);
      kk_box_dup(x2, _ctx);
      kk_box_dup(x3, _ctx);
      kk_box_dup(x4, _ctx);
      kk_datatype_ptr_decref(_match_x216, _ctx);
    }
    y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, x4, _ctx), _ctx); /*8060*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_clause_tail4_fun463(_b_x160, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(_b_x160, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0,kk_context());
    return y;
  }
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail4(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c,d,a1,b1,c1> (op : (c, d, a1, b1) -> e c1) -> clause1<(c, d, a1, b1),c1,b,e,a> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_tail4_fun459(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_tail_noop4_fun464__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_tail_noop4_fun464(kk_function_t _fself, int32_t _b_x167, kk_std_core_hnd__ev _b_x168, kk_box_t _b_x169, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail_noop4_fun464(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop4_fun464__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail_noop4_fun464__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail_noop4_fun464, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_tail_noop4_fun464(kk_function_t _fself, int32_t _b_x167, kk_std_core_hnd__ev _b_x168, kk_box_t _b_x169, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop4_fun464__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail_noop4_fun464__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (8147, 8148, 8149, 8150) -> 8144 8151 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x168, (KK_I32(3)), _ctx);
  kk_std_core_types__tuple4 _match_x214 = kk_std_core_types__tuple4_unbox(_b_x169, KK_OWNED, _ctx); /*(8147, 8148, 8149, 8150)*/;
  {
    struct kk_std_core_types_Tuple4* _con_x465 = kk_std_core_types__as_Tuple4(_match_x214, _ctx);
    kk_box_t x1 = _con_x465->fst;
    kk_box_t x2 = _con_x465->snd;
    kk_box_t x3 = _con_x465->thd;
    kk_box_t x4 = _con_x465->field4;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x214, _ctx)) {
      kk_datatype_ptr_free(_match_x214, _ctx);
    }
    else {
      kk_box_dup(x1, _ctx);
      kk_box_dup(x2, _ctx);
      kk_box_dup(x3, _ctx);
      kk_box_dup(x4, _ctx);
      kk_datatype_ptr_decref(_match_x214, _ctx);
    }
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, x4, _ctx), _ctx);
  }
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail_noop4(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c,d,a1,b1,c1> (op : (c, d, a1, b1) -> e c1) -> clause1<(c, d, a1, b1),c1,b,e,a> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_tail_noop4_fun464(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_never4_fun466__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never4_fun466(kk_function_t _fself, int32_t _b_x175, kk_std_core_hnd__ev _b_x176, kk_box_t _b_x177, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never4_fun466(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never4_fun466__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never4_fun466__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never4_fun466, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_never4_fun467__t {
  struct kk_function_s _base;
  kk_box_t _b_x177;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never4_fun467(kk_function_t _fself, kk_function_t ___wildcard_x638__45, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never4_fun467(kk_box_t _b_x177, kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never4_fun467__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never4_fun467__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never4_fun467, kk_context());
  _self->_b_x177 = _b_x177;
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_never4_fun467(kk_function_t _fself, kk_function_t ___wildcard_x638__45, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never4_fun467__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never4_fun467__t*, _fself, _ctx);
  kk_box_t _b_x177 = _self->_b_x177; /* 45 */
  kk_function_t op = _self->op; /* (8235, 8236, 8237, 8238) -> 8240 8242 */
  kk_drop_match(_self, {kk_box_dup(_b_x177, _ctx);kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x638__45, _ctx);
  kk_std_core_types__tuple4 _match_x213 = kk_std_core_types__tuple4_unbox(_b_x177, KK_OWNED, _ctx); /*(8235, 8236, 8237, 8238)*/;
  {
    struct kk_std_core_types_Tuple4* _con_x468 = kk_std_core_types__as_Tuple4(_match_x213, _ctx);
    kk_box_t x1 = _con_x468->fst;
    kk_box_t x2 = _con_x468->snd;
    kk_box_t x3 = _con_x468->thd;
    kk_box_t x4 = _con_x468->field4;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x213, _ctx)) {
      kk_datatype_ptr_free(_match_x213, _ctx);
    }
    else {
      kk_box_dup(x1, _ctx);
      kk_box_dup(x2, _ctx);
      kk_box_dup(x3, _ctx);
      kk_box_dup(x4, _ctx);
      kk_datatype_ptr_decref(_match_x213, _ctx);
    }
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, x4, _ctx), _ctx);
  }
}
static kk_box_t kk_std_core_hnd_clause_never4_fun466(kk_function_t _fself, int32_t _b_x175, kk_std_core_hnd__ev _b_x176, kk_box_t _b_x177, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never4_fun466__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never4_fun466__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (8235, 8236, 8237, 8238) -> 8240 8242 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x176, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(_b_x175, kk_std_core_hnd_new_clause_never4_fun467(_b_x177, op, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_never4(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,e,b1,c1> (op : (a, b, c, d) -> e c1) -> clause1<(a, b, c, d),a1,b1,e,c1> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_never4_fun466(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_under4_fun474__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under4_fun474(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under4_fun474(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under4_fun474__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under4_fun474__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under4_fun474, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_under4_fun477__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under4_fun477(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under4_fun477(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under4_fun477__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under4_fun477__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under4_fun477, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_under4_fun477(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under4_fun477__t* _self = kk_function_as(struct kk_std_core_hnd_under4_fun477__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<8466> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont_0, res_0, _ctx);
}
static kk_box_t kk_std_core_hnd_under4_fun474(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under4_fun474__t* _self = kk_function_as(struct kk_std_core_hnd_under4_fun474__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<8466> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  kk_evv_t w0_0;
  kk_evv_t _x_x475;
  {
    struct kk_std_core_hnd_Ev* _con_x476 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w_0 = _con_x476->hevv;
    kk_evv_dup(w_0, _ctx);
    _x_x475 = w_0; /*hnd/evv<5010>*/
  }
  w0_0 = kk_evv_swap(_x_x475,kk_context()); /*hnd/evv<_5153>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*8464*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0_0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under4_fun477(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0_0,kk_context());
    return y;
  }
}

kk_box_t kk_std_core_hnd_under4(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,e,b1> (ev : ev<b1>, op : (a, b, c, d) -> e a1, x1 : a, x2 : b, x3 : c, x4 : d) -> e a1 */ 
  kk_evv_t w0;
  kk_evv_t _x_x472;
  {
    struct kk_std_core_hnd_Ev* _con_x473 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x473->hevv;
    kk_evv_dup(w, _ctx);
    _x_x472 = w; /*hnd/evv<5010>*/
  }
  w0 = kk_evv_swap(_x_x472,kk_context()); /*hnd/evv<_8386>*/
  kk_box_t z = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, x4, _ctx), _ctx); /*8464*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(z, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under4_fun474(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return z;
  }
}


// lift anonymous function
struct kk_std_core_hnd_open_at1_fun478__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd_open_at1_fun478(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_open_at1_fun478(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd_open_at1_fun478__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_open_at1_fun478__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_open_at1_fun478, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_open_at1_fun478(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_open_at1_fun478__t* _self = kk_function_as(struct kk_std_core_hnd_open_at1_fun478__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd_open_at1(kk_ssize_t i, kk_function_t f, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,e1> (i : ev-index, f : (a) -> e b, x : a) -> e1 b */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<8933>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx), _ctx); /*8931*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_open_at1_fun478(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open_at0_fun479__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd__open_at0_fun479(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open_at0_fun479(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at0_fun479__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open_at0_fun479__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open_at0_fun479, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open_at0_fun479(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at0_fun479__t* _self = kk_function_as(struct kk_std_core_hnd__open_at0_fun479__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open_at0(kk_ssize_t i, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e,e1> (i : ev-index, f : () -> e a) -> e1 a */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<9027>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), f, (f, _ctx), _ctx); /*9025*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open_at0_fun479(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open_at1_fun480__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd__open_at1_fun480(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open_at1_fun480(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at1_fun480__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open_at1_fun480__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open_at1_fun480, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open_at1_fun480(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at1_fun480__t* _self = kk_function_as(struct kk_std_core_hnd__open_at1_fun480__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open_at1(kk_ssize_t i, kk_function_t f, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,e1> (i : ev-index, f : (a) -> e b, x : a) -> e1 b */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<9126>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx), _ctx); /*9124*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open_at1_fun480(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open_at2_fun481__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd__open_at2_fun481(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open_at2_fun481(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at2_fun481__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open_at2_fun481__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open_at2_fun481, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open_at2_fun481(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at2_fun481__t* _self = kk_function_as(struct kk_std_core_hnd__open_at2_fun481__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open_at2(kk_ssize_t i, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) { /* forall<a,b,c,e,e1> (i : ev-index, f : (a, b) -> e c, x1 : a, x2 : b) -> e1 c */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<9236>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, _ctx), _ctx); /*9234*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open_at2_fun481(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open_at3_fun482__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd__open_at3_fun482(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open_at3_fun482(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at3_fun482__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open_at3_fun482__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open_at3_fun482, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open_at3_fun482(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at3_fun482__t* _self = kk_function_as(struct kk_std_core_hnd__open_at3_fun482__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open_at3(kk_ssize_t i, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_context_t* _ctx) { /* forall<a,b,c,d,e,e1> (i : ev-index, f : (a, b, c) -> e d, x1 : a, x2 : b, x3 : c) -> e1 d */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<9357>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, x3, _ctx), _ctx); /*9355*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open_at3_fun482(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open_at4_fun483__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd__open_at4_fun483(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open_at4_fun483(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at4_fun483__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open_at4_fun483__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open_at4_fun483, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open_at4_fun483(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at4_fun483__t* _self = kk_function_as(struct kk_std_core_hnd__open_at4_fun483__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open_at4(kk_ssize_t i, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,e,e1> (i : ev-index, f : (a, b, c, d) -> e a1, x1 : a, x2 : b, x3 : c, x4 : d) -> e1 a1 */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<9489>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, x3, x4, _ctx), _ctx); /*9487*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open_at4_fun483(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd_open1_fun485__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd_open1_fun485(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_open1_fun485(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd_open1_fun485__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_open1_fun485__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_open1_fun485, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_open1_fun485(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_open1_fun485__t* _self = kk_function_as(struct kk_std_core_hnd_open1_fun485__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd_open1(kk_vector_t indices, kk_function_t f, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,e1> (indices : vector<ev-index>, f : (a) -> e b, x : a) -> e1 b */ 
  kk_evv_t w;
  kk_vector_t _x_x484 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x484, _ctx); /*hnd/evv<9606>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx), _ctx); /*9604*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_open1_fun485(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open0_fun487__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd__open0_fun487(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open0_fun487(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open0_fun487__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open0_fun487__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open0_fun487, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open0_fun487(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open0_fun487__t* _self = kk_function_as(struct kk_std_core_hnd__open0_fun487__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open0(kk_vector_t indices, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e,e1> (indices : vector<ev-index>, f : () -> e a) -> e1 a */ 
  kk_evv_t w;
  kk_vector_t _x_x486 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x486, _ctx); /*hnd/evv<9700>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), f, (f, _ctx), _ctx); /*9698*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open0_fun487(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open1_fun489__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd__open1_fun489(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open1_fun489(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open1_fun489__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open1_fun489__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open1_fun489, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open1_fun489(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open1_fun489__t* _self = kk_function_as(struct kk_std_core_hnd__open1_fun489__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open1(kk_vector_t indices, kk_function_t f, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,e1> (indices : vector<ev-index>, f : (a) -> e b, x : a) -> e1 b */ 
  kk_evv_t w;
  kk_vector_t _x_x488 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x488, _ctx); /*hnd/evv<9799>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx), _ctx); /*9797*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open1_fun489(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open2_fun491__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd__open2_fun491(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open2_fun491(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open2_fun491__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open2_fun491__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open2_fun491, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open2_fun491(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open2_fun491__t* _self = kk_function_as(struct kk_std_core_hnd__open2_fun491__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open2(kk_vector_t indices, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) { /* forall<a,b,c,e,e1> (indices : vector<ev-index>, f : (a, b) -> e c, x1 : a, x2 : b) -> e1 c */ 
  kk_evv_t w;
  kk_vector_t _x_x490 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x490, _ctx); /*hnd/evv<9909>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, _ctx), _ctx); /*9907*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open2_fun491(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open3_fun493__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd__open3_fun493(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open3_fun493(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open3_fun493__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open3_fun493__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open3_fun493, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open3_fun493(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open3_fun493__t* _self = kk_function_as(struct kk_std_core_hnd__open3_fun493__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open3(kk_vector_t indices, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_context_t* _ctx) { /* forall<a,b,c,d,e,e1> (indices : vector<ev-index>, f : (a, b, c) -> e d, x1 : a, x2 : b, x3 : c) -> e1 d */ 
  kk_evv_t w;
  kk_vector_t _x_x492 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x492, _ctx); /*hnd/evv<10030>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, x3, _ctx), _ctx); /*10028*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open3_fun493(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open4_fun495__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd__open4_fun495(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open4_fun495(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open4_fun495__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open4_fun495__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open4_fun495, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open4_fun495(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open4_fun495__t* _self = kk_function_as(struct kk_std_core_hnd__open4_fun495__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open4(kk_vector_t indices, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,e,e1> (indices : vector<ev-index>, f : (a, b, c, d) -> e a1, x1 : a, x2 : b, x3 : c, x4 : d) -> e1 a1 */ 
  kk_evv_t w;
  kk_vector_t _x_x494 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x494, _ctx); /*hnd/evv<10162>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, x3, x4, _ctx), _ctx); /*10160*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open4_fun495(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd_try_finalize_prompt_fun497__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_hnd_try_finalize_prompt_fun497(kk_function_t _fself, kk_function_t _b_x190, kk_box_t _b_x191, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_try_finalize_prompt_fun497(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_hnd_try_finalize_prompt_fun497, _ctx)
  return kk_function_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_hnd_try_finalize_prompt_fun497(kk_function_t _fself, kk_function_t _b_x190, kk_box_t _b_x191, kk_context_t* _ctx) {
  kk_unused(_fself);
  kk_function_t cont_195 = _b_x190; /*(10222) -> 10273 10272*/;
  kk_box_t x_196 = _b_x191; /*10222*/;
  kk_std_core_types__either _x_x498;
  kk_box_t _x_x499 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont_195, (cont_195, x_196, _ctx), _ctx); /*10272*/
  _x_x498 = kk_std_core_hnd_try_finalize_prompt(_x_x499, _ctx); /*either<hnd/yield-info,1833>*/
  return kk_std_core_types__either_box(_x_x498, _ctx);
}

kk_std_core_types__either kk_std_core_hnd_try_finalize_prompt(kk_box_t res, kk_context_t* _ctx) { /* forall<a,e> (res : a) -> e either<yield-info,a> */ 
  bool _match_x197 = kk_yielding_non_final(kk_context()); /*bool*/;
  if (_match_x197) {
    kk_box_drop(res, _ctx);
    kk_box_t _x_x496 = kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_try_finalize_prompt_fun497(_ctx), _ctx); /*3102*/
    return kk_std_core_types__either_unbox(_x_x496, KK_OWNED, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_box_drop(res, _ctx);
    kk_std_core_hnd__yield_info _b_x192_194 = kk_std_core_hnd_yield_capture(_ctx); /*hnd/yield-info*/;
    return kk_std_core_types__new_Left(kk_std_core_hnd__yield_info_box(_b_x192_194, _ctx), _ctx);
  }
  {
    return kk_std_core_types__new_Right(res, _ctx);
  }
}

// initialization
void kk_std_core_hnd__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_undiv__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_hnd__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_undiv__done(_ctx);
  kk_std_core_types__done(_ctx);
}
