// testing a stepper motor with a Pololu A4988 driver board or equivalent
// on an Uno the onboard led will flash with each step
// this version uses delay() to manage timing

#define X_STEP_PIN 54
#define X_DIR_PIN 55
#define X_ENABLE_PIN 38
#define X_MIN_PIN 3
#define X_MAX_PIN 2

#define Y_STEP_PIN 60
#define Y_DIR_PIN 61
#define Y_ENABLE_PIN 56
#define Y_MIN_PIN 14
#define Y_MAX_PIN 15

#define Z_STEP_PIN 46
#define Z_DIR_PIN 48
#define Z_ENABLE_PIN 62
#define Z_MIN_PIN 18
#define Z_MAX_PIN 19

#define E_STEP_PIN 26
#define E_DIR_PIN 28
#define E_ENABLE_PIN 24

#define Q_STEP_PIN 36
#define Q_DIR_PIN 34
#define Q_ENABLE_PIN 30

#define SDPOWER -1
#define SDSS 53
#define LED_PIN 13

#define FAN_PIN 9

#define PS_ON_PIN 12
#define KILL_PIN -1

#define HEATER_0_PIN 10
#define HEATER_1_PIN 8
#define TEMP_0_PIN 13 // ANALOG NUMBERING
#define TEMP_1_PIN 14 // ANALOG NUMBERING

int numberOfSteps = 500;
int pulseWidthMicros = 20;  // microseconds
int millisbetweenSteps = 2; // milliseconds - or try 1000 for slower steps

void setup()
{

    Serial.begin(9600);
    Serial.println("Starting StepperTest");

    delay(2000);

    pinMode(LED_PIN, OUTPUT);
    pinMode(FAN_PIN, OUTPUT);
    pinMode(X_ENABLE_PIN, OUTPUT);
    pinMode(Y_ENABLE_PIN, OUTPUT);
    pinMode(Z_ENABLE_PIN, OUTPUT);
    digitalWrite(X_ENABLE_PIN, LOW);
    digitalWrite(Y_ENABLE_PIN, LOW);
    digitalWrite(Z_ENABLE_PIN, LOW);
    digitalWrite(FAN_PIN, HIGH);
}

void loop()
{
    Serial.println("Change direction LOW");

    moveAxis(X_STEP_PIN, numberOfSteps, X_DIR_PIN, LOW);
    moveAxis(Y_STEP_PIN, numberOfSteps, Y_DIR_PIN, LOW);
    moveAxis(Z_STEP_PIN, numberOfSteps, Z_DIR_PIN, LOW);

    Serial.println("Change direction HIGH");
    delay(3000);

    moveAxis(Y_STEP_PIN, numberOfSteps, Y_DIR_PIN, HIGH);
    moveAxis(X_STEP_PIN, numberOfSteps, X_DIR_PIN, HIGH);
    moveAxis(Z_STEP_PIN, numberOfSteps, Z_DIR_PIN, HIGH);
}

void moveAxis(byte axis, int steps, byte directPin, byte direction)
{
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(directPin, direction);

    for (int n = 0; n < steps; n++)
    {
        digitalWrite(axis, HIGH);
        digitalWrite(axis, LOW);

        delay(millisbetweenSteps);
    }

    digitalWrite(LED_PIN, LOW);
}