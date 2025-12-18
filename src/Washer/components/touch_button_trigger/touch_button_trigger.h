#pragma once

#include "esphome/core/component.h"
#include "esphome/components/switch/switch.h"
#include "esphome/core/log.h"

namespace esphome {
  namespace touch_button_trigger {

    class TouchButtonTrigger : public Component, public switch_::Switch {
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

  }
}

