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

This file is the entry for prediction of the xLearn.
*/

#include "src/base/common.h"
#include "src/solver/solver.h"

//------------------------------------------------------------------------------
// The pre-defined main function
//------------------------------------------------------------------------------

int main(int argc, char* argv[]) {
  clock_t start, end;
  start = clock();

  xLearn::Solver solver;
  solver.SetPredict();
  solver.Initialize(argc, argv);
  solver.StartWork();
  solver.FinalizeWork();

  end = clock();
  printf("Total time: %.2f sec",
         (float)(end-start) / CLOCKS_PER_SEC);

  return 0;
}
