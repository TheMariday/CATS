#include "TFP_Drivetrain.h"
#include "TFP_Transmitter.h"

Drivetrain drivetrain;
TFP_Transmitter transmitter;

void setup(void) {
    Serial.begin(9600);

    while (!Serial) {
        delay(1);
    }
    Serial.println("Serial connected");

    drivetrain.begin();
    drivetrain.load_calibration();

    transmitter.begin(10);
    transmitter.load_calibration();
}


void loop() {
    transmitter.update();
    transmitter.print_state();
    drivetrain.wheel_steer(transmitter.left_stick_y.value, transmitter.left_stick_x.value);
    drivetrain.print_state();
    delay(10);
}
