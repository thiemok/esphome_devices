import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import switch
from esphome.const import CONF_ID

touch_button_trigger_ns = cg.esphome_ns.namespace("touch_button_trigger")
Trigger = touch_button_trigger_ns.class_("TouchButtonTrigger", switch.Switch, cg.Component)

CONFIG_SCHEMA = switch.switch_schema(Trigger).extend(cv.COMPONENT_SCHEMA)

async def to_code(config):
  var = await switch.new_switch(config)
  await cg.register_component(var, config)
