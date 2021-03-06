/* <starsha/bison_file.h>

   TODO

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
#include <vector>

#include <base/class_traits.h>
#include <starsha/corpus.h>

namespace Starsha {

  /* TODO */
  class TBisonFile
      : public TCorpus::TFile {
    NO_COPY(TBisonFile);
    public:

    /* TODO */
    virtual const TKind *GetKind() const;

    private:

    /* TODO */
    TBisonFile(TCorpus *corpus, const std::string &rel_path)
        : TFile(corpus, rel_path) {
      Init();
    }

    /* TODO */
    TBisonFile(TCorpus *corpus, const std::string &rel_path, time_t mod_time)
        : TFile(corpus, rel_path, mod_time) {
      Init();
    }

    /* TODO */
    virtual ~TBisonFile();

    /* TODO */
    void Init() {
      assert(this);
      PrimaryTarget = 0;
    }

    /* TODO */
    virtual void OnNew();

    /* TODO */
    virtual void Produce(bool run, const std::unordered_set<TFile *> &targets, std::unordered_set<TFile *> &products);

    /* TODO */
    TFile *PrimaryTarget;

    /* TODO */
    std::unordered_set<TFile *> Targets;

    /* TODO */
    static const TSpecificKind<TBisonFile> Kind;

    /* TODO */
    friend class TSpecificKind<TBisonFile>;

  };  // TBisonFile

}  // Starsha
