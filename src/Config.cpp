#include "Config.h"

Wicher::Config::Config(const Wicher::Config &) {}

Wicher::Config::Config(){
    builder = Wicher::Builder::getSingleton().getBuilder();
    builder->get_widget("options_safety_switch", options_safety_switch);
}

Wicher::Config & Wicher::Config::getSingleton(){
    static Config b;
    return b;
}

bool Wicher::Config::get_unsafe_mode(){
	return this->options_safety_switch->get_active();
}
