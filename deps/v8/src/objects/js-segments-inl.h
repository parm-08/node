// Copyright 2020 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_OBJECTS_JS_SEGMENTS_INL_H_
#define V8_OBJECTS_JS_SEGMENTS_INL_H_

#ifndef V8_INTL_SUPPORT
#error Internationalization is expected to be enabled.
#endif  // V8_INTL_SUPPORT

#include "src/objects/js-segments.h"
// Include the non-inl header before the rest of the headers.

#include "src/objects/objects-inl.h"

// Has to be the last include (doesn't have include guards):
#include "src/objects/object-macros.h"

namespace v8 {
namespace internal {

#include "torque-generated/src/objects/js-segments-tq-inl.inc"

TQ_OBJECT_CONSTRUCTORS_IMPL(JSSegments)

// Base segments accessors.
ACCESSORS(JSSegments, icu_break_iterator, Tagged<Managed<icu::BreakIterator>>,
          kIcuBreakIteratorOffset)
ACCESSORS(JSSegments, raw_string, Tagged<String>, kRawStringOffset)
ACCESSORS(JSSegments, unicode_string, Tagged<Managed<icu::UnicodeString>>,
          kUnicodeStringOffset)

inline void JSSegments::set_granularity(JSSegmenter::Granularity granularity) {
  DCHECK(GranularityBits::is_valid(granularity));
  int hints = flags();
  hints = GranularityBits::update(hints, granularity);
  set_flags(hints);
}

inline JSSegmenter::Granularity JSSegments::granularity() const {
  return GranularityBits::decode(flags());
}

}  // namespace internal
}  // namespace v8

#include "src/objects/object-macros-undef.h"

#endif  // V8_OBJECTS_JS_SEGMENTS_INL_H_
