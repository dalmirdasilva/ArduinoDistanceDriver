/**
 * Arduino - Ultrasound distance sensor
 * 
 * UltrasoundDistanceSensor.cpp
 * 
 * The abstract class for the ultrasound distance sensor.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_ULTRASOUND_DISTANCE_SENSOR_CPP__
#define __ARDUINO_DRIVER_ULTRASOUND_DISTANCE_SENSOR_CPP__ 1

#include <Arduino.h>
#include <UltrasoundDistanceSensor.h>

UltrasoundDistanceSensor::UltrasoundDistanceSensor(unsigned char echoPin, unsigned char trigPin) : echoPin(echoPin), trigPin(trigPin) {
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);
}

unsigned long UltrasoundDistanceSensor::getEchoTime() {
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(trigPin, LOW);
    return pulseIn(echoPin, HIGH, US_SENSOR_PULSE_IN_TIMEOUT);
}

float UltrasoundDistanceSensor::getDistance() {
    float time = (float) getEchoTime();
    return time / US_SENSOR_2_TIMES_US_PER_CM;
}

#endif /* __ARDUINO_DRIVER_ULTRASOUND_DISTANCE_SENSOR_CPP__ */
