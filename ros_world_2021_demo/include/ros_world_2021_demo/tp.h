// Copyright (c) 2023
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
#ifndef ROS_WORLD_2021_DEMO_TP_H_
#define ROS_WORLD_2021_DEMO_TP_H_

#if __cplusplus
extern "C"
{
#endif

#include<lttng/tracepoint.h>

LTTNG_UST_TRACEPOINT_EVENT(
    my_app, my_tracepoint,
    LTTNG_UST_TP_ARGS(int, count_arg),
    LTTNG_UST_TP_FIELDS(
        lttng_ust_field_integer(int, count, count_arg))
    )

#if __cplusplus
}
#endif

#endif  // ROS_WORLD_2021_DEMO_TP_H_