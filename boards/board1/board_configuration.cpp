#include "pch.h"
#include "board_overrides.h"

// 1. İletişim LED'i (Veri transferi varken yanar söner)
Gpio getCommsLedPin() {
    return Gpio::A15; // Örnek: PA15 pinindeki LED
}

// 2. Çalışma LED'i (ECU sorunsuz çalışıyorsa düzenli yanıp söner)
Gpio getRunningLedPin() {
    return Gpio::C13; // Çoğu STM32 kartında gömülü LED PC13'tedir
}

// 3. Uyarı LED'i (Hata varsa yanar - Check Engine gibi düşün)
Gpio getWarningLedPin() {
    return Gpio::Unassigned; // Şimdilik boş bırakalım
}

// 4. ASIL MESELE: Pinleri Görevlendirme
void setup_custom_board_overrides() {

    // --- ENJEKTÖRLER ---
    engineConfiguration->injectionPins[0] = Gpio::B7; // 1. Silindir Enjektör
    engineConfiguration->injectionPins[1] = Gpio::B8; // 2. Silindir
    engineConfiguration->injectionPins[2] = Gpio::B9; // 3. Silindir
    engineConfiguration->injectionPins[3] = Gpio::E6; // 4. Silindir

    // --- ATEŞLEME (BOBİNLER) ---
    engineConfiguration->ignitionPins[0] = Gpio::E4; // 1. ve 4. silindir ortak (Wasted Spark)
    engineConfiguration->ignitionPins[1] = Gpio::E5; // 2. ve 3. silindir ortak

    // --- SENSÖR GİRİŞLERİ (TRIGGER) ---
    engineConfiguration->triggerInputPins[0] = Gpio::B1; // Krank Sensörü girişi

    // --- YAKIT POMPASI ---
    engineConfiguration->fuelPumpPin = Gpio::A8; // Yakıt pompasını tetikleyen röle pini

    // --- CAN BUS AYARI (Varsa) ---
    // engineConfiguration->canRxPin = Gpio::D0;
    // engineConfiguration->canTxPin = Gpio::D1;
}
