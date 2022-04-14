// Copyright (c) 2021, Stogl Robotics Consulting UG (haftungsbeschränkt)
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

//
// Authors: Subhas Das, Denis Stogl
//

#ifndef ros2_control_hardware__RRBOT_ACTUATOR_HPP_
#define ros2_control_hardware__RRBOT_ACTUATOR_HPP_

#include <memory>
#include <string>
#include <vector>

#include "hardware_interface/actuator_interface.hpp"
#include "hardware_interface/handle.hpp"
#include "hardware_interface/hardware_info.hpp"
#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "rclcpp/macros.hpp"
#include "ros2_control_hardware/visibility_control.h"

namespace ros2_control_hardware
{
class RRBotModularJoint : public hardware_interface::ActuatorInterface
{
public:
  RCLCPP_SHARED_PTR_DEFINITIONS(RRBotModularJoint);

  ros2_control_hardware_PUBLIC
  CallbackReturn on_init(const hardware_interface::HardwareInfo & info) override;

  ros2_control_hardware_PUBLIC
  std::vector<hardware_interface::StateInterface> export_state_interfaces() override;

  ros2_control_hardware_PUBLIC
  std::vector<hardware_interface::CommandInterface> export_command_interfaces() override;

  ros2_control_hardware_PUBLIC
  CallbackReturn on_activate(const rclcpp_lifecycle::State & previous_state) override;

  ros2_control_hardware_PUBLIC
  CallbackReturn on_deactivate(const rclcpp_lifecycle::State & previous_state) override;

  ros2_control_hardware_PUBLIC
  hardware_interface::return_type read() override;

  ros2_control_hardware_PUBLIC
  hardware_interface::return_type write() override;

private:
  // Parameters for the RRBot simulation
  double hw_start_sec_;
  double hw_stop_sec_;
  double hw_slowdown_;

  // Store the command for the simulated robot
  double hw_joint_command_;
  double hw_joint_state_;
};

}  // namespace ros2_control_hardware

#endif  // ros2_control_hardware__RRBOT_ACTUATOR_HPP_
