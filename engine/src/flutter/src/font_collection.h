/*
 * Copyright 2017 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LIB_TXT_SRC_FONT_COLLECTION_H_
#define LIB_TXT_SRC_FONT_COLLECTION_H_

#define DEFAULT_FAMILY_NAME "Roboto"

#include <memory>
#include <set>
#include <string>
#include <vector>

#include "lib/ftl/macros.h"
#include "minikin/FontCollection.h"
#include "minikin/FontFamily.h"
#include "third_party/gtest/include/gtest/gtest_prod.h"
#include "third_party/skia/include/core/SkRefCnt.h"
#include "third_party/skia/include/ports/SkFontMgr.h"

namespace txt {

class FontCollection {
 public:
  // Will be deprecated when full compatibility with Flutter Engine is complete.
  static FontCollection& GetDefaultFontCollection();

  // Will be deprecated when full compatibility with Flutter Engine is complete.
  static FontCollection& GetFontCollection(std::string dir = "");

  // Will be deprecated when full compatibility with Flutter Engine is complete.
  static FontCollection& GetFontCollection(std::vector<std::string> dirs);

  std::shared_ptr<minikin::FontCollection> GetMinikinFontCollectionForFamily(
      const std::string& family);

  FontCollection(const std::vector<std::string>& dirs);

  FontCollection(std::string dir);

  FontCollection();

  ~FontCollection();

  // Provides a set of all available family names.
  std::set<std::string> GetFamilyNames();

 private:
  std::vector<sk_sp<SkFontMgr>> skia_font_managers_;
  // Cache the names because GetFamilyNames() can be frequently called.
  std::set<std::string> family_names_;

  FRIEND_TEST(FontCollection, HasDefaultRegistrations);
  FRIEND_TEST(FontCollection, GetMinikinFontCollections);
  FRIEND_TEST(FontCollection, GetFamilyNames);

  const std::string ProcessFamilyName(const std::string& family);

  static const std::string GetDefaultFamilyName() {
    return DEFAULT_FAMILY_NAME;
  };

  // TODO(chinmaygarde): Caches go here.
};

}  // namespace txt

#endif  // LIB_TXT_SRC_FONT_COLLECTION_H_
