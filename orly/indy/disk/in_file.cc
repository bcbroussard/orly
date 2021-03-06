/* <orly/indy/disk/in_file.cc>

   Implements <orly/indy/disk/in_file.h>.

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

#include <orly/indy/disk/in_file.h>

using namespace Orly::Atom;
using namespace Orly::Indy::Disk;

static_assert(sizeof(TCore) == 24, "NullCore must be set to right number of zero'd out bytes");
const uint8_t TData::NullCore[sizeof(TCore)] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const TCore TData::TombstoneCore = TData::GetTombstoneCore();