/* <orly/compiler.h>

   The controller for the orly compiler. Runs all the phases, exits on first phase failure.

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

#include <iostream>
#include <string>

#include <base/error.h>
#include <jhm/naming.h>
#include <orly/package/name.h>

namespace Orly {

  namespace Compiler {

    /* Thrown when we compilation fails. Errors will have been printed to the out-stream. */
    class TCompileFailure
        : public Base::TFinalError<TCompileFailure> {
      public:

      /* Constructor. */
      TCompileFailure(const Base::TCodeLocation &code_location, const char *message = nullptr) {
        PostCtor(code_location, message);
      }

    };  // TCompileFailure

    Package::TVersionedName Compile(
        const Jhm::TAbsPath &core_file,
        const Jhm::TAbsBase &out_tree,
        bool found_root, // Only if we found the root can we look at sub scopes.
        bool debug_cc,
        bool machine_mode,
        std::ostream &out_strm = std::cout);

  }  // Compiler

}  // Orly
