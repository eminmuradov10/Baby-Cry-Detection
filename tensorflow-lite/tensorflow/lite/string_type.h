/* Copyright 2017 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

/* File modified by NXP. Changes are described in file
   /middleware/eiq/tensorflow-lite/readme.txt in section "Release notes" */

// Abstract string. We don't want even absl at this level.
#ifndef TENSORFLOW_LITE_STRING_TYPE_H_
#define TENSORFLOW_LITE_STRING_TYPE_H_

#include <string>

namespace tflite {

using ::std::string;

}  // namespace tflite

#endif  // TENSORFLOW_LITE_STRING_TYPE_H_
