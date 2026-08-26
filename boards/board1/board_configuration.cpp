#include "pch.h"
#include "board_overrides.h"

Gpio getCommsLedPin() {
	return Gpio::Unassigned;
}

Gpio getRunningLedPin() {
	return Gpio::Unassigned;
}

Gpio getWarningLedPin() {
	return Gpio::Unassigned;
}

static void setupSdCard() {
	engineConfiguration->sdCardSpiDevice = SPI_DEVICE_3;
	engineConfiguration->sdCardCsPin = Gpio::I3;

	engineConfiguration->is_enabled_spi_3 = true;
	engineConfiguration->spi3sckPin = Gpio::C10;
	engineConfiguration->spi3misoPin = Gpio::C11;
	engineConfiguration->spi3mosiPin = Gpio::C12;
static void proteus_boardConfigOverrides() {
	setupSdCard();

}
}
void setup_custom_board_overrides() {
	custom_board_DefaultConfiguration = proteus_boardDefaultConfiguration;
	// ... senin injectionPins / auxValves / ignitionPins satırların ...

}   // <-- fonksiyonun en sonunda bu da olmalı
