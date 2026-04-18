#include <Arduino.h>

const int MAX_OUTPUT = (1 << 8) - 1;  // Max 8 bit output resolution.
const int MAX_OUTPUT_10BIT = (1 << 10) - 1;  // Max 10 bit output resolution.
const int MAX_INPUT = (1 << 10) - 1;  // Max 10 bit analog read resolution.


// GPIO Pin mapping.
const uint8_t P1 = 0;  // Knob 1
const uint8_t P2 = 1;  // Knob 2
const uint8_t P3 = 3;  // Knob 3

const uint8_t P_COUNT = 3;                            // Number of knobs.
const uint8_t KNOB_PINS[P_COUNT] = {P1, P2, P3};  // Array of knob GPIO pin identifiers.

const uint8_t GATE_IN = A6;  // Digital Input
const uint8_t CV_OUT = 9;  // CV Output for current step

const uint8_t LED1_PIN = 13;  // LED 1


class DigitalOutput {
   public:
    /**
     * @brief Initializes an CV Output paired object.
     * 
     * @param cv_pin gpio pin for the cv output
     */
    void Init(uint8_t cv_pin) {
        pinMode(cv_pin, OUTPUT);  // Gate/Trigger Output
        cv_pin_ = cv_pin;
    }
    
    /**
     * @brief Initializes an LED & CV Output paired object.
     * 
     * @param cv_pin gpio pin for the cv output
     * @param led_pin gpio pin for the LED
     */
    void Init(uint8_t cv_pin, uint8_t led_pin) {
        pinMode(led_pin, OUTPUT);  // LED
        led_pin_ = led_pin;
        #define LED_PIN_DEFINED
        Init(cv_pin);
    }

    /**
     * @brief Turn the CV and LED on or off according to the input state.
     * 
     * @param state Arduino digital HIGH or LOW values.
     */
    inline void Update(uint8_t state) {
        if (state == HIGH) High();  // Rising
        if (state == LOW) Low();    // Falling
    }

    /// @brief Sets the cv output HIGH to about 5v.
    inline void High() { update(HIGH); }

    /// @brief Sets the cv output LOW to 0v.
    inline void Low() { update(LOW); }

    /**
     * @brief Return a bool representing the on/off state of the output.
     * 
     * @return true if current cv state is high
     * @return false if current cv state is low
     */
    inline bool On() { return on_; }

   private:
    uint8_t cv_pin_;
    uint8_t led_pin_;
    bool on_;

    void update(uint8_t state) {
        digitalWrite(cv_pin_, state);
        #ifdef LED_PIN_DEFINED
        digitalWrite(led_pin_, state);
        #endif
        on_ = state == HIGH;
    }
};

class DigitalInput {
   public:
    /// @brief Enum constants for clk input rising/falling state.
    enum InputState {
        STATE_UNCHANGED,
        STATE_RISING,
        STATE_FALLING,
    };

    DigitalInput() {}
    ~DigitalInput() {}

    /**
     * @brief Initializes a CV Input object.
     *
     * @param cv_pin gpio pin for the cv output.
     */
    void Init(uint8_t cv_pin) {
        pinMode(cv_pin, INPUT);
        cv_pin_ = cv_pin;
    }

    /**
     * @brief Read the state of the cv input.
     *
     */
    void Process() {
        old_read_ = read_;
        read_ = digitalRead(cv_pin_);

        // Determine current clock input state.
        state_ = STATE_UNCHANGED;
        if (old_read_ == 0 && read_ == 1) {
            state_ = STATE_RISING;
            on_ = true;
        } else if (old_read_ == 1 && read_ == 0) {
            state_ = STATE_FALLING;
            on_ = false;
        }
    }

    /**
     * @brief Get the current input state of the digital input.
     *
     * @return InputState
     */
    inline InputState State() { return state_; }

    /**
     * @brief Current cv state represented as a bool.
     *
     * @return true if cv signal went high this loop.
     * @return false if cv signal went high this loop.
     */
    inline bool On() { return on_; }

    /**
     * @brief Read live pin state as a bool.
     *
     * @return true if cv signal is high.
     * @return false if cv signal is low.
     */
    inline bool Read() { return digitalRead(cv_pin_); }

   private:
    uint8_t cv_pin_;
    uint8_t read_;
    uint8_t old_read_;
    InputState state_;
    bool on_;
};
class AnalogOutput {
   public:
    /**
     * @brief Initializes an Analog CV Output object.
     *
     * @param pin gpio pin for the cv output
     */
    void Init(uint8_t pin) {
        pinMode(pin, OUTPUT);  // Analog CV Output
        cv_pin_ = pin;
    }

    /**
     * @brief Initializes an LED & CV Output paired object.
     * 
     * @param cv_pin gpio pin for the cv output
     * @param led_pin gpio pin for the LED
     */
    void Init(uint8_t cv_pin, uint8_t led_pin) {
        pinMode(led_pin, OUTPUT);  // LED
        led_pin_ = led_pin;
        #define LED_PIN_DEFINED
        Init(cv_pin);
    }

    /**
     * @brief Set the output pin to the given 8 bit value.
     *
     * @param val Arduino analog value between 0 and 255 (0..10v).
     */
    inline void Update(int val) {
        update((val <= MAX_OUTPUT) ? val : MAX_OUTPUT);
    }

    /**
     * @brief Set the output pin to the given 10 bit value.
     *
     * @param val Arduino analog value between 0 and 1024 (0..10v).
     */
    inline void Update10bit(int val) {
        val = val <= MAX_OUTPUT_10BIT ? val : MAX_OUTPUT_10BIT;
        val = map(val, 0, MAX_OUTPUT_10BIT, 0, MAX_OUTPUT);
        update(val);
    }

    /// @brief Sets the cv output HIGH to about 10v.
    inline void High() { update(MAX_OUTPUT); }

    /// @brief Sets the cv output LOW to 0v.
    inline void Low() { update(0); }

    /**
     * @brief Return an integer value between 0 and 1023 (0..10v) representing the current value of the output.
     *
     * @return integer value of cv from 0 to 1023.
     */
    inline uint16_t GetValue() { return cv_; }

   private:
    uint8_t cv_pin_;
    uint8_t led_pin_;
    uint8_t cv_;

    void update(uint16_t val) {
        cv_ = val;
        analogWrite(cv_pin_, cv_);
        #ifdef LED_PIN_DEFINED
        analogWrite(led_pin_, cv_);
        #endif
    }
};

class AnalogInput {
   public:
    AnalogInput() {}
    ~AnalogInput() {}

    /**
    * @brief Initializes a analog input object.
    * 
    * @param pin gpio pin for the analog input.
    */
    void Init(uint8_t pin) {
        pinMode(pin, INPUT);
        pin_ = pin;
    }

    /**
     * @brief Read the value of the analog input.
     * 
     */
    void Process() {
        old_read_ = read_;
        read_ = analogRead(pin_);
    }

    /**
     * @brief Get the current value of the analog input.
     * 
     * @return InputState 
     */
    inline uint16_t Read() { return read_; }

   private:
    uint8_t pin_;
    uint16_t read_;
    uint16_t old_read_;
};


/// @brief Hardware abstraction wrapper for SyncLFO module.
class SyncLFO {
   public:
    /// @brief Constructor
    SyncLFO(){}

    /// @brief Deconstructor
    ~SyncLFO() {}

    /// @brief Initializes the Arduino, and SyncLFO hardware.
    void Init();

    /// @brief Read the state of the CLK and RST inputs.
    void ProcessInputs();

    AnalogInput p1;
    AnalogInput p2;
    AnalogInput p3;
    AnalogInput *knobs[P_COUNT];

    DigitalInput gate;
    DigitalInput trig;
    AnalogOutput output;

   private:
    void InitInputs();
    void InitOutputs();
};






void SyncLFO::Init() {
    InitInputs();
    InitOutputs();
}

void SyncLFO::InitInputs() {
    gate.Init(GATE_IN);
    trig.Init(GATE_IN);

    p1.Init(P1);
    p2.Init(P2);
    p3.Init(P3);
    knobs[0] = &p1;
    knobs[1] = &p2;
    knobs[2] = &p3;


}

void SyncLFO::InitOutputs() {
    output.Init(CV_OUT);

    // Register setting for high frequency PWM.
    TCCR1A = 0b00100001;
    TCCR1B = 0b00100001;
}

void SyncLFO::ProcessInputs() {
    gate.Process();
    trig.Process();
    for (int i = 0; i < P_COUNT; i++) {
        knobs[i]->Process();
    }
}
