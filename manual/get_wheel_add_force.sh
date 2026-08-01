#!/bin/bash
awk '/\/\/ Function: CSceneVehicleCar::WheelAddForceToVehicle/,/^}/' ../tmnf_dump/src/CSceneVehicleCar.cpp > scratch_WheelAddForceToVehicle.cpp
