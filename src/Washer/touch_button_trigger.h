#include "esphome.h"

class TouchButtonTrigger : public Component, public Switch {
public:
  void setup() override {
    pinMode(4, INPUT);
    digitalWrite(4, LOW);
  }

  void write_state(bool state) override {
    if(state) {
      pinMode(4, OUTPUT);
      digitalWrite(4, LOW);
      ESP_LOGD("TouchButtonTrigger", "pulling pin low");
      delay(500);

      pinMode(4, INPUT);
      digitalWrite(4, LOW);
      ESP_LOGD("TouchButtonTrigger", "setting pin floating");
    }

    publish_state(state);
  }
};
