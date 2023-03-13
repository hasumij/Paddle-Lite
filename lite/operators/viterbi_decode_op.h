// Copyright (c) 2023 PaddlePaddle Authors. All Rights Reserved.
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

#pragma once
#include <string>
#include <vector>
#include "lite/core/kernel.h"
#include "lite/core/op_lite.h"
#include "lite/core/scope.h"
#include "lite/operators/op_params.h"
#include "lite/utils/all.h"

namespace paddle {
namespace lite {
namespace operators {

class ViterbiDecodeOpLite : public OpLite {
 public:
  ViterbiDecodeOpLite() {}

  explicit ViterbiDecodeOpLite(const std::string &type) : OpLite(type) {}

  bool CheckShape() const override;

  bool InferShapeImpl() const override;

  bool InferShapeWithCache() const override { return true; }

  void AttachKernel(KernelBase *kernel) override { kernel->SetParam(param_); }

  bool AttachImpl(const cpp::OpDesc &op_desc, lite::Scope *scope) override;

  std::string DebugString() const override { return "viterbi_decode"; }

 private:
  mutable ViterbiDecodeParam param_;
};

}  // namespace operators
}  // namespace lite
}  // namespace paddle
