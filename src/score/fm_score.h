//------------------------------------------------------------------------------
// Copyright (c) 2016 by contributors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//------------------------------------------------------------------------------

/*
Author: Chao Ma (mctt90@gmail.com)
This file defines the FMrScore (factorization machine) class.
*/

#ifndef XLEARN_LOSS_FM_SCORE_H_
#define XLEARN_LOSS_FM_SCORE_H_

#include "src/base/common.h"
#include "src/score/score_function.h"

namespace xLearn {

//------------------------------------------------------------------------------
// FMScore is used to implemente factorization machines, in which
// the socre function is y = wTx + sum[(V_i*V_j)(x_i * x_j)]
//------------------------------------------------------------------------------
class FMScore : public Score {
 public:
  // Constructor and Desstructor
  FMScore() { }
  ~FMScore() { }

  // This function needs to be invoked before using this class.
  void Initialize(index_t num_feat, int k, int field = 0) {
    CHECK_GT(k, 0);
    CHECK_GT(num_feat, 0);
    num_factor_ = k;
    num_feature_ = num_feat;
  }

  // Given one exmaple and current model, return the score.
  real_t CalcScore(const SparseRow* row,
                   const std::vector<real_t>* w);

  // Calculate gradient and update current model.
  void CalcGrad(const SparseRow* row,
                std::vector<real_t>& param,
                real_t pg, /* partial gradient */
                Updater* updater);

 private:
  DISALLOW_COPY_AND_ASSIGN(FMScore);
};

} // namespace xLearn

#endif // XLEARN_LOSS_FM_SCORE_H_
