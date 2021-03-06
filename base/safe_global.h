/* <base/safe_global.h>

   A global variable that initializes only when called for.

   Copyright 2010-2014 OrlyAtomics, Inc.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */

#pragma once

#include <cassert>
#include <functional>
#include <memory>

#include <base/assert_true.h>
#include <base/class_traits.h>
#include <base/spin_lock.h>

namespace Base {

  /* TODO */
  template <typename TVal>
  class TSafeGlobal {
    NO_COPY(TSafeGlobal);
    public:

    /* TODO */
    typedef std::function<TVal *()> TFactory;

    /* TODO */
    TSafeGlobal(const TFactory &factory)
        : Factory(factory), Constructing(false) {}

    /* TODO */
    const TVal &operator*() const {
      assert(this);
      Freshen();
      return *AssertTrue(Val).get();
    }

    /* TODO */
    TVal &operator*() {
      assert(this);
      Freshen();
      return *AssertTrue(Val).get();
    }

    /* TODO */
    const TVal *operator->() const {
      assert(this);
      Freshen();
      return AssertTrue(Val).get();
    }

    /* TODO */
    TVal *operator->() {
      assert(this);
      Freshen();
      return AssertTrue(Val).get();
    }

    /* TODO */
    const TVal *GetObj() const {
      assert(this);
      Freshen();
      return AssertTrue(Val).get();
    }

    /* TODO */
    TVal *GetObj() {
      assert(this);
      Freshen();
      return AssertTrue(Val).get();
    }

    private:

    /* TODO */
    void Freshen() const {
      assert(this);
      TSpinLock::TLock lock(SpinLock);
      if (!Val) {
        assert(!Constructing);
        Constructing = true;
        Val = std::unique_ptr<TVal>(Factory());
        assert(Val);
        Constructing = false;
      }
    }

    /* TODO */
    TSpinLock SpinLock;

    /* TODO */
    TFactory Factory;

    /* TODO */
    mutable std::unique_ptr<TVal> Val;

    /* TODO */
    mutable bool Constructing;
  };

}
