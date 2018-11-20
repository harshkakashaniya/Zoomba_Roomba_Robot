/************************************************************************
 MIT License

 Copyright (c) 2018 Harsh Kakashaniya

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 *************************************************************************/

/**
 *  @file    Walker.cpp
 *  @author  Harsh Kakashaniya
 *  @date    11/19/2018
 *  @version 1.0
 *
 *  @brief UMD ENPM 808X, ROS tutorials.
 *
 *  @Description DESCRIPTION
 *
 *  This file is used to implement sensor data and command robot to move
 *
 */
#include "Walker.hpp"

Walker::Walker() {
	float SetRange = 0.5;  // set range of 0.5 m for trial
  laserSubscribe = nh.subscribe < sensor_msgs::LaserScan
      > ("/scan", 10, &Walker::processLaserScan, this);

  ROS_INFO("Range of %f m is set to avoid obstacles.",SetRange)
}

void LaserScan(const sensor_msgs::LaserScan::ConstPtr &scan) {
  // Let first element be minimum distance
  float minDis = scan->ranges[0];
   // for loop for minimum distance
for (int i = 0; i < scan->ranges.size(); i++) {
  float currentVal = scanMsg->ranges[i];
    // comparison of values
    if (currentVal < minDis) {
        minDistance = currentScanVal;
    }
  }
  // obstacle near by signal
   if (minDistance < SetRange) {
    ROS_INFO("Terrain!");
  }
}

void Motion(bool movement) {
// TODO Implementation of Robot control
}


Walker::~Walker() {
	// TODO Auto-generated destructor stub
}