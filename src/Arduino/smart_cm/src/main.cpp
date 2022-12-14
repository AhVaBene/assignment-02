#include <Arduino.h>
#include "Scheduler.h"
#include "SubsystemLight.h"
#include "SubsystemRiverFlow.h"
#include "globals.h"

#define LED_A 13
#define LED_B 12
#define LED_C 11
#define POT_PIN A1
#define TRIG_PIN 10
#define ECHO_PIN 9
#define BUTTON_PIN 8
#define SERVO_PIN 4
#define PIR_PIN 2
#define LS_PIN A0
#define SDA A4 
#define SCL A5

bool disable_light_system = false;

Scheduler sched;

void setup() {
    Serial.begin(9600);
    Timer1.initialize(1000);
    sched.init(250);

    // Task *t0 = new SubSystemLight(LED_A, LS_PIN, PIR_PIN);
    // t0->init(500);
    // sched.addTask(t0);

    Task *t1 = new SubsystemRiverFlow(LED_B, LED_C, ECHO_PIN, TRIG_PIN, POT_PIN,
    SDA, SCL, BUTTON_PIN, SERVO_PIN);
    t1->init(1000);
    sched.addTask(t1);
}

void loop() {
    sched.schedule();
}